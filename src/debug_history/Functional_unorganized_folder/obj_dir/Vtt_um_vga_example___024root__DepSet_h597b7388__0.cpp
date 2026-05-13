// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtt_um_vga_example.h for the primary calling header

#include "Vtt_um_vga_example__pch.h"
#include "Vtt_um_vga_example___024root.h"

void Vtt_um_vga_example___024root___ico_sequent__TOP__0(Vtt_um_vga_example___024root* vlSelf);

void Vtt_um_vga_example___024root___eval_ico(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___eval_ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vtt_um_vga_example___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtt_um_vga_example___024root___ico_sequent__TOP__0(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___ico_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ tt_um_vga_example__DOT__tx_header;
    tt_um_vga_example__DOT__tx_header = 0;
    // Body
    vlSelfRef.debug_uart_rx = (1U & ((IData)(vlSelfRef.uio_in) 
                                     >> 1U));
    vlSelfRef.debug_has_ball_rx = (1U & ((IData)(vlSelfRef.uio_in) 
                                         >> 5U));
    vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__hmaxxed 
        = (1U & ((~ (IData)(vlSelfRef.rst_n)) | (0x31fU 
                                                 == (IData)(vlSelfRef.tt_um_vga_example__DOT__hpos))));
    vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__vmaxxed 
        = (1U & ((~ (IData)(vlSelfRef.rst_n)) | (0x20cU 
                                                 == (IData)(vlSelfRef.tt_um_vga_example__DOT__vpos))));
    tt_um_vga_example__DOT__tx_header = (((IData)(vlSelfRef.tt_um_vga_example__DOT__packet_cmd) 
                                          << 4U) | 
                                         (1U & ((IData)(vlSelfRef.ui_in) 
                                                >> 7U)));
    vlSelfRef.tt_um_vga_example__DOT__tx_packet_bytes[1U] 
        = tt_um_vga_example__DOT__tx_header;
    vlSelfRef.tt_um_vga_example__DOT__tx_packet_bytes[6U] 
        = ((IData)(tt_um_vga_example__DOT__tx_header) 
           ^ ((IData)(vlSelfRef.tt_um_vga_example__DOT__packet_1) 
              ^ ((IData)(vlSelfRef.tt_um_vga_example__DOT__packet_2) 
                 ^ ((IData)(vlSelfRef.tt_um_vga_example__DOT__packet_3) 
                    ^ (IData)(vlSelfRef.tt_um_vga_example__DOT__packet_4)))));
}

void Vtt_um_vga_example___024root___eval_triggers__ico(Vtt_um_vga_example___024root* vlSelf);

bool Vtt_um_vga_example___024root___eval_phase__ico(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___eval_phase__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtt_um_vga_example___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vtt_um_vga_example___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtt_um_vga_example___024root___eval_act(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtt_um_vga_example___024root___nba_sequent__TOP__0(Vtt_um_vga_example___024root* vlSelf);
void Vtt_um_vga_example___024root___nba_sequent__TOP__1(Vtt_um_vga_example___024root* vlSelf);
void Vtt_um_vga_example___024root___nba_sequent__TOP__2(Vtt_um_vga_example___024root* vlSelf);
void Vtt_um_vga_example___024root___nba_comb__TOP__0(Vtt_um_vga_example___024root* vlSelf);

void Vtt_um_vga_example___024root___eval_nba(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtt_um_vga_example___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtt_um_vga_example___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtt_um_vga_example___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtt_um_vga_example___024root___nba_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtt_um_vga_example___024root___nba_sequent__TOP__0(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__tt_um_vga_example__DOT__insync_rx_sync 
        = vlSelfRef.tt_um_vga_example__DOT__insync_rx_sync;
    vlSelfRef.__Vdly__tt_um_vga_example__DOT__has_ball_rx_sync 
        = vlSelfRef.tt_um_vga_example__DOT__has_ball_rx_sync;
    vlSelfRef.__Vdly__tt_um_vga_example__DOT__insync_rx_sync 
        = ((2U & ((IData)(vlSelfRef.tt_um_vga_example__DOT__insync_rx_sync) 
                  << 1U)) | (1U & ((IData)(vlSelfRef.uio_in) 
                                   >> 7U)));
    vlSelfRef.__Vdly__tt_um_vga_example__DOT__has_ball_rx_sync 
        = ((2U & ((IData)(vlSelfRef.tt_um_vga_example__DOT__has_ball_rx_sync) 
                  << 1U)) | (IData)(vlSelfRef.debug_has_ball_rx));
    vlSelfRef.tt_um_vga_example__DOT__vga_hsync = (1U 
                                                   & (~ 
                                                      ((0x290U 
                                                        <= (IData)(vlSelfRef.tt_um_vga_example__DOT__hpos)) 
                                                       & (0x2efU 
                                                          >= (IData)(vlSelfRef.tt_um_vga_example__DOT__hpos)))));
    vlSelfRef.tt_um_vga_example__DOT__vga_vsync = (1U 
                                                   & (~ 
                                                      ((0x1eaU 
                                                        <= (IData)(vlSelfRef.tt_um_vga_example__DOT__vpos)) 
                                                       & (0x1ebU 
                                                          >= (IData)(vlSelfRef.tt_um_vga_example__DOT__vpos)))));
    if (vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__hmaxxed) {
        vlSelfRef.tt_um_vga_example__DOT__hpos = 0U;
        vlSelfRef.tt_um_vga_example__DOT__vpos = ((IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__vmaxxed)
                                                   ? 0U
                                                   : 
                                                  (0x3ffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelfRef.tt_um_vga_example__DOT__vpos))));
    } else {
        vlSelfRef.tt_um_vga_example__DOT__hpos = (0x3ffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelfRef.tt_um_vga_example__DOT__hpos)));
    }
    vlSelfRef.tt_um_vga_example__DOT__ack_prev = vlSelfRef.tt_um_vga_example__DOT__ack;
    vlSelfRef.sdl_sx = vlSelfRef.tt_um_vga_example__DOT__hpos;
    vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__hmaxxed 
        = (1U & ((~ (IData)(vlSelfRef.rst_n)) | (0x31fU 
                                                 == (IData)(vlSelfRef.tt_um_vga_example__DOT__hpos))));
    vlSelfRef.sdl_sy = vlSelfRef.tt_um_vga_example__DOT__vpos;
    vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__vmaxxed 
        = (1U & ((~ (IData)(vlSelfRef.rst_n)) | (0x20cU 
                                                 == (IData)(vlSelfRef.tt_um_vga_example__DOT__vpos))));
    vlSelfRef.sdl_de = ((0x280U > (IData)(vlSelfRef.tt_um_vga_example__DOT__hpos)) 
                        & (0x1e0U > (IData)(vlSelfRef.tt_um_vga_example__DOT__vpos)));
}

