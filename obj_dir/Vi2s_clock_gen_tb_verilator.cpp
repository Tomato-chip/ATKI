// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vi2s_clock_gen_tb_verilator__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vi2s_clock_gen_tb_verilator::Vi2s_clock_gen_tb_verilator(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vi2s_clock_gen_tb_verilator__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vi2s_clock_gen_tb_verilator::Vi2s_clock_gen_tb_verilator(const char* _vcname__)
    : Vi2s_clock_gen_tb_verilator(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vi2s_clock_gen_tb_verilator::~Vi2s_clock_gen_tb_verilator() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vi2s_clock_gen_tb_verilator___024root___eval_debug_assertions(Vi2s_clock_gen_tb_verilator___024root* vlSelf);
#endif  // VL_DEBUG
void Vi2s_clock_gen_tb_verilator___024root___eval_static(Vi2s_clock_gen_tb_verilator___024root* vlSelf);
void Vi2s_clock_gen_tb_verilator___024root___eval_initial(Vi2s_clock_gen_tb_verilator___024root* vlSelf);
void Vi2s_clock_gen_tb_verilator___024root___eval_settle(Vi2s_clock_gen_tb_verilator___024root* vlSelf);
void Vi2s_clock_gen_tb_verilator___024root___eval(Vi2s_clock_gen_tb_verilator___024root* vlSelf);

void Vi2s_clock_gen_tb_verilator::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vi2s_clock_gen_tb_verilator::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vi2s_clock_gen_tb_verilator___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vi2s_clock_gen_tb_verilator___024root___eval_static(&(vlSymsp->TOP));
        Vi2s_clock_gen_tb_verilator___024root___eval_initial(&(vlSymsp->TOP));
        Vi2s_clock_gen_tb_verilator___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vi2s_clock_gen_tb_verilator___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vi2s_clock_gen_tb_verilator::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vi2s_clock_gen_tb_verilator::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vi2s_clock_gen_tb_verilator::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vi2s_clock_gen_tb_verilator::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vi2s_clock_gen_tb_verilator::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vi2s_clock_gen_tb_verilator___024root___eval_final(Vi2s_clock_gen_tb_verilator___024root* vlSelf);

VL_ATTR_COLD void Vi2s_clock_gen_tb_verilator::final() {
    Vi2s_clock_gen_tb_verilator___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vi2s_clock_gen_tb_verilator::hierName() const { return vlSymsp->name(); }
const char* Vi2s_clock_gen_tb_verilator::modelName() const { return "Vi2s_clock_gen_tb_verilator"; }
unsigned Vi2s_clock_gen_tb_verilator::threads() const { return 1; }
void Vi2s_clock_gen_tb_verilator::prepareClone() const { contextp()->prepareClone(); }
void Vi2s_clock_gen_tb_verilator::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vi2s_clock_gen_tb_verilator::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vi2s_clock_gen_tb_verilator___024root__trace_decl_types(VerilatedVcd* tracep);

void Vi2s_clock_gen_tb_verilator___024root__trace_init_top(Vi2s_clock_gen_tb_verilator___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vi2s_clock_gen_tb_verilator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vi2s_clock_gen_tb_verilator___024root*>(voidSelf);
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vi2s_clock_gen_tb_verilator___024root__trace_decl_types(tracep);
    Vi2s_clock_gen_tb_verilator___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vi2s_clock_gen_tb_verilator___024root__trace_register(Vi2s_clock_gen_tb_verilator___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vi2s_clock_gen_tb_verilator::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vi2s_clock_gen_tb_verilator::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vi2s_clock_gen_tb_verilator___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
