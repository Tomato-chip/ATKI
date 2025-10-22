// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vi2s_integration_tb.h for the primary calling header

#include "Vi2s_integration_tb__pch.h"
#include "Vi2s_integration_tb___024root.h"

VL_ATTR_COLD void Vi2s_integration_tb___024root___eval_initial__TOP(Vi2s_integration_tb___024root* vlSelf);
VlCoroutine Vi2s_integration_tb___024root___eval_initial__TOP__Vtiming__0(Vi2s_integration_tb___024root* vlSelf);
VlCoroutine Vi2s_integration_tb___024root___eval_initial__TOP__Vtiming__1(Vi2s_integration_tb___024root* vlSelf);
VlCoroutine Vi2s_integration_tb___024root___eval_initial__TOP__Vtiming__2(Vi2s_integration_tb___024root* vlSelf);

void Vi2s_integration_tb___024root___eval_initial(Vi2s_integration_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root___eval_initial\n"); );
    // Body
    Vi2s_integration_tb___024root___eval_initial__TOP(vlSelf);
    Vi2s_integration_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vi2s_integration_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vi2s_integration_tb___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__i2s_integration_tb__DOT__clk_i__0 
        = vlSelf->i2s_integration_tb__DOT__clk_i;
    vlSelf->__Vtrigprevexpr___TOP__i2s_integration_tb__DOT__ready_o__0 
        = vlSelf->i2s_integration_tb__DOT__ready_o;
    vlSelf->__Vtrigprevexpr_h39b803dc__0 = (1U & (~ (IData)(vlSelf->i2s_integration_tb__DOT__ready_o)));
}

VL_INLINE_OPT VlCoroutine Vi2s_integration_tb___024root___eval_initial__TOP__Vtiming__0(Vi2s_integration_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->i2s_integration_tb__DOT__clk_i = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x4857ULL, 
                                           nullptr, 
                                           "i2s_integration_tb.sv", 
                                           64);
        vlSelf->i2s_integration_tb__DOT__clk_i = (1U 
                                                  & (~ (IData)(vlSelf->i2s_integration_tb__DOT__clk_i)));
    }
}

