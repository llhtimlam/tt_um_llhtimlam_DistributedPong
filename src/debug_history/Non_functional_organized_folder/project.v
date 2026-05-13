/*
 * Copyright (c) 2026 Tim Lam
 * SPDX-License-Identifier: Apache-2.0
 */

`default_nettype none

`include "config.vh"
`include "distributed_pong.v"
`include "router.v"
`include "graphic.v"

module tt_um_llhtimlam_distributedpong (
  input  wire [7:0] ui_in,    // Dedicated inputs: Paddle up(0), down(1), identity(7)
  output wire [7:0] uo_out,   // Dedicated outputs: TinyVGA: R1,G1,B1,vsync,R0,G0,B0,hsync
  input  wire [7:0] uio_in,   // IOs: Input path
  output wire [7:0] uio_out,  // IOs: Output path
  output wire [7:0] uio_oe,   // IOs: Enable path (active high: 0=input, 1=output)
  input  wire       ena,      // always 1 when the design is powered, so you can ignore it
  input  wire       clk,      // clock
  input  wire       rst_n,    // reset_n - low to reset

  // Verilog Simulation with Verilator and SDL
  output wire [9:0] sdl_sx,   
  output wire [9:0] sdl_sy,
  output wire       sdl_de,
  output wire [7:0] sdl_r,
  output wire [7:0] sdl_g,
  output wire [7:0] sdl_b,

  output wire [2:0] dd,
  output wire [7:0] dc
  
);
  wire [2:0] dab;
  assign dd = dab;
  // ----- Input mapping -----
  wire move_up   = ui_in[0];
  wire move_down = ui_in[1];
  wire id        = ui_in[7];

  // ----- Output mapping (TinyVGA) -----
  assign uo_out[0] = vga_r1;
  assign uo_out[1] = vga_g1;
  assign uo_out[2] = vga_b1;
  assign uo_out[3] = vga_vsync;
  assign uo_out[4] = vga_r0;
  assign uo_out[5] = vga_g0;
  assign uo_out[6] = vga_b0;
  assign uo_out[7] = vga_hsync;

  // ----- Bidirectional UART configuration -----
  wire uart_tx, uart_rx, has_ball_rx, insync_rx;
  //assign uio_oe = 8'b01010101;   // [NOT INDEX] odd pins output (TX), even input (RX)
  assign uio_out[0] = uart_tx;
  assign uart_rx    = uio_in[1];
  assign uio_out[4] = has_ball_tx;
  assign has_ball_rx = uio_in[5];
  assign uio_out[6] = insync_tx;
  assign insync_rx   = uio_in[7];

  // ----- Internal wires -----

  // ----- Internal wires -----
  // System Command
  wire        game_tick, cmd_pause;
  
  // Physics
  wire [9:0]  ball_x, ball_y, paddle_y, tx_ball_x, tx_ball_y, rx_ball_x, rx_ball_y;
  wire signed [3:0] tx_ball_vel_x, tx_ball_vel_y, rx_ball_vel_x, rx_ball_vel_y;
  
  // State
  wire        has_ball, has_ball_tx, has_ball_router, insync_tx, insync_router;
  
  // Handshake
  wire        rx_ball_valid, rx_ball_ack;                                             // Inbound
  wire        tx_ball_valid, tx_disabled, ball_tx_valid, del_ball_req, ball_del_act;  // Outbound
  
  // Graphics
  wire        vga_r0, vga_g0, vga_b0, vga_vsync, vga_r1, vga_g1, vga_b1, vga_hsync;
  wire [9:0]  hpos, vpos;
  wire        display_on, pixel;

  // ----- Module instances -----
  distributed_pong game_inst (
    .clk(clk), .rst_n(rst_n),
    .game_tick(game_tick),
    .move_up(move_up), .move_down(move_down), .id(id),
    .cmd_pause(cmd_pause),
    .rx_ball_valid(rx_ball_valid),
    .has_ball_router(has_ball_rx), .insync_router(insync_router),
    .rx_ball_x(rx_ball_x), .rx_ball_y(rx_ball_y),
    .rx_ball_vel_x(rx_ball_vel_x), .rx_ball_vel_y(rx_ball_vel_y),
    .del_ball_req(del_ball_req),
    .tx_ball_x(tx_ball_x), .tx_ball_y(tx_ball_y),
    .tx_ball_vel_x(tx_ball_vel_x), .tx_ball_vel_y(tx_ball_vel_y),
    .tx_disabled(tx_disabled), .rx_ball_ack(rx_ball_ack),
    .tx_ball_valid(tx_ball_valid), .ball_del_act(ball_del_act),
    .has_ball(has_ball), .ball_x(ball_x), .ball_y(ball_y), .paddle_y(paddle_y),
    .has_ball_tx(has_ball_tx)
  );

  router router_inst (
    .clk(clk), .rst_n(rst_n),
    .has_ball(has_ball), .tx_ball_valid(tx_ball_valid), 
    .tx_ball_x(tx_ball_x), .tx_ball_y(tx_ball_y),
    .tx_ball_vel_x(tx_ball_vel_x), .tx_ball_vel_y(tx_ball_vel_y),
    .tx_disabled(tx_disabled), .rx_ball_ack(rx_ball_ack),
    .ball_del_act(ball_del_act), .rx_ball_valid(rx_ball_valid),
    .rx_ball_x(rx_ball_x), .rx_ball_y(rx_ball_y),
    .rx_ball_vel_x(rx_ball_vel_x), .rx_ball_vel_y(rx_ball_vel_y),
    .del_ball_req(del_ball_req),
    .uart_rx_pin(uart_rx), .uart_tx_pin(uart_tx),
    .has_ball_rx(has_ball_rx), .insync_rx(insync_rx),
    .insync_tx(insync_tx), .has_ball_router(has_ball_router),
    .insync_router(insync_router), .id(id) ,.da(dab), .dc(dc)
  );

  graphic graphic_inst (
    .clk(clk), .rst_n(rst_n),
    .ball_x(ball_x), .ball_y(ball_y), .has_ball(has_ball), .paddle_y(paddle_y),
    .vga_hsync(vga_hsync), .vga_vsync(vga_vsync),
    .vga_r0(vga_r0), .vga_r1(vga_r1),
    .vga_g0(vga_g0), .vga_g1(vga_g1),
    .vga_b0(vga_b0), .vga_b1(vga_b1),
    .display_on(display_on), .hpos(hpos), .vpos(vpos), .pixel(pixel), .game_tick(game_tick)
  );
  
  // VGA screen output (for external DAC / monitor)
  assign sdl_sx = hpos;
  assign sdl_sy = vpos;
  assign sdl_de = display_on;
  assign sdl_r  = pixel ? 8'hFF : 8'h00;
  assign sdl_g  = pixel ? 8'hFF : 8'h00;
  assign sdl_b  = pixel ? 8'hFF : 8'h00;

endmodule

