// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdouble_buffer_ram.h for the primary calling header

#include "Vdouble_buffer_ram__pch.h"
#include "Vdouble_buffer_ram___024root.h"

VL_ATTR_COLD void Vdouble_buffer_ram___024root___eval_static(Vdouble_buffer_ram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdouble_buffer_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdouble_buffer_ram___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vdouble_buffer_ram___024root___eval_initial__TOP(Vdouble_buffer_ram___024root* vlSelf);

VL_ATTR_COLD void Vdouble_buffer_ram___024root___eval_initial(Vdouble_buffer_ram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdouble_buffer_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdouble_buffer_ram___024root___eval_initial\n"); );
    // Body
    Vdouble_buffer_ram___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__clk_i__0 = vlSelf->clk_i;
}

VL_ATTR_COLD void Vdouble_buffer_ram___024root___eval_initial__TOP(Vdouble_buffer_ram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdouble_buffer_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdouble_buffer_ram___024root___eval_initial__TOP\n"); );
    // Init
    IData/*31:0*/ double_buffer_ram__DOT__gen_generic_dpram__DOT__dpram_buffer_a__DOT__unnamedblk1__DOT__i;
    double_buffer_ram__DOT__gen_generic_dpram__DOT__dpram_buffer_a__DOT__unnamedblk1__DOT__i = 0;
    IData/*31:0*/ double_buffer_ram__DOT__gen_generic_dpram__DOT__dpram_buffer_b__DOT__unnamedblk1__DOT__i;
    double_buffer_ram__DOT__gen_generic_dpram__DOT__dpram_buffer_b__DOT__unnamedblk1__DOT__i = 0;
    // Body
    vlSelf->in_ready_o = 1U;
    double_buffer_ram__DOT__gen_generic_dpram__DOT__dpram_buffer_a__DOT__unnamedblk1__DOT__i = 0U;
    while ((0x100U > double_buffer_ram__DOT__gen_generic_dpram__DOT__dpram_buffer_a__DOT__unnamedblk1__DOT__i)) {
        vlSelf->double_buffer_ram__DOT__gen_generic_dpram__DOT__dpram_buffer_a__DOT__mem[(0xffU 
                                                                                & double_buffer_ram__DOT__gen_generic_dpram__DOT__dpram_buffer_a__DOT__unnamedblk1__DOT__i)] = 0U;
        double_buffer_ram__DOT__gen_generic_dpram__DOT__dpram_buffer_a__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + double_buffer_ram__DOT__gen_generic_dpram__DOT__dpram_buffer_a__DOT__unnamedblk1__DOT__i);
    }
    double_buffer_ram__DOT__gen_generic_dpram__DOT__dpram_buffer_b__DOT__unnamedblk1__DOT__i = 0U;
    while ((0x100U > double_buffer_ram__DOT__gen_generic_dpram__DOT__dpram_buffer_b__DOT__unnamedblk1__DOT__i)) {
        vlSelf->double_buffer_ram__DOT__gen_generic_dpram__DOT__dpram_buffer_b__DOT__mem[(0xffU 
                                                                                & double_buffer_ram__DOT__gen_generic_dpram__DOT__dpram_buffer_b__DOT__unnamedblk1__DOT__i)] = 0U;
        double_buffer_ram__DOT__gen_generic_dpram__DOT__dpram_buffer_b__DOT__unnamedblk1__DOT__i 
            = ((IData)(1U) + double_buffer_ram__DOT__gen_generic_dpram__DOT__dpram_buffer_b__DOT__unnamedblk1__DOT__i);
    }
}

