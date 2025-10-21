// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vi2s_clock_gen_tb_simple.h for the primary calling header

#include "Vi2s_clock_gen_tb_simple__pch.h"
#include "Vi2s_clock_gen_tb_simple___024root.h"

VlCoroutine Vi2s_clock_gen_tb_simple___024root___eval_initial__TOP__Vtiming__0(Vi2s_clock_gen_tb_simple___024root* vlSelf);
VlCoroutine Vi2s_clock_gen_tb_simple___024root___eval_initial__TOP__Vtiming__1(Vi2s_clock_gen_tb_simple___024root* vlSelf);

void Vi2s_clock_gen_tb_simple___024root___eval_initial(Vi2s_clock_gen_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_simple___024root___eval_initial\n"); );
    // Body
    Vi2s_clock_gen_tb_simple___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vi2s_clock_gen_tb_simple___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__i2s_clock_gen_tb_simple__DOT__clk_i__0 
        = vlSelf->i2s_clock_gen_tb_simple__DOT__clk_i;
}

VL_INLINE_OPT VlCoroutine Vi2s_clock_gen_tb_simple___024root___eval_initial__TOP__Vtiming__0(Vi2s_clock_gen_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_simple___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Init
    IData/*31:0*/ i2s_clock_gen_tb_simple__DOT____Vrepeat0;
    i2s_clock_gen_tb_simple__DOT____Vrepeat0 = 0;
    // Body
    VL_WRITEF("=================================================================\nI2S Clock Generator Simple Test\n=================================================================\nExpected SCK period: 8 cycles\nExpected WS half-period: 512 cycles\nRunning for 5096 cycles\n=================================================================\n\n");
    vlSelf->i2s_clock_gen_tb_simple__DOT__clk_i = 0U;
    vlSelf->i2s_clock_gen_tb_simple__DOT__rst_ni = 0U;
    co_await vlSelf->__VdlySched.delay(0xc8ULL, nullptr, 
                                       "sim/i2s_clock_gen_tb_simple.sv", 
                                       86);
    vlSelf->i2s_clock_gen_tb_simple__DOT__rst_ni = 1U;
    VL_WRITEF("[%0t] Reset released\n",64,VL_TIME_UNITED_Q(1),
              -12);
    i2s_clock_gen_tb_simple__DOT____Vrepeat0 = 0x13e8U;
    while (VL_LTS_III(32, 0U, i2s_clock_gen_tb_simple__DOT____Vrepeat0)) {
        co_await vlSelf->__VtrigSched_h69d85542__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge i2s_clock_gen_tb_simple.clk_i)", 
                                                           "sim/i2s_clock_gen_tb_simple.sv", 
                                                           91);
        i2s_clock_gen_tb_simple__DOT____Vrepeat0 = 
            (i2s_clock_gen_tb_simple__DOT____Vrepeat0 
             - (IData)(1U));
    }
    VL_WRITEF("\n=================================================================\nTest Results\n=================================================================\nTotal cycles:      %0#\nSCK toggles:       %0#\nWS toggles:        %0#\nExpected WS toggles: ~8\n",
              32,vlSelf->i2s_clock_gen_tb_simple__DOT__cycle_count,
              32,vlSelf->i2s_clock_gen_tb_simple__DOT__sck_toggle_count,
              32,vlSelf->i2s_clock_gen_tb_simple__DOT__ws_toggle_count);
    if (VL_UNLIKELY(((7U <= vlSelf->i2s_clock_gen_tb_simple__DOT__ws_toggle_count) 
                     & (9U >= vlSelf->i2s_clock_gen_tb_simple__DOT__ws_toggle_count)))) {
        VL_WRITEF("\n \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227   \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227  \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227 \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\n \342\225\232\342\225\220\342\225\220\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\235\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\225\232\342\225\220\342\225\220\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\235   \342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\n");
        VL_WRITEF("    \342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227  \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227   \342\226\210\342\226\210\342\225\221      \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\224\342\225\235\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\n    \342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\235  \342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\225\221      \342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\220\342\225\235 \342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\226\210\342\226\210\342\225\221\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\226\210\342\226\210\342\225\221\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\226\210\342\226\210\342\225\221\n");
        VL_WRITEF("    \342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\225\221      \342\226\210\342\226\210\342\225\221     \342\226\210\342\226\210\342\225\221  \342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\221\n    \342\225\232\342\225\220\342\225\235   \342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235   \342\225\232\342\225\220\342\225\235      \342\225\232\342\225\220\342\225\235     \342\225\232\342\225\220\342\225\235  \342\225\232\342\225\220\342\225\235\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\n\n");
    } else {
        VL_WRITEF("\n \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227   \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227 \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227 \342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\225\227     \n \342\225\232\342\225\220\342\225\220\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\235\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\225\232\342\225\220\342\225\220\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\235   \342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\225\221     \n    \342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227  \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227   \342\226\210\342\226\210\342\225\221      \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227  \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\225\221     \n");
        VL_WRITEF("    \342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\235  \342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\225\221      \342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\235  \342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\225\221     \n    \342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\225\221      \342\226\210\342\226\210\342\225\221     \342\226\210\342\226\210\342\225\221  \342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\n    \342\225\232\342\225\220\342\225\235   \342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235   \342\225\232\342\225\220\342\225\235      \342\225\232\342\225\220\342\225\235     \342\225\232\342\225\220\342\225\235  \342\225\232\342\225\220\342\225\235\342\225\232\342\225\220\342\225\235\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\n\n");
    }
    VL_WRITEF("=================================================================\n\n");
    VL_FINISH_MT("sim/i2s_clock_gen_tb_simple.sv", 118, "");
}

