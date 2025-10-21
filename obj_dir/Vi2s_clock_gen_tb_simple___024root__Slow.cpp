// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vi2s_clock_gen_tb_simple.h for the primary calling header

#include "Vi2s_clock_gen_tb_simple__pch.h"
#include "Vi2s_clock_gen_tb_simple__Syms.h"
#include "Vi2s_clock_gen_tb_simple___024root.h"

void Vi2s_clock_gen_tb_simple___024root___ctor_var_reset(Vi2s_clock_gen_tb_simple___024root* vlSelf);

Vi2s_clock_gen_tb_simple___024root::Vi2s_clock_gen_tb_simple___024root(Vi2s_clock_gen_tb_simple__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vi2s_clock_gen_tb_simple___024root___ctor_var_reset(this);
}

void Vi2s_clock_gen_tb_simple___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vi2s_clock_gen_tb_simple___024root::~Vi2s_clock_gen_tb_simple___024root() {
}
