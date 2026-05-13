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
    
    // Simple edge detection
    always @(posedge clk_pix) begin
        if (reset) begin
            ball_at_edge_reg <= 1'b0;
        end else if (!nego_done_reg) begin
            ball_at_edge_reg <= 1'b0;
        end else if (has_ball) begin
            if (!is_right_fpga_reg) begin
                ball_at_edge_reg <= (ball_x >= 310 && ball_x <= 320);
            end else begin
                ball_at_edge_reg <= (ball_x <= 320 && ball_x >= 310);
            end
        end else begin
            ball_at_edge_reg <= 1'b0;
        end
    end

    // Negotiation - simplified
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

    wire comm_sync_out;
    wire link_alive;
    wire spawn_trigger;
    wire [7:0] rx_y, rx_phys;

    hvsync_generator vga_inst (
        .clk(clk_pix), .reset(reset),
        .hsync(hsync), .vsync(vsync),
        .hpos(hpos), .vpos(vpos), .display_on(display_on),
        .sync_reset(spawn_trigger) 
    );

    // Game logic
    always @(posedge vsync or posedge reset) begin
        if (reset) begin
            has_ball <= 0;
            ball_x <= 310;
            ball_y <= 240;
            vel_x <= -3;
            vel_y <= 2;
            paddle_y <= 210;
        end else if (!nego_done_reg) begin
            has_ball <= 0;
        end else if (!has_ball && !spawn_trigger && is_right_fpga_reg == 0) begin
            has_ball <= 1;
            ball_x <= 310;
            ball_y <= 240;
        end else if (has_ball) begin
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
                if (ball_x >= 315 && link_alive) begin
                    has_ball <= 1'b0;
                end
                if (ball_x >= 315 && !link_alive) begin 
                    vel_x <= -3; ball_x <= 314; 
                end
            end else begin 
                if (vel_x > 0 && ball_x >= 615 && ball_x <= 625 && 
                    ball_y + 8 > paddle_y && ball_y < paddle_y + 60) begin
                    vel_x <= -3; ball_x <= 614;
                end
                if (ball_x >= 638) begin 
                    ball_x <= 480; vel_x <= -3; 
                end
                if (ball_x <= 325 && link_alive) begin
                    has_ball <= 1'b0;
                end
                if (ball_x <= 325 && !link_alive) begin 
                    vel_x <= 3; ball_x <= 326; 
                end
            end
        end else if (spawn_trigger) begin
            has_ball <= 1'b1;
            ball_x <= is_right_fpga_reg ? 330 : 310;
            ball_y <= {rx_phys[7:6], rx_y}; 
            vel_x <= is_right_fpga_reg ? 3 : -3; 
            vel_y <= { rx_phys[2], rx_phys[2:0] }; 
        end

        if (ui_in[0] && paddle_y > 4)   paddle_y <= paddle_y - 4;
        if (ui_in[1] && paddle_y < 416) paddle_y <= paddle_y + 4;
    end

    wire [9:0] paddle_x = is_right_fpga_reg ? 620 : 10;
    wire my_territory = is_right_fpga_reg ? (hpos >= 320) : (hpos < 320);
    wire ball_px = (hpos >= ball_x && hpos < ball_x+8 && vpos >= ball_y && vpos < ball_y+8);
    wire padd_px = (hpos >= paddle_x && hpos < paddle_x+8 && vpos >= {1'b0, paddle_y} && vpos < {1'b0, paddle_y}+10'd60);
    wire pixel = display_on && my_territory && ((has_ball && ball_px) || padd_px);

    assign uo_out = {hsync, pixel, pixel, pixel, (nego_done_reg ? comm_sync_out : 1'b0), vsync, ball_at_edge_reg, has_ball};
    
    wire [7:0] comm_bus_out, comm_bus_oe;
    assign uio_out = comm_bus_out;
    assign uio_oe = comm_bus_oe;

    assign sdl_sx = hpos;
    assign sdl_sy = vpos;
    assign sdl_de = display_on;
    assign sdl_r  = pixel ? 8'hFF : 8'h00;
    assign sdl_g  = pixel ? 8'hFF : 8'h00;
    assign sdl_b  = pixel ? 8'hFF : 8'h00;

    chip_comm_manager comms (
        .clk(clk_pix), .reset(reset || !nego_done_reg),
        .out_sync_pin(comm_sync_out), .in_sync_pin(ui_in[3]),
        .bus_in(uio_in), .bus_out(comm_bus_out), .bus_oe(comm_bus_oe),
        .vsync_trigger(vsync), .ball_at_edge(ball_at_edge_reg),
        .ball_y(ball_y), .ball_phys({vel_x, vel_y}),
        .link_alive(link_alive), .received_y(rx_y), 
        .received_physics(rx_phys), .spawn_ball(spawn_trigger)
    );
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
    output reg [7:0] received_y, received_physics, output reg spawn_ball
);
    reg [2:0] state;
    reg [15:0] watchdog;
    reg in_sync_prev;
    reg edge_detected;
    reg last_ball_at_edge;
    
    // Detect sync pulses from other FPGA to determine link_alive
    always @(posedge clk) begin
        if (reset) begin
            watchdog <= 0;
            in_sync_prev <= 0;
            link_alive <= 0;
        end else begin
            in_sync_prev <= in_sync_pin;
            if (in_sync_pin && !in_sync_prev) begin
                watchdog <= 0;
                link_alive <= 1;
            end else if (watchdog < 50000) begin
                watchdog <= watchdog + 1;
            end else begin
                link_alive <= 0;
            end
        end
    end
    
    // Edge detection - trigger only on rising edge of ball_at_edge
    always @(posedge clk) begin
        if (reset) begin
            last_ball_at_edge <= 0;
            edge_detected <= 0;
        end else begin
            last_ball_at_edge <= ball_at_edge;
            // Detect rising edge
            if (ball_at_edge && !last_ball_at_edge && !edge_detected) begin
                edge_detected <= 1;
            end
        end
    end
    
    // Transmit when ball reaches edge (one-shot)
    always @(posedge clk) begin
        if (reset) begin
            state <= 0;
            out_sync_pin <= 0;
            bus_oe <= 0;
            bus_out <= 0;
        end else begin
            case(state)
                0: if (edge_detected && link_alive) begin
                        out_sync_pin <= 1;
                        state <= 1;
                    end
                1: begin
                        bus_oe <= 8'hFF;
                        bus_out <= ball_y[7:0];
                        state <= 2;
                    end
                2: begin
                        bus_out <= {ball_y[9:8], ball_phys[6:4], ball_phys[2:0]};
                        state <= 3;
                    end
                3: begin
                        out_sync_pin <= 0;
                        state <= 4;
                    end
                4: begin
                        bus_oe <= 0;
                        edge_detected <= 0;
                        state <= 0;
                    end
                default: state <= 0;
            endcase
        end
    end
    
    // Receive - one-shot on sync pulse
    always @(posedge clk) begin
        if (reset) begin
            spawn_ball <= 0;
            received_y <= 0;
            received_physics <= 0;
        end else begin
            spawn_ball <= 0;
            // Trigger only on rising edge of sync
            if (in_sync_pin && !in_sync_prev) begin
                received_y <= bus_in;
                received_physics <= bus_in;
                spawn_ball <= 1;
            end
        end
    end
endmodule