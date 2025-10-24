// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vi2s_clock_gen_tb_verilator__pch.h"
#include "Vi2s_clock_gen_tb_verilator.h"
#include "Vi2s_clock_gen_tb_verilator___024root.h"

// FUNCTIONS
Vi2s_clock_gen_tb_verilator__Syms::~Vi2s_clock_gen_tb_verilator__Syms()
{
#ifdef VM_TRACE
    if (__Vm_dumping) _traceDumpClose();
#endif  // VM_TRACE
}

void Vi2s_clock_gen_tb_verilator__Syms::_traceDump() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    __Vm_dumperp->dump(VL_TIME_Q());
}

void Vi2s_clock_gen_tb_verilator__Syms::_traceDumpOpen() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    if (VL_UNLIKELY(!__Vm_dumperp)) {
        __Vm_dumperp = new VerilatedVcdC();
        __Vm_modelp->trace(__Vm_dumperp, 0, 0);
        std::string dumpfile = _vm_contextp__->dumpfileCheck();
        __Vm_dumperp->open(dumpfile.c_str());
        __Vm_dumping = true;
    }
}

void Vi2s_clock_gen_tb_verilator__Syms::_traceDumpClose() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    __Vm_dumping = false;
    VL_DO_CLEAR(delete __Vm_dumperp, __Vm_dumperp = nullptr);
}

Vi2s_clock_gen_tb_verilator__Syms::Vi2s_clock_gen_tb_verilator__Syms(VerilatedContext* contextp, const char* namep, Vi2s_clock_gen_tb_verilator* modelp)
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
    __Vscope_i2s_clock_gen_tb_verilator.configure(this, name(), "i2s_clock_gen_tb_verilator", "i2s_clock_gen_tb_verilator", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_i2s_clock_gen_tb_verilator__unnamedblk2.configure(this, name(), "i2s_clock_gen_tb_verilator.unnamedblk2", "unnamedblk2", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_i2s_clock_gen_tb_verilator__unnamedblk3.configure(this, name(), "i2s_clock_gen_tb_verilator.unnamedblk3", "unnamedblk3", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_i2s_clock_gen_tb_verilator__unnamedblk4.configure(this, name(), "i2s_clock_gen_tb_verilator.unnamedblk4", "unnamedblk4", -9, VerilatedScope::SCOPE_OTHER);
}
