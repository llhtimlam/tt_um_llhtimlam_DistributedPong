// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VDISTRIBUTEDPONG__SYMS_H_
#define VERILATED_VDISTRIBUTEDPONG__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vdistributedpong.h"

// INCLUDE MODULE CLASSES
#include "Vdistributedpong___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vdistributedpong__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vdistributedpong* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vdistributedpong___024root     TOP;

    // CONSTRUCTORS
    Vdistributedpong__Syms(VerilatedContext* contextp, const char* namep, Vdistributedpong* modelp);
    ~Vdistributedpong__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
