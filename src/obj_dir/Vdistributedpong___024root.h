// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdistributedpong.h for the primary calling header

#ifndef VERILATED_VDISTRIBUTEDPONG___024ROOT_H_
#define VERILATED_VDISTRIBUTEDPONG___024ROOT_H_  // guard

#include "verilated.h"


class Vdistributedpong__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vdistributedpong___024root final : public VerilatedModule {
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
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__vga_hsync;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__vga_vsync;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__tx_busy;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__rx_ready;
        CData/*7:0*/ tt_um_llhtimlam_DistributedPong__DOT__rx_data;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__tx_send;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__packet_busy;
        CData/*7:0*/ tt_um_llhtimlam_DistributedPong__DOT__tx_data;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__rx_packet_ready;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__tx_small_rst;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__send_packet_reg;
        CData/*3:0*/ tt_um_llhtimlam_DistributedPong__DOT__packet_cmd;
        CData/*7:0*/ tt_um_llhtimlam_DistributedPong__DOT__packet_1;
        CData/*7:0*/ tt_um_llhtimlam_DistributedPong__DOT__packet_2;
        CData/*7:0*/ tt_um_llhtimlam_DistributedPong__DOT__packet_3;
        CData/*7:0*/ tt_um_llhtimlam_DistributedPong__DOT__packet_4;
        CData/*7:0*/ tt_um_llhtimlam_DistributedPong__DOT__tx_header;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__ack;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__ack_prev;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__ball_tx_ready;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__ball_rx_valid;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__ball_del_req;
        CData/*3:0*/ tt_um_llhtimlam_DistributedPong__DOT__rx_ball_vel_x;
        CData/*3:0*/ tt_um_llhtimlam_DistributedPong__DOT__rx_ball_vel_y;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__send_ack_packet;
        CData/*1:0*/ tt_um_llhtimlam_DistributedPong__DOT__insync_rx_sync;
        CData/*1:0*/ tt_um_llhtimlam_DistributedPong__DOT__has_ball_rx_sync;
        CData/*3:0*/ tt_um_llhtimlam_DistributedPong__DOT__gone_timer;
        CData/*3:0*/ tt_um_llhtimlam_DistributedPong__DOT__dup_timer;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__game_tick;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__booted;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__game_launch;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__pause;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__has_ball;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__ball_tx_valid;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__ball_rx_ack;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__ball_del_act;
        CData/*3:0*/ tt_um_llhtimlam_DistributedPong__DOT__tx_cd;
        CData/*1:0*/ tt_um_llhtimlam_DistributedPong__DOT__bounce_cd;
        CData/*3:0*/ tt_um_llhtimlam_DistributedPong__DOT__vel_x;
        CData/*3:0*/ tt_um_llhtimlam_DistributedPong__DOT__vel_y;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__collision_paddle_l;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__any_collision;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__ball_edge_l;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__ball_at_edge;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__vga_inst__DOT__hmaxxed;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__vga_inst__DOT__vmaxxed;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__uart_tx_inst__DOT__baud_tick;
        CData/*3:0*/ tt_um_llhtimlam_DistributedPong__DOT__uart_tx_inst__DOT__bit_idx;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__uart_rx_inst__DOT__baud_tick;
        CData/*3:0*/ tt_um_llhtimlam_DistributedPong__DOT__uart_rx_inst__DOT__bit_idx;
        CData/*7:0*/ tt_um_llhtimlam_DistributedPong__DOT__uart_rx_inst__DOT__shift;
    };
    struct {
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__uart_rx_inst__DOT__receiving;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__uart_rx_inst__DOT__rx_sync;
        CData/*1:0*/ tt_um_llhtimlam_DistributedPong__DOT__packet_sender_inst__DOT__state;
        CData/*2:0*/ tt_um_llhtimlam_DistributedPong__DOT__packet_sender_inst__DOT__byte_cnt;
        CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__packet_sender_inst__DOT__start_ff;
        CData/*1:0*/ tt_um_llhtimlam_DistributedPong__DOT__packet_receiver_inst__DOT__state;
        CData/*2:0*/ tt_um_llhtimlam_DistributedPong__DOT__packet_receiver_inst__DOT__byte_cnt;
        CData/*7:0*/ tt_um_llhtimlam_DistributedPong__DOT__packet_receiver_inst__DOT__running_ecc;
        CData/*7:0*/ tt_um_llhtimlam_DistributedPong__DOT__packet_receiver_inst__DOT____Vlvbound_hb2c8e3b0__0;
        CData/*1:0*/ __Vdly__tt_um_llhtimlam_DistributedPong__DOT__insync_rx_sync;
        CData/*1:0*/ __Vdly__tt_um_llhtimlam_DistributedPong__DOT__has_ball_rx_sync;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
        CData/*0:0*/ __VactContinue;
        VL_OUT16(sdl_sx,9,0);
        VL_OUT16(sdl_sy,9,0);
        SData/*9:0*/ tt_um_llhtimlam_DistributedPong__DOT__hpos;
        SData/*9:0*/ tt_um_llhtimlam_DistributedPong__DOT__vpos;
        SData/*9:0*/ tt_um_llhtimlam_DistributedPong__DOT__rx_ball_x;
        SData/*9:0*/ tt_um_llhtimlam_DistributedPong__DOT__rx_ball_y;
        SData/*9:0*/ tt_um_llhtimlam_DistributedPong__DOT__ball_x;
        SData/*9:0*/ tt_um_llhtimlam_DistributedPong__DOT__ball_y;
        SData/*9:0*/ tt_um_llhtimlam_DistributedPong__DOT__paddle_y;
        SData/*13:0*/ tt_um_llhtimlam_DistributedPong__DOT__uart_tx_inst__DOT__baud_counter;
        SData/*9:0*/ tt_um_llhtimlam_DistributedPong__DOT__uart_tx_inst__DOT__shift;
        SData/*13:0*/ tt_um_llhtimlam_DistributedPong__DOT__uart_rx_inst__DOT__baud_counter;
        IData/*31:0*/ __VactIterCount;
        QData/*39:0*/ tt_um_llhtimlam_DistributedPong__DOT__rx_packet_bytes;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vdistributedpong__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdistributedpong___024root(Vdistributedpong__Syms* symsp, const char* v__name);
    ~Vdistributedpong___024root();
    VL_UNCOPYABLE(Vdistributedpong___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
