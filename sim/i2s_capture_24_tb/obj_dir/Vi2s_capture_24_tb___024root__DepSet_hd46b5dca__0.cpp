// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vi2s_capture_24_tb.h for the primary calling header

#include "Vi2s_capture_24_tb__pch.h"
#include "Vi2s_capture_24_tb___024root.h"

VlCoroutine Vi2s_capture_24_tb___024root___eval_initial__TOP__Vtiming__0(Vi2s_capture_24_tb___024root* vlSelf);
VlCoroutine Vi2s_capture_24_tb___024root___eval_initial__TOP__Vtiming__1(Vi2s_capture_24_tb___024root* vlSelf);
VlCoroutine Vi2s_capture_24_tb___024root___eval_initial__TOP__Vtiming__2(Vi2s_capture_24_tb___024root* vlSelf);

void Vi2s_capture_24_tb___024root___eval_initial(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vm_traceActivity[1U] = 1U;
    Vi2s_capture_24_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vi2s_capture_24_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vi2s_capture_24_tb___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__i2s_capture_24_tb__DOT__clk_i__0 
        = vlSelf->i2s_capture_24_tb__DOT__clk_i;
    vlSelf->__Vtrigprevexpr___TOP__i2s_capture_24_tb__DOT__ready_o__0 
        = vlSelf->i2s_capture_24_tb__DOT__ready_o;
    vlSelf->__Vtrigprevexpr_h8e568cca__0 = (1U & (~ (IData)(vlSelf->i2s_capture_24_tb__DOT__ready_o)));
}

VL_INLINE_OPT VlCoroutine Vi2s_capture_24_tb___024root___eval_initial__TOP__Vtiming__0(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->i2s_capture_24_tb__DOT__clk_i = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x4857ULL, 
                                           nullptr, 
                                           "../../digital/sampler/i2s_capture_24_tb.sv", 
                                           28);
        vlSelf->i2s_capture_24_tb__DOT__clk_i = (1U 
                                                 & (~ (IData)(vlSelf->i2s_capture_24_tb__DOT__clk_i)));
    }
}

VL_INLINE_OPT VlCoroutine Vi2s_capture_24_tb___024root___eval_initial__TOP__Vtiming__2(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0x3b9aca00ULL, 
                                       nullptr, "../../digital/sampler/i2s_capture_24_tb.sv", 
                                       507);
    VL_WRITEF("\n[ERROR] Simulation timeout! Test did not complete in time.\nThis may indicate a hang or timing issue.\n\n");
    VL_FINISH_MT("../../digital/sampler/i2s_capture_24_tb.sv", 510, "");
}

