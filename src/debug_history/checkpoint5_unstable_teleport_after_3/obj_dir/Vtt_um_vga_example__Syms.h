// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTT_UM_VGA_EXAMPLE__SYMS_H_
#define VERILATED_VTT_UM_VGA_EXAMPLE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtt_um_vga_example.h"

// INCLUDE MODULE CLASSES
#include "Vtt_um_vga_example___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtt_um_vga_example__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtt_um_vga_example* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtt_um_vga_example___024root   TOP;

    // CONSTRUCTORS
    Vtt_um_vga_example__Syms(VerilatedContext* contextp, const char* namep, Vtt_um_vga_example* modelp);
    ~Vtt_um_vga_example__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
