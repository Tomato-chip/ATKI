// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpingpong_buffer_sp_tb_simple.h for the primary calling header

#include "Vpingpong_buffer_sp_tb_simple__pch.h"
#include "Vpingpong_buffer_sp_tb_simple___024root.h"

VL_ATTR_COLD void Vpingpong_buffer_sp_tb_simple___024root___eval_initial__TOP(Vpingpong_buffer_sp_tb_simple___024root* vlSelf);
VlCoroutine Vpingpong_buffer_sp_tb_simple___024root___eval_initial__TOP__Vtiming__0(Vpingpong_buffer_sp_tb_simple___024root* vlSelf);
VlCoroutine Vpingpong_buffer_sp_tb_simple___024root___eval_initial__TOP__Vtiming__1(Vpingpong_buffer_sp_tb_simple___024root* vlSelf);
VlCoroutine Vpingpong_buffer_sp_tb_simple___024root___eval_initial__TOP__Vtiming__2(Vpingpong_buffer_sp_tb_simple___024root* vlSelf);

void Vpingpong_buffer_sp_tb_simple___024root___eval_initial(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___eval_initial\n"); );
    // Body
    Vpingpong_buffer_sp_tb_simple___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    Vpingpong_buffer_sp_tb_simple___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vpingpong_buffer_sp_tb_simple___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vpingpong_buffer_sp_tb_simple___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram0__DO__0 
        = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram0__DO;
    vlSelf->__Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram1__DO__0 
        = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram1__DO;
    vlSelf->__Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram0__DO__1 
        = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram0__DO;
    vlSelf->__Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram1__DO__1 
        = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram1__DO;
    vlSelf->__Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__clk__0 
        = vlSelf->pingpong_buffer_sp_tb_simple__DOT__clk;
}

VL_INLINE_OPT VlCoroutine Vpingpong_buffer_sp_tb_simple___024root___eval_initial__TOP__Vtiming__0(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__clk = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x4844ULL, 
                                           nullptr, 
                                           "pingpong_buffer_sp_tb_simple.sv", 
                                           63);
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__clk 
            = (1U & (~ (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__clk)));
    }
}

VL_INLINE_OPT VlCoroutine Vpingpong_buffer_sp_tb_simple___024root___eval_initial__TOP__Vtiming__2(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0x2540be400ULL, 
                                       nullptr, "pingpong_buffer_sp_tb_simple.sv", 
                                       190);
    VL_WRITEF("\n*** TIMEOUT ***\n");
    VL_FINISH_MT("pingpong_buffer_sp_tb_simple.sv", 192, "");
}

VL_INLINE_OPT void Vpingpong_buffer_sp_tb_simple___024root___act_sequent__TOP__0(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___act_sequent__TOP__0\n"); );
    // Body
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram0__DO 
        = (0xffffU & vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram0__DO);
}

VL_INLINE_OPT void Vpingpong_buffer_sp_tb_simple___024root___act_sequent__TOP__1(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___act_sequent__TOP__1\n"); );
    // Body
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram1__DO 
        = (0xffffU & vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram1__DO);
}

VL_INLINE_OPT void Vpingpong_buffer_sp_tb_simple___024root___act_sequent__TOP__2(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___act_sequent__TOP__2\n"); );
    // Body
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_beat 
        = ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__rd_ready) 
           & (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__rd_valid));
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__sample_beat 
        = ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__wr_valid) 
           & ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__wr_ready) 
              & (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__sample_ready)));
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_buf_complete 
        = ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_beat) 
           & (0xffU == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_addr)));
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wre_ram0 
        = ((1U & (~ (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_sel))) 
           && (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__sample_beat));
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wre_ram1 
        = ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_sel) 
           && (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__sample_beat));
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_complete 
        = ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__sample_beat) 
           & (0xffU == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_addr)));
}

