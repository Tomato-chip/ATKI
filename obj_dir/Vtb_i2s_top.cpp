// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_i2s_top__pch.h"

//============================================================
// Constructors

Vtb_i2s_top::Vtb_i2s_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_i2s_top__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , sck{vlSymsp->TOP.sck}
    , ws{vlSymsp->TOP.ws}
    , sd{vlSymsp->TOP.sd}
    , valid{vlSymsp->TOP.valid}
    , data24{vlSymsp->TOP.data24}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_i2s_top::Vtb_i2s_top(const char* _vcname__)
    : Vtb_i2s_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_i2s_top::~Vtb_i2s_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_i2s_top___024root___eval_debug_assertions(Vtb_i2s_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_i2s_top___024root___eval_static(Vtb_i2s_top___024root* vlSelf);
void Vtb_i2s_top___024root___eval_initial(Vtb_i2s_top___024root* vlSelf);
void Vtb_i2s_top___024root___eval_settle(Vtb_i2s_top___024root* vlSelf);
void Vtb_i2s_top___024root___eval(Vtb_i2s_top___024root* vlSelf);

void Vtb_i2s_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_i2s_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_i2s_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_i2s_top___024root___eval_static(&(vlSymsp->TOP));
        Vtb_i2s_top___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_i2s_top___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_i2s_top___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_i2s_top::eventsPending() { return false; }

uint64_t Vtb_i2s_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtb_i2s_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_i2s_top___024root___eval_final(Vtb_i2s_top___024root* vlSelf);

VL_ATTR_COLD void Vtb_i2s_top::final() {
    Vtb_i2s_top___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_i2s_top::hierName() const { return vlSymsp->name(); }
const char* Vtb_i2s_top::modelName() const { return "Vtb_i2s_top"; }
unsigned Vtb_i2s_top::threads() const { return 1; }
void Vtb_i2s_top::prepareClone() const { contextp()->prepareClone(); }
void Vtb_i2s_top::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vtb_i2s_top::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtb_i2s_top::trace()' called on model that was Verilated without --trace option");
}
