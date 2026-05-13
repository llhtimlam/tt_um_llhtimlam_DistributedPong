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
    top_left->eval();       top_right->eval();
    top_left->sim_rst = 0;  top_right->sim_rst = 0;

    // Force the Right FPGA to be "Right" by setting bit 7
    top_right->ui_in = 0x80; 
    top_left->ui_in  = 0x00;
    
    uint64_t frame_count = 0;
    bool done = false;

    while (!done) {
        // 1. CLOCK CYCLE
        top_left->clk_pix = 1; top_right->clk_pix = 1;
        top_left->eval();      top_right->eval();
        top_left->clk_pix = 0; top_right->clk_pix = 0;
        top_left->eval();      top_right->eval();

        // 2. INPUT MAPPING (Preserve Bit 7 and Bit 3)
        // Keep bit 7 and bit 3, clear the rest
        top_left->ui_in  &= 0x88; 
        top_right->ui_in &= 0x88;

        // Map Left (W/S)
        if (keyb_state[SDL_SCANCODE_W]) top_left->ui_in |= 0x01;
        if (keyb_state[SDL_SCANCODE_S]) top_left->ui_in |= 0x02;

        // Map Right (I/K)
        if (keyb_state[SDL_SCANCODE_I]) top_right->ui_in |= 0x01;
        if (keyb_state[SDL_SCANCODE_K]) top_right->ui_in |= 0x02;

        // 3. VIRTUAL WIRING (Handover)
        top_right->uio_in = top_left->uio_out;
        top_left->uio_in  = top_right->uio_out;

        // Sync bit logic (Bit 3 of uo_out -> Bit 3 of ui_in)
        bool left_sync  = (top_left->uo_out  >> 3) & 0x01;
        bool right_sync = (top_right->uo_out >> 3) & 0x01;

        if (left_sync)  top_right->ui_in |= 0x08; else top_right->ui_in &= ~0x08;
        if (right_sync) top_left->ui_in  |= 0x08; else top_left->ui_in  &= ~0x08;

        // 4. DRAWING
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

        // 5. RENDER
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