// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsampler.h for the primary calling header

#include "Vsampler__pch.h"
#include "Vsampler__Syms.h"
#include "Vsampler___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsampler___024root___dump_triggers__ico(Vsampler___024root* vlSelf);
#endif  // VL_DEBUG

void Vsampler___024root___eval_triggers__ico(Vsampler___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsampler___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsampler___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsampler___024root___dump_triggers__act(Vsampler___024root* vlSelf);
#endif  // VL_DEBUG

void Vsampler___024root___eval_triggers__act(Vsampler___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsampler___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->clk_i) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk_i__0))));
    vlSelf->__Vtrigprevexpr___TOP__clk_i__0 = vlSelf->clk_i;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsampler___024root___dump_triggers__act(vlSelf);
    }
#endif
}
