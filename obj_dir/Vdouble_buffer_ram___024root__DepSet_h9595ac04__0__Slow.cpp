// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdouble_buffer_ram.h for the primary calling header

#include "Vdouble_buffer_ram__pch.h"
#include "Vdouble_buffer_ram__Syms.h"
#include "Vdouble_buffer_ram___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdouble_buffer_ram___024root___dump_triggers__stl(Vdouble_buffer_ram___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdouble_buffer_ram___024root___eval_triggers__stl(Vdouble_buffer_ram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdouble_buffer_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdouble_buffer_ram___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdouble_buffer_ram___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
