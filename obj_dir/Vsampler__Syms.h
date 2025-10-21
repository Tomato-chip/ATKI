// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSAMPLER__SYMS_H_
#define VERILATED_VSAMPLER__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vsampler.h"

// INCLUDE MODULE CLASSES
#include "Vsampler___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vsampler__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vsampler* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vsampler___024root             TOP;

    // CONSTRUCTORS
    Vsampler__Syms(VerilatedContext* contextp, const char* namep, Vsampler* modelp);
    ~Vsampler__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
