// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vi2s_integration_tb.h for the primary calling header

#include "Vi2s_integration_tb__pch.h"
#include "Vi2s_integration_tb__Syms.h"
#include "Vi2s_integration_tb___024root.h"

VL_INLINE_OPT VlCoroutine Vi2s_integration_tb___024root___eval_initial__TOP__Vtiming__2(Vi2s_integration_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0x174876e800ULL, 
                                       nullptr, "i2s_integration_tb.sv", 
                                       344);
    VL_WRITEF("[%0t] %%Error: i2s_integration_tb.sv:345: Assertion failed in %Ni2s_integration_tb: [TIMEOUT] Simulation exceeded maximum time\n",
              64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
    VL_STOP_MT("i2s_integration_tb.sv", 345, "");
    VL_FINISH_MT("i2s_integration_tb.sv", 346, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vi2s_integration_tb___024root___dump_triggers__act(Vi2s_integration_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vi2s_integration_tb___024root___eval_triggers__act(Vi2s_integration_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root___eval_triggers__act\n"); );
    // Body
    CData/*0:0*/ __Vtrigcurrexpr_h39b803dc__0;
    __Vtrigcurrexpr_h39b803dc__0 = 0;
    __Vtrigcurrexpr_h39b803dc__0 = (1U & (~ (IData)(vlSelf->i2s_integration_tb__DOT__ready_o)));
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->i2s_integration_tb__DOT__clk_i) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__i2s_integration_tb__DOT__clk_i__0))));
    vlSelf->__VactTriggered.set(1U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__VactTriggered.set(2U, ((IData)(vlSelf->i2s_integration_tb__DOT__ready_o) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__i2s_integration_tb__DOT__ready_o__0)));
    vlSelf->__VactTriggered.set(3U, ((IData)(__Vtrigcurrexpr_h39b803dc__0) 
                                     != (IData)(vlSelf->__Vtrigprevexpr_h39b803dc__0)));
    vlSelf->__Vtrigprevexpr___TOP__i2s_integration_tb__DOT__clk_i__0 
        = vlSelf->i2s_integration_tb__DOT__clk_i;
    vlSelf->__Vtrigprevexpr___TOP__i2s_integration_tb__DOT__ready_o__0 
        = vlSelf->i2s_integration_tb__DOT__ready_o;
    vlSelf->__Vtrigprevexpr_h39b803dc__0 = __Vtrigcurrexpr_h39b803dc__0;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.set(2U, 1U);
        vlSelf->__VactTriggered.set(3U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vi2s_integration_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}

extern const VlUnpacked<CData/*2:0*/, 32> Vi2s_integration_tb__ConstPool__TABLE_hb31b5e30_0;
extern const VlUnpacked<CData/*1:0*/, 32> Vi2s_integration_tb__ConstPool__TABLE_h11502f1d_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vi2s_integration_tb__ConstPool__TABLE_h56c82868_0;

