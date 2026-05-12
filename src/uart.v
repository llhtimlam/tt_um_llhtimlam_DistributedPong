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

  wire        baud_tick;    // send tick (1: Send 0: Idle)
  reg [13:0]  baud_counter; // counts clock cycles 8192
  
  reg [3:0]   bit_idx;      // 0..9 (start, 8 data, stop)
  reg [9:0]   shift;        // {stop, data, start}

  assign baud_tick = (baud_counter == `BAUD_COUNTER); 

  // During busy, tx set to data bit; idle(1) otherwise
  assign tx = busy ? shift[0] : 1'b1;

  // Timer Logic
  always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      baud_counter <= 14'd0;
    end else if (busy) begin
      // Reset baud_counter for next baud interval
      if (baud_tick) begin
        baud_counter <= 14'd0;
      end else begin
        baud_counter <= baud_counter + 1'b1;
      end
    end else begin
      // Turn off baud_counter when tx completed
      baud_counter <= 14'd0;
    end
  end
  
  // Shifter Logic
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
      // Stop bit
      if (bit_idx == 4'd9) begin
        bit_idx <= 4'd0; 
        busy    <= 1'b0;
      // Data bit
      end else begin
        bit_idx <= bit_idx + 1'b1;
        shift <= {1'b1, shift[9:1]}; // Move to next bit
      end
    end
  end
endmodule

module uart_rx (
  input  wire       clk, rst_n,
  input  wire       rx,          // serial input
  output reg  [7:0] data,        // received byte
  output reg        ready        // pulse(1) done reading
);
  
  wire        baud_tick;     // sample tick (1: Sample 0: Idle)
  reg [13:0]  baud_counter; // counts clock cycles 8192
  
  reg [3:0]   bit_idx;      // 0..9 (start, 8 data, stop)
  reg [7:0]   shift;        // {8 data}
  reg         receiving;
  
  assign baud_tick = (baud_counter == 0);

  reg        rx_sync;       // synchroniser, detect start bit drop (0) with confidence
  always @(posedge clk) rx_sync <= rx;   // Double flip flop to avoid metastability

  // Timer Logic
  always @(posedge clk or negedge rst_n) begin
      if (!rst_n) begin
          baud_counter <= 14'd0;
      end else if (receiving) begin
          // Wait full bit for next sample
          if (baud_tick) begin
              baud_counter <= `BAUD_TICK;
          end else begin
              baud_counter <= baud_counter - 1'b1;
          end
      // Start sampling at half bit after rx start bit drop (0)
      end else if (!rx_sync) begin
          baud_counter <= `HALF_BAUD_TICK; 
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

/*
reg [7:0] tx_packet[0:5];
// Byte 0: start
tx_packet[0] = 8'h55;
// Bytes 1..4: your data (e.g., function+id, X, Y, velocity)
tx_packet[1] = {cmd, id};
tx_packet[2] = x_low;
tx_packet[3] = {x_high, y_high, vx};
tx_packet[4] = y_low;
// Byte 5: checksum (XOR of bytes 1..4)
tx_packet[5] = tx_packet[1] ^ tx_packet[2] ^ tx_packet[3] ^ tx_packet[4];


module packet_sender (
  input  wire       clk, rst_n,
  input  wire       start,            // pulse(1) to send packet
  input  wire [7:0] packet_bytes [0:6], // packet to send
  output reg        tx_send,          // pulse uart_tx(.send) 
  output reg [7:0] tx_data,          // bitstream uart_tx(.data)
  input  wire       tx_busy,          // status uart_tx(.busy)
  output reg        busy              // 1 while sending, 0 when idle
);

  reg [1:0] state;
  reg [2:0] byte_cnt;

  reg [14:0] timeout;
  
  reg start_ff;   // edge detect

  // Edge detection for start (ensure single-cycle pulse)
  wire start_rising = start && !start_ff;
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
      tx_send <= 1'b0; // default: pulse is only one cycle
      case (state)
        0: begin
          if (start_ff && !tx_busy) begin // start_ff && !tx_busy
            byte_cnt <= 3'd0;
            state <= 2'd1;
            busy <= 1'b1;
          end
        end
        1: begin  // send current byte
            tx_data = packet_bytes[byte_cnt];
            tx_send <= 1'b1;  // Pulse(1) trigger uart_tx
            state <= 2'd2;    // Wait for TX to start
        end
        2: begin  // wait for UART to start (tx_busy=1)
          tx_send <= 1'b0;
          if (tx_busy) begin // Wait for TX to acknowledge and turn busy for next tick
            state <= 2'd3;
          end
        end
        3: begin  // wait for UART to finish (tx_busy=0)
          if (!tx_busy) begin          // Wait for TX to finish, proceed next byte after sent and idle
            //timeout <= 4'd0; // Reset timeout after send
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

module packet_receiver (
  input  wire           clk, rst_n,
  output reg  [7:0]     packet_bytes [0:4],
  input  wire           rx_ready,     // pulse uart_rx(.ready) after reading byte
  input  wire [7:0]     rx_data,      // bitstream uart_rx(.data)
  output reg            ready        // pulse(1) done reading packet
);
  
  reg [1:0] state;   // 0=wait_start, 1=get_data, 2=verify
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
            if (byte_cnt == 4)
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

/* verilator lint_on WIDTHTRUNC */
/* verilator lint_on WIDTHEXPAND */
