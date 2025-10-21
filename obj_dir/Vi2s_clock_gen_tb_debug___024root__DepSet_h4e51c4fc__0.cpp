// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vi2s_clock_gen_tb_debug.h for the primary calling header

#include "Vi2s_clock_gen_tb_debug__pch.h"
#include "Vi2s_clock_gen_tb_debug___024root.h"

VlCoroutine Vi2s_clock_gen_tb_debug___024root___eval_initial__TOP__Vtiming__0(Vi2s_clock_gen_tb_debug___024root* vlSelf);
VlCoroutine Vi2s_clock_gen_tb_debug___024root___eval_initial__TOP__Vtiming__1(Vi2s_clock_gen_tb_debug___024root* vlSelf);

void Vi2s_clock_gen_tb_debug___024root___eval_initial(Vi2s_clock_gen_tb_debug___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_debug___024root___eval_initial\n"); );
    // Body
    Vi2s_clock_gen_tb_debug___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vi2s_clock_gen_tb_debug___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__i2s_clock_gen_tb_debug__DOT__clk_i__0 
        = vlSelf->i2s_clock_gen_tb_debug__DOT__clk_i;
}

VL_INLINE_OPT VlCoroutine Vi2s_clock_gen_tb_debug___024root___eval_initial__TOP__Vtiming__0(Vi2s_clock_gen_tb_debug___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_debug___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Init
    IData/*31:0*/ i2s_clock_gen_tb_debug__DOT____Vrepeat0;
    i2s_clock_gen_tb_debug__DOT____Vrepeat0 = 0;
    // Body
    vlSelf->i2s_clock_gen_tb_debug__DOT__clk_i = 0U;
    vlSelf->i2s_clock_gen_tb_debug__DOT__rst_ni = 0U;
    co_await vlSelf->__VdlySched.delay(0x64ULL, nullptr, 
                                       "sim/i2s_clock_gen_tb_debug.sv", 
                                       21);
    vlSelf->i2s_clock_gen_tb_debug__DOT__rst_ni = 1U;
    i2s_clock_gen_tb_debug__DOT____Vrepeat0 = 0xc8U;
    while (VL_LTS_III(32, 0U, i2s_clock_gen_tb_debug__DOT____Vrepeat0)) {
        co_await vlSelf->__VtrigSched_h2165eb79__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge i2s_clock_gen_tb_debug.clk_i)", 
                                                           "sim/i2s_clock_gen_tb_debug.sv", 
                                                           25);
        VL_WRITEF("cyc=%0# sck_ctr=%0# sck=%0b ws=%0#\n",
                  64,VL_DIV_QQQ(64, (QData)(VL_TIME_UNITED_Q(1)), 0x25ULL),
                  3,(IData)(vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__sck_ctr_q),
                  1,vlSelf->i2s_clock_gen_tb_debug__DOT__sck_o,
                  1,(IData)(vlSelf->i2s_clock_gen_tb_debug__DOT__ws_o));
        i2s_clock_gen_tb_debug__DOT____Vrepeat0 = (i2s_clock_gen_tb_debug__DOT____Vrepeat0 
                                                   - (IData)(1U));
    }
    VL_FINISH_MT("sim/i2s_clock_gen_tb_debug.sv", 30, "");
}

VL_INLINE_OPT VlCoroutine Vi2s_clock_gen_tb_debug___024root___eval_initial__TOP__Vtiming__1(Vi2s_clock_gen_tb_debug___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_debug___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x13ULL, 
                                           nullptr, 
                                           "sim/i2s_clock_gen_tb_debug.sv", 
                                           16);
        vlSelf->i2s_clock_gen_tb_debug__DOT__clk_i 
            = (1U & (~ (IData)(vlSelf->i2s_clock_gen_tb_debug__DOT__clk_i)));
    }
}

VL_INLINE_OPT void Vi2s_clock_gen_tb_debug___024root___act_comb__TOP__0(Vi2s_clock_gen_tb_debug___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_debug___024root___act_comb__TOP__0\n"); );
    // Body
    vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__clk_i 
        = vlSelf->i2s_clock_gen_tb_debug__DOT__clk_i;
    vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__rst_ni 
        = vlSelf->i2s_clock_gen_tb_debug__DOT__rst_ni;
}

