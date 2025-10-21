// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpingpong_sp_ram_tb.h for the primary calling header

#include "Vpingpong_sp_ram_tb__pch.h"
#include "Vpingpong_sp_ram_tb___024root.h"

VL_ATTR_COLD void Vpingpong_sp_ram_tb___024root___eval_initial__TOP(Vpingpong_sp_ram_tb___024root* vlSelf);
VlCoroutine Vpingpong_sp_ram_tb___024root___eval_initial__TOP__Vtiming__0(Vpingpong_sp_ram_tb___024root* vlSelf);
VlCoroutine Vpingpong_sp_ram_tb___024root___eval_initial__TOP__Vtiming__1(Vpingpong_sp_ram_tb___024root* vlSelf);
VlCoroutine Vpingpong_sp_ram_tb___024root___eval_initial__TOP__Vtiming__2(Vpingpong_sp_ram_tb___024root* vlSelf);

void Vpingpong_sp_ram_tb___024root___eval_initial(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___eval_initial\n"); );
    // Body
    Vpingpong_sp_ram_tb___024root___eval_initial__TOP(vlSelf);
    Vpingpong_sp_ram_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vpingpong_sp_ram_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vpingpong_sp_ram_tb___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__pingpong_sp_ram_tb__DOT__clk_i__0 
        = vlSelf->pingpong_sp_ram_tb__DOT__clk_i;
}

VL_INLINE_OPT VlCoroutine Vpingpong_sp_ram_tb___024root___eval_initial__TOP__Vtiming__0(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->pingpong_sp_ram_tb__DOT__clk_i = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "sim/pingpong_sp_ram_tb.sv", 
                                           59);
        vlSelf->pingpong_sp_ram_tb__DOT__clk_i = (1U 
                                                  & (~ (IData)(vlSelf->pingpong_sp_ram_tb__DOT__clk_i)));
    }
}

VL_INLINE_OPT void Vpingpong_sp_ram_tb___024root___act_comb__TOP__0(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___act_comb__TOP__0\n"); );
    // Body
    vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__we_a = 0U;
    vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__we_b = 0U;
    if (vlSelf->pingpong_sp_ram_tb__DOT__in_valid_i) {
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__write_last 
            = (0xffU == (IData)(vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__write_addr));
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__addr_a = 0U;
        if ((1U & (~ (IData)(vlSelf->pingpong_sp_ram_tb__DOT__active_buf_o)))) {
            vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__we_a = 1U;
            vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__addr_a 
                = vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__write_addr;
        }
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__addr_b = 0U;
        if (vlSelf->pingpong_sp_ram_tb__DOT__active_buf_o) {
            vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__we_b = 1U;
            vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__addr_b 
                = vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__write_addr;
        }
    } else {
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__write_last = 0U;
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__addr_a = 0U;
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__addr_b = 0U;
    }
    if (vlSelf->pingpong_sp_ram_tb__DOT__rd_en_i) {
        if (vlSelf->pingpong_sp_ram_tb__DOT__active_buf_o) {
            vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__addr_a 
                = vlSelf->pingpong_sp_ram_tb__DOT__rd_addr_i;
        }
        if ((1U & (~ (IData)(vlSelf->pingpong_sp_ram_tb__DOT__active_buf_o)))) {
            vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__addr_b 
                = vlSelf->pingpong_sp_ram_tb__DOT__rd_addr_i;
        }
    }
}

