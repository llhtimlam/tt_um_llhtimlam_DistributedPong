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
    // Body
    vlSelfRef.tt_um_vga_example__DOT____Vcellinp__comms__reset 
        = (1U & ((~ (IData)(vlSelfRef.tt_um_vga_example__DOT__nego_done_reg)) 
                 | (IData)(vlSelfRef.sim_rst)));
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
void Vtt_um_vga_example___024root___nba_sequent__TOP__3(Vtt_um_vga_example___024root* vlSelf);
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
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtt_um_vga_example___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtt_um_vga_example___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtt_um_vga_example___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((7ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtt_um_vga_example___024root___nba_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtt_um_vga_example___024root___nba_sequent__TOP__0(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*9:0*/ __Vdly__tt_um_vga_example__DOT__vga_inst__DOT__h_cnt;
    __Vdly__tt_um_vga_example__DOT__vga_inst__DOT__h_cnt = 0;
    SData/*9:0*/ __Vdly__tt_um_vga_example__DOT__vga_inst__DOT__v_cnt;
    __Vdly__tt_um_vga_example__DOT__vga_inst__DOT__v_cnt = 0;
    CData/*0:0*/ __Vdly__tt_um_vga_example__DOT__comms__DOT__edge_detected;
    __Vdly__tt_um_vga_example__DOT__comms__DOT__edge_detected = 0;
    CData/*1:0*/ __Vdly__tt_um_vga_example__DOT__comms__DOT__state;
    __Vdly__tt_um_vga_example__DOT__comms__DOT__state = 0;
    // Body
    vlSelfRef.__Vdly__tt_um_vga_example__DOT__nego_timer 
        = vlSelfRef.tt_um_vga_example__DOT__nego_timer;
    vlSelfRef.__Vdly__tt_um_vga_example__DOT__comms__DOT__rx_shift_cnt 
        = vlSelfRef.tt_um_vga_example__DOT__comms__DOT__rx_shift_cnt;
    vlSelfRef.__Vdly__tt_um_vga_example__DOT__comms__DOT__rx_shift_reg 
        = vlSelfRef.tt_um_vga_example__DOT__comms__DOT__rx_shift_reg;
    vlSelfRef.__Vdly__tt_um_vga_example__DOT__nego_done_reg 
        = vlSelfRef.tt_um_vga_example__DOT__nego_done_reg;
    __Vdly__tt_um_vga_example__DOT__comms__DOT__state 
        = vlSelfRef.tt_um_vga_example__DOT__comms__DOT__state;
    __Vdly__tt_um_vga_example__DOT__vga_inst__DOT__h_cnt 
        = vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__h_cnt;
    __Vdly__tt_um_vga_example__DOT__vga_inst__DOT__v_cnt 
        = vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__v_cnt;
    vlSelfRef.__Vdly__tt_um_vga_example__DOT__spawn_req_meta 
        = vlSelfRef.tt_um_vga_example__DOT__spawn_req_meta;
    __Vdly__tt_um_vga_example__DOT__comms__DOT__edge_detected 
        = vlSelfRef.tt_um_vga_example__DOT__comms__DOT__edge_detected;
    if (vlSelfRef.sim_rst) {
        __Vdly__tt_um_vga_example__DOT__vga_inst__DOT__h_cnt = 0U;
        __Vdly__tt_um_vga_example__DOT__vga_inst__DOT__v_cnt = 0U;
    } else if ((0x31fU > (IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__h_cnt))) {
        __Vdly__tt_um_vga_example__DOT__vga_inst__DOT__h_cnt 
            = (0x3ffU & ((IData)(1U) + (IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__h_cnt)));
    } else {
        __Vdly__tt_um_vga_example__DOT__vga_inst__DOT__v_cnt 
            = ((0x20cU > (IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__v_cnt))
                ? (0x3ffU & ((IData)(1U) + (IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__v_cnt)))
                : 0U);
        __Vdly__tt_um_vga_example__DOT__vga_inst__DOT__h_cnt = 0U;
    }
    if (vlSelfRef.tt_um_vga_example__DOT____Vcellinp__comms__reset) {
        __Vdly__tt_um_vga_example__DOT__comms__DOT__edge_detected = 0U;
        __Vdly__tt_um_vga_example__DOT__comms__DOT__state = 0U;
        vlSelfRef.tt_um_vga_example__DOT__comm_sync_out = 0U;
        vlSelfRef.uio_oe = 0U;
        vlSelfRef.uio_out = 0U;
    } else {
        if ((((IData)(vlSelfRef.tt_um_vga_example__DOT__ball_at_edge_reg) 
              & (~ (IData)(vlSelfRef.tt_um_vga_example__DOT__comms__DOT__last_ball_at_edge))) 
             & (~ (IData)(vlSelfRef.tt_um_vga_example__DOT__comms__DOT__edge_detected)))) {
            __Vdly__tt_um_vga_example__DOT__comms__DOT__edge_detected = 1U;
        }
        if ((3U == (IData)(vlSelfRef.tt_um_vga_example__DOT__comms__DOT__state))) {
            __Vdly__tt_um_vga_example__DOT__comms__DOT__edge_detected = 0U;
        }
        if ((0U == (IData)(vlSelfRef.tt_um_vga_example__DOT__comms__DOT__state))) {
            if (vlSelfRef.tt_um_vga_example__DOT__comms__DOT__edge_detected) {
                vlSelfRef.tt_um_vga_example__DOT__comm_sync_out = 1U;
                vlSelfRef.uio_oe = 0xffU;
                vlSelfRef.uio_out = (0xffU & (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_y));
                __Vdly__tt_um_vga_example__DOT__comms__DOT__state = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.tt_um_vga_example__DOT__comms__DOT__state))) {
            vlSelfRef.uio_out = ((0xc0U & ((IData)(vlSelfRef.tt_um_vga_example__DOT__ball_y) 
                                           >> 2U)) 
                                 | ((0x38U & ((IData)(vlSelfRef.tt_um_vga_example__DOT__vel_x) 
                                              << 3U)) 
                                    | (7U & (IData)(vlSelfRef.tt_um_vga_example__DOT__vel_y))));
            __Vdly__tt_um_vga_example__DOT__comms__DOT__state = 2U;
        } else if ((2U == (IData)(vlSelfRef.tt_um_vga_example__DOT__comms__DOT__state))) {
            vlSelfRef.tt_um_vga_example__DOT__comm_sync_out = 0U;
            __Vdly__tt_um_vga_example__DOT__comms__DOT__state = 3U;
        } else if ((3U == (IData)(vlSelfRef.tt_um_vga_example__DOT__comms__DOT__state))) {
            vlSelfRef.uio_oe = 0U;
            __Vdly__tt_um_vga_example__DOT__comms__DOT__state = 0U;
        } else {
            __Vdly__tt_um_vga_example__DOT__comms__DOT__state = 0U;
        }
    }
    vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__h_cnt 
        = __Vdly__tt_um_vga_example__DOT__vga_inst__DOT__h_cnt;
    vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__v_cnt 
        = __Vdly__tt_um_vga_example__DOT__vga_inst__DOT__v_cnt;
    vlSelfRef.tt_um_vga_example__DOT__comms__DOT__state 
        = __Vdly__tt_um_vga_example__DOT__comms__DOT__state;
    vlSelfRef.tt_um_vga_example__DOT__comms__DOT__edge_detected 
        = __Vdly__tt_um_vga_example__DOT__comms__DOT__edge_detected;
    vlSelfRef.sdl_sx = vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__h_cnt;
    vlSelfRef.sdl_sy = vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__v_cnt;
    vlSelfRef.tt_um_vga_example__DOT__vsync = (1U & 
                                               (~ (
                                                   (0x1eaU 
                                                    <= (IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__v_cnt)) 
                                                   & (0x1ecU 
                                                      > (IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__v_cnt)))));
    vlSelfRef.sdl_de = ((0x280U > (IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__h_cnt)) 
                        & (0x1e0U > (IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__v_cnt)));
    vlSelfRef.tt_um_vga_example__DOT__comms__DOT__last_ball_at_edge 
        = ((1U & (~ (IData)(vlSelfRef.tt_um_vga_example__DOT____Vcellinp__comms__reset))) 
           && (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_at_edge_reg));
    vlSelfRef.tt_um_vga_example__DOT__ball_at_edge_reg 
        = ((1U & (~ (IData)(vlSelfRef.sim_rst))) && 
           ((IData)(vlSelfRef.tt_um_vga_example__DOT__nego_done_reg) 
            && ((IData)(vlSelfRef.tt_um_vga_example__DOT__has_ball) 
                && ((IData)(vlSelfRef.tt_um_vga_example__DOT__is_right_fpga_reg)
                     ? ((0x145U >= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x)) 
                        & (0x13bU <= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x)))
                     : ((0x13bU <= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x)) 
                        & (0x145U >= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x)))))));
}