void Vi2s_clock_gen_tb_debug___024root___eval_act(Vi2s_clock_gen_tb_debug___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_debug___024root___eval_act\n"); );
    // Body
    if ((3ULL & vlSelf->__VactTriggered.word(0U))) {
        Vi2s_clock_gen_tb_debug___024root___act_comb__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*2:0*/, 32> Vi2s_clock_gen_tb_debug__ConstPool__TABLE_hb31b5e30_0;
extern const VlUnpacked<CData/*1:0*/, 32> Vi2s_clock_gen_tb_debug__ConstPool__TABLE_h11502f1d_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vi2s_clock_gen_tb_debug__ConstPool__TABLE_h56c82868_0;

VL_INLINE_OPT void Vi2s_clock_gen_tb_debug___024root___nba_sequent__TOP__0(Vi2s_clock_gen_tb_debug___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_debug___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*0:0*/ __Vdly__i2s_clock_gen_tb_debug__DOT__dut__DOT__sck_q;
    __Vdly__i2s_clock_gen_tb_debug__DOT__dut__DOT__sck_q = 0;
    CData/*0:0*/ __Vdly__i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_q;
    __Vdly__i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_q = 0;
    CData/*5:0*/ __Vdly__i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_ctr_q;
    __Vdly__i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_ctr_q = 0;
    // Body
    __Vdly__i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_ctr_q 
        = vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_ctr_q;
    __Vdly__i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_q 
        = vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_q;
    __Vdly__i2s_clock_gen_tb_debug__DOT__dut__DOT__sck_q 
        = vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__sck_q;
    __Vtableidx1 = (((IData)(vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__sck_ctr_q) 
                     << 2U) | (((IData)(vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__sck_q) 
                                << 1U) | (IData)(vlSelf->i2s_clock_gen_tb_debug__DOT__rst_ni)));
    vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__sck_ctr_q 
        = Vi2s_clock_gen_tb_debug__ConstPool__TABLE_hb31b5e30_0
        [__Vtableidx1];
    if ((2U & Vi2s_clock_gen_tb_debug__ConstPool__TABLE_h11502f1d_0
         [__Vtableidx1])) {
        __Vdly__i2s_clock_gen_tb_debug__DOT__dut__DOT__sck_q 
            = Vi2s_clock_gen_tb_debug__ConstPool__TABLE_h56c82868_0
            [__Vtableidx1];
    }
    vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__sck_prev_q 
        = ((IData)(vlSelf->i2s_clock_gen_tb_debug__DOT__rst_ni) 
           && (IData)(vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__sck_q));
    if (vlSelf->i2s_clock_gen_tb_debug__DOT__rst_ni) {
        vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__frame_start_q = 0U;
        if (vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__sck_falling_edge) {
            if ((0x3fU == (IData)(vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_ctr_q))) {
                __Vdly__i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_q 
                    = (1U & (~ (IData)(vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_q)));
                __Vdly__i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_ctr_q = 0U;
                if (vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_q) {
                    vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__frame_start_q = 1U;
                }
            } else {
                __Vdly__i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_ctr_q 
                    = (0x3fU & ((IData)(1U) + (IData)(vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_ctr_q)));
            }
        }
    } else {
        __Vdly__i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_ctr_q = 0U;
        __Vdly__i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_q = 0U;
        vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__frame_start_q = 0U;
    }
    vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__sck_q 
        = __Vdly__i2s_clock_gen_tb_debug__DOT__dut__DOT__sck_q;
    vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_ctr_q 
        = __Vdly__i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_ctr_q;
    vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_q 
        = __Vdly__i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_q;
    vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__sck_falling_edge 
        = ((~ (IData)(vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__sck_q)) 
           & (IData)(vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__sck_prev_q));
    vlSelf->i2s_clock_gen_tb_debug__DOT__sck_o = vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__sck_q;
    vlSelf->i2s_clock_gen_tb_debug__DOT__frame_start_o 
        = vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__frame_start_q;
    vlSelf->i2s_clock_gen_tb_debug__DOT__ws_o = vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_q;
    vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__sck_o 
        = vlSelf->i2s_clock_gen_tb_debug__DOT__sck_o;
    vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__frame_start_o 
        = vlSelf->i2s_clock_gen_tb_debug__DOT__frame_start_o;
    vlSelf->i2s_clock_gen_tb_debug__DOT__dut__DOT__ws_o 
        = vlSelf->i2s_clock_gen_tb_debug__DOT__ws_o;
}

void Vi2s_clock_gen_tb_debug___024root___eval_nba(Vi2s_clock_gen_tb_debug___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_debug___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vi2s_clock_gen_tb_debug___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vi2s_clock_gen_tb_debug___024root___act_comb__TOP__0(vlSelf);
    }
}

void Vi2s_clock_gen_tb_debug___024root___timing_resume(Vi2s_clock_gen_tb_debug___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_debug___024root___timing_resume\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h2165eb79__0.resume("@(posedge i2s_clock_gen_tb_debug.clk_i)");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vi2s_clock_gen_tb_debug___024root___timing_commit(Vi2s_clock_gen_tb_debug___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_debug___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h2165eb79__0.commit("@(posedge i2s_clock_gen_tb_debug.clk_i)");
    }
}

void Vi2s_clock_gen_tb_debug___024root___eval_triggers__act(Vi2s_clock_gen_tb_debug___024root* vlSelf);

bool Vi2s_clock_gen_tb_debug___024root___eval_phase__act(Vi2s_clock_gen_tb_debug___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_debug___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vi2s_clock_gen_tb_debug___024root___eval_triggers__act(vlSelf);
    Vi2s_clock_gen_tb_debug___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vi2s_clock_gen_tb_debug___024root___timing_resume(vlSelf);
        Vi2s_clock_gen_tb_debug___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vi2s_clock_gen_tb_debug___024root___eval_phase__nba(Vi2s_clock_gen_tb_debug___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_debug___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vi2s_clock_gen_tb_debug___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vi2s_clock_gen_tb_debug___024root___dump_triggers__nba(Vi2s_clock_gen_tb_debug___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vi2s_clock_gen_tb_debug___024root___dump_triggers__act(Vi2s_clock_gen_tb_debug___024root* vlSelf);
#endif  // VL_DEBUG

void Vi2s_clock_gen_tb_debug___024root___eval(Vi2s_clock_gen_tb_debug___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_debug___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vi2s_clock_gen_tb_debug___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("sim/i2s_clock_gen_tb_debug.sv", 2, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vi2s_clock_gen_tb_debug___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("sim/i2s_clock_gen_tb_debug.sv", 2, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vi2s_clock_gen_tb_debug___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vi2s_clock_gen_tb_debug___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vi2s_clock_gen_tb_debug___024root___eval_debug_assertions(Vi2s_clock_gen_tb_debug___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_debug___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
