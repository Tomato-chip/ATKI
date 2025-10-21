// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpingpong_sp_ram_tb.h for the primary calling header

#include "Vpingpong_sp_ram_tb__pch.h"
#include "Vpingpong_sp_ram_tb__Syms.h"
#include "Vpingpong_sp_ram_tb___024root.h"

VL_INLINE_OPT VlCoroutine Vpingpong_sp_ram_tb___024root___eval_initial__TOP__Vtiming__1(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Init
    SData/*15:0*/ pingpong_sp_ram_tb__DOT__expected_data;
    pingpong_sp_ram_tb__DOT__expected_data = 0;
    IData/*31:0*/ pingpong_sp_ram_tb__DOT__i;
    pingpong_sp_ram_tb__DOT__i = 0;
    // Body
    VL_WRITEF("============================================\nPing-Pong SP RAM Testbench\n============================================\n\n");
    vlSelf->pingpong_sp_ram_tb__DOT__rst_ni = 0U;
    vlSelf->pingpong_sp_ram_tb__DOT__in_valid_i = 0U;
    vlSelf->pingpong_sp_ram_tb__DOT__in_data_i = 0U;
    vlSelf->pingpong_sp_ram_tb__DOT__rd_en_i = 0U;
    vlSelf->pingpong_sp_ram_tb__DOT__rd_addr_i = 0U;
    co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                       "sim/pingpong_sp_ram_tb.sv", 
                                                       76);
    co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                       "sim/pingpong_sp_ram_tb.sv", 
                                                       76);
    co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                       "sim/pingpong_sp_ram_tb.sv", 
                                                       76);
    co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                       "sim/pingpong_sp_ram_tb.sv", 
                                                       76);
    co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                       "sim/pingpong_sp_ram_tb.sv", 
                                                       76);
    vlSelf->pingpong_sp_ram_tb__DOT__rst_ni = 1U;
    co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                       "sim/pingpong_sp_ram_tb.sv", 
                                                       78);
    VL_WRITEF("[Test 1] Initial state check\n");
    if (VL_UNLIKELY(vlSelf->pingpong_sp_ram_tb__DOT__active_buf_o)) {
        VL_WRITEF("  ERROR: active_buf_o should be 0 after reset, got %b\n",
                  1,vlSelf->pingpong_sp_ram_tb__DOT__active_buf_o);
        vlSelf->pingpong_sp_ram_tb__DOT__errors = ((IData)(1U) 
                                                   + vlSelf->pingpong_sp_ram_tb__DOT__errors);
    }
    if (VL_UNLIKELY(vlSelf->pingpong_sp_ram_tb__DOT__buf_ready_pulse_o)) {
        VL_WRITEF("  ERROR: buf_ready_pulse_o should be 0 after reset, got %b\n",
                  1,vlSelf->pingpong_sp_ram_tb__DOT__buf_ready_pulse_o);
        vlSelf->pingpong_sp_ram_tb__DOT__errors = ((IData)(1U) 
                                                   + vlSelf->pingpong_sp_ram_tb__DOT__errors);
    }
    VL_WRITEF("  PASS: Initial state correct\n\n[Test 2] Writing 256 samples to buffer A (active_buf_o=0)\n");
    pingpong_sp_ram_tb__DOT__i = 0U;
    while (VL_GTS_III(32, 0x100U, pingpong_sp_ram_tb__DOT__i)) {
        co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                           "sim/pingpong_sp_ram_tb.sv", 
                                                           94);
        vlSelf->pingpong_sp_ram_tb__DOT__in_valid_i = 1U;
        vlSelf->pingpong_sp_ram_tb__DOT__in_data_i 
            = (0xffffU & ((IData)(0xa000U) + pingpong_sp_ram_tb__DOT__i));
        pingpong_sp_ram_tb__DOT__i = ((IData)(1U) + pingpong_sp_ram_tb__DOT__i);
    }
    co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                       "sim/pingpong_sp_ram_tb.sv", 
                                                       100);
    vlSelf->pingpong_sp_ram_tb__DOT__in_valid_i = 0U;
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "sim/pingpong_sp_ram_tb.sv", 
                                       102);
    VL_WRITEF("  Debug: After 256 writes, active_buf_o=%b, buf_ready_pulse_o=%b\n",
              1,vlSelf->pingpong_sp_ram_tb__DOT__active_buf_o,
              1,(IData)(vlSelf->pingpong_sp_ram_tb__DOT__buf_ready_pulse_o));
    if (VL_UNLIKELY(vlSelf->pingpong_sp_ram_tb__DOT__buf_ready_pulse_o)) {
        VL_WRITEF("  ERROR: buf_ready_pulse_o should be LOW (1-cycle pulse already passed)\n");
        vlSelf->pingpong_sp_ram_tb__DOT__errors = ((IData)(1U) 
                                                   + vlSelf->pingpong_sp_ram_tb__DOT__errors);
    }
    if (VL_UNLIKELY(vlSelf->pingpong_sp_ram_tb__DOT__buf_ready_id_o)) {
        VL_WRITEF("  ERROR: buf_ready_id_o should be 0 (buffer A was filled)\n");
        vlSelf->pingpong_sp_ram_tb__DOT__errors = ((IData)(1U) 
                                                   + vlSelf->pingpong_sp_ram_tb__DOT__errors);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->pingpong_sp_ram_tb__DOT__active_buf_o))))) {
        VL_WRITEF("  ERROR: active_buf_o should be 1 after 256 writes to buffer A\n");
        vlSelf->pingpong_sp_ram_tb__DOT__errors = ((IData)(1U) 
                                                   + vlSelf->pingpong_sp_ram_tb__DOT__errors);
    }
    VL_WRITEF("  PASS: 256 samples written, buffer toggled\n\n[Test 3] Reading from buffer A with 1-cycle pipeline latency\n");
    co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                       "sim/pingpong_sp_ram_tb.sv", 
                                                       126);
    vlSelf->pingpong_sp_ram_tb__DOT__rd_en_i = 1U;
    vlSelf->pingpong_sp_ram_tb__DOT__rd_addr_i = 0U;
    pingpong_sp_ram_tb__DOT__expected_data = 0xa000U;
    co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                       "sim/pingpong_sp_ram_tb.sv", 
                                                       132);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "sim/pingpong_sp_ram_tb.sv", 
                                       133);
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__rd_valid_q))))) {
        VL_WRITEF("  ERROR: rd_valid_o should be HIGH after 1-cycle latency\n");
        vlSelf->pingpong_sp_ram_tb__DOT__errors = ((IData)(1U) 
                                                   + vlSelf->pingpong_sp_ram_tb__DOT__errors);
    }
    if (((IData)(vlSelf->pingpong_sp_ram_tb__DOT__rd_data_o) 
         != (IData)(pingpong_sp_ram_tb__DOT__expected_data))) {
        VL_WRITEF("  ERROR: Expected 0x%04x, got 0x%04x\n",
                  16,pingpong_sp_ram_tb__DOT__expected_data,
                  16,(IData)(vlSelf->pingpong_sp_ram_tb__DOT__rd_data_o));
        vlSelf->pingpong_sp_ram_tb__DOT__errors = ((IData)(1U) 
                                                   + vlSelf->pingpong_sp_ram_tb__DOT__errors);
    } else {
        VL_WRITEF("  PASS: Read 0x%04x from address 0 with correct 1-cycle latency\n",
                  16,vlSelf->pingpong_sp_ram_tb__DOT__rd_data_o);
    }
    co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                       "sim/pingpong_sp_ram_tb.sv", 
                                                       148);
    vlSelf->pingpong_sp_ram_tb__DOT__rd_addr_i = 1U;
    pingpong_sp_ram_tb__DOT__expected_data = 0xa001U;
    co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                       "sim/pingpong_sp_ram_tb.sv", 
                                                       153);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "sim/pingpong_sp_ram_tb.sv", 
                                       154);
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__rd_valid_q))))) {
        VL_WRITEF("  ERROR: rd_valid_o not asserted for address 1\n");
        vlSelf->pingpong_sp_ram_tb__DOT__errors = ((IData)(1U) 
                                                   + vlSelf->pingpong_sp_ram_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->pingpong_sp_ram_tb__DOT__rd_data_o) 
                     != (IData)(pingpong_sp_ram_tb__DOT__expected_data)))) {
        VL_WRITEF("  ERROR: Address 1: Expected 0x%04x, got 0x%04x\n",
                  16,pingpong_sp_ram_tb__DOT__expected_data,
                  16,(IData)(vlSelf->pingpong_sp_ram_tb__DOT__rd_data_o));
        vlSelf->pingpong_sp_ram_tb__DOT__errors = ((IData)(1U) 
                                                   + vlSelf->pingpong_sp_ram_tb__DOT__errors);
    }
    pingpong_sp_ram_tb__DOT__i = 2U;
    co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                       "sim/pingpong_sp_ram_tb.sv", 
                                                       148);
    vlSelf->pingpong_sp_ram_tb__DOT__rd_addr_i = 2U;
    pingpong_sp_ram_tb__DOT__expected_data = 0xa002U;
    co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                       "sim/pingpong_sp_ram_tb.sv", 
                                                       153);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "sim/pingpong_sp_ram_tb.sv", 
                                       154);
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__rd_valid_q))))) {
        VL_WRITEF("  ERROR: rd_valid_o not asserted for address 2\n");
        vlSelf->pingpong_sp_ram_tb__DOT__errors = ((IData)(1U) 
                                                   + vlSelf->pingpong_sp_ram_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->pingpong_sp_ram_tb__DOT__rd_data_o) 
                     != (IData)(pingpong_sp_ram_tb__DOT__expected_data)))) {
        VL_WRITEF("  ERROR: Address 2: Expected 0x%04x, got 0x%04x\n",
                  16,pingpong_sp_ram_tb__DOT__expected_data,
                  16,(IData)(vlSelf->pingpong_sp_ram_tb__DOT__rd_data_o));
        vlSelf->pingpong_sp_ram_tb__DOT__errors = ((IData)(1U) 
                                                   + vlSelf->pingpong_sp_ram_tb__DOT__errors);
    }
    pingpong_sp_ram_tb__DOT__i = 3U;
    co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                       "sim/pingpong_sp_ram_tb.sv", 
                                                       148);
    vlSelf->pingpong_sp_ram_tb__DOT__rd_addr_i = 3U;
    pingpong_sp_ram_tb__DOT__expected_data = 0xa003U;
    co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                       "sim/pingpong_sp_ram_tb.sv", 
                                                       153);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "sim/pingpong_sp_ram_tb.sv", 
                                       154);
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__rd_valid_q))))) {
        VL_WRITEF("  ERROR: rd_valid_o not asserted for address 3\n");
        vlSelf->pingpong_sp_ram_tb__DOT__errors = ((IData)(1U) 
                                                   + vlSelf->pingpong_sp_ram_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->pingpong_sp_ram_tb__DOT__rd_data_o) 
                     != (IData)(pingpong_sp_ram_tb__DOT__expected_data)))) {
        VL_WRITEF("  ERROR: Address 3: Expected 0x%04x, got 0x%04x\n",
                  16,pingpong_sp_ram_tb__DOT__expected_data,
                  16,(IData)(vlSelf->pingpong_sp_ram_tb__DOT__rd_data_o));
        vlSelf->pingpong_sp_ram_tb__DOT__errors = ((IData)(1U) 
                                                   + vlSelf->pingpong_sp_ram_tb__DOT__errors);
    }
    pingpong_sp_ram_tb__DOT__i = 4U;
    co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                       "sim/pingpong_sp_ram_tb.sv", 
                                                       148);
    vlSelf->pingpong_sp_ram_tb__DOT__rd_addr_i = 4U;
    pingpong_sp_ram_tb__DOT__expected_data = 0xa004U;
    co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                       "sim/pingpong_sp_ram_tb.sv", 
                                                       153);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "sim/pingpong_sp_ram_tb.sv", 
                                       154);
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__rd_valid_q))))) {
        VL_WRITEF("  ERROR: rd_valid_o not asserted for address 4\n");
        vlSelf->pingpong_sp_ram_tb__DOT__errors = ((IData)(1U) 
                                                   + vlSelf->pingpong_sp_ram_tb__DOT__errors);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->pingpong_sp_ram_tb__DOT__rd_data_o) 
                     != (IData)(pingpong_sp_ram_tb__DOT__expected_data)))) {
        VL_WRITEF("  ERROR: Address 4: Expected 0x%04x, got 0x%04x\n",
                  16,pingpong_sp_ram_tb__DOT__expected_data,
                  16,(IData)(vlSelf->pingpong_sp_ram_tb__DOT__rd_data_o));
        vlSelf->pingpong_sp_ram_tb__DOT__errors = ((IData)(1U) 
                                                   + vlSelf->pingpong_sp_ram_tb__DOT__errors);
    }
    pingpong_sp_ram_tb__DOT__i = 5U;
    vlSelf->pingpong_sp_ram_tb__DOT__rd_en_i = 0U;
    co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                       "sim/pingpong_sp_ram_tb.sv", 
                                                       167);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "sim/pingpong_sp_ram_tb.sv", 
                                       168);
    if (VL_UNLIKELY(vlSelf->pingpong_sp_ram_tb__DOT__dut__DOT__rd_valid_q)) {
        VL_WRITEF("  WARNING: rd_valid_o should go LOW when rd_en_i is LOW\n");
    }
    VL_WRITEF("  PASS: Read verification complete for buffer A\n\n[Test 4] Writing 256 samples to buffer B (active_buf_o=1)\n");
    pingpong_sp_ram_tb__DOT__i = 0U;
    while (VL_GTS_III(32, 0x100U, pingpong_sp_ram_tb__DOT__i)) {
        co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                           "sim/pingpong_sp_ram_tb.sv", 
                                                           180);
        vlSelf->pingpong_sp_ram_tb__DOT__in_valid_i = 1U;
        vlSelf->pingpong_sp_ram_tb__DOT__in_data_i 
            = (0xffffU & ((IData)(0xb000U) + pingpong_sp_ram_tb__DOT__i));
        pingpong_sp_ram_tb__DOT__i = ((IData)(1U) + pingpong_sp_ram_tb__DOT__i);
    }
    co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                       "sim/pingpong_sp_ram_tb.sv", 
                                                       185);
    vlSelf->pingpong_sp_ram_tb__DOT__in_valid_i = 0U;
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "sim/pingpong_sp_ram_tb.sv", 
                                       187);
    if (VL_UNLIKELY(vlSelf->pingpong_sp_ram_tb__DOT__active_buf_o)) {
        VL_WRITEF("  ERROR: active_buf_o should toggle back to 0, got %b\n",
                  1,vlSelf->pingpong_sp_ram_tb__DOT__active_buf_o);
        vlSelf->pingpong_sp_ram_tb__DOT__errors = ((IData)(1U) 
                                                   + vlSelf->pingpong_sp_ram_tb__DOT__errors);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->pingpong_sp_ram_tb__DOT__buf_ready_id_o))))) {
        VL_WRITEF("  ERROR: buf_ready_id_o should be 1 (buffer B filled), got %b\n",
                  1,vlSelf->pingpong_sp_ram_tb__DOT__buf_ready_id_o);
        vlSelf->pingpong_sp_ram_tb__DOT__errors = ((IData)(1U) 
                                                   + vlSelf->pingpong_sp_ram_tb__DOT__errors);
    }
    VL_WRITEF("  PASS: Buffer B filled, active_buf_o toggled back to 0\n\n[Test 5] Reading from buffer B\n");
    co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                       "sim/pingpong_sp_ram_tb.sv", 
                                                       202);
    vlSelf->pingpong_sp_ram_tb__DOT__rd_en_i = 1U;
    vlSelf->pingpong_sp_ram_tb__DOT__rd_addr_i = 0U;
    pingpong_sp_ram_tb__DOT__expected_data = 0xb000U;
    co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                       "sim/pingpong_sp_ram_tb.sv", 
                                                       208);
    co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                       "sim/pingpong_sp_ram_tb.sv", 
                                                       209);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "sim/pingpong_sp_ram_tb.sv", 
                                       210);
    if (((IData)(vlSelf->pingpong_sp_ram_tb__DOT__rd_data_o) 
         != (IData)(pingpong_sp_ram_tb__DOT__expected_data))) {
        VL_WRITEF("  ERROR: Expected 0x%04x from buffer B, got 0x%04x\n",
                  16,pingpong_sp_ram_tb__DOT__expected_data,
                  16,(IData)(vlSelf->pingpong_sp_ram_tb__DOT__rd_data_o));
        vlSelf->pingpong_sp_ram_tb__DOT__errors = ((IData)(1U) 
                                                   + vlSelf->pingpong_sp_ram_tb__DOT__errors);
    } else {
        VL_WRITEF("  PASS: Read 0x%04x from buffer B\n",
                  16,vlSelf->pingpong_sp_ram_tb__DOT__rd_data_o);
    }
    vlSelf->pingpong_sp_ram_tb__DOT__rd_en_i = 0U;
    co_await vlSelf->__VtrigSched_h6eefdb72__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge pingpong_sp_ram_tb.clk_i)", 
                                                       "sim/pingpong_sp_ram_tb.sv", 
                                                       220);
    VL_WRITEF("\n============================================\n");
    if (VL_LIKELY((0U == vlSelf->pingpong_sp_ram_tb__DOT__errors))) {
        VL_WRITEF("*** PASS: All tests passed! ***\n");
    } else {
        VL_WRITEF("*** FAIL: %0d error(s) detected ***\n[%0t] %%Fatal: pingpong_sp_ram_tb.sv:228: Assertion failed in %Npingpong_sp_ram_tb: Testbench failed with errors\n",
                  32,vlSelf->pingpong_sp_ram_tb__DOT__errors,
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("sim/pingpong_sp_ram_tb.sv", 228, "");
    }
    VL_WRITEF("============================================\n\n");
    VL_FINISH_MT("sim/pingpong_sp_ram_tb.sv", 232, "");
}

VL_INLINE_OPT VlCoroutine Vpingpong_sp_ram_tb___024root___eval_initial__TOP__Vtiming__2(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0x5f5e100ULL, 
                                       nullptr, "sim/pingpong_sp_ram_tb.sv", 
                                       237);
    VL_WRITEF("\nERROR: Testbench timeout!\n[%0t] %%Fatal: pingpong_sp_ram_tb.sv:239: Assertion failed in %Npingpong_sp_ram_tb: Timeout\n",
              64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
    VL_STOP_MT("sim/pingpong_sp_ram_tb.sv", 239, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vpingpong_sp_ram_tb___024root___dump_triggers__act(Vpingpong_sp_ram_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vpingpong_sp_ram_tb___024root___eval_triggers__act(Vpingpong_sp_ram_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpingpong_sp_ram_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpingpong_sp_ram_tb___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->pingpong_sp_ram_tb__DOT__clk_i) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__pingpong_sp_ram_tb__DOT__clk_i__0))));
    vlSelf->__VactTriggered.set(1U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__pingpong_sp_ram_tb__DOT__clk_i__0 
        = vlSelf->pingpong_sp_ram_tb__DOT__clk_i;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vpingpong_sp_ram_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}
