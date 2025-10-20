// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vpingpong_sp_ram_tb__pch.h"
#include "Vpingpong_sp_ram_tb.h"
#include "Vpingpong_sp_ram_tb___024root.h"

// FUNCTIONS
Vpingpong_sp_ram_tb__Syms::~Vpingpong_sp_ram_tb__Syms()
{
}

Vpingpong_sp_ram_tb__Syms::Vpingpong_sp_ram_tb__Syms(VerilatedContext* contextp, const char* namep, Vpingpong_sp_ram_tb* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_pingpong_sp_ram_tb.configure(this, name(), "pingpong_sp_ram_tb", "pingpong_sp_ram_tb", -9, VerilatedScope::SCOPE_OTHER);
}
