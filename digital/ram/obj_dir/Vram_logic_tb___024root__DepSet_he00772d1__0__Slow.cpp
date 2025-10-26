// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vram_logic_tb.h for the primary calling header

#include "Vram_logic_tb__pch.h"
#include "Vram_logic_tb___024root.h"

VL_ATTR_COLD void Vram_logic_tb___024root___eval_static__TOP(Vram_logic_tb___024root* vlSelf);

VL_ATTR_COLD void Vram_logic_tb___024root___eval_static(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_static\n"); );
    // Body
    Vram_logic_tb___024root___eval_static__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[8U] = 1U;
    vlSelf->__Vm_traceActivity[7U] = 1U;
    vlSelf->__Vm_traceActivity[6U] = 1U;
    vlSelf->__Vm_traceActivity[5U] = 1U;
    vlSelf->__Vm_traceActivity[4U] = 1U;
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vram_logic_tb___024root___eval_static__TOP(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->ram_logic_tb__DOT__error_count = 0U;
    vlSelf->ram_logic_tb__DOT__test_num = 0U;
    vlSelf->ram_logic_tb__DOT__buffer_number = 0U;
}

VL_ATTR_COLD void Vram_logic_tb___024root___eval_initial__TOP(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__i = 0U;
    while (VL_GTS_III(32, 0x400U, vlSelf->ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__i)) {
        vlSelf->ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__mem[(0x3ffU 
                                                               & vlSelf->ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__i)] = 0U;
        vlSelf->ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__i 
            = ((IData)(1U) + vlSelf->ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__i);
    }
    vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO = 0U;
    vlSelf->ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__do_pipeline = 0U;
    vlSelf->ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x400U, vlSelf->ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__i)) {
        vlSelf->ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__mem[(0x3ffU 
                                                               & vlSelf->ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__i)] = 0U;
        vlSelf->ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__i 
            = ((IData)(1U) + vlSelf->ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__i);
    }
    vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO = 0U;
    vlSelf->ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__do_pipeline = 0U;
}

VL_ATTR_COLD void Vram_logic_tb___024root___eval_final(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vram_logic_tb___024root___dump_triggers__stl(Vram_logic_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vram_logic_tb___024root___eval_phase__stl(Vram_logic_tb___024root* vlSelf);

VL_ATTR_COLD void Vram_logic_tb___024root___eval_settle(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_settle\n"); );
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
            Vram_logic_tb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("ram_logic_tb.sv", 18, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vram_logic_tb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vram_logic_tb___024root___dump_triggers__stl(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vram_logic_tb___024root___stl_sequent__TOP__0(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->ram_logic_tb__DOT__dut__DOT__read_accepted 
        = ((IData)(vlSelf->ram_logic_tb__DOT__read_ready) 
           & (IData)(vlSelf->ram_logic_tb__DOT__read_valid));
    vlSelf->ram_logic_tb__DOT__dut__DOT__write_accepted 
        = ((0x10U > (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count)) 
           & (IData)(vlSelf->ram_logic_tb__DOT__write_valid));
    if (vlSelf->ram_logic_tb__DOT__dut__DOT__write_buffer_sel) {
        vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__12__addr 
            = vlSelf->ram_logic_tb__DOT__dut__DOT__read_address;
        vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__12__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__12__addr) 
               << 4U);
        vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_address 
            = vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__12__Vfuncout;
        vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__13__addr 
            = vlSelf->ram_logic_tb__DOT__dut__DOT__write_address;
        vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__13__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__13__addr) 
               << 4U);
        vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_address 
            = vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__13__Vfuncout;
    } else {
        vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__14__addr 
            = vlSelf->ram_logic_tb__DOT__dut__DOT__write_address;
        vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__14__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__14__addr) 
               << 4U);
        vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_address 
            = vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__14__Vfuncout;
        vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__15__addr 
            = vlSelf->ram_logic_tb__DOT__dut__DOT__read_address;
        vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__15__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__15__addr) 
               << 4U);
        vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_address 
            = vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__15__Vfuncout;
    }
    vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_write_enable 
        = ((~ (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_buffer_sel)) 
           & (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_accepted));
    vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_write_enable 
        = ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_accepted) 
           & (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_buffer_sel));
}

