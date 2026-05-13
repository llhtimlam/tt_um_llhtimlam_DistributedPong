// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtt_um_vga_example.h for the primary calling header

#include "Vtt_um_vga_example__pch.h"
#include "Vtt_um_vga_example__Syms.h"
#include "Vtt_um_vga_example___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtt_um_vga_example___024root___dump_triggers__stl(Vtt_um_vga_example___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtt_um_vga_example___024root___eval_triggers__stl(Vtt_um_vga_example___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtt_um_vga_example__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_vga_example___024root___eval_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtt_um_vga_example___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
