// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtt_um_vga_example__pch.h"

//============================================================
// Constructors

Vtt_um_vga_example::Vtt_um_vga_example(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtt_um_vga_example__Syms(contextp(), _vcname__, this)}
    , clk_pix{vlSymsp->TOP.clk_pix}
    , sim_rst{vlSymsp->TOP.sim_rst}
    , ui_in{vlSymsp->TOP.ui_in}
    , uo_out{vlSymsp->TOP.uo_out}
    , uio_in{vlSymsp->TOP.uio_in}
    , uio_out{vlSymsp->TOP.uio_out}
    , uio_oe{vlSymsp->TOP.uio_oe}
    , sdl_de{vlSymsp->TOP.sdl_de}
    , sdl_r{vlSymsp->TOP.sdl_r}
    , sdl_g{vlSymsp->TOP.sdl_g}
    , sdl_b{vlSymsp->TOP.sdl_b}
    , ena{vlSymsp->TOP.ena}
    , sdl_sx{vlSymsp->TOP.sdl_sx}
    , sdl_sy{vlSymsp->TOP.sdl_sy}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtt_um_vga_example::Vtt_um_vga_example(const char* _vcname__)
    : Vtt_um_vga_example(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtt_um_vga_example::~Vtt_um_vga_example() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtt_um_vga_example___024root___eval_debug_assertions(Vtt_um_vga_example___024root* vlSelf);
#endif  // VL_DEBUG
void Vtt_um_vga_example___024root___eval_static(Vtt_um_vga_example___024root* vlSelf);
void Vtt_um_vga_example___024root___eval_initial(Vtt_um_vga_example___024root* vlSelf);
void Vtt_um_vga_example___024root___eval_settle(Vtt_um_vga_example___024root* vlSelf);
void Vtt_um_vga_example___024root___eval(Vtt_um_vga_example___024root* vlSelf);

void Vtt_um_vga_example::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtt_um_vga_example::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtt_um_vga_example___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtt_um_vga_example___024root___eval_static(&(vlSymsp->TOP));
        Vtt_um_vga_example___024root___eval_initial(&(vlSymsp->TOP));
        Vtt_um_vga_example___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtt_um_vga_example___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtt_um_vga_example::eventsPending() { return false; }

uint64_t Vtt_um_vga_example::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtt_um_vga_example::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtt_um_vga_example___024root___eval_final(Vtt_um_vga_example___024root* vlSelf);

VL_ATTR_COLD void Vtt_um_vga_example::final() {
    Vtt_um_vga_example___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtt_um_vga_example::hierName() const { return vlSymsp->name(); }
const char* Vtt_um_vga_example::modelName() const { return "Vtt_um_vga_example"; }
unsigned Vtt_um_vga_example::threads() const { return 1; }
void Vtt_um_vga_example::prepareClone() const { contextp()->prepareClone(); }
void Vtt_um_vga_example::atClone() const {
    contextp()->threadPoolpOnClone();
}