VL_ATTR_COLD void Vdouble_buffer_ram___024root___eval_final(Vdouble_buffer_ram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdouble_buffer_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdouble_buffer_ram___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdouble_buffer_ram___024root___dump_triggers__stl(Vdouble_buffer_ram___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vdouble_buffer_ram___024root___eval_phase__stl(Vdouble_buffer_ram___024root* vlSelf);

VL_ATTR_COLD void Vdouble_buffer_ram___024root___eval_settle(Vdouble_buffer_ram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdouble_buffer_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdouble_buffer_ram___024root___eval_settle\n"); );
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
            Vdouble_buffer_ram___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("rtl/double_buffer_ram.sv", 11, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vdouble_buffer_ram___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdouble_buffer_ram___024root___dump_triggers__stl(Vdouble_buffer_ram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdouble_buffer_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdouble_buffer_ram___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdouble_buffer_ram___024root___stl_sequent__TOP__0(Vdouble_buffer_ram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdouble_buffer_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdouble_buffer_ram___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->rd_data_valid_o = vlSelf->double_buffer_ram__DOT__rd_en_q;
    vlSelf->double_buffer_ram__DOT__buffer_full = (
                                                   (0xffU 
                                                    == (IData)(vlSelf->double_buffer_ram__DOT__write_addr)) 
                                                   & (IData)(vlSelf->in_valid_i));
    vlSelf->rd_data_o = ((IData)(vlSelf->active_buf_o)
                          ? (IData)(vlSelf->double_buffer_ram__DOT__ram_a_rdata)
                          : (IData)(vlSelf->double_buffer_ram__DOT__ram_b_rdata));
}

VL_ATTR_COLD void Vdouble_buffer_ram___024root___eval_stl(Vdouble_buffer_ram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdouble_buffer_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdouble_buffer_ram___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vdouble_buffer_ram___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vdouble_buffer_ram___024root___eval_triggers__stl(Vdouble_buffer_ram___024root* vlSelf);

VL_ATTR_COLD bool Vdouble_buffer_ram___024root___eval_phase__stl(Vdouble_buffer_ram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdouble_buffer_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdouble_buffer_ram___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vdouble_buffer_ram___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vdouble_buffer_ram___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdouble_buffer_ram___024root___dump_triggers__ico(Vdouble_buffer_ram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdouble_buffer_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdouble_buffer_ram___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdouble_buffer_ram___024root___dump_triggers__act(Vdouble_buffer_ram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdouble_buffer_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdouble_buffer_ram___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk_i)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdouble_buffer_ram___024root___dump_triggers__nba(Vdouble_buffer_ram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdouble_buffer_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdouble_buffer_ram___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk_i)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdouble_buffer_ram___024root___ctor_var_reset(Vdouble_buffer_ram___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdouble_buffer_ram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdouble_buffer_ram___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk_i = VL_RAND_RESET_I(1);
    vlSelf->rst_ni = VL_RAND_RESET_I(1);
    vlSelf->in_valid_i = VL_RAND_RESET_I(1);
    vlSelf->in_data_i = VL_RAND_RESET_I(16);
    vlSelf->in_ready_o = VL_RAND_RESET_I(1);
    vlSelf->rd_addr_i = VL_RAND_RESET_I(8);
    vlSelf->rd_en_i = VL_RAND_RESET_I(1);
    vlSelf->rd_data_o = VL_RAND_RESET_I(16);
    vlSelf->rd_data_valid_o = VL_RAND_RESET_I(1);
    vlSelf->active_buf_o = VL_RAND_RESET_I(1);
    vlSelf->buf_ready_pulse_o = VL_RAND_RESET_I(1);
    vlSelf->buf_ready_id_o = VL_RAND_RESET_I(1);
    vlSelf->double_buffer_ram__DOT__write_addr = VL_RAND_RESET_I(8);
    vlSelf->double_buffer_ram__DOT__buffer_full = VL_RAND_RESET_I(1);
    vlSelf->double_buffer_ram__DOT__ram_a_rdata = VL_RAND_RESET_I(16);
    vlSelf->double_buffer_ram__DOT__ram_b_rdata = VL_RAND_RESET_I(16);
    vlSelf->double_buffer_ram__DOT__rd_en_q = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->double_buffer_ram__DOT__gen_generic_dpram__DOT__dpram_buffer_a__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->double_buffer_ram__DOT__gen_generic_dpram__DOT__dpram_buffer_b__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->__Vtrigprevexpr___TOP__clk_i__0 = VL_RAND_RESET_I(1);
}