VL_INLINE_OPT VlCoroutine Vi2s_integration_tb___024root___eval_initial__TOP__Vtiming__1(Vi2s_integration_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    VL_WRITEF("================================================================\nI2S Integration Testbench\n================================================================\nSystem Clock: 27000000 Hz (37.037 ns period)\nSCK Divider: 8\nSCKs per half-frame: 32 (64 SCK per full frame)\n================================================================\n\n");
    vlSelf->i2s_integration_tb__DOT__rst_ni = 0U;
    vlSelf->i2s_integration_tb__DOT__test_num = 0U;
    vlSelf->i2s_integration_tb__DOT__check_enable = 0U;
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       267);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       267);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       267);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       267);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       267);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       267);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       267);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       267);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       267);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       267);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       267);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       267);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       267);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       267);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       267);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       267);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       267);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       267);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       267);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       267);
    vlSelf->i2s_integration_tb__DOT__rst_ni = 1U;
    VL_WRITEF("[%0t] Reset released\n\n[%0t] Starting Test 0: L=0xa5a5a5, R=0x5a5a5a\n",
              64,VL_TIME_UNITED_Q(1000),-9,64,VL_TIME_UNITED_Q(1000),
              -9);
    vlSelf->i2s_integration_tb__DOT__test_num = 0U;
    vlSelf->i2s_integration_tb__DOT__check_enable = 1U;
    while ((1U & (~ (IData)(vlSelf->i2s_integration_tb__DOT__ready_o)))) {
        co_await vlSelf->__VtrigSched_h70d215d1__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] i2s_integration_tb.ready_o)", 
                                                           "i2s_integration_tb.sv", 
                                                           275);
    }
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       276);
    vlSelf->i2s_integration_tb__DOT__check_enable = 0U;
    VL_WRITEF("[PASS] Test 0 completed\n\n");
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       279);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       279);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       279);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       279);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       279);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       279);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       279);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       279);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       279);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       279);
    vlSelf->i2s_integration_tb__DOT__test_num = 1U;
    VL_WRITEF("\n[%0t] Starting Test 1: L=0x123456, R=0x789abc\n",
              64,VL_TIME_UNITED_Q(1000),-9);
    while (vlSelf->i2s_integration_tb__DOT__ready_o) {
        co_await vlSelf->__VtrigSched_had803bee__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] (~ i2s_integration_tb.ready_o))", 
                                                           "i2s_integration_tb.sv", 
                                                           285);
    }
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       285);
    while ((1U & (~ (IData)(vlSelf->i2s_integration_tb__DOT__ready_o)))) {
        co_await vlSelf->__VtrigSched_h70d215d1__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] i2s_integration_tb.ready_o)", 
                                                           "i2s_integration_tb.sv", 
                                                           286);
    }
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       287);
    while (vlSelf->i2s_integration_tb__DOT__ready_o) {
        co_await vlSelf->__VtrigSched_had803bee__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] (~ i2s_integration_tb.ready_o))", 
                                                           "i2s_integration_tb.sv", 
                                                           288);
    }
    vlSelf->i2s_integration_tb__DOT__check_enable = 1U;
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       290);
    while ((1U & (~ (IData)(vlSelf->i2s_integration_tb__DOT__ready_o)))) {
        co_await vlSelf->__VtrigSched_h70d215d1__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] i2s_integration_tb.ready_o)", 
                                                           "i2s_integration_tb.sv", 
                                                           291);
    }
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       292);
    vlSelf->i2s_integration_tb__DOT__check_enable = 0U;
    VL_WRITEF("[PASS] Test 1 completed\n\n");
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       295);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       295);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       295);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       295);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       295);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       295);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       295);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       295);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       295);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       295);
    vlSelf->i2s_integration_tb__DOT__test_num = 2U;
    VL_WRITEF("\n[%0t] Starting Test 2: L=0xdef012, R=0x345678\n",
              64,VL_TIME_UNITED_Q(1000),-9);
    while (vlSelf->i2s_integration_tb__DOT__ready_o) {
        co_await vlSelf->__VtrigSched_had803bee__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] (~ i2s_integration_tb.ready_o))", 
                                                           "i2s_integration_tb.sv", 
                                                           301);
    }
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       301);
    while ((1U & (~ (IData)(vlSelf->i2s_integration_tb__DOT__ready_o)))) {
        co_await vlSelf->__VtrigSched_h70d215d1__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] i2s_integration_tb.ready_o)", 
                                                           "i2s_integration_tb.sv", 
                                                           302);
    }
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       303);
    while (vlSelf->i2s_integration_tb__DOT__ready_o) {
        co_await vlSelf->__VtrigSched_had803bee__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] (~ i2s_integration_tb.ready_o))", 
                                                           "i2s_integration_tb.sv", 
                                                           304);
    }
    vlSelf->i2s_integration_tb__DOT__check_enable = 1U;
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       306);
    while ((1U & (~ (IData)(vlSelf->i2s_integration_tb__DOT__ready_o)))) {
        co_await vlSelf->__VtrigSched_h70d215d1__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] i2s_integration_tb.ready_o)", 
                                                           "i2s_integration_tb.sv", 
                                                           307);
    }
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       308);
    vlSelf->i2s_integration_tb__DOT__check_enable = 0U;
    VL_WRITEF("[PASS] Test 2 completed\n\n");
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       311);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       311);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       311);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       311);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       311);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       311);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       311);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       311);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       311);
    co_await vlSelf->__VtrigSched_h80ee4ec0__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_integration_tb.clk_i)", 
                                                       "i2s_integration_tb.sv", 
                                                       311);
    VL_WRITEF("\n================================================================\nTest Summary\n================================================================\nTotal ready_o pulses: %0#\nTotal errors: %0#\n",
              32,vlSelf->i2s_integration_tb__DOT__ready_count,
              32,vlSelf->i2s_integration_tb__DOT__error_count);
    if (((0U == vlSelf->i2s_integration_tb__DOT__error_count) 
         & (3U <= vlSelf->i2s_integration_tb__DOT__ready_count))) {
        VL_WRITEF("\n  \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227    \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227  \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227 \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\n  \342\225\232\342\225\220\342\225\220\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\235\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\225\232\342\225\220\342\225\220\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\235    \342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\n");
        VL_WRITEF("     \342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227  \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227   \342\226\210\342\226\210\342\225\221       \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\224\342\225\235\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\n     \342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\235  \342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\225\221       \342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\220\342\225\235 \342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\226\210\342\226\210\342\225\221\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\226\210\342\226\210\342\225\221\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\226\210\342\226\210\342\225\221\n");
        VL_WRITEF("     \342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\225\221       \342\226\210\342\226\210\342\225\221     \342\226\210\342\226\210\342\225\221  \342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\221\n     \342\225\232\342\225\220\342\225\235   \342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235   \342\225\232\342\225\220\342\225\235       \342\225\232\342\225\220\342\225\235     \342\225\232\342\225\220\342\225\235  \342\225\232\342\225\220\342\225\235\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\n\n  All tests passed successfully!\n");
    } else {
        VL_WRITEF("\n  \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227    \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227 \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227 \342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\225\227     \n  \342\225\232\342\225\220\342\225\220\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\235\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\225\232\342\225\220\342\225\220\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\235    \342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\225\221     \n");
        VL_WRITEF("     \342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227  \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227   \342\226\210\342\226\210\342\225\221       \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227  \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\225\221     \n     \342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\235  \342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\225\221       \342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\235  \342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\225\221     \n     \342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\225\221       \342\226\210\342\226\210\342\225\221     \342\226\210\342\226\210\342\225\221  \342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\n");
        VL_WRITEF("     \342\225\232\342\225\220\342\225\235   \342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235   \342\225\232\342\225\220\342\225\235       \342\225\232\342\225\220\342\225\235     \342\225\232\342\225\220\342\225\235  \342\225\232\342\225\220\342\225\235\342\225\232\342\225\220\342\225\235\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\n\n  Test failed with %0# errors\n",
                  32,vlSelf->i2s_integration_tb__DOT__error_count);
    }
    VL_WRITEF("================================================================\n\n");
    VL_FINISH_MT("i2s_integration_tb.sv", 339, "");
}

