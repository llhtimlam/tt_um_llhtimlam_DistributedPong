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
    VL_IN8(clk_pix,0,0);
    VL_IN8(sim_rst,0,0);
    CData/*0:0*/ tt_um_vga_example__DOT__vsync;
    VL_IN8(ui_in,7,0);
    VL_OUT8(uo_out,7,0);
    VL_IN8(uio_in,7,0);
    VL_OUT8(uio_out,7,0);
    VL_OUT8(uio_oe,7,0);
    VL_OUT8(sdl_de,0,0);
    VL_OUT8(sdl_r,7,0);
    VL_OUT8(sdl_g,7,0);
    VL_OUT8(sdl_b,7,0);
    VL_IN8(ena,0,0);
    CData/*0:0*/ tt_um_vga_example__DOT__is_right_fpga;
    CData/*0:0*/ tt_um_vga_example__DOT__nego_done;
    CData/*0:0*/ tt_um_vga_example__DOT__ball_at_edge_reg;
    CData/*0:0*/ tt_um_vga_example__DOT__comm_sync_out;
    CData/*0:0*/ tt_um_vga_example__DOT__spawn_trigger;
    CData/*7:0*/ tt_um_vga_example__DOT__rx_y;
    CData/*7:0*/ tt_um_vga_example__DOT__rx_phys;
    CData/*3:0*/ tt_um_vga_example__DOT__vel_x;
    CData/*3:0*/ tt_um_vga_example__DOT__vel_y;
    CData/*0:0*/ tt_um_vga_example__DOT__has_ball;
    CData/*7:0*/ tt_um_vga_example__DOT__comm_bus_out;
    CData/*7:0*/ tt_um_vga_example__DOT__comm_bus_oe;
    CData/*7:0*/ tt_um_vga_example__DOT____Vcellinp__comms__ball_phys;
    CData/*0:0*/ tt_um_vga_example__DOT____Vcellinp__comms__reset;
    CData/*1:0*/ tt_um_vga_example__DOT__comms__DOT__tx_state;
    CData/*1:0*/ tt_um_vga_example__DOT__comms__DOT__rx_state;
    CData/*0:0*/ tt_um_vga_example__DOT__comms__DOT__in_sync_prev;
    CData/*3:0*/ tt_um_vga_example__DOT__comms__DOT__startup_delay;
    CData/*0:0*/ __Vdly__tt_um_vga_example__DOT__nego_done;
    CData/*1:0*/ __Vdly__tt_um_vga_example__DOT__comms__DOT__rx_state;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk_pix__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__sim_rst__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tt_um_vga_example__DOT__vsync__0;
    CData/*0:0*/ __VactContinue;
    VL_OUT16(sdl_sx,9,0);
    VL_OUT16(sdl_sy,9,0);
    SData/*9:0*/ tt_um_vga_example__DOT__ball_x;
    SData/*9:0*/ tt_um_vga_example__DOT__ball_y;
    SData/*8:0*/ tt_um_vga_example__DOT__paddle_y;
    SData/*9:0*/ tt_um_vga_example__DOT__vga_inst__DOT__h_cnt;
    SData/*9:0*/ tt_um_vga_example__DOT__vga_inst__DOT__v_cnt;
    SData/*15:0*/ tt_um_vga_example__DOT__comms__DOT__watchdog;
    SData/*15:0*/ __Vdly__tt_um_vga_example__DOT__comms__DOT__watchdog;
    IData/*16:0*/ tt_um_vga_example__DOT__nego_timer;
    IData/*16:0*/ __Vdly__tt_um_vga_example__DOT__nego_timer;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

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