VL_INLINE_OPT void Vtt_um_vga_example___024root___nba_sequent__TOP__1(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___nba_sequent__TOP__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
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
    SData/*8:0*/ __Vdly__tt_um_vga_example__DOT__paddle_y;
    __Vdly__tt_um_vga_example__DOT__paddle_y = 0;
    CData/*0:0*/ __Vdly__tt_um_vga_example__DOT__game_started;
    __Vdly__tt_um_vga_example__DOT__game_started = 0;
    // Body
    vlSelfRef.__Vdly__tt_um_vga_example__DOT__spawn_ack 
        = vlSelfRef.tt_um_vga_example__DOT__spawn_ack;
    __Vdly__tt_um_vga_example__DOT__vel_x = vlSelfRef.tt_um_vga_example__DOT__vel_x;
    __Vdly__tt_um_vga_example__DOT__vel_y = vlSelfRef.tt_um_vga_example__DOT__vel_y;
    __Vdly__tt_um_vga_example__DOT__game_started = vlSelfRef.tt_um_vga_example__DOT__game_started;
    __Vdly__tt_um_vga_example__DOT__ball_x = vlSelfRef.tt_um_vga_example__DOT__ball_x;
    __Vdly__tt_um_vga_example__DOT__ball_y = vlSelfRef.tt_um_vga_example__DOT__ball_y;
    __Vdly__tt_um_vga_example__DOT__paddle_y = vlSelfRef.tt_um_vga_example__DOT__paddle_y;
    __Vdly__tt_um_vga_example__DOT__has_ball = vlSelfRef.tt_um_vga_example__DOT__has_ball;
    if (vlSelfRef.sim_rst) {
        vlSelfRef.__Vdly__tt_um_vga_example__DOT__spawn_ack = 0U;
        __Vdly__tt_um_vga_example__DOT__has_ball = 0U;
        __Vdly__tt_um_vga_example__DOT__ball_x = 0x136U;
        __Vdly__tt_um_vga_example__DOT__ball_y = 0xf0U;
        __Vdly__tt_um_vga_example__DOT__vel_x = 0xdU;
        __Vdly__tt_um_vga_example__DOT__vel_y = 2U;
        __Vdly__tt_um_vga_example__DOT__paddle_y = 0xd2U;
        __Vdly__tt_um_vga_example__DOT__game_started = 0U;
    } else if (vlSelfRef.tt_um_vga_example__DOT__nego_done_reg) {
        if (((IData)(vlSelfRef.tt_um_vga_example__DOT__spawn_req_sync) 
             & (~ (IData)(vlSelfRef.tt_um_vga_example__DOT__has_ball)))) {
            vlSelfRef.__Vdly__tt_um_vga_example__DOT__spawn_ack = 1U;
            __Vdly__tt_um_vga_example__DOT__has_ball = 1U;
            __Vdly__tt_um_vga_example__DOT__ball_y 
                = vlSelfRef.tt_um_vga_example__DOT__pending_y;
            __Vdly__tt_um_vga_example__DOT__vel_x = 
                ((8U & ((IData)(vlSelfRef.tt_um_vga_example__DOT__pending_phys) 
                        >> 2U)) | (7U & ((IData)(vlSelfRef.tt_um_vga_example__DOT__pending_phys) 
                                         >> 3U)));
            __Vdly__tt_um_vga_example__DOT__vel_y = 
                ((8U & ((IData)(vlSelfRef.tt_um_vga_example__DOT__pending_phys) 
                        << 1U)) | (7U & (IData)(vlSelfRef.tt_um_vga_example__DOT__pending_phys)));
            __Vdly__tt_um_vga_example__DOT__ball_x 
                = ((IData)(vlSelfRef.tt_um_vga_example__DOT__is_right_fpga_reg)
                    ? 0x14aU : 0x136U);
            __Vdly__tt_um_vga_example__DOT__game_started = 1U;
        } else {
            vlSelfRef.__Vdly__tt_um_vga_example__DOT__spawn_ack = 0U;
        }
        if ((1U & (((~ (IData)(vlSelfRef.tt_um_vga_example__DOT__game_started)) 
                    & (~ (IData)(vlSelfRef.tt_um_vga_example__DOT__has_ball))) 
                   & (~ (IData)(vlSelfRef.tt_um_vga_example__DOT__is_right_fpga_reg))))) {
            __Vdly__tt_um_vga_example__DOT__has_ball = 1U;
            __Vdly__tt_um_vga_example__DOT__ball_x = 0x136U;
            __Vdly__tt_um_vga_example__DOT__ball_y = 0xf0U;
            __Vdly__tt_um_vga_example__DOT__vel_x = 0xdU;
            __Vdly__tt_um_vga_example__DOT__vel_y = 2U;
            __Vdly__tt_um_vga_example__DOT__game_started = 1U;
        }
        if (vlSelfRef.tt_um_vga_example__DOT__has_ball) {
            __Vdly__tt_um_vga_example__DOT__ball_x 
                = (0x3ffU & ((IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x) 
                             + ((0x3f0U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.tt_um_vga_example__DOT__vel_x) 
                                                          >> 3U)))) 
                                           << 4U)) 
                                | (IData)(vlSelfRef.tt_um_vga_example__DOT__vel_x))));
            __Vdly__tt_um_vga_example__DOT__ball_y 
                = (0x3ffU & ((IData)(vlSelfRef.tt_um_vga_example__DOT__ball_y) 
                             + ((0x3f0U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.tt_um_vga_example__DOT__vel_y) 
                                                          >> 3U)))) 
                                           << 4U)) 
                                | (IData)(vlSelfRef.tt_um_vga_example__DOT__vel_y))));
            if ((0xaU >= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_y))) {
                __Vdly__tt_um_vga_example__DOT__vel_y = 2U;
                __Vdly__tt_um_vga_example__DOT__ball_y = 0xbU;
            } else if ((0x1d6U <= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_y))) {
                __Vdly__tt_um_vga_example__DOT__vel_y = 0xeU;
                __Vdly__tt_um_vga_example__DOT__ball_y = 0x1d5U;
            }
            if (vlSelfRef.tt_um_vga_example__DOT__is_right_fpga_reg) {
                if (((((VL_LTS_III(32, 0U, VL_EXTENDS_II(32,4, (IData)(vlSelfRef.tt_um_vga_example__DOT__vel_x))) 
                        & (0x267U <= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x))) 
                       & (0x271U >= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x))) 
                      & (((IData)(8U) + (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_y)) 
                         > (IData)(vlSelfRef.tt_um_vga_example__DOT__paddle_y))) 
                     & ((IData)(vlSelfRef.tt_um_vga_example__DOT__ball_y) 
                        < ((IData)(0x3cU) + (IData)(vlSelfRef.tt_um_vga_example__DOT__paddle_y))))) {
                    __Vdly__tt_um_vga_example__DOT__vel_x = 0xdU;
                    __Vdly__tt_um_vga_example__DOT__ball_x = 0x266U;
                }
                if ((0x27eU <= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x))) {
                    __Vdly__tt_um_vga_example__DOT__ball_x = 0x1e0U;
                    __Vdly__tt_um_vga_example__DOT__vel_x = 0xdU;
                }
                if ((0x145U >= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x))) {
                    __Vdly__tt_um_vga_example__DOT__has_ball = 0U;
                }
            } else {
                if (((((VL_GTS_III(32, 0U, VL_EXTENDS_II(32,4, (IData)(vlSelfRef.tt_um_vga_example__DOT__vel_x))) 
                        & (0x14U >= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x))) 
                       & (0xaU <= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x))) 
                      & (((IData)(8U) + (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_y)) 
                         > (IData)(vlSelfRef.tt_um_vga_example__DOT__paddle_y))) 
                     & ((IData)(vlSelfRef.tt_um_vga_example__DOT__ball_y) 
                        < ((IData)(0x3cU) + (IData)(vlSelfRef.tt_um_vga_example__DOT__paddle_y))))) {
                    __Vdly__tt_um_vga_example__DOT__vel_x = 3U;
                    __Vdly__tt_um_vga_example__DOT__ball_x = 0x15U;
                }
                if ((2U >= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x))) {
                    __Vdly__tt_um_vga_example__DOT__vel_x = 3U;
                    __Vdly__tt_um_vga_example__DOT__ball_x = 0xa0U;
                }
                if ((0x13bU <= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x))) {
                    __Vdly__tt_um_vga_example__DOT__has_ball = 0U;
                }
            }
        }
    } else {
        __Vdly__tt_um_vga_example__DOT__game_started = 0U;
        __Vdly__tt_um_vga_example__DOT__has_ball = 0U;
        vlSelfRef.__Vdly__tt_um_vga_example__DOT__spawn_ack = 0U;
    }
    if (((IData)(vlSelfRef.ui_in) & (4U < (IData)(vlSelfRef.tt_um_vga_example__DOT__paddle_y)))) {
        __Vdly__tt_um_vga_example__DOT__paddle_y = 
            (0x1ffU & ((IData)(vlSelfRef.tt_um_vga_example__DOT__paddle_y) 
                       - (IData)(4U)));
    }
    if ((((IData)(vlSelfRef.ui_in) >> 1U) & (0x1a0U 
                                             > (IData)(vlSelfRef.tt_um_vga_example__DOT__paddle_y)))) {
        __Vdly__tt_um_vga_example__DOT__paddle_y = 
            (0x1ffU & ((IData)(4U) + (IData)(vlSelfRef.tt_um_vga_example__DOT__paddle_y)));
    }
    vlSelfRef.tt_um_vga_example__DOT__game_started 
        = __Vdly__tt_um_vga_example__DOT__game_started;
    vlSelfRef.tt_um_vga_example__DOT__paddle_y = __Vdly__tt_um_vga_example__DOT__paddle_y;
    vlSelfRef.tt_um_vga_example__DOT__vel_x = __Vdly__tt_um_vga_example__DOT__vel_x;
    vlSelfRef.tt_um_vga_example__DOT__vel_y = __Vdly__tt_um_vga_example__DOT__vel_y;
    vlSelfRef.tt_um_vga_example__DOT__ball_y = __Vdly__tt_um_vga_example__DOT__ball_y;
    vlSelfRef.tt_um_vga_example__DOT__ball_x = __Vdly__tt_um_vga_example__DOT__ball_x;
    vlSelfRef.tt_um_vga_example__DOT__has_ball = __Vdly__tt_um_vga_example__DOT__has_ball;
    vlSelfRef.tt_um_vga_example__DOT__spawn_req_sync 
        = ((1U & (~ (IData)(vlSelfRef.sim_rst))) && 
           ((IData)(vlSelfRef.tt_um_vga_example__DOT__nego_done_reg) 
            && (IData)(vlSelfRef.tt_um_vga_example__DOT__spawn_req_meta)));
}

VL_INLINE_OPT void Vtt_um_vga_example___024root___nba_sequent__TOP__2(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___nba_sequent__TOP__2\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & ((IData)(vlSelfRef.sim_rst) | (~ (IData)(vlSelfRef.tt_um_vga_example__DOT__nego_done_reg))))) {
        vlSelfRef.__Vdly__tt_um_vga_example__DOT__spawn_req_meta = 0U;
    } else if (((IData)(vlSelfRef.tt_um_vga_example__DOT__spawn_ball) 
                & (~ (IData)(vlSelfRef.tt_um_vga_example__DOT__spawn_req_meta)))) {
        vlSelfRef.__Vdly__tt_um_vga_example__DOT__spawn_req_meta = 1U;
        vlSelfRef.tt_um_vga_example__DOT__pending_y 
            = ((0x300U & ((IData)(vlSelfRef.tt_um_vga_example__DOT__rx_phys) 
                          << 2U)) | (IData)(vlSelfRef.tt_um_vga_example__DOT__rx_y));
        vlSelfRef.tt_um_vga_example__DOT__pending_phys 
            = vlSelfRef.tt_um_vga_example__DOT__rx_phys;
    } else if (vlSelfRef.tt_um_vga_example__DOT__spawn_ack) {
        vlSelfRef.__Vdly__tt_um_vga_example__DOT__spawn_req_meta = 0U;
    }
    if (vlSelfRef.sim_rst) {
        vlSelfRef.tt_um_vga_example__DOT__is_right_fpga_reg = 0U;
        vlSelfRef.__Vdly__tt_um_vga_example__DOT__nego_done_reg = 0U;
        vlSelfRef.__Vdly__tt_um_vga_example__DOT__nego_timer = 0U;
    } else if ((1U & (~ (IData)(vlSelfRef.tt_um_vga_example__DOT__nego_done_reg)))) {
        if ((0x80U & (IData)(vlSelfRef.ui_in))) {
            vlSelfRef.tt_um_vga_example__DOT__is_right_fpga_reg = 1U;
            vlSelfRef.__Vdly__tt_um_vga_example__DOT__nego_done_reg = 1U;
        } else if ((0x1ffffU == vlSelfRef.tt_um_vga_example__DOT__nego_timer)) {
            vlSelfRef.tt_um_vga_example__DOT__is_right_fpga_reg = 0U;
            vlSelfRef.__Vdly__tt_um_vga_example__DOT__nego_done_reg = 1U;
        } else {
            vlSelfRef.__Vdly__tt_um_vga_example__DOT__nego_timer 
                = (0x1ffffU & ((IData)(1U) + vlSelfRef.tt_um_vga_example__DOT__nego_timer));
        }
    }
    vlSelfRef.tt_um_vga_example__DOT__spawn_req_meta 
        = vlSelfRef.__Vdly__tt_um_vga_example__DOT__spawn_req_meta;
    vlSelfRef.tt_um_vga_example__DOT__nego_timer = vlSelfRef.__Vdly__tt_um_vga_example__DOT__nego_timer;
    vlSelfRef.tt_um_vga_example__DOT__nego_done_reg 
        = vlSelfRef.__Vdly__tt_um_vga_example__DOT__nego_done_reg;
    if (vlSelfRef.tt_um_vga_example__DOT____Vcellinp__comms__reset) {
        vlSelfRef.__Vdly__tt_um_vga_example__DOT__comms__DOT__rx_shift_cnt = 0U;
        vlSelfRef.__Vdly__tt_um_vga_example__DOT__comms__DOT__rx_shift_reg = 0U;
        vlSelfRef.tt_um_vga_example__DOT__spawn_ball = 0U;
        vlSelfRef.tt_um_vga_example__DOT__rx_y = 0U;
        vlSelfRef.tt_um_vga_example__DOT__rx_phys = 0U;
    } else {
        vlSelfRef.tt_um_vga_example__DOT__spawn_ball = 0U;
        if ((1U & (((IData)(vlSelfRef.ui_in) >> 3U) 
                   & (~ (IData)(vlSelfRef.tt_um_vga_example__DOT__comms__DOT__in_sync_prev))))) {
            vlSelfRef.__Vdly__tt_um_vga_example__DOT__comms__DOT__rx_shift_cnt = 0U;
            vlSelfRef.__Vdly__tt_um_vga_example__DOT__comms__DOT__rx_shift_reg = 0U;
        }
        if ((8U & (IData)(vlSelfRef.ui_in))) {
            if ((0U == (IData)(vlSelfRef.tt_um_vga_example__DOT__comms__DOT__rx_shift_cnt))) {
                vlSelfRef.__Vdly__tt_um_vga_example__DOT__comms__DOT__rx_shift_reg 
                    = ((0xff00U & (IData)(vlSelfRef.__Vdly__tt_um_vga_example__DOT__comms__DOT__rx_shift_reg)) 
                       | (IData)(vlSelfRef.uio_in));
                vlSelfRef.__Vdly__tt_um_vga_example__DOT__comms__DOT__rx_shift_cnt = 1U;
            } else if ((1U == (IData)(vlSelfRef.tt_um_vga_example__DOT__comms__DOT__rx_shift_cnt))) {
                vlSelfRef.__Vdly__tt_um_vga_example__DOT__comms__DOT__rx_shift_cnt = 2U;
                vlSelfRef.tt_um_vga_example__DOT__rx_y 
                    = (0xffU & (IData)(vlSelfRef.tt_um_vga_example__DOT__comms__DOT__rx_shift_reg));
                vlSelfRef.tt_um_vga_example__DOT__rx_phys 
                    = vlSelfRef.uio_in;
                vlSelfRef.tt_um_vga_example__DOT__spawn_ball = 1U;
                vlSelfRef.__Vdly__tt_um_vga_example__DOT__comms__DOT__rx_shift_reg 
                    = ((0xffU & (IData)(vlSelfRef.__Vdly__tt_um_vga_example__DOT__comms__DOT__rx_shift_reg)) 
                       | ((IData)(vlSelfRef.uio_in) 
                          << 8U));
            }
        }
    }
    vlSelfRef.nego_done = vlSelfRef.tt_um_vga_example__DOT__nego_done_reg;
    vlSelfRef.is_right_fpga = vlSelfRef.tt_um_vga_example__DOT__is_right_fpga_reg;
    vlSelfRef.tt_um_vga_example__DOT__comms__DOT__rx_shift_cnt 
        = vlSelfRef.__Vdly__tt_um_vga_example__DOT__comms__DOT__rx_shift_cnt;
    vlSelfRef.tt_um_vga_example__DOT__comms__DOT__rx_shift_reg 
        = vlSelfRef.__Vdly__tt_um_vga_example__DOT__comms__DOT__rx_shift_reg;
    vlSelfRef.tt_um_vga_example__DOT__comms__DOT__in_sync_prev 
        = ((1U & (~ (IData)(vlSelfRef.tt_um_vga_example__DOT____Vcellinp__comms__reset))) 
           && (1U & ((IData)(vlSelfRef.ui_in) >> 3U)));
    vlSelfRef.tt_um_vga_example__DOT____Vcellinp__comms__reset 
        = (1U & ((~ (IData)(vlSelfRef.tt_um_vga_example__DOT__nego_done_reg)) 
                 | (IData)(vlSelfRef.sim_rst)));
}

