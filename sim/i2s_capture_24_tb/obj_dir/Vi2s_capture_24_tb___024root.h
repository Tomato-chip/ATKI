// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vi2s_capture_24_tb.h for the primary calling header

#ifndef VERILATED_VI2S_CAPTURE_24_TB___024ROOT_H_
#define VERILATED_VI2S_CAPTURE_24_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vi2s_capture_24_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vi2s_capture_24_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ i2s_capture_24_tb__DOT__clk_i;
    CData/*0:0*/ i2s_capture_24_tb__DOT__rst_ni;
    CData/*0:0*/ i2s_capture_24_tb__DOT__sd_i;
    CData/*0:0*/ i2s_capture_24_tb__DOT__ready_o;
    CData/*2:0*/ i2s_capture_24_tb__DOT__sck_counter;
    CData/*0:0*/ i2s_capture_24_tb__DOT__sck_reg;
    CData/*5:0*/ i2s_capture_24_tb__DOT__sck_edge_counter;
    CData/*0:0*/ i2s_capture_24_tb__DOT__ws_reg;
    CData/*0:0*/ i2s_capture_24_tb__DOT__sck_prev;
    CData/*0:0*/ i2s_capture_24_tb__DOT__sck_falling;
    CData/*4:0*/ i2s_capture_24_tb__DOT__bit_index;
    CData/*0:0*/ i2s_capture_24_tb__DOT__ws_prev;
    CData/*0:0*/ i2s_capture_24_tb__DOT__new_channel;
    CData/*0:0*/ i2s_capture_24_tb__DOT__ws_edge_det;
    CData/*0:0*/ i2s_capture_24_tb__DOT__test_running;
    CData/*0:0*/ i2s_capture_24_tb__DOT__dut__DOT__sck_d;
    CData/*0:0*/ i2s_capture_24_tb__DOT__dut__DOT__ws_d;
    CData/*0:0*/ i2s_capture_24_tb__DOT__dut__DOT__ws_edge;
    CData/*5:0*/ i2s_capture_24_tb__DOT__dut__DOT__cnt_q;
    CData/*0:0*/ i2s_capture_24_tb__DOT__dut__DOT__left_done_q;
    CData/*0:0*/ i2s_capture_24_tb__DOT__dut__DOT__right_done_q;
    CData/*0:0*/ i2s_capture_24_tb__DOT__dut__DOT__channel_q;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__i2s_capture_24_tb__DOT__clk_i__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__i2s_capture_24_tb__DOT__ready_o__0;
    CData/*0:0*/ __Vtrigprevexpr_h8e568cca__0;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    IData/*23:0*/ i2s_capture_24_tb__DOT__left_o;
    IData/*23:0*/ i2s_capture_24_tb__DOT__right_o;
    IData/*23:0*/ i2s_capture_24_tb__DOT__left_pattern_1;
    IData/*23:0*/ i2s_capture_24_tb__DOT__right_pattern_1;
    IData/*23:0*/ i2s_capture_24_tb__DOT__current_pattern;
    IData/*31:0*/ i2s_capture_24_tb__DOT__test_phase;
    IData/*31:0*/ i2s_capture_24_tb__DOT__frame_count;
    IData/*31:0*/ i2s_capture_24_tb__DOT__left_captures;
    IData/*31:0*/ i2s_capture_24_tb__DOT__right_captures;
    IData/*31:0*/ i2s_capture_24_tb__DOT__ready_pulses;
    IData/*31:0*/ i2s_capture_24_tb__DOT__errors;
    IData/*31:0*/ i2s_capture_24_tb__DOT__ready_pulse_width;
    IData/*24:0*/ i2s_capture_24_tb__DOT__dut__DOT__shift25_q;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_he7b63118__0;
    VlTriggerScheduler __VtrigSched_h8d69a51b__0;
    VlTriggerScheduler __VtrigSched_h1a61c2e8__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vi2s_capture_24_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vi2s_capture_24_tb___024root(Vi2s_capture_24_tb__Syms* symsp, const char* v__name);
    ~Vi2s_capture_24_tb___024root();
    VL_UNCOPYABLE(Vi2s_capture_24_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
