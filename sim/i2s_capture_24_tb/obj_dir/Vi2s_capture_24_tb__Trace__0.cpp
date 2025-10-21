// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vi2s_capture_24_tb__Syms.h"


void Vi2s_capture_24_tb___024root__trace_chg_0_sub_0(Vi2s_capture_24_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vi2s_capture_24_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root__trace_chg_0\n"); );
    // Init
    Vi2s_capture_24_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vi2s_capture_24_tb___024root*>(voidSelf);
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vi2s_capture_24_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vi2s_capture_24_tb___024root__trace_chg_0_sub_0(Vi2s_capture_24_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+0,(vlSelf->i2s_capture_24_tb__DOT__rst_ni));
        bufp->chgIData(oldp+1,(vlSelf->i2s_capture_24_tb__DOT__left_pattern_1),24);
        bufp->chgIData(oldp+2,(vlSelf->i2s_capture_24_tb__DOT__right_pattern_1),24);
        bufp->chgIData(oldp+3,(vlSelf->i2s_capture_24_tb__DOT__test_phase),32);
        bufp->chgIData(oldp+4,(vlSelf->i2s_capture_24_tb__DOT__frame_count),32);
        bufp->chgBit(oldp+5,(vlSelf->i2s_capture_24_tb__DOT__test_running));
        bufp->chgIData(oldp+6,(vlSelf->i2s_capture_24_tb__DOT__left_captures),32);
        bufp->chgIData(oldp+7,(vlSelf->i2s_capture_24_tb__DOT__right_captures),32);
        bufp->chgIData(oldp+8,(vlSelf->i2s_capture_24_tb__DOT__ready_pulses),32);
        bufp->chgIData(oldp+9,(vlSelf->i2s_capture_24_tb__DOT__errors),32);
        bufp->chgIData(oldp+10,(vlSelf->i2s_capture_24_tb__DOT__ready_pulse_width),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgBit(oldp+11,(vlSelf->i2s_capture_24_tb__DOT__sck_reg));
        bufp->chgBit(oldp+12,(vlSelf->i2s_capture_24_tb__DOT__ws_reg));
        bufp->chgBit(oldp+13,(vlSelf->i2s_capture_24_tb__DOT__sd_i));
        bufp->chgIData(oldp+14,(vlSelf->i2s_capture_24_tb__DOT__left_o),24);
        bufp->chgIData(oldp+15,(vlSelf->i2s_capture_24_tb__DOT__right_o),24);
        bufp->chgBit(oldp+16,(vlSelf->i2s_capture_24_tb__DOT__ready_o));
        bufp->chgCData(oldp+17,(vlSelf->i2s_capture_24_tb__DOT__sck_counter),3);
        bufp->chgCData(oldp+18,(vlSelf->i2s_capture_24_tb__DOT__sck_edge_counter),6);
        bufp->chgBit(oldp+19,(vlSelf->i2s_capture_24_tb__DOT__sck_prev));
        bufp->chgBit(oldp+20,(((~ (IData)(vlSelf->i2s_capture_24_tb__DOT__sck_prev)) 
                               & (IData)(vlSelf->i2s_capture_24_tb__DOT__sck_reg))));
        bufp->chgBit(oldp+21,(vlSelf->i2s_capture_24_tb__DOT__sck_falling));
        bufp->chgCData(oldp+22,(vlSelf->i2s_capture_24_tb__DOT__bit_index),5);
        bufp->chgIData(oldp+23,(vlSelf->i2s_capture_24_tb__DOT__current_pattern),24);
        bufp->chgBit(oldp+24,(vlSelf->i2s_capture_24_tb__DOT__ws_prev));
        bufp->chgBit(oldp+25,(vlSelf->i2s_capture_24_tb__DOT__new_channel));
        bufp->chgBit(oldp+26,(vlSelf->i2s_capture_24_tb__DOT__ws_edge_det));
        bufp->chgBit(oldp+27,(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__sck_d));
        bufp->chgBit(oldp+28,(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__ws_d));
        bufp->chgBit(oldp+29,(((~ (IData)(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__sck_d)) 
                               & (IData)(vlSelf->i2s_capture_24_tb__DOT__sck_reg))));
        bufp->chgBit(oldp+30,(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__ws_edge));
        bufp->chgIData(oldp+31,(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__shift25_q),25);
        bufp->chgCData(oldp+32,(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__cnt_q),6);
        bufp->chgBit(oldp+33,(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__left_done_q));
        bufp->chgBit(oldp+34,(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__right_done_q));
        bufp->chgBit(oldp+35,(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__channel_q));
    }
    bufp->chgBit(oldp+36,(vlSelf->i2s_capture_24_tb__DOT__clk_i));
}

void Vi2s_capture_24_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root__trace_cleanup\n"); );
    // Init
    Vi2s_capture_24_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vi2s_capture_24_tb___024root*>(voidSelf);
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
