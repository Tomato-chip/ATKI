// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpga_template_top_tb.h for the primary calling header

#include "Vfpga_template_top_tb__pch.h"
#include "Vfpga_template_top_tb__Syms.h"
#include "Vfpga_template_top_tb___024root.h"

VL_ATTR_COLD void Vfpga_template_top_tb___024root___eval_initial__TOP(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<6>/*191:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x705f7462U;
    __Vtemp_1[2U] = 0x655f746fU;
    __Vtemp_1[3U] = 0x706c6174U;
    __Vtemp_1[4U] = 0x5f74656dU;
    __Vtemp_1[5U] = 0x66706761U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(6, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSymsp->_traceDumpOpen();
    vlSymsp->_traceDumpOpen();
    vlSymsp->_traceDumpOpen();
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__i = 0U;
    while (VL_GTS_III(32, 0x200U, vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__i)) {
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem[(0x1ffU 
                                                                                & vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__i)] = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__i 
            = ((IData)(1U) + vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__i);
    }
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_data_out = 0U;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__do_pipeline = 0U;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x200U, vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__i)) {
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem[(0x1ffU 
                                                                                & vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__i)] = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__i 
            = ((IData)(1U) + vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__i);
    }
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_data_out = 0U;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__do_pipeline = 0U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpga_template_top_tb___024root___dump_triggers__stl(Vfpga_template_top_tb___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfpga_template_top_tb___024root___eval_triggers__stl(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vfpga_template_top_tb___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
