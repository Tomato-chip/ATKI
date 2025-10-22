// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vi2s_integration_tb__Syms.h"


VL_ATTR_COLD void Vi2s_integration_tb___024root__trace_init_sub__TOP__0(Vi2s_integration_tb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("i2s_integration_tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+35,0,"SYS_CLK_HZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+36,0,"SCK_DIV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+37,0,"SCKS_PER_FRAME",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+38,0,"WS_POL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declDouble(c+39,0,"SYS_CLK_PERIOD_NS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBus(c+41,0,"TEST_LEFT_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+42,0,"TEST_RIGHT_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+43,0,"TEST_LEFT_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+44,0,"TEST_RIGHT_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+45,0,"TEST_LEFT_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+46,0,"TEST_RIGHT_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+31,0,"clk_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"sck_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"ws_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"frame_start_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"sd_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"left_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+6,0,"right_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+7,0,"ready_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+33,0,"test_num",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+8,0,"error_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+9,0,"ready_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+10,0,"current_pattern",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+11,0,"bit_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+12,0,"ws_prev",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"sck_prev",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"ws_edge",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"sck_rising",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"sck_falling",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"init_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"check_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_capture", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+31,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"sck_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"ws_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"sd_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"left_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+6,0,"right_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+7,0,"ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"sck_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"ws_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"sck_rise",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"ws_edge",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+22,0,"shift25_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declBus(c+23,0,"cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+24,0,"left_done_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"right_done_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"channel_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_clk_gen", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+35,0,"SYS_CLK_HZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+36,0,"SCK_DIV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+37,0,"SCKS_PER_FRAME",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+38,0,"WS_POL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+47,0,"FRAME_PULSE_EN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+31,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"sck_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"ws_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"frame_start_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+48,0,"SCK_HZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+49,0,"WS_HZ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+50,0,"SCK_CTR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+51,0,"WS_CTR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+52,0,"SCK_HALF_HIGH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+52,0,"SCK_HALF_LOW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+27,0,"sck_ctr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1,0,"sck_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"sck_tick",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"sck_falling_edge",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"sck_prev_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+30,0,"ws_ctr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+2,0,"ws_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"frame_start_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vi2s_integration_tb___024root__trace_init_top(Vi2s_integration_tb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root__trace_init_top\n"); );
    // Body
    Vi2s_integration_tb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vi2s_integration_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vi2s_integration_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vi2s_integration_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vi2s_integration_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vi2s_integration_tb___024root__trace_register(Vi2s_integration_tb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vi2s_integration_tb___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vi2s_integration_tb___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vi2s_integration_tb___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vi2s_integration_tb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vi2s_integration_tb___024root__trace_const_0_sub_0(Vi2s_integration_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vi2s_integration_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root__trace_const_0\n"); );
    // Init
    Vi2s_integration_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vi2s_integration_tb___024root*>(voidSelf);
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vi2s_integration_tb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vi2s_integration_tb___024root__trace_const_0_sub_0(Vi2s_integration_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+35,(0x19bfcc0U),32);
    bufp->fullIData(oldp+36,(8U),32);
    bufp->fullIData(oldp+37,(0x20U),32);
    bufp->fullBit(oldp+38,(0U));
    bufp->fullDouble(oldp+39,(3.70370370370370381e+01));
    bufp->fullIData(oldp+41,(0xa5a5a5U),24);
    bufp->fullIData(oldp+42,(0x5a5a5aU),24);
    bufp->fullIData(oldp+43,(0x123456U),24);
    bufp->fullIData(oldp+44,(0x789abcU),24);
    bufp->fullIData(oldp+45,(0xdef012U),24);
    bufp->fullIData(oldp+46,(0x345678U),24);
    bufp->fullBit(oldp+47,(1U));
    bufp->fullIData(oldp+48,(0x337f98U),32);
    bufp->fullIData(oldp+49,(0x19bfcU),32);
    bufp->fullIData(oldp+50,(3U),32);
    bufp->fullIData(oldp+51,(6U),32);
    bufp->fullIData(oldp+52,(4U),32);
    bufp->fullBit(oldp+53,(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_tick));
}

VL_ATTR_COLD void Vi2s_integration_tb___024root__trace_full_0_sub_0(Vi2s_integration_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vi2s_integration_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root__trace_full_0\n"); );
    // Init
    Vi2s_integration_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vi2s_integration_tb___024root*>(voidSelf);
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vi2s_integration_tb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vi2s_integration_tb___024root__trace_full_0_sub_0(Vi2s_integration_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_integration_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_integration_tb___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q));
    bufp->fullBit(oldp+2,(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__ws_q));
    bufp->fullBit(oldp+3,(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__frame_start_q));
    bufp->fullBit(oldp+4,(((0x18U >= (0x1fU & vlSelf->i2s_integration_tb__DOT__bit_index)) 
                           && (1U & (vlSelf->i2s_integration_tb__DOT__current_pattern 
                                     >> (0x1fU & vlSelf->i2s_integration_tb__DOT__bit_index))))));
    bufp->fullIData(oldp+5,(vlSelf->i2s_integration_tb__DOT__left_o),24);
    bufp->fullIData(oldp+6,(vlSelf->i2s_integration_tb__DOT__right_o),24);
    bufp->fullBit(oldp+7,(vlSelf->i2s_integration_tb__DOT__ready_o));
    bufp->fullIData(oldp+8,(vlSelf->i2s_integration_tb__DOT__error_count),32);
    bufp->fullIData(oldp+9,(vlSelf->i2s_integration_tb__DOT__ready_count),32);
    bufp->fullIData(oldp+10,(vlSelf->i2s_integration_tb__DOT__current_pattern),25);
    bufp->fullIData(oldp+11,(vlSelf->i2s_integration_tb__DOT__bit_index),32);
    bufp->fullBit(oldp+12,(vlSelf->i2s_integration_tb__DOT__ws_prev));
    bufp->fullBit(oldp+13,(vlSelf->i2s_integration_tb__DOT__sck_prev));
    bufp->fullBit(oldp+14,(vlSelf->i2s_integration_tb__DOT__ws_edge));
    bufp->fullBit(oldp+15,(((~ (IData)(vlSelf->i2s_integration_tb__DOT__sck_prev)) 
                            & (IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q))));
    bufp->fullBit(oldp+16,(((~ (IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q)) 
                            & (IData)(vlSelf->i2s_integration_tb__DOT__sck_prev))));
    bufp->fullBit(oldp+17,(vlSelf->i2s_integration_tb__DOT__init_done));
    bufp->fullBit(oldp+18,(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__sck_d));
    bufp->fullBit(oldp+19,(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__ws_d));
    bufp->fullBit(oldp+20,(((~ (IData)(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__sck_d)) 
                            & (IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q))));
    bufp->fullBit(oldp+21,(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__ws_edge));
    bufp->fullIData(oldp+22,(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__shift25_q),25);
    bufp->fullCData(oldp+23,(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__cnt_q),6);
    bufp->fullBit(oldp+24,(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__left_done_q));
    bufp->fullBit(oldp+25,(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__right_done_q));
    bufp->fullBit(oldp+26,(vlSelf->i2s_integration_tb__DOT__u_capture__DOT__channel_q));
    bufp->fullCData(oldp+27,(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_ctr_q),3);
    bufp->fullBit(oldp+28,(((~ (IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_q)) 
                            & (IData)(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_prev_q))));
    bufp->fullBit(oldp+29,(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__sck_prev_q));
    bufp->fullCData(oldp+30,(vlSelf->i2s_integration_tb__DOT__u_clk_gen__DOT__ws_ctr_q),6);
    bufp->fullBit(oldp+31,(vlSelf->i2s_integration_tb__DOT__clk_i));
    bufp->fullBit(oldp+32,(vlSelf->i2s_integration_tb__DOT__rst_ni));
    bufp->fullIData(oldp+33,(vlSelf->i2s_integration_tb__DOT__test_num),32);
    bufp->fullBit(oldp+34,(vlSelf->i2s_integration_tb__DOT__check_enable));
}
