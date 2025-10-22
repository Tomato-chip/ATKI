// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vram_vu_handshake_tb.h for the primary calling header

#include "Vram_vu_handshake_tb__pch.h"
#include "Vram_vu_handshake_tb__Syms.h"
#include "Vram_vu_handshake_tb___024root.h"

VL_ATTR_COLD void Vram_vu_handshake_tb___024root___eval_initial__TOP(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x68616b65U;
    __Vtemp_1[2U] = 0x616e6473U;
    __Vtemp_1[3U] = 0x76755f68U;
    __Vtemp_1[4U] = 0x72616d5fU;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(5, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__i = 0U;
    while (VL_GTS_III(32, 0x400U, vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__i)) {
        vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__mem[(0x3ffU 
                                                                        & vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__i)] = 0U;
        vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__i 
            = ((IData)(1U) + vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__i);
    }
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__do_reg = 0U;
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__do_pipe = 0U;
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x400U, vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__i)) {
        vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__mem[(0x3ffU 
                                                                        & vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__i)] = 0U;
        vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__i 
            = ((IData)(1U) + vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__i);
    }
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__do_reg = 0U;
    vlSelf->ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__do_pipe = 0U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vram_vu_handshake_tb___024root___dump_triggers__stl(Vram_vu_handshake_tb___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vram_vu_handshake_tb___024root___eval_triggers__stl(Vram_vu_handshake_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_vu_handshake_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_vu_handshake_tb___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vram_vu_handshake_tb___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
