// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vi2s_clock_gen_tb_simple__Syms.h"


VL_ATTR_COLD void Vi2s_clock_gen_tb_simple___024root__trace_init_sub__TOP__0(Vi2s_clock_gen_tb_simple___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_simple___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("i2s_clock_gen_tb_simple", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+15,0,"SYS_CLK_HZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+16,0,"SCK_DIV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+17,0,"SCKS_PER_FRAME",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+18,0,"WS_POL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+19,0,"FRAME_PULSE_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+16,0,"EXPECTED_SCK_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+20,0,"EXPECTED_WS_HALF_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+21,0,"SIM_WS_PERIODS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+22,0,"SIM_CYCLES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+13,0,"clk_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"sck_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"ws_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"frame_start_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"cycle_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+5,0,"sck_toggle_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+6,0,"ws_toggle_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+7,0,"sck_prev",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"ws_prev",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+15,0,"SYS_CLK_HZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+16,0,"SCK_DIV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+17,0,"SCKS_PER_FRAME",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+18,0,"WS_POL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+19,0,"FRAME_PULSE_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+13,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"sck_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"ws_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"frame_start_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+23,0,"SCK_HZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+24,0,"WS_HZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+25,0,"SCK_CTR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+26,0,"WS_CTR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+21,0,"SCK_HALF_HIGH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+21,0,"SCK_HALF_LOW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+9,0,"sck_ctr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1,0,"sck_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"sck_tick",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"sck_falling_edge",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"sck_prev_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+12,0,"ws_ctr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+2,0,"ws_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"frame_start_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vi2s_clock_gen_tb_simple___024root__trace_init_top(Vi2s_clock_gen_tb_simple___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_simple___024root__trace_init_top\n"); );
    // Body
    Vi2s_clock_gen_tb_simple___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vi2s_clock_gen_tb_simple___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vi2s_clock_gen_tb_simple___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vi2s_clock_gen_tb_simple___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vi2s_clock_gen_tb_simple___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vi2s_clock_gen_tb_simple___024root__trace_register(Vi2s_clock_gen_tb_simple___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_simple___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vi2s_clock_gen_tb_simple___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vi2s_clock_gen_tb_simple___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vi2s_clock_gen_tb_simple___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vi2s_clock_gen_tb_simple___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vi2s_clock_gen_tb_simple___024root__trace_const_0_sub_0(Vi2s_clock_gen_tb_simple___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vi2s_clock_gen_tb_simple___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_simple___024root__trace_const_0\n"); );
    // Init
    Vi2s_clock_gen_tb_simple___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vi2s_clock_gen_tb_simple___024root*>(voidSelf);
    Vi2s_clock_gen_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vi2s_clock_gen_tb_simple___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vi2s_clock_gen_tb_simple___024root__trace_const_0_sub_0(Vi2s_clock_gen_tb_simple___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_simple___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+15,(0x19bfcc0U),32);
    bufp->fullIData(oldp+16,(8U),32);
    bufp->fullIData(oldp+17,(0x40U),32);
    bufp->fullBit(oldp+18,(0U));
    bufp->fullBit(oldp+19,(1U));
    bufp->fullIData(oldp+20,(0x200U),32);
    bufp->fullIData(oldp+21,(4U),32);
    bufp->fullIData(oldp+22,(0x13e8U),32);
    bufp->fullIData(oldp+23,(0x337f98U),32);
    bufp->fullIData(oldp+24,(0xcdfeU),32);
    bufp->fullIData(oldp+25,(3U),32);
    bufp->fullIData(oldp+26,(6U),32);
    bufp->fullBit(oldp+27,(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_tick));
}

VL_ATTR_COLD void Vi2s_clock_gen_tb_simple___024root__trace_full_0_sub_0(Vi2s_clock_gen_tb_simple___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vi2s_clock_gen_tb_simple___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_simple___024root__trace_full_0\n"); );
    // Init
    Vi2s_clock_gen_tb_simple___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vi2s_clock_gen_tb_simple___024root*>(voidSelf);
    Vi2s_clock_gen_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vi2s_clock_gen_tb_simple___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vi2s_clock_gen_tb_simple___024root__trace_full_0_sub_0(Vi2s_clock_gen_tb_simple___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_simple__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_simple___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_q));
    bufp->fullBit(oldp+2,(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__ws_q));
    bufp->fullBit(oldp+3,(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__frame_start_q));
    bufp->fullIData(oldp+4,(vlSelf->i2s_clock_gen_tb_simple__DOT__cycle_count),32);
    bufp->fullIData(oldp+5,(vlSelf->i2s_clock_gen_tb_simple__DOT__sck_toggle_count),32);
    bufp->fullIData(oldp+6,(vlSelf->i2s_clock_gen_tb_simple__DOT__ws_toggle_count),32);
    bufp->fullBit(oldp+7,(vlSelf->i2s_clock_gen_tb_simple__DOT__sck_prev));
    bufp->fullBit(oldp+8,(vlSelf->i2s_clock_gen_tb_simple__DOT__ws_prev));
    bufp->fullCData(oldp+9,(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_ctr_q),3);
    bufp->fullBit(oldp+10,(((~ (IData)(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_q)) 
                            & (IData)(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_prev_q))));
    bufp->fullBit(oldp+11,(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__sck_prev_q));
    bufp->fullCData(oldp+12,(vlSelf->i2s_clock_gen_tb_simple__DOT__dut__DOT__ws_ctr_q),6);
    bufp->fullBit(oldp+13,(vlSelf->i2s_clock_gen_tb_simple__DOT__clk_i));
    bufp->fullBit(oldp+14,(vlSelf->i2s_clock_gen_tb_simple__DOT__rst_ni));
}
