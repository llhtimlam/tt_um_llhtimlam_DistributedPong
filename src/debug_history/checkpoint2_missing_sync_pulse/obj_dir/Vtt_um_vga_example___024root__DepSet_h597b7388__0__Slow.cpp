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

VL_ATTR_COLD void Vtt_um_vga_example___024root___eval_initial(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___eval_initial\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk_pix__0 = vlSelfRef.clk_pix;
    vlSelfRef.__Vtrigprevexpr___TOP__sim_rst__0 = vlSelfRef.sim_rst;
    vlSelfRef.__Vtrigprevexpr___TOP__tt_um_vga_example__DOT__vsync__0 
        = vlSelfRef.tt_um_vga_example__DOT__vsync;
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
            VL_FATAL_MT("tt_um_vga_example.v", 3, "", "Settle region did not converge.");
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
    CData/*0:0*/ tt_um_vga_example__DOT__pixel;
    tt_um_vga_example__DOT__pixel = 0;
    // Body
    vlSelfRef.sdl_sx = vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__h_cnt;
    vlSelfRef.sdl_sy = vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__v_cnt;
    vlSelfRef.nego_done = vlSelfRef.tt_um_vga_example__DOT__nego_done_reg;
    vlSelfRef.is_right_fpga = vlSelfRef.tt_um_vga_example__DOT__is_right_fpga_reg;
    vlSelfRef.uio_out = vlSelfRef.tt_um_vga_example__DOT__comm_bus_out;
    vlSelfRef.uio_oe = vlSelfRef.tt_um_vga_example__DOT__comm_bus_oe;
    vlSelfRef.tt_um_vga_example__DOT____Vcellinp__comms__reset 
        = (1U & ((~ (IData)(vlSelfRef.tt_um_vga_example__DOT__nego_done_reg)) 
                 | (IData)(vlSelfRef.sim_rst)));
    vlSelfRef.tt_um_vga_example__DOT____Vcellinp__comms__ball_phys 
        = (((IData)(vlSelfRef.tt_um_vga_example__DOT__vel_x) 
            << 4U) | (IData)(vlSelfRef.tt_um_vga_example__DOT__vel_y));
    vlSelfRef.tt_um_vga_example__DOT__vsync = (1U & 
                                               (~ (
                                                   (0x1eaU 
                                                    <= (IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__v_cnt)) 
                                                   & (0x1ecU 
                                                      > (IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__v_cnt)))));
    vlSelfRef.sdl_de = ((0x280U > (IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__h_cnt)) 
                        & (0x1e0U > (IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__v_cnt)));
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
                                                       (0x3ffU 
                                                        & ((IData)(0x3cU) 
                                                           + (IData)(vlSelfRef.tt_um_vga_example__DOT__paddle_y))))))))));
    vlSelfRef.uo_out = (((0x80U & ((~ ((0x290U <= (IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__h_cnt)) 
                                       & (0x2f0U > (IData)(vlSelfRef.tt_um_vga_example__DOT__vga_inst__DOT__h_cnt)))) 
                                   << 7U)) | (((IData)(tt_um_vga_example__DOT__pixel) 
                                               << 6U) 
                                              | (0x30U 
                                                 & ((- (IData)((IData)(tt_um_vga_example__DOT__pixel))) 
                                                    << 4U)))) 
                        | (((((IData)(vlSelfRef.tt_um_vga_example__DOT__comm_sync_out) 
                              & (IData)(vlSelfRef.tt_um_vga_example__DOT__nego_done_reg)) 
                             << 3U) | ((IData)(vlSelfRef.tt_um_vga_example__DOT__vsync) 
                                       << 2U)) | (((IData)(vlSelfRef.tt_um_vga_example__DOT__ball_at_edge_reg) 
                                                   << 1U) 
                                                  | (IData)(vlSelfRef.tt_um_vga_example__DOT__has_ball))));
    vlSelfRef.sdl_r = ((IData)(tt_um_vga_example__DOT__pixel)
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
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk_pix)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge sim_rst)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge tt_um_vga_example.vsync)\n");
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
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk_pix)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge sim_rst)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge tt_um_vga_example.vsync)\n");
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
    vlSelf->sdl_sx = VL_RAND_RESET_I(10);
    vlSelf->sdl_sy = VL_RAND_RESET_I(10);
    vlSelf->sdl_de = VL_RAND_RESET_I(1);
    vlSelf->sdl_r = VL_RAND_RESET_I(8);
    vlSelf->sdl_g = VL_RAND_RESET_I(8);
    vlSelf->sdl_b = VL_RAND_RESET_I(8);
    vlSelf->ena = VL_RAND_RESET_I(1);
    vlSelf->clk_pix = VL_RAND_RESET_I(1);
    vlSelf->sim_rst = VL_RAND_RESET_I(1);
    vlSelf->nego_done = VL_RAND_RESET_I(1);
    vlSelf->is_right_fpga = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__vsync = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__is_right_fpga_reg = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__nego_done_reg = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__nego_timer = VL_RAND_RESET_I(17);
    vlSelf->tt_um_vga_example__DOT__ball_at_edge_reg = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__ball_x = VL_RAND_RESET_I(10);
    vlSelf->tt_um_vga_example__DOT__ball_y = VL_RAND_RESET_I(10);
    vlSelf->tt_um_vga_example__DOT__vel_x = VL_RAND_RESET_I(4);
    vlSelf->tt_um_vga_example__DOT__vel_y = VL_RAND_RESET_I(4);
    vlSelf->tt_um_vga_example__DOT__paddle_y = VL_RAND_RESET_I(9);
    vlSelf->tt_um_vga_example__DOT__has_ball = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__comm_sync_out = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__link_alive = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__spawn_trigger = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__rx_y = VL_RAND_RESET_I(8);
    vlSelf->tt_um_vga_example__DOT__rx_phys = VL_RAND_RESET_I(8);
    vlSelf->tt_um_vga_example__DOT__comm_bus_out = VL_RAND_RESET_I(8);
    vlSelf->tt_um_vga_example__DOT__comm_bus_oe = VL_RAND_RESET_I(8);
    vlSelf->tt_um_vga_example__DOT____Vcellinp__comms__ball_phys = VL_RAND_RESET_I(8);
    vlSelf->tt_um_vga_example__DOT____Vcellinp__comms__reset = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__vga_inst__DOT__h_cnt = VL_RAND_RESET_I(10);
    vlSelf->tt_um_vga_example__DOT__vga_inst__DOT__v_cnt = VL_RAND_RESET_I(10);
    vlSelf->tt_um_vga_example__DOT__comms__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->tt_um_vga_example__DOT__comms__DOT__watchdog = VL_RAND_RESET_I(16);
    vlSelf->tt_um_vga_example__DOT__comms__DOT__in_sync_prev = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__comms__DOT__edge_detected = VL_RAND_RESET_I(1);
    vlSelf->tt_um_vga_example__DOT__comms__DOT__last_ball_at_edge = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tt_um_vga_example__DOT__nego_done_reg = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__tt_um_vga_example__DOT__nego_timer = VL_RAND_RESET_I(17);
    vlSelf->__Vdly__tt_um_vga_example__DOT__comms__DOT__watchdog = VL_RAND_RESET_I(16);
    vlSelf->__Vtrigprevexpr___TOP__clk_pix__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__sim_rst__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tt_um_vga_example__DOT__vsync__0 = VL_RAND_RESET_I(1);
}
