`default_nettype none

`include "config.vh"
`include "hvsync_generator.v"

module graphic (
  input  wire       clk, rst_n,
  // Game state from game_core
  input  wire [9:0] ball_x,
  input  wire [9:0] ball_y,
  input  wire       has_ball,
  input  wire [9:0] paddle_y,
  // VGA outputs
  output wire       vga_hsync,
  output wire       vga_vsync,
  output wire       vga_r0, vga_r1,
  output wire       vga_g0, vga_g1,
  output wire       vga_b0, vga_b1,
  // Optional: game tick
  output            display_on,
  output wire [9:0] hpos,
  output wire [9:0] vpos,
  output wire       pixel,
  output wire       game_tick
);

  // ---------- Sync generator ----------
  //wire        display_on;
  //wire [9:0]  hpos, vpos;

  hvsync_generator vga_inst (
    .clk(clk),
    .reset(~rst_n),
    .hsync(vga_hsync),
    .vsync(vga_vsync),
    .display_on(display_on),
    .hpos(hpos),
    .vpos(vpos)
  );
  
  assign game_tick = (hpos == 10'd0 && vpos == 10'd0);
  
  // Video output (TinyVGA)
  // ---------- Pixel generation ----------
  wire ball_px = (hpos >= ball_x - `BALL_RADIUS && hpos < ball_x + `BALL_RADIUS &&
                  vpos >= ball_y - `BALL_RADIUS && vpos < ball_y + `BALL_RADIUS);
  wire padd_px = (hpos >= `PADDLE_LEFT_EDGE && hpos < `PADDLE_RIGHT_EDGE &&
                  vpos >= paddle_y - `PADDLE_HALF_HEIGHT && vpos < paddle_y + `PADDLE_HALF_HEIGHT);
  assign pixel = display_on && ((has_ball && ball_px) || padd_px);
  
  // 2‑bit per colour (simple white on black)
  assign vga_r1 = pixel;
  assign vga_g1 = pixel;
  assign vga_b1 = pixel;
  assign vga_r0 = pixel;
  assign vga_g0 = pixel;
  assign vga_b0 = pixel;

endmodule
