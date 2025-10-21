// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vi2s_clock_gen_tb_simple__pch.h"
#include "Vi2s_clock_gen_tb_simple.h"
#include "Vi2s_clock_gen_tb_simple___024root.h"

// FUNCTIONS
Vi2s_clock_gen_tb_simple__Syms::~Vi2s_clock_gen_tb_simple__Syms()
{
}

Vi2s_clock_gen_tb_simple__Syms::Vi2s_clock_gen_tb_simple__Syms(VerilatedContext* contextp, const char* namep, Vi2s_clock_gen_tb_simple* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
