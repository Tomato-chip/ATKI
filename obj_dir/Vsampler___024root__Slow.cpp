// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsampler.h for the primary calling header

#include "Vsampler__pch.h"
#include "Vsampler__Syms.h"
#include "Vsampler___024root.h"

void Vsampler___024root___ctor_var_reset(Vsampler___024root* vlSelf);

Vsampler___024root::Vsampler___024root(Vsampler__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsampler___024root___ctor_var_reset(this);
}

void Vsampler___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vsampler___024root::~Vsampler___024root() {
}
