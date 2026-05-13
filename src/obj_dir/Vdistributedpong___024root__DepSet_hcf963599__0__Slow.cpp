// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdistributedpong.h for the primary calling header

#include "Vdistributedpong__pch.h"
#include "Vdistributedpong___024root.h"

VL_ATTR_COLD void Vdistributedpong___024root___eval_static(Vdistributedpong___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdistributedpong__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdistributedpong___024root___eval_static\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vdistributedpong___024root___eval_initial__TOP(Vdistributedpong___024root* vlSelf);

VL_ATTR_COLD void Vdistributedpong___024root___eval_initial(Vdistributedpong___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdistributedpong__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdistributedpong___024root___eval_initial\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vdistributedpong___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

VL_ATTR_COLD void Vdistributedpong___024root___eval_initial__TOP(Vdistributedpong___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdistributedpong__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdistributedpong___024root___eval_initial__TOP\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.uio_oe = 0x5dU;
}

VL_ATTR_COLD void Vdistributedpong___024root___eval_final(Vdistributedpong___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdistributedpong__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdistributedpong___024root___eval_final\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdistributedpong___024root___dump_triggers__stl(Vdistributedpong___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vdistributedpong___024root___eval_phase__stl(Vdistributedpong___024root* vlSelf);

VL_ATTR_COLD void Vdistributedpong___024root___eval_settle(Vdistributedpong___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdistributedpong__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdistributedpong___024root___eval_settle\n"); );
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
            Vdistributedpong___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("distributedpong.v", 13, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vdistributedpong___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdistributedpong___024root___dump_triggers__stl(Vdistributedpong___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdistributedpong__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdistributedpong___024root___dump_triggers__stl\n"); );
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

VL_ATTR_COLD void Vdistributedpong___024root___stl_sequent__TOP__0(Vdistributedpong___024root* vlSelf);

VL_ATTR_COLD void Vdistributedpong___024root___eval_stl(Vdistributedpong___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdistributedpong__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdistributedpong___024root___eval_stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vdistributedpong___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vdistributedpong___024root___stl_sequent__TOP__0(Vdistributedpong___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdistributedpong__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdistributedpong___024root___stl_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ tt_um_llhtimlam_DistributedPong__DOT__vga_r0;
    tt_um_llhtimlam_DistributedPong__DOT__vga_r0 = 0;
    // Body
    vlSelfRef.sdl_sx = vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__hpos;
    vlSelfRef.sdl_sy = vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__vpos;
    vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__ball_at_edge 
        = ((0xaU >= (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__ball_x)) 
           | ((0x276U <= (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__ball_x)) 
              & (0x28aU >= (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__ball_x))));
    vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__ball_edge_l 
        = (0xaU >= (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__ball_x));
    vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__uart_tx_inst__DOT__baud_tick 
        = (0xa2bU == (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__uart_tx_inst__DOT__baud_counter));
    vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__uart_rx_inst__DOT__baud_tick 
        = (0U == (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__uart_rx_inst__DOT__baud_counter));
    vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__tx_header 
        = (((IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__packet_cmd) 
            << 4U) | (1U & ((IData)(vlSelfRef.ui_in) 
                            >> 7U)));
    vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__game_tick 
        = ((0U == (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__hpos)) 
           & (0U == (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__vpos)));
    vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__vga_inst__DOT__hmaxxed 
        = (1U & ((~ (IData)(vlSelfRef.rst_n)) | (0x31fU 
                                                 == (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__hpos))));
    vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__vga_inst__DOT__vmaxxed 
        = (1U & ((~ (IData)(vlSelfRef.rst_n)) | (0x20cU 
                                                 == (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__vpos))));
    vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__send_ack_packet 
        = ((~ ((IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__ack) 
               | (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__send_packet_reg))) 
           & (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__ack_prev));
    vlSelfRef.uio_out = (0x40U | (((IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__has_ball) 
                                   << 4U) | (1U & (
                                                   (~ (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__tx_busy)) 
                                                   | (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__uart_tx_inst__DOT__shift)))));
    vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__collision_paddle_l 
        = ((~ ((IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__vel_x) 
               >> 3U)) & ((0x131U <= (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__ball_x)) 
                          & (0x13bU >= (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__ball_x))));
    vlSelfRef.sdl_de = ((0x280U > (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__hpos)) 
                        & (0x1e0U > (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__vpos)));
    vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__any_collision 
        = (((IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__collision_paddle_l) 
            | (((IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__vel_x) 
                >> 3U) & ((0x14fU >= (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__ball_x)) 
                          & (0x145U <= (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__ball_x))))) 
           & (((0x3ffU & ((IData)(4U) + (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__ball_y))) 
               >= (0x3ffU & ((IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__paddle_y) 
                             - (IData)(0x1eU)))) & 
              ((0x3ffU & ((IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__ball_y) 
                          - (IData)(4U))) <= (0x3ffU 
                                              & ((IData)(0x1eU) 
                                                 + (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__paddle_y))))));
    tt_um_llhtimlam_DistributedPong__DOT__vga_r0 = 
        ((IData)(vlSelfRef.sdl_de) & (((IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__has_ball) 
                                       & (((0x3ffU 
                                            & ((IData)(4U) 
                                               + (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__hpos))) 
                                           >= (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__ball_x)) 
                                          & (((IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__hpos) 
                                              <= (0x3ffU 
                                                  & ((IData)(4U) 
                                                     + (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__ball_x)))) 
                                             & (((0x3ffU 
                                                  & ((IData)(4U) 
                                                     + (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__vpos))) 
                                                 >= (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__ball_y)) 
                                                & ((IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__vpos) 
                                                   < 
                                                   (0x3ffU 
                                                    & ((IData)(4U) 
                                                       + (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__ball_y)))))))) 
                                      | ((0x13bU <= (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__hpos)) 
                                         & ((0x145U 
                                             > (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__hpos)) 
                                            & (((IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__vpos) 
                                                >= 
                                                (0x3ffU 
                                                 & ((IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__paddle_y) 
                                                    - (IData)(0x1eU)))) 
                                               & ((IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__vpos) 
                                                  < 
                                                  (0x3ffU 
                                                   & ((IData)(0x1eU) 
                                                      + (IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__paddle_y)))))))));
    vlSelfRef.uo_out = ((((IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__vga_hsync) 
                          << 7U) | (((IData)(tt_um_llhtimlam_DistributedPong__DOT__vga_r0) 
                                     << 6U) | (0x30U 
                                               & ((- (IData)((IData)(tt_um_llhtimlam_DistributedPong__DOT__vga_r0))) 
                                                  << 4U)))) 
                        | (((IData)(vlSelfRef.tt_um_llhtimlam_DistributedPong__DOT__vga_vsync) 
                            << 3U) | (7U & (- (IData)((IData)(tt_um_llhtimlam_DistributedPong__DOT__vga_r0))))));
    vlSelfRef.sdl_r = ((IData)(tt_um_llhtimlam_DistributedPong__DOT__vga_r0)
                        ? 0xffU : 0U);
    vlSelfRef.sdl_g = vlSelfRef.sdl_r;
    vlSelfRef.sdl_b = vlSelfRef.sdl_r;
}

VL_ATTR_COLD void Vdistributedpong___024root___eval_triggers__stl(Vdistributedpong___024root* vlSelf);

VL_ATTR_COLD bool Vdistributedpong___024root___eval_phase__stl(Vdistributedpong___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdistributedpong__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdistributedpong___024root___eval_phase__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vdistributedpong___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vdistributedpong___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdistributedpong___024root___dump_triggers__ico(Vdistributedpong___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdistributedpong__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdistributedpong___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void Vdistributedpong___024root___dump_triggers__act(Vdistributedpong___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdistributedpong__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdistributedpong___024root___dump_triggers__act\n"); );
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
VL_ATTR_COLD void Vdistributedpong___024root___dump_triggers__nba(Vdistributedpong___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdistributedpong__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdistributedpong___024root___dump_triggers__nba\n"); );
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

VL_ATTR_COLD void Vdistributedpong___024root___ctor_var_reset(Vdistributedpong___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdistributedpong__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdistributedpong___024root___ctor_var_reset\n"); );
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
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__vga_hsync = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__vga_vsync = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__hpos = VL_RAND_RESET_I(10);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__vpos = VL_RAND_RESET_I(10);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__tx_busy = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__rx_ready = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__rx_data = VL_RAND_RESET_I(8);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__tx_send = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__packet_busy = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__tx_data = VL_RAND_RESET_I(8);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__rx_packet_ready = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__rx_packet_bytes = VL_RAND_RESET_Q(40);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__tx_small_rst = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__send_packet_reg = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__packet_cmd = VL_RAND_RESET_I(4);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__packet_1 = VL_RAND_RESET_I(8);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__packet_2 = VL_RAND_RESET_I(8);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__packet_3 = VL_RAND_RESET_I(8);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__packet_4 = VL_RAND_RESET_I(8);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__tx_header = VL_RAND_RESET_I(8);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__ack = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__ack_prev = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__ball_tx_ready = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__ball_rx_valid = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__ball_del_req = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__rx_ball_x = VL_RAND_RESET_I(10);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__rx_ball_y = VL_RAND_RESET_I(10);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__rx_ball_vel_x = VL_RAND_RESET_I(4);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__rx_ball_vel_y = VL_RAND_RESET_I(4);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__send_ack_packet = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__insync_rx_sync = VL_RAND_RESET_I(2);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__has_ball_rx_sync = VL_RAND_RESET_I(2);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__gone_timer = VL_RAND_RESET_I(4);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__dup_timer = VL_RAND_RESET_I(4);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__game_tick = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__booted = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__game_launch = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__pause = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__has_ball = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__ball_tx_valid = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__ball_rx_ack = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__ball_del_act = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__tx_cd = VL_RAND_RESET_I(4);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__bounce_cd = VL_RAND_RESET_I(2);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__ball_x = VL_RAND_RESET_I(10);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__ball_y = VL_RAND_RESET_I(10);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__vel_x = VL_RAND_RESET_I(4);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__vel_y = VL_RAND_RESET_I(4);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__paddle_y = VL_RAND_RESET_I(10);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__collision_paddle_l = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__any_collision = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__ball_edge_l = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__ball_at_edge = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__vga_inst__DOT__hmaxxed = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__vga_inst__DOT__vmaxxed = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__uart_tx_inst__DOT__baud_tick = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__uart_tx_inst__DOT__baud_counter = VL_RAND_RESET_I(14);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__uart_tx_inst__DOT__bit_idx = VL_RAND_RESET_I(4);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__uart_tx_inst__DOT__shift = VL_RAND_RESET_I(10);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__uart_rx_inst__DOT__baud_tick = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__uart_rx_inst__DOT__baud_counter = VL_RAND_RESET_I(14);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__uart_rx_inst__DOT__bit_idx = VL_RAND_RESET_I(4);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__uart_rx_inst__DOT__shift = VL_RAND_RESET_I(8);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__uart_rx_inst__DOT__receiving = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__uart_rx_inst__DOT__rx_sync = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__packet_sender_inst__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__packet_sender_inst__DOT__byte_cnt = VL_RAND_RESET_I(3);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__packet_sender_inst__DOT__start_ff = VL_RAND_RESET_I(1);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__packet_receiver_inst__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__packet_receiver_inst__DOT__byte_cnt = VL_RAND_RESET_I(3);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__packet_receiver_inst__DOT__running_ecc = VL_RAND_RESET_I(8);
    vlSelf->tt_um_llhtimlam_DistributedPong__DOT__packet_receiver_inst__DOT____Vlvbound_hb2c8e3b0__0 = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__tt_um_llhtimlam_DistributedPong__DOT__insync_rx_sync = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__tt_um_llhtimlam_DistributedPong__DOT__has_ball_rx_sync = VL_RAND_RESET_I(2);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
}
