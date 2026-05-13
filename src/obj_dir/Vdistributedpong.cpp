// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdistributedpong__pch.h"

//============================================================
// Constructors

Vdistributedpong::Vdistributedpong(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdistributedpong__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , ui_in{vlSymsp->TOP.ui_in}
    , uo_out{vlSymsp->TOP.uo_out}
    , uio_in{vlSymsp->TOP.uio_in}
    , uio_out{vlSymsp->TOP.uio_out}
    , uio_oe{vlSymsp->TOP.uio_oe}
    , ena{vlSymsp->TOP.ena}
    , sdl_de{vlSymsp->TOP.sdl_de}
    , sdl_r{vlSymsp->TOP.sdl_r}
    , sdl_g{vlSymsp->TOP.sdl_g}
    , sdl_b{vlSymsp->TOP.sdl_b}
    , sdl_sx{vlSymsp->TOP.sdl_sx}
    , sdl_sy{vlSymsp->TOP.sdl_sy}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vdistributedpong::Vdistributedpong(const char* _vcname__)
    : Vdistributedpong(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdistributedpong::~Vdistributedpong() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vdistributedpong___024root___eval_debug_assertions(Vdistributedpong___024root* vlSelf);
#endif  // VL_DEBUG
void Vdistributedpong___024root___eval_static(Vdistributedpong___024root* vlSelf);
void Vdistributedpong___024root___eval_initial(Vdistributedpong___024root* vlSelf);
void Vdistributedpong___024root___eval_settle(Vdistributedpong___024root* vlSelf);
void Vdistributedpong___024root___eval(Vdistributedpong___024root* vlSelf);

void Vdistributedpong::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdistributedpong::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdistributedpong___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vdistributedpong___024root___eval_static(&(vlSymsp->TOP));
        Vdistributedpong___024root___eval_initial(&(vlSymsp->TOP));
        Vdistributedpong___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vdistributedpong___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vdistributedpong::eventsPending() { return false; }

uint64_t Vdistributedpong::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vdistributedpong::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vdistributedpong___024root___eval_final(Vdistributedpong___024root* vlSelf);

VL_ATTR_COLD void Vdistributedpong::final() {
    Vdistributedpong___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdistributedpong::hierName() const { return vlSymsp->name(); }
const char* Vdistributedpong::modelName() const { return "Vdistributedpong"; }
unsigned Vdistributedpong::threads() const { return 1; }
void Vdistributedpong::prepareClone() const { contextp()->prepareClone(); }
void Vdistributedpong::atClone() const {
    contextp()->threadPoolpOnClone();
}
