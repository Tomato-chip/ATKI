// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vi2s_capture_24_tb__Syms.h"


VL_ATTR_COLD void Vi2s_capture_24_tb___024root__trace_init_sub__TOP__0(Vi2s_capture_24_tb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("i2s_capture_24_tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+37,0,"clk_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declDouble(c+38,0,"CLK_PERIOD_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBit(c+12,0,"sck_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"ws_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"sd_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+15,0,"left_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+16,0,"right_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+17,0,"ready_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+40,0,"SCK_DIV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declDouble(c+41,0,"SCK_PERIOD_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBus(c+43,0,"SCKS_PER_CHANNEL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+44,0,"SCKS_PER_FRAME",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+2,0,"left_pattern_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+3,0,"right_pattern_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+45,0,"left_pattern_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+46,0,"right_pattern_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+47,0,"left_pattern_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+48,0,"right_pattern_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+49,0,"left_pattern_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+50,0,"right_pattern_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+18,0,"sck_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+12,0,"sck_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+19,0,"sck_edge_counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+13,0,"ws_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"sck_prev",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"sck_rising",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"sck_falling",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+23,0,"bit_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+24,0,"current_pattern",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+25,0,"ws_prev",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"new_channel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"ws_edge_det",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"test_phase",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+5,0,"frame_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+6,0,"test_running",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"left_captures",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+8,0,"right_captures",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+9,0,"ready_pulses",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+10,0,"errors",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+11,0,"ready_pulse_width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+37,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"sck_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"ws_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"sd_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+15,0,"left_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+16,0,"right_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+17,0,"ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"sck_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"ws_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"sck_rise",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"ws_edge",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+32,0,"shift25_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+33,0,"cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+34,0,"left_done_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"right_done_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"channel_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vi2s_capture_24_tb___024root__trace_init_top(Vi2s_capture_24_tb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root__trace_init_top\n"); );
    // Body
    Vi2s_capture_24_tb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vi2s_capture_24_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vi2s_capture_24_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vi2s_capture_24_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vi2s_capture_24_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vi2s_capture_24_tb___024root__trace_register(Vi2s_capture_24_tb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vi2s_capture_24_tb___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vi2s_capture_24_tb___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vi2s_capture_24_tb___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vi2s_capture_24_tb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vi2s_capture_24_tb___024root__trace_const_0_sub_0(Vi2s_capture_24_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vi2s_capture_24_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root__trace_const_0\n"); );
    // Init
    Vi2s_capture_24_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vi2s_capture_24_tb___024root*>(voidSelf);
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vi2s_capture_24_tb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vi2s_capture_24_tb___024root__trace_const_0_sub_0(Vi2s_capture_24_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullDouble(oldp+38,(3.70369999999999990e+01));
    bufp->fullIData(oldp+40,(8U),32);
    bufp->fullDouble(oldp+41,(2.96295999999999992e+02));
    bufp->fullIData(oldp+43,(0x20U),32);
    bufp->fullIData(oldp+44,(0x40U),32);
    bufp->fullIData(oldp+45,(0U),24);
    bufp->fullIData(oldp+46,(0xffffffU),24);
    bufp->fullIData(oldp+47,(0xaaaaaaU),24);
    bufp->fullIData(oldp+48,(0x555555U),24);
    bufp->fullIData(oldp+49,(0x7fffffU),24);
    bufp->fullIData(oldp+50,(0x800000U),24);
}

VL_ATTR_COLD void Vi2s_capture_24_tb___024root__trace_full_0_sub_0(Vi2s_capture_24_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vi2s_capture_24_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root__trace_full_0\n"); );
    // Init
    Vi2s_capture_24_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vi2s_capture_24_tb___024root*>(voidSelf);
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vi2s_capture_24_tb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vi2s_capture_24_tb___024root__trace_full_0_sub_0(Vi2s_capture_24_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->i2s_capture_24_tb__DOT__rst_ni));
    bufp->fullIData(oldp+2,(vlSelf->i2s_capture_24_tb__DOT__left_pattern_1),24);
    bufp->fullIData(oldp+3,(vlSelf->i2s_capture_24_tb__DOT__right_pattern_1),24);
    bufp->fullIData(oldp+4,(vlSelf->i2s_capture_24_tb__DOT__test_phase),32);
    bufp->fullIData(oldp+5,(vlSelf->i2s_capture_24_tb__DOT__frame_count),32);
    bufp->fullBit(oldp+6,(vlSelf->i2s_capture_24_tb__DOT__test_running));
    bufp->fullIData(oldp+7,(vlSelf->i2s_capture_24_tb__DOT__left_captures),32);
    bufp->fullIData(oldp+8,(vlSelf->i2s_capture_24_tb__DOT__right_captures),32);
    bufp->fullIData(oldp+9,(vlSelf->i2s_capture_24_tb__DOT__ready_pulses),32);
    bufp->fullIData(oldp+10,(vlSelf->i2s_capture_24_tb__DOT__errors),32);
    bufp->fullIData(oldp+11,(vlSelf->i2s_capture_24_tb__DOT__ready_pulse_width),32);
    bufp->fullBit(oldp+12,(vlSelf->i2s_capture_24_tb__DOT__sck_reg));
    bufp->fullBit(oldp+13,(vlSelf->i2s_capture_24_tb__DOT__ws_reg));
    bufp->fullBit(oldp+14,(vlSelf->i2s_capture_24_tb__DOT__sd_i));
    bufp->fullIData(oldp+15,(vlSelf->i2s_capture_24_tb__DOT__left_o),24);
    bufp->fullIData(oldp+16,(vlSelf->i2s_capture_24_tb__DOT__right_o),24);
    bufp->fullBit(oldp+17,(vlSelf->i2s_capture_24_tb__DOT__ready_o));
    bufp->fullCData(oldp+18,(vlSelf->i2s_capture_24_tb__DOT__sck_counter),3);
    bufp->fullCData(oldp+19,(vlSelf->i2s_capture_24_tb__DOT__sck_edge_counter),6);
    bufp->fullBit(oldp+20,(vlSelf->i2s_capture_24_tb__DOT__sck_prev));
    bufp->fullBit(oldp+21,(((~ (IData)(vlSelf->i2s_capture_24_tb__DOT__sck_prev)) 
                            & (IData)(vlSelf->i2s_capture_24_tb__DOT__sck_reg))));
    bufp->fullBit(oldp+22,(vlSelf->i2s_capture_24_tb__DOT__sck_falling));
    bufp->fullCData(oldp+23,(vlSelf->i2s_capture_24_tb__DOT__bit_index),5);
    bufp->fullIData(oldp+24,(vlSelf->i2s_capture_24_tb__DOT__current_pattern),24);
    bufp->fullBit(oldp+25,(vlSelf->i2s_capture_24_tb__DOT__ws_prev));
    bufp->fullBit(oldp+26,(vlSelf->i2s_capture_24_tb__DOT__new_channel));
    bufp->fullBit(oldp+27,(vlSelf->i2s_capture_24_tb__DOT__ws_edge_det));
    bufp->fullBit(oldp+28,(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__sck_d));
    bufp->fullBit(oldp+29,(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__ws_d));
    bufp->fullBit(oldp+30,(((~ (IData)(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__sck_d)) 
                            & (IData)(vlSelf->i2s_capture_24_tb__DOT__sck_reg))));
    bufp->fullBit(oldp+31,(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__ws_edge));
    bufp->fullIData(oldp+32,(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__shift25_q),25);
    bufp->fullCData(oldp+33,(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__cnt_q),6);
    bufp->fullBit(oldp+34,(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__left_done_q));
    bufp->fullBit(oldp+35,(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__right_done_q));
    bufp->fullBit(oldp+36,(vlSelf->i2s_capture_24_tb__DOT__dut__DOT__channel_q));
    bufp->fullBit(oldp+37,(vlSelf->i2s_capture_24_tb__DOT__clk_i));
}
