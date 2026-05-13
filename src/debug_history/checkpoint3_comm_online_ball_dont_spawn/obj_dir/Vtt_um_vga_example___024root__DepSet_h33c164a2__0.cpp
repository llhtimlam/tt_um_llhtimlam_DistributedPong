// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtt_um_vga_example.h for the primary calling header

#include "Vtt_um_vga_example__pch.h"
#include "Vtt_um_vga_example__Syms.h"
#include "Vtt_um_vga_example___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtt_um_vga_example___024root___dump_triggers__ico(Vtt_um_vga_example___024root* vlSelf);
#endif  // VL_DEBUG

void Vtt_um_vga_example___024root___eval_triggers__ico(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___eval_triggers__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.set(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtt_um_vga_example___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtt_um_vga_example___024root___dump_triggers__act(Vtt_um_vga_example___024root* vlSelf);
#endif  // VL_DEBUG

void Vtt_um_vga_example___024root___eval_triggers__act(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___eval_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.clk_pix) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk_pix__0))));
    vlSelfRef.__VactTriggered.set(1U, ((IData)(vlSelfRef.sim_rst) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sim_rst__0))));
    vlSelfRef.__VactTriggered.set(2U, ((IData)(vlSelfRef.tt_um_vga_example__DOT__vsync) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tt_um_vga_example__DOT__vsync__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk_pix__0 = vlSelfRef.clk_pix;
    vlSelfRef.__Vtrigprevexpr___TOP__sim_rst__0 = vlSelfRef.sim_rst;
    vlSelfRef.__Vtrigprevexpr___TOP__tt_um_vga_example__DOT__vsync__0 
        = vlSelfRef.tt_um_vga_example__DOT__vsync;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtt_um_vga_example___024root___dump_triggers__act(vlSelf);
    }
#endif
}
