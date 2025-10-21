// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpingpong_sp_ram_tb.h for the primary calling header

#include "Vpingpong_sp_ram_tb__pch.h"
#include "Vpingpong_sp_ram_tb__Syms.h"
#include "Vpingpong_sp_ram_tb___024root.h"

VL_ATTR_COLD void Vpingpong_sp_ram_tb___024root___eval_initial__TOP(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___eval_initial__TOP\n"); );
    // Init
    IData/*31:0*/ pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__i;
    pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__i = 0;
    IData/*31:0*/ pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__i;
    pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__i = 0;
    VlWide<6>/*191:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x6d5f7462U;
    __Vtemp_1[2U] = 0x705f7261U;
    __Vtemp_1[3U] = 0x6e675f73U;
    __Vtemp_1[4U] = 0x6e67706fU;
    __Vtemp_1[5U] = 0x7069U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(6, __Vtemp_1));
    VL_PRINTF_MT("-Info: sim/pingpong_sp_ram_tb.sv:245: $dumpvar ignored, as Verilated without --trace\n");
    pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__i = 0U;
    while (VL_GTS_III(32, 0x400U, pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__i)) {
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__mem[(0x3ffU 
                                                                    & pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__i)] = 0U;
        pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__i 
            = ((IData)(1U) + pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__i);
    }
    vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__do_pipe = 0U;
    pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__i = 0U;
    while (VL_GTS_III(32, 0x400U, pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__i)) {
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__mem[(0x3ffU 
                                                                    & pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__i)] = 0U;
        pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__i 
            = ((IData)(1U) + pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__i);
    }
    vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__do_pipe = 0U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpingpong_sp_ram_tb___024root___dump_triggers__stl(Vpingpong_sp_ram_tb___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vpingpong_sp_ram_tb___024root___eval_triggers__stl(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vpingpong_sp_ram_tb___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
