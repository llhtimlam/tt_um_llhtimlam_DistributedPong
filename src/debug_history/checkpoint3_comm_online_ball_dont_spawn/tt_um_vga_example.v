`default_nettype none

module tt_um_vga_example (
    input  wire [7:0] ui_in,    
    output wire [7:0] uo_out,   
    input  wire [7:0] uio_in,   
    output wire [7:0] uio_out,  
    output wire [7:0] uio_oe,   
    output wire [9:0] sdl_sx,
    output wire [9:0] sdl_sy,
    output wire       sdl_de,
    output wire [7:0] sdl_r,    
    output wire [7:0] sdl_g,    
    output wire [7:0] sdl_b,    
    input  wire       ena, clk_pix, sim_rst,
    output wire       nego_done,
    output wire       is_right_fpga
);
    wire reset = sim_rst; 
    wire hsync, vsync, display_on;
    wire [9:0] hpos, vpos;

    reg is_right_fpga_reg;
    reg nego_done_reg;
    reg [16:0] nego_timer;

    assign is_right_fpga = is_right_fpga_reg;
    assign nego_done = nego_done_reg;

    reg ball_at_edge_reg;
    reg [9:0] ball_x, ball_y;
    reg signed [3:0] vel_x, vel_y;
    reg [8:0] paddle_y;
    reg has_ball;
    
    wire [7:0] ball_phys = {vel_x, vel_y};

    // Edge detection (wide window)
    always @(posedge clk_pix) begin
        if (reset) begin
            ball_at_edge_reg <= 1'b0;
        end else if (!nego_done_reg) begin
            ball_at_edge_reg <= 1'b0;
        end else if (has_ball) begin
            if (!is_right_fpga_reg)
                ball_at_edge_reg <= (ball_x >= 310 && ball_x <= 330);
            else
                ball_at_edge_reg <= (ball_x <= 330 && ball_x >= 310);
        end else begin
            ball_at_edge_reg <= 1'b0;
        end
    end

    // Negotiation
    always @(posedge clk_pix) begin
        if (reset) begin
            is_right_fpga_reg <= 0;
            nego_done_reg <= 0;
            nego_timer <= 0;
        end else if (!nego_done_reg) begin
            if (ui_in[7]) begin
                is_right_fpga_reg <= 1'b1;
                nego_done_reg <= 1'b1;
            end else if (nego_timer == 17'h1FFFF) begin
                is_right_fpga_reg <= 1'b0;
                nego_done_reg <= 1'b1;
            end else begin
                nego_timer <= nego_timer + 1;
            end
        end
    end

    hvsync_generator vga_inst (
        .clk(clk_pix), .reset(reset),
        .hsync(hsync), .vsync(vsync),
        .hpos(hpos), .vpos(vpos), .display_on(display_on),
        .sync_reset(1'b0)
    );

    // ------------------------------------------------------------------
    //  Communication manager
    // ------------------------------------------------------------------
    wire comm_sync_out;
    wire link_alive;
    wire spawn_ready;          // level signal: data ready to be read
    wire [9:0] received_y;
    wire [7:0] rx_phys;
    wire spawn_clear;

    chip_comm_manager comms (
        .clk(clk_pix), .reset(reset || !nego_done_reg),
        .out_sync_pin(comm_sync_out), .in_sync_pin(ui_in[3]),
        .bus_in(uio_in), .bus_out(uio_out), .bus_oe(uio_oe),
        .vsync_trigger(vsync), .ball_at_edge(ball_at_edge_reg),
        .ball_y(ball_y), .ball_phys(ball_phys),
        .link_alive(link_alive), .received_y(received_y), 
        .received_physics(rx_phys), .spawn_ready(spawn_ready),
        .spawn_clear(spawn_clear)
    );

    // ------------------------------------------------------------------
    //  Game logic – uses level‑triggered spawn_ready
    // ------------------------------------------------------------------
    reg game_started;
    reg spawn_acked;
    
    always @(posedge vsync or posedge reset) begin
        if (reset) begin
            has_ball <= 0;
            ball_x <= 310;
            ball_y <= 240;
            vel_x <= -3;
            vel_y <= 2;
            paddle_y <= 210;
            game_started <= 0;
            spawn_acked <= 0;
        end else if (!nego_done_reg) begin
            has_ball <= 0;
            game_started <= 0;
            spawn_acked <= 0;
        end else begin
            // Acknowledge spawn after we use it
            spawn_acked <= spawn_ready && !has_ball;
            
            // Spawn if data is ready and we don't have the ball
            if (spawn_ready && !has_ball) begin
                has_ball <= 1;
                ball_y <= {received_y};
                vel_x <= rx_phys[7:4];
                vel_y <= rx_phys[3:0];
                ball_x <= is_right_fpga_reg ? 320 : 310;
                game_started <= 1;
            end
            
            // Initial ball on left only
            if (!game_started && !has_ball && is_right_fpga_reg == 0) begin
                has_ball <= 1;
                ball_x <= 310;
                ball_y <= 240;
                vel_x <= -3;
                vel_y <= 2;
                game_started <= 1;
            end
            
            // Ball movement
            if (has_ball) begin
                ball_x <= ball_x + {{6{vel_x[3]}}, vel_x}; 
                ball_y <= ball_y + {{6{vel_y[3]}}, vel_y};
                
                if (ball_y <= 10) begin vel_y <= 2; ball_y <= 11; end
                else if (ball_y >= 470) begin vel_y <= -2; ball_y <= 469; end

                if (!is_right_fpga_reg) begin 
                    if (vel_x < 0 && ball_x <= 20 && ball_x >= 10 && 
                        ball_y + 8 > paddle_y && ball_y < paddle_y + 60) begin
                        vel_x <= 3; ball_x <= 21;
                    end
                    if (ball_x <= 2) begin 
                        ball_x <= 160; vel_x <= 3; 
                    end
                    if (ball_x >= 315) has_ball <= 1'b0;
                end else begin 
                    if (vel_x > 0 && ball_x >= 615 && ball_x <= 625 && 
                        ball_y + 8 > paddle_y && ball_y < paddle_y + 60) begin
                        vel_x <= -3; ball_x <= 614;
                    end
                    if (ball_x >= 638) begin 
                        ball_x <= 480; vel_x <= -3; 
                    end
                    if (ball_x <= 325) has_ball <= 1'b0;
                end
            end
        end

        if (ui_in[0] && paddle_y > 4)   paddle_y <= paddle_y - 4;
        if (ui_in[1] && paddle_y < 416) paddle_y <= paddle_y + 4;
    end

    // Connect the clear signal
    assign spawn_clear = spawn_acked;

    // ------------------------------------------------------------------
    //  Video output
    // ------------------------------------------------------------------
    wire [9:0] paddle_x = is_right_fpga_reg ? 620 : 10;
    wire my_territory = is_right_fpga_reg ? (hpos >= 320) : (hpos < 320);
    wire ball_px = (hpos >= ball_x && hpos < ball_x+8 && vpos >= ball_y && vpos < ball_y+8);
    wire padd_px = (hpos >= paddle_x && hpos < paddle_x+8 && vpos >= {1'b0, paddle_y} && vpos < {1'b0, paddle_y}+60);
    wire pixel = display_on && my_territory && ((has_ball && ball_px) || padd_px);

    assign uo_out = {hsync, pixel, pixel, pixel, comm_sync_out, vsync, ball_at_edge_reg, has_ball};
    assign sdl_sx = hpos;
    assign sdl_sy = vpos;
    assign sdl_de = display_on;
    assign sdl_r  = pixel ? 8'hFF : 8'h00;
    assign sdl_g  = pixel ? 8'hFF : 8'h00;
    assign sdl_b  = pixel ? 8'hFF : 8'h00;
endmodule


module hvsync_generator (
    input wire clk, reset, sync_reset,
    output wire hsync, vsync, display_on,
    output wire [9:0] hpos, vpos
);
    reg [9:0] h_cnt, v_cnt;
    always @(posedge clk) begin
        if (reset || sync_reset) {h_cnt, v_cnt} <= 0;
        else if (h_cnt < 799) h_cnt <= h_cnt + 1;
        else begin
            h_cnt <= 0;
            v_cnt <= (v_cnt < 524) ? v_cnt + 1 : 0;
        end
    end
    assign hsync = ~(h_cnt >= 656 && h_cnt < 752);
    assign vsync = ~(v_cnt >= 490 && v_cnt < 492);
    assign display_on = (h_cnt < 640 && v_cnt < 480);
    assign hpos = h_cnt; assign vpos = v_cnt;
endmodule


module chip_comm_manager (
    input wire clk, reset,
    output reg out_sync_pin, input wire in_sync_pin,
    input wire [7:0] bus_in, output reg [7:0] bus_out, output reg [7:0] bus_oe,
    input wire vsync_trigger, ball_at_edge,
    input wire [9:0] ball_y, input wire [7:0] ball_phys,
    output reg link_alive, 
    output reg [9:0] received_y,
    output reg [7:0] received_physics,
    output reg spawn_ready,
    input  wire spawn_clear
);
    reg [1:0] state;           // transmit state
    reg [15:0] watchdog;
    reg in_sync_prev;
    reg edge_detected;
    reg last_ball_at_edge;

    // Receive state machine
    reg [1:0] rx_state;        // 0=idle, 1=got first byte, 2=got second byte
    reg [7:0] rx_byte1;
    reg [7:0] rx_byte2;

    // Watchdog
    always @(posedge clk) begin
        if (reset) begin
            watchdog <= 0;
            in_sync_prev <= 0;
            link_alive <= 1;
        end else begin
            in_sync_prev <= in_sync_pin;
            if (in_sync_pin && !in_sync_prev) begin
                watchdog <= 0;
                link_alive <= 1;
            end else if (watchdog < 50000) begin
                watchdog <= watchdog + 1;
                link_alive <= 1;
            end else begin
                link_alive <= 0;
            end
        end
    end

    // Edge detection for transmit
    always @(posedge clk) begin
        if (reset) begin
            last_ball_at_edge <= 0;
            edge_detected <= 0;
        end else begin
            last_ball_at_edge <= ball_at_edge;
            if (ball_at_edge && !last_ball_at_edge && !edge_detected) begin
                edge_detected <= 1;
            end
            if (state == 3) edge_detected <= 0;
        end
    end

    // Transmit state machine
    always @(posedge clk) begin
        if (reset) begin
            state <= 0;
            out_sync_pin <= 0;
            bus_oe <= 0;
            bus_out <= 0;
        end else begin
            case(state)
                0: if (edge_detected) begin
                        out_sync_pin <= 1;
                        bus_oe <= 8'hFF;
                        bus_out <= ball_y[7:0];
                        state <= 1;
                    end
                1: begin
                        bus_out <= {ball_y[9:8], ball_phys[7:5], ball_phys[3:1]};
                        state <= 2;
                    end
                2: begin
                        out_sync_pin <= 0;
                        state <= 3;
                    end
                3: begin
                        bus_oe <= 0;
                        state <= 0;
                    end
                default: state <= 0;
            endcase
        end
    end

    // Receive state machine – uses separate registers, no shift register
    always @(posedge clk) begin
        if (reset) begin
            rx_state <= 0;
            spawn_ready <= 0;
            received_y <= 0;
            received_physics <= 0;
            rx_byte1 <= 0;
            rx_byte2 <= 0;
        end else begin
            // Clear spawn_ready when acknowledged
            if (spawn_clear) begin
                spawn_ready <= 0;
            end

            // On rising edge of sync, reset the receiver
            if (in_sync_pin && !in_sync_prev) begin
                rx_state <= 0;
                rx_byte1 <= 0;
                rx_byte2 <= 0;
            end

            // Sample the bus while sync is high
            if (in_sync_pin) begin
                case (rx_state)
                    0: begin
                        rx_byte1 <= bus_in;
                        rx_state <= 1;
                    end
                    1: begin
                        rx_byte2 <= bus_in;
                        rx_state <= 2;
                        // Reconstruct 10-bit Y and physics
                        received_y <= {rx_byte2[7:6], rx_byte1};
                        received_physics <= {rx_byte2[5:3], 1'b0, rx_byte2[2:0], 1'b0};
                        spawn_ready <= 1;
                    end
                    default: ;
                endcase
            end
        end
    end
endmodule