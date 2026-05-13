#include <stdio.h>
#include <SDL.h>
#include <verilated.h>
#include "Vtt_um_vga_example.h"

const int H_RES = 640;
const int V_RES = 480;

struct Pixel { uint8_t a, b, g, r; };

// Helper to create a window and texture for one FPGA
struct Display {
    SDL_Window*   window;
    SDL_Renderer* renderer;
    SDL_Texture*  texture;
    Pixel*        buffer;
    const char*   title;
    int           xpos, ypos;
};

Display* create_display(const char* title, int x, int y) {
    Display* d = new Display;
    d->title = title;
    d->xpos = x;
    d->ypos = y;
    d->window = SDL_CreateWindow(title, x, y, H_RES, V_RES, SDL_WINDOW_SHOWN);
    if (!d->window) return nullptr;
    d->renderer = SDL_CreateRenderer(d->window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    d->texture = SDL_CreateTexture(d->renderer, SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_TARGET, H_RES, V_RES);
    d->buffer = new Pixel[H_RES * V_RES];
    return d;
}

void update_display(Display* d, int hpos, int vpos, bool de, uint8_t r, uint8_t g, uint8_t b) {
    if (de && hpos < H_RES && vpos < V_RES) {
        int idx = vpos * H_RES + hpos;
        d->buffer[idx].a = 0xFF;
        d->buffer[idx].r = r;
        d->buffer[idx].g = g;
        d->buffer[idx].b = b;
    }
    // At end of frame, present
    if (hpos == H_RES-1 && vpos == V_RES-1) {
        SDL_UpdateTexture(d->texture, NULL, d->buffer, H_RES * sizeof(Pixel));
        SDL_RenderClear(d->renderer);
        SDL_RenderCopy(d->renderer, d->texture, NULL, NULL);
        SDL_RenderPresent(d->renderer);
        memset(d->buffer, 0, H_RES * V_RES * sizeof(Pixel));
    }
}

int main(int argc, char* argv[]) {
    Verilated::commandArgs(argc, argv);
    if (SDL_Init(SDL_INIT_VIDEO) < 0) return 1;

    // Create two windows side by side
    Display* left_disp  = create_display("FPGA Left (W/S)", 50, 50);
    Display* right_disp = create_display("FPGA Right (I/K)", 50 + H_RES + 20, 50);
    if (!left_disp || !right_disp) return 1;

    const Uint8 *keys = SDL_GetKeyboardState(NULL);

    // Create two FPGA instances (left and right)
    Vtt_um_vga_example* left  = new Vtt_um_vga_example;
    Vtt_um_vga_example* right = new Vtt_um_vga_example;

    // Reset both
    // Start with clk low
    left->clk = right->clk = 0;
    left->eval(); right->eval();

    // Assert reset
    left->rst_n = right->rst_n = 0;
    left->eval(); right->eval();   // let reset propagate

    // Generate a rising edge while reset is active
    left->clk = right->clk = 1;
    left->eval(); right->eval();

    // Lower clock
    left->clk = right->clk = 0;
    left->eval(); right->eval();

    // Release reset
    left->rst_n = right->rst_n = 1;
    left->eval(); right->eval();

    // Another rising edge to capture the released state
    left->clk = right->clk = 1;
    left->eval(); right->eval();
    left->clk = right->clk = 0;
    left->eval(); right->eval();

    // Set identity: left = 0, right = 1 (ui_in[7])
    left->ui_in  = 0x00;   // id=0
    right->ui_in = 0x80;   // id=1

    // Initial boot cycles
    for (int i = 0; i < 5000; i++) {
        left->clk = right->clk = 1;
        left->eval(); right->eval();
        left->clk = right->clk = 0;
        left->eval(); right->eval();
    }

    printf("Left FPGA id = %d, Right FPGA id = %d\n",
           (left->ui_in >> 7) & 1, (right->ui_in >> 7) & 1);

    // Main simulation loop
    int cycle = 0;
    bool quit = false;

    while (!quit && cycle < 100000000) {
        // ----- Keyboard input -----
        left->ui_in  = 0x00;          // left id = 0
        right->ui_in = 0x80;          // right id = 1

        if (keys[SDL_SCANCODE_W]) left->ui_in  |= 0x01;  // move_up
        if (keys[SDL_SCANCODE_S]) left->ui_in  |= 0x02;  // move_down
        if (keys[SDL_SCANCODE_I])   right->ui_in |= 0x01;
        if (keys[SDL_SCANCODE_K]) right->ui_in |= 0x02;

        // ----- UART cross‑connection (push‑pull, direct) -----
        // Set uio_oe 01010101
        left->uio_oe = (1 << 0) | (1 << 2) | (1 << 4) | (1 << 6);
        right->uio_oe = left->uio_oe;

        // Clock high
        //left->clk = right->clk = 1;
        //left->eval(); right->eval();

        // ---- Cross connections (point‑to‑point) ----
        uint8_t left_out  = left->uio_out;
        uint8_t right_out = right->uio_out;

        // left outputs → right inputs
        right->uio_in = 0;
        right->uio_in |= ((left_out >> 0) & 1) << 1;   // bit0 -> bit1 (TX→RX)
        right->uio_in |= ((left_out >> 2) & 1) << 3;   // bit2 -> bit3 (unused)
        right->uio_in |= ((left_out >> 4) & 1) << 5;   // bit4 -> bit5 (has_ball)
        right->uio_in |= ((left_out >> 6) & 1) << 7;   // bit6 -> bit7 (insync)
        // right outputs → left inputs
        left->uio_in = 0;
        left->uio_in |= ((right_out >> 0) & 1) << 1;
        left->uio_in |= ((right_out >> 2) & 1) << 3;
        left->uio_in |= ((right_out >> 4) & 1) << 5;
        left->uio_in |= ((right_out >> 6) & 1) << 7;
        // Let new inputs settle
        left->eval(); right->eval();

        // Clock low
        //left->clk = right->clk = 0;
        //left->eval(); right->eval();
        
        // 2. Rising Edge (This is where 'send' is captured)
        left->clk = right->clk = 1;
        left->eval(); right->eval();

        // 3. Falling Edge
        left->clk = right->clk = 0;
        left->eval(); right->eval();

        // ----- Video rendering (each FPGA renders its own full screen) -----
        // Left FPGA
        update_display(left_disp, left->sdl_sx, left->sdl_sy,
                       left->sdl_de, left->sdl_r, left->sdl_g, left->sdl_b);
        // Right FPGA
        update_display(right_disp, right->sdl_sx, right->sdl_sy,
                       right->sdl_de, right->sdl_r, right->sdl_g, right->sdl_b);
        
        if (left->debug_game_tick == 1) {
            printf("txdata=%d, | rxdata=%d, | state=%d, | packet busy=%d, | counter=%d\n", 
                left->debug_tx_data,  right->debug_rx_data, left->state1,  left->debug_packet_busy,  left->baud_counter);
            fflush(stdout);
        }
        if (left->debug_game_tick) {
            printf("L: has_ball=%d, has_ball_rx=%d, txcd=%d, bouncecd=%d\n", left->debug_has_ball, left->debug_has_ball_rx, left->debug_txcd, left->debug_bounce_cd);
            printf("R: has_ball=%d, has_ball_rx=%d\n", right->debug_has_ball, right->debug_has_ball_rx);
        }
        if (left->debug_game_tick) {
            printf("vx=%d | hit r=%d | hit l=%d | hit y %d | x=%d | txcmd1=%d | txcmd2=%d\n", left->debug_ball_vel_x, left->debug_collision_paddle_r, left->debug_collision_paddle_l, left->debug_collision_paddle_y, left-> debug_ball_x, left-> debug_rx_cmd, left->debug_packet2);
        }
        static int last_send = 0, last_ready = 0;
        if (left->debug_baud_tick == 1) {
            printf("L send_packet: state=%d, | tx=%d, | send=%d, | byte_cnt=%d, | bit_idx=%d, | busy=%d, | packet busy=%d, | rx=%d\n", left->state1, left->debug_uart_tx, left->debug_tx_sent, left->byte_cnt, left->bit_idx, left->debug_tx_busy, left->debug_packet_busy, right->debug_uart_rx);
            last_send = left->debug_5;
        }
        if (left->debug_tx_sent == 1) {
            printf("L send_packet: state=%d, | tx=%d, | send=%d, | byte_cnt=%d, | bit_idx=%d, | busy=%d, | packet busy=%d, | rx=%d\n", left->state1, left->debug_uart_tx, left->debug_tx_sent, left->byte_cnt, left->bit_idx, left->debug_tx_busy, left->debug_packet_busy, right->debug_uart_rx);
            last_send = left->debug_5;
        }
        /*
        if (right->debug_baud_tick == 1) {
            printf("Right send_packet: state=%d, | tx=%d, | send=%d, | byte_cnt=%d, | bit_idx=%d, | busy=%d, | packet busy=%d\n", right->state1, right->debug_uart_tx, right->debug_tx_sent, right->byte_cnt, right->bit_idx, right->debug_tx_busy, right->debug_packet_busy);
            last_send = left->debug_5;
        }
        if (right->debug_tx_sent == 1) {
            printf("Right send_packet: state=%d, | tx=%d, | send=%d, | byte_cnt=%d, | bit_idx=%d, | busy=%d, | packet busy=%d\n", right->state1, right->debug_uart_tx, right->debug_tx_sent, right->byte_cnt, right->bit_idx, right->debug_tx_busy, right->debug_packet_busy);
            last_send = left->debug_5;
        }*/
        /*
        if (right->debug_rx_packet_ready != last_ready) {
            printf("Right rx_packet_ready: %d\n", right->debug_rx_packet_ready);
            last_ready = right->debug_rx_packet_ready;
        }
        */
        if (right->debug_rx_packet_ready == 1) {
            printf("x=%d, | y=%d, | vx=%d, | vy=%d, | cmd=%d, | by=%d, | bvx=%d, | bvy=%d\n", right->debug_rx_ball_x, right->debug_rx_ball_y, right->debug_rx_ball_vel_x, right->debug_rx_ball_vel_y, right->debug_rx_cmd, left->debug_ball_y, left->debug_ball_vel_x, left->debug_ball_vel_y);
        }
        if (right->debug_rx_packet_ready == 1) {
            printf("cmd=%d, | ack=%d, | tx=%d, | rx=%d, | txcmd=%d\n", right->debug_rx_cmd, right->debug_send_ack_packet, right->debug_ball_tx, right->debug_ball_rx, right->debug_packet_cmd);
        }
        if (right->debug_rx_packet_ready == 1) {
            printf("ack=%d, | rx_ack_packet=%d, | rx_packet=%d, | rx=%d\n", right->debug_ack, right->debug_send_ack_packet, right->debug_send_packet, right->debug_ball_rx);
        }
        if (right->debug_rx_packet_ready == 1) {
            printf("x=%d, | y=%d, | vx=%d, | vy=%d, | cmd=%d, | by=%d, | bvx=%d, | bvy=%d\n", left->debug_rx_ball_x, left->debug_rx_ball_y, left->debug_rx_ball_vel_x, left->debug_rx_ball_vel_y, left->debug_rx_cmd, right->debug_ball_y, right->debug_ball_vel_x, right->debug_ball_vel_y);
        }
        if (right->debug_rx_packet_ready == 1) {
            printf("cmd=%d, | ack=%d, | tx=%d, | rx=%d\n", right->debug_rx_cmd, right->debug_send_ack_packet, right->debug_ball_tx, right->debug_ball_rx);
        }
        if (right->debug_send_ack_packet == 1) {
            printf("ack=%d, | rx_ack_packet=%d, | rx_packet=%d, | rx=%d\n", right->debug_ack, right->debug_send_ack_packet, right->debug_send_packet, right->debug_ball_rx);
        }
        // Handle SDL events
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = true;
        }
        if (keys[SDL_SCANCODE_Q]) quit = true;

        cycle++;
    }

    left->final(); right->final();
    delete left; delete right;
    SDL_Quit();
    return 0;
}