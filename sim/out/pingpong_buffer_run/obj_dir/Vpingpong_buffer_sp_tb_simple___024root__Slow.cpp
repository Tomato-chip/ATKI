// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpingpong_buffer_sp_tb_simple.h for the primary calling header

#include "Vpingpong_buffer_sp_tb_simple__pch.h"
#include "Vpingpong_buffer_sp_tb_simple__Syms.h"
#include "Vpingpong_buffer_sp_tb_simple___024root.h"

void Vpingpong_buffer_sp_tb_simple___024root___ctor_var_reset(Vpingpong_buffer_sp_tb_simple___024root* vlSelf);

Vpingpong_buffer_sp_tb_simple___024root::Vpingpong_buffer_sp_tb_simple___024root(Vpingpong_buffer_sp_tb_simple__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vpingpong_buffer_sp_tb_simple___024root___ctor_var_reset(this);
}

void Vpingpong_buffer_sp_tb_simple___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vpingpong_buffer_sp_tb_simple___024root::~Vpingpong_buffer_sp_tb_simple___024root() {
}
