// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vdistributedpong__pch.h"
#include "Vdistributedpong.h"
#include "Vdistributedpong___024root.h"

// FUNCTIONS
Vdistributedpong__Syms::~Vdistributedpong__Syms()
{
}

Vdistributedpong__Syms::Vdistributedpong__Syms(VerilatedContext* contextp, const char* namep, Vdistributedpong* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(95);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
