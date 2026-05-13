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
    
    // Force right FPGA identification
    top_right->ui_in = 0x80;
    top_left->ui_in  = 0x00;
    
    // Run initial cycles
    for (int i = 0; i < 1000; i++) {
        top_left->clk_pix = 1; top_right->clk_pix = 1;
        top_left->eval(); top_right->eval();
        uint8_t left_bus = top_left->uio_oe ? top_left->uio_out : 0;
        uint8_t right_bus = top_right->uio_oe ? top_right->uio_out : 0;
        uint8_t shared_bus = left_bus | right_bus;
        top_left->uio_in = shared_bus;
        top_right->uio_in = shared_bus;
        top_left->clk_pix = 0; top_right->clk_pix = 0;
        top_left->eval(); top_right->eval();
        left_bus = top_left->uio_oe ? top_left->uio_out : 0;
        right_bus = top_right->uio_oe ? top_right->uio_out : 0;
        shared_bus = left_bus | right_bus;
        top_left->uio_in = shared_bus;
        top_right->uio_in = shared_bus;
        top_left->eval(); top_right->eval();
    }
    
    printf("After initialization:\n");
    printf("Left is_right=%d, Right is_right=%d\n", 
           top_left->is_right_fpga, top_right->is_right_fpga);
    
    uint64_t frame_count = 0;
    bool done = false;
    int cycle_count = 0;
    
    // Debug state for serial capture
    int tx_phase = 0;          // 0=idle, 1=wait first byte, 2=wait second byte
    uint8_t tx_byte1 = 0, tx_byte2 = 0;
    int rx_phase = 0;          // 0=idle, 1=wait first byte, 2=wait second byte
    uint8_t rx_byte1 = 0;
    
    int last_left_sync = 0, last_right_sync = 0;
    int last_left_ui_sync = 0, last_right_ui_sync = 0;
    int left_edge_count = 0, right_edge_count = 0;
    int left_sync_count = 0, right_sync_count = 0;
    
    while (!done && frame_count < 10000) {
        // --- CLOCK HIGH PHASE ---
        top_left->clk_pix = 1; top_right->clk_pix = 1;
        top_left->eval(); top_right->eval();

        // Input mapping
        top_left->ui_in &= 0x88;
        top_right->ui_in &= 0x88;
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
        
        // Sync cross‑connection
        int left_sync = (top_left->uo_out >> 3) & 1;
        int right_sync = (top_right->uo_out >> 3) & 1;
        if (left_sync) top_right->ui_in |= 0x08;
        else top_right->ui_in &= ~0x08;
        if (right_sync) top_left->ui_in |= 0x08;
        else top_left->ui_in &= ~0x08;
        
        // --- Capture transmitted bytes from left FPGA ---
        if (left_sync && !last_left_sync) {
            tx_phase = 1;
            printf("\n[%d] LEFT TX START (sync)\n", cycle_count);
        }
        // Check for data while left is driving the bus
        if (tx_phase == 1 && top_left->uio_oe) {
            tx_byte1 = top_left->uio_out;
            printf("   TX byte1 = 0x%02X (Y low)\n", tx_byte1);
            tx_phase = 2;
        } else if (tx_phase == 2 && top_left->uio_oe) {
            tx_byte2 = top_left->uio_out;
            printf("   TX byte2 = 0x%02X (Y high+vel)\n", tx_byte2);
            printf("   -> Y = %d, vx = %d, vy = %d\n",
                   ((tx_byte2 >> 6) & 0x03) | (tx_byte1 << 2),
                   (tx_byte2 >> 3) & 0x07,
                   (tx_byte2 >> 0) & 0x07);
            tx_phase = 0;
        }
        
        // --- CLOCK LOW PHASE ---
        top_left->clk_pix = 0; top_right->clk_pix = 0;
        top_left->eval(); top_right->eval();
        
        // Update bus again (falling edge)
        left_drive = top_left->uio_oe ? top_left->uio_out : 0;
        right_drive = top_right->uio_oe ? top_right->uio_out : 0;
        shared_bus = left_drive | right_drive;
        top_left->uio_in = shared_bus;
        top_right->uio_in = shared_bus;
        top_left->eval(); top_right->eval();

        // --- Capture received bytes on right FPGA ---
        int right_ui_sync = (top_right->ui_in >> 3) & 1;
        if (right_ui_sync && !last_right_ui_sync) {
            rx_phase = 1;   // expect first byte
            printf(">>> RIGHT RECEIVED SYNC at cycle %d\n", cycle_count);
        }
        if (rx_phase == 1 && top_right->uio_in != 0) {
            rx_byte1 = top_right->uio_in;
            printf("   RX byte1 = 0x%02X\n", rx_byte1);
            rx_phase = 2;
        } else if (rx_phase == 2 && top_right->uio_in != 0) {
            uint8_t rx_byte2 = top_right->uio_in;
            printf("   RX byte2 = 0x%02X\n", rx_byte2);
            printf("   -> Y = %d, vx = %d, vy = %d\n",
                   ((rx_byte2 >> 6) & 0x03) | (rx_byte1 << 2),
                   (rx_byte2 >> 3) & 0x07,
                   (rx_byte2 >> 0) & 0x07);
            rx_phase = 0;
        }
        
        // --- Track other events ---
        int left_edge = (top_left->uo_out >> 1) & 1;
        int right_edge = (top_right->uo_out >> 1) & 1;
        
        if (left_sync && !last_left_sync) {
            left_sync_count++;
            printf("*** LEFT SYNC #%d at cycle %d\n", left_sync_count, cycle_count);
        }
        if (right_sync && !last_right_sync) {
            right_sync_count++;
            printf("*** RIGHT SYNC #%d at cycle %d\n", right_sync_count, cycle_count);
        }
        if (left_edge && !left_edge_count) {
            left_edge_count = 1;
            printf("*** LEFT EDGE at cycle %d\n", cycle_count);
        }
        if (right_edge && !right_edge_count) {
            right_edge_count = 1;
            printf("*** RIGHT EDGE at cycle %d\n", cycle_count);
        }
        
        last_left_sync = left_sync;
        last_right_sync = right_sync;
        last_right_ui_sync = right_ui_sync;
        left_edge_count = left_edge ? 1 : left_edge_count;
        right_edge_count = right_edge ? 1 : right_edge_count;

        // Periodic summary
        if (cycle_count % 10000000 == 0) {
            printf("\n=== CYCLE %d ===\n", cycle_count);
            printf("LEFT: uo_out=0x%02X (sync=%d, edge=%d, ball=%d) ui_in=0x%02X\n",
                top_left->uo_out, left_sync, left_edge, top_left->uo_out&1, top_left->ui_in);
            printf("RIGHT: uo_out=0x%02X (sync=%d, edge=%d, ball=%d) ui_in=0x%02X\n",
                top_right->uo_out, right_sync, right_edge, top_right->uo_out&1, top_right->ui_in);
        }

        cycle_count++;

        // --- Video drawing (unchanged) ---
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