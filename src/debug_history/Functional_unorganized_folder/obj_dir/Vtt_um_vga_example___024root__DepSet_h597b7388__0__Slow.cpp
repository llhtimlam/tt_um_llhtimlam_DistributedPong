// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtt_um_vga_example.h for the primary calling header

#include "Vtt_um_vga_example__pch.h"
#include "Vtt_um_vga_example___024root.h"

VL_ATTR_COLD void Vtt_um_vga_example___024root___eval_static(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___eval_static\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtt_um_vga_example___024root___eval_initial__TOP(Vtt_um_vga_example___024root* vlSelf);

VL_ATTR_COLD void Vtt_um_vga_example___024root___eval_initial(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___eval_initial\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtt_um_vga_example___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

VL_ATTR_COLD void Vtt_um_vga_example___024root___eval_initial__TOP(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___eval_initial__TOP\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.uio_out = (0x40U | (IData)(vlSelfRef.uio_out));
}

VL_ATTR_COLD void Vtt_um_vga_example___024root___eval_final(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___eval_final\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtt_um_vga_example___024root___dump_triggers__stl(Vtt_um_vga_example___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtt_um_vga_example___024root___eval_phase__stl(Vtt_um_vga_example___024root* vlSelf);

VL_ATTR_COLD void Vtt_um_vga_example___024root___eval_settle(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___eval_settle\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtt_um_vga_example___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tt_um_vga_example.v", 13, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtt_um_vga_example___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtt_um_vga_example___024root___dump_triggers__stl(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___dump_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtt_um_vga_example___024root___stl_sequent__TOP__0(Vtt_um_vga_example___024root* vlSelf);

VL_ATTR_COLD void Vtt_um_vga_example___024root___eval_stl(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___eval_stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtt_um_vga_example___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtt_um_vga_example___024root___stl_sequent__TOP__0(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___stl_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ tt_um_vga_example__DOT__vga_r0;
    tt_um_vga_example__DOT__vga_r0 = 0;
    CData/*7:0*/ tt_um_vga_example__DOT__tx_header;
    tt_um_vga_example__DOT__tx_header = 0;
    // Body
    vlSelfRef.debug_packet_cmd = vlSelfRef.tt_um_vga_example__DOT__packet_cmd;
    vlSelfRef.debug_packet2 = vlSelfRef.tt_um_vga_example__DOT__packet_2;
    vlSelfRef.debug_ack = vlSelfRef.tt_um_vga_example__DOT__ack;
    vlSelfRef.debug_send_packet = vlSelfRef.tt_um_vga_example__DOT__send_packet_reg;
    vlSelfRef.sdl_sx = vlSelfRef.tt_um_vga_example__DOT__hpos;
    vlSelfRef.sdl_sy = vlSelfRef.tt_um_vga_example__DOT__vpos;
    vlSelfRef.debug_tx_busy = vlSelfRef.tt_um_vga_example__DOT__tx_busy;
    vlSelfRef.debug_ball_x = vlSelfRef.tt_um_vga_example__DOT__ball_x;
    vlSelfRef.debug_ball_y = vlSelfRef.tt_um_vga_example__DOT__ball_y;
    vlSelfRef.debug_ball_vel_x = vlSelfRef.tt_um_vga_example__DOT__vel_x;
    vlSelfRef.debug_has_ball = vlSelfRef.tt_um_vga_example__DOT__has_ball;
    vlSelfRef.tt_um_vga_example__DOT__ball_at_edge 
        = ((0xaU >= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x)) 
           | ((0x276U <= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x)) 
              & (0x28aU >= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x))));
    vlSelfRef.tt_um_vga_example__DOT__ball_edge_l = 
        (0xaU >= (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_x));
    vlSelfRef.debug_uart_rx = (1U & ((IData)(vlSelfRef.uio_in) 
                                     >> 1U));
    vlSelfRef.debug_has_ball_rx = (1U & ((IData)(vlSelfRef.uio_in) 
                                         >> 5U));
    vlSelfRef.debug_4 = vlSelfRef.tt_um_vga_example__DOT__tx_data;
    vlSelfRef.debug_tx_data = vlSelfRef.tt_um_vga_example__DOT__tx_data;
    vlSelfRef.debug_6 = vlSelfRef.tt_um_vga_example__DOT__packet_busy;
    vlSelfRef.debug_packet_busy = vlSelfRef.tt_um_vga_example__DOT__packet_busy;
    vlSelfRef.debug_tx_sent = vlSelfRef.tt_um_vga_example__DOT__tx_send;
    vlSelfRef.debug_rx_data = vlSelfRef.tt_um_vga_example__DOT__rx_data;
    vlSelfRef.debug_rx_ball_x = vlSelfRef.tt_um_vga_example__DOT__rx_ball_x;
    vlSelfRef.debug_rx_ball_y = vlSelfRef.tt_um_vga_example__DOT__rx_ball_y;
    vlSelfRef.debug_rx_ball_vel_x = vlSelfRef.tt_um_vga_example__DOT__rx_ball_vel_x;
    vlSelfRef.debug_rx_ball_vel_y = vlSelfRef.tt_um_vga_example__DOT__rx_ball_vel_y;
    vlSelfRef.debug_rx_cmd = (0xfU & (vlSelfRef.tt_um_vga_example__DOT__rx_packet_bytes
                                      [0U] >> 4U));
    vlSelfRef.debug_rx_ack = (0xfU & (vlSelfRef.tt_um_vga_example__DOT__rx_packet_bytes
                                      [1U] >> 4U));
    vlSelfRef.debug_ball_vel_y = vlSelfRef.tt_um_vga_example__DOT__vel_y;
    vlSelfRef.debug_txcd = vlSelfRef.tt_um_vga_example__DOT__tx_cd;
    vlSelfRef.debug_bounce_cd = vlSelfRef.tt_um_vga_example__DOT__bounce_cd;
    vlSelfRef.debug_ball_tx = vlSelfRef.tt_um_vga_example__DOT__ball_tx_ready;
    vlSelfRef.debug_ball_rx = vlSelfRef.tt_um_vga_example__DOT__ball_rx_ack;
    vlSelfRef.debug_rx_packet_ready = vlSelfRef.tt_um_vga_example__DOT__rx_packet_ready;
    vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__baud_tick 
        = (0U == (IData)(vlSelfRef.tt_um_vga_example__DOT__uart_rx_inst__DOT__baud_counter));
    vlSelfRef.uio_out = ((0xefU & (IData)(vlSelfRef.uio_out)) 
                         | ((IData)(vlSelfRef.tt_um_vga_example__DOT__has_ball) 
                            << 4U));
    vlSelfRef.debug_game_tick = ((0U == (IData)(vlSelfRef.tt_um_vga_example__DOT__hpos)) 
                                 & (0U == (IData)(vlSelfRef.tt_um_vga_example__DOT__vpos)));
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
    vlSelfRef.debug_collision_paddle_y = ((((IData)(4U) 
                                            + (IData)(vlSelfRef.tt_um_vga_example__DOT__ball_y)) 
                                           >= ((IData)(vlSelfRef.tt_um_vga_example__DOT__paddle_y) 
                                               - (IData)(0x1eU))) 
                                          & (((IData)(vlSelfRef.tt_um_vga_example__DOT__ball_y) 
                                              - (IData)(4U)) 
                                             <= ((IData)(0x1eU) 
                                                 + (IData)(vlSelfRef.tt_um_vga_example__DOT__paddle_y))));
    vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__hmaxxed 
        = (1U & ((~ (IData)(vlSelfRef.rst_n)) | (0x31fU 
                                                 == (IData)(vlSelfRef.tt_um_vga_example__DOT__hpos))));
    vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__vmaxxed 
        = (1U & ((~ (IData)(vlSelfRef.rst_n)) | (0x20cU 
                                                 == (IData)(vlSelfRef.tt_um_vga_example__DOT__vpos))));
    vlSelfRef.debug_send_ack_packet = ((~ ((IData)(vlSelfRef.tt_um_vga_example__DOT__ack) 
                                           | (IData)(vlSelfRef.tt_um_vga_example__DOT__send_packet_reg))) 
                                       & (IData)(vlSelfRef.tt_um_vga_example__DOT__ack_prev));
    vlSelfRef.debug_5 = (0xa2bU == (IData)(vlSelfRef.baud_counter));
    vlSelfRef.debug_uart_tx = (1U & ((~ (IData)(vlSelfRef.tt_um_vga_example__DOT__tx_busy)) 
                                     | (IData)(vlSelfRef.tt_um_vga_example__DOT__uart_tx_inst__DOT__shift)));
    vlSelfRef.tt_um_vga_example__DOT__tx_packet_bytes[0U] 
        = ((IData)(vlSelfRef.tt_um_vga_example__DOT__send_packet_reg)
            ? 0x55U : 0U);
    vlSelfRef.tt_um_vga_example__DOT__tx_packet_bytes[2U] 
        = vlSelfRef.tt_um_vga_example__DOT__packet_1;
    vlSelfRef.tt_um_vga_example__DOT__tx_packet_bytes[3U] 
        = vlSelfRef.tt_um_vga_example__DOT__packet_2;
    vlSelfRef.tt_um_vga_example__DOT__tx_packet_bytes[4U] 
        = vlSelfRef.tt_um_vga_example__DOT__packet_3;
    vlSelfRef.tt_um_vga_example__DOT__tx_packet_bytes[5U] 
        = vlSelfRef.tt_um_vga_example__DOT__packet_4;
    tt_um_vga_example__DOT__tx_header = (((IData)(vlSelfRef.tt_um_vga_example__DOT__packet_cmd) 
                                          << 4U) | 
                                         (1U & ((IData)(vlSelfRef.ui_in) 
                                                >> 7U)));
    vlSelfRef.sdl_de = ((0x280U > (IData)(vlSelfRef.tt_um_vga_example__DOT__hpos)) 
                        & (0x1e0U > (IData)(vlSelfRef.tt_um_vga_example__DOT__vpos)));
    vlSelfRef.debug_baud_tick = vlSelfRef.debug_5;
    vlSelfRef.uio_out = ((0xfeU & (IData)(vlSelfRef.uio_out)) 
                         | (IData)(vlSelfRef.debug_uart_tx));
    vlSelfRef.tt_um_vga_example__DOT__tx_packet_bytes[1U] 
        = tt_um_vga_example__DOT__tx_header;
    vlSelfRef.tt_um_vga_example__DOT__tx_packet_bytes[6U] 
        = ((IData)(tt_um_vga_example__DOT__tx_header) 
           ^ ((IData)(vlSelfRef.tt_um_vga_example__DOT__packet_1) 
              ^ ((IData)(vlSelfRef.tt_um_vga_example__DOT__packet_2) 
                 ^ ((IData)(vlSelfRef.tt_um_vga_example__DOT__packet_3) 
                    ^ (IData)(vlSelfRef.tt_um_vga_example__DOT__packet_4)))));
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

VL_ATTR_COLD void Vtt_um_vga_example___024root___eval_triggers__stl(Vtt_um_vga_example___024root* vlSelf);

VL_ATTR_COLD bool Vtt_um_vga_example___024root___eval_phase__stl(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___eval_phase__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtt_um_vga_example___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtt_um_vga_example___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtt_um_vga_example___024root___dump_triggers__ico(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___dump_triggers__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtt_um_vga_example___024root___dump_triggers__act(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___dump_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtt_um_vga_example___024root___dump_triggers__nba(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___dump_triggers__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtt_um_vga_example___024root___ctor_var_reset(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->ui_in = VL_RAND_RESET_I(8);
    vlSelf->uo_out = VL_RAND_RESET_I(8);
    vlSelf->uio_in = VL_RAND_RESET_I(8);
    vlSelf->uio_out = VL_RAND_RESET_I(8);
    vlSelf->uio_oe = VL_RAND_RESET_I(8);
    vlSelf->ena = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->sdl_sx = VL_RAND_RESET_I(10);
    vlSelf->sdl_sy = VL_RAND_RESET_I(10);
    vlSelf->sdl_de = VL_RAND_RESET_I(1);
    vlSelf->sdl_r = VL_RAND_RESET_I(8);
    vlSelf->sdl_g = VL_RAND_RESET_I(8);
    vlSelf->sdl_b = VL_RAND_RESET_I(8);
    vlSelf->debug_1 = VL_RAND_RESET_I(1);
    vlSelf->debug_2 = VL_RAND_RESET_I(1);
    vlSelf->debug_3 = VL_RAND_RESET_I(1);
    vlSelf->debug_4 = VL_RAND_RESET_I(8);
    vlSelf->debug_5 = VL_RAND_RESET_I(1);
    vlSelf->debug_6 = VL_RAND_RESET_I(1);
    vlSelf->tx_sent = VL_RAND_RESET_I(1);
    vlSelf->debug_game_tick = VL_RAND_RESET_I(1);
    vlSelf->debug_baud_tick = VL_RAND_RESET_I(1);
    vlSelf->debug_uart_tx = VL_RAND_RESET_I(1);
    vlSelf->debug_uart_rx = VL_RAND_RESET_I(1);
    vlSelf->debug_tx_sent = VL_RAND_RESET_I(1);
    vlSelf->debug_tx_busy = VL_RAND_RESET_I(1);
    vlSelf->debug_packet_busy = VL_RAND_RESET_I(1);
    vlSelf->debug_tx_data = VL_RAND_RESET_I(8);
    vlSelf->debug_rx_data = VL_RAND_RESET_I(8);
    vlSelf->debug_rx_ball_x = VL_RAND_RESET_I(10);
    vlSelf->debug_rx_ball_y = VL_RAND_RESET_I(10);
    vlSelf->debug_ball_x = VL_RAND_RESET_I(10);
    vlSelf->debug_ball_y = VL_RAND_RESET_I(10);
    vlSelf->debug_rx_ball_vel_x = VL_RAND_RESET_I(4);
    vlSelf->debug_rx_ball_vel_y = VL_RAND_RESET_I(4);
    vlSelf->debug_rx_cmd = VL_RAND_RESET_I(4);
    vlSelf->debug_ball_vel_x = VL_RAND_RESET_I(4);
    vlSelf->debug_ball_vel_y = VL_RAND_RESET_I(4);
    vlSelf->debug_rx_ack = VL_RAND_RESET_I(4);
    vlSelf->debug_packet_cmd = VL_RAND_RESET_I(4);
    vlSelf->debug_packet2 = VL_RAND_RESET_I(8);
    vlSelf->debug_txcd = VL_RAND_RESET_I(4);
    vlSelf->debug_bounce_cd = VL_RAND_RESET_I(2);
    vlSelf->debug_collision_paddle_r = VL_RAND_RESET_I(1);
    vlSelf->debug_collision_paddle_l = VL_RAND_RESET_I(1);
    vlSelf->debug_collision_paddle_y = VL_RAND_RESET_I(1);
    vlSelf->debug_ball_tx = VL_RAND_RESET_I(1);
    vlSelf->debug_ball_rx = VL_RAND_RESET_I(1);
    vlSelf->debug_ack = VL_RAND_RESET_I(1);
    vlSelf->debug_send_ack_packet = VL_RAND_RESET_I(1);
    vlSelf->debug_send_packet = VL_RAND_RESET_I(1);
    vlSelf->debug_rx_packet_ready = VL_RAND_RESET_I(1);
    vlSelf->debug_has_ball = VL_RAND_RESET_I(1);
    vlSelf->debug_has_ball_rx = VL_RAND_RESET_I(1);
    vlSelf->baud_counter = VL_RAND_RESET_I(14);
    vlSelf->state1 = VL_RAND_RESET_I(2);
    vlSelf->byte_cnt = VL_RAND_RESET_I(3);
    vlSelf->bit_idx = VL_RAND_RESET_I(4);
    vlSelf->tt_um_vga_example__DOT__vga_hsync = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__vga_vsync = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__hpos = VL_RAND_RESET_I(10);
    vlSelf->tt_um_vga_example__DOT__vpos = VL_RAND_RESET_I(10);
    vlSelf->tt_um_vga_example__DOT__tx_busy = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__rx_ready = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__rx_data = VL_RAND_RESET_I(8);
    vlSelf->tt_um_vga_example__DOT__tx_send = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__packet_busy = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->tt_um_vga_example__DOT__tx_packet_bytes[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tt_um_vga_example__DOT__tx_data = VL_RAND_RESET_I(8);
    vlSelf->tt_um_vga_example__DOT__rx_packet_ready = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->tt_um_vga_example__DOT__rx_packet_bytes[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tt_um_vga_example__DOT__tx_small_rst = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__send_packet_reg = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__packet_cmd = VL_RAND_RESET_I(4);
    vlSelf->tt_um_vga_example__DOT__packet_1 = VL_RAND_RESET_I(8);
    vlSelf->tt_um_vga_example__DOT__packet_2 = VL_RAND_RESET_I(8);
    vlSelf->tt_um_vga_example__DOT__packet_3 = VL_RAND_RESET_I(8);
    vlSelf->tt_um_vga_example__DOT__packet_4 = VL_RAND_RESET_I(8);
    vlSelf->tt_um_vga_example__DOT__ack = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__ack_prev = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__ball_tx_ready = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__ball_rx_valid = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__ball_del_req = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__rx_ball_x = VL_RAND_RESET_I(10);
    vlSelf->tt_um_vga_example__DOT__rx_ball_y = VL_RAND_RESET_I(10);
    vlSelf->tt_um_vga_example__DOT__rx_ball_vel_x = VL_RAND_RESET_I(4);
    vlSelf->tt_um_vga_example__DOT__rx_ball_vel_y = VL_RAND_RESET_I(4);
    vlSelf->tt_um_vga_example__DOT__insync_rx_sync = VL_RAND_RESET_I(2);
    vlSelf->tt_um_vga_example__DOT__has_ball_rx_sync = VL_RAND_RESET_I(2);
    vlSelf->tt_um_vga_example__DOT__gone_timer = VL_RAND_RESET_I(4);
    vlSelf->tt_um_vga_example__DOT__dup_timer = VL_RAND_RESET_I(4);
    vlSelf->tt_um_vga_example__DOT__booted = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__game_launch = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__pause = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__has_ball = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__ball_tx_valid = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__ball_rx_ack = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__ball_del_act = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__tx_cd = VL_RAND_RESET_I(4);
    vlSelf->tt_um_vga_example__DOT__bounce_cd = VL_RAND_RESET_I(2);
    vlSelf->tt_um_vga_example__DOT__ball_x = VL_RAND_RESET_I(10);
    vlSelf->tt_um_vga_example__DOT__ball_y = VL_RAND_RESET_I(10);
    vlSelf->tt_um_vga_example__DOT__vel_x = VL_RAND_RESET_I(4);
    vlSelf->tt_um_vga_example__DOT__vel_y = VL_RAND_RESET_I(4);
    vlSelf->tt_um_vga_example__DOT__paddle_y = VL_RAND_RESET_I(10);
    vlSelf->tt_um_vga_example__DOT__ball_edge_l = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__ball_at_edge = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__vga_inst__DOT__hmaxxed = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__vga_inst__DOT__vmaxxed = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__uart_tx_inst__DOT__shift = VL_RAND_RESET_I(10);
    vlSelf->tt_um_vga_example__DOT__uart_rx_inst__DOT__baud_tick = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__uart_rx_inst__DOT__baud_counter = VL_RAND_RESET_I(14);
    vlSelf->tt_um_vga_example__DOT__uart_rx_inst__DOT__bit_idx = VL_RAND_RESET_I(4);
    vlSelf->tt_um_vga_example__DOT__uart_rx_inst__DOT__shift = VL_RAND_RESET_I(8);
    vlSelf->tt_um_vga_example__DOT__uart_rx_inst__DOT__receiving = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__uart_rx_inst__DOT__rx_sync = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__packet_sender_inst__DOT__start_ff = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__packet_receiver_inst__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->tt_um_vga_example__DOT__packet_receiver_inst__DOT__byte_cnt = VL_RAND_RESET_I(3);
    vlSelf->tt_um_vga_example__DOT__packet_receiver_inst__DOT__running_ecc = VL_RAND_RESET_I(8);
    vlSelf->tt_um_vga_example__DOT__packet_receiver_inst__DOT____Vlvbound_hedfcfc53__0 = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__tt_um_vga_example__DOT__insync_rx_sync = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__tt_um_vga_example__DOT__has_ball_rx_sync = VL_RAND_RESET_I(2);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
}
