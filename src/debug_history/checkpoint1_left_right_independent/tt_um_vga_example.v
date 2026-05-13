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
    input  wire       ena, clk_pix, sim_rst 
);
    wire reset = sim_rst; 
    wire hsync, vsync, display_on;
    wire [9:0] hpos, vpos;

    // --- MISSING DECLARATIONS ADDED HERE ---
    reg is_right_fpga;
    reg nego_done;
    reg [16:0] nego_timer;

    reg ball_at_edge_reg;
    always @(posedge clk_pix) begin
        if (reset) 
            ball_at_edge_reg <= 1'b0;
        else 
            ball_at_edge_reg <= is_right_fpga ? (ball_x <= 5) : (ball_x >= 315);
    end

    // --- AUTO-ID NEGOTIATION ---
    always @(posedge clk_pix) begin
        if (reset) begin
            is_right_fpga <= 0;
            nego_done <= 0;
            nego_timer <= 0;
        end else if (!nego_done) begin
            if (ui_in[7]) begin
                is_right_fpga <= 1'b1;
                nego_done <= 1'b1;
            end 
            else if (uio_in[0] == 1'b1) begin
                is_right_fpga <= 1'b1;
                nego_done <= 1'b1;
            end 
            else if (nego_timer == 17'h1FFFF) begin
                is_right_fpga <= 1'b0;
                nego_done <= 1'b1;
            end else begin
                nego_timer <= nego_timer + 1;
            end
        end
    end

    wire comm_sync_out;
    wire link_alive, spawn_trigger;
    wire [7:0] rx_y, rx_phys;
    reg [9:0] ball_x, ball_y;
    reg signed [3:0] vel_x, vel_y;
    reg [8:0] paddle_y;
    reg has_ball;

    hvsync_generator vga_inst (
        .clk(clk_pix), .reset(reset),
        .hsync(hsync), .vsync(vsync),
        .hpos(hpos), .vpos(vpos), .display_on(display_on),
        .sync_reset(spawn_trigger) 
    );

    always @(posedge vsync or posedge reset) begin
        if (reset || !nego_done) begin
            has_ball <= !is_right_fpga;
            ball_x <= is_right_fpga ? 330 : 310; 
            ball_y <= 240;
            vel_x <= is_right_fpga ? 4 : -4; 
            vel_y <= 2;
            paddle_y <= 210;
        end else if (has_ball) begin
            ball_x <= ball_x + {{6{vel_x[3]}}, vel_x}; 
            ball_y <= ball_y + {{6{vel_y[3]}}, vel_y};
            if (ball_y <= 10) begin vel_y <= 2; ball_y <= 11; end
            else if (ball_y >= 470) begin vel_y <= -2; ball_y <= 469; end

            if (!is_right_fpga) begin 
                if (vel_x < 0 && ball_x <= 20 && ball_x >= 10 && ball_y + 8 > paddle_y && ball_y < paddle_y + 60) begin
                    vel_x <= 4; ball_x <= 21;
                end
                if (ball_x <= 2) begin ball_x <= 160; vel_x <= 4; end
                if (ball_x >= 315) begin
                    if (link_alive) has_ball <= 1'b0;
                    else begin vel_x <= -4; ball_x <= 314; end 
                end
            end else begin 
                if (vel_x > 0 && ball_x >= 615 && ball_x <= 625 && ball_y + 8 > paddle_y && ball_y < paddle_y + 60) begin
                    vel_x <= -4; ball_x <= 614;
                end
                if (ball_x >= 638) begin ball_x <= 480; vel_x <= -4; end
                if (ball_x <= 325) begin
                    if (link_alive) has_ball <= 1'b0;
                    else begin vel_x <= 4; ball_x <= 326; end
                end
            end
        end else if (spawn_trigger) begin
            has_ball <= 1'b1;
            ball_x <= is_right_fpga ? 330 : 310;
            ball_y <= {rx_phys[7:6], rx_y}; 
            vel_x <= is_right_fpga ? 4 : -4; 
            vel_y <= { rx_phys[2], rx_phys[2:0] }; 
        end

        if (ui_in[0] && paddle_y > 4)   paddle_y <= paddle_y - 5;
        if (ui_in[1] && paddle_y < 416) paddle_y <= paddle_y + 5;
    end

    wire [9:0] paddle_x = is_right_fpga ? 620 : 10;
    wire my_territory = is_right_fpga ? (hpos >= 320) : (hpos < 320);
    wire ball_px = (hpos >= ball_x && hpos < ball_x+8 && vpos >= ball_y && vpos < ball_y+8);
    wire padd_px = (hpos >= paddle_x && hpos < paddle_x+8 && vpos >= {1'b0, paddle_y} && vpos < {1'b0, paddle_y}+10'd60);
    wire pixel = display_on && my_territory && ((has_ball && ball_px) || padd_px);

    assign uo_out = {hsync, {3{pixel}}, comm_sync_out, vsync, {2{pixel}}};
    
    wire [7:0] comm_bus_out, comm_bus_oe;
    assign uio_out = (!nego_done) ? 8'h01 : comm_bus_out;
    assign uio_oe  = (!nego_done && nego_timer > 17'h1F000 && !is_right_fpga) ? 8'hFF : comm_bus_oe;

    assign sdl_sx = hpos;
    assign sdl_sy = vpos;
    assign sdl_de = display_on;
    assign sdl_r  = pixel ? 8'hFF : 8'h00;
    assign sdl_g  = pixel ? 8'hFF : 8'h00;
    assign sdl_b  = pixel ? 8'hFF : 8'h00;

    chip_comm_manager comms (
        .clk(clk_pix), .reset(reset || !nego_done),
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
    output wire link_alive, 
    output reg [7:0] received_y, received_physics, output reg spawn_ball
);
    reg [1:0] tx_state, rx_state;
    reg [15:0] watchdog;
    reg in_sync_prev;

    always @(posedge clk) begin
        if (reset) begin watchdog <= 16'hFFFF; in_sync_prev <= 0; end
        else begin
            in_sync_prev <= in_sync_pin;
            if (in_sync_pin && !in_sync_prev) watchdog <= 0;
            else if (watchdog < 16'hFFFF) watchdog <= watchdog + 1;
        end
    end
    assign link_alive = (watchdog < 16'hA000); 
    reg [3:0] startup_delay;
    
    always @(posedge clk) begin
        if (reset) startup_delay <= 0;
        else if (vsync_trigger && startup_delay < 15) startup_delay <= startup_delay + 1;
    end

    always @(posedge clk) begin
        if (reset) begin tx_state <= 0; out_sync_pin <= 0; bus_oe <= 0; end
        else case(tx_state)
            0: if (ball_at_edge && link_alive && (startup_delay == 15)) begin 
                   out_sync_pin <= 1; bus_oe <= 8'hFF; bus_out <= ball_y[7:0]; tx_state <= 1; 
               end
            1: begin bus_out <= {ball_y[9:8], ball_phys[6:4], ball_phys[2:0]}; tx_state <= 2; end
            2: begin out_sync_pin <= 0; bus_oe <= 0; tx_state <= 3; end
            3: if (!ball_at_edge) tx_state <= 0;
            default: tx_state <= 0;
        endcase
    end

    always @(posedge clk) begin
        if (reset) begin rx_state <= 0; spawn_ball <= 0; end
        else if (in_sync_pin) begin
            case(rx_state)
                0: begin received_y <= bus_in; rx_state <= 1; end
                1: begin received_physics <= bus_in; spawn_ball <= 1; rx_state <= 2; end
                2: spawn_ball <= 0; 
                default: rx_state <= 0;
            endcase
        end else rx_state <= 0;
    end
endmodule