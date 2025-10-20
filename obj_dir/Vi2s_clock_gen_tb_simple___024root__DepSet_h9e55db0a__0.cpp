// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vi2s_clock_gen_tb_simple.h for the primary calling header

#include "Vi2s_clock_gen_tb_simple__pch.h"
#include "Vi2s_clock_gen_tb_simple__Syms.h"
#include "Vi2s_clock_gen_tb_simple___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vi2s_clock_gen_tb_simple___024root___dump_triggers__act(Vi2s_clock_gen_tb_simple___024root* vlSelf);
#endif  // VL_DEBUG

void Vi2s_clock_gen_tb_simple___024root___eval_triggers__act(Vi2s_clock_gen_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_simple___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->i2s_clock_gen_tb_simple__DOT__clk_i) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__i2s_clock_gen_tb_simple__DOT__clk_i__0))));
    vlSelf->__VactTriggered.set(1U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__i2s_clock_gen_tb_simple__DOT__clk_i__0 
        = vlSelf->i2s_clock_gen_tb_simple__DOT__clk_i;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vi2s_clock_gen_tb_simple___024root___dump_triggers__act(vlSelf);
    }
#endif
}
