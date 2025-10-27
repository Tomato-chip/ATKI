// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpga_template_top_tb.h for the primary calling header

#include "Vfpga_template_top_tb__pch.h"
#include "Vfpga_template_top_tb__Syms.h"
#include "Vfpga_template_top_tb___024root.h"

void Vfpga_template_top_tb___024root___ctor_var_reset(Vfpga_template_top_tb___024root* vlSelf);

Vfpga_template_top_tb___024root::Vfpga_template_top_tb___024root(Vfpga_template_top_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vfpga_template_top_tb___024root___ctor_var_reset(this);
}

void Vfpga_template_top_tb___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vfpga_template_top_tb___024root::~Vfpga_template_top_tb___024root() {
}
