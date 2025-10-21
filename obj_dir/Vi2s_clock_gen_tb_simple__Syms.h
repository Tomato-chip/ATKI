// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VI2S_CLOCK_GEN_TB_SIMPLE__SYMS_H_
#define VERILATED_VI2S_CLOCK_GEN_TB_SIMPLE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vi2s_clock_gen_tb_simple.h"

// INCLUDE MODULE CLASSES
#include "Vi2s_clock_gen_tb_simple___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vi2s_clock_gen_tb_simple__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vi2s_clock_gen_tb_simple* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vi2s_clock_gen_tb_simple___024root TOP;

    // CONSTRUCTORS
    Vi2s_clock_gen_tb_simple__Syms(VerilatedContext* contextp, const char* namep, Vi2s_clock_gen_tb_simple* modelp);
    ~Vi2s_clock_gen_tb_simple__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
