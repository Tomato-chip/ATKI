// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vi2s_integration_tb.h for the primary calling header

#ifndef VERILATED_VI2S_INTEGRATION_TB___024ROOT_H_
#define VERILATED_VI2S_INTEGRATION_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vi2s_integration_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vi2s_integration_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ i2s_integration_tb__DOT__clk_i;
    CData/*0:0*/ i2s_integration_tb__DOT__rst_ni;
    CData/*0:0*/ i2s_integration_tb__DOT__ready_o;
    CData/*0:0*/ i2s_integration_tb__DOT__ws_prev;
    CData/*0:0*/ i2s_integration_tb__DOT__sck_prev;
    CData/*0:0*/ i2s_integration_tb__DOT__ws_edge;
    CData/*0:0*/ i2s_integration_tb__DOT__init_done;
    CData/*0:0*/ i2s_integration_tb__DOT__check_enable;
    CData/*2:0*/ i2s_integration_tb__DOT__u_clk_gen__DOT__sck_ctr_q;
    CData/*0:0*/ i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q;
    CData/*0:0*/ i2s_integration_tb__DOT__u_clk_gen__DOT__sck_tick;
    CData/*0:0*/ i2s_integration_tb__DOT__u_clk_gen__DOT__sck_prev_q;
    CData/*5:0*/ i2s_integration_tb__DOT__u_clk_gen__DOT__ws_ctr_q;
    CData/*0:0*/ i2s_integration_tb__DOT__u_clk_gen__DOT__ws_q;
    CData/*0:0*/ i2s_integration_tb__DOT__u_clk_gen__DOT__frame_start_q;
    CData/*0:0*/ i2s_integration_tb__DOT__u_capture__DOT__sck_d;
    CData/*0:0*/ i2s_integration_tb__DOT__u_capture__DOT__ws_d;
    CData/*0:0*/ i2s_integration_tb__DOT__u_capture__DOT__ws_edge;
    CData/*5:0*/ i2s_integration_tb__DOT__u_capture__DOT__cnt_q;
    CData/*0:0*/ i2s_integration_tb__DOT__u_capture__DOT__left_done_q;
    CData/*0:0*/ i2s_integration_tb__DOT__u_capture__DOT__right_done_q;
    CData/*0:0*/ i2s_integration_tb__DOT__u_capture__DOT__channel_q;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__i2s_integration_tb__DOT__clk_i__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__i2s_integration_tb__DOT__ready_o__0;
    CData/*0:0*/ __Vtrigprevexpr_h39b803dc__0;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    IData/*23:0*/ i2s_integration_tb__DOT__left_o;
    IData/*23:0*/ i2s_integration_tb__DOT__right_o;
    IData/*31:0*/ i2s_integration_tb__DOT__test_num;
    IData/*31:0*/ i2s_integration_tb__DOT__error_count;
    IData/*31:0*/ i2s_integration_tb__DOT__ready_count;
    IData/*24:0*/ i2s_integration_tb__DOT__current_pattern;
    IData/*31:0*/ i2s_integration_tb__DOT__bit_index;
    IData/*24:0*/ i2s_integration_tb__DOT__u_capture__DOT__shift25_q;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h80ee4ec0__0;
    VlTriggerScheduler __VtrigSched_h70d215d1__0;
    VlTriggerScheduler __VtrigSched_had803bee__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vi2s_integration_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vi2s_integration_tb___024root(Vi2s_integration_tb__Syms* symsp, const char* v__name);
    ~Vi2s_integration_tb___024root();
    VL_UNCOPYABLE(Vi2s_integration_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