VL_INLINE_OPT void Vtt_um_vga_example___024root___nba_sequent__TOP__1(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___nba_sequent__TOP__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ tt_um_vga_example__DOT__tx_header;
    tt_um_vga_example__DOT__tx_header = 0;
    CData/*0:0*/ __Vdly__tt_um_vga_example__DOT__tx_small_rst;
    __Vdly__tt_um_vga_example__DOT__tx_small_rst = 0;
    CData/*0:0*/ __Vdly__tt_um_vga_example__DOT__send_packet_reg;
    __Vdly__tt_um_vga_example__DOT__send_packet_reg = 0;
    CData/*0:0*/ __Vdly__tt_um_vga_example__DOT__ball_rx_valid;
    __Vdly__tt_um_vga_example__DOT__ball_rx_valid = 0;
    CData/*3:0*/ __Vdly__tt_um_vga_example__DOT__gone_timer;
    __Vdly__tt_um_vga_example__DOT__gone_timer = 0;
    CData/*3:0*/ __Vdly__tt_um_vga_example__DOT__dup_timer;
    __Vdly__tt_um_vga_example__DOT__dup_timer = 0;
    SData/*9:0*/ __Vdly__tt_um_vga_example__DOT__paddle_y;
    __Vdly__tt_um_vga_example__DOT__paddle_y = 0;
    CData/*3:0*/ __Vdly__tt_um_vga_example__DOT__tx_cd;
    __Vdly__tt_um_vga_example__DOT__tx_cd = 0;
    CData/*1:0*/ __Vdly__tt_um_vga_example__DOT__bounce_cd;
    __Vdly__tt_um_vga_example__DOT__bounce_cd = 0;
    CData/*0:0*/ __Vdly__tt_um_vga_example__DOT__has_ball;
    __Vdly__tt_um_vga_example__DOT__has_ball = 0;
    SData/*9:0*/ __Vdly__tt_um_vga_example__DOT__ball_x;
    __Vdly__tt_um_vga_example__DOT__ball_x = 0;
    SData/*9:0*/ __Vdly__tt_um_vga_example__DOT__ball_y;
    __Vdly__tt_um_vga_example__DOT__ball_y = 0;
    CData/*3:0*/ __Vdly__tt_um_vga_example__DOT__vel_x;
    __Vdly__tt_um_vga_example__DOT__vel_x = 0;
    CData/*3:0*/ __Vdly__tt_um_vga_example__DOT__vel_y;
    __Vdly__tt_um_vga_example__DOT__vel_y = 0;
    CData/*0:0*/ __Vdly__tt_um_vga_example__DOT__ball_del_act;
    __Vdly__tt_um_vga_example__DOT__ball_del_act = 0;
    CData/*0:0*/ __Vdly__tt_um_vga_example__DOT__ball_rx_ack;
    __Vdly__tt_um_vga_example__DOT__ball_rx_ack = 0;
    CData/*0:0*/ __Vdly__tt_um_vga_example__DOT__booted;
    __Vdly__tt_um_vga_example__DOT__booted = 0;
    CData/*3:0*/ __Vdly__bit_idx;
    __Vdly__bit_idx = 0;
    SData/*9:0*/ __Vdly__tt_um_vga_example__DOT__uart_tx_inst__DOT__shift;
    __Vdly__tt_um_vga_example__DOT__uart_tx_inst__DOT__shift = 0;
    CData/*0:0*/ __Vdly__tt_um_vga_example__DOT__tx_busy;
    __Vdly__tt_um_vga_example__DOT__tx_busy = 0;
    SData/*13:0*/ __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__baud_counter;
    __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__baud_counter = 0;
    CData/*3:0*/ __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__bit_idx;
    __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__bit_idx = 0;
    CData/*0:0*/ __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__receiving;
    __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__receiving = 0;
    CData/*7:0*/ __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__shift;
    __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__shift = 0;
    CData/*2:0*/ __Vdly__byte_cnt;
    __Vdly__byte_cnt = 0;
    CData/*1:0*/ __Vdly__state1;
    __Vdly__state1 = 0;
    CData/*1:0*/ __Vdly__tt_um_vga_example__DOT__packet_receiver_inst__DOT__state;
    __Vdly__tt_um_vga_example__DOT__packet_receiver_inst__DOT__state = 0;
    CData/*2:0*/ __Vdly__tt_um_vga_example__DOT__packet_receiver_inst__DOT__byte_cnt;
    __Vdly__tt_um_vga_example__DOT__packet_receiver_inst__DOT__byte_cnt = 0;
    CData/*7:0*/ __Vdly__tt_um_vga_example__DOT__packet_receiver_inst__DOT__running_ecc;
    __Vdly__tt_um_vga_example__DOT__packet_receiver_inst__DOT__running_ecc = 0;
    CData/*7:0*/ __VdlyVal__tt_um_vga_example__DOT__rx_packet_bytes__v0;
    __VdlyVal__tt_um_vga_example__DOT__rx_packet_bytes__v0 = 0;
    CData/*2:0*/ __VdlyDim0__tt_um_vga_example__DOT__rx_packet_bytes__v0;
    __VdlyDim0__tt_um_vga_example__DOT__rx_packet_bytes__v0 = 0;
    CData/*0:0*/ __VdlySet__tt_um_vga_example__DOT__rx_packet_bytes__v0;
    __VdlySet__tt_um_vga_example__DOT__rx_packet_bytes__v0 = 0;
    // Body
    __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__baud_counter 
        = vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__baud_counter;
    __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__bit_idx 
        = vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__bit_idx;
    __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__receiving 
        = vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__receiving;
    __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__shift 
        = vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__shift;
    __Vdly__tt_um_vga_example__DOT__gone_timer = vlSelfRef.tt_um_vga_example__DOT__gone_timer;
    __Vdly__tt_um_vga_example__DOT__dup_timer = vlSelfRef.tt_um_vga_example__DOT__dup_timer;
    __Vdly__tt_um_vga_example__DOT__paddle_y = vlSelfRef.tt_um_vga_example__DOT__paddle_y;
    __Vdly__byte_cnt = vlSelfRef.byte_cnt;
    __Vdly__state1 = vlSelfRef.state1;
    __Vdly__tt_um_vga_example__DOT__packet_receiver_inst__DOT__state 
        = vlSelfRef.tt_um_vga_example__DOT__packet_receiver_inst__DOT__state;
    __Vdly__tt_um_vga_example__DOT__packet_receiver_inst__DOT__byte_cnt 
        = vlSelfRef.tt_um_vga_example__DOT__packet_receiver_inst__DOT__byte_cnt;
    __Vdly__tt_um_vga_example__DOT__packet_receiver_inst__DOT__running_ecc 
        = vlSelfRef.tt_um_vga_example__DOT__packet_receiver_inst__DOT__running_ecc;
    __Vdly__bit_idx = vlSelfRef.bit_idx;
    __VdlySet__tt_um_vga_example__DOT__rx_packet_bytes__v0 = 0U;
    __Vdly__tt_um_vga_example__DOT__uart_tx_inst__DOT__shift 
        = vlSelfRef.tt_um_vga_example__DOT__uart_tx_inst__DOT__shift;
    __Vdly__tt_um_vga_example__DOT__tx_busy = vlSelfRef.tt_um_vga_example__DOT__tx_busy;
    __Vdly__tt_um_vga_example__DOT__tx_small_rst = vlSelfRef.tt_um_vga_example__DOT__tx_small_rst;
    __Vdly__tt_um_vga_example__DOT__ball_rx_valid = vlSelfRef.tt_um_vga_example__DOT__ball_rx_valid;
    __Vdly__tt_um_vga_example__DOT__ball_del_act = vlSelfRef.tt_um_vga_example__DOT__ball_del_act;
    __Vdly__tt_um_vga_example__DOT__booted = vlSelfRef.tt_um_vga_example__DOT__booted;
    __Vdly__tt_um_vga_example__DOT__tx_cd = vlSelfRef.tt_um_vga_example__DOT__tx_cd;
    __Vdly__tt_um_vga_example__DOT__bounce_cd = vlSelfRef.tt_um_vga_example__DOT__bounce_cd;
    __Vdly__tt_um_vga_example__DOT__vel_y = vlSelfRef.tt_um_vga_example__DOT__vel_y;
    __Vdly__tt_um_vga_example__DOT__ball_rx_ack = vlSelfRef.tt_um_vga_example__DOT__ball_rx_ack;
    __Vdly__tt_um_vga_example__DOT__vel_x = vlSelfRef.tt_um_vga_example__DOT__vel_x;
    __Vdly__tt_um_vga_example__DOT__has_ball = vlSelfRef.tt_um_vga_example__DOT__has_ball;
    __Vdly__tt_um_vga_example__DOT__ball_y = vlSelfRef.tt_um_vga_example__DOT__ball_y;
    __Vdly__tt_um_vga_example__DOT__ball_x = vlSelfRef.tt_um_vga_example__DOT__ball_x;
    __Vdly__tt_um_vga_example__DOT__send_packet_reg 
        = vlSelfRef.tt_um_vga_example__DOT__send_packet_reg;
    if ((1U & ((~ (IData)(vlSelfRef.rst_n)) | (~ (IData)(vlSelfRef.tt_um_vga_example__DOT__booted))))) {
        __Vdly__tt_um_vga_example__DOT__gone_timer = 0U;
        __Vdly__tt_um_vga_example__DOT__dup_timer = 0U;
        __Vdly__tt_um_vga_example__DOT__tx_small_rst = 0U;
        __Vdly__tt_um_vga_example__DOT__send_packet_reg = 0U;
        vlSelfRef.tt_um_vga_example__DOT__packet_cmd = 0U;
        vlSelfRef.tt_um_vga_example__DOT__packet_1 = 0U;
        vlSelfRef.tt_um_vga_example__DOT__packet_2 = 0U;
        vlSelfRef.tt_um_vga_example__DOT__packet_3 = 0U;
        vlSelfRef.tt_um_vga_example__DOT__packet_4 = 0U;
        vlSelfRef.tt_um_vga_example__DOT__ball_tx_ready = 1U;
    } else {
        if (((IData)(vlSelfRef.tt_um_vga_example__DOT__has_ball) 
             | ((IData)(vlSelfRef.tt_um_vga_example__DOT__has_ball_rx_sync) 
                >> 1U))) {
            __Vdly__tt_um_vga_example__DOT__gone_timer = 0U;
        } else if (((IData)(vlSelfRef.debug_game_tick) 
                    & (0xfU > (IData)(vlSelfRef.tt_um_vga_example__DOT__gone_timer)))) {
            __Vdly__tt_um_vga_example__DOT__gone_timer 
                = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.tt_um_vga_example__DOT__gone_timer)));
        }
        if (vlSelfRef.debug_game_tick) {
            if (((IData)(vlSelfRef.tt_um_vga_example__DOT__has_ball) 
                 & ((IData)(vlSelfRef.tt_um_vga_example__DOT__has_ball_rx_sync) 
                    >> 1U))) {
                if ((0xfU > (IData)(vlSelfRef.tt_um_vga_example__DOT__dup_timer))) {
                    __Vdly__tt_um_vga_example__DOT__dup_timer 
                        = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.tt_um_vga_example__DOT__dup_timer)));
                }
            } else {
                __Vdly__tt_um_vga_example__DOT__dup_timer = 0U;
            }
        }
        __Vdly__tt_um_vga_example__DOT__tx_small_rst = 0U;
        if (vlSelfRef.tt_um_vga_example__DOT__send_packet_reg) {
            if ((1U & ((~ ((IData)(vlSelfRef.tt_um_vga_example__DOT__insync_rx_sync) 
                           >> 1U)) | (IData)(vlSelfRef.tt_um_vga_example__DOT__packet_busy)))) {
                __Vdly__tt_um_vga_example__DOT__send_packet_reg = 0U;
            }
        } else if (vlSelfRef.debug_send_ack_packet) {
            __Vdly__tt_um_vga_example__DOT__send_packet_reg = 1U;
            vlSelfRef.tt_um_vga_example__DOT__packet_cmd = 0xfU;
            vlSelfRef.tt_um_vga_example__DOT__packet_1 
                = ((IData)(vlSelfRef.tt_um_vga_example__DOT__ball_rx_ack)
                    ? 0x90U : 0U);
            vlSelfRef.tt_um_vga_example__DOT__packet_2 = 0U;
            vlSelfRef.tt_um_vga_example__DOT__packet_3 = 0U;
            vlSelfRef.tt_um_vga_example__DOT__packet_4 = 0U;
        } else if (((IData)(vlSelfRef.tt_um_vga_example__DOT__ball_tx_valid) 
                    & (0U == (IData)(vlSelfRef.tt_um_vga_example__DOT__tx_cd)))) {
            __Vdly__tt_um_vga_example__DOT__send_packet_reg = 1U;
            vlSelfRef.tt_um_vga_example__DOT__packet_cmd = 9U;
            vlSelfRef.tt_um_vga_example__DOT__packet_1 
                = (0xffU & ((IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x) 
                            >> 2U));
            vlSelfRef.tt_um_vga_example__DOT__packet_2 
                = ((0xc0U & ((IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x) 
                             << 6U)) | (0x3fU & ((IData)(vlSelfRef.tt_um_vga_example__DOT__ball_y) 
                                                 >> 4U)));
            vlSelfRef.tt_um_vga_example__DOT__packet_3 
                = ((0xf0U & ((IData)(vlSelfRef.tt_um_vga_example__DOT__ball_y) 
                             << 4U)) | (IData)(vlSelfRef.tt_um_vga_example__DOT__vel_x));
            vlSelfRef.tt_um_vga_example__DOT__packet_4 
                = ((IData)(vlSelfRef.tt_um_vga_example__DOT__vel_y) 
                   << 4U);
        }
        if (vlSelfRef.tt_um_vga_example__DOT__ball_tx_ready) {
            __Vdly__tt_um_vga_example__DOT__tx_small_rst = 1U;
            __Vdly__tt_um_vga_example__DOT__send_packet_reg = 0U;
            vlSelfRef.tt_um_vga_example__DOT__packet_cmd = 0U;
            vlSelfRef.tt_um_vga_example__DOT__packet_1 = 0U;
            vlSelfRef.tt_um_vga_example__DOT__packet_2 = 0U;
            vlSelfRef.tt_um_vga_example__DOT__packet_3 = 0U;
            vlSelfRef.tt_um_vga_example__DOT__packet_4 = 0U;
        }
        if (vlSelfRef.tt_um_vga_example__DOT__rx_packet_ready) {
            if ((9U != (0xfU & (vlSelfRef.tt_um_vga_example__DOT__rx_packet_bytes
                                [0U] >> 4U)))) {
                if ((0xfU == (0xfU & (vlSelfRef.tt_um_vga_example__DOT__rx_packet_bytes
                                      [0U] >> 4U)))) {
                    if ((9U == (0xfU & (vlSelfRef.tt_um_vga_example__DOT__rx_packet_bytes
                                        [1U] >> 4U)))) {
                        vlSelfRef.tt_um_vga_example__DOT__ball_tx_ready = 1U;
                    }
                }
            }
        }
        if (vlSelfRef.tt_um_vga_example__DOT__tx_small_rst) {
            vlSelfRef.tt_um_vga_example__DOT__ball_tx_ready = 0U;
        }
    }
    if (vlSelfRef.rst_n) {
        vlSelfRef.baud_counter = ((IData)(vlSelfRef.tt_um_vga_example__DOT__tx_busy)
                                   ? ((IData)(vlSelfRef.debug_5)
                                       ? 0U : (0x3fffU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.baud_counter))))
                                   : 0U);
        if (vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__receiving) {
            __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__baud_counter 
                = ((IData)(vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__baud_tick)
                    ? 0xa2cU : (0x3fffU & ((IData)(vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__baud_counter) 
                                           - (IData)(1U))));
        } else if ((1U & (~ (IData)(vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__rx_sync)))) {
            __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__baud_counter = 0x516U;
        }
        if ((1U & (~ (IData)(vlSelfRef.tt_um_vga_example__DOT__pause)))) {
            if (vlSelfRef.debug_game_tick) {
                if (((IData)(vlSelfRef.ui_in) & (0x20U 
                                                 < (IData)(vlSelfRef.tt_um_vga_example__DOT__paddle_y)))) {
                    __Vdly__tt_um_vga_example__DOT__paddle_y 
                        = (0x3ffU & ((IData)(vlSelfRef.tt_um_vga_example__DOT__paddle_y) 
                                     - (IData)(4U)));
                }
                if ((((IData)(vlSelfRef.ui_in) >> 1U) 
                     & (0x1c1U > (IData)(vlSelfRef.tt_um_vga_example__DOT__paddle_y)))) {
                    __Vdly__tt_um_vga_example__DOT__paddle_y 
                        = (0x3ffU & ((IData)(4U) + (IData)(vlSelfRef.tt_um_vga_example__DOT__paddle_y)));
                }
            }
        }
        if (((~ (IData)(vlSelfRef.tt_um_vga_example__DOT__tx_busy)) 
             & (IData)(vlSelfRef.tt_um_vga_example__DOT__tx_send))) {
            __Vdly__bit_idx = 0U;
            __Vdly__tt_um_vga_example__DOT__uart_tx_inst__DOT__shift 
                = (0x200U | ((IData)(vlSelfRef.tt_um_vga_example__DOT__tx_data) 
                             << 1U));
            __Vdly__tt_um_vga_example__DOT__tx_busy = 1U;
        } else if (((IData)(vlSelfRef.tt_um_vga_example__DOT__tx_busy) 
                    & (IData)(vlSelfRef.debug_5))) {
            if ((9U == (IData)(vlSelfRef.bit_idx))) {
                __Vdly__bit_idx = 0U;
                __Vdly__tt_um_vga_example__DOT__tx_busy = 0U;
            } else {
                __Vdly__bit_idx = (0xfU & ((IData)(1U) 
                                           + (IData)(vlSelfRef.bit_idx)));
                __Vdly__tt_um_vga_example__DOT__uart_tx_inst__DOT__shift 
                    = (0x200U | (0x1ffU & ((IData)(vlSelfRef.tt_um_vga_example__DOT__uart_tx_inst__DOT__shift) 
                                           >> 1U)));
            }
        }
        vlSelfRef.tt_um_vga_example__DOT__tx_send = 0U;
        if ((0U == (IData)(vlSelfRef.state1))) {
            if (((IData)(vlSelfRef.tt_um_vga_example__DOT__packet_sender_inst__DOT__start_ff) 
                 & (~ (IData)(vlSelfRef.tt_um_vga_example__DOT__tx_busy)))) {
                __Vdly__byte_cnt = 0U;
                __Vdly__state1 = 1U;
                vlSelfRef.tt_um_vga_example__DOT__packet_busy = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.state1))) {
            vlSelfRef.tt_um_vga_example__DOT__tx_data 
                = ((6U >= (IData)(vlSelfRef.byte_cnt))
                    ? vlSelfRef.tt_um_vga_example__DOT__tx_packet_bytes
                   [vlSelfRef.byte_cnt] : 0U);
            vlSelfRef.tt_um_vga_example__DOT__tx_send = 1U;
            __Vdly__state1 = 2U;
        } else if ((2U == (IData)(vlSelfRef.state1))) {
            vlSelfRef.tt_um_vga_example__DOT__tx_send = 0U;
            if (vlSelfRef.tt_um_vga_example__DOT__tx_busy) {
                __Vdly__state1 = 3U;
            }
        } else if ((3U == (IData)(vlSelfRef.state1))) {
            if ((1U & (~ (IData)(vlSelfRef.tt_um_vga_example__DOT__tx_busy)))) {
                if ((6U == (IData)(vlSelfRef.byte_cnt))) {
                    __Vdly__state1 = 0U;
                    vlSelfRef.tt_um_vga_example__DOT__packet_busy = 0U;
                } else {
                    __Vdly__byte_cnt = (7U & ((IData)(1U) 
                                              + (IData)(vlSelfRef.byte_cnt)));
                    __Vdly__state1 = 1U;
                }
            }
        }
        if (vlSelfRef.tt_um_vga_example__DOT__booted) {
            if ((1U & (~ (IData)(vlSelfRef.tt_um_vga_example__DOT__pause)))) {
                if (vlSelfRef.debug_game_tick) {
                    if ((0U != (IData)(vlSelfRef.tt_um_vga_example__DOT__tx_cd))) {
                        __Vdly__tt_um_vga_example__DOT__tx_cd 
                            = (0xfU & ((IData)(vlSelfRef.tt_um_vga_example__DOT__tx_cd) 
                                       - (IData)(1U)));
                    }
                    if ((0U != (IData)(vlSelfRef.tt_um_vga_example__DOT__bounce_cd))) {
                        __Vdly__tt_um_vga_example__DOT__bounce_cd 
                            = (3U & ((IData)(vlSelfRef.tt_um_vga_example__DOT__bounce_cd) 
                                     - (IData)(1U)));
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_at_edge)))) {
                        vlSelfRef.tt_um_vga_example__DOT__ball_tx_valid = 0U;
                    }
                    if ((((0xfU == (IData)(vlSelfRef.tt_um_vga_example__DOT__dup_timer)) 
                          & ((IData)(vlSelfRef.ui_in) 
                             >> 7U)) | (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_del_req))) {
                        __Vdly__tt_um_vga_example__DOT__has_ball = 0U;
                        __Vdly__tt_um_vga_example__DOT__ball_x = 0x3ffU;
                        __Vdly__tt_um_vga_example__DOT__ball_y = 0x1ffU;
                        __Vdly__tt_um_vga_example__DOT__vel_x = 0U;
                        __Vdly__tt_um_vga_example__DOT__vel_y = 0U;
                        vlSelfRef.tt_um_vga_example__DOT__ball_tx_valid = 0U;
                        __Vdly__tt_um_vga_example__DOT__ball_del_act = 1U;
                    } else if (vlSelfRef.tt_um_vga_example__DOT__ball_rx_valid) {
                        __Vdly__tt_um_vga_example__DOT__has_ball = 1U;
                        __Vdly__tt_um_vga_example__DOT__ball_x 
                            = (0x3ffU & ((IData)(0x280U) 
                                         - (IData)(vlSelfRef.tt_um_vga_example__DOT__rx_ball_x)));
                        __Vdly__tt_um_vga_example__DOT__ball_y 
                            = vlSelfRef.tt_um_vga_example__DOT__rx_ball_y;
                        __Vdly__tt_um_vga_example__DOT__vel_x 
                            = vlSelfRef.tt_um_vga_example__DOT__rx_ball_vel_x;
                        __Vdly__tt_um_vga_example__DOT__vel_y 
                            = vlSelfRef.tt_um_vga_example__DOT__rx_ball_vel_y;
                        __Vdly__tt_um_vga_example__DOT__tx_cd = 0xfU;
                        __Vdly__tt_um_vga_example__DOT__bounce_cd = 3U;
                        __Vdly__tt_um_vga_example__DOT__ball_rx_ack = 1U;
                    } else if ((((0xfU == (IData)(vlSelfRef.tt_um_vga_example__DOT__gone_timer)) 
                                 | (IData)(vlSelfRef.tt_um_vga_example__DOT__game_launch)) 
                                & (~ ((IData)(vlSelfRef.ui_in) 
                                      >> 7U)))) {
                        vlSelfRef.tt_um_vga_example__DOT__game_launch = 0U;
                        __Vdly__tt_um_vga_example__DOT__has_ball = 1U;
                        __Vdly__tt_um_vga_example__DOT__ball_x = 0x258U;
                        __Vdly__tt_um_vga_example__DOT__ball_y = 0x190U;
                        __Vdly__tt_um_vga_example__DOT__vel_x = 7U;
                        __Vdly__tt_um_vga_example__DOT__vel_y = 5U;
                        __Vdly__tt_um_vga_example__DOT__ball_del_act = 0U;
                    } else {
                        __Vdly__tt_um_vga_example__DOT__ball_rx_ack = 0U;
                        __Vdly__tt_um_vga_example__DOT__ball_del_act = 0U;
                    }
                    if (vlSelfRef.tt_um_vga_example__DOT__has_ball) {
                        if ((((IData)(vlSelfRef.tt_um_vga_example__DOT__ball_at_edge) 
                              & ((IData)(vlSelfRef.tt_um_vga_example__DOT__insync_rx_sync) 
                                 >> 1U)) & (0U == (IData)(vlSelfRef.tt_um_vga_example__DOT__tx_cd)))) {
                            vlSelfRef.tt_um_vga_example__DOT__ball_tx_valid = 1U;
                        } else {
                            if ((((((IData)(vlSelfRef.debug_collision_paddle_l) 
                                    | (IData)(vlSelfRef.debug_collision_paddle_r)) 
                                   & (IData)(vlSelfRef.debug_collision_paddle_y)) 
                                  | (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_at_edge)) 
                                 & (0U == (IData)(vlSelfRef.tt_um_vga_example__DOT__bounce_cd)))) {
                                __Vdly__tt_um_vga_example__DOT__vel_x 
                                    = (0xfU & (- (IData)(vlSelfRef.tt_um_vga_example__DOT__vel_x)));
                                __Vdly__tt_um_vga_example__DOT__bounce_cd = 3U;
                                __Vdly__tt_um_vga_example__DOT__ball_x 
                                    = ((IData)(vlSelfRef.tt_um_vga_example__DOT__ball_at_edge)
                                        ? ((IData)(vlSelfRef.tt_um_vga_example__DOT__ball_edge_l)
                                            ? 0xaU : 0x276U)
                                        : ((IData)(vlSelfRef.debug_collision_paddle_l)
                                            ? 0x136U
                                            : 0x14aU));
                            } else {
                                __Vdly__tt_um_vga_example__DOT__ball_x 
                                    = (0x3ffU & ((IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x) 
                                                 + 
                                                 ((0x3f0U 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & ((IData)(vlSelfRef.tt_um_vga_example__DOT__vel_x) 
                                                                     >> 3U)))) 
                                                      << 4U)) 
                                                  | (IData)(vlSelfRef.tt_um_vga_example__DOT__vel_x))));
                            }
                            __Vdly__tt_um_vga_example__DOT__ball_y 
                                = (0x3ffU & ((IData)(vlSelfRef.tt_um_vga_example__DOT__ball_y) 
                                             + ((0x3f0U 
                                                 & ((- (IData)(
                                                               (1U 
                                                                & ((IData)(vlSelfRef.tt_um_vga_example__DOT__vel_y) 
                                                                   >> 3U)))) 
                                                    << 4U)) 
                                                | (IData)(vlSelfRef.tt_um_vga_example__DOT__vel_y))));
                            if ((0U == (IData)(vlSelfRef.tt_um_vga_example__DOT__bounce_cd))) {
                                if (((0xaU >= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_y)) 
                                     & ((IData)(vlSelfRef.tt_um_vga_example__DOT__vel_y) 
                                        >> 3U))) {
                                    __Vdly__tt_um_vga_example__DOT__vel_y 
                                        = (0xfU & (- (IData)(vlSelfRef.tt_um_vga_example__DOT__vel_y)));
                                    __Vdly__tt_um_vga_example__DOT__ball_y = 0xfU;
                                    __Vdly__tt_um_vga_example__DOT__bounce_cd = 3U;
                                } else if (((0x1d6U 
                                             <= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_y)) 
                                            & (~ ((IData)(vlSelfRef.tt_um_vga_example__DOT__vel_y) 
                                                  >> 3U)))) {
                                    __Vdly__tt_um_vga_example__DOT__vel_y 
                                        = (0xfU & (- (IData)(vlSelfRef.tt_um_vga_example__DOT__vel_y)));
                                    __Vdly__tt_um_vga_example__DOT__ball_y = 0x1d1U;
                                    __Vdly__tt_um_vga_example__DOT__bounce_cd = 3U;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            __Vdly__tt_um_vga_example__DOT__booted = 1U;
            vlSelfRef.tt_um_vga_example__DOT__game_launch = 1U;
        }
    } else {
        vlSelfRef.baud_counter = 0U;
        __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__baud_counter = 0U;
        __Vdly__tt_um_vga_example__DOT__paddle_y = 0xf0U;
        __Vdly__bit_idx = 0U;
        __Vdly__tt_um_vga_example__DOT__uart_tx_inst__DOT__shift = 0x3ffU;
        __Vdly__tt_um_vga_example__DOT__tx_busy = 0U;
        __Vdly__state1 = 0U;
        vlSelfRef.tt_um_vga_example__DOT__tx_send = 0U;
        vlSelfRef.tt_um_vga_example__DOT__packet_busy = 0U;
        __Vdly__byte_cnt = 0U;
        __Vdly__tt_um_vga_example__DOT__ball_x = 0xf0U;
        __Vdly__tt_um_vga_example__DOT__ball_y = 0x78U;
        __Vdly__tt_um_vga_example__DOT__vel_x = 3U;
        __Vdly__tt_um_vga_example__DOT__vel_y = 2U;
        __Vdly__tt_um_vga_example__DOT__booted = 0U;
        vlSelfRef.tt_um_vga_example__DOT__game_launch = 1U;
        __Vdly__tt_um_vga_example__DOT__has_ball = 0U;
        vlSelfRef.tt_um_vga_example__DOT__ball_tx_valid = 0U;
        __Vdly__tt_um_vga_example__DOT__ball_rx_ack = 0U;
        __Vdly__tt_um_vga_example__DOT__ball_del_act = 0U;
        __Vdly__tt_um_vga_example__DOT__tx_cd = 0U;
        __Vdly__tt_um_vga_example__DOT__bounce_cd = 0U;
    }
    if ((1U & ((~ (IData)(vlSelfRef.rst_n)) | (~ (IData)(vlSelfRef.tt_um_vga_example__DOT__booted))))) {
        vlSelfRef.tt_um_vga_example__DOT__ball_del_req = 0U;
        vlSelfRef.tt_um_vga_example__DOT__ack = 0U;
        __Vdly__tt_um_vga_example__DOT__ball_rx_valid = 0U;
    } else {
        if (vlSelfRef.tt_um_vga_example__DOT__rx_packet_ready) {
            if ((9U != (0xfU & (vlSelfRef.tt_um_vga_example__DOT__rx_packet_bytes
                                [0U] >> 4U)))) {
                if ((0xfU == (0xfU & (vlSelfRef.tt_um_vga_example__DOT__rx_packet_bytes
                                      [0U] >> 4U)))) {
                    if ((9U == (0xfU & (vlSelfRef.tt_um_vga_example__DOT__rx_packet_bytes
                                        [1U] >> 4U)))) {
                        vlSelfRef.tt_um_vga_example__DOT__ball_del_req = 1U;
                    }
                }
            }
            if ((9U == (0xfU & (vlSelfRef.tt_um_vga_example__DOT__rx_packet_bytes
                                [0U] >> 4U)))) {
                if ((1U & ((~ (IData)(vlSelfRef.tt_um_vga_example__DOT__has_ball)) 
                           & (~ (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_rx_valid))))) {
                    vlSelfRef.tt_um_vga_example__DOT__rx_ball_x 
                        = ((vlSelfRef.tt_um_vga_example__DOT__rx_packet_bytes
                            [1U] << 2U) | (3U & (vlSelfRef.tt_um_vga_example__DOT__rx_packet_bytes
                                                 [2U] 
                                                 >> 6U)));
                    vlSelfRef.tt_um_vga_example__DOT__rx_ball_y 
                        = ((0x3f0U & (vlSelfRef.tt_um_vga_example__DOT__rx_packet_bytes
                                      [2U] << 4U)) 
                           | (0xfU & (vlSelfRef.tt_um_vga_example__DOT__rx_packet_bytes
                                      [3U] >> 4U)));
                    vlSelfRef.tt_um_vga_example__DOT__rx_ball_vel_x 
                        = (0xfU & vlSelfRef.tt_um_vga_example__DOT__rx_packet_bytes
                           [3U]);
                    vlSelfRef.tt_um_vga_example__DOT__rx_ball_vel_y 
                        = (0xfU & (vlSelfRef.tt_um_vga_example__DOT__rx_packet_bytes
                                   [4U] >> 4U));
                    __Vdly__tt_um_vga_example__DOT__ball_rx_valid = 1U;
                    vlSelfRef.tt_um_vga_example__DOT__ack = 1U;
                }
            }
        }
        if (vlSelfRef.tt_um_vga_example__DOT__ball_del_act) {
            vlSelfRef.tt_um_vga_example__DOT__ball_del_req = 0U;
        }
        if (vlSelfRef.tt_um_vga_example__DOT__ball_rx_ack) {
            __Vdly__tt_um_vga_example__DOT__ball_rx_valid = 0U;
            vlSelfRef.tt_um_vga_example__DOT__ack = 0U;
        }
    }
    if (vlSelfRef.rst_n) {
        vlSelfRef.tt_um_vga_example__DOT__rx_packet_ready = 0U;
        if (vlSelfRef.tt_um_vga_example__DOT__rx_ready) {
            if ((0U == (IData)(vlSelfRef.tt_um_vga_example__DOT__packet_receiver_inst__DOT__state))) {
                if ((0x55U == (IData)(vlSelfRef.tt_um_vga_example__DOT__rx_data))) {
                    __Vdly__tt_um_vga_example__DOT__packet_receiver_inst__DOT__state = 1U;
                    __Vdly__tt_um_vga_example__DOT__packet_receiver_inst__DOT__byte_cnt = 0U;
                    __Vdly__tt_um_vga_example__DOT__packet_receiver_inst__DOT__running_ecc = 0U;
                }
            } else if ((1U == (IData)(vlSelfRef.tt_um_vga_example__DOT__packet_receiver_inst__DOT__state))) {
                vlSelfRef.tt_um_vga_example__DOT__packet_receiver_inst__DOT____Vlvbound_hedfcfc53__0 
                    = vlSelfRef.tt_um_vga_example__DOT__rx_data;
                __Vdly__tt_um_vga_example__DOT__packet_receiver_inst__DOT__running_ecc 
                    = ((IData)(vlSelfRef.tt_um_vga_example__DOT__packet_receiver_inst__DOT__running_ecc) 
                       ^ (IData)(vlSelfRef.tt_um_vga_example__DOT__rx_data));
                if ((4U >= (IData)(vlSelfRef.tt_um_vga_example__DOT__packet_receiver_inst__DOT__byte_cnt))) {
                    __VdlyVal__tt_um_vga_example__DOT__rx_packet_bytes__v0 
                        = vlSelfRef.tt_um_vga_example__DOT__packet_receiver_inst__DOT____Vlvbound_hedfcfc53__0;
                    __VdlyDim0__tt_um_vga_example__DOT__rx_packet_bytes__v0 
                        = vlSelfRef.tt_um_vga_example__DOT__packet_receiver_inst__DOT__byte_cnt;
                    __VdlySet__tt_um_vga_example__DOT__rx_packet_bytes__v0 = 1U;
                }
                if ((4U == (IData)(vlSelfRef.tt_um_vga_example__DOT__packet_receiver_inst__DOT__byte_cnt))) {
                    __Vdly__tt_um_vga_example__DOT__packet_receiver_inst__DOT__state = 2U;
                } else {
                    __Vdly__tt_um_vga_example__DOT__packet_receiver_inst__DOT__byte_cnt 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tt_um_vga_example__DOT__packet_receiver_inst__DOT__byte_cnt)));
                }
            } else if ((2U == (IData)(vlSelfRef.tt_um_vga_example__DOT__packet_receiver_inst__DOT__state))) {
                if (((IData)(vlSelfRef.tt_um_vga_example__DOT__packet_receiver_inst__DOT__running_ecc) 
                     == (IData)(vlSelfRef.tt_um_vga_example__DOT__rx_data))) {
                    vlSelfRef.tt_um_vga_example__DOT__rx_packet_ready = 1U;
                }
                __Vdly__tt_um_vga_example__DOT__packet_receiver_inst__DOT__state = 0U;
            }
        }
        vlSelfRef.tt_um_vga_example__DOT__rx_ready = 0U;
        if ((1U & ((~ (IData)(vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__receiving)) 
                   & (~ (IData)(vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__rx_sync))))) {
            __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__bit_idx = 0U;
            __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__receiving = 1U;
        } else if (((IData)(vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__receiving) 
                    & (0U == (IData)(vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__baud_counter)))) {
            if ((0U == (IData)(vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__bit_idx))) {
                __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__bit_idx 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__bit_idx)));
            } else if ((8U >= (IData)(vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__bit_idx))) {
                __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__shift 
                    = (((~ ((IData)(1U) << (7U & ((IData)(vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__bit_idx) 
                                                  - (IData)(1U))))) 
                        & (IData)(__Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__shift)) 
                       | (0xffU & ((IData)(vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__rx_sync) 
                                   << (7U & ((IData)(vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__bit_idx) 
                                             - (IData)(1U))))));
                __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__bit_idx 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__bit_idx)));
            } else {
                vlSelfRef.tt_um_vga_example__DOT__rx_data 
                    = vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__shift;
                __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__receiving = 0U;
                vlSelfRef.tt_um_vga_example__DOT__rx_ready = 1U;
            }
        }
    } else {
        __Vdly__tt_um_vga_example__DOT__packet_receiver_inst__DOT__state = 0U;
        __Vdly__tt_um_vga_example__DOT__packet_receiver_inst__DOT__byte_cnt = 0U;
        __Vdly__tt_um_vga_example__DOT__packet_receiver_inst__DOT__running_ecc = 0U;
        vlSelfRef.tt_um_vga_example__DOT__rx_packet_ready = 0U;
        __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__bit_idx = 0xaU;
        __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__shift = 0U;
        vlSelfRef.tt_um_vga_example__DOT__rx_data = 0U;
        __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__receiving = 0U;
        vlSelfRef.tt_um_vga_example__DOT__rx_ready = 0U;
    }
    vlSelfRef.tt_um_vga_example__DOT__paddle_y = __Vdly__tt_um_vga_example__DOT__paddle_y;
    vlSelfRef.bit_idx = __Vdly__bit_idx;
    vlSelfRef.tt_um_vga_example__DOT__uart_tx_inst__DOT__shift 
        = __Vdly__tt_um_vga_example__DOT__uart_tx_inst__DOT__shift;
    vlSelfRef.debug_5 = (0xa2bU == (IData)(vlSelfRef.baud_counter));
    vlSelfRef.debug_packet2 = vlSelfRef.tt_um_vga_example__DOT__packet_2;
    vlSelfRef.debug_packet_cmd = vlSelfRef.tt_um_vga_example__DOT__packet_cmd;
    tt_um_vga_example__DOT__tx_header = (((IData)(vlSelfRef.tt_um_vga_example__DOT__packet_cmd) 
                                          << 4U) | 
                                         (1U & ((IData)(vlSelfRef.ui_in) 
                                                >> 7U)));
    vlSelfRef.debug_baud_tick = vlSelfRef.debug_5;
    vlSelfRef.byte_cnt = __Vdly__byte_cnt;
    vlSelfRef.state1 = __Vdly__state1;
    vlSelfRef.debug_4 = vlSelfRef.tt_um_vga_example__DOT__tx_data;
    vlSelfRef.debug_tx_data = vlSelfRef.tt_um_vga_example__DOT__tx_data;
    vlSelfRef.tt_um_vga_example__DOT__tx_busy = __Vdly__tt_um_vga_example__DOT__tx_busy;
    vlSelfRef.tt_um_vga_example__DOT__tx_packet_bytes[1U] 
        = tt_um_vga_example__DOT__tx_header;
    vlSelfRef.tt_um_vga_example__DOT__tx_packet_bytes[2U] 
        = vlSelfRef.tt_um_vga_example__DOT__packet_1;
    vlSelfRef.tt_um_vga_example__DOT__tx_packet_bytes[3U] 
        = vlSelfRef.tt_um_vga_example__DOT__packet_2;
    vlSelfRef.tt_um_vga_example__DOT__tx_packet_bytes[4U] 
        = vlSelfRef.tt_um_vga_example__DOT__packet_3;
    vlSelfRef.tt_um_vga_example__DOT__tx_packet_bytes[5U] 
        = vlSelfRef.tt_um_vga_example__DOT__packet_4;
    vlSelfRef.tt_um_vga_example__DOT__tx_packet_bytes[6U] 
        = ((IData)(tt_um_vga_example__DOT__tx_header) 
           ^ ((IData)(vlSelfRef.tt_um_vga_example__DOT__packet_1) 
              ^ ((IData)(vlSelfRef.tt_um_vga_example__DOT__packet_2) 
                 ^ ((IData)(vlSelfRef.tt_um_vga_example__DOT__packet_3) 
                    ^ (IData)(vlSelfRef.tt_um_vga_example__DOT__packet_4)))));
    vlSelfRef.tt_um_vga_example__DOT__tx_small_rst 
        = __Vdly__tt_um_vga_example__DOT__tx_small_rst;
    vlSelfRef.tt_um_vga_example__DOT__dup_timer = __Vdly__tt_um_vga_example__DOT__dup_timer;
    vlSelfRef.tt_um_vga_example__DOT__gone_timer = __Vdly__tt_um_vga_example__DOT__gone_timer;
    vlSelfRef.tt_um_vga_example__DOT__tx_cd = __Vdly__tt_um_vga_example__DOT__tx_cd;
    vlSelfRef.tt_um_vga_example__DOT__bounce_cd = __Vdly__tt_um_vga_example__DOT__bounce_cd;
    vlSelfRef.tt_um_vga_example__DOT__vel_y = __Vdly__tt_um_vga_example__DOT__vel_y;
    vlSelfRef.tt_um_vga_example__DOT__vel_x = __Vdly__tt_um_vga_example__DOT__vel_x;
    vlSelfRef.tt_um_vga_example__DOT__ball_y = __Vdly__tt_um_vga_example__DOT__ball_y;
    vlSelfRef.tt_um_vga_example__DOT__ball_x = __Vdly__tt_um_vga_example__DOT__ball_x;
    vlSelfRef.debug_tx_sent = vlSelfRef.tt_um_vga_example__DOT__tx_send;
    vlSelfRef.debug_6 = vlSelfRef.tt_um_vga_example__DOT__packet_busy;
    vlSelfRef.debug_packet_busy = vlSelfRef.tt_um_vga_example__DOT__packet_busy;
    vlSelfRef.debug_tx_busy = vlSelfRef.tt_um_vga_example__DOT__tx_busy;
    vlSelfRef.debug_uart_tx = (1U & ((~ (IData)(vlSelfRef.tt_um_vga_example__DOT__tx_busy)) 
                                     | (IData)(vlSelfRef.tt_um_vga_example__DOT__uart_tx_inst__DOT__shift)));
    vlSelfRef.tt_um_vga_example__DOT__packet_sender_inst__DOT__start_ff 
        = ((IData)(vlSelfRef.rst_n) & (IData)(vlSelfRef.tt_um_vga_example__DOT__send_packet_reg));
    vlSelfRef.debug_ball_tx = vlSelfRef.tt_um_vga_example__DOT__ball_tx_ready;
    vlSelfRef.debug_txcd = vlSelfRef.tt_um_vga_example__DOT__tx_cd;
    vlSelfRef.debug_bounce_cd = vlSelfRef.tt_um_vga_example__DOT__bounce_cd;
    vlSelfRef.debug_ball_vel_y = vlSelfRef.tt_um_vga_example__DOT__vel_y;
    vlSelfRef.debug_ball_vel_x = vlSelfRef.tt_um_vga_example__DOT__vel_x;
    vlSelfRef.debug_ball_y = vlSelfRef.tt_um_vga_example__DOT__ball_y;
    vlSelfRef.debug_collision_paddle_y = ((((IData)(4U) 
                                            + (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_y)) 
                                           >= ((IData)(vlSelfRef.tt_um_vga_example__DOT__paddle_y) 
                                               - (IData)(0x1eU))) 
                                          & (((IData)(vlSelfRef.tt_um_vga_example__DOT__ball_y) 
                                              - (IData)(4U)) 
                                             <= ((IData)(0x1eU) 
                                                 + (IData)(vlSelfRef.tt_um_vga_example__DOT__paddle_y))));
    vlSelfRef.debug_ball_x = vlSelfRef.tt_um_vga_example__DOT__ball_x;
    vlSelfRef.tt_um_vga_example__DOT__ball_at_edge 
        = ((0xaU >= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x)) 
           | ((0x276U <= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x)) 
              & (0x28aU >= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x))));
    vlSelfRef.tt_um_vga_example__DOT__ball_edge_l = 
        (0xaU >= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x));
    vlSelfRef.debug_collision_paddle_r = (((IData)(vlSelfRef.tt_um_vga_example__DOT__vel_x) 
                                           >> 3U) & 
                                          ((0x14fU 
                                            >= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x)) 
                                           & (0x145U 
                                              <= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x))));
    vlSelfRef.debug_collision_paddle_l = ((~ ((IData)(vlSelfRef.tt_um_vga_example__DOT__vel_x) 
                                              >> 3U)) 
                                          & ((0x131U 
                                              <= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x)) 
                                             & (0x13bU 
                                                >= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x))));
    if ((1U & (~ (IData)(vlSelfRef.rst_n)))) {
        vlSelfRef.tt_um_vga_example__DOT__pause = 0U;
    }
    vlSelfRef.uio_out = ((0xfeU & (IData)(vlSelfRef.uio_out)) 
                         | (IData)(vlSelfRef.debug_uart_tx));
    vlSelfRef.tt_um_vga_example__DOT__send_packet_reg 
        = __Vdly__tt_um_vga_example__DOT__send_packet_reg;
    vlSelfRef.tt_um_vga_example__DOT__ball_del_act 
        = __Vdly__tt_um_vga_example__DOT__ball_del_act;
    vlSelfRef.tt_um_vga_example__DOT__ball_rx_valid 
        = __Vdly__tt_um_vga_example__DOT__ball_rx_valid;
    vlSelfRef.tt_um_vga_example__DOT__ball_rx_ack = __Vdly__tt_um_vga_example__DOT__ball_rx_ack;
    vlSelfRef.tt_um_vga_example__DOT__booted = __Vdly__tt_um_vga_example__DOT__booted;
    vlSelfRef.tt_um_vga_example__DOT__has_ball = __Vdly__tt_um_vga_example__DOT__has_ball;
    if (vlSelfRef.tt_um_vga_example__DOT__send_packet_reg) {
        vlSelfRef.debug_send_packet = 1U;
        vlSelfRef.tt_um_vga_example__DOT__tx_packet_bytes[0U] = 0x55U;
    } else {
        vlSelfRef.debug_send_packet = 0U;
        vlSelfRef.tt_um_vga_example__DOT__tx_packet_bytes[0U] = 0U;
    }
    vlSelfRef.debug_rx_ball_x = vlSelfRef.tt_um_vga_example__DOT__rx_ball_x;
    vlSelfRef.debug_rx_ball_y = vlSelfRef.tt_um_vga_example__DOT__rx_ball_y;
    vlSelfRef.debug_rx_ball_vel_x = vlSelfRef.tt_um_vga_example__DOT__rx_ball_vel_x;
    vlSelfRef.debug_rx_ball_vel_y = vlSelfRef.tt_um_vga_example__DOT__rx_ball_vel_y;
    vlSelfRef.debug_ball_rx = vlSelfRef.tt_um_vga_example__DOT__ball_rx_ack;
    vlSelfRef.debug_ack = vlSelfRef.tt_um_vga_example__DOT__ack;
    vlSelfRef.debug_has_ball = vlSelfRef.tt_um_vga_example__DOT__has_ball;
    vlSelfRef.uio_out = ((0xefU & (IData)(vlSelfRef.uio_out)) 
                         | ((IData)(vlSelfRef.tt_um_vga_example__DOT__has_ball) 
                            << 4U));
    vlSelfRef.tt_um_vga_example__DOT__packet_receiver_inst__DOT__state 
        = __Vdly__tt_um_vga_example__DOT__packet_receiver_inst__DOT__state;
    vlSelfRef.tt_um_vga_example__DOT__packet_receiver_inst__DOT__byte_cnt 
        = __Vdly__tt_um_vga_example__DOT__packet_receiver_inst__DOT__byte_cnt;
    vlSelfRef.tt_um_vga_example__DOT__packet_receiver_inst__DOT__running_ecc 
        = __Vdly__tt_um_vga_example__DOT__packet_receiver_inst__DOT__running_ecc;
    if (__VdlySet__tt_um_vga_example__DOT__rx_packet_bytes__v0) {
        vlSelfRef.tt_um_vga_example__DOT__rx_packet_bytes[__VdlyDim0__tt_um_vga_example__DOT__rx_packet_bytes__v0] 
            = __VdlyVal__tt_um_vga_example__DOT__rx_packet_bytes__v0;
    }
    vlSelfRef.debug_rx_packet_ready = vlSelfRef.tt_um_vga_example__DOT__rx_packet_ready;
    vlSelfRef.debug_rx_cmd = (0xfU & (vlSelfRef.tt_um_vga_example__DOT__rx_packet_bytes
                                      [0U] >> 4U));
    vlSelfRef.debug_rx_ack = (0xfU & (vlSelfRef.tt_um_vga_example__DOT__rx_packet_bytes
                                      [1U] >> 4U));
    vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__bit_idx 
        = __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__bit_idx;
    vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__receiving 
        = __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__receiving;
    vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__shift 
        = __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__shift;
    vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__baud_counter 
        = __Vdly__tt_um_vga_example__DOT__uart_rx_inst__DOT__baud_counter;
    vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__baud_tick 
        = (0U == (IData)(vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__baud_counter));
    vlSelfRef.debug_rx_data = vlSelfRef.tt_um_vga_example__DOT__rx_data;
}

