// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vi2s_integration_tb.h for the primary calling header

#include "Vi2s_integration_tb__pch.h"
#include "Vi2s_integration_tb__Syms.h"
#include "Vi2s_integration_tb___024root.h"

extern const VlWide<12>/*383:0*/ Vi2s_integration_tb__ConstPool__CONST_h5e13e486_0;

VL_ATTR_COLD void Vi2s_integration_tb___024root___eval_initial__TOP(Vi2s_integration_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root___eval_initial__TOP\n"); );
    // Body
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(12, Vi2s_integration_tb__ConstPool__CONST_h5e13e486_0));
    vlSymsp->_traceDumpOpen();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vi2s_integration_tb___024root___dump_triggers__stl(Vi2s_integration_tb___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vi2s_integration_tb___024root___eval_triggers__stl(Vi2s_integration_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vi2s_integration_tb___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
