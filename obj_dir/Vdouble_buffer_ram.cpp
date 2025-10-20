// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdouble_buffer_ram__pch.h"

//============================================================
// Constructors

Vdouble_buffer_ram::Vdouble_buffer_ram(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdouble_buffer_ram__Syms(contextp(), _vcname__, this)}
    , clk_i{vlSymsp->TOP.clk_i}
    , rst_ni{vlSymsp->TOP.rst_ni}
    , in_valid_i{vlSymsp->TOP.in_valid_i}
    , in_ready_o{vlSymsp->TOP.in_ready_o}
    , rd_addr_i{vlSymsp->TOP.rd_addr_i}
    , rd_en_i{vlSymsp->TOP.rd_en_i}
    , rd_data_valid_o{vlSymsp->TOP.rd_data_valid_o}
    , active_buf_o{vlSymsp->TOP.active_buf_o}
    , buf_ready_pulse_o{vlSymsp->TOP.buf_ready_pulse_o}
    , buf_ready_id_o{vlSymsp->TOP.buf_ready_id_o}
    , in_data_i{vlSymsp->TOP.in_data_i}
    , rd_data_o{vlSymsp->TOP.rd_data_o}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vdouble_buffer_ram::Vdouble_buffer_ram(const char* _vcname__)
    : Vdouble_buffer_ram(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdouble_buffer_ram::~Vdouble_buffer_ram() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vdouble_buffer_ram___024root___eval_debug_assertions(Vdouble_buffer_ram___024root* vlSelf);
#endif  // VL_DEBUG
void Vdouble_buffer_ram___024root___eval_static(Vdouble_buffer_ram___024root* vlSelf);
void Vdouble_buffer_ram___024root___eval_initial(Vdouble_buffer_ram___024root* vlSelf);
void Vdouble_buffer_ram___024root___eval_settle(Vdouble_buffer_ram___024root* vlSelf);
void Vdouble_buffer_ram___024root___eval(Vdouble_buffer_ram___024root* vlSelf);

void Vdouble_buffer_ram::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdouble_buffer_ram::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdouble_buffer_ram___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vdouble_buffer_ram___024root___eval_static(&(vlSymsp->TOP));
        Vdouble_buffer_ram___024root___eval_initial(&(vlSymsp->TOP));
        Vdouble_buffer_ram___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vdouble_buffer_ram___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vdouble_buffer_ram::eventsPending() { return false; }

uint64_t Vdouble_buffer_ram::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vdouble_buffer_ram::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vdouble_buffer_ram___024root___eval_final(Vdouble_buffer_ram___024root* vlSelf);

VL_ATTR_COLD void Vdouble_buffer_ram::final() {
    Vdouble_buffer_ram___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdouble_buffer_ram::hierName() const { return vlSymsp->name(); }
const char* Vdouble_buffer_ram::modelName() const { return "Vdouble_buffer_ram"; }
unsigned Vdouble_buffer_ram::threads() const { return 1; }
void Vdouble_buffer_ram::prepareClone() const { contextp()->prepareClone(); }
void Vdouble_buffer_ram::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vdouble_buffer_ram::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vdouble_buffer_ram::trace()' called on model that was Verilated without --trace option");
}