VL_INLINE_OPT VlCoroutine Vi2s_clock_gen_tb_simple___024root___eval_initial__TOP__Vtiming__1(Vi2s_clock_gen_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_simple___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x13ULL, 
                                           nullptr, 
                                           "sim/i2s_clock_gen_tb_simple.sv", 
                                           46);
        vlSelf->i2s_clock_gen_tb_simple__DOT__clk_i 
            = (1U & (~ (IData)(vlSelf->i2s_clock_gen_tb_simple__DOT__clk_i)));
    }
}

void Vi2s_clock_gen_tb_simple___024root___eval_act(Vi2s_clock_gen_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_simple___024root___eval_act\n"); );
}

extern const VlUnpacked<CData/*2:0*/, 32> Vi2s_clock_gen_tb_simple__ConstPool__TABLE_hb31b5e30_0;
extern const VlUnpacked<CData/*1:0*/, 32> Vi2s_clock_gen_tb_simple__ConstPool__TABLE_h11502f1d_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vi2s_clock_gen_tb_simple__ConstPool__TABLE_h56c82868_0;

VL_INLINE_OPT void Vi2s_clock_gen_tb_simple___024root___nba_sequent__TOP__0(Vi2s_clock_gen_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_simple___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*0:0*/ __Vdly__i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_q;
    __Vdly__i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_q = 0;
    CData/*5:0*/ __Vdly__i2s_clock_gen_tb_simple__DOT__dut__DOT__ws_ctr_q;
    __Vdly__i2s_clock_gen_tb_simple__DOT__dut__DOT__ws_ctr_q = 0;
    // Body
    __Vdly__i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_q 
        = vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_q;
    __Vdly__i2s_clock_gen_tb_simple__DOT__dut__DOT__ws_ctr_q 
        = vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__ws_ctr_q;
    if (vlSelf->i2s_clock_gen_tb_simple__DOT__rst_ni) {
        vlSelf->i2s_clock_gen_tb_simple__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->i2s_clock_gen_tb_simple__DOT__cycle_count);
        if (((IData)(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_q) 
             != (IData)(vlSelf->i2s_clock_gen_tb_simple__DOT__sck_prev))) {
            vlSelf->i2s_clock_gen_tb_simple__DOT__sck_toggle_count 
                = ((IData)(1U) + vlSelf->i2s_clock_gen_tb_simple__DOT__sck_toggle_count);
        }
        if (VL_UNLIKELY(((IData)(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__ws_q) 
                         != (IData)(vlSelf->i2s_clock_gen_tb_simple__DOT__ws_prev)))) {
            vlSelf->i2s_clock_gen_tb_simple__DOT__ws_toggle_count 
                = ((IData)(1U) + vlSelf->i2s_clock_gen_tb_simple__DOT__ws_toggle_count);
            VL_WRITEF("[%0t] WS toggled (count=%0#, cycle=%0#)\n",
                      64,VL_TIME_UNITED_Q(1),-12,32,
                      vlSelf->i2s_clock_gen_tb_simple__DOT__ws_toggle_count,
                      32,vlSelf->i2s_clock_gen_tb_simple__DOT__cycle_count);
        }
        vlSelf->i2s_clock_gen_tb_simple__DOT__sck_prev 
            = vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_q;
        vlSelf->i2s_clock_gen_tb_simple__DOT__ws_prev 
            = vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__ws_q;
    } else {
        vlSelf->i2s_clock_gen_tb_simple__DOT__cycle_count = 0U;
        vlSelf->i2s_clock_gen_tb_simple__DOT__sck_toggle_count = 0U;
        vlSelf->i2s_clock_gen_tb_simple__DOT__ws_toggle_count = 0U;
        vlSelf->i2s_clock_gen_tb_simple__DOT__sck_prev = 0U;
        vlSelf->i2s_clock_gen_tb_simple__DOT__ws_prev = 0U;
    }
    if (vlSelf->i2s_clock_gen_tb_simple__DOT__rst_ni) {
        if (((~ (IData)(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_q)) 
             & (IData)(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_prev_q))) {
            if ((0x3fU == (IData)(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__ws_ctr_q))) {
                vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__ws_q 
                    = (1U & (~ (IData)(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__ws_q)));
                __Vdly__i2s_clock_gen_tb_simple__DOT__dut__DOT__ws_ctr_q = 0U;
            } else {
                __Vdly__i2s_clock_gen_tb_simple__DOT__dut__DOT__ws_ctr_q 
                    = (0x3fU & ((IData)(1U) + (IData)(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__ws_ctr_q)));
            }
        }
    } else {
        __Vdly__i2s_clock_gen_tb_simple__DOT__dut__DOT__ws_ctr_q = 0U;
        vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__ws_q = 0U;
    }
    __Vtableidx1 = (((IData)(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_ctr_q) 
                     << 2U) | (((IData)(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_q) 
                                << 1U) | (IData)(vlSelf->i2s_clock_gen_tb_simple__DOT__rst_ni)));
    vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_ctr_q 
        = Vi2s_clock_gen_tb_simple__ConstPool__TABLE_hb31b5e30_0
        [__Vtableidx1];
    if ((2U & Vi2s_clock_gen_tb_simple__ConstPool__TABLE_h11502f1d_0
         [__Vtableidx1])) {
        __Vdly__i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_q 
            = Vi2s_clock_gen_tb_simple__ConstPool__TABLE_h56c82868_0
            [__Vtableidx1];
    }
    vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__ws_ctr_q 
        = __Vdly__i2s_clock_gen_tb_simple__DOT__dut__DOT__ws_ctr_q;
    vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_prev_q 
        = ((IData)(vlSelf->i2s_clock_gen_tb_simple__DOT__rst_ni) 
           && (IData)(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_q));
    vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_q 
        = __Vdly__i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_q;
}

