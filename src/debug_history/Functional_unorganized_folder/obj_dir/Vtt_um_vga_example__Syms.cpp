// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtt_um_vga_example__pch.h"
#include "Vtt_um_vga_example.h"
#include "Vtt_um_vga_example___024root.h"

// FUNCTIONS
Vtt_um_vga_example__Syms::~Vtt_um_vga_example__Syms()
{
}

Vtt_um_vga_example__Syms::Vtt_um_vga_example__Syms(VerilatedContext* contextp, const char* namep, Vtt_um_vga_example* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(107);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
