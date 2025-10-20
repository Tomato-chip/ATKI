// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vi2s_clock_gen_tb_debug.h for the primary calling header

#include "Vi2s_clock_gen_tb_debug__pch.h"
#include "Vi2s_clock_gen_tb_debug__Syms.h"
#include "Vi2s_clock_gen_tb_debug___024root.h"

// Parameter definitions for Vi2s_clock_gen_tb_debug___024root
constexpr CData/*0:0*/ Vi2s_clock_gen_tb_debug___024root::i2s_clock_gen_tb_debug__DOT__dut__DOT__WS_POL;
constexpr CData/*0:0*/ Vi2s_clock_gen_tb_debug___024root::i2s_clock_gen_tb_debug__DOT__dut__DOT__FRAME_PULSE_EN;
constexpr IData/*31:0*/ Vi2s_clock_gen_tb_debug___024root::i2s_clock_gen_tb_debug__DOT__SCK_DIV;
constexpr IData/*31:0*/ Vi2s_clock_gen_tb_debug___024root::i2s_clock_gen_tb_debug__DOT__SCKS_PER_FRAME;
constexpr IData/*31:0*/ Vi2s_clock_gen_tb_debug___024root::i2s_clock_gen_tb_debug__DOT__dut__DOT__SYS_CLK_HZ;
constexpr IData/*31:0*/ Vi2s_clock_gen_tb_debug___024root::i2s_clock_gen_tb_debug__DOT__dut__DOT__SCK_DIV;
constexpr IData/*31:0*/ Vi2s_clock_gen_tb_debug___024root::i2s_clock_gen_tb_debug__DOT__dut__DOT__SCKS_PER_FRAME;
constexpr IData/*31:0*/ Vi2s_clock_gen_tb_debug___024root::i2s_clock_gen_tb_debug__DOT__dut__DOT__SCK_HZ;
constexpr IData/*31:0*/ Vi2s_clock_gen_tb_debug___024root::i2s_clock_gen_tb_debug__DOT__dut__DOT__WS_HZ;
constexpr IData/*31:0*/ Vi2s_clock_gen_tb_debug___024root::i2s_clock_gen_tb_debug__DOT__dut__DOT__SCK_CTR_WIDTH;
constexpr IData/*31:0*/ Vi2s_clock_gen_tb_debug___024root::i2s_clock_gen_tb_debug__DOT__dut__DOT__WS_CTR_WIDTH;
constexpr IData/*31:0*/ Vi2s_clock_gen_tb_debug___024root::i2s_clock_gen_tb_debug__DOT__dut__DOT__SCK_HALF_HIGH;
constexpr IData/*31:0*/ Vi2s_clock_gen_tb_debug___024root::i2s_clock_gen_tb_debug__DOT__dut__DOT__SCK_HALF_LOW;


void Vi2s_clock_gen_tb_debug___024root___ctor_var_reset(Vi2s_clock_gen_tb_debug___024root* vlSelf);

Vi2s_clock_gen_tb_debug___024root::Vi2s_clock_gen_tb_debug___024root(Vi2s_clock_gen_tb_debug__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vi2s_clock_gen_tb_debug___024root___ctor_var_reset(this);
}

void Vi2s_clock_gen_tb_debug___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vi2s_clock_gen_tb_debug___024root::~Vi2s_clock_gen_tb_debug___024root() {
}
