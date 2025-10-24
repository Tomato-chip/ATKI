// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vi2s_clock_gen_tb_simple__Syms.h"


void Vi2s_clock_gen_tb_simple___024root__trace_chg_0_sub_0(Vi2s_clock_gen_tb_simple___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vi2s_clock_gen_tb_simple___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_simple___024root__trace_chg_0\n"); );
    // Init
    Vi2s_clock_gen_tb_simple___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vi2s_clock_gen_tb_simple___024root*>(voidSelf);
    Vi2s_clock_gen_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vi2s_clock_gen_tb_simple___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vi2s_clock_gen_tb_simple___024root__trace_chg_0_sub_0(Vi2s_clock_gen_tb_simple___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_simple___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_q));
        bufp->chgBit(oldp+1,(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__ws_q));
        bufp->chgBit(oldp+2,(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__frame_start_q));
        bufp->chgIData(oldp+3,(vlSelf->i2s_clock_gen_tb_simple__DOT__cycle_count),32);
        bufp->chgIData(oldp+4,(vlSelf->i2s_clock_gen_tb_simple__DOT__sck_toggle_count),32);
        bufp->chgIData(oldp+5,(vlSelf->i2s_clock_gen_tb_simple__DOT__ws_toggle_count),32);
        bufp->chgBit(oldp+6,(vlSelf->i2s_clock_gen_tb_simple__DOT__sck_prev));
        bufp->chgBit(oldp+7,(vlSelf->i2s_clock_gen_tb_simple__DOT__ws_prev));
        bufp->chgCData(oldp+8,(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_ctr_q),3);
        bufp->chgBit(oldp+9,(((~ (IData)(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_q)) 
                              & (IData)(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_prev_q))));
        bufp->chgBit(oldp+10,(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_prev_q));
        bufp->chgCData(oldp+11,(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__ws_ctr_q),6);
    }
    bufp->chgBit(oldp+12,(vlSelf->i2s_clock_gen_tb_simple__DOT__clk_i));
    bufp->chgBit(oldp+13,(vlSelf->i2s_clock_gen_tb_simple__DOT__rst_ni));
}

void Vi2s_clock_gen_tb_simple___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_simple___024root__trace_cleanup\n"); );
    // Init
    Vi2s_clock_gen_tb_simple___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vi2s_clock_gen_tb_simple___024root*>(voidSelf);
    Vi2s_clock_gen_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
