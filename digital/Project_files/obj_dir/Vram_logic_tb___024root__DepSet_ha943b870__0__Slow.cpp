// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vram_logic_tb.h for the primary calling header

#include "Vram_logic_tb__pch.h"
#include "Vram_logic_tb__Syms.h"
#include "Vram_logic_tb___024root.h"

VL_ATTR_COLD void Vram_logic_tb___024root___eval_initial__TOP(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x635f7462U;
    __Vtemp_1[2U] = 0x6c6f6769U;
    __Vtemp_1[3U] = 0x72616d5fU;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(4, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__unnamedblk2__DOT__i = 0U;
    while (VL_GTS_III(32, 0x200U, vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__unnamedblk2__DOT__i)) {
        vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem[(0x1ffU 
                                                                             & vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__unnamedblk2__DOT__i)] = 0U;
        vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__unnamedblk2__DOT__i 
            = ((IData)(1U) + vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__unnamedblk2__DOT__i);
    }
    vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__unnamedblk2__DOT__i = 0U;
    while (VL_GTS_III(32, 0x200U, vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__unnamedblk2__DOT__i)) {
        vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem[(0x1ffU 
                                                                             & vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__unnamedblk2__DOT__i)] = 0U;
        vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__unnamedblk2__DOT__i 
            = ((IData)(1U) + vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__unnamedblk2__DOT__i);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vram_logic_tb___024root___dump_triggers__stl(Vram_logic_tb___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vram_logic_tb___024root___eval_triggers__stl(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vram_logic_tb___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
