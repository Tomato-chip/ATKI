// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsp_ram_simple_tb.h for the primary calling header

#include "Vsp_ram_simple_tb__pch.h"
#include "Vsp_ram_simple_tb___024root.h"

VL_ATTR_COLD void Vsp_ram_simple_tb___024root___eval_static(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vsp_ram_simple_tb___024root___eval_initial__TOP(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__i = 0U;
    while (VL_GTS_III(32, 0x4000U, vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__i)) {
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__mem[(0x3fffU 
                                                                   & vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__i)] = 0U;
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__i 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__i);
    }
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x4000U, vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__i)) {
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__mem[(0x3fffU 
                                                                   & vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__i)] = 0U;
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__i 
            = ((IData)(1U) + vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__i);
    }
}

VL_ATTR_COLD void Vsp_ram_simple_tb___024root___eval_final(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsp_ram_simple_tb___024root___dump_triggers__stl(Vsp_ram_simple_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vsp_ram_simple_tb___024root___eval_phase__stl(Vsp_ram_simple_tb___024root* vlSelf);

VL_ATTR_COLD void Vsp_ram_simple_tb___024root___eval_settle(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vsp_ram_simple_tb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("sp_ram_simple_tb.sv", 8, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vsp_ram_simple_tb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsp_ram_simple_tb___024root___dump_triggers__stl(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsp_ram_simple_tb___024root___stl_sequent__TOP__0(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__buffer_full 
        = ((IData)(vlSelf->sp_ram_simple_tb__DOT__sample_ready) 
           & (9U == (IData)(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_address)));
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_enable_RAM_0 
        = ((~ (IData)(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__rw_sel)) 
           & (IData)(vlSelf->sp_ram_simple_tb__DOT__sample_ready));
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_enable_RAM_1 
        = ((IData)(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__rw_sel) 
           & (IData)(vlSelf->sp_ram_simple_tb__DOT__sample_ready));
    vlSelf->sp_ram_simple_tb__DOT__read_data = 0U;
    if (vlSelf->sp_ram_simple_tb__DOT__dut__DOT__valid_read_out) {
        vlSelf->sp_ram_simple_tb__DOT__read_data = 
            ((IData)(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__rw_sel_read)
              ? (IData)(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__data_out_RAM_1)
              : (IData)(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__data_out_RAM_0));
    }
    if (vlSelf->sp_ram_simple_tb__DOT__dut__DOT__rw_sel) {
        vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__0__a8 
            = vlSelf->sp_ram_simple_tb__DOT__dut__DOT__read_address;
        vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__0__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__0__a8) 
               << 4U);
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__address_RAM_0 
            = vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__0__Vfuncout;
        vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__1__a8 
            = vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_address;
        vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__1__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__1__a8) 
               << 4U);
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__address_RAM_1 
            = vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__1__Vfuncout;
    } else {
        vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__2__a8 
            = vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_address;
        vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__2__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__2__a8) 
               << 4U);
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__address_RAM_0 
            = vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__2__Vfuncout;
        vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__3__a8 
            = vlSelf->sp_ram_simple_tb__DOT__dut__DOT__read_address;
        vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__3__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__3__a8) 
               << 4U);
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__address_RAM_1 
            = vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__3__Vfuncout;
    }
}

VL_ATTR_COLD void Vsp_ram_simple_tb___024root___eval_stl(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vsp_ram_simple_tb___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vsp_ram_simple_tb___024root___eval_triggers__stl(Vsp_ram_simple_tb___024root* vlSelf);

VL_ATTR_COLD bool Vsp_ram_simple_tb___024root___eval_phase__stl(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vsp_ram_simple_tb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vsp_ram_simple_tb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsp_ram_simple_tb___024root___dump_triggers__act(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge sp_ram_simple_tb.clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsp_ram_simple_tb___024root___dump_triggers__nba(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge sp_ram_simple_tb.clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsp_ram_simple_tb___024root___ctor_var_reset(Vsp_ram_simple_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->sp_ram_simple_tb__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->sp_ram_simple_tb__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->sp_ram_simple_tb__DOT__sample_in = VL_RAND_RESET_I(16);
    vlSelf->sp_ram_simple_tb__DOT__sample_ready = VL_RAND_RESET_I(1);
    vlSelf->sp_ram_simple_tb__DOT__read_data = VL_RAND_RESET_I(16);
    vlSelf->sp_ram_simple_tb__DOT__buffer_ready = VL_RAND_RESET_I(1);
    vlSelf->sp_ram_simple_tb__DOT__sample_count = VL_RAND_RESET_I(32);
    vlSelf->sp_ram_simple_tb__DOT__cycle_count = VL_RAND_RESET_I(32);
    vlSelf->sp_ram_simple_tb__DOT__read_data_prev = VL_RAND_RESET_I(16);
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__buffer = 0;
    vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_address = VL_RAND_RESET_I(8);
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__read_address = VL_RAND_RESET_I(8);
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__rw_sel = VL_RAND_RESET_I(1);
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__rw_sel_read = VL_RAND_RESET_I(1);
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__valid_read_out = VL_RAND_RESET_I(1);
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__buffer_full = VL_RAND_RESET_I(1);
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__address_RAM_0 = VL_RAND_RESET_I(14);
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__address_RAM_1 = VL_RAND_RESET_I(14);
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_enable_RAM_0 = VL_RAND_RESET_I(1);
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_enable_RAM_1 = VL_RAND_RESET_I(1);
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__data_out_RAM_0 = VL_RAND_RESET_I(16);
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__data_out_RAM_1 = VL_RAND_RESET_I(16);
    for (int __Vi0 = 0; __Vi0 < 16384; ++__Vi0) {
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__data_out_reg = VL_RAND_RESET_I(16);
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 16384; ++__Vi0) {
        vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__data_out_reg = VL_RAND_RESET_I(16);
    vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__0__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__0__a8 = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__1__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__1__a8 = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__2__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__2__a8 = VL_RAND_RESET_I(8);
    vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__3__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__3__a8 = VL_RAND_RESET_I(8);
    vlSelf->__Vtrigprevexpr___TOP__sp_ram_simple_tb__DOT__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
