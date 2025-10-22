// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vi2s_capture_24_tb.h for the primary calling header

#include "Vi2s_capture_24_tb__pch.h"
#include "Vi2s_capture_24_tb___024root.h"

VL_ATTR_COLD void Vi2s_capture_24_tb___024root___eval_static__TOP(Vi2s_capture_24_tb___024root* vlSelf);

VL_ATTR_COLD void Vi2s_capture_24_tb___024root___eval_static(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___eval_static\n"); );
    // Body
    Vi2s_capture_24_tb___024root___eval_static__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vi2s_capture_24_tb___024root___eval_static__TOP(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->i2s_capture_24_tb__DOT__left_pattern_1 = 0x123456U;
    vlSelf->i2s_capture_24_tb__DOT__right_pattern_1 = 0xabcdefU;
}

VL_ATTR_COLD void Vi2s_capture_24_tb___024root___eval_final(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vi2s_capture_24_tb___024root___dump_triggers__stl(Vi2s_capture_24_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vi2s_capture_24_tb___024root___eval_phase__stl(Vi2s_capture_24_tb___024root* vlSelf);

VL_ATTR_COLD void Vi2s_capture_24_tb___024root___eval_settle(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vi2s_capture_24_tb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../../digital/sampler/i2s_capture_24_tb.sv", 15, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vi2s_capture_24_tb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vi2s_capture_24_tb___024root___dump_triggers__stl(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vi2s_capture_24_tb___024root___stl_sequent__TOP__0(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->i2s_capture_24_tb__DOT__sck_falling = (
                                                   (~ (IData)(vlSelf->i2s_capture_24_tb__DOT__sck_reg)) 
                                                   & (IData)(vlSelf->i2s_capture_24_tb__DOT__sck_prev));
    vlSelf->i2s_capture_24_tb__DOT__ws_edge_det = ((IData)(vlSelf->i2s_capture_24_tb__DOT__ws_reg) 
                                                   != (IData)(vlSelf->i2s_capture_24_tb__DOT__ws_prev));
    vlSelf->i2s_capture_24_tb__DOT__dut__DOT__ws_edge 
        = ((IData)(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__ws_d) 
           != (IData)(vlSelf->i2s_capture_24_tb__DOT__ws_reg));
}

VL_ATTR_COLD void Vi2s_capture_24_tb___024root___eval_stl(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vi2s_capture_24_tb___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vi2s_capture_24_tb___024root___eval_triggers__stl(Vi2s_capture_24_tb___024root* vlSelf);

VL_ATTR_COLD bool Vi2s_capture_24_tb___024root___eval_phase__stl(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vi2s_capture_24_tb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vi2s_capture_24_tb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vi2s_capture_24_tb___024root___dump_triggers__act(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge i2s_capture_24_tb.clk_i)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([changed] i2s_capture_24_tb.ready_o)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([changed] (~ i2s_capture_24_tb.ready_o))\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vi2s_capture_24_tb___024root___dump_triggers__nba(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge i2s_capture_24_tb.clk_i)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([changed] i2s_capture_24_tb.ready_o)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([changed] (~ i2s_capture_24_tb.ready_o))\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vi2s_capture_24_tb___024root___ctor_var_reset(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->i2s_capture_24_tb__DOT__clk_i = VL_RAND_RESET_I(1);
    vlSelf->i2s_capture_24_tb__DOT__rst_ni = VL_RAND_RESET_I(1);
    vlSelf->i2s_capture_24_tb__DOT__sd_i = VL_RAND_RESET_I(1);
    vlSelf->i2s_capture_24_tb__DOT__left_o = VL_RAND_RESET_I(24);
    vlSelf->i2s_capture_24_tb__DOT__right_o = VL_RAND_RESET_I(24);
    vlSelf->i2s_capture_24_tb__DOT__ready_o = VL_RAND_RESET_I(1);
    vlSelf->i2s_capture_24_tb__DOT__left_pattern_1 = VL_RAND_RESET_I(24);
    vlSelf->i2s_capture_24_tb__DOT__right_pattern_1 = VL_RAND_RESET_I(24);
    vlSelf->i2s_capture_24_tb__DOT__sck_counter = VL_RAND_RESET_I(3);
    vlSelf->i2s_capture_24_tb__DOT__sck_reg = VL_RAND_RESET_I(1);
    vlSelf->i2s_capture_24_tb__DOT__sck_edge_counter = VL_RAND_RESET_I(6);
    vlSelf->i2s_capture_24_tb__DOT__ws_reg = VL_RAND_RESET_I(1);
    vlSelf->i2s_capture_24_tb__DOT__sck_prev = VL_RAND_RESET_I(1);
    vlSelf->i2s_capture_24_tb__DOT__sck_falling = VL_RAND_RESET_I(1);
    vlSelf->i2s_capture_24_tb__DOT__bit_index = VL_RAND_RESET_I(5);
    vlSelf->i2s_capture_24_tb__DOT__current_pattern = VL_RAND_RESET_I(24);
    vlSelf->i2s_capture_24_tb__DOT__ws_prev = VL_RAND_RESET_I(1);
    vlSelf->i2s_capture_24_tb__DOT__new_channel = VL_RAND_RESET_I(1);
    vlSelf->i2s_capture_24_tb__DOT__ws_edge_det = VL_RAND_RESET_I(1);
    vlSelf->i2s_capture_24_tb__DOT__test_phase = 0;
    vlSelf->i2s_capture_24_tb__DOT__frame_count = 0;
    vlSelf->i2s_capture_24_tb__DOT__test_running = VL_RAND_RESET_I(1);
    vlSelf->i2s_capture_24_tb__DOT__left_captures = 0;
    vlSelf->i2s_capture_24_tb__DOT__right_captures = 0;
    vlSelf->i2s_capture_24_tb__DOT__ready_pulses = 0;
    vlSelf->i2s_capture_24_tb__DOT__errors = 0;
    vlSelf->i2s_capture_24_tb__DOT__ready_pulse_width = 0;
    vlSelf->i2s_capture_24_tb__DOT__dut__DOT__sck_d = VL_RAND_RESET_I(1);
    vlSelf->i2s_capture_24_tb__DOT__dut__DOT__ws_d = VL_RAND_RESET_I(1);
    vlSelf->i2s_capture_24_tb__DOT__dut__DOT__ws_edge = VL_RAND_RESET_I(1);
    vlSelf->i2s_capture_24_tb__DOT__dut__DOT__shift25_q = VL_RAND_RESET_I(25);
    vlSelf->i2s_capture_24_tb__DOT__dut__DOT__cnt_q = VL_RAND_RESET_I(6);
    vlSelf->i2s_capture_24_tb__DOT__dut__DOT__left_done_q = VL_RAND_RESET_I(1);
    vlSelf->i2s_capture_24_tb__DOT__dut__DOT__right_done_q = VL_RAND_RESET_I(1);
    vlSelf->i2s_capture_24_tb__DOT__dut__DOT__channel_q = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__i2s_capture_24_tb__DOT__clk_i__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__i2s_capture_24_tb__DOT__ready_o__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr_h8e568cca__0 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
