// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vi2s_integration_tb__Syms.h"


void Vi2s_integration_tb___024root__trace_chg_0_sub_0(Vi2s_integration_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vi2s_integration_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root__trace_chg_0\n"); );
    // Init
    Vi2s_integration_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vi2s_integration_tb___024root*>(voidSelf);
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vi2s_integration_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vi2s_integration_tb___024root__trace_chg_0_sub_0(Vi2s_integration_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q));
        bufp->chgBit(oldp+1,(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__ws_q));
        bufp->chgBit(oldp+2,(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__frame_start_q));
        bufp->chgBit(oldp+3,(((0x18U >= (0x1fU & vlSelf->i2s_integration_tb__DOT__bit_index)) 
                              && (1U & (vlSelf->i2s_integration_tb__DOT__current_pattern 
                                        >> (0x1fU & vlSelf->i2s_integration_tb__DOT__bit_index))))));
        bufp->chgIData(oldp+4,(vlSelf->i2s_integration_tb__DOT__left_o),24);
        bufp->chgIData(oldp+5,(vlSelf->i2s_integration_tb__DOT__right_o),24);
        bufp->chgBit(oldp+6,(vlSelf->i2s_integration_tb__DOT__ready_o));
        bufp->chgIData(oldp+7,(vlSelf->i2s_integration_tb__DOT__error_count),32);
        bufp->chgIData(oldp+8,(vlSelf->i2s_integration_tb__DOT__ready_count),32);
        bufp->chgIData(oldp+9,(vlSelf->i2s_integration_tb__DOT__current_pattern),25);
        bufp->chgIData(oldp+10,(vlSelf->i2s_integration_tb__DOT__bit_index),32);
        bufp->chgBit(oldp+11,(vlSelf->i2s_integration_tb__DOT__ws_prev));
        bufp->chgBit(oldp+12,(vlSelf->i2s_integration_tb__DOT__sck_prev));
        bufp->chgBit(oldp+13,(vlSelf->i2s_integration_tb__DOT__ws_edge));
        bufp->chgBit(oldp+14,(((~ (IData)(vlSelf->i2s_integration_tb__DOT__sck_prev)) 
                               & (IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q))));
        bufp->chgBit(oldp+15,(((~ (IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q)) 
                               & (IData)(vlSelf->i2s_integration_tb__DOT__sck_prev))));
        bufp->chgBit(oldp+16,(vlSelf->i2s_integration_tb__DOT__init_done));
        bufp->chgBit(oldp+17,(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__sck_d));
        bufp->chgBit(oldp+18,(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__ws_d));
        bufp->chgBit(oldp+19,(((~ (IData)(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__sck_d)) 
                               & (IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q))));
        bufp->chgBit(oldp+20,(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__ws_edge));
        bufp->chgIData(oldp+21,(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__shift25_q),25);
        bufp->chgCData(oldp+22,(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__cnt_q),6);
        bufp->chgBit(oldp+23,(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__left_done_q));
        bufp->chgBit(oldp+24,(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__right_done_q));
        bufp->chgBit(oldp+25,(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__channel_q));
        bufp->chgCData(oldp+26,(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_ctr_q),3);
        bufp->chgBit(oldp+27,(((~ (IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q)) 
                               & (IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_prev_q))));
        bufp->chgBit(oldp+28,(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_prev_q));
        bufp->chgCData(oldp+29,(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__ws_ctr_q),6);
    }
    bufp->chgBit(oldp+30,(vlSelf->i2s_integration_tb__DOT__clk_i));
    bufp->chgBit(oldp+31,(vlSelf->i2s_integration_tb__DOT__rst_ni));
    bufp->chgIData(oldp+32,(vlSelf->i2s_integration_tb__DOT__test_num),32);
    bufp->chgBit(oldp+33,(vlSelf->i2s_integration_tb__DOT__check_enable));
}

void Vi2s_integration_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root__trace_cleanup\n"); );
    // Init
    Vi2s_integration_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vi2s_integration_tb___024root*>(voidSelf);
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
