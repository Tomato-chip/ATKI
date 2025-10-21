// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vi2s_clock_gen_tb_verilator.h for the primary calling header

#include "Vi2s_clock_gen_tb_verilator__pch.h"
#include "Vi2s_clock_gen_tb_verilator___024root.h"

VL_ATTR_COLD void Vi2s_clock_gen_tb_verilator___024root___eval_static(Vi2s_clock_gen_tb_verilator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vi2s_clock_gen_tb_verilator___024root___eval_final(Vi2s_clock_gen_tb_verilator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vi2s_clock_gen_tb_verilator___024root___eval_settle(Vi2s_clock_gen_tb_verilator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vi2s_clock_gen_tb_verilator___024root___dump_triggers__act(Vi2s_clock_gen_tb_verilator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge i2s_clock_gen_tb_verilator.clk_i)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([changed] (32'h8 <= i2s_clock_gen_tb_verilator.ws_toggle_count))\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vi2s_clock_gen_tb_verilator___024root___dump_triggers__nba(Vi2s_clock_gen_tb_verilator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge i2s_clock_gen_tb_verilator.clk_i)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([changed] (32'h8 <= i2s_clock_gen_tb_verilator.ws_toggle_count))\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vi2s_clock_gen_tb_verilator___024root___ctor_var_reset(Vi2s_clock_gen_tb_verilator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->i2s_clock_gen_tb_verilator__DOT__clk_i = VL_RAND_RESET_I(1);
    vlSelf->i2s_clock_gen_tb_verilator__DOT__rst_ni = VL_RAND_RESET_I(1);
    vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_toggle_count = 0;
    vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_period_sum = 0;
    vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_period_count = 0;
    vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_high_time = 0;
    vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_low_time = 0;
    vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_last_toggle_cycle = 0;
    vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_prev = VL_RAND_RESET_I(1);
    vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_toggle_count = 0;
    vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_period_sum = 0;
    vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_period_count = 0;
    vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_last_toggle_cycle = 0;
    vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_prev = VL_RAND_RESET_I(1);
    vlSelf->i2s_clock_gen_tb_verilator__DOT__cycle_count = 0;
    vlSelf->i2s_clock_gen_tb_verilator__DOT__frame_start_count = 0;
    vlSelf->i2s_clock_gen_tb_verilator__DOT__errors = 0;
    vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_change_on_sck_high_count = 0;
    vlSelf->i2s_clock_gen_tb_verilator__DOT__duty_diff_val = 0;
    vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_to_sck_ratio_val = 0;
    vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk1__DOT__period = 0;
    vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk2__DOT__period = 0;
    vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk3__DOT__sck_period_avg = 0;
    vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk4__DOT__ws_period_avg = 0;
    vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_ctr_q = VL_RAND_RESET_I(3);
    vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_q = VL_RAND_RESET_I(1);
    vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_prev_q = VL_RAND_RESET_I(1);
    vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_ctr_q = VL_RAND_RESET_I(6);
    vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_q = VL_RAND_RESET_I(1);
    vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__frame_start_q = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__i2s_clock_gen_tb_verilator__DOT__clk_i__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr_hcd664f0a__0 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
}
