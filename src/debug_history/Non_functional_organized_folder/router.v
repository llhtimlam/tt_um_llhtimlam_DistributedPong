`default_nettype none

`include "config.vh"
`include "uart_tx.v"
`include "uart_rx.v"
`include "packet_sender.v"
`include "packet_receiver.v"

module router (
  input  wire         clk, rst_n,
  // Interface to game_core
  input  reg          has_ball,
  input  wire         tx_ball_valid,      // from game_core: pulse rx ball
  input  wire [9:0]   tx_ball_x,
  input  wire [9:0]   tx_ball_y,
  input  wire signed  [3:0] tx_ball_vel_x,
  input  wire signed  [3:0] tx_ball_vel_y,
  input  wire         tx_disabled,      // from game_core: disable tx ball
  input  reg          rx_ball_ack,      // from game_core: acknowledge tx ball receipt
  input  reg          ball_del_act,     // from game_core: deleted ball
  output reg          rx_ball_valid,    // to game_core: pulse tx ball
  output reg  [9:0]   rx_ball_x,
  output reg  [9:0]   rx_ball_y,
  output reg signed [3:0] rx_ball_vel_x,
  output reg signed [3:0] rx_ball_vel_y,
  output reg          del_ball_req,     // tell game_core to delete local ball
  // Physical UART pins (bidirectional)
  input  wire         uart_rx_pin,
  output wire         uart_tx_pin,
  // Status from remote (via uio)
  input  wire         has_ball_rx,
  input  wire         insync_rx,
  output wire         insync_tx,
  // Status: Double flip flop treated
  output wire         has_ball_router,  
  output wire         insync_router,
  // ID for packet assembly
  input  wire         id,
  output reg [2:0] da,
  output reg [7:0] dc
);
  reg [2:0] db;
  assign da = db;
  assign dc = tx_packet_bytes[0];
  // ---------- UART core instances ----------
  wire        tx_busy, rx_ready;
  wire [7:0]  rx_data;
  reg         tx_send;
  reg  [7:0]  tx_data;

  uart_tx uart_tx_inst (
    .clk(clk), .rst_n(rst_n),
    .send(tx_send), .data(tx_data), .tx(uart_tx_pin),
    .busy(tx_busy)
  );
  uart_rx uart_rx_inst (
    .clk(clk), .rst_n(rst_n),
    .rx(uart_rx_pin), .data(rx_data), .ready(rx_ready)
  );

  // ---------- Packet sender / receiver ----------
  localparam DATA_BYTES = 5;
  localparam MAX_BYTES  = DATA_BYTES + 2;

  wire        send_packet;
  reg         send_packet_reg;
  wire        packet_busy;
  wire [7:0]  tx_packet_bytes [0:MAX_BYTES-1];
  wire [7:0]  tx_packet_data;

  packet_sender #(.MAX_BYTES(MAX_BYTES)) packet_sender_inst (
    .clk(clk), .rst_n(rst_n),
    .start(send_packet_reg),
    .packet_bytes(tx_packet_bytes),
    .tx_send(tx_send), .tx_data(tx_packet_data),
    .tx_busy(tx_busy), .busy(packet_busy), .byte_cnt(db)
  );

  wire        rx_packet_ready;
  wire [7:0]  rx_packet_bytes [0:DATA_BYTES-1];

  packet_receiver #(.DATA_BYTES(DATA_BYTES)) packet_receiver_inst (
    .clk(clk), .rst_n(rst_n),
    .packet_bytes(rx_packet_bytes),
    .rx_ready(rx_ready), .rx_data(rx_data),
    .ready(rx_packet_ready)
  );

  // ---------- TX packet assembly ----------
  reg  [3:0]  packet_cmd;
  reg  [7:0]  packet_1, packet_2, packet_3, packet_4;
  
  wire [7:0] tx_header = {packet_cmd, 3'b0, id};
  wire [7:0] tx_checksum = tx_header ^ packet_1 ^ packet_2 ^ packet_3 ^ packet_4;

  assign tx_packet_bytes[0] = 8'h55; // send_packet_reg ? 8'h55 : 8'h00; // Start Byte
  assign tx_packet_bytes[1] = tx_header;    // Command(4) + ID(4)
  assign tx_packet_bytes[2] = packet_1;     // Data Byte 1
  assign tx_packet_bytes[3] = packet_2;     // Data Byte 2
  assign tx_packet_bytes[4] = packet_3;     // Data Byte 3
  assign tx_packet_bytes[5] = packet_4;     // Data Byte 4
  assign tx_packet_bytes[6] = tx_checksum;  // XOR checksum (8)

  // ---------- TX state machine ----------
  reg ack, ack_prev;
  reg tx_small_rst;
  always @(posedge clk) ack_prev <= ack;
  wire send_ack_packet = (ack_prev && !ack && !send_packet_reg);   // falling edge of ack
  
  reg tx_ball_ready;
  
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
      tx_small_rst <= 1'b0; // Default low
      // abort if link lost or still busy
      if (send_packet_reg) begin
        if (!insync_router || packet_busy) begin 
          send_packet_reg <= 1'b0;
        end
      end else begin
        // 1st Priority: ACK packet
        if (send_ack_packet) begin
          send_packet_reg <= 1'b1;
          // Response
          packet_cmd <= 4'hF;                     // ACK command
          if (rx_ball_ack)
            packet_1 <= {4'h9, 4'd0};             // Ball Tx command
          else
            packet_1 <= {4'h0, 4'd0};             // Placeholder
          packet_2   <= 8'd0;
          packet_3   <= 8'd0;
          packet_4   <= 8'd0;
        end
        // 2nd Priority: Reset
        // 3rd Priority: Win
        // 4th Priority: Death
        // 5th Priority: Connection
        // 6th Priority: Network consensus
        // 7th Priority: Pause
        // 8th Priority: Ball Tx
        else if (tx_ball_valid) begin
          send_packet_reg <= 1'b1;
          packet_cmd <= 4'h9;       // ball command
          // Ball State x(10), y(10), vel_x(4), vel_y(4)
          packet_1   <= tx_ball_x[9:2];
          packet_2   <= {tx_ball_x[1:0], tx_ball_y[9:4]};
          packet_3   <= {tx_ball_y[3:0], tx_ball_vel_x};
          packet_4   <= {tx_ball_vel_y, 4'b0};
        end
      end
      if (tx_ball_ready) begin // Need more thought on acknowledge based tx memory wipe
        tx_small_rst    <= 1'b1;
        if (packet_cmd == 4'h9) begin
          packet_cmd    <= 4'd0;
          packet_1      <= 8'd0;
          packet_2      <= 8'd0;
          packet_3      <= 8'd0;
          packet_4      <= 8'd0;
        end
      end
    end
  end

  // ---------- RX packet decoding ----------
  always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      ack           <= 1'b0;
      tx_ball_ready <= 1'b1;
      rx_ball_valid <= 1'b0;
      rx_ball_x     <= 10'd0;
      rx_ball_y     <= 10'd0;
      rx_ball_vel_x <= 4'sd0;
      rx_ball_vel_y <= 4'sd0;
      del_ball_req  <= 1'b0;
    end else begin
      // Decode rx_packet
      if (rx_packet_ready) begin
        case (rx_packet_bytes[0][7:4])
          // Ball Transmission
          4'h9: begin // Ball transmission command
            if (!has_ball && !rx_ball_valid) begin
              rx_ball_x     <= {rx_packet_bytes[1], rx_packet_bytes[2][7:6]};
              rx_ball_y     <= {rx_packet_bytes[2][5:0], rx_packet_bytes[3][7:4]};
              rx_ball_vel_x <= rx_packet_bytes[3][3:0];
              rx_ball_vel_y <= rx_packet_bytes[4][7:4];
              rx_ball_valid <= 1'b1;
              ack           <= 1'b1;
            end
          end
          4'hF: begin   // ACK command
            case (rx_packet_bytes[1][7:4])
              4'h9: begin // Ball transmission acknowledgement
                tx_ball_ready <= 1'b1;
                del_ball_req  <= 1'b1;
              end
              default: ;
            endcase
          end
          default: ;
        endcase
      end
      // Handshake reset (independent)
      // Reset after game physics spawn ball transmission
      if (rx_ball_ack) begin // (2 game tick)
        rx_ball_valid <= 1'b0;
        ack           <= 1'b0;
      end
      // Reset delete ball request
      if (ball_del_act) begin
        del_ball_req  <= 1'b0;
      end
      // Toggle off acknowledgement after tx memory wipe
      if (tx_small_rst) begin
        tx_ball_ready <= 1'b0;
      end
    end
  end
  
  // ---------- Double flip flop for metastability -----------
  reg [1:0] insync_rx_sync, has_ball_rx_sync;
  reg [3:0] timeout;
  always @(posedge clk) begin
    has_ball_rx_sync <= {has_ball_rx_sync[0], has_ball_rx};
    insync_rx_sync <= {insync_rx_sync[0], insync_rx};
  end
  
  assign has_ball_router = has_ball_rx_sync[1];
  assign insync_router = insync_rx_sync[1];
  
  // ---------- Status outputs for cross‑connection ----------
  assign insync_tx   = 1'b1;          // always (1)

endmodule