void Vi2s_capture_24_tb___024root___eval_act(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vi2s_capture_24_tb___024root___nba_sequent__TOP__0(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdly__i2s_capture_24_tb__DOT__sck_reg;
    __Vdly__i2s_capture_24_tb__DOT__sck_reg = 0;
    CData/*2:0*/ __Vdly__i2s_capture_24_tb__DOT__sck_counter;
    __Vdly__i2s_capture_24_tb__DOT__sck_counter = 0;
    CData/*0:0*/ __Vdly__i2s_capture_24_tb__DOT__ws_reg;
    __Vdly__i2s_capture_24_tb__DOT__ws_reg = 0;
    CData/*5:0*/ __Vdly__i2s_capture_24_tb__DOT__sck_edge_counter;
    __Vdly__i2s_capture_24_tb__DOT__sck_edge_counter = 0;
    CData/*4:0*/ __Vdly__i2s_capture_24_tb__DOT__bit_index;
    __Vdly__i2s_capture_24_tb__DOT__bit_index = 0;
    CData/*5:0*/ __Vdly__i2s_capture_24_tb__DOT__dut__DOT__cnt_q;
    __Vdly__i2s_capture_24_tb__DOT__dut__DOT__cnt_q = 0;
    IData/*24:0*/ __Vdly__i2s_capture_24_tb__DOT__dut__DOT__shift25_q;
    __Vdly__i2s_capture_24_tb__DOT__dut__DOT__shift25_q = 0;
    CData/*0:0*/ __Vdly__i2s_capture_24_tb__DOT__dut__DOT__right_done_q;
    __Vdly__i2s_capture_24_tb__DOT__dut__DOT__right_done_q = 0;
    CData/*0:0*/ __Vdly__i2s_capture_24_tb__DOT__dut__DOT__left_done_q;
    __Vdly__i2s_capture_24_tb__DOT__dut__DOT__left_done_q = 0;
    // Body
    __Vdly__i2s_capture_24_tb__DOT__sck_counter = vlSelf->i2s_capture_24_tb__DOT__sck_counter;
    __Vdly__i2s_capture_24_tb__DOT__sck_reg = vlSelf->i2s_capture_24_tb__DOT__sck_reg;
    __Vdly__i2s_capture_24_tb__DOT__bit_index = vlSelf->i2s_capture_24_tb__DOT__bit_index;
    __Vdly__i2s_capture_24_tb__DOT__sck_edge_counter 
        = vlSelf->i2s_capture_24_tb__DOT__sck_edge_counter;
    __Vdly__i2s_capture_24_tb__DOT__ws_reg = vlSelf->i2s_capture_24_tb__DOT__ws_reg;
    __Vdly__i2s_capture_24_tb__DOT__dut__DOT__left_done_q 
        = vlSelf->i2s_capture_24_tb__DOT__dut__DOT__left_done_q;
    __Vdly__i2s_capture_24_tb__DOT__dut__DOT__right_done_q 
        = vlSelf->i2s_capture_24_tb__DOT__dut__DOT__right_done_q;
    __Vdly__i2s_capture_24_tb__DOT__dut__DOT__shift25_q 
        = vlSelf->i2s_capture_24_tb__DOT__dut__DOT__shift25_q;
    __Vdly__i2s_capture_24_tb__DOT__dut__DOT__cnt_q 
        = vlSelf->i2s_capture_24_tb__DOT__dut__DOT__cnt_q;
    if (VL_UNLIKELY(((IData)(vlSelf->i2s_capture_24_tb__DOT__test_running) 
                     & (IData)(vlSelf->i2s_capture_24_tb__DOT__ready_o)))) {
        VL_WRITEF("  [%0t ns] ready_o asserted (L=0x%06x, R=0x%06x)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,24,vlSelf->i2s_capture_24_tb__DOT__left_o,
                  24,vlSelf->i2s_capture_24_tb__DOT__right_o);
    }
    if (vlSelf->i2s_capture_24_tb__DOT__rst_ni) {
        if ((3U == (IData)(vlSelf->i2s_capture_24_tb__DOT__sck_counter))) {
            __Vdly__i2s_capture_24_tb__DOT__sck_reg 
                = (1U & (~ (IData)(vlSelf->i2s_capture_24_tb__DOT__sck_reg)));
            __Vdly__i2s_capture_24_tb__DOT__sck_counter = 0U;
        } else {
            __Vdly__i2s_capture_24_tb__DOT__sck_counter 
                = (7U & ((IData)(1U) + (IData)(vlSelf->i2s_capture_24_tb__DOT__sck_counter)));
        }
        if (((~ (IData)(vlSelf->i2s_capture_24_tb__DOT__sck_prev)) 
             & (IData)(vlSelf->i2s_capture_24_tb__DOT__sck_reg))) {
            if ((0x1fU == (IData)(vlSelf->i2s_capture_24_tb__DOT__sck_edge_counter))) {
                __Vdly__i2s_capture_24_tb__DOT__ws_reg 
                    = (1U & (~ (IData)(vlSelf->i2s_capture_24_tb__DOT__ws_reg)));
                __Vdly__i2s_capture_24_tb__DOT__sck_edge_counter = 0U;
            } else {
                __Vdly__i2s_capture_24_tb__DOT__sck_edge_counter 
                    = (0x3fU & ((IData)(1U) + (IData)(vlSelf->i2s_capture_24_tb__DOT__sck_edge_counter)));
            }
        }
        vlSelf->i2s_capture_24_tb__DOT__ready_o = 0U;
        if ((0x19U == (IData)(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__cnt_q))) {
            if (vlSelf->i2s_capture_24_tb__DOT__dut__DOT__channel_q) {
                vlSelf->i2s_capture_24_tb__DOT__right_o 
                    = (0xffffffU & vlSelf->i2s_capture_24_tb__DOT__dut__DOT__shift25_q);
                __Vdly__i2s_capture_24_tb__DOT__dut__DOT__right_done_q = 1U;
            } else {
                vlSelf->i2s_capture_24_tb__DOT__left_o 
                    = (0xffffffU & vlSelf->i2s_capture_24_tb__DOT__dut__DOT__shift25_q);
                __Vdly__i2s_capture_24_tb__DOT__dut__DOT__left_done_q = 1U;
            }
        }
        if (vlSelf->i2s_capture_24_tb__DOT__dut__DOT__ws_edge) {
            __Vdly__i2s_capture_24_tb__DOT__dut__DOT__cnt_q = 0U;
            __Vdly__i2s_capture_24_tb__DOT__dut__DOT__shift25_q = 0U;
        } else if (((~ (IData)(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__sck_d)) 
                    & (IData)(vlSelf->i2s_capture_24_tb__DOT__sck_reg))) {
            if ((0x19U > (IData)(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__cnt_q))) {
                __Vdly__i2s_capture_24_tb__DOT__dut__DOT__shift25_q 
                    = ((0x1fffffeU & (vlSelf->i2s_capture_24_tb__DOT__dut__DOT__shift25_q 
                                      << 1U)) | (IData)(vlSelf->i2s_capture_24_tb__DOT__sd_i));
                __Vdly__i2s_capture_24_tb__DOT__dut__DOT__cnt_q 
                    = (0x3fU & ((IData)(1U) + (IData)(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__cnt_q)));
            }
        }
        if (vlSelf->i2s_capture_24_tb__DOT__ws_edge_det) {
            vlSelf->i2s_capture_24_tb__DOT__new_channel = 1U;
            __Vdly__i2s_capture_24_tb__DOT__bit_index = 0U;
            vlSelf->i2s_capture_24_tb__DOT__sd_i = 0U;
            vlSelf->i2s_capture_24_tb__DOT__current_pattern 
                = ((IData)(vlSelf->i2s_capture_24_tb__DOT__ws_reg)
                    ? vlSelf->i2s_capture_24_tb__DOT__right_pattern_1
                    : vlSelf->i2s_capture_24_tb__DOT__left_pattern_1);
        } else if (vlSelf->i2s_capture_24_tb__DOT__sck_falling) {
            vlSelf->i2s_capture_24_tb__DOT__new_channel = 0U;
            if ((0x18U > (IData)(vlSelf->i2s_capture_24_tb__DOT__bit_index))) {
                vlSelf->i2s_capture_24_tb__DOT__sd_i 
                    = ((0x17U >= (0x1fU & ((IData)(0x17U) 
                                           - (IData)(vlSelf->i2s_capture_24_tb__DOT__bit_index)))) 
                       && (1U & (vlSelf->i2s_capture_24_tb__DOT__current_pattern 
                                 >> (0x1fU & ((IData)(0x17U) 
                                              - (IData)(vlSelf->i2s_capture_24_tb__DOT__bit_index))))));
                __Vdly__i2s_capture_24_tb__DOT__bit_index 
                    = (0x1fU & ((IData)(1U) + (IData)(vlSelf->i2s_capture_24_tb__DOT__bit_index)));
            } else {
                if ((0x19U > (IData)(vlSelf->i2s_capture_24_tb__DOT__bit_index))) {
                    __Vdly__i2s_capture_24_tb__DOT__bit_index 
                        = (0x1fU & ((IData)(1U) + (IData)(vlSelf->i2s_capture_24_tb__DOT__bit_index)));
                }
                vlSelf->i2s_capture_24_tb__DOT__sd_i = 0U;
            }
        }
        if (vlSelf->i2s_capture_24_tb__DOT__dut__DOT__ws_edge) {
            vlSelf->i2s_capture_24_tb__DOT__dut__DOT__channel_q 
                = vlSelf->i2s_capture_24_tb__DOT__ws_reg;
        }
        if (((IData)(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__left_done_q) 
             & (IData)(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__right_done_q))) {
            vlSelf->i2s_capture_24_tb__DOT__ready_o = 1U;
            __Vdly__i2s_capture_24_tb__DOT__dut__DOT__left_done_q = 0U;
            __Vdly__i2s_capture_24_tb__DOT__dut__DOT__right_done_q = 0U;
        }
    } else {
        __Vdly__i2s_capture_24_tb__DOT__sck_reg = 0U;
        __Vdly__i2s_capture_24_tb__DOT__sck_counter = 0U;
        __Vdly__i2s_capture_24_tb__DOT__ws_reg = 0U;
        __Vdly__i2s_capture_24_tb__DOT__sck_edge_counter = 0U;
        vlSelf->i2s_capture_24_tb__DOT__new_channel = 0U;
        __Vdly__i2s_capture_24_tb__DOT__dut__DOT__left_done_q = 0U;
        __Vdly__i2s_capture_24_tb__DOT__dut__DOT__right_done_q = 0U;
        __Vdly__i2s_capture_24_tb__DOT__dut__DOT__shift25_q = 0U;
        __Vdly__i2s_capture_24_tb__DOT__dut__DOT__cnt_q = 0U;
        vlSelf->i2s_capture_24_tb__DOT__left_o = 0U;
        vlSelf->i2s_capture_24_tb__DOT__right_o = 0U;
        vlSelf->i2s_capture_24_tb__DOT__ready_o = 0U;
        vlSelf->i2s_capture_24_tb__DOT__dut__DOT__channel_q = 0U;
        __Vdly__i2s_capture_24_tb__DOT__bit_index = 0U;
        vlSelf->i2s_capture_24_tb__DOT__sd_i = 0U;
        vlSelf->i2s_capture_24_tb__DOT__current_pattern 
            = vlSelf->i2s_capture_24_tb__DOT__left_pattern_1;
    }
    vlSelf->i2s_capture_24_tb__DOT__dut__DOT__ws_d 
        = ((IData)(vlSelf->i2s_capture_24_tb__DOT__rst_ni) 
           && (IData)(vlSelf->i2s_capture_24_tb__DOT__ws_reg));
    vlSelf->i2s_capture_24_tb__DOT__ws_prev = ((IData)(vlSelf->i2s_capture_24_tb__DOT__rst_ni) 
                                               && (IData)(vlSelf->i2s_capture_24_tb__DOT__ws_reg));
    vlSelf->i2s_capture_24_tb__DOT__sck_counter = __Vdly__i2s_capture_24_tb__DOT__sck_counter;
    vlSelf->i2s_capture_24_tb__DOT__sck_edge_counter 
        = __Vdly__i2s_capture_24_tb__DOT__sck_edge_counter;
    vlSelf->i2s_capture_24_tb__DOT__sck_prev = ((IData)(vlSelf->i2s_capture_24_tb__DOT__rst_ni) 
                                                && (IData)(vlSelf->i2s_capture_24_tb__DOT__sck_reg));
    vlSelf->i2s_capture_24_tb__DOT__dut__DOT__cnt_q 
        = __Vdly__i2s_capture_24_tb__DOT__dut__DOT__cnt_q;
    vlSelf->i2s_capture_24_tb__DOT__dut__DOT__shift25_q 
        = __Vdly__i2s_capture_24_tb__DOT__dut__DOT__shift25_q;
    vlSelf->i2s_capture_24_tb__DOT__dut__DOT__right_done_q 
        = __Vdly__i2s_capture_24_tb__DOT__dut__DOT__right_done_q;
    vlSelf->i2s_capture_24_tb__DOT__dut__DOT__left_done_q 
        = __Vdly__i2s_capture_24_tb__DOT__dut__DOT__left_done_q;
    vlSelf->i2s_capture_24_tb__DOT__dut__DOT__sck_d 
        = ((IData)(vlSelf->i2s_capture_24_tb__DOT__rst_ni) 
           && (IData)(vlSelf->i2s_capture_24_tb__DOT__sck_reg));
    vlSelf->i2s_capture_24_tb__DOT__sck_reg = __Vdly__i2s_capture_24_tb__DOT__sck_reg;
    vlSelf->i2s_capture_24_tb__DOT__bit_index = __Vdly__i2s_capture_24_tb__DOT__bit_index;
    vlSelf->i2s_capture_24_tb__DOT__sck_falling = (
                                                   (~ (IData)(vlSelf->i2s_capture_24_tb__DOT__sck_reg)) 
                                                   & (IData)(vlSelf->i2s_capture_24_tb__DOT__sck_prev));
    vlSelf->i2s_capture_24_tb__DOT__ws_reg = __Vdly__i2s_capture_24_tb__DOT__ws_reg;
    vlSelf->i2s_capture_24_tb__DOT__ws_edge_det = ((IData)(vlSelf->i2s_capture_24_tb__DOT__ws_reg) 
                                                   != (IData)(vlSelf->i2s_capture_24_tb__DOT__ws_prev));
    vlSelf->i2s_capture_24_tb__DOT__dut__DOT__ws_edge 
        = ((IData)(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__ws_d) 
           != (IData)(vlSelf->i2s_capture_24_tb__DOT__ws_reg));
}

void Vi2s_capture_24_tb___024root___eval_nba(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vi2s_capture_24_tb___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
}

void Vi2s_capture_24_tb___024root___timing_resume(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___timing_resume\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_he7b63118__0.resume("@(posedge i2s_capture_24_tb.clk_i)");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h8d69a51b__0.resume("@([changed] i2s_capture_24_tb.ready_o)");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h1a61c2e8__0.resume("@([changed] (~ i2s_capture_24_tb.ready_o))");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vi2s_capture_24_tb___024root___timing_commit(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_he7b63118__0.commit("@(posedge i2s_capture_24_tb.clk_i)");
    }
    if ((! (4ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h8d69a51b__0.commit("@([changed] i2s_capture_24_tb.ready_o)");
    }
    if ((! (8ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h1a61c2e8__0.commit("@([changed] (~ i2s_capture_24_tb.ready_o))");
    }
}

void Vi2s_capture_24_tb___024root___eval_triggers__act(Vi2s_capture_24_tb___024root* vlSelf);

bool Vi2s_capture_24_tb___024root___eval_phase__act(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vi2s_capture_24_tb___024root___eval_triggers__act(vlSelf);
    Vi2s_capture_24_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vi2s_capture_24_tb___024root___timing_resume(vlSelf);
        Vi2s_capture_24_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vi2s_capture_24_tb___024root___eval_phase__nba(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vi2s_capture_24_tb___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vi2s_capture_24_tb___024root___dump_triggers__nba(Vi2s_capture_24_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vi2s_capture_24_tb___024root___dump_triggers__act(Vi2s_capture_24_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vi2s_capture_24_tb___024root___eval(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vi2s_capture_24_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../../digital/sampler/i2s_capture_24_tb.sv", 15, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vi2s_capture_24_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../../digital/sampler/i2s_capture_24_tb.sv", 15, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vi2s_capture_24_tb___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vi2s_capture_24_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vi2s_capture_24_tb___024root___eval_debug_assertions(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
