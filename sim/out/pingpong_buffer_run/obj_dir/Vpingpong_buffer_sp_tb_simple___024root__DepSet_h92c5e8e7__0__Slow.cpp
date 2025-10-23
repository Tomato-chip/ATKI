// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpingpong_buffer_sp_tb_simple.h for the primary calling header

#include "Vpingpong_buffer_sp_tb_simple__pch.h"
#include "Vpingpong_buffer_sp_tb_simple__Syms.h"
#include "Vpingpong_buffer_sp_tb_simple___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpingpong_buffer_sp_tb_simple___024root___dump_triggers__stl(Vpingpong_buffer_sp_tb_simple___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vpingpong_buffer_sp_tb_simple___024root___eval_triggers__stl(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
    vlSelf->__VstlTriggered.set(1U, (vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram0__DO 
                                     != vlSelf->__Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram0__DO__0));
    vlSelf->__VstlTriggered.set(2U, (vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram1__DO 
                                     != vlSelf->__Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram1__DO__0));
    vlSelf->__Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram0__DO__0 
        = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram0__DO;
    vlSelf->__Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram1__DO__0 
        = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram1__DO;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VstlDidInit))))) {
        vlSelf->__VstlDidInit = 1U;
        vlSelf->__VstlTriggered.set(1U, 1U);
        vlSelf->__VstlTriggered.set(2U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vpingpong_buffer_sp_tb_simple___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
