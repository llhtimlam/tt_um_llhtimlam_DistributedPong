`default_nettype none

module packet_receiver #(
  parameter DATA_BYTES = 5
) (
  input  wire           clk, rst_n,
  output reg  [7:0]     packet_bytes [0:DATA_BYTES-1],
  input  wire           rx_ready, // pulse from uart_rx(.ready) after reading byte
  input  wire [7:0]     rx_data,  // bitstream from uart_rx(.data)
  output reg            ready     // pulse(1) done reading packet
);

  reg [1:0] state;   // 0: wait, 1: data, 2: verify
  reg [2:0] byte_cnt;
  reg [7:0] running_ecc;
  
  // Control Logic (Counter & ECC Check)
  always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      state       <= 2'd0;
      byte_cnt    <= 3'd0;
      running_ecc <= 8'd0;
      ready       <= 1'b0;
    end else begin
      ready       <= 1'b0; // Idle
      // Concatenate packet_bytes after uart_rx finish reading
      if (rx_ready) begin
        case (state)
          0: begin // Start Byte
            if (rx_data == 8'h55) begin
              state       <= 2'd1;
              byte_cnt    <= 3'd0;
              running_ecc <= 8'd0;
            end
          end
          1: begin // Message Byte
            packet_bytes[byte_cnt] <= rx_data;
            running_ecc <= running_ecc ^ rx_data;
            if (byte_cnt == DATA_BYTES - 1)
              state <= 2'd2;
            else
              byte_cnt <= byte_cnt + 3'd1;
          end
          2: begin // ECC Check
            if (running_ecc == rx_data)
              ready <= 1'b1;
            state <= 2'd0; // Idle until next Start Byte
          end
          default: ;
        endcase
      end
    end
  end
endmodule
