// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vi2s_clock_gen_tb_debug__pch.h"

//============================================================
// Constructors

Vi2s_clock_gen_tb_debug::Vi2s_clock_gen_tb_debug(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vi2s_clock_gen_tb_debug__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vi2s_clock_gen_tb_debug::Vi2s_clock_gen_tb_debug(const char* _vcname__)
    : Vi2s_clock_gen_tb_debug(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vi2s_clock_gen_tb_debug::~Vi2s_clock_gen_tb_debug() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vi2s_clock_gen_tb_debug___024root___eval_debug_assertions(Vi2s_clock_gen_tb_debug___024root* vlSelf);
#endif  // VL_DEBUG
void Vi2s_clock_gen_tb_debug___024root___eval_static(Vi2s_clock_gen_tb_debug___024root* vlSelf);
void Vi2s_clock_gen_tb_debug___024root___eval_initial(Vi2s_clock_gen_tb_debug___024root* vlSelf);
void Vi2s_clock_gen_tb_debug___024root___eval_settle(Vi2s_clock_gen_tb_debug___024root* vlSelf);
void Vi2s_clock_gen_tb_debug___024root___eval(Vi2s_clock_gen_tb_debug___024root* vlSelf);

void Vi2s_clock_gen_tb_debug::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vi2s_clock_gen_tb_debug::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vi2s_clock_gen_tb_debug___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vi2s_clock_gen_tb_debug___024root___eval_static(&(vlSymsp->TOP));
        Vi2s_clock_gen_tb_debug___024root___eval_initial(&(vlSymsp->TOP));
        Vi2s_clock_gen_tb_debug___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vi2s_clock_gen_tb_debug___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vi2s_clock_gen_tb_debug::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vi2s_clock_gen_tb_debug::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vi2s_clock_gen_tb_debug::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vi2s_clock_gen_tb_debug___024root___eval_final(Vi2s_clock_gen_tb_debug___024root* vlSelf);

VL_ATTR_COLD void Vi2s_clock_gen_tb_debug::final() {
    Vi2s_clock_gen_tb_debug___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vi2s_clock_gen_tb_debug::hierName() const { return vlSymsp->name(); }
const char* Vi2s_clock_gen_tb_debug::modelName() const { return "Vi2s_clock_gen_tb_debug"; }
unsigned Vi2s_clock_gen_tb_debug::threads() const { return 1; }
void Vi2s_clock_gen_tb_debug::prepareClone() const { contextp()->prepareClone(); }
void Vi2s_clock_gen_tb_debug::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vi2s_clock_gen_tb_debug::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vi2s_clock_gen_tb_debug::trace()' called on model that was Verilated without --trace option");
}
