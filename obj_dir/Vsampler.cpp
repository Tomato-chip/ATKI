// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsampler__pch.h"

//============================================================
// Constructors

Vsampler::Vsampler(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsampler__Syms(contextp(), _vcname__, this)}
    , clk_i{vlSymsp->TOP.clk_i}
    , rst_ni{vlSymsp->TOP.rst_ni}
    , mic_valid_i{vlSymsp->TOP.mic_valid_i}
    , buf_ready_pulse_o{vlSymsp->TOP.buf_ready_pulse_o}
    , buf_ready_ch_o{vlSymsp->TOP.buf_ready_ch_o}
    , active_buf_o{vlSymsp->TOP.active_buf_o}
    , mic_data_i{vlSymsp->TOP.mic_data_i}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vsampler::Vsampler(const char* _vcname__)
    : Vsampler(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsampler::~Vsampler() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsampler___024root___eval_debug_assertions(Vsampler___024root* vlSelf);
#endif  // VL_DEBUG
void Vsampler___024root___eval_static(Vsampler___024root* vlSelf);
void Vsampler___024root___eval_initial(Vsampler___024root* vlSelf);
void Vsampler___024root___eval_settle(Vsampler___024root* vlSelf);
void Vsampler___024root___eval(Vsampler___024root* vlSelf);

void Vsampler::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsampler::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsampler___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vsampler___024root___eval_static(&(vlSymsp->TOP));
        Vsampler___024root___eval_initial(&(vlSymsp->TOP));
        Vsampler___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vsampler___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vsampler::eventsPending() { return false; }

uint64_t Vsampler::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vsampler::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vsampler___024root___eval_final(Vsampler___024root* vlSelf);

VL_ATTR_COLD void Vsampler::final() {
    Vsampler___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsampler::hierName() const { return vlSymsp->name(); }
const char* Vsampler::modelName() const { return "Vsampler"; }
unsigned Vsampler::threads() const { return 1; }
void Vsampler::prepareClone() const { contextp()->prepareClone(); }
void Vsampler::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vsampler::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vsampler::trace()' called on model that was Verilated without --trace option");
}