VL_ATTR_COLD void Vram_logic_tb___024root___eval_stl(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vram_logic_tb___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[8U] = 1U;
        vlSelf->__Vm_traceActivity[7U] = 1U;
        vlSelf->__Vm_traceActivity[6U] = 1U;
        vlSelf->__Vm_traceActivity[5U] = 1U;
        vlSelf->__Vm_traceActivity[4U] = 1U;
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vram_logic_tb___024root___eval_triggers__stl(Vram_logic_tb___024root* vlSelf);

VL_ATTR_COLD bool Vram_logic_tb___024root___eval_phase__stl(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vram_logic_tb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vram_logic_tb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vram_logic_tb___024root___dump_triggers__act(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge ram_logic_tb.clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vram_logic_tb___024root___dump_triggers__nba(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge ram_logic_tb.clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vram_logic_tb___024root___ctor_var_reset(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->ram_logic_tb__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->ram_logic_tb__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->ram_logic_tb__DOT__write_data = VL_RAND_RESET_I(16);
    vlSelf->ram_logic_tb__DOT__write_valid = VL_RAND_RESET_I(1);
    vlSelf->ram_logic_tb__DOT__read_ready = VL_RAND_RESET_I(1);
    vlSelf->ram_logic_tb__DOT__read_valid = VL_RAND_RESET_I(1);
    vlSelf->ram_logic_tb__DOT__buffer_ready = VL_RAND_RESET_I(1);
    vlSelf->ram_logic_tb__DOT__buffer_overflow = VL_RAND_RESET_I(1);
    vlSelf->ram_logic_tb__DOT__error_count = 0;
    vlSelf->ram_logic_tb__DOT__test_num = 0;
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->ram_logic_tb__DOT__expected_buffer[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->ram_logic_tb__DOT__buffer_number = 0;
    vlSelf->ram_logic_tb__DOT__unnamedblk5__DOT__saw_buffer_ready = VL_RAND_RESET_I(1);
    vlSelf->ram_logic_tb__DOT__unnamedblk6__DOT__i = 0;
    vlSelf->ram_logic_tb__DOT__unnamedblk7__DOT__buf_idx = 0;
    vlSelf->ram_logic_tb__DOT__unnamedblk8__DOT__buf_idx = 0;
    vlSelf->ram_logic_tb__DOT__dut__DOT__write_address = VL_RAND_RESET_I(4);
    vlSelf->ram_logic_tb__DOT__dut__DOT__read_address = VL_RAND_RESET_I(4);
    vlSelf->ram_logic_tb__DOT__dut__DOT__write_count = VL_RAND_RESET_I(5);
    vlSelf->ram_logic_tb__DOT__dut__DOT__read_count = VL_RAND_RESET_I(5);
    vlSelf->ram_logic_tb__DOT__dut__DOT__write_buffer_sel = VL_RAND_RESET_I(1);
    vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel = VL_RAND_RESET_I(1);
    vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid = VL_RAND_RESET_I(1);
    vlSelf->ram_logic_tb__DOT__dut__DOT__read_in_progress = VL_RAND_RESET_I(1);
    vlSelf->ram_logic_tb__DOT__dut__DOT__write_accepted = VL_RAND_RESET_I(1);
    vlSelf->ram_logic_tb__DOT__dut__DOT__read_accepted = VL_RAND_RESET_I(1);
    vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_address = VL_RAND_RESET_I(14);
    vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_address = VL_RAND_RESET_I(14);
    vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_write_enable = VL_RAND_RESET_I(1);
    vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_write_enable = VL_RAND_RESET_I(1);
    vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram0__DO = VL_RAND_RESET_I(32);
    vlSelf->ram_logic_tb__DOT__dut__DOT____Vcellout__u_ram1__DO = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__do_pipeline = VL_RAND_RESET_I(32);
    vlSelf->ram_logic_tb__DOT__dut__DOT__u_ram0__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__do_pipeline = VL_RAND_RESET_I(32);
    vlSelf->ram_logic_tb__DOT__dut__DOT__u_ram1__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__12__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__12__addr = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__13__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__13__addr = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__14__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__14__addr = VL_RAND_RESET_I(4);
    vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__15__Vfuncout = VL_RAND_RESET_I(14);
    vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__pack_address__15__addr = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigprevexpr___TOP__ram_logic_tb__DOT__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 9; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