void Vi2s_integration_tb___024root___eval_act(Vi2s_integration_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root___eval_act\n"); );
}

void Vi2s_integration_tb___024root___nba_sequent__TOP__0(Vi2s_integration_tb___024root* vlSelf);

void Vi2s_integration_tb___024root___eval_nba(Vi2s_integration_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vi2s_integration_tb___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vi2s_integration_tb___024root___timing_resume(Vi2s_integration_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root___timing_resume\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h80ee4ec0__0.resume("@(posedge i2s_integration_tb.clk_i)");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h70d215d1__0.resume("@([changed] i2s_integration_tb.ready_o)");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_had803bee__0.resume("@([changed] (~ i2s_integration_tb.ready_o))");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vi2s_integration_tb___024root___timing_commit(Vi2s_integration_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h80ee4ec0__0.commit("@(posedge i2s_integration_tb.clk_i)");
    }
    if ((! (4ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h70d215d1__0.commit("@([changed] i2s_integration_tb.ready_o)");
    }
    if ((! (8ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_had803bee__0.commit("@([changed] (~ i2s_integration_tb.ready_o))");
    }
}

void Vi2s_integration_tb___024root___eval_triggers__act(Vi2s_integration_tb___024root* vlSelf);

bool Vi2s_integration_tb___024root___eval_phase__act(Vi2s_integration_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vi2s_integration_tb___024root___eval_triggers__act(vlSelf);
    Vi2s_integration_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vi2s_integration_tb___024root___timing_resume(vlSelf);
        Vi2s_integration_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vi2s_integration_tb___024root___eval_phase__nba(Vi2s_integration_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vi2s_integration_tb___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vi2s_integration_tb___024root___dump_triggers__nba(Vi2s_integration_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vi2s_integration_tb___024root___dump_triggers__act(Vi2s_integration_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vi2s_integration_tb___024root___eval(Vi2s_integration_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vi2s_integration_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("i2s_integration_tb.sv", 17, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vi2s_integration_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("i2s_integration_tb.sv", 17, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vi2s_integration_tb___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vi2s_integration_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vi2s_integration_tb___024root___eval_debug_assertions(Vi2s_integration_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