void Vpingpong_sp_ram_tb___024root___eval_act(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___eval_act\n"); );
    // Body
    if ((3ULL & vlSelf->__VactTriggered.word(0U))) {
        Vpingpong_sp_ram_tb___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vpingpong_sp_ram_tb___024root___nba_sequent__TOP__0(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdly__pingpong_sp_ram_tb__DOT__active_buf_o;
    __Vdly__pingpong_sp_ram_tb__DOT__active_buf_o = 0;
    SData/*9:0*/ __Vdlyvdim0__pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__mem__v0;
    __Vdlyvdim0__pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__mem__v0;
    __Vdlyvval__pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__mem__v0;
    __Vdlyvset__pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__mem__v0 = 0;
    SData/*9:0*/ __Vdlyvdim0__pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__mem__v0;
    __Vdlyvdim0__pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__mem__v0;
    __Vdlyvval__pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__mem__v0;
    __Vdlyvset__pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__mem__v0 = 0;
    // Body
    __Vdlyvset__pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__mem__v0 = 0U;
    __Vdlyvset__pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__mem__v0 = 0U;
    __Vdly__pingpong_sp_ram_tb__DOT__active_buf_o = vlSelf->pingpong_sp_ram_tb__DOT__active_buf_o;
    if (vlSelf->pingpong_sp_ram_tb__DOT__rst_ni) {
        if (vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__we_b) {
            __Vdlyvval__pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__mem__v0 
                = vlSelf->pingpong_sp_ram_tb__DOT__in_data_i;
            __Vdlyvset__pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__mem__v0 = 1U;
            __Vdlyvdim0__pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__mem__v0 
                = vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__addr_b;
        }
        if (vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__we_a) {
            __Vdlyvval__pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__mem__v0 
                = vlSelf->pingpong_sp_ram_tb__DOT__in_data_i;
            __Vdlyvset__pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__mem__v0 = 1U;
            __Vdlyvdim0__pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__mem__v0 
                = vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__addr_a;
        }
        if (vlSelf->pingpong_sp_ram_tb__DOT__in_valid_i) {
            vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__write_addr 
                = ((0xffU == (IData)(vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__write_addr))
                    ? 0U : (0xffU & ((IData)(1U) + (IData)(vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__write_addr))));
        }
        vlSelf->pingpong_sp_ram_tb__DOT__buf_ready_pulse_o = 0U;
        if (vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__write_last) {
            vlSelf->pingpong_sp_ram_tb__DOT__buf_ready_pulse_o = 1U;
            vlSelf->pingpong_sp_ram_tb__DOT__buf_ready_id_o 
                = vlSelf->pingpong_sp_ram_tb__DOT__active_buf_o;
            __Vdly__pingpong_sp_ram_tb__DOT__active_buf_o 
                = (1U & (~ (IData)(vlSelf->pingpong_sp_ram_tb__DOT__active_buf_o)));
        }
        if (vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__rd_valid_q) {
            vlSelf->pingpong_sp_ram_tb__DOT__rd_data_o 
                = (0xffffU & ((IData)(vlSelf->pingpong_sp_ram_tb__DOT__active_buf_o)
                               ? vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__do_pipe
                               : vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__do_pipe));
        }
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__do_pipe 
            = (0xffffU & vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__mem
               [vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__addr_a]);
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__do_pipe 
            = (0xffffU & vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__mem
               [vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__addr_b]);
    } else {
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__write_addr = 0U;
        vlSelf->pingpong_sp_ram_tb__DOT__buf_ready_pulse_o = 0U;
        __Vdly__pingpong_sp_ram_tb__DOT__active_buf_o = 0U;
        vlSelf->pingpong_sp_ram_tb__DOT__buf_ready_id_o = 0U;
        vlSelf->pingpong_sp_ram_tb__DOT__rd_data_o = 0U;
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__do_pipe = 0U;
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__do_pipe = 0U;
    }
    vlSelf->pingpong_sp_ram_tb__DOT__active_buf_o = __Vdly__pingpong_sp_ram_tb__DOT__active_buf_o;
    vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__rd_valid_q 
        = ((IData)(vlSelf->pingpong_sp_ram_tb__DOT__rst_ni) 
           && (IData)(vlSelf->pingpong_sp_ram_tb__DOT__rd_en_i));
    if (__Vdlyvset__pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__mem__v0) {
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__mem[__Vdlyvdim0__pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__mem__v0] 
            = __Vdlyvval__pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__mem__v0;
    }
    if (__Vdlyvset__pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__mem__v0) {
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__mem[__Vdlyvdim0__pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__mem__v0] 
            = __Vdlyvval__pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__mem__v0;
    }
}

VL_INLINE_OPT void Vpingpong_sp_ram_tb___024root___nba_comb__TOP__0(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___nba_comb__TOP__0\n"); );
    // Body
    if (vlSelf->pingpong_sp_ram_tb__DOT__in_valid_i) {
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__write_last 
            = (0xffU == (IData)(vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__write_addr));
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__we_a = 0U;
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__we_b = 0U;
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__addr_a = 0U;
        if ((1U & (~ (IData)(vlSelf->pingpong_sp_ram_tb__DOT__active_buf_o)))) {
            vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__we_a = 1U;
            vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__addr_a 
                = vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__write_addr;
        }
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__addr_b = 0U;
        if (vlSelf->pingpong_sp_ram_tb__DOT__active_buf_o) {
            vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__we_b = 1U;
            vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__addr_b 
                = vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__write_addr;
        }
    } else {
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__write_last = 0U;
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__we_a = 0U;
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__we_b = 0U;
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__addr_a = 0U;
        vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__addr_b = 0U;
    }
    if (vlSelf->pingpong_sp_ram_tb__DOT__rd_en_i) {
        if (vlSelf->pingpong_sp_ram_tb__DOT__active_buf_o) {
            vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__addr_a 
                = vlSelf->pingpong_sp_ram_tb__DOT__rd_addr_i;
        }
        if ((1U & (~ (IData)(vlSelf->pingpong_sp_ram_tb__DOT__active_buf_o)))) {
            vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__addr_b 
                = vlSelf->pingpong_sp_ram_tb__DOT__rd_addr_i;
        }
    }
}

void Vpingpong_sp_ram_tb___024root___eval_nba(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vpingpong_sp_ram_tb___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vpingpong_sp_ram_tb___024root___nba_comb__TOP__0(vlSelf);
    }
}

void Vpingpong_sp_ram_tb___024root___timing_resume(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___timing_resume\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h6eefdb72__0.resume("@(posedge pingpong_sp_ram_tb.clk_i)");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vpingpong_sp_ram_tb___024root___timing_commit(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h6eefdb72__0.commit("@(posedge pingpong_sp_ram_tb.clk_i)");
    }
}

void Vpingpong_sp_ram_tb___024root___eval_triggers__act(Vpingpong_sp_ram_tb___024root* vlSelf);

bool Vpingpong_sp_ram_tb___024root___eval_phase__act(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vpingpong_sp_ram_tb___024root___eval_triggers__act(vlSelf);
    Vpingpong_sp_ram_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vpingpong_sp_ram_tb___024root___timing_resume(vlSelf);
        Vpingpong_sp_ram_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vpingpong_sp_ram_tb___024root___eval_phase__nba(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vpingpong_sp_ram_tb___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpingpong_sp_ram_tb___024root___dump_triggers__nba(Vpingpong_sp_ram_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vpingpong_sp_ram_tb___024root___dump_triggers__act(Vpingpong_sp_ram_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vpingpong_sp_ram_tb___024root___eval(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vpingpong_sp_ram_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("sim/pingpong_sp_ram_tb.sv", 11, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vpingpong_sp_ram_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("sim/pingpong_sp_ram_tb.sv", 11, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vpingpong_sp_ram_tb___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vpingpong_sp_ram_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vpingpong_sp_ram_tb___024root___eval_debug_assertions(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
