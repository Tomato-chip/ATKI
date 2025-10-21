// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_i2s_top.h for the primary calling header

#include "Vtb_i2s_top__pch.h"
#include "Vtb_i2s_top___024root.h"

void Vtb_i2s_top___024root___eval_act(Vtb_i2s_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_i2s_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_i2s_top___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtb_i2s_top___024root___nba_sequent__TOP__0(Vtb_i2s_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_i2s_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_i2s_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*1:0*/ __Vdly__tb_i2s_top__DOT__dut__DOT__sck_sync;
    __Vdly__tb_i2s_top__DOT__dut__DOT__sck_sync = 0;
    CData/*1:0*/ __Vdly__tb_i2s_top__DOT__dut__DOT__ws_sync;
    __Vdly__tb_i2s_top__DOT__dut__DOT__ws_sync = 0;
    CData/*1:0*/ __Vdly__tb_i2s_top__DOT__dut__DOT__sd_sync;
    __Vdly__tb_i2s_top__DOT__dut__DOT__sd_sync = 0;
    CData/*5:0*/ __Vdly__tb_i2s_top__DOT__dut__DOT__bit_count_q;
    __Vdly__tb_i2s_top__DOT__dut__DOT__bit_count_q = 0;
    IData/*23:0*/ __Vdly__tb_i2s_top__DOT__dut__DOT__shift_reg_q;
    __Vdly__tb_i2s_top__DOT__dut__DOT__shift_reg_q = 0;
    // Body
    __Vdly__tb_i2s_top__DOT__dut__DOT__sd_sync = vlSelf->tb_i2s_top__DOT__dut__DOT__sd_sync;
    __Vdly__tb_i2s_top__DOT__dut__DOT__ws_sync = vlSelf->tb_i2s_top__DOT__dut__DOT__ws_sync;
    __Vdly__tb_i2s_top__DOT__dut__DOT__sck_sync = vlSelf->tb_i2s_top__DOT__dut__DOT__sck_sync;
    __Vdly__tb_i2s_top__DOT__dut__DOT__shift_reg_q 
        = vlSelf->tb_i2s_top__DOT__dut__DOT__shift_reg_q;
    __Vdly__tb_i2s_top__DOT__dut__DOT__bit_count_q 
        = vlSelf->tb_i2s_top__DOT__dut__DOT__bit_count_q;
    if (vlSelf->rst_n) {
        __Vdly__tb_i2s_top__DOT__dut__DOT__sd_sync 
            = ((2U & ((IData)(vlSelf->tb_i2s_top__DOT__dut__DOT__sd_sync) 
                      << 1U)) | (IData)(vlSelf->sd));
        __Vdly__tb_i2s_top__DOT__dut__DOT__ws_sync 
            = ((2U & ((IData)(vlSelf->tb_i2s_top__DOT__dut__DOT__ws_sync) 
                      << 1U)) | (IData)(vlSelf->ws));
        __Vdly__tb_i2s_top__DOT__dut__DOT__sck_sync 
            = ((2U & ((IData)(vlSelf->tb_i2s_top__DOT__dut__DOT__sck_sync) 
                      << 1U)) | (IData)(vlSelf->sck));
        vlSelf->valid = 0U;
        if ((1U & VL_REDXOR_2(vlSelf->tb_i2s_top__DOT__dut__DOT__ws_sync))) {
            __Vdly__tb_i2s_top__DOT__dut__DOT__bit_count_q = 0U;
        } else if ((IData)(((1U == (IData)(vlSelf->tb_i2s_top__DOT__dut__DOT__sck_sync)) 
                            & (~ (IData)(vlSelf->tb_i2s_top__DOT__dut__DOT__ws_sync))))) {
            if ((0U == (IData)(vlSelf->tb_i2s_top__DOT__dut__DOT__bit_count_q))) {
                __Vdly__tb_i2s_top__DOT__dut__DOT__bit_count_q = 1U;
            } else if ((0x18U >= (IData)(vlSelf->tb_i2s_top__DOT__dut__DOT__bit_count_q))) {
                __Vdly__tb_i2s_top__DOT__dut__DOT__shift_reg_q 
                    = ((0xfffffeU & (vlSelf->tb_i2s_top__DOT__dut__DOT__shift_reg_q 
                                     << 1U)) | (1U 
                                                & (IData)(vlSelf->tb_i2s_top__DOT__dut__DOT__sd_sync)));
                __Vdly__tb_i2s_top__DOT__dut__DOT__bit_count_q 
                    = (0x3fU & ((IData)(1U) + (IData)(vlSelf->tb_i2s_top__DOT__dut__DOT__bit_count_q)));
                if ((0x18U == (IData)(vlSelf->tb_i2s_top__DOT__dut__DOT__bit_count_q))) {
                    vlSelf->data24 = ((0xfffffeU & 
                                       (vlSelf->tb_i2s_top__DOT__dut__DOT__shift_reg_q 
                                        << 1U)) | (1U 
                                                   & (IData)(vlSelf->tb_i2s_top__DOT__dut__DOT__sd_sync)));
                    vlSelf->valid = 1U;
                }
            }
        }
    } else {
        __Vdly__tb_i2s_top__DOT__dut__DOT__sd_sync = 0U;
        __Vdly__tb_i2s_top__DOT__dut__DOT__ws_sync = 0U;
        __Vdly__tb_i2s_top__DOT__dut__DOT__sck_sync = 0U;
        __Vdly__tb_i2s_top__DOT__dut__DOT__shift_reg_q = 0U;
        __Vdly__tb_i2s_top__DOT__dut__DOT__bit_count_q = 0U;
        vlSelf->data24 = 0U;
        vlSelf->valid = 0U;
    }
    vlSelf->tb_i2s_top__DOT__dut__DOT__ws_sync = __Vdly__tb_i2s_top__DOT__dut__DOT__ws_sync;
    vlSelf->tb_i2s_top__DOT__dut__DOT__bit_count_q 
        = __Vdly__tb_i2s_top__DOT__dut__DOT__bit_count_q;
    vlSelf->tb_i2s_top__DOT__dut__DOT__sck_sync = __Vdly__tb_i2s_top__DOT__dut__DOT__sck_sync;
    vlSelf->tb_i2s_top__DOT__dut__DOT__sd_sync = __Vdly__tb_i2s_top__DOT__dut__DOT__sd_sync;
    vlSelf->tb_i2s_top__DOT__dut__DOT__shift_reg_q 
        = __Vdly__tb_i2s_top__DOT__dut__DOT__shift_reg_q;
}

void Vtb_i2s_top___024root___eval_nba(Vtb_i2s_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_i2s_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_i2s_top___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_i2s_top___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vtb_i2s_top___024root___eval_triggers__act(Vtb_i2s_top___024root* vlSelf);

bool Vtb_i2s_top___024root___eval_phase__act(Vtb_i2s_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_i2s_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_i2s_top___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_i2s_top___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_i2s_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_i2s_top___024root___eval_phase__nba(Vtb_i2s_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_i2s_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_i2s_top___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_i2s_top___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_i2s_top___024root___dump_triggers__nba(Vtb_i2s_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_i2s_top___024root___dump_triggers__act(Vtb_i2s_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_i2s_top___024root___eval(Vtb_i2s_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_i2s_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_i2s_top___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_i2s_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("sim/tb_i2s_top.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_i2s_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("sim/tb_i2s_top.sv", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_i2s_top___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_i2s_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_i2s_top___024root___eval_debug_assertions(Vtb_i2s_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_i2s_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_i2s_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((vlSelf->sck & 0xfeU))) {
        Verilated::overWidthError("sck");}
    if (VL_UNLIKELY((vlSelf->ws & 0xfeU))) {
        Verilated::overWidthError("ws");}
    if (VL_UNLIKELY((vlSelf->sd & 0xfeU))) {
        Verilated::overWidthError("sd");}
}
#endif  // VL_DEBUG
