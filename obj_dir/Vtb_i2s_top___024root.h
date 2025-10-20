// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_i2s_top.h for the primary calling header

#ifndef VERILATED_VTB_I2S_TOP___024ROOT_H_
#define VERILATED_VTB_I2S_TOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtb_i2s_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_i2s_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(sck,0,0);
    VL_IN8(ws,0,0);
    VL_IN8(sd,0,0);
    VL_OUT8(valid,0,0);
    CData/*1:0*/ tb_i2s_top__DOT__dut__DOT__sck_sync;
    CData/*1:0*/ tb_i2s_top__DOT__dut__DOT__ws_sync;
    CData/*1:0*/ tb_i2s_top__DOT__dut__DOT__sd_sync;
    CData/*5:0*/ tb_i2s_top__DOT__dut__DOT__bit_count_q;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    CData/*0:0*/ __VactContinue;
    VL_OUT(data24,23,0);
    IData/*23:0*/ tb_i2s_top__DOT__dut__DOT__shift_reg_q;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_i2s_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_i2s_top___024root(Vtb_i2s_top__Syms* symsp, const char* v__name);
    ~Vtb_i2s_top___024root();
    VL_UNCOPYABLE(Vtb_i2s_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
