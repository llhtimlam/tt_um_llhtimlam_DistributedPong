`default_nettype none

module packet_sender #(
  parameter MAX_BYTES = 7
)(
  input  wire       clk, rst_n,
  input  wire       start,      // pulse(1) to send packet
  input  wire [7:0] packet_bytes [0:MAX_BYTES-1], // packet to send
  output reg        tx_send,    // pulse to uart_tx(.send) 
  output wire [7:0] tx_data,    // bitstream uart_tx(.data)
  input  wire       tx_busy,    // status uart_tx(.busy)
  output reg        busy,        // 1 while sending, 0 when idle
  output reg [2:0] byte_cnt
);
  
  reg [1:0] state;
  //reg [2:0] byte_cnt;
  
  // Start pulse flip flop
  reg start_ff;
  wire start_pulse = start && !start_ff;
  always @(posedge clk or negedge rst_n) begin
    if (!rst_n) start_ff <= 1'b0;
    else start_ff <= start;
  end
  
  // State Logic
  always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      state     <= 2'd0;
      tx_send   <= 1'b0;
      busy      <= 1'b0;
      byte_cnt  <= 3'd0;
    end else begin
      tx_send <= 1'b0; // 1 tick pulse
      case (state)
        0: begin
          if (start_ff && !tx_busy) begin // Start_ff && !tx_busy
            byte_cnt <= 3'd0;
            state <= 2'd1;
            busy <= 1'b1;
          end
        end
        1: begin  // Send current byte
            tx_data = packet_bytes[byte_cnt];
            tx_send <= 1'b1;  // Pulse(1) trigger uart_tx
            state <= 2'd2;    // Wait for TX to start
        end
        2: begin  // Wait for UART to start (tx_busy=1)
          tx_send <= 1'b0;
          if (tx_busy) begin // Wait for TX to acknowledge and turn busy for next tick
            state <= 2'd3;
          end
        end
        3: begin  // wait for UART to finish (tx_busy=0)
          if (!tx_busy) begin   // Wait for TX to finish, proceed next byte after sent and idle
            if (byte_cnt == MAX_BYTES - 3'd1) begin // Reset when last byte
              state <= 2'd0;
              busy <= 1'b0;
            // Progress to next byte
            end else begin
              byte_cnt <= byte_cnt + 1'b1;
              state <= 2'd1;
            end
          end
        end
      endcase
    end
  end
endmodule
