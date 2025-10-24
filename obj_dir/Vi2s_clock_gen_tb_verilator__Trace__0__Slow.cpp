// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vi2s_clock_gen_tb_verilator__Syms.h"


VL_ATTR_COLD void Vi2s_clock_gen_tb_verilator___024root__trace_init_sub__TOP__0(Vi2s_clock_gen_tb_verilator___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("i2s_clock_gen_tb_verilator", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+36,0,"SYS_CLK_HZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+37,0,"SCK_DIV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+38,0,"SCKS_PER_FRAME",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+39,0,"WS_POL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+40,0,"FRAME_PULSE_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+37,0,"EXPECTED_SCK_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+41,0,"EXPECTED_WS_HALF_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+42,0,"EXPECTED_WS_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declDouble(c+43,0,"SYS_CLK_PERIOD_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+45,0,"SCK_FREQ_HZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+47,0,"WS_FREQ_HZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBus(c+49,0,"SIM_WS_PERIODS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+50,0,"SIM_TIMEOUT_CYCLES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+34,0,"clk_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"sck_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"ws_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"frame_start_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+13,0,"sck_toggle_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+14,0,"sck_period_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+15,0,"sck_period_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+16,0,"sck_high_time",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+17,0,"sck_low_time",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+18,0,"sck_last_toggle_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+19,0,"sck_prev",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+20,0,"ws_toggle_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+21,0,"ws_period_sum",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+22,0,"ws_period_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+23,0,"ws_last_toggle_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+24,0,"ws_prev",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+25,0,"cycle_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+26,0,"frame_start_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+2,0,"test_passed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+35,0,"errors",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+27,0,"ws_change_on_sck_high_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+3,0,"duty_diff_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declDouble(c+4,0,"ws_to_sck_ratio_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+36,0,"SYS_CLK_HZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+37,0,"SCK_DIV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+38,0,"SCKS_PER_FRAME",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+39,0,"WS_POL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+40,0,"FRAME_PULSE_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+34,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"sck_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"ws_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"frame_start_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+51,0,"SCK_HZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+52,0,"WS_HZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+53,0,"SCK_CTR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+54,0,"WS_CTR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+49,0,"SCK_HALF_HIGH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+49,0,"SCK_HALF_LOW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+28,0,"sck_ctr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+10,0,"sck_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"sck_tick",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"sck_falling_edge",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"sck_prev_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"ws_ctr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+11,0,"ws_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"frame_start_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+32,0,"period",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+33,0,"period",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declDouble(c+6,0,"sck_period_avg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declDouble(c+8,0,"ws_period_avg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vi2s_clock_gen_tb_verilator___024root__trace_init_top(Vi2s_clock_gen_tb_verilator___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root__trace_init_top\n"); );
    // Body
    Vi2s_clock_gen_tb_verilator___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vi2s_clock_gen_tb_verilator___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vi2s_clock_gen_tb_verilator___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vi2s_clock_gen_tb_verilator___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vi2s_clock_gen_tb_verilator___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vi2s_clock_gen_tb_verilator___024root__trace_register(Vi2s_clock_gen_tb_verilator___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vi2s_clock_gen_tb_verilator___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vi2s_clock_gen_tb_verilator___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vi2s_clock_gen_tb_verilator___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vi2s_clock_gen_tb_verilator___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vi2s_clock_gen_tb_verilator___024root__trace_const_0_sub_0(Vi2s_clock_gen_tb_verilator___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vi2s_clock_gen_tb_verilator___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root__trace_const_0\n"); );
    // Init
    Vi2s_clock_gen_tb_verilator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vi2s_clock_gen_tb_verilator___024root*>(voidSelf);
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vi2s_clock_gen_tb_verilator___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vi2s_clock_gen_tb_verilator___024root__trace_const_0_sub_0(Vi2s_clock_gen_tb_verilator___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+36,(0x19bfcc0U),32);
    bufp->fullIData(oldp+37,(8U),32);
    bufp->fullIData(oldp+38,(0x40U),32);
    bufp->fullBit(oldp+39,(0U));
    bufp->fullBit(oldp+40,(1U));
    bufp->fullIData(oldp+41,(0x200U),32);
    bufp->fullIData(oldp+42,(0x400U),32);
    bufp->fullDouble(oldp+43,(3.70370370370370381e+01));
    bufp->fullDouble(oldp+45,(3.37500000000000000e+06));
    bufp->fullDouble(oldp+47,(5.27343750000000000e+04));
    bufp->fullIData(oldp+49,(4U),32);
    bufp->fullIData(oldp+50,(0x3000U),32);
    bufp->fullIData(oldp+51,(0x337f98U),32);
    bufp->fullIData(oldp+52,(0xcdfeU),32);
    bufp->fullIData(oldp+53,(3U),32);
    bufp->fullIData(oldp+54,(6U),32);
    bufp->fullBit(oldp+55,(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_tick));
}

VL_ATTR_COLD void Vi2s_clock_gen_tb_verilator___024root__trace_full_0_sub_0(Vi2s_clock_gen_tb_verilator___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vi2s_clock_gen_tb_verilator___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root__trace_full_0\n"); );
    // Init
    Vi2s_clock_gen_tb_verilator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vi2s_clock_gen_tb_verilator___024root*>(voidSelf);
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vi2s_clock_gen_tb_verilator___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vi2s_clock_gen_tb_verilator___024root__trace_full_0_sub_0(Vi2s_clock_gen_tb_verilator___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->i2s_clock_gen_tb_verilator__DOT__rst_ni));
    bufp->fullBit(oldp+2,(vlSelf->i2s_clock_gen_tb_verilator__DOT__test_passed));
    bufp->fullIData(oldp+3,(vlSelf->i2s_clock_gen_tb_verilator__DOT__duty_diff_val),32);
    bufp->fullDouble(oldp+4,(vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_to_sck_ratio_val));
    bufp->fullDouble(oldp+6,(vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk3__DOT__sck_period_avg));
    bufp->fullDouble(oldp+8,(vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk4__DOT__ws_period_avg));
    bufp->fullBit(oldp+10,(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_q));
    bufp->fullBit(oldp+11,(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_q));
    bufp->fullBit(oldp+12,(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__frame_start_q));
    bufp->fullIData(oldp+13,(vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_toggle_count),32);
    bufp->fullIData(oldp+14,(vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_period_sum),32);
    bufp->fullIData(oldp+15,(vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_period_count),32);
    bufp->fullIData(oldp+16,(vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_high_time),32);
    bufp->fullIData(oldp+17,(vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_low_time),32);
    bufp->fullIData(oldp+18,(vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_last_toggle_cycle),32);
    bufp->fullBit(oldp+19,(vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_prev));
    bufp->fullIData(oldp+20,(vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_toggle_count),32);
    bufp->fullIData(oldp+21,(vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_period_sum),32);
    bufp->fullIData(oldp+22,(vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_period_count),32);
    bufp->fullIData(oldp+23,(vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_last_toggle_cycle),32);
    bufp->fullBit(oldp+24,(vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_prev));
    bufp->fullIData(oldp+25,(vlSelf->i2s_clock_gen_tb_verilator__DOT__cycle_count),32);
    bufp->fullIData(oldp+26,(vlSelf->i2s_clock_gen_tb_verilator__DOT__frame_start_count),32);
    bufp->fullIData(oldp+27,(vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_change_on_sck_high_count),32);
    bufp->fullCData(oldp+28,(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_ctr_q),3);
    bufp->fullBit(oldp+29,(((~ (IData)(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_q)) 
                            & (IData)(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_prev_q))));
    bufp->fullBit(oldp+30,(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_prev_q));
    bufp->fullCData(oldp+31,(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_ctr_q),6);
    bufp->fullIData(oldp+32,(vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk1__DOT__period),32);
    bufp->fullIData(oldp+33,(vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk2__DOT__period),32);
    bufp->fullBit(oldp+34,(vlSelf->i2s_clock_gen_tb_verilator__DOT__clk_i));
    bufp->fullIData(oldp+35,(vlSelf->i2s_clock_gen_tb_verilator__DOT__errors),32);
}