void Vi2s_clock_gen_tb_simple___024root___eval_nba(Vi2s_clock_gen_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_simple___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vi2s_clock_gen_tb_simple___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vi2s_clock_gen_tb_simple___024root___timing_resume(Vi2s_clock_gen_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_simple___024root___timing_resume\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h69d85542__0.resume("@(posedge i2s_clock_gen_tb_simple.clk_i)");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vi2s_clock_gen_tb_simple___024root___timing_commit(Vi2s_clock_gen_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_simple___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h69d85542__0.commit("@(posedge i2s_clock_gen_tb_simple.clk_i)");
    }
}

void Vi2s_clock_gen_tb_simple___024root___eval_triggers__act(Vi2s_clock_gen_tb_simple___024root* vlSelf);

bool Vi2s_clock_gen_tb_simple___024root___eval_phase__act(Vi2s_clock_gen_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_simple___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vi2s_clock_gen_tb_simple___024root___eval_triggers__act(vlSelf);
    Vi2s_clock_gen_tb_simple___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vi2s_clock_gen_tb_simple___024root___timing_resume(vlSelf);
        Vi2s_clock_gen_tb_simple___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vi2s_clock_gen_tb_simple___024root___eval_phase__nba(Vi2s_clock_gen_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_simple___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vi2s_clock_gen_tb_simple___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vi2s_clock_gen_tb_simple___024root___dump_triggers__nba(Vi2s_clock_gen_tb_simple___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vi2s_clock_gen_tb_simple___024root___dump_triggers__act(Vi2s_clock_gen_tb_simple___024root* vlSelf);
#endif  // VL_DEBUG

void Vi2s_clock_gen_tb_simple___024root___eval(Vi2s_clock_gen_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_simple___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vi2s_clock_gen_tb_simple___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("sim/i2s_clock_gen_tb_simple.sv", 5, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vi2s_clock_gen_tb_simple___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("sim/i2s_clock_gen_tb_simple.sv", 5, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vi2s_clock_gen_tb_simple___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vi2s_clock_gen_tb_simple___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vi2s_clock_gen_tb_simple___024root___eval_debug_assertions(Vi2s_clock_gen_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_simple___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