VL_INLINE_OPT void Vtt_um_vga_example___024root___nba_sequent__TOP__2(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___nba_sequent__TOP__2\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tt_um_vga_example__DOT__has_ball_rx_sync 
        = vlSelfRef.__Vdly__tt_um_vga_example__DOT__has_ball_rx_sync;
    vlSelfRef.tt_um_vga_example__DOT__insync_rx_sync 
        = vlSelfRef.__Vdly__tt_um_vga_example__DOT__insync_rx_sync;
    vlSelfRef.debug_game_tick = ((0U == (IData)(vlSelfRef.tt_um_vga_example__DOT__hpos)) 
                                 & (0U == (IData)(vlSelfRef.tt_um_vga_example__DOT__vpos)));
    vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__rx_sync 
        = vlSelfRef.debug_uart_rx;
}

VL_INLINE_OPT void Vtt_um_vga_example___024root___nba_comb__TOP__0(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___nba_comb__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ tt_um_vga_example__DOT__vga_r0;
    tt_um_vga_example__DOT__vga_r0 = 0;
    // Body
    vlSelfRef.debug_send_ack_packet = ((~ ((IData)(vlSelfRef.tt_um_vga_example__DOT__ack) 
                                           | (IData)(vlSelfRef.tt_um_vga_example__DOT__send_packet_reg))) 
                                       & (IData)(vlSelfRef.tt_um_vga_example__DOT__ack_prev));
    tt_um_vga_example__DOT__vga_r0 = ((IData)(vlSelfRef.sdl_de) 
                                      & (((IData)(vlSelfRef.tt_um_vga_example__DOT__has_ball) 
                                          & ((((IData)(4U) 
                                               + (IData)(vlSelfRef.tt_um_vga_example__DOT__hpos)) 
                                              >= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x)) 
                                             & (((IData)(vlSelfRef.tt_um_vga_example__DOT__hpos) 
                                                 <= 
                                                 ((IData)(4U) 
                                                  + (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x))) 
                                                & ((((IData)(4U) 
                                                     + (IData)(vlSelfRef.tt_um_vga_example__DOT__vpos)) 
                                                    >= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_y)) 
                                                   & ((IData)(vlSelfRef.tt_um_vga_example__DOT__vpos) 
                                                      < 
                                                      ((IData)(4U) 
                                                       + (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_y))))))) 
                                         | ((0x13bU 
                                             <= (IData)(vlSelfRef.tt_um_vga_example__DOT__hpos)) 
                                            & ((0x145U 
                                                > (IData)(vlSelfRef.tt_um_vga_example__DOT__hpos)) 
                                               & (((IData)(vlSelfRef.tt_um_vga_example__DOT__vpos) 
                                                   >= 
                                                   ((IData)(vlSelfRef.tt_um_vga_example__DOT__paddle_y) 
                                                    - (IData)(0x1eU))) 
                                                  & ((IData)(vlSelfRef.tt_um_vga_example__DOT__vpos) 
                                                     < 
                                                     ((IData)(0x1eU) 
                                                      + (IData)(vlSelfRef.tt_um_vga_example__DOT__paddle_y))))))));
    vlSelfRef.uo_out = ((((IData)(vlSelfRef.tt_um_vga_example__DOT__vga_hsync) 
                          << 7U) | (((IData)(tt_um_vga_example__DOT__vga_r0) 
                                     << 6U) | (0x30U 
                                               & ((- (IData)((IData)(tt_um_vga_example__DOT__vga_r0))) 
                                                  << 4U)))) 
                        | (((IData)(vlSelfRef.tt_um_vga_example__DOT__vga_vsync) 
                            << 3U) | (7U & (- (IData)((IData)(tt_um_vga_example__DOT__vga_r0))))));
    vlSelfRef.sdl_r = ((IData)(tt_um_vga_example__DOT__vga_r0)
                        ? 0xffU : 0U);
    vlSelfRef.sdl_g = vlSelfRef.sdl_r;
    vlSelfRef.sdl_b = vlSelfRef.sdl_r;
}

void Vtt_um_vga_example___024root___eval_triggers__act(Vtt_um_vga_example___024root* vlSelf);

bool Vtt_um_vga_example___024root___eval_phase__act(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtt_um_vga_example___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtt_um_vga_example___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtt_um_vga_example___024root___eval_phase__nba(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtt_um_vga_example___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtt_um_vga_example___024root___dump_triggers__ico(Vtt_um_vga_example___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtt_um_vga_example___024root___dump_triggers__nba(Vtt_um_vga_example___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtt_um_vga_example___024root___dump_triggers__act(Vtt_um_vga_example___024root* vlSelf);
#endif  // VL_DEBUG

void Vtt_um_vga_example___024root___eval(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___eval\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vtt_um_vga_example___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("tt_um_vga_example.v", 13, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtt_um_vga_example___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtt_um_vga_example___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tt_um_vga_example.v", 13, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vtt_um_vga_example___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tt_um_vga_example.v", 13, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtt_um_vga_example___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtt_um_vga_example___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtt_um_vga_example___024root___eval_debug_assertions(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.ena & 0xfeU))) {
        Verilated::overWidthError("ena");}
    if (VL_UNLIKELY((vlSelfRef.clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelfRef.rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
}
#endif  // VL_DEBUG
