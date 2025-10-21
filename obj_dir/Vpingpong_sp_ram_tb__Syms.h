// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VPINGPONG_SP_RAM_TB__SYMS_H_
#define VERILATED_VPINGPONG_SP_RAM_TB__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vpingpong_sp_ram_tb.h"

// INCLUDE MODULE CLASSES
#include "Vpingpong_sp_ram_tb___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vpingpong_sp_ram_tb__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vpingpong_sp_ram_tb* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vpingpong_sp_ram_tb___024root  TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_pingpong_sp_ram_tb;

    // CONSTRUCTORS
    Vpingpong_sp_ram_tb__Syms(VerilatedContext* contextp, const char* namep, Vpingpong_sp_ram_tb* modelp);
    ~Vpingpong_sp_ram_tb__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
