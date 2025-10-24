// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vi2s_clock_gen_tb_simple.h for the primary calling header

#ifndef VERILATED_VI2S_CLOCK_GEN_TB_SIMPLE___024ROOT_H_
#define VERILATED_VI2S_CLOCK_GEN_TB_SIMPLE___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vi2s_clock_gen_tb_simple__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vi2s_clock_gen_tb_simple___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ i2s_clock_gen_tb_simple__DOT__clk_i;
    CData/*0:0*/ i2s_clock_gen_tb_simple__DOT__rst_ni;
    CData/*0:0*/ i2s_clock_gen_tb_simple__DOT__sck_prev;
    CData/*0:0*/ i2s_clock_gen_tb_simple__DOT__ws_prev;
    CData/*2:0*/ i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_ctr_q;
    CData/*0:0*/ i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_q;
    CData/*0:0*/ i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_tick;
    CData/*0:0*/ i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_prev_q;
    CData/*5:0*/ i2s_clock_gen_tb_simple__DOT__dut__DOT__ws_ctr_q;
    CData/*0:0*/ i2s_clock_gen_tb_simple__DOT__dut__DOT__ws_q;
    CData/*0:0*/ i2s_clock_gen_tb_simple__DOT__dut__DOT__frame_start_q;
    CData/*0:0*/ __Vtrigprevexpr___TOP__i2s_clock_gen_tb_simple__DOT__clk_i__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ i2s_clock_gen_tb_simple__DOT__cycle_count;
    IData/*31:0*/ i2s_clock_gen_tb_simple__DOT__sck_toggle_count;
    IData/*31:0*/ i2s_clock_gen_tb_simple__DOT__ws_toggle_count;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h69d85542__0;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vi2s_clock_gen_tb_simple__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vi2s_clock_gen_tb_simple___024root(Vi2s_clock_gen_tb_simple__Syms* symsp, const char* v__name);
    ~Vi2s_clock_gen_tb_simple___024root();
    VL_UNCOPYABLE(Vi2s_clock_gen_tb_simple___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
