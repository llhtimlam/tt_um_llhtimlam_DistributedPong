`include "config.vh"
`default_nettype none

/* verilator lint_off WIDTHTRUNC */
/* verilator lint_off WIDTHEXPAND */

module uart_tx (
  input   wire        clk, rst_n,
  input   wire        send,       // pulse(1) to send byte
  input   wire [7:0]  data,       // byte to send
  output  wire        tx,         // serial output
  output  reg         busy        // 1 while sending, 0 when idle
);
  
  // Clock
  wire baud_tick;   // UART Baudrate
  reg [13:0] baud_cnt;
  assign baud_tick = (baud_cnt == `BAUD_COUNTER);
  
  // Serialization
  reg [3:0] bit_idx;  // 0 ~ 9 bit (start, data, stop)
  reg [9:0] shift;    // {stop, data, start}

  // Pin Serialized Output
  assign tx = busy ? shift[0] : 1'b1;
  
  // Timer logic
  always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      baud_cnt <= 14'd0;
    end else if (busy) begin
      if (baud_tick)
        baud_cnt <= 14'd0;
      else
        baud_cnt <= baud_cnt + 1'b1;
    end else begin
      baud_cnt <= 14'd0;
    end
  end
  
  // Shifter logic
  always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      bit_idx <= 4'd0;
      shift   <= {10{1'b1}}; // Idle(1)
      busy    <= 1'b0;
    // Start bit
    end else if (!busy && send) begin
      bit_idx <= 4'd0;
      shift   <= {1'b1, data, 1'b0}; // Stop(1), Data, Start(0)
      busy    <= 1'b1;
    end else if (busy && baud_tick) begin
      if (bit_idx == 4'd9) begin
        bit_idx <= 4'd0;
        busy    <= 1'b0;
      end else begin
        bit_idx <= bit_idx + 1'b1;
        shift   <= {1'b1, shift[9:1]}; // Move to next bit
      end
    end
  end

endmodule

/* verilator lint_on WIDTHTRUNC */
/* verilator lint_on WIDTHEXPAND */
