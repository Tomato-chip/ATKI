// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vi2s_clock_gen_tb_verilator__Syms.h"


void Vi2s_clock_gen_tb_verilator___024root__trace_chg_0_sub_0(Vi2s_clock_gen_tb_verilator___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vi2s_clock_gen_tb_verilator___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root__trace_chg_0\n"); );
    // Init
    Vi2s_clock_gen_tb_verilator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vi2s_clock_gen_tb_verilator___024root*>(voidSelf);
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vi2s_clock_gen_tb_verilator___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vi2s_clock_gen_tb_verilator___024root__trace_chg_0_sub_0(Vi2s_clock_gen_tb_verilator___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+0,(vlSelf->i2s_clock_gen_tb_verilator__DOT__rst_ni));
        bufp->chgBit(oldp+1,(vlSelf->i2s_clock_gen_tb_verilator__DOT__test_passed));
        bufp->chgIData(oldp+2,(vlSelf->i2s_clock_gen_tb_verilator__DOT__duty_diff_val),32);
        bufp->chgDouble(oldp+3,(vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_to_sck_ratio_val));
        bufp->chgDouble(oldp+5,(vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk3__DOT__sck_period_avg));
        bufp->chgDouble(oldp+7,(vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk4__DOT__ws_period_avg));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgBit(oldp+9,(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_q));
        bufp->chgBit(oldp+10,(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_q));
        bufp->chgBit(oldp+11,(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__frame_start_q));
        bufp->chgIData(oldp+12,(vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_toggle_count),32);
        bufp->chgIData(oldp+13,(vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_period_sum),32);
        bufp->chgIData(oldp+14,(vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_period_count),32);
        bufp->chgIData(oldp+15,(vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_high_time),32);
        bufp->chgIData(oldp+16,(vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_low_time),32);
        bufp->chgIData(oldp+17,(vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_last_toggle_cycle),32);
        bufp->chgBit(oldp+18,(vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_prev));
        bufp->chgIData(oldp+19,(vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_toggle_count),32);
        bufp->chgIData(oldp+20,(vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_period_sum),32);
        bufp->chgIData(oldp+21,(vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_period_count),32);
        bufp->chgIData(oldp+22,(vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_last_toggle_cycle),32);
        bufp->chgBit(oldp+23,(vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_prev));
        bufp->chgIData(oldp+24,(vlSelf->i2s_clock_gen_tb_verilator__DOT__cycle_count),32);
        bufp->chgIData(oldp+25,(vlSelf->i2s_clock_gen_tb_verilator__DOT__frame_start_count),32);
        bufp->chgIData(oldp+26,(vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_change_on_sck_high_count),32);
        bufp->chgCData(oldp+27,(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_ctr_q),3);
        bufp->chgBit(oldp+28,(((~ (IData)(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_q)) 
                               & (IData)(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_prev_q))));
        bufp->chgBit(oldp+29,(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_prev_q));
        bufp->chgCData(oldp+30,(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_ctr_q),6);
        bufp->chgIData(oldp+31,(vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk1__DOT__period),32);
        bufp->chgIData(oldp+32,(vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk2__DOT__period),32);
    }
    bufp->chgBit(oldp+33,(vlSelf->i2s_clock_gen_tb_verilator__DOT__clk_i));
    bufp->chgIData(oldp+34,(vlSelf->i2s_clock_gen_tb_verilator__DOT__errors),32);
}

void Vi2s_clock_gen_tb_verilator___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root__trace_cleanup\n"); );
    // Init
    Vi2s_clock_gen_tb_verilator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vi2s_clock_gen_tb_verilator___024root*>(voidSelf);
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