void Vpingpong_buffer_sp_tb_simple___024root___eval_act(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___eval_act\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        Vpingpong_buffer_sp_tb_simple___024root___act_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        Vpingpong_buffer_sp_tb_simple___024root___act_sequent__TOP__1(vlSelf);
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        Vpingpong_buffer_sp_tb_simple___024root___act_sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vpingpong_buffer_sp_tb_simple___024root___nba_sequent__TOP__0(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_addr;
    __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_addr = 0;
    CData/*1:0*/ __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_state;
    __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_state = 0;
    CData/*1:0*/ __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf0_state;
    __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf0_state = 0;
    CData/*1:0*/ __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf1_state;
    __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf1_state = 0;
    SData/*9:0*/ __Vdlyvdim0__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__mem__v0;
    __Vdlyvdim0__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__mem__v0;
    __Vdlyvval__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__mem__v0;
    __Vdlyvset__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__mem__v0 = 0;
    SData/*9:0*/ __Vdlyvdim0__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__mem__v0;
    __Vdlyvdim0__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__mem__v0;
    __Vdlyvval__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__mem__v0;
    __Vdlyvset__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__mem__v0 = 0;
    // Body
    __Vdlyvset__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__mem__v0 = 0U;
    __Vdlyvset__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__mem__v0 = 0U;
    __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_state 
        = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_state;
    __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_addr 
        = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_addr;
    __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf1_state 
        = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf1_state;
    __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf0_state 
        = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf0_state;
    if (vlSelf->pingpong_buffer_sp_tb_simple__DOT__rst_n) {
        if (vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wre_ram1) {
            __Vdlyvval__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__mem__v0 
                = vlSelf->pingpong_buffer_sp_tb_simple__DOT__wr_data;
            __Vdlyvset__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__mem__v0 = 1U;
            __Vdlyvdim0__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__mem__v0 
                = (0x3ffU & ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__addr_ram1) 
                             >> 4U));
        }
        if (vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wre_ram0) {
            __Vdlyvval__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__mem__v0 
                = vlSelf->pingpong_buffer_sp_tb_simple__DOT__wr_data;
            __Vdlyvset__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__mem__v0 = 1U;
            __Vdlyvdim0__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__mem__v0 
                = (0x3ffU & ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__addr_ram0) 
                             >> 4U));
        }
        if (vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__sample_beat) {
            vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_addr 
                = ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_complete)
                    ? 0U : (0xffU & ((IData)(1U) + (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_addr))));
        }
        if ((2U & (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf1_state))) {
            if ((1U & (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf1_state))) {
                if (((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_buf_sel) 
                     & (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_buf_complete))) {
                    __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf1_state = 0U;
                }
            } else if (((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__buf_take) 
                        & (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__buf_id))) {
                __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf1_state = 3U;
            }
        } else if ((1U & (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf1_state))) {
            if (((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_sel) 
                 & (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_complete))) {
                __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf1_state = 2U;
            }
        } else if (((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_sel) 
                    & (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__sample_beat))) {
            __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf1_state = 1U;
        }
        if ((2U & (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf0_state))) {
            if ((1U & (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf0_state))) {
                if (((~ (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_buf_sel)) 
                     & (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_buf_complete))) {
                    __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf0_state = 0U;
                }
            } else if (((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__buf_take) 
                        & (~ (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__buf_id)))) {
                __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf0_state = 3U;
            }
        } else if ((1U & (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf0_state))) {
            if (((~ (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_sel)) 
                 & (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_complete))) {
                __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf0_state = 2U;
            }
        } else if (((~ (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_sel)) 
                    & (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__sample_beat))) {
            __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf0_state = 1U;
        }
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__buf_ready = 0U;
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__read_data 
            = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__mem
            [(0x3ffU & ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__addr_ram1) 
                        >> 4U))];
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__read_data 
            = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__mem
            [(0x3ffU & ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__addr_ram0) 
                        >> 4U))];
        if (((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__wr_valid) 
             & (~ (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__wr_ready)))) {
            vlSelf->pingpong_buffer_sp_tb_simple__DOT__overrun = 1U;
        } else if (vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__sample_beat) {
            vlSelf->pingpong_buffer_sp_tb_simple__DOT__overrun = 0U;
        }
        if ((0U == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_state))) {
            vlSelf->pingpong_buffer_sp_tb_simple__DOT__rd_valid = 0U;
            if (((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__rd_ready) 
                 & (~ (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_buf_has_data)))) {
                vlSelf->pingpong_buffer_sp_tb_simple__DOT__underrun = 1U;
            }
            vlSelf->pingpong_buffer_sp_tb_simple__DOT__buf_empty = 1U;
            if (vlSelf->pingpong_buffer_sp_tb_simple__DOT__buf_take) {
                vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_buf_sel 
                    = vlSelf->pingpong_buffer_sp_tb_simple__DOT__buf_id;
                __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_addr = 0U;
                __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_state = 1U;
                vlSelf->pingpong_buffer_sp_tb_simple__DOT__rd_valid = 1U;
                vlSelf->pingpong_buffer_sp_tb_simple__DOT__buf_empty = 0U;
            }
        } else if ((1U == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_state))) {
            vlSelf->pingpong_buffer_sp_tb_simple__DOT__rd_valid = 1U;
            vlSelf->pingpong_buffer_sp_tb_simple__DOT__underrun = 0U;
            if (vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_beat) {
                if (vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_buf_complete) {
                    __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_addr = 0U;
                    __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_state = 0U;
                    vlSelf->pingpong_buffer_sp_tb_simple__DOT__rd_valid = 0U;
                } else {
                    __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_addr 
                        = (0xffU & ((IData)(1U) + (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_addr)));
                }
            }
        }
        if (vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_complete) {
            vlSelf->pingpong_buffer_sp_tb_simple__DOT__buf_ready = 1U;
            vlSelf->pingpong_buffer_sp_tb_simple__DOT__buf_id 
                = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_sel;
            vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_sel 
                = (1U & (~ (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_sel)));
        }
    } else {
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_addr = 0U;
        __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf1_state = 0U;
        __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf0_state = 0U;
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__buf_ready = 0U;
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__read_data = 0U;
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__read_data = 0U;
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__overrun = 0U;
        __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_state = 0U;
        __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_addr = 0U;
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_buf_sel = 1U;
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__rd_valid = 0U;
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__buf_empty = 1U;
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__underrun = 0U;
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_sel = 0U;
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__buf_id = 0U;
    }
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf1_state 
        = __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf1_state;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf0_state 
        = __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf0_state;
    if (__Vdlyvset__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__mem__v0) {
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__mem[__Vdlyvdim0__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__mem__v0] 
            = __Vdlyvval__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__mem__v0;
    }
    if (__Vdlyvset__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__mem__v0) {
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__mem[__Vdlyvdim0__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__mem__v0] 
            = __Vdlyvval__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__mem__v0;
    }
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram1__DO 
        = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__read_data;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram0__DO 
        = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__read_data;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_state 
        = __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_state;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_addr 
        = __Vdly__pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_addr;
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_buf_has_data 
        = ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_buf_sel)
            ? ((2U == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf1_state)) 
               | (3U == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf1_state)))
            : ((2U == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf0_state)) 
               | (3U == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf0_state))));
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_beat 
        = ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__rd_ready) 
           & (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__rd_valid));
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_buf_complete 
        = ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_beat) 
           & (0xffU == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_addr)));
    if (vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_sel) {
        vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__0__addr 
            = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_addr;
        vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__0__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__0__addr) 
               << 4U);
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__addr_ram0 
            = vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__0__Vfuncout;
        vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__1__addr 
            = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_addr;
        vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__1__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__1__addr) 
               << 4U);
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__addr_ram1 
            = vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__1__Vfuncout;
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__wr_ready 
            = ((0U == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf1_state)) 
               | (1U == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf1_state)));
    } else {
        vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__2__addr 
            = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_addr;
        vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__2__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__2__addr) 
               << 4U);
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__addr_ram0 
            = vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__2__Vfuncout;
        vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__3__addr 
            = vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_addr;
        vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__3__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__3__addr) 
               << 4U);
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__addr_ram1 
            = vlSelf->__Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__3__Vfuncout;
        vlSelf->pingpong_buffer_sp_tb_simple__DOT__wr_ready 
            = ((0U == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf0_state)) 
               | (1U == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf0_state)));
    }
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__sample_beat 
        = ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__wr_valid) 
           & ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__wr_ready) 
              & (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__sample_ready)));
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wre_ram0 
        = ((1U & (~ (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_sel))) 
           && (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__sample_beat));
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wre_ram1 
        = ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_sel) 
           && (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__sample_beat));
    vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_complete 
        = ((IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__sample_beat) 
           & (0xffU == (IData)(vlSelf->pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_addr)));
}

