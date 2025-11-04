// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vram_logic_tb.h for the primary calling header

#include "Vram_logic_tb__pch.h"
#include "Vram_logic_tb__Syms.h"
#include "Vram_logic_tb___024root.h"

void Vram_logic_tb___024root___ctor_var_reset(Vram_logic_tb___024root* vlSelf);

Vram_logic_tb___024root::Vram_logic_tb___024root(Vram_logic_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vram_logic_tb___024root___ctor_var_reset(this);
}

void Vram_logic_tb___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vram_logic_tb___024root::~Vram_logic_tb___024root() {
}
