// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vi2s_clock_gen_tb_verilator.h for the primary calling header

#include "Vi2s_clock_gen_tb_verilator__pch.h"
#include "Vi2s_clock_gen_tb_verilator___024root.h"

VL_ATTR_COLD void Vi2s_clock_gen_tb_verilator___024root___eval_initial__TOP(Vi2s_clock_gen_tb_verilator___024root* vlSelf);
VlCoroutine Vi2s_clock_gen_tb_verilator___024root___eval_initial__TOP__Vtiming__0(Vi2s_clock_gen_tb_verilator___024root* vlSelf);
VlCoroutine Vi2s_clock_gen_tb_verilator___024root___eval_initial__TOP__Vtiming__1(Vi2s_clock_gen_tb_verilator___024root* vlSelf);
VlCoroutine Vi2s_clock_gen_tb_verilator___024root___eval_initial__TOP__Vtiming__2(Vi2s_clock_gen_tb_verilator___024root* vlSelf);

void Vi2s_clock_gen_tb_verilator___024root___eval_initial(Vi2s_clock_gen_tb_verilator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root___eval_initial\n"); );
    // Body
    Vi2s_clock_gen_tb_verilator___024root___eval_initial__TOP(vlSelf);
    Vi2s_clock_gen_tb_verilator___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vi2s_clock_gen_tb_verilator___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vi2s_clock_gen_tb_verilator___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__i2s_clock_gen_tb_verilator__DOT__clk_i__0 
        = vlSelf->i2s_clock_gen_tb_verilator__DOT__clk_i;
    vlSelf->__Vtrigprevexpr_hcd664f0a__0 = (8U <= vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_toggle_count);
}

VL_INLINE_OPT VlCoroutine Vi2s_clock_gen_tb_verilator___024root___eval_initial__TOP__Vtiming__0(Vi2s_clock_gen_tb_verilator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->i2s_clock_gen_tb_verilator__DOT__clk_i = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x4857ULL, 
                                           nullptr, 
                                           "sim/i2s_clock_gen_tb_verilator.sv", 
                                           51);
        vlSelf->i2s_clock_gen_tb_verilator__DOT__clk_i 
            = (1U & (~ (IData)(vlSelf->i2s_clock_gen_tb_verilator__DOT__clk_i)));
    }
}

void Vi2s_clock_gen_tb_verilator___024root___eval_act(Vi2s_clock_gen_tb_verilator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root___eval_act\n"); );
}

void Vi2s_clock_gen_tb_verilator___024root___nba_sequent__TOP__0(Vi2s_clock_gen_tb_verilator___024root* vlSelf);

void Vi2s_clock_gen_tb_verilator___024root___eval_nba(Vi2s_clock_gen_tb_verilator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vi2s_clock_gen_tb_verilator___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vi2s_clock_gen_tb_verilator___024root___timing_resume(Vi2s_clock_gen_tb_verilator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root___timing_resume\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_hb7b23e70__0.resume("@(posedge i2s_clock_gen_tb_verilator.clk_i)");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h595187a8__0.resume("@([changed] (32'h8 <= i2s_clock_gen_tb_verilator.ws_toggle_count))");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vi2s_clock_gen_tb_verilator___024root___timing_commit(Vi2s_clock_gen_tb_verilator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_hb7b23e70__0.commit("@(posedge i2s_clock_gen_tb_verilator.clk_i)");
    }
    if ((! (4ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h595187a8__0.commit("@([changed] (32'h8 <= i2s_clock_gen_tb_verilator.ws_toggle_count))");
    }
}

void Vi2s_clock_gen_tb_verilator___024root___eval_triggers__act(Vi2s_clock_gen_tb_verilator___024root* vlSelf);

bool Vi2s_clock_gen_tb_verilator___024root___eval_phase__act(Vi2s_clock_gen_tb_verilator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vi2s_clock_gen_tb_verilator___024root___eval_triggers__act(vlSelf);
    Vi2s_clock_gen_tb_verilator___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vi2s_clock_gen_tb_verilator___024root___timing_resume(vlSelf);
        Vi2s_clock_gen_tb_verilator___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vi2s_clock_gen_tb_verilator___024root___eval_phase__nba(Vi2s_clock_gen_tb_verilator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vi2s_clock_gen_tb_verilator___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vi2s_clock_gen_tb_verilator___024root___dump_triggers__nba(Vi2s_clock_gen_tb_verilator___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vi2s_clock_gen_tb_verilator___024root___dump_triggers__act(Vi2s_clock_gen_tb_verilator___024root* vlSelf);
#endif  // VL_DEBUG

void Vi2s_clock_gen_tb_verilator___024root___eval(Vi2s_clock_gen_tb_verilator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vi2s_clock_gen_tb_verilator___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("sim/i2s_clock_gen_tb_verilator.sv", 13, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vi2s_clock_gen_tb_verilator___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("sim/i2s_clock_gen_tb_verilator.sv", 13, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vi2s_clock_gen_tb_verilator___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vi2s_clock_gen_tb_verilator___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vi2s_clock_gen_tb_verilator___024root___eval_debug_assertions(Vi2s_clock_gen_tb_verilator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
