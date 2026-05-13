// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtt_um_vga_example.h for the primary calling header

#ifndef VERILATED_VTT_UM_VGA_EXAMPLE___024ROOT_H_
#define VERILATED_VTT_UM_VGA_EXAMPLE___024ROOT_H_  // guard

#include "verilated.h"


class Vtt_um_vga_example__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtt_um_vga_example___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst_n,0,0);
        VL_IN8(ui_in,7,0);
        VL_OUT8(uo_out,7,0);
        VL_IN8(uio_in,7,0);
        VL_OUT8(uio_out,7,0);
        VL_OUT8(uio_oe,7,0);
        VL_IN8(ena,0,0);
        VL_OUT8(sdl_de,0,0);
        VL_OUT8(sdl_r,7,0);
        VL_OUT8(sdl_g,7,0);
        VL_OUT8(sdl_b,7,0);
        VL_OUT8(debug_1,0,0);
        VL_OUT8(debug_2,0,0);
        VL_OUT8(debug_3,0,0);
        VL_OUT8(debug_4,7,0);
        VL_OUT8(debug_5,0,0);
        VL_OUT8(debug_6,0,0);
        VL_OUT8(tx_sent,0,0);
        VL_OUT8(debug_game_tick,0,0);
        VL_OUT8(debug_baud_tick,0,0);
        VL_OUT8(debug_uart_tx,0,0);
        VL_OUT8(debug_uart_rx,0,0);
        VL_OUT8(debug_tx_sent,0,0);
        VL_OUT8(debug_tx_busy,0,0);
        VL_OUT8(debug_packet_busy,0,0);
        VL_OUT8(debug_tx_data,7,0);
        VL_OUT8(debug_rx_data,7,0);
        VL_OUT8(debug_rx_ball_vel_x,3,0);
        VL_OUT8(debug_rx_ball_vel_y,3,0);
        VL_OUT8(debug_rx_cmd,3,0);
        VL_OUT8(debug_ball_vel_x,3,0);
        VL_OUT8(debug_ball_vel_y,3,0);
        VL_OUT8(debug_rx_ack,3,0);
        VL_OUT8(debug_packet_cmd,3,0);
        VL_OUT8(debug_packet2,7,0);
        VL_OUT8(debug_txcd,3,0);
        VL_OUT8(debug_bounce_cd,1,0);
        VL_OUT8(debug_collision_paddle_r,0,0);
        VL_OUT8(debug_collision_paddle_l,0,0);
        VL_OUT8(debug_collision_paddle_y,0,0);
        VL_OUT8(debug_ball_tx,0,0);
        VL_OUT8(debug_ball_rx,0,0);
        VL_OUT8(debug_ack,0,0);
        VL_OUT8(debug_send_ack_packet,0,0);
        VL_OUT8(debug_send_packet,0,0);
        VL_OUT8(debug_rx_packet_ready,0,0);
        VL_OUT8(debug_has_ball,0,0);
        VL_OUT8(debug_has_ball_rx,0,0);
        VL_OUT8(state1,1,0);
        VL_OUT8(byte_cnt,2,0);
        VL_OUT8(bit_idx,3,0);
        CData/*0:0*/ tt_um_vga_example__DOT__vga_hsync;
        CData/*0:0*/ tt_um_vga_example__DOT__vga_vsync;
        CData/*0:0*/ tt_um_vga_example__DOT__tx_busy;
        CData/*0:0*/ tt_um_vga_example__DOT__rx_ready;
        CData/*7:0*/ tt_um_vga_example__DOT__rx_data;
        CData/*0:0*/ tt_um_vga_example__DOT__tx_send;
        CData/*0:0*/ tt_um_vga_example__DOT__packet_busy;
        CData/*7:0*/ tt_um_vga_example__DOT__tx_data;
        CData/*0:0*/ tt_um_vga_example__DOT__rx_packet_ready;
        CData/*0:0*/ tt_um_vga_example__DOT__tx_small_rst;
        CData/*0:0*/ tt_um_vga_example__DOT__send_packet_reg;
        CData/*3:0*/ tt_um_vga_example__DOT__packet_cmd;
    };
    struct {
        CData/*7:0*/ tt_um_vga_example__DOT__packet_1;
        CData/*7:0*/ tt_um_vga_example__DOT__packet_2;
        CData/*7:0*/ tt_um_vga_example__DOT__packet_3;
        CData/*7:0*/ tt_um_vga_example__DOT__packet_4;
        CData/*0:0*/ tt_um_vga_example__DOT__ack;
        CData/*0:0*/ tt_um_vga_example__DOT__ack_prev;
        CData/*0:0*/ tt_um_vga_example__DOT__ball_tx_ready;
        CData/*0:0*/ tt_um_vga_example__DOT__ball_rx_valid;
        CData/*0:0*/ tt_um_vga_example__DOT__ball_del_req;
        CData/*3:0*/ tt_um_vga_example__DOT__rx_ball_vel_x;
        CData/*3:0*/ tt_um_vga_example__DOT__rx_ball_vel_y;
        CData/*1:0*/ tt_um_vga_example__DOT__insync_rx_sync;
        CData/*1:0*/ tt_um_vga_example__DOT__has_ball_rx_sync;
        CData/*3:0*/ tt_um_vga_example__DOT__gone_timer;
        CData/*3:0*/ tt_um_vga_example__DOT__dup_timer;
        CData/*0:0*/ tt_um_vga_example__DOT__booted;
        CData/*0:0*/ tt_um_vga_example__DOT__game_launch;
        CData/*0:0*/ tt_um_vga_example__DOT__pause;
        CData/*0:0*/ tt_um_vga_example__DOT__has_ball;
        CData/*0:0*/ tt_um_vga_example__DOT__ball_tx_valid;
        CData/*0:0*/ tt_um_vga_example__DOT__ball_rx_ack;
        CData/*0:0*/ tt_um_vga_example__DOT__ball_del_act;
        CData/*3:0*/ tt_um_vga_example__DOT__tx_cd;
        CData/*1:0*/ tt_um_vga_example__DOT__bounce_cd;
        CData/*3:0*/ tt_um_vga_example__DOT__vel_x;
        CData/*3:0*/ tt_um_vga_example__DOT__vel_y;
        CData/*0:0*/ tt_um_vga_example__DOT__ball_edge_l;
        CData/*0:0*/ tt_um_vga_example__DOT__ball_at_edge;
        CData/*0:0*/ tt_um_vga_example__DOT__vga_inst__DOT__hmaxxed;
        CData/*0:0*/ tt_um_vga_example__DOT__vga_inst__DOT__vmaxxed;
        CData/*0:0*/ tt_um_vga_example__DOT__uart_rx_inst__DOT__baud_tick;
        CData/*3:0*/ tt_um_vga_example__DOT__uart_rx_inst__DOT__bit_idx;
        CData/*7:0*/ tt_um_vga_example__DOT__uart_rx_inst__DOT__shift;
        CData/*0:0*/ tt_um_vga_example__DOT__uart_rx_inst__DOT__receiving;
        CData/*0:0*/ tt_um_vga_example__DOT__uart_rx_inst__DOT__rx_sync;
        CData/*0:0*/ tt_um_vga_example__DOT__packet_sender_inst__DOT__start_ff;
        CData/*1:0*/ tt_um_vga_example__DOT__packet_receiver_inst__DOT__state;
        CData/*2:0*/ tt_um_vga_example__DOT__packet_receiver_inst__DOT__byte_cnt;
        CData/*7:0*/ tt_um_vga_example__DOT__packet_receiver_inst__DOT__running_ecc;
        CData/*7:0*/ tt_um_vga_example__DOT__packet_receiver_inst__DOT____Vlvbound_hedfcfc53__0;
        CData/*1:0*/ __Vdly__tt_um_vga_example__DOT__insync_rx_sync;
        CData/*1:0*/ __Vdly__tt_um_vga_example__DOT__has_ball_rx_sync;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
        CData/*0:0*/ __VactContinue;
        VL_OUT16(sdl_sx,9,0);
        VL_OUT16(sdl_sy,9,0);
        VL_OUT16(debug_rx_ball_x,9,0);
        VL_OUT16(debug_rx_ball_y,9,0);
        VL_OUT16(debug_ball_x,9,0);
        VL_OUT16(debug_ball_y,9,0);
        VL_OUT16(baud_counter,13,0);
        SData/*9:0*/ tt_um_vga_example__DOT__hpos;
        SData/*9:0*/ tt_um_vga_example__DOT__vpos;
        SData/*9:0*/ tt_um_vga_example__DOT__rx_ball_x;
        SData/*9:0*/ tt_um_vga_example__DOT__rx_ball_y;
        SData/*9:0*/ tt_um_vga_example__DOT__ball_x;
        SData/*9:0*/ tt_um_vga_example__DOT__ball_y;
        SData/*9:0*/ tt_um_vga_example__DOT__paddle_y;
        SData/*9:0*/ tt_um_vga_example__DOT__uart_tx_inst__DOT__shift;
        SData/*13:0*/ tt_um_vga_example__DOT__uart_rx_inst__DOT__baud_counter;
        IData/*31:0*/ __VactIterCount;
    };
    struct {
        VlUnpacked<CData/*7:0*/, 7> tt_um_vga_example__DOT__tx_packet_bytes;
        VlUnpacked<CData/*7:0*/, 5> tt_um_vga_example__DOT__rx_packet_bytes;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtt_um_vga_example__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtt_um_vga_example___024root(Vtt_um_vga_example__Syms* symsp, const char* v__name);
    ~Vtt_um_vga_example___024root();
    VL_UNCOPYABLE(Vtt_um_vga_example___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