VL_INLINE_OPT void Vi2s_integration_tb___024root___nba_sequent__TOP__0(Vi2s_integration_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    IData/*31:0*/ __Vdly__i2s_integration_tb__DOT__bit_index;
    __Vdly__i2s_integration_tb__DOT__bit_index = 0;
    IData/*31:0*/ __Vdly__i2s_integration_tb__DOT__error_count;
    __Vdly__i2s_integration_tb__DOT__error_count = 0;
    CData/*0:0*/ __Vdly__i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q;
    __Vdly__i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q = 0;
    CData/*0:0*/ __Vdly__i2s_integration_tb__DOT__u_clk_gen__DOT__ws_q;
    __Vdly__i2s_integration_tb__DOT__u_clk_gen__DOT__ws_q = 0;
    CData/*5:0*/ __Vdly__i2s_integration_tb__DOT__u_clk_gen__DOT__ws_ctr_q;
    __Vdly__i2s_integration_tb__DOT__u_clk_gen__DOT__ws_ctr_q = 0;
    CData/*5:0*/ __Vdly__i2s_integration_tb__DOT__u_capture__DOT__cnt_q;
    __Vdly__i2s_integration_tb__DOT__u_capture__DOT__cnt_q = 0;
    IData/*24:0*/ __Vdly__i2s_integration_tb__DOT__u_capture__DOT__shift25_q;
    __Vdly__i2s_integration_tb__DOT__u_capture__DOT__shift25_q = 0;
    CData/*0:0*/ __Vdly__i2s_integration_tb__DOT__u_capture__DOT__right_done_q;
    __Vdly__i2s_integration_tb__DOT__u_capture__DOT__right_done_q = 0;
    CData/*0:0*/ __Vdly__i2s_integration_tb__DOT__u_capture__DOT__left_done_q;
    __Vdly__i2s_integration_tb__DOT__u_capture__DOT__left_done_q = 0;
    // Body
    __Vdly__i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q 
        = vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q;
    __Vdly__i2s_integration_tb__DOT__bit_index = vlSelf->i2s_integration_tb__DOT__bit_index;
    __Vdly__i2s_integration_tb__DOT__u_clk_gen__DOT__ws_ctr_q 
        = vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__ws_ctr_q;
    __Vdly__i2s_integration_tb__DOT__u_clk_gen__DOT__ws_q 
        = vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__ws_q;
    __Vdly__i2s_integration_tb__DOT__u_capture__DOT__left_done_q 
        = vlSelf->i2s_integration_tb__DOT__u_capture__DOT__left_done_q;
    __Vdly__i2s_integration_tb__DOT__u_capture__DOT__right_done_q 
        = vlSelf->i2s_integration_tb__DOT__u_capture__DOT__right_done_q;
    __Vdly__i2s_integration_tb__DOT__u_capture__DOT__shift25_q 
        = vlSelf->i2s_integration_tb__DOT__u_capture__DOT__shift25_q;
    __Vdly__i2s_integration_tb__DOT__u_capture__DOT__cnt_q 
        = vlSelf->i2s_integration_tb__DOT__u_capture__DOT__cnt_q;
    __Vdly__i2s_integration_tb__DOT__error_count = vlSelf->i2s_integration_tb__DOT__error_count;
    __Vtableidx1 = (((IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_ctr_q) 
                     << 2U) | (((IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q) 
                                << 1U) | (IData)(vlSelf->i2s_integration_tb__DOT__rst_ni)));
    vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_ctr_q 
        = Vi2s_integration_tb__ConstPool__TABLE_hb31b5e30_0
        [__Vtableidx1];
    if ((2U & Vi2s_integration_tb__ConstPool__TABLE_h11502f1d_0
         [__Vtableidx1])) {
        __Vdly__i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q 
            = Vi2s_integration_tb__ConstPool__TABLE_h56c82868_0
            [__Vtableidx1];
    }
    if (vlSelf->i2s_integration_tb__DOT__rst_ni) {
        if ((1U & (~ (IData)(vlSelf->i2s_integration_tb__DOT__init_done)))) {
            vlSelf->i2s_integration_tb__DOT__init_done = 1U;
        }
        if (vlSelf->i2s_integration_tb__DOT__ws_edge) {
            __Vdly__i2s_integration_tb__DOT__bit_index = 0x18U;
        } else if (((~ (IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q)) 
                    & (IData)(vlSelf->i2s_integration_tb__DOT__sck_prev))) {
            __Vdly__i2s_integration_tb__DOT__bit_index 
                = ((0U < vlSelf->i2s_integration_tb__DOT__bit_index)
                    ? (vlSelf->i2s_integration_tb__DOT__bit_index 
                       - (IData)(1U)) : 0x18U);
        }
    } else {
        vlSelf->i2s_integration_tb__DOT__init_done = 0U;
        __Vdly__i2s_integration_tb__DOT__bit_index = 0x18U;
    }
    if (vlSelf->i2s_integration_tb__DOT__rst_ni) {
        if (vlSelf->i2s_integration_tb__DOT__ready_o) {
            vlSelf->i2s_integration_tb__DOT__ready_count 
                = ((IData)(1U) + vlSelf->i2s_integration_tb__DOT__ready_count);
            if (vlSelf->i2s_integration_tb__DOT__check_enable) {
                if ((0U == vlSelf->i2s_integration_tb__DOT__test_num)) {
                    if (VL_UNLIKELY((0xa5a5a5U != vlSelf->i2s_integration_tb__DOT__left_o))) {
                        VL_WRITEF("[%0t] %%Error: i2s_integration_tb.sv:193: Assertion failed in %Ni2s_integration_tb: [FAIL] Test %0#: Left channel mismatch. Expected 0xa5a5a5, got 0x%06x\n",
                                  64,VL_TIME_UNITED_Q(1000),
                                  -9,vlSymsp->name(),
                                  32,vlSelf->i2s_integration_tb__DOT__test_num,
                                  24,vlSelf->i2s_integration_tb__DOT__left_o);
                        __Vdly__i2s_integration_tb__DOT__error_count 
                            = ((IData)(1U) + vlSelf->i2s_integration_tb__DOT__error_count);
                        VL_STOP_MT("i2s_integration_tb.sv", 193, "");
                    } else {
                        VL_WRITEF("[PASS] Test %0#: Left channel = 0x%06x \342\234\223\n",
                                  32,vlSelf->i2s_integration_tb__DOT__test_num,
                                  24,vlSelf->i2s_integration_tb__DOT__left_o);
                    }
                    if (VL_UNLIKELY((0x5a5a5aU != vlSelf->i2s_integration_tb__DOT__right_o))) {
                        VL_WRITEF("[%0t] %%Error: i2s_integration_tb.sv:201: Assertion failed in %Ni2s_integration_tb: [FAIL] Test %0#: Right channel mismatch. Expected 0x5a5a5a, got 0x%06x\n",
                                  64,VL_TIME_UNITED_Q(1000),
                                  -9,vlSymsp->name(),
                                  32,vlSelf->i2s_integration_tb__DOT__test_num,
                                  24,vlSelf->i2s_integration_tb__DOT__right_o);
                        __Vdly__i2s_integration_tb__DOT__error_count 
                            = ((IData)(1U) + vlSelf->i2s_integration_tb__DOT__error_count);
                        VL_STOP_MT("i2s_integration_tb.sv", 201, "");
                    } else {
                        VL_WRITEF("[PASS] Test %0#: Right channel = 0x%06x \342\234\223\n",
                                  32,vlSelf->i2s_integration_tb__DOT__test_num,
                                  24,vlSelf->i2s_integration_tb__DOT__right_o);
                    }
                } else if ((1U == vlSelf->i2s_integration_tb__DOT__test_num)) {
                    if (VL_UNLIKELY((0x123456U != vlSelf->i2s_integration_tb__DOT__left_o))) {
                        VL_WRITEF("[%0t] %%Error: i2s_integration_tb.sv:211: Assertion failed in %Ni2s_integration_tb: [FAIL] Test %0#: Left channel mismatch. Expected 0x123456, got 0x%06x\n",
                                  64,VL_TIME_UNITED_Q(1000),
                                  -9,vlSymsp->name(),
                                  32,vlSelf->i2s_integration_tb__DOT__test_num,
                                  24,vlSelf->i2s_integration_tb__DOT__left_o);
                        __Vdly__i2s_integration_tb__DOT__error_count 
                            = ((IData)(1U) + vlSelf->i2s_integration_tb__DOT__error_count);
                        VL_STOP_MT("i2s_integration_tb.sv", 211, "");
                    } else {
                        VL_WRITEF("[PASS] Test %0#: Left channel = 0x%06x \342\234\223\n",
                                  32,vlSelf->i2s_integration_tb__DOT__test_num,
                                  24,vlSelf->i2s_integration_tb__DOT__left_o);
                    }
                    if (VL_UNLIKELY((0x789abcU != vlSelf->i2s_integration_tb__DOT__right_o))) {
                        VL_WRITEF("[%0t] %%Error: i2s_integration_tb.sv:219: Assertion failed in %Ni2s_integration_tb: [FAIL] Test %0#: Right channel mismatch. Expected 0x789abc, got 0x%06x\n",
                                  64,VL_TIME_UNITED_Q(1000),
                                  -9,vlSymsp->name(),
                                  32,vlSelf->i2s_integration_tb__DOT__test_num,
                                  24,vlSelf->i2s_integration_tb__DOT__right_o);
                        __Vdly__i2s_integration_tb__DOT__error_count 
                            = ((IData)(1U) + vlSelf->i2s_integration_tb__DOT__error_count);
                        VL_STOP_MT("i2s_integration_tb.sv", 219, "");
                    } else {
                        VL_WRITEF("[PASS] Test %0#: Right channel = 0x%06x \342\234\223\n",
                                  32,vlSelf->i2s_integration_tb__DOT__test_num,
                                  24,vlSelf->i2s_integration_tb__DOT__right_o);
                    }
                } else if ((2U == vlSelf->i2s_integration_tb__DOT__test_num)) {
                    if (VL_UNLIKELY((0xdef012U != vlSelf->i2s_integration_tb__DOT__left_o))) {
                        VL_WRITEF("[%0t] %%Error: i2s_integration_tb.sv:229: Assertion failed in %Ni2s_integration_tb: [FAIL] Test %0#: Left channel mismatch. Expected 0xdef012, got 0x%06x\n",
                                  64,VL_TIME_UNITED_Q(1000),
                                  -9,vlSymsp->name(),
                                  32,vlSelf->i2s_integration_tb__DOT__test_num,
                                  24,vlSelf->i2s_integration_tb__DOT__left_o);
                        __Vdly__i2s_integration_tb__DOT__error_count 
                            = ((IData)(1U) + vlSelf->i2s_integration_tb__DOT__error_count);
                        VL_STOP_MT("i2s_integration_tb.sv", 229, "");
                    } else {
                        VL_WRITEF("[PASS] Test %0#: Left channel = 0x%06x \342\234\223\n",
                                  32,vlSelf->i2s_integration_tb__DOT__test_num,
                                  24,vlSelf->i2s_integration_tb__DOT__left_o);
                    }
                    if (VL_UNLIKELY((0x345678U != vlSelf->i2s_integration_tb__DOT__right_o))) {
                        VL_WRITEF("[%0t] %%Error: i2s_integration_tb.sv:237: Assertion failed in %Ni2s_integration_tb: [FAIL] Test %0#: Right channel mismatch. Expected 0x345678, got 0x%06x\n",
                                  64,VL_TIME_UNITED_Q(1000),
                                  -9,vlSymsp->name(),
                                  32,vlSelf->i2s_integration_tb__DOT__test_num,
                                  24,vlSelf->i2s_integration_tb__DOT__right_o);
                        __Vdly__i2s_integration_tb__DOT__error_count 
                            = ((IData)(1U) + vlSelf->i2s_integration_tb__DOT__error_count);
                        VL_STOP_MT("i2s_integration_tb.sv", 237, "");
                    } else {
                        VL_WRITEF("[PASS] Test %0#: Right channel = 0x%06x \342\234\223\n",
                                  32,vlSelf->i2s_integration_tb__DOT__test_num,
                                  24,vlSelf->i2s_integration_tb__DOT__right_o);
                    }
                }
            }
        }
    } else {
        vlSelf->i2s_integration_tb__DOT__ready_count = 0U;
        __Vdly__i2s_integration_tb__DOT__error_count = 0U;
    }
    if (vlSelf->i2s_integration_tb__DOT__rst_ni) {
        vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__frame_start_q = 0U;
        if (((~ (IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q)) 
             & (IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_prev_q))) {
            if ((0x1fU == (IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__ws_ctr_q))) {
                __Vdly__i2s_integration_tb__DOT__u_clk_gen__DOT__ws_q 
                    = (1U & (~ (IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__ws_q)));
                __Vdly__i2s_integration_tb__DOT__u_clk_gen__DOT__ws_ctr_q = 0U;
                if (vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__ws_q) {
                    vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__frame_start_q = 1U;
                }
            } else {
                __Vdly__i2s_integration_tb__DOT__u_clk_gen__DOT__ws_ctr_q 
                    = (0x3fU & ((IData)(1U) + (IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__ws_ctr_q)));
            }
        }
        vlSelf->i2s_integration_tb__DOT__ready_o = 0U;
        if ((0x19U == (IData)(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__cnt_q))) {
            if (vlSelf->i2s_integration_tb__DOT__u_capture__DOT__channel_q) {
                vlSelf->i2s_integration_tb__DOT__right_o 
                    = (0xffffffU & vlSelf->i2s_integration_tb__DOT__u_capture__DOT__shift25_q);
                __Vdly__i2s_integration_tb__DOT__u_capture__DOT__right_done_q = 1U;
            } else {
                vlSelf->i2s_integration_tb__DOT__left_o 
                    = (0xffffffU & vlSelf->i2s_integration_tb__DOT__u_capture__DOT__shift25_q);
                __Vdly__i2s_integration_tb__DOT__u_capture__DOT__left_done_q = 1U;
            }
        }
        if (vlSelf->i2s_integration_tb__DOT__u_capture__DOT__ws_edge) {
            __Vdly__i2s_integration_tb__DOT__u_capture__DOT__cnt_q = 0U;
            __Vdly__i2s_integration_tb__DOT__u_capture__DOT__shift25_q = 0U;
            vlSelf->i2s_integration_tb__DOT__u_capture__DOT__channel_q 
                = vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__ws_q;
        } else if (((~ (IData)(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__sck_d)) 
                    & (IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q))) {
            if ((0x19U > (IData)(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__cnt_q))) {
                __Vdly__i2s_integration_tb__DOT__u_capture__DOT__shift25_q 
                    = ((0x1fffffeU & (vlSelf->i2s_integration_tb__DOT__u_capture__DOT__shift25_q 
                                      << 1U)) | ((0x18U 
                                                  >= 
                                                  (0x1fU 
                                                   & vlSelf->i2s_integration_tb__DOT__bit_index)) 
                                                 && (1U 
                                                     & (vlSelf->i2s_integration_tb__DOT__current_pattern 
                                                        >> 
                                                        (0x1fU 
                                                         & vlSelf->i2s_integration_tb__DOT__bit_index)))));
                __Vdly__i2s_integration_tb__DOT__u_capture__DOT__cnt_q 
                    = (0x3fU & ((IData)(1U) + (IData)(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__cnt_q)));
            }
        }
        if (((IData)(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__left_done_q) 
             & (IData)(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__right_done_q))) {
            vlSelf->i2s_integration_tb__DOT__ready_o = 1U;
            __Vdly__i2s_integration_tb__DOT__u_capture__DOT__left_done_q = 0U;
            __Vdly__i2s_integration_tb__DOT__u_capture__DOT__right_done_q = 0U;
        }
        if (vlSelf->i2s_integration_tb__DOT__ws_edge) {
            vlSelf->i2s_integration_tb__DOT__current_pattern 
                = ((IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__ws_q)
                    ? ((0U == vlSelf->i2s_integration_tb__DOT__test_num)
                        ? 0x5a5a5aU : ((1U == vlSelf->i2s_integration_tb__DOT__test_num)
                                        ? 0x789abcU
                                        : ((2U == vlSelf->i2s_integration_tb__DOT__test_num)
                                            ? 0x345678U
                                            : 0x5a5a5aU)))
                    : ((0U == vlSelf->i2s_integration_tb__DOT__test_num)
                        ? 0xa5a5a5U : ((1U == vlSelf->i2s_integration_tb__DOT__test_num)
                                        ? 0x123456U
                                        : ((2U == vlSelf->i2s_integration_tb__DOT__test_num)
                                            ? 0xdef012U
                                            : 0xa5a5a5U))));
        }
    } else {
        __Vdly__i2s_integration_tb__DOT__u_clk_gen__DOT__ws_ctr_q = 0U;
        __Vdly__i2s_integration_tb__DOT__u_clk_gen__DOT__ws_q = 0U;
        vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__frame_start_q = 0U;
        __Vdly__i2s_integration_tb__DOT__u_capture__DOT__left_done_q = 0U;
        __Vdly__i2s_integration_tb__DOT__u_capture__DOT__right_done_q = 0U;
        __Vdly__i2s_integration_tb__DOT__u_capture__DOT__shift25_q = 0U;
        __Vdly__i2s_integration_tb__DOT__u_capture__DOT__cnt_q = 0U;
        vlSelf->i2s_integration_tb__DOT__left_o = 0U;
        vlSelf->i2s_integration_tb__DOT__right_o = 0U;
        vlSelf->i2s_integration_tb__DOT__ready_o = 0U;
        vlSelf->i2s_integration_tb__DOT__u_capture__DOT__channel_q = 0U;
        vlSelf->i2s_integration_tb__DOT__current_pattern = 0xa5a5a5U;
    }
    vlSelf->i2s_integration_tb__DOT__u_capture__DOT__ws_d 
        = ((IData)(vlSelf->i2s_integration_tb__DOT__rst_ni) 
           && (IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__ws_q));
    vlSelf->i2s_integration_tb__DOT__ws_prev = ((IData)(vlSelf->i2s_integration_tb__DOT__rst_ni) 
                                                && (IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__ws_q));
    vlSelf->i2s_integration_tb__DOT__error_count = __Vdly__i2s_integration_tb__DOT__error_count;
    vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__ws_ctr_q 
        = __Vdly__i2s_integration_tb__DOT__u_clk_gen__DOT__ws_ctr_q;
    vlSelf->i2s_integration_tb__DOT__sck_prev = ((IData)(vlSelf->i2s_integration_tb__DOT__rst_ni) 
                                                 && (IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q));
    vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_prev_q 
        = ((IData)(vlSelf->i2s_integration_tb__DOT__rst_ni) 
           && (IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q));
    vlSelf->i2s_integration_tb__DOT__u_capture__DOT__cnt_q 
        = __Vdly__i2s_integration_tb__DOT__u_capture__DOT__cnt_q;
    vlSelf->i2s_integration_tb__DOT__u_capture__DOT__shift25_q 
        = __Vdly__i2s_integration_tb__DOT__u_capture__DOT__shift25_q;
    vlSelf->i2s_integration_tb__DOT__bit_index = __Vdly__i2s_integration_tb__DOT__bit_index;
    vlSelf->i2s_integration_tb__DOT__u_capture__DOT__right_done_q 
        = __Vdly__i2s_integration_tb__DOT__u_capture__DOT__right_done_q;
    vlSelf->i2s_integration_tb__DOT__u_capture__DOT__left_done_q 
        = __Vdly__i2s_integration_tb__DOT__u_capture__DOT__left_done_q;
    vlSelf->i2s_integration_tb__DOT__u_capture__DOT__sck_d 
        = ((IData)(vlSelf->i2s_integration_tb__DOT__rst_ni) 
           && (IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q));
    vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q 
        = __Vdly__i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q;
    vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__ws_q 
        = __Vdly__i2s_integration_tb__DOT__u_clk_gen__DOT__ws_q;
    vlSelf->i2s_integration_tb__DOT__ws_edge = ((IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__ws_q) 
                                                != (IData)(vlSelf->i2s_integration_tb__DOT__ws_prev));
    vlSelf->i2s_integration_tb__DOT__u_capture__DOT__ws_edge 
        = ((IData)(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__ws_d) 
           != (IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__ws_q));
}
