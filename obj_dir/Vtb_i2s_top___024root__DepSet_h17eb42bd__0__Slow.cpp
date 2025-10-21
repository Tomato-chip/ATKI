// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_i2s_top.h for the primary calling header

#include "Vtb_i2s_top__pch.h"
#include "Vtb_i2s_top___024root.h"

VL_ATTR_COLD void Vtb_i2s_top___024root___eval_static(Vtb_i2s_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_i2s_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_i2s_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtb_i2s_top___024root___eval_initial(Vtb_i2s_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_i2s_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_i2s_top___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = vlSelf->rst_n;
}

VL_ATTR_COLD void Vtb_i2s_top___024root___eval_final(Vtb_i2s_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_i2s_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_i2s_top___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtb_i2s_top___024root___eval_settle(Vtb_i2s_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_i2s_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_i2s_top___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_i2s_top___024root___dump_triggers__act(Vtb_i2s_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_i2s_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_i2s_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_i2s_top___024root___dump_triggers__nba(Vtb_i2s_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_i2s_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_i2s_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_i2s_top___024root___ctor_var_reset(Vtb_i2s_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_i2s_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_i2s_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->sck = VL_RAND_RESET_I(1);
    vlSelf->ws = VL_RAND_RESET_I(1);
    vlSelf->sd = VL_RAND_RESET_I(1);
    vlSelf->data24 = VL_RAND_RESET_I(24);
    vlSelf->valid = VL_RAND_RESET_I(1);
    vlSelf->tb_i2s_top__DOT__dut__DOT__sck_sync = VL_RAND_RESET_I(2);
    vlSelf->tb_i2s_top__DOT__dut__DOT__ws_sync = VL_RAND_RESET_I(2);
    vlSelf->tb_i2s_top__DOT__dut__DOT__sd_sync = VL_RAND_RESET_I(2);
    vlSelf->tb_i2s_top__DOT__dut__DOT__shift_reg_q = VL_RAND_RESET_I(24);
    vlSelf->tb_i2s_top__DOT__dut__DOT__bit_count_q = VL_RAND_RESET_I(6);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
}
