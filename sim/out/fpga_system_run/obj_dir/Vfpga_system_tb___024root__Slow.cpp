// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpga_system_tb.h for the primary calling header

#include "Vfpga_system_tb__pch.h"
#include "Vfpga_system_tb__Syms.h"
#include "Vfpga_system_tb___024root.h"

void Vfpga_system_tb___024root___ctor_var_reset(Vfpga_system_tb___024root* vlSelf);

Vfpga_system_tb___024root::Vfpga_system_tb___024root(Vfpga_system_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vfpga_system_tb___024root___ctor_var_reset(this);
}

void Vfpga_system_tb___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vfpga_system_tb___024root::~Vfpga_system_tb___024root() {
}
