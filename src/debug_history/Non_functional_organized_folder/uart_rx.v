`include "config.vh"
`default_nettype none

/* verilator lint_off WIDTHTRUNC */
/* verilator lint_off WIDTHEXPAND */

module uart_rx (
  input  wire       clk, rst_n,
  input  wire       rx,   // serial input
  output reg  [7:0] data, // received byte
  output reg        ready // pulse(1) done reading
);
  
  // Clock
  wire baud_tick;     // UART Baudrate
  reg [13:0] baud_cnt;
  assign baud_tick = (baud_cnt == 0);

  reg [3:0] bit_idx;  // 0..9 (start, 8 data, stop)
  reg [7:0] shift;    // {8 data}
  reg receiving;
  reg rx_sync;        // synchroniser, detect start bit drop (0) with confidence
  always @(posedge clk) rx_sync <= rx;   // Double flip flop to avoid metastability
  // Timer Logic
  always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      baud_cnt <= 14'd0;
    end else if (receiving) begin
      // Wait full bit for next sample
      if (baud_tick) begin
        baud_cnt <= `BAUD_TICK;
      end else begin
        baud_cnt <= baud_cnt - 1'd1;
      end
    // Start sampling at half bit after rx start bit drop (0)
    end else if (!rx_sync) begin
      baud_cnt <= `HALF_BAUD_TICK; 
    end
  end
  
  // Shifter Logic
  always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      bit_idx   <= 4'd10;
      shift     <= 8'b0;
      data      <= 8'b0;
      receiving <= 1'b0;
      ready     <= 1'b0;
    end else begin
      ready <= 1'b0; // Idle
      // Detect rx start bit drop (0)
      if (!receiving && !rx_sync) begin
        bit_idx   <= 4'd0;
        receiving <= 1'b1;
      end else if (receiving && baud_tick) begin
        // Start bit
        if (bit_idx == 4'd0) begin
          bit_idx <= bit_idx + 1'b1;
        // Data bit
        end else if (bit_idx <= 4'd8) begin
          shift[bit_idx-1] <= rx_sync;
          bit_idx <= bit_idx + 1'b1;
        // Stop bit (ignore stop bit (1))
        end else begin
          data      <= shift;
          receiving <= 1'b0;
          ready     <= 1'b1;
        end
      end
    end
  end
endmodule

/* verilator lint_on WIDTHTRUNC */
/* verilator lint_on WIDTHEXPAND */
