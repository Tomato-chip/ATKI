// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vi2s_clock_gen_tb_debug.h for the primary calling header

#ifndef VERILATED_VI2S_CLOCK_GEN_TB_DEBUG___024ROOT_H_
#define VERILATED_VI2S_CLOCK_GEN_TB_DEBUG___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vi2s_clock_gen_tb_debug__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vi2s_clock_gen_tb_debug___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ i2s_clock_gen_tb_debug__DOT__clk_i;
    CData/*0:0*/ i2s_clock_gen_tb_debug__DOT__rst_ni;
    CData/*0:0*/ i2s_clock_gen_tb_debug__DOT__sck_o;
    CData/*0:0*/ i2s_clock_gen_tb_debug__DOT__ws_o;
    CData/*0:0*/ i2s_clock_gen_tb_debug__DOT__frame_start_o;
    CData/*0:0*/ i2s_clock_gen_tb_debug__DOT__dut__DOT__clk_i;
    CData/*0:0*/ i2s_clock_gen_tb_debug__DOT__dut__DOT__rst_ni;
    CData/*0:0*/ i2s_clock_gen_tb_debug__DOT__dut__DOT__sck_o;
    CData/*0:0*/ i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_o;
    CData/*0:0*/ i2s_clock_gen_tb_debug__DOT__dut__DOT__frame_start_o;
    CData/*2:0*/ i2s_clock_gen_tb_debug__DOT__dut__DOT__sck_ctr_q;
    CData/*0:0*/ i2s_clock_gen_tb_debug__DOT__dut__DOT__sck_q;
    CData/*0:0*/ i2s_clock_gen_tb_debug__DOT__dut__DOT__sck_falling_edge;
    CData/*0:0*/ i2s_clock_gen_tb_debug__DOT__dut__DOT__sck_prev_q;
    CData/*5:0*/ i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_ctr_q;
    CData/*0:0*/ i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_q;
    CData/*0:0*/ i2s_clock_gen_tb_debug__DOT__dut__DOT__frame_start_q;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__i2s_clock_gen_tb_debug__DOT__clk_i__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h2165eb79__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vi2s_clock_gen_tb_debug__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr CData/*0:0*/ i2s_clock_gen_tb_debug__DOT__dut__DOT__WS_POL = 0U;
    static constexpr CData/*0:0*/ i2s_clock_gen_tb_debug__DOT__dut__DOT__FRAME_PULSE_EN = 1U;
    static constexpr IData/*31:0*/ i2s_clock_gen_tb_debug__DOT__SCK_DIV = 8U;
    static constexpr IData/*31:0*/ i2s_clock_gen_tb_debug__DOT__SCKS_PER_FRAME = 0x00000040U;
    static constexpr IData/*31:0*/ i2s_clock_gen_tb_debug__DOT__dut__DOT__SYS_CLK_HZ = 0x019bfcc0U;
    static constexpr IData/*31:0*/ i2s_clock_gen_tb_debug__DOT__dut__DOT__SCK_DIV = 8U;
    static constexpr IData/*31:0*/ i2s_clock_gen_tb_debug__DOT__dut__DOT__SCKS_PER_FRAME = 0x00000040U;
    static constexpr IData/*31:0*/ i2s_clock_gen_tb_debug__DOT__dut__DOT__SCK_HZ = 0x00337f98U;
    static constexpr IData/*31:0*/ i2s_clock_gen_tb_debug__DOT__dut__DOT__WS_HZ = 0x0000cdfeU;
    static constexpr IData/*31:0*/ i2s_clock_gen_tb_debug__DOT__dut__DOT__SCK_CTR_WIDTH = 3U;
    static constexpr IData/*31:0*/ i2s_clock_gen_tb_debug__DOT__dut__DOT__WS_CTR_WIDTH = 6U;
    static constexpr IData/*31:0*/ i2s_clock_gen_tb_debug__DOT__dut__DOT__SCK_HALF_HIGH = 4U;
    static constexpr IData/*31:0*/ i2s_clock_gen_tb_debug__DOT__dut__DOT__SCK_HALF_LOW = 4U;

    // CONSTRUCTORS
    Vi2s_clock_gen_tb_debug___024root(Vi2s_clock_gen_tb_debug__Syms* symsp, const char* v__name);
    ~Vi2s_clock_gen_tb_debug___024root();
    VL_UNCOPYABLE(Vi2s_clock_gen_tb_debug___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
