// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsampler.h for the primary calling header

#include "Vsampler__pch.h"
#include "Vsampler___024root.h"

VL_INLINE_OPT void Vsampler___024root___ico_sequent__TOP__0(Vsampler___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsampler___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->sampler__DOT__channel_0_buffer__DOT__buffer_full 
        = ((0xffU == (IData)(vlSelf->sampler__DOT__channel_0_buffer__DOT__write_addr)) 
           & (IData)(vlSelf->mic_valid_i));
}

void Vsampler___024root___eval_ico(Vsampler___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsampler___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vsampler___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vsampler___024root___eval_triggers__ico(Vsampler___024root* vlSelf);

bool Vsampler___024root___eval_phase__ico(Vsampler___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsampler___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vsampler___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vsampler___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vsampler___024root___eval_act(Vsampler___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsampler___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vsampler___024root___nba_sequent__TOP__0(Vsampler___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsampler___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ sampler__DOT__unnamedblk2__DOT__i;
    sampler__DOT__unnamedblk2__DOT__i = 0;
    // Body
    if (vlSelf->rst_ni) {
        if (vlSelf->mic_valid_i) {
            vlSelf->sampler__DOT__channel_0_buffer__DOT__write_addr 
                = ((0xffU == (IData)(vlSelf->sampler__DOT__channel_0_buffer__DOT__write_addr))
                    ? 0U : (0xffU & ((IData)(1U) + (IData)(vlSelf->sampler__DOT__channel_0_buffer__DOT__write_addr))));
        }
        if (vlSelf->sampler__DOT__channel_0_buffer__DOT__buffer_full) {
            vlSelf->sampler__DOT__ch_active_buf = (1U 
                                                   & (~ (IData)(vlSelf->sampler__DOT__ch_active_buf)));
        }
    } else {
        vlSelf->sampler__DOT__channel_0_buffer__DOT__write_addr = 0U;
        vlSelf->sampler__DOT__ch_active_buf = 0U;
    }
    vlSelf->sampler__DOT__ch_buf_ready_pulse = ((IData)(vlSelf->rst_ni) 
                                                && (IData)(vlSelf->sampler__DOT__channel_0_buffer__DOT__buffer_full));
    vlSelf->sampler__DOT__channel_0_buffer__DOT__buffer_full 
        = ((0xffU == (IData)(vlSelf->sampler__DOT__channel_0_buffer__DOT__write_addr)) 
           & (IData)(vlSelf->mic_valid_i));
    vlSelf->active_buf_o = vlSelf->sampler__DOT__ch_active_buf;
    vlSelf->buf_ready_pulse_o = 0U;
    vlSelf->buf_ready_pulse_o = ((IData)(vlSelf->buf_ready_pulse_o) 
                                 | (IData)(vlSelf->sampler__DOT__ch_buf_ready_pulse));
    vlSelf->buf_ready_ch_o = 0U;
    sampler__DOT__unnamedblk2__DOT__i = 0U;
    {
        while ((1U > sampler__DOT__unnamedblk2__DOT__i)) {
            if (((0U >= (1U & sampler__DOT__unnamedblk2__DOT__i)) 
                 && (1U & ((IData)(vlSelf->sampler__DOT__ch_buf_ready_pulse) 
                           >> (1U & sampler__DOT__unnamedblk2__DOT__i))))) {
                vlSelf->buf_ready_ch_o = (1U & sampler__DOT__unnamedblk2__DOT__i);
                goto __Vlabel1;
            }
            sampler__DOT__unnamedblk2__DOT__i = ((IData)(1U) 
                                                 + sampler__DOT__unnamedblk2__DOT__i);
        }
        __Vlabel1: ;
    }
}

void Vsampler___024root___eval_nba(Vsampler___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsampler___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsampler___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vsampler___024root___eval_triggers__act(Vsampler___024root* vlSelf);

bool Vsampler___024root___eval_phase__act(Vsampler___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsampler___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vsampler___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vsampler___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vsampler___024root___eval_phase__nba(Vsampler___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsampler___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vsampler___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsampler___024root___dump_triggers__ico(Vsampler___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsampler___024root___dump_triggers__nba(Vsampler___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsampler___024root___dump_triggers__act(Vsampler___024root* vlSelf);
#endif  // VL_DEBUG

void Vsampler___024root___eval(Vsampler___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsampler___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vsampler___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("rtl/sampler.sv", 10, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vsampler___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vsampler___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl/sampler.sv", 10, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vsampler___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl/sampler.sv", 10, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vsampler___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vsampler___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vsampler___024root___eval_debug_assertions(Vsampler___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsampler__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsampler___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelf->rst_ni & 0xfeU))) {
        Verilated::overWidthError("rst_ni");}
    if (VL_UNLIKELY((vlSelf->mic_valid_i & 0xfeU))) {
        Verilated::overWidthError("mic_valid_i");}
}
#endif  // VL_DEBUG
