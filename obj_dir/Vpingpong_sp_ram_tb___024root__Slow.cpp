// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpingpong_sp_ram_tb.h for the primary calling header

#include "Vpingpong_sp_ram_tb__pch.h"
#include "Vpingpong_sp_ram_tb__Syms.h"
#include "Vpingpong_sp_ram_tb___024root.h"

void Vpingpong_sp_ram_tb___024root___ctor_var_reset(Vpingpong_sp_ram_tb___024root* vlSelf);

Vpingpong_sp_ram_tb___024root::Vpingpong_sp_ram_tb___024root(Vpingpong_sp_ram_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vpingpong_sp_ram_tb___024root___ctor_var_reset(this);
}

void Vpingpong_sp_ram_tb___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vpingpong_sp_ram_tb___024root::~Vpingpong_sp_ram_tb___024root() {
}
