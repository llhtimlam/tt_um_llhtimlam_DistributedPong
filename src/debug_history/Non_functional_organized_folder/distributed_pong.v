`default_nettype none

/* verilator lint_off WIDTHTRUNC */
/* verilator lint_off WIDTHEXPAND */

`include "config.vh"

module distributed_pong (
  input  wire        clk, rst_n,
  input  wire        game_tick,          // Game clock
  input  wire        move_up,
  input  wire        move_down,
  input  wire        id,                  // 0 = left, 1 = right
  // Inputs from router
  input  wire        cmd_pause,           // from router: pause command
  input  wire        rx_ball_valid,       // transmit new rx ball
  input  wire        has_ball_router,     // router has ball
  input  wire        insync_router,       // FPGA Connection (1)
  input  wire [9:0]  rx_ball_x,
  input  wire [9:0]  rx_ball_y,
  input  wire signed [3:0] rx_ball_vel_x,
  input  wire signed [3:0] rx_ball_vel_y,
  input  wire        del_ball_req,        // from router: ball deletion
  // Outputs to router
  output reg  [9:0]  tx_ball_x,
  output reg  [9:0]  tx_ball_y,
  output reg signed [3:0] tx_ball_vel_x,
  output reg signed [3:0] tx_ball_vel_y,
  output wire        tx_disabled,         // to router: disable tx ball
  output reg         rx_ball_ack,         // to router: acknowledge rx ball
  output reg         tx_ball_valid,       // ready to transmit ball to router
  output reg         ball_del_act,        // to router: acknowledge tx ball
  // Game state outputs to graphic
  output reg         has_ball,
  output reg  [9:0]  ball_x,
  output reg  [9:0]  ball_y,
  output reg  [9:0]  paddle_y,
  // Status from remote (via uio)
  output wire         has_ball_tx
);

    // ---------- Internal registers ----------
    reg         booted;
    reg         game_launch;
    reg         pause;
    reg signed [3:0] vel_x, vel_y;
    reg  [9:0]  paddle_x;
    reg  [3:0]  tx_cd;
    reg  [1:0]  bounce_cd;
    reg  [3:0]  gone_timer, dup_timer;

    // ---------- Ball timeout / duplicate detection ----------
    wire ball_gone = (gone_timer == 4'd15);
    wire ball_dup  = (dup_timer == 4'd15);
    assign tx_disabled = (tx_cd == 4'd0);

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

    // ---------- Paddle movement ----------
    always @(posedge clk or negedge rst_n) begin
      if (!rst_n) begin
        paddle_x <= `PADDLE_X;
        paddle_y <= 10'd240;
      end else if (!pause && game_tick) begin
        if (move_up && paddle_y > `PADDLE_UPPER_BOUND)
          paddle_y <= paddle_y - 10'd4;
        if (move_down && paddle_y < `PADDLE_LOWER_BOUND)
          paddle_y <= paddle_y + 10'd4;
      end
    end

  // ---------- Game state machine (boot, launch, ball physics) ----------
  always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      booted        <= 1'b0;
      game_launch   <= 1'b1;
      pause         <= 1'b0;
      has_ball      <= 1'b0;
      ball_x        <= 10'd240;
      ball_y        <= 10'd80;
      vel_x         <= 4'sd3;
      vel_y         <= 4'sd2;
      tx_ball_x     <= 10'sd40;
      tx_ball_y     <= 10'sd240;
      tx_ball_vel_x <= 4'sd4;
      tx_ball_vel_y <= -4'sd2;
      tx_cd         <= 4'd0;
      bounce_cd     <= 2'd0;
      tx_ball_valid <= 1'b0;
      rx_ball_ack   <= 1'b0;
      ball_del_act  <= 1'b0;
    end else begin
      // Boot sequence
      if (!booted) begin
        booted      <= 1'b1;
        game_launch <= 1'b1;
      end else begin
        if (cmd_pause) begin
          pause <= ~pause;
        end
        if (!pause) begin
          if (game_tick) begin
            // Cooldowns
            if (tx_cd != 0)     tx_cd <= tx_cd - 4'd1;
            if (bounce_cd != 0) bounce_cd <= bounce_cd - 2'd1;
            if (!ball_at_edge)  tx_ball_valid <= 1'b0;
            
            // Ball deletion on duplication or remote request
            if ((ball_dup && id) || del_ball_req) begin
              has_ball      <= 1'b0;
              ball_x        <= 10'd1023;
              ball_y        <= 10'd511;
              vel_x         <= 4'sd0;
              vel_y         <= 4'sd0;
              tx_ball_valid <= 1'b0;
              ball_del_act  <= 1'b1;
            end
            // Receive a ball from router
            else if (rx_ball_valid) begin
              has_ball  <= 1'b1;
              ball_x    <= `H_DISPLAY - rx_ball_x;;
              ball_y    <= rx_ball_y;
              vel_x     <= rx_ball_vel_x;
              vel_y     <= rx_ball_vel_y;
              tx_cd     <= 4'd15;
              bounce_cd <= 2'd3;
              rx_ball_ack   <= 1'b1;      // acknowledge receipt
            end
            // Spawn new ball on id 0 when ball timeout or game starts
            else if ((ball_gone || game_launch) && !id) begin
              game_launch   <= 1'b0;
              has_ball      <= 1'b1;
              ball_x        <= 10'd600;
              ball_y        <= 10'd400;
              vel_x         <= 4'sd7;
              vel_y         <= 4'sd5;
              ball_del_act  <= 1'b0;
            end
            else begin
              rx_ball_ack   <= 1'b0;      // Reset acknowledge receipt
              ball_del_act  <= 1'b0;
            end
            // Ball physics (only if we have the ball)
            if (has_ball) begin
              // Stop ball physics for ball transmission after cooldown
              if (ball_at_edge && insync_router && tx_disabled) begin
                tx_ball_valid <= 1'b1; // Trigger ball transmission and stop ball physics
                // Record ball physics for transmission
                tx_ball_x     <= ball_x;
                tx_ball_y     <= ball_y;
                tx_ball_vel_x <= vel_x;
                tx_ball_vel_y <= vel_y;
              end else begin
                // X movement
                if ((any_collision || ball_at_edge) && bounce_cd == 2'd0) begin
                    vel_x <= -vel_x;
                    bounce_cd <= 2'd3;
                  if (ball_at_edge) begin
                    if (ball_edge_l) begin
                      ball_x <= `HIT_WINDOW;
                    end
                    else begin
                      ball_x <= `RIGHT_HIT_WINDOW;
                    end
                  end
                  else begin
                    // Paddle collision
                    if (collision_paddle_l) begin
                      ball_x <= `PADDLE_LEFT_SPAWN_X;
                    end else begin
                      ball_x <= `PADDLE_RIGHT_SPAWN_X;
                    end
                  end
                end else begin
                  ball_x <= ball_x + {{6{vel_x[3]}}, vel_x};// Arithmetic: 10 bit pos, 4 bit vel, take 4th sign bit and expand to largest bit
                end
                
                // Y movement
                ball_y <= ball_y + {{6{vel_y[3]}}, vel_y};
                // Top/bottom walls (vel_y[3] is UP, !vel_y[3] is DOWN)
                if (bounce_cd == 2'd0) begin
                  if (ball_y <= `HIT_WINDOW && vel_y[3]) begin // top wall
                    vel_y <= -vel_y;
                    ball_y <= `BALL_TOP_SPAWN_Y;
                    bounce_cd <= 2'd3;
                  end else if (ball_y >= `BOTTOM_HIT_WINDOW && !vel_y[3]) begin // Bottom wall
                    vel_y <= -vel_y;
                    ball_y <= `BALL_BOTTOM_SPAWN_Y;
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

  // ---------- Collision detection ----------
  wire collision_paddle_y = (ball_y + `BALL_RADIUS >= paddle_y - `PADDLE_HALF_HEIGHT) &&
                            (ball_y - `BALL_RADIUS <= paddle_y + `PADDLE_HALF_HEIGHT);
  wire collision_paddle_l = !vel_x[3]  && ((ball_x >= `PADDLE_LEFT_HIT_X) && (ball_x <= `PADDLE_LEFT_EDGE));
  wire collision_paddle_r = vel_x[3] && ((ball_x <= `PADDLE_RIGHT_HIT_X) && (ball_x >= `PADDLE_RIGHT_EDGE));
  wire any_collision = (collision_paddle_l || collision_paddle_r) && collision_paddle_y;
  
  // Edge detection
  wire ball_edge_l = (ball_x <= `HIT_WINDOW);
  wire ball_edge_r = (ball_x >= `RIGHT_HIT_WINDOW && ball_x <= `RIGHT_EDGE); // Prevent out of screen
  wire ball_at_edge = (ball_edge_l || ball_edge_r);
  
  // ---------- Status outputs for cross‑connection ----------
  assign has_ball_tx = has_ball;

endmodule
