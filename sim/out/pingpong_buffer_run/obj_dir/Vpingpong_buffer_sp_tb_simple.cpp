// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vpingpong_buffer_sp_tb_simple__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vpingpong_buffer_sp_tb_simple::Vpingpong_buffer_sp_tb_simple(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vpingpong_buffer_sp_tb_simple__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vpingpong_buffer_sp_tb_simple::Vpingpong_buffer_sp_tb_simple(const char* _vcname__)
    : Vpingpong_buffer_sp_tb_simple(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vpingpong_buffer_sp_tb_simple::~Vpingpong_buffer_sp_tb_simple() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vpingpong_buffer_sp_tb_simple___024root___eval_debug_assertions(Vpingpong_buffer_sp_tb_simple___024root* vlSelf);
#endif  // VL_DEBUG
void Vpingpong_buffer_sp_tb_simple___024root___eval_static(Vpingpong_buffer_sp_tb_simple___024root* vlSelf);
void Vpingpong_buffer_sp_tb_simple___024root___eval_initial(Vpingpong_buffer_sp_tb_simple___024root* vlSelf);
void Vpingpong_buffer_sp_tb_simple___024root___eval_settle(Vpingpong_buffer_sp_tb_simple___024root* vlSelf);
void Vpingpong_buffer_sp_tb_simple___024root___eval(Vpingpong_buffer_sp_tb_simple___024root* vlSelf);

void Vpingpong_buffer_sp_tb_simple::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vpingpong_buffer_sp_tb_simple::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vpingpong_buffer_sp_tb_simple___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vpingpong_buffer_sp_tb_simple___024root___eval_static(&(vlSymsp->TOP));
        Vpingpong_buffer_sp_tb_simple___024root___eval_initial(&(vlSymsp->TOP));
        Vpingpong_buffer_sp_tb_simple___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vpingpong_buffer_sp_tb_simple___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vpingpong_buffer_sp_tb_simple::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vpingpong_buffer_sp_tb_simple::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vpingpong_buffer_sp_tb_simple::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vpingpong_buffer_sp_tb_simple::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vpingpong_buffer_sp_tb_simple::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vpingpong_buffer_sp_tb_simple___024root___eval_final(Vpingpong_buffer_sp_tb_simple___024root* vlSelf);

VL_ATTR_COLD void Vpingpong_buffer_sp_tb_simple::final() {
    Vpingpong_buffer_sp_tb_simple___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vpingpong_buffer_sp_tb_simple::hierName() const { return vlSymsp->name(); }
const char* Vpingpong_buffer_sp_tb_simple::modelName() const { return "Vpingpong_buffer_sp_tb_simple"; }
unsigned Vpingpong_buffer_sp_tb_simple::threads() const { return 1; }
void Vpingpong_buffer_sp_tb_simple::prepareClone() const { contextp()->prepareClone(); }
void Vpingpong_buffer_sp_tb_simple::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vpingpong_buffer_sp_tb_simple::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vpingpong_buffer_sp_tb_simple___024root__trace_decl_types(VerilatedVcd* tracep);

void Vpingpong_buffer_sp_tb_simple___024root__trace_init_top(Vpingpong_buffer_sp_tb_simple___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vpingpong_buffer_sp_tb_simple___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpingpong_buffer_sp_tb_simple___024root*>(voidSelf);
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vpingpong_buffer_sp_tb_simple___024root__trace_decl_types(tracep);
    Vpingpong_buffer_sp_tb_simple___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vpingpong_buffer_sp_tb_simple___024root__trace_register(Vpingpong_buffer_sp_tb_simple___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vpingpong_buffer_sp_tb_simple::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vpingpong_buffer_sp_tb_simple::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vpingpong_buffer_sp_tb_simple___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
