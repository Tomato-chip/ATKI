// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpingpong_sp_ram_tb.h for the primary calling header

#include "Vpingpong_sp_ram_tb__pch.h"
#include "Vpingpong_sp_ram_tb___024root.h"

VL_ATTR_COLD void Vpingpong_sp_ram_tb___024root___eval_static__TOP(Vpingpong_sp_ram_tb___024root* vlSelf);

VL_ATTR_COLD void Vpingpong_sp_ram_tb___024root___eval_static(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___eval_static\n"); );
    // Body
    Vpingpong_sp_ram_tb___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vpingpong_sp_ram_tb___024root___eval_static__TOP(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->pingpong_sp_ram_tb__DOT__errors = 0U;
}

VL_ATTR_COLD void Vpingpong_sp_ram_tb___024root___eval_final(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpingpong_sp_ram_tb___024root___dump_triggers__stl(Vpingpong_sp_ram_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vpingpong_sp_ram_tb___024root___eval_phase__stl(Vpingpong_sp_ram_tb___024root* vlSelf);

VL_ATTR_COLD void Vpingpong_sp_ram_tb___024root___eval_settle(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___eval_settle\n"); );
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
            Vpingpong_sp_ram_tb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("sim/pingpong_sp_ram_tb.sv", 11, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vpingpong_sp_ram_tb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpingpong_sp_ram_tb___024root___dump_triggers__stl(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vpingpong_sp_ram_tb___024root___act_comb__TOP__0(Vpingpong_sp_ram_tb___024root* vlSelf);

VL_ATTR_COLD void Vpingpong_sp_ram_tb___024root___eval_stl(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vpingpong_sp_ram_tb___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vpingpong_sp_ram_tb___024root___eval_triggers__stl(Vpingpong_sp_ram_tb___024root* vlSelf);

VL_ATTR_COLD bool Vpingpong_sp_ram_tb___024root___eval_phase__stl(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vpingpong_sp_ram_tb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vpingpong_sp_ram_tb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpingpong_sp_ram_tb___024root___dump_triggers__act(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge pingpong_sp_ram_tb.clk_i)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpingpong_sp_ram_tb___024root___dump_triggers__nba(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge pingpong_sp_ram_tb.clk_i)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vpingpong_sp_ram_tb___024root___ctor_var_reset(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->pingpong_sp_ram_tb__DOT__clk_i = VL_RAND_RESET_I(1);
    vlSelf->pingpong_sp_ram_tb__DOT__rst_ni = VL_RAND_RESET_I(1);
    vlSelf->pingpong_sp_ram_tb__DOT__in_valid_i = VL_RAND_RESET_I(1);
    vlSelf->pingpong_sp_ram_tb__DOT__in_data_i = VL_RAND_RESET_I(16);
    vlSelf->pingpong_sp_ram_tb__DOT__rd_en_i = VL_RAND_RESET_I(1);
    vlSelf->pingpong_sp_ram_tb__DOT__rd_addr_i = VL_RAND_RESET_I(8);
    vlSelf->pingpong_sp_ram_tb__DOT__rd_data_o = VL_RAND_RESET_I(16);
    vlSelf->pingpong_sp_ram_tb__DOT__active_buf_o = VL_RAND_RESET_I(1);
    vlSelf->pingpong_sp_ram_tb__DOT__buf_ready_pulse_o = VL_RAND_RESET_I(1);
    vlSelf->pingpong_sp_ram_tb__DOT__buf_ready_id_o = VL_RAND_RESET_I(1);
    vlSelf->pingpong_sp_ram_tb__DOT__errors = 0;
    vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__write_addr = VL_RAND_RESET_I(8);
    vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__write_last = VL_RAND_RESET_I(1);
    vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__we_a = VL_RAND_RESET_I(1);
    vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__we_b = VL_RAND_RESET_I(1);
    vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__addr_a = VL_RAND_RESET_I(8);
    vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__addr_b = VL_RAND_RESET_I(8);
    vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__rd_valid_q = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__do_pipe = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__do_pipe = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__pingpong_sp_ram_tb__DOT__clk_i__0 = VL_RAND_RESET_I(1);
}
