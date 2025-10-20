// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vdouble_buffer_ram__pch.h"
#include "Vdouble_buffer_ram.h"
#include "Vdouble_buffer_ram___024root.h"

// FUNCTIONS
Vdouble_buffer_ram__Syms::~Vdouble_buffer_ram__Syms()
{
}

Vdouble_buffer_ram__Syms::Vdouble_buffer_ram__Syms(VerilatedContext* contextp, const char* namep, Vdouble_buffer_ram* modelp)
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
