#include <stdio.h>
#include <SDL.h>
#include <verilated.h>
#include "Vtt_um_vga_example.h"

const int H_RES = 640;
const int V_RES = 480;

typedef struct Pixel { uint8_t a, b, g, r; } Pixel;

int main(int argc, char* argv[]) {
    Verilated::commandArgs(argc, argv);
    if (SDL_Init(SDL_INIT_VIDEO) < 0) return 1;

    Pixel screenbuffer[H_RES*V_RES];
    SDL_Window* sdl_window = SDL_CreateWindow("Dual FPGA Pong Sim", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, H_RES, V_RES, SDL_WINDOW_SHOWN);
    SDL_Renderer* sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture* sdl_texture = SDL_CreateTexture(sdl_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, H_RES, V_RES);
    const Uint8 *keyb_state = SDL_GetKeyboardState(NULL);

    Vtt_um_vga_example* top_left  = new Vtt_um_vga_example;
    Vtt_um_vga_example* top_right = new Vtt_um_vga_example;

    // --- RESET PHASE ---
    top_left->sim_rst = 1;  top_right->sim_rst = 1;
    top_left->clk_pix = 0; top_right->clk_pix = 0;
    top_left->eval();       top_right->eval();
    top_left->sim_rst = 0;  top_right->sim_rst = 0;
    
    // Force right FPGA identification via bit 7
    top_right->ui_in = 0x80;  // Set bit 7 to identify as right
    top_left->ui_in  = 0x00;  // Left has no force
    
    // Run initial clock cycles to let them settle
    for (int i = 0; i < 1000; i++) {
        top_left->clk_pix = 1; top_right->clk_pix = 1;
        top_left->eval(); top_right->eval();
        top_left->clk_pix = 0; top_right->clk_pix = 0;
        top_left->eval(); top_right->eval();
    }
    
    printf("After initialization:\n");
    printf("Left is_right=%d, Right is_right=%d\n", 
           top_left->is_right_fpga, top_right->is_right_fpga);
    
    uint64_t frame_count = 0;
    bool done = false;
    int cycle_count = 0;
    
    // Tracking variables
    int left_sync_count = 0, right_sync_count = 0;
    int last_left_sync = 0, last_right_sync = 0;
    int left_edge_count = 0, right_edge_count = 0;
    int left_edge_triggered = 0, right_edge_triggered = 0;
    
    // Main game loop
    while (!done && frame_count < 10000) {
        // Clock high
        top_left->clk_pix = 1; top_right->clk_pix = 1;
        top_left->eval(); top_right->eval();

        // Input mapping - preserve bit 7 (right ID) and bit 3 (sync)
        top_left->ui_in &= 0x88;
        top_right->ui_in &= 0x88;
        
        // Keep right FPGA identification
        top_right->ui_in |= 0x80;

        if (keyb_state[SDL_SCANCODE_W]) top_left->ui_in |= 0x01;
        if (keyb_state[SDL_SCANCODE_S]) top_left->ui_in |= 0x02;
        if (keyb_state[SDL_SCANCODE_I]) top_right->ui_in |= 0x01;
        if (keyb_state[SDL_SCANCODE_K]) top_right->ui_in |= 0x02;

        // Bidirectional bus
        uint8_t left_drive = top_left->uio_oe ? top_left->uio_out : 0;
        uint8_t right_drive = top_right->uio_oe ? top_right->uio_out : 0;
        uint8_t shared_bus = left_drive | right_drive;
        
        top_left->uio_in = shared_bus;
        top_right->uio_in = shared_bus;
        
        // Sync signals cross-connect
        int left_sync = (top_left->uo_out >> 3) & 1;
        int right_sync = (top_right->uo_out >> 3) & 1;
        
        top_left->ui_in = (top_left->ui_in & ~0x08) | (right_sync ? 0x08 : 0);
        top_right->ui_in = (top_right->ui_in & ~0x08) | (left_sync ? 0x08 : 0);
        
        // Clock low
        top_left->clk_pix = 0; top_right->clk_pix = 0;
        top_left->eval(); top_right->eval();
        
        // Update bus for falling edge
        left_drive = top_left->uio_oe ? top_left->uio_out : 0;
        right_drive = top_right->uio_oe ? top_right->uio_out : 0;
        shared_bus = left_drive | right_drive;
        
        top_left->uio_in = shared_bus;
        top_right->uio_in = shared_bus;
        
        top_left->eval(); top_right->eval();

        // Track events
        int left_edge = (top_left->uo_out >> 1) & 1;
        int right_edge = (top_right->uo_out >> 1) & 1;
        
        if (left_sync && !last_left_sync) {
            left_sync_count++;
            printf("*** LEFT SYNC PULSE #%d at cycle %d (RIGHT ui_in=0x%02X)\n", 
                   left_sync_count, cycle_count, top_right->ui_in);
        }
        if (right_sync && !last_right_sync) {
            right_sync_count++;
            printf("*** RIGHT SYNC PULSE #%d at cycle %d (LEFT ui_in=0x%02X)\n", 
                   right_sync_count, cycle_count, top_left->ui_in);
        }
        if (left_edge && !left_edge_triggered) {
            left_edge_triggered = 1;
            printf("*** LEFT EDGE REACHED at cycle %d\n", cycle_count);
        }
        if (right_edge && !right_edge_triggered) {
            right_edge_triggered = 1;
            printf("*** RIGHT EDGE REACHED at cycle %d\n", cycle_count);
        }
        
        if (left_edge) left_edge_count++;
        if (right_edge) right_edge_count++;
        
        last_left_sync = left_sync;
        last_right_sync = right_sync;

        // Debug output periodically
        if (cycle_count % 1000000 == 0) {
            printf("\n=== CYCLE %d ===\n", cycle_count);
            printf("LEFT: uo_out=0x%02X (sync=%d, edge=%d, ball=%d), is_right=%d\n",
                top_left->uo_out, left_sync, left_edge, top_left->uo_out&1,
                top_left->is_right_fpga);
            printf("RIGHT: uo_out=0x%02X (sync=%d, edge=%d, ball=%d), is_right=%d\n",
                top_right->uo_out, right_sync, right_edge, top_right->uo_out&1,
                top_right->is_right_fpga);
            printf("LEFT uio_oe=0x%02X, RIGHT uio_oe=0x%02X\n", top_left->uio_oe, top_right->uio_oe);
            printf("LEFT ui_in=0x%02X, RIGHT ui_in=0x%02X\n", top_left->ui_in, top_right->ui_in);
            printf("Sync pulses: L=%d, R=%d | Edge events: L=%d, R=%d\n", 
                   left_sync_count, right_sync_count, left_edge_count, right_edge_count);
        }

        cycle_count++;

        // Drawing
        if (top_left->sdl_sy == 0 && top_left->sdl_sx == 0) {
            memset(screenbuffer, 0, sizeof(screenbuffer));
        }

        if (top_left->sdl_de && top_left->sdl_sx < 320) {
            Pixel* p = &screenbuffer[top_left->sdl_sy * H_RES + top_left->sdl_sx];
            p->a = 0xFF; p->r = top_left->sdl_r; p->g = top_left->sdl_g; p->b = top_left->sdl_b;
        }

        if (top_right->sdl_de && top_right->sdl_sx >= 320) {
            Pixel* p = &screenbuffer[top_right->sdl_sy * H_RES + top_right->sdl_sx];
            p->a = 0xFF; p->r = top_right->sdl_r; p->g = top_right->sdl_g; p->b = top_right->sdl_b;
        }

        // Render
        if (top_left->sdl_sy == V_RES-1 && top_left->sdl_sx == H_RES-1) {
            SDL_Event e;
            while (SDL_PollEvent(&e)) if (e.type == SDL_QUIT) done = true;
            if (keyb_state[SDL_SCANCODE_Q]) done = true;

            SDL_UpdateTexture(sdl_texture, NULL, screenbuffer, H_RES*sizeof(Pixel));
            SDL_RenderClear(sdl_renderer);
            SDL_RenderCopy(sdl_renderer, sdl_texture, NULL, NULL);
            SDL_RenderPresent(sdl_renderer);
            frame_count++;
        }
    }

    top_left->final(); top_right->final();
    SDL_DestroyTexture(sdl_texture);
    SDL_DestroyRenderer(sdl_renderer);
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
    return 0;
}