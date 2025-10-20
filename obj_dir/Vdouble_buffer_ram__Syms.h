// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VDOUBLE_BUFFER_RAM__SYMS_H_
#define VERILATED_VDOUBLE_BUFFER_RAM__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vdouble_buffer_ram.h"

// INCLUDE MODULE CLASSES
#include "Vdouble_buffer_ram___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vdouble_buffer_ram__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vdouble_buffer_ram* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vdouble_buffer_ram___024root   TOP;

    // CONSTRUCTORS
    Vdouble_buffer_ram__Syms(VerilatedContext* contextp, const char* namep, Vdouble_buffer_ram* modelp);
    ~Vdouble_buffer_ram__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
