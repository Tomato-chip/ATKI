// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vpingpong_sp_ram_tb__pch.h"

//============================================================
// Constructors

Vpingpong_sp_ram_tb::Vpingpong_sp_ram_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vpingpong_sp_ram_tb__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vpingpong_sp_ram_tb::Vpingpong_sp_ram_tb(const char* _vcname__)
    : Vpingpong_sp_ram_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vpingpong_sp_ram_tb::~Vpingpong_sp_ram_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vpingpong_sp_ram_tb___024root___eval_debug_assertions(Vpingpong_sp_ram_tb___024root* vlSelf);
#endif  // VL_DEBUG
void Vpingpong_sp_ram_tb___024root___eval_static(Vpingpong_sp_ram_tb___024root* vlSelf);
void Vpingpong_sp_ram_tb___024root___eval_initial(Vpingpong_sp_ram_tb___024root* vlSelf);
void Vpingpong_sp_ram_tb___024root___eval_settle(Vpingpong_sp_ram_tb___024root* vlSelf);
void Vpingpong_sp_ram_tb___024root___eval(Vpingpong_sp_ram_tb___024root* vlSelf);

void Vpingpong_sp_ram_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vpingpong_sp_ram_tb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vpingpong_sp_ram_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vpingpong_sp_ram_tb___024root___eval_static(&(vlSymsp->TOP));
        Vpingpong_sp_ram_tb___024root___eval_initial(&(vlSymsp->TOP));
        Vpingpong_sp_ram_tb___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vpingpong_sp_ram_tb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vpingpong_sp_ram_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vpingpong_sp_ram_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vpingpong_sp_ram_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vpingpong_sp_ram_tb___024root___eval_final(Vpingpong_sp_ram_tb___024root* vlSelf);

VL_ATTR_COLD void Vpingpong_sp_ram_tb::final() {
    Vpingpong_sp_ram_tb___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vpingpong_sp_ram_tb::hierName() const { return vlSymsp->name(); }
const char* Vpingpong_sp_ram_tb::modelName() const { return "Vpingpong_sp_ram_tb"; }
unsigned Vpingpong_sp_ram_tb::threads() const { return 1; }
void Vpingpong_sp_ram_tb::prepareClone() const { contextp()->prepareClone(); }
void Vpingpong_sp_ram_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vpingpong_sp_ram_tb::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vpingpong_sp_ram_tb::trace()' called on model that was Verilated without --trace option");
}
