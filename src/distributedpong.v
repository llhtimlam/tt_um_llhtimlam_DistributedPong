/*
 * Copyright (c) 2026 Tim Lam
 * SPDX-License-Identifier: Apache-2.0

`default_nettype none
`include "config.vh"

/* verilator lint_off UNUSEDSIGNAL */

module tt_um_llhtimlam_DistributedPong (
  input  wire [7:0] ui_in,    // Dedicated inputs: Paddle up(0), down(1), identity(7)
  output wire [7:0] uo_out,   // Dedicated outputs: TinyVGA: R1,G1,B1,vsync,R0,G0,B0,hsync
  input  wire [7:0] uio_in,   // IOs: Input path
  output wire [7:0] uio_out,  // IOs: Output path
  output wire [7:0] uio_oe,   // IOs: Enable path (active high: 0=input, 1=output)
  input  wire       ena,      // always 1 when the design is powered, so you can ignore it
  input  wire       clk,      // clock
  input  wire       rst_n     // reset_n - low to reset
);

  // Input Mapping
  wire move_up, move_down, id;
  assign move_up    = ui_in[0];
  assign move_down  = ui_in[1];
  //assign sel        = ui_in[2];
  assign id         = ui_in[7];

  // Output Graphics (Tiny VGA)
  wire vga_r0, vga_r1, vga_g0, vga_g1, vga_b0, vga_b1, vga_hsync, vga_vsync;
  assign uo_out[0]  = vga_r1;
  assign uo_out[1]  = vga_g1;
  assign uo_out[2]  = vga_b1;
  assign uo_out[3]  = vga_vsync;
  assign uo_out[4]  = vga_r0;
  assign uo_out[5]  = vga_g0;
  assign uo_out[6]  = vga_b0;
  assign uo_out[7]  = vga_hsync;

  // Bidirectional UART Configuration
  wire uart_tx, uart_rx, has_ball_rx, insync_rx;
  assign uio_oe     = 8'b01011101;  // [NOT INDEX] odd pins output (TX), even pins input (RX), value 1: Output 0: Input
  assign uio_out[0] = uart_tx;
  assign uart_rx    = uio_in[1];
  assign uio_out[4] = has_ball;
  assign has_ball_rx  = uio_in[5];
  assign uio_out[6] = 1'b1;         // insync_tx
  assign insync_rx  = uio_in[7];
  
  // Drive input pin 2 6 8 output low
  assign uio_out[1] = 1'b0;
  assign uio_out[5] = 1'b0;
  assign uio_out[7] = 1'b0;
  // Pin 34 is not used as logic is not implemented, set output and drive low
  assign uio_out[3:2] = 2'b00;
  
  // Graphic Generator
  wire        display_on;
  wire [9:0]  hpos, vpos;

  hvsync_generator vga_inst (
    .clk(clk), .reset(~rst_n),
    .hsync(vga_hsync), .vsync(vga_vsync),
    .display_on(display_on), .hpos(hpos), .vpos(vpos)
  );

  // UART interface (bidirectional)
  wire tx_busy, rx_ready;
  wire [7:0] rx_data;

  // UART modules
  uart_tx uart_tx_inst (
      .clk(clk), .rst_n(rst_n),
      .send(tx_send), .data(tx_data), .tx(uart_tx), .busy(tx_busy)
  );
  uart_rx uart_rx_inst (
      .clk(clk), .rst_n(rst_n),
      .rx(uart_rx), .data(rx_data), .ready(rx_ready)
  );

  // Packet sender / receiver (ball state exchange)
  // localparam DATA_BYTES = 5;
  // localparam MAX_BYTES  = DATA_BYTES + 2;  // start + data + checksum
  
  wire tx_send;
  wire packet_busy;

  wire [55:0] tx_packet_bytes; // 7 byte total length
  wire [7:0] tx_data;
  
  packet_sender packet_sender_inst (
    .clk(clk), .rst_n(rst_n),
    .start(send_packet_reg),
    .packet_bytes(tx_packet_bytes),
    .tx_send(tx_send), .tx_data(tx_data),
    .tx_busy(tx_busy), .busy(packet_busy)
  );

  wire rx_packet_ready;
  wire [39:0] rx_packet_bytes; // 5 byte total length

  packet_receiver packet_receiver_inst (
    .clk(clk), .rst_n(rst_n),
    .packet_bytes(rx_packet_bytes),
    .rx_ready(rx_ready), .rx_data(rx_data),
    .ready(rx_packet_ready)
  );

  // UART Protocol
  // Tx handler (clk domain)
  reg tx_small_rst;
  reg send_packet_reg;
  reg [3:0] packet_cmd;
  reg [7:0] packet_1, packet_2, packet_3, packet_4;
  
  // Assemble packet bytes (start, cmd, data, checksum)
  wire [7:0] tx_header = {packet_cmd, 3'b0, id};
  wire [7:0] tx_checksum = tx_header ^ packet_1 ^ packet_2 ^ packet_3 ^ packet_4;
  assign tx_packet_bytes[0  +: 8] = send_packet_reg ? 8'h55 : 8'h00; // start
  assign tx_packet_bytes[8  +: 8] = tx_header;  // Command(4) + ID(4)
  assign tx_packet_bytes[16 +: 8] = packet_1;
  assign tx_packet_bytes[24 +: 8] = packet_2;
  assign tx_packet_bytes[32 +: 8] = packet_3;
  assign tx_packet_bytes[40 +: 8] = packet_4;
  assign tx_packet_bytes[48 +: 8] = tx_checksum; // XOR checksum (8)

  // Tx ball transmission (clk domain)
  always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      tx_small_rst    <= 1'b0;
      send_packet_reg <= 1'b0;
      packet_cmd      <= 4'd0;
      packet_1        <= 8'd0;
      packet_2        <= 8'd0;
      packet_3        <= 8'd0;
      packet_4        <= 8'd0;
    end else begin
      tx_small_rst <= 1'b0;
      if (send_packet_reg) begin
        // Timeout or Tx busy
        if (!insync || packet_busy) begin
          send_packet_reg <= 1'b0;
        end
      // Tx trigger if idle
      end
      else begin
        // Tx Command Trigger (Bottom priority)
        // Acknowledgement command (1st)
        if (send_ack_packet) begin // Acknowledgement when ack drop from (1) to (0) receive Rx and deleted
          send_packet_reg <= 1'b1;
          packet_cmd  <= 4'hF; // Acknowledgement command
          // Acknowledgement to which command
          if (ball_rx_ack) begin
            packet_1  <= {4'h9, 4'd0}; // Ball transmission command
          end
          else begin
            packet_1  <= 8'd0; // Placeholder packet
          end
          packet_2 <= 8'd0;
          packet_3 <= 8'd0;
          packet_4 <= 8'd0;
        end
        // Ball transmission command
        else if (ball_tx_valid && tx_cd == 4'd0) begin
          send_packet_reg <= 1'b1;
          packet_cmd  <= 4'h9; // Ball transmission command
          // Ball State x(10), y(10), vel_x(4), vel_y(4)
          packet_1    <= ball_x[9:2];
          packet_2    <= {ball_x[1:0], ball_y[9:4]};
          packet_3    <= {ball_y[3:0], vel_x};
          packet_4    <= {vel_y, 4'b0};
        end
      if (ball_tx_ready) begin
        tx_small_rst    <= 1'b1;
        send_packet_reg <= 1'b0;
        packet_cmd      <= 4'd0;
        packet_1        <= 8'd0;
        packet_2        <= 8'd0;
        packet_3        <= 8'd0;
        packet_4        <= 8'd0;
      end
    end
  end

  // Rx handler (clk domain)
  reg ack, ack_prev;
  reg ball_tx_ready, ball_rx_valid, ball_del_req;
  reg [9:0] rx_ball_x, rx_ball_y;
  reg signed [3:0] rx_ball_vel_x, rx_ball_vel_y;
  
  // Send tx acknowledgement when ack drop from (1) to (0) (before next game tick)
  always @(posedge clk) ack_prev <= ack; // 2 clk tick
  wire send_ack_packet = (ack_prev && !ack && !send_packet_reg); // trigger acknowledgement command

  always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      ack           <= 1'b0;
      ball_tx_ready <= 1'b1;
      ball_rx_valid <= 1'b0;
      ball_del_req  <= 1'b0;
    end else begin
      // Decode rx_packet
      if (rx_packet_ready) begin
        case (rx_packet_bytes[7:4])
          // Ball Transmission
          4'h9: begin // Ball transmission command
            if (!has_ball && !ball_rx_valid) begin
              rx_ball_x     <= {rx_packet_bytes[8 +: 8],  rx_packet_bytes[16 +: 2]};
              rx_ball_y     <= {rx_packet_bytes[18 +: 6], rx_packet_bytes[24 +: 4]};
              rx_ball_vel_x <= rx_packet_bytes[28 +: 4];
              rx_ball_vel_y <= rx_packet_bytes[32 +: 4];
              ball_rx_valid <= 1'b1;
              ack           <= 1'b1;
            end
          end
          4'hF: begin // Acknowledgement command
            case (rx_packet_bytes[8 + 7 : 8 + 4])
              4'h9: begin // Ball transmission acknowledgement
                ball_tx_ready <= 1'b1;
                ball_del_req  <= 1'b1;
              end
              default: ;
            endcase
          end
          default: ;
        endcase
      end
      // Handshake reset (independent)
      // Reset after game physics spawn ball transmission
      if (ball_rx_ack) begin // (2 game tick)
        ball_rx_valid <= 1'b0;
        ack           <= 1'b0;
      end
      // Reset delete ball request
      if (ball_del_act) begin
        ball_del_req  <= 1'b0;
      end
      // Reset reset tx request
      if (tx_small_rst) begin
        ball_tx_ready <= 1'b0;
      end
    end
  end
  
  // Double Flip Flop (clk domain)
  reg [1:0] insync_rx_sync, has_ball_rx_sync;

  always @(posedge clk) begin
    // Shift bit (Only for Raw RX)
    insync_rx_sync <= {insync_rx_sync[0], insync_rx};
    has_ball_rx_sync <= {has_ball_rx_sync[0], has_ball_rx};
  end
  
  wire insync = insync_rx_sync[1];
  
  // Ball glitch logic
  // Timeout based detection
  reg [3:0] gone_timer, dup_timer;
  wire ball_gone  = (gone_timer == 4'd15);
  wire ball_dup   = (dup_timer == 4'd15);
  always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      gone_timer <= 4'd0;
      dup_timer  <= 4'd0;
    end else if (!pause && game_tick) begin
      // gone timer
      if (has_ball || has_ball_router)
        gone_timer <= 4'd0;
      else if (gone_timer < 4'd15)
        gone_timer <= gone_timer + 1'd1;
      // duplicated timer (both sides have ball)
      if (has_ball && has_ball_router) begin
        if (dup_timer < 4'd15) dup_timer <= dup_timer + 1'b1;
      end else
        dup_timer <= 4'd0;
    end
  end

  wire action_pause = 1'b0; // placeholder for pause logic

  // Game logic
  // Clock
  // Game Clock
  wire game_tick = (hpos == 10'd0 && vpos == 10'd0); // VSync as game tick

  // Game state (game domain)
  reg booted, game_launch;
  reg pause;
  reg has_ball;

  reg ball_tx_valid, ball_rx_ack, ball_del_act;

  reg [3:0] tx_cd;
  reg [1:0] bounce_cd;

  reg [9:0] ball_x, ball_y; // 0~1023
  reg signed [3:0] vel_x, vel_y; // +7~-8
  reg [9:0] paddle_y;       // 0~1023
  
  // Advanced Collision Check
  /*
  // integer r;
  //always @(*) begin
  //    for (r = 0; r < 12; r = r + 1) begin
  //        ball_slice[r] = current_ball_mask[r*12 + col_idx];
  //    end
  //end
  // wire [SIZE:0] ball_slice = get_ball_slice(ball_col);
  // wire [SIZE:0] paddle_slice = get_paddle_slice(paddle_col);
  // wire [SIZE:0] shifted_paddle = paddle_slice >> (ball_y - paddle_y);
  // wire collision = |(ball_slice & shifted_paddle);
  */
  
  // Paddle movement
  always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      paddle_y       <= 10'd240;
    end else if (!pause) begin
      if (game_tick) begin
        if (move_up && paddle_y > 10'd32)    paddle_y <= paddle_y - 10'd4;
        if (move_down && paddle_y < 10'd449)  paddle_y <= paddle_y + 10'd4;
      end
    end
  end

  always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      booted            <= 1'b0;
      game_launch       <= 1'b1;
      pause             <= 1'b0;
      has_ball          <= 1'b0;
      ball_tx_valid     <= 1'b0;
      ball_rx_ack       <= 1'b0;
      ball_del_act      <= 1'b0;
      ball_x            <= 10'd240;
      ball_y            <= 10'd120;
      vel_x             <= 4'sd3;
      vel_y             <= 4'sd2;
      tx_cd             <= 4'd0;
      bounce_cd         <= 2'd0;
    // Booting
    end else begin
      if (!booted) begin
        booted          <= 1'b1;
        game_launch     <= 1'b1;
      end else begin
        // Pause logic placeholder
        if (action_pause) begin
          pause <= ~pause;
        end
        if (!pause) begin
          if (game_tick) begin
            // Cooldown logic
            if (tx_cd != 0) begin // Transmission cooldown
                tx_cd <= tx_cd - 4'd1;
            end
            if (bounce_cd !=0) begin // Anti-sticking
              bounce_cd <= bounce_cd - 2'd1;
            end
            
            if (!ball_at_edge) begin // Not in edge
              ball_tx_valid <= 1'b0;
            end
            // Ball deletion logic, duplication and acknowledged transmission, send ball outside screen and keep it still
            if ((ball_dup && id) || ball_del_req) begin
              has_ball      <= 1'b0;
              ball_x        <= 10'd1023;
              ball_y        <= 10'd511;
              vel_x         <= 4'sd0;
              vel_y         <= 4'sd0;
              ball_tx_valid <= 1'b0;
              ball_del_act  <= 1'b1;
            end
            // Ball transmission
            else if (ball_rx_valid) begin
              has_ball      <= 1'b1;
              ball_x        <= 10'd640 - rx_ball_x;
              ball_y        <= rx_ball_y;
              vel_x         <= rx_ball_vel_x;
              vel_y         <= rx_ball_vel_y;
              tx_cd         <= 4'd15;
              bounce_cd     <= 2'd3;
              ball_rx_ack   <= 1'b1;
            end
            // Ball spawn logic
            else if ((ball_gone || game_launch) && !id) begin // Initial or Ball disappear
              game_launch   <= 1'b0;
              has_ball      <= 1'b1;
              ball_x        <= 10'd200;
              ball_y        <= 10'd150;
              vel_x         <= 4'sd7;
              vel_y         <= 4'sd2;
              ball_del_act  <= 1'b0;
            end
            else begin
              ball_rx_ack   <= 1'b0; // CDC game → clk
              ball_del_act  <= 1'b0;
            end
            // Ball physics
            if (has_ball) begin
              // Stop ball physics for ball transmission after cooldown
              if (ball_at_edge && insync && tx_cd == 4'd0) begin
                ball_tx_valid <= 1'b1; // Trigger ball transmission and stop ball physics
              end else begin
                // X axis physics
                // Connection fail safe
                if ((any_collision || ball_at_edge) && bounce_cd == 2'd0) begin
                  // Bounce if no connection
                  vel_x <= -vel_x;
                  bounce_cd <= 2'd3;
                  if (ball_at_edge) begin
                    if (ball_edge_l) begin
                      ball_x <= 10'd10;
                    end
                    else begin
                      ball_x <= 10'd470;
                    end
                  end
                  else begin
                    // Paddle collision
                    if (collision_paddle_l) begin
                      ball_x <= 10'd330;
                    end else begin
                      ball_x <= 10'd350;
                    end
                  end
                end else begin
                  ball_x <= ball_x + {{6{vel_x[3]}}, vel_x};// Arithmetic: 10 bit pos, 4 bit vel, take 4th sign bit and expand to largest bit
                end
                
                // Y axis physics
                ball_y <= ball_y + {{6{vel_y[3]}}, vel_y};
                // Top/bottom walls (vel_y[3] is UP, !vel_y[3] is DOWN)
                if (bounce_cd == 2'd0) begin
                  if (ball_y <= 10'd10 && vel_y[3]) begin // top wall
                    vel_y <= -vel_y;
                    ball_y <= 10'd15;
                    bounce_cd <= 2'd3;
                  end else if (ball_y >= 10'd630 && !vel_y[3]) begin // Bottom wall
                    vel_y <= -vel_y;
                    ball_y <= 10'd625;
                    bounce_cd <= 2'd3;
                  end
                end
              end
            end
          end
        end
      end
    end
  end
  
  // Collision detection
  wire collision_paddle_y = (ball_y + 10'd4 >= paddle_y - 10'd30) &&  // top hitbox
                            (ball_y - 10'd4 <= paddle_y + 10'd30);    // bottom hitbox
  wire collision_paddle_l = !vel_x[3]  && (ball_x >= 10'd305) && (ball_x <= 10'd315);
  wire collision_paddle_r = vel_x[3] && (ball_x <= 10'd335) && (ball_x >= 10'd325);

  wire any_collision = (collision_paddle_l || collision_paddle_r) && collision_paddle_y;
  
  // Edge detection
  wire ball_edge_l = (ball_x <= 10'd10);
  wire ball_edge_r = (ball_x >= 10'd630 && ball_x <= 10'd650); // Prevent out of screen
  wire ball_at_edge = (ball_edge_l || ball_edge_r);
  
  // Video output (TinyVGA pin mapping)
  wire ball_px = (hpos +  10'd4 >= ball_x && hpos <= ball_x + 10'd4 &&
                  vpos + 10'd4 >= ball_y  && vpos < ball_y + 10'd4);
  wire padd_px = (hpos >= 10'd315 && hpos < 10'd325 &&
                  vpos >= paddle_y - 10'd30 && vpos < paddle_y + 10'd30);
  wire pixel = display_on && ((has_ball && ball_px) || padd_px);
  
  assign vga_r1 = pixel;
  assign vga_g1 = pixel;
  assign vga_b1 = pixel;
  assign vga_r0 = pixel;
  assign vga_g0 = pixel;
  assign vga_b0 = pixel;

  // VGA screen output (for external DAC / monitor)
  // assign sdl_sx = hpos;
  // assign sdl_sy = vpos;
  // assign sdl_de = display_on;
  // assign sdl_r  = pixel ? 8'hFF : 8'h00;
  // assign sdl_g  = pixel ? 8'hFF : 8'h00;
  // assign sdl_b  = pixel ? 8'hFF : 8'h00;

  wire _unused = &{ena, 
                 rx_packet_bytes[39:36], rx_packet_bytes[3:0],
                 uio_in[6], uio_in[4:2], uio_in[0], ui_in[6:2],
                 1'b0};

endmodule