void Vpingpong_buffer_sp_tb_simple___024root___eval_nba(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___eval_nba\n"); );
    // Body
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vpingpong_buffer_sp_tb_simple___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
}

void Vpingpong_buffer_sp_tb_simple___024root___timing_resume(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___timing_resume\n"); );
    // Body
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h28b425f1__0.resume("@(posedge pingpong_buffer_sp_tb_simple.clk)");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vpingpong_buffer_sp_tb_simple___024root___timing_commit(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___timing_commit\n"); );
    // Body
    if ((! (4ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h28b425f1__0.commit("@(posedge pingpong_buffer_sp_tb_simple.clk)");
    }
}

void Vpingpong_buffer_sp_tb_simple___024root___eval_triggers__act(Vpingpong_buffer_sp_tb_simple___024root* vlSelf);

bool Vpingpong_buffer_sp_tb_simple___024root___eval_phase__act(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vpingpong_buffer_sp_tb_simple___024root___eval_triggers__act(vlSelf);
    Vpingpong_buffer_sp_tb_simple___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vpingpong_buffer_sp_tb_simple___024root___timing_resume(vlSelf);
        Vpingpong_buffer_sp_tb_simple___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vpingpong_buffer_sp_tb_simple___024root___eval_phase__nba(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vpingpong_buffer_sp_tb_simple___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpingpong_buffer_sp_tb_simple___024root___dump_triggers__nba(Vpingpong_buffer_sp_tb_simple___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vpingpong_buffer_sp_tb_simple___024root___dump_triggers__act(Vpingpong_buffer_sp_tb_simple___024root* vlSelf);
#endif  // VL_DEBUG

void Vpingpong_buffer_sp_tb_simple___024root___eval(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vpingpong_buffer_sp_tb_simple___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("pingpong_buffer_sp_tb_simple.sv", 6, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vpingpong_buffer_sp_tb_simple___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("pingpong_buffer_sp_tb_simple.sv", 6, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vpingpong_buffer_sp_tb_simple___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vpingpong_buffer_sp_tb_simple___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vpingpong_buffer_sp_tb_simple___024root___eval_debug_assertions(Vpingpong_buffer_sp_tb_simple___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_buffer_sp_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_buffer_sp_tb_simple___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
