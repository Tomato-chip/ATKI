// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VI2S_CLOCK_GEN_TB_VERILATOR__SYMS_H_
#define VERILATED_VI2S_CLOCK_GEN_TB_VERILATOR__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vi2s_clock_gen_tb_verilator.h"

// INCLUDE MODULE CLASSES
#include "Vi2s_clock_gen_tb_verilator___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vi2s_clock_gen_tb_verilator__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vi2s_clock_gen_tb_verilator* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vi2s_clock_gen_tb_verilator___024root TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_i2s_clock_gen_tb_verilator;
    VerilatedScope __Vscope_i2s_clock_gen_tb_verilator__unnamedblk2;
    VerilatedScope __Vscope_i2s_clock_gen_tb_verilator__unnamedblk3;
    VerilatedScope __Vscope_i2s_clock_gen_tb_verilator__unnamedblk4;

    // CONSTRUCTORS
    Vi2s_clock_gen_tb_verilator__Syms(VerilatedContext* contextp, const char* namep, Vi2s_clock_gen_tb_verilator* modelp);
    ~Vi2s_clock_gen_tb_verilator__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