VL_INLINE_OPT void Vtt_um_vga_example___024root___nba_sequent__TOP__3(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___nba_sequent__TOP__3\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tt_um_vga_example__DOT__spawn_ack = vlSelfRef.__Vdly__tt_um_vga_example__DOT__spawn_ack;
}

VL_INLINE_OPT void Vtt_um_vga_example___024root___nba_comb__TOP__0(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___nba_comb__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ tt_um_vga_example__DOT__pixel;
    tt_um_vga_example__DOT__pixel = 0;
    // Body
    tt_um_vga_example__DOT__pixel = ((IData)(vlSelfRef.sdl_de) 
                                     & (((IData)(vlSelfRef.tt_um_vga_example__DOT__is_right_fpga_reg)
                                          ? (0x140U 
                                             <= (IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__h_cnt))
                                          : (0x140U 
                                             > (IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__h_cnt))) 
                                        & (((IData)(vlSelfRef.tt_um_vga_example__DOT__has_ball) 
                                            & (((IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__h_cnt) 
                                                >= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x)) 
                                               & (((IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__h_cnt) 
                                                   < 
                                                   ((IData)(8U) 
                                                    + (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x))) 
                                                  & (((IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__v_cnt) 
                                                      >= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_y)) 
                                                     & ((IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__v_cnt) 
                                                        < 
                                                        ((IData)(8U) 
                                                         + (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_y))))))) 
                                           | (((IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__h_cnt) 
                                               >= ((IData)(vlSelfRef.tt_um_vga_example__DOT__is_right_fpga_reg)
                                                    ? 0x26cU
                                                    : 0xaU)) 
                                              & (((IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__h_cnt) 
                                                  < 
                                                  ((IData)(8U) 
                                                   + 
                                                   ((IData)(vlSelfRef.tt_um_vga_example__DOT__is_right_fpga_reg)
                                                     ? 0x26cU
                                                     : 0xaU))) 
                                                 & (((IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__v_cnt) 
                                                     >= (IData)(vlSelfRef.tt_um_vga_example__DOT__paddle_y)) 
                                                    & ((IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__v_cnt) 
                                                       < 
                                                       ((IData)(0x3cU) 
                                                        + (IData)(vlSelfRef.tt_um_vga_example__DOT__paddle_y)))))))));
    vlSelfRef.uo_out = (((0x80U & ((~ ((0x290U <= (IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__h_cnt)) 
                                       & (0x2f0U > (IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__h_cnt)))) 
                                   << 7U)) | (((IData)(tt_um_vga_example__DOT__pixel) 
                                               << 6U) 
                                              | (0x30U 
                                                 & ((- (IData)((IData)(tt_um_vga_example__DOT__pixel))) 
                                                    << 4U)))) 
                        | ((((IData)(vlSelfRef.tt_um_vga_example__DOT__comm_sync_out) 
                             << 3U) | ((IData)(vlSelfRef.tt_um_vga_example__DOT__vsync) 
                                       << 2U)) | (((IData)(vlSelfRef.tt_um_vga_example__DOT__ball_at_edge_reg) 
                                                   << 1U) 
                                                  | (IData)(vlSelfRef.tt_um_vga_example__DOT__has_ball))));
    vlSelfRef.sdl_r = ((IData)(tt_um_vga_example__DOT__pixel)
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
    VlTriggerVec<3> __VpreTriggered;
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
            VL_FATAL_MT("tt_um_vga_example.v", 3, "", "Input combinational region did not converge.");
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
            VL_FATAL_MT("tt_um_vga_example.v", 3, "", "NBA region did not converge.");
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
                VL_FATAL_MT("tt_um_vga_example.v", 3, "", "Active region did not converge.");
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
    if (VL_UNLIKELY((vlSelfRef.clk_pix & 0xfeU))) {
        Verilated::overWidthError("clk_pix");}
    if (VL_UNLIKELY((vlSelfRef.sim_rst & 0xfeU))) {
        Verilated::overWidthError("sim_rst");}
}
#endif  // VL_DEBUG
