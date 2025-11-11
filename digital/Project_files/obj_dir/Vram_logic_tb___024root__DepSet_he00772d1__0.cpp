// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vram_logic_tb.h for the primary calling header

#include "Vram_logic_tb__pch.h"
#include "Vram_logic_tb___024root.h"

VL_ATTR_COLD void Vram_logic_tb___024root___eval_initial__TOP(Vram_logic_tb___024root* vlSelf);
VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__0(Vram_logic_tb___024root* vlSelf);
VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1(Vram_logic_tb___024root* vlSelf);
VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__2(Vram_logic_tb___024root* vlSelf);

void Vram_logic_tb___024root___eval_initial(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_initial\n"); );
    // Body
    Vram_logic_tb___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__ram_logic_tb__DOT__clk__0 
        = vlSelf->ram_logic_tb__DOT__clk;
}

VL_INLINE_OPT VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__0(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->ram_logic_tb__DOT__clk = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "ram_logic_tb.sv", 
                                           58);
        vlSelf->ram_logic_tb__DOT__clk = (1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__clk)));
    }
}

VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_1__0(Vram_logic_tb___024root* vlSelf);
VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_1__1(Vram_logic_tb___024root* vlSelf);

VL_INLINE_OPT VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Init
    IData/*31:0*/ __Vtask_ram_logic_tb__DOT__write_sample__4__data;
    __Vtask_ram_logic_tb__DOT__write_sample__4__data = 0;
    IData/*31:0*/ __Vtask_ram_logic_tb__DOT__write_sample__7__data;
    __Vtask_ram_logic_tb__DOT__write_sample__7__data = 0;
    IData/*31:0*/ __Vtask_ram_logic_tb__DOT__write_sample__10__data;
    __Vtask_ram_logic_tb__DOT__write_sample__10__data = 0;
    IData/*31:0*/ __Vtask_ram_logic_tb__DOT__read_sample__11__data;
    __Vtask_ram_logic_tb__DOT__read_sample__11__data = 0;
    IData/*31:0*/ __Vtask_ram_logic_tb__DOT__write_sample__14__data;
    __Vtask_ram_logic_tb__DOT__write_sample__14__data = 0;
    IData/*31:0*/ __Vtask_ram_logic_tb__DOT__write_sample__19__data;
    __Vtask_ram_logic_tb__DOT__write_sample__19__data = 0;
    IData/*31:0*/ __Vtask_ram_logic_tb__DOT__write_sample__20__data;
    __Vtask_ram_logic_tb__DOT__write_sample__20__data = 0;
    // Body
    VL_WRITEF("\n\n================================================================================\nRAM Logic Ping-Pong Buffer Testbench\n================================================================================\nWIDTH = 32, DEPTH = 16\n================================================================================\n\n");
    VL_WRITEF("========================================\nTEST 1: Reset Behavior\n========================================\n");
    VL_WRITEF("========================================\nApplying Reset...\n========================================\n");
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->ram_logic_tb__DOT__write_data = 0U;
    vlSelf->ram_logic_tb__DOT__rst_n = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__rst_n = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       106);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       106);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("Reset complete\n\n");
    if (VL_UNLIKELY((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q)))) {
        VL_WRITEF("ERROR: write_ready should be 1 after reset\n");
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    if (VL_UNLIKELY(vlSelf->ram_logic_tb__DOT__read_valid)) {
        VL_WRITEF("ERROR: read_valid should be 0 after reset\n");
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    if (VL_UNLIKELY((0U != (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q)))) {
        VL_WRITEF("ERROR: write_count should be 0 after reset\n");
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    if (VL_UNLIKELY((0U != (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_count_q)))) {
        VL_WRITEF("ERROR: read_count should be 0 after reset\n");
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    if ((0U == vlSelf->ram_logic_tb__DOT__test_errors)) {
        VL_WRITEF("\342\234\223 Test PASSED\n\n");
        vlSelf->ram_logic_tb__DOT__test_passed = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_passed);
    } else {
        VL_WRITEF("\342\234\227 Test FAILED\n\n");
    }
    VL_WRITEF("========================================\nTEST 2: Write Operations\n========================================\n");
    VL_WRITEF("========================================\nApplying Reset...\n========================================\n");
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->ram_logic_tb__DOT__write_data = 0U;
    vlSelf->ram_logic_tb__DOT__rst_n = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__rst_n = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       106);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       106);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("Reset complete\n\n");
    vlSelf->ram_logic_tb__DOT__test_data[0U] = 0x1000U;
    VL_WRITEF("Writing sample 0: 0x%08x\n",32,vlSelf->ram_logic_tb__DOT__test_data
              [0U]);
    __Vtask_ram_logic_tb__DOT__write_sample__4__data 
        = vlSelf->ram_logic_tb__DOT__test_data[0U];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__4__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       196);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY((1U != (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q)))) {
        VL_WRITEF("ERROR: write_count = %0#, expected 1\n",
                  5,vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__test_data[1U] = 0x1001U;
    VL_WRITEF("Writing sample 1: 0x%08x\n",32,vlSelf->ram_logic_tb__DOT__test_data
              [1U]);
    __Vtask_ram_logic_tb__DOT__write_sample__4__data 
        = vlSelf->ram_logic_tb__DOT__test_data[1U];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__4__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       196);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY((2U != (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q)))) {
        VL_WRITEF("ERROR: write_count = %0#, expected 2\n",
                  5,vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__test_data[2U] = 0x1002U;
    VL_WRITEF("Writing sample 2: 0x%08x\n",32,vlSelf->ram_logic_tb__DOT__test_data
              [2U]);
    __Vtask_ram_logic_tb__DOT__write_sample__4__data 
        = vlSelf->ram_logic_tb__DOT__test_data[2U];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__4__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       196);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY((3U != (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q)))) {
        VL_WRITEF("ERROR: write_count = %0#, expected 3\n",
                  5,vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__test_data[3U] = 0x1003U;
    VL_WRITEF("Writing sample 3: 0x%08x\n",32,vlSelf->ram_logic_tb__DOT__test_data
              [3U]);
    __Vtask_ram_logic_tb__DOT__write_sample__4__data 
        = vlSelf->ram_logic_tb__DOT__test_data[3U];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__4__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       196);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY((4U != (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q)))) {
        VL_WRITEF("ERROR: write_count = %0#, expected 4\n",
                  5,vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__test_data[4U] = 0x1004U;
    VL_WRITEF("Writing sample 4: 0x%08x\n",32,vlSelf->ram_logic_tb__DOT__test_data
              [4U]);
    __Vtask_ram_logic_tb__DOT__write_sample__4__data 
        = vlSelf->ram_logic_tb__DOT__test_data[4U];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__4__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       196);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY((5U != (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q)))) {
        VL_WRITEF("ERROR: write_count = %0#, expected 5\n",
                  5,vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__test_data[5U] = 0x1005U;
    VL_WRITEF("Writing sample 5: 0x%08x\n",32,vlSelf->ram_logic_tb__DOT__test_data
              [5U]);
    __Vtask_ram_logic_tb__DOT__write_sample__4__data 
        = vlSelf->ram_logic_tb__DOT__test_data[5U];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__4__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       196);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY((6U != (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q)))) {
        VL_WRITEF("ERROR: write_count = %0#, expected 6\n",
                  5,vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__test_data[6U] = 0x1006U;
    VL_WRITEF("Writing sample 6: 0x%08x\n",32,vlSelf->ram_logic_tb__DOT__test_data
              [6U]);
    __Vtask_ram_logic_tb__DOT__write_sample__4__data 
        = vlSelf->ram_logic_tb__DOT__test_data[6U];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__4__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       196);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY((7U != (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q)))) {
        VL_WRITEF("ERROR: write_count = %0#, expected 7\n",
                  5,vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__test_data[7U] = 0x1007U;
    VL_WRITEF("Writing sample 7: 0x%08x\n",32,vlSelf->ram_logic_tb__DOT__test_data
              [7U]);
    __Vtask_ram_logic_tb__DOT__write_sample__4__data 
        = vlSelf->ram_logic_tb__DOT__test_data[7U];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__4__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       196);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY((8U != (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q)))) {
        VL_WRITEF("ERROR: write_count = %0#, expected 8\n",
                  5,vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__test_data[8U] = 0x1008U;
    VL_WRITEF("Writing sample 8: 0x%08x\n",32,vlSelf->ram_logic_tb__DOT__test_data
              [8U]);
    __Vtask_ram_logic_tb__DOT__write_sample__4__data 
        = vlSelf->ram_logic_tb__DOT__test_data[8U];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__4__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       196);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY((9U != (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q)))) {
        VL_WRITEF("ERROR: write_count = %0#, expected 9\n",
                  5,vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__test_data[9U] = 0x1009U;
    VL_WRITEF("Writing sample 9: 0x%08x\n",32,vlSelf->ram_logic_tb__DOT__test_data
              [9U]);
    __Vtask_ram_logic_tb__DOT__write_sample__4__data 
        = vlSelf->ram_logic_tb__DOT__test_data[9U];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__4__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       196);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY((0xaU != (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q)))) {
        VL_WRITEF("ERROR: write_count = %0#, expected 10\n",
                  5,vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__test_data[0xaU] = 0x100aU;
    VL_WRITEF("Writing sample 10: 0x%08x\n",32,vlSelf->ram_logic_tb__DOT__test_data
              [0xaU]);
    __Vtask_ram_logic_tb__DOT__write_sample__4__data 
        = vlSelf->ram_logic_tb__DOT__test_data[0xaU];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__4__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       196);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY((0xbU != (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q)))) {
        VL_WRITEF("ERROR: write_count = %0#, expected 11\n",
                  5,vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__test_data[0xbU] = 0x100bU;
    VL_WRITEF("Writing sample 11: 0x%08x\n",32,vlSelf->ram_logic_tb__DOT__test_data
              [0xbU]);
    __Vtask_ram_logic_tb__DOT__write_sample__4__data 
        = vlSelf->ram_logic_tb__DOT__test_data[0xbU];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__4__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       196);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY((0xcU != (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q)))) {
        VL_WRITEF("ERROR: write_count = %0#, expected 12\n",
                  5,vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__test_data[0xcU] = 0x100cU;
    VL_WRITEF("Writing sample 12: 0x%08x\n",32,vlSelf->ram_logic_tb__DOT__test_data
              [0xcU]);
    __Vtask_ram_logic_tb__DOT__write_sample__4__data 
        = vlSelf->ram_logic_tb__DOT__test_data[0xcU];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__4__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       196);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY((0xdU != (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q)))) {
        VL_WRITEF("ERROR: write_count = %0#, expected 13\n",
                  5,vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__test_data[0xdU] = 0x100dU;
    VL_WRITEF("Writing sample 13: 0x%08x\n",32,vlSelf->ram_logic_tb__DOT__test_data
              [0xdU]);
    __Vtask_ram_logic_tb__DOT__write_sample__4__data 
        = vlSelf->ram_logic_tb__DOT__test_data[0xdU];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__4__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       196);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY((0xeU != (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q)))) {
        VL_WRITEF("ERROR: write_count = %0#, expected 14\n",
                  5,vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__test_data[0xeU] = 0x100eU;
    VL_WRITEF("Writing sample 14: 0x%08x\n",32,vlSelf->ram_logic_tb__DOT__test_data
              [0xeU]);
    __Vtask_ram_logic_tb__DOT__write_sample__4__data 
        = vlSelf->ram_logic_tb__DOT__test_data[0xeU];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__4__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       196);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY((0xfU != (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q)))) {
        VL_WRITEF("ERROR: write_count = %0#, expected 15\n",
                  5,vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__test_data[0xfU] = 0x100fU;
    VL_WRITEF("Writing sample 15: 0x%08x\n",32,vlSelf->ram_logic_tb__DOT__test_data
              [0xfU]);
    __Vtask_ram_logic_tb__DOT__write_sample__4__data 
        = vlSelf->ram_logic_tb__DOT__test_data[0xfU];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__4__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       205);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       206);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY((0U != (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q)))) {
        VL_WRITEF("ERROR: After buffer swap, write_count = %0#, expected 0\n",
                  5,vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    if ((0U == vlSelf->ram_logic_tb__DOT__test_errors)) {
        VL_WRITEF("\342\234\223 Test PASSED\n\n");
        vlSelf->ram_logic_tb__DOT__test_passed = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_passed);
    } else {
        VL_WRITEF("\342\234\227 Test FAILED\n\n");
    }
    VL_WRITEF("========================================\nTEST 3: Buffer Swap\n========================================\n");
    VL_WRITEF("========================================\nApplying Reset...\n========================================\n");
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->ram_logic_tb__DOT__write_data = 0U;
    vlSelf->ram_logic_tb__DOT__rst_n = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__rst_n = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       106);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       106);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("Reset complete\n\n");
    __Vtask_ram_logic_tb__DOT__write_sample__7__data = 0x2000U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__7__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__7__data = 0x2001U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__7__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__7__data = 0x2002U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__7__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__7__data = 0x2003U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__7__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__7__data = 0x2004U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__7__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__7__data = 0x2005U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__7__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__7__data = 0x2006U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__7__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__7__data = 0x2007U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__7__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__7__data = 0x2008U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__7__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__7__data = 0x2009U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__7__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__7__data = 0x200aU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__7__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__7__data = 0x200bU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__7__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__7__data = 0x200cU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__7__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__7__data = 0x200dU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__7__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__7__data = 0x200eU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__7__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__7__data = 0x200fU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__7__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       236);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       237);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY((0U != (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q)))) {
        VL_WRITEF("ERROR: write_count should reset to 0 after swap, got %0#\n",
                  5,vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid))))) {
        VL_WRITEF("ERROR: read_valid should be 1 after buffer swap\n");
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    if ((0U == vlSelf->ram_logic_tb__DOT__test_errors)) {
        VL_WRITEF("\342\234\223 Test PASSED\n\n");
        vlSelf->ram_logic_tb__DOT__test_passed = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_passed);
    } else {
        VL_WRITEF("\342\234\227 Test FAILED\n\n");
    }
    VL_WRITEF("========================================\nTEST 4: Read Operations\n========================================\n");
    VL_WRITEF("========================================\nApplying Reset...\n========================================\n");
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->ram_logic_tb__DOT__write_data = 0U;
    vlSelf->ram_logic_tb__DOT__rst_n = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__rst_n = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       106);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       106);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("Reset complete\n\n");
    vlSelf->ram_logic_tb__DOT__test_data[0U] = 0x3000U;
    __Vtask_ram_logic_tb__DOT__write_sample__10__data 
        = vlSelf->ram_logic_tb__DOT__test_data[0U];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__10__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__test_data[1U] = 0x3001U;
    __Vtask_ram_logic_tb__DOT__write_sample__10__data 
        = vlSelf->ram_logic_tb__DOT__test_data[1U];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__10__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__test_data[2U] = 0x3002U;
    __Vtask_ram_logic_tb__DOT__write_sample__10__data 
        = vlSelf->ram_logic_tb__DOT__test_data[2U];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__10__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__test_data[3U] = 0x3003U;
    __Vtask_ram_logic_tb__DOT__write_sample__10__data 
        = vlSelf->ram_logic_tb__DOT__test_data[3U];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__10__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__test_data[4U] = 0x3004U;
    __Vtask_ram_logic_tb__DOT__write_sample__10__data 
        = vlSelf->ram_logic_tb__DOT__test_data[4U];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__10__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__test_data[5U] = 0x3005U;
    __Vtask_ram_logic_tb__DOT__write_sample__10__data 
        = vlSelf->ram_logic_tb__DOT__test_data[5U];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__10__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__test_data[6U] = 0x3006U;
    __Vtask_ram_logic_tb__DOT__write_sample__10__data 
        = vlSelf->ram_logic_tb__DOT__test_data[6U];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__10__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__test_data[7U] = 0x3007U;
    __Vtask_ram_logic_tb__DOT__write_sample__10__data 
        = vlSelf->ram_logic_tb__DOT__test_data[7U];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__10__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__test_data[8U] = 0x3008U;
    __Vtask_ram_logic_tb__DOT__write_sample__10__data 
        = vlSelf->ram_logic_tb__DOT__test_data[8U];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__10__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__test_data[9U] = 0x3009U;
    __Vtask_ram_logic_tb__DOT__write_sample__10__data 
        = vlSelf->ram_logic_tb__DOT__test_data[9U];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__10__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__test_data[0xaU] = 0x300aU;
    __Vtask_ram_logic_tb__DOT__write_sample__10__data 
        = vlSelf->ram_logic_tb__DOT__test_data[0xaU];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__10__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__test_data[0xbU] = 0x300bU;
    __Vtask_ram_logic_tb__DOT__write_sample__10__data 
        = vlSelf->ram_logic_tb__DOT__test_data[0xbU];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__10__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__test_data[0xcU] = 0x300cU;
    __Vtask_ram_logic_tb__DOT__write_sample__10__data 
        = vlSelf->ram_logic_tb__DOT__test_data[0xcU];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__10__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__test_data[0xdU] = 0x300dU;
    __Vtask_ram_logic_tb__DOT__write_sample__10__data 
        = vlSelf->ram_logic_tb__DOT__test_data[0xdU];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__10__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__test_data[0xeU] = 0x300eU;
    __Vtask_ram_logic_tb__DOT__write_sample__10__data 
        = vlSelf->ram_logic_tb__DOT__test_data[0xeU];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__10__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__test_data[0xfU] = 0x300fU;
    __Vtask_ram_logic_tb__DOT__write_sample__10__data 
        = vlSelf->ram_logic_tb__DOT__test_data[0xfU];
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__10__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       276);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       277);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    __Vtask_ram_logic_tb__DOT__read_sample__11__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->ram_logic_tb__DOT__read_back[0U] = __Vtask_ram_logic_tb__DOT__read_sample__11__data;
    VL_WRITEF("Read sample 0: 0x%08x, expected: 0x%08x\n",
              32,vlSelf->ram_logic_tb__DOT__read_back
              [0U],32,vlSelf->ram_logic_tb__DOT__test_data
              [0U]);
    if (VL_UNLIKELY((vlSelf->ram_logic_tb__DOT__read_back
                     [0U] != vlSelf->ram_logic_tb__DOT__test_data
                     [0U]))) {
        VL_WRITEF("ERROR: Data mismatch at 0\n");
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    __Vtask_ram_logic_tb__DOT__read_sample__11__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->ram_logic_tb__DOT__read_back[1U] = __Vtask_ram_logic_tb__DOT__read_sample__11__data;
    VL_WRITEF("Read sample 1: 0x%08x, expected: 0x%08x\n",
              32,vlSelf->ram_logic_tb__DOT__read_back
              [1U],32,vlSelf->ram_logic_tb__DOT__test_data
              [1U]);
    if (VL_UNLIKELY((vlSelf->ram_logic_tb__DOT__read_back
                     [1U] != vlSelf->ram_logic_tb__DOT__test_data
                     [1U]))) {
        VL_WRITEF("ERROR: Data mismatch at 1\n");
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    __Vtask_ram_logic_tb__DOT__read_sample__11__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->ram_logic_tb__DOT__read_back[2U] = __Vtask_ram_logic_tb__DOT__read_sample__11__data;
    VL_WRITEF("Read sample 2: 0x%08x, expected: 0x%08x\n",
              32,vlSelf->ram_logic_tb__DOT__read_back
              [2U],32,vlSelf->ram_logic_tb__DOT__test_data
              [2U]);
    if (VL_UNLIKELY((vlSelf->ram_logic_tb__DOT__read_back
                     [2U] != vlSelf->ram_logic_tb__DOT__test_data
                     [2U]))) {
        VL_WRITEF("ERROR: Data mismatch at 2\n");
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    __Vtask_ram_logic_tb__DOT__read_sample__11__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->ram_logic_tb__DOT__read_back[3U] = __Vtask_ram_logic_tb__DOT__read_sample__11__data;
    VL_WRITEF("Read sample 3: 0x%08x, expected: 0x%08x\n",
              32,vlSelf->ram_logic_tb__DOT__read_back
              [3U],32,vlSelf->ram_logic_tb__DOT__test_data
              [3U]);
    if (VL_UNLIKELY((vlSelf->ram_logic_tb__DOT__read_back
                     [3U] != vlSelf->ram_logic_tb__DOT__test_data
                     [3U]))) {
        VL_WRITEF("ERROR: Data mismatch at 3\n");
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    __Vtask_ram_logic_tb__DOT__read_sample__11__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->ram_logic_tb__DOT__read_back[4U] = __Vtask_ram_logic_tb__DOT__read_sample__11__data;
    VL_WRITEF("Read sample 4: 0x%08x, expected: 0x%08x\n",
              32,vlSelf->ram_logic_tb__DOT__read_back
              [4U],32,vlSelf->ram_logic_tb__DOT__test_data
              [4U]);
    if (VL_UNLIKELY((vlSelf->ram_logic_tb__DOT__read_back
                     [4U] != vlSelf->ram_logic_tb__DOT__test_data
                     [4U]))) {
        VL_WRITEF("ERROR: Data mismatch at 4\n");
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    __Vtask_ram_logic_tb__DOT__read_sample__11__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->ram_logic_tb__DOT__read_back[5U] = __Vtask_ram_logic_tb__DOT__read_sample__11__data;
    VL_WRITEF("Read sample 5: 0x%08x, expected: 0x%08x\n",
              32,vlSelf->ram_logic_tb__DOT__read_back
              [5U],32,vlSelf->ram_logic_tb__DOT__test_data
              [5U]);
    if (VL_UNLIKELY((vlSelf->ram_logic_tb__DOT__read_back
                     [5U] != vlSelf->ram_logic_tb__DOT__test_data
                     [5U]))) {
        VL_WRITEF("ERROR: Data mismatch at 5\n");
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    __Vtask_ram_logic_tb__DOT__read_sample__11__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->ram_logic_tb__DOT__read_back[6U] = __Vtask_ram_logic_tb__DOT__read_sample__11__data;
    VL_WRITEF("Read sample 6: 0x%08x, expected: 0x%08x\n",
              32,vlSelf->ram_logic_tb__DOT__read_back
              [6U],32,vlSelf->ram_logic_tb__DOT__test_data
              [6U]);
    if (VL_UNLIKELY((vlSelf->ram_logic_tb__DOT__read_back
                     [6U] != vlSelf->ram_logic_tb__DOT__test_data
                     [6U]))) {
        VL_WRITEF("ERROR: Data mismatch at 6\n");
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    __Vtask_ram_logic_tb__DOT__read_sample__11__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->ram_logic_tb__DOT__read_back[7U] = __Vtask_ram_logic_tb__DOT__read_sample__11__data;
    VL_WRITEF("Read sample 7: 0x%08x, expected: 0x%08x\n",
              32,vlSelf->ram_logic_tb__DOT__read_back
              [7U],32,vlSelf->ram_logic_tb__DOT__test_data
              [7U]);
    if (VL_UNLIKELY((vlSelf->ram_logic_tb__DOT__read_back
                     [7U] != vlSelf->ram_logic_tb__DOT__test_data
                     [7U]))) {
        VL_WRITEF("ERROR: Data mismatch at 7\n");
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    __Vtask_ram_logic_tb__DOT__read_sample__11__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->ram_logic_tb__DOT__read_back[8U] = __Vtask_ram_logic_tb__DOT__read_sample__11__data;
    VL_WRITEF("Read sample 8: 0x%08x, expected: 0x%08x\n",
              32,vlSelf->ram_logic_tb__DOT__read_back
              [8U],32,vlSelf->ram_logic_tb__DOT__test_data
              [8U]);
    if (VL_UNLIKELY((vlSelf->ram_logic_tb__DOT__read_back
                     [8U] != vlSelf->ram_logic_tb__DOT__test_data
                     [8U]))) {
        VL_WRITEF("ERROR: Data mismatch at 8\n");
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    __Vtask_ram_logic_tb__DOT__read_sample__11__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->ram_logic_tb__DOT__read_back[9U] = __Vtask_ram_logic_tb__DOT__read_sample__11__data;
    VL_WRITEF("Read sample 9: 0x%08x, expected: 0x%08x\n",
              32,vlSelf->ram_logic_tb__DOT__read_back
              [9U],32,vlSelf->ram_logic_tb__DOT__test_data
              [9U]);
    if (VL_UNLIKELY((vlSelf->ram_logic_tb__DOT__read_back
                     [9U] != vlSelf->ram_logic_tb__DOT__test_data
                     [9U]))) {
        VL_WRITEF("ERROR: Data mismatch at 9\n");
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    __Vtask_ram_logic_tb__DOT__read_sample__11__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->ram_logic_tb__DOT__read_back[0xaU] = __Vtask_ram_logic_tb__DOT__read_sample__11__data;
    VL_WRITEF("Read sample 10: 0x%08x, expected: 0x%08x\n",
              32,vlSelf->ram_logic_tb__DOT__read_back
              [0xaU],32,vlSelf->ram_logic_tb__DOT__test_data
              [0xaU]);
    if (VL_UNLIKELY((vlSelf->ram_logic_tb__DOT__read_back
                     [0xaU] != vlSelf->ram_logic_tb__DOT__test_data
                     [0xaU]))) {
        VL_WRITEF("ERROR: Data mismatch at 10\n");
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    __Vtask_ram_logic_tb__DOT__read_sample__11__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->ram_logic_tb__DOT__read_back[0xbU] = __Vtask_ram_logic_tb__DOT__read_sample__11__data;
    VL_WRITEF("Read sample 11: 0x%08x, expected: 0x%08x\n",
              32,vlSelf->ram_logic_tb__DOT__read_back
              [0xbU],32,vlSelf->ram_logic_tb__DOT__test_data
              [0xbU]);
    if (VL_UNLIKELY((vlSelf->ram_logic_tb__DOT__read_back
                     [0xbU] != vlSelf->ram_logic_tb__DOT__test_data
                     [0xbU]))) {
        VL_WRITEF("ERROR: Data mismatch at 11\n");
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    __Vtask_ram_logic_tb__DOT__read_sample__11__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->ram_logic_tb__DOT__read_back[0xcU] = __Vtask_ram_logic_tb__DOT__read_sample__11__data;
    VL_WRITEF("Read sample 12: 0x%08x, expected: 0x%08x\n",
              32,vlSelf->ram_logic_tb__DOT__read_back
              [0xcU],32,vlSelf->ram_logic_tb__DOT__test_data
              [0xcU]);
    if (VL_UNLIKELY((vlSelf->ram_logic_tb__DOT__read_back
                     [0xcU] != vlSelf->ram_logic_tb__DOT__test_data
                     [0xcU]))) {
        VL_WRITEF("ERROR: Data mismatch at 12\n");
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    __Vtask_ram_logic_tb__DOT__read_sample__11__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->ram_logic_tb__DOT__read_back[0xdU] = __Vtask_ram_logic_tb__DOT__read_sample__11__data;
    VL_WRITEF("Read sample 13: 0x%08x, expected: 0x%08x\n",
              32,vlSelf->ram_logic_tb__DOT__read_back
              [0xdU],32,vlSelf->ram_logic_tb__DOT__test_data
              [0xdU]);
    if (VL_UNLIKELY((vlSelf->ram_logic_tb__DOT__read_back
                     [0xdU] != vlSelf->ram_logic_tb__DOT__test_data
                     [0xdU]))) {
        VL_WRITEF("ERROR: Data mismatch at 13\n");
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    __Vtask_ram_logic_tb__DOT__read_sample__11__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->ram_logic_tb__DOT__read_back[0xeU] = __Vtask_ram_logic_tb__DOT__read_sample__11__data;
    VL_WRITEF("Read sample 14: 0x%08x, expected: 0x%08x\n",
              32,vlSelf->ram_logic_tb__DOT__read_back
              [0xeU],32,vlSelf->ram_logic_tb__DOT__test_data
              [0xeU]);
    if (VL_UNLIKELY((vlSelf->ram_logic_tb__DOT__read_back
                     [0xeU] != vlSelf->ram_logic_tb__DOT__test_data
                     [0xeU]))) {
        VL_WRITEF("ERROR: Data mismatch at 14\n");
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    __Vtask_ram_logic_tb__DOT__read_sample__11__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->ram_logic_tb__DOT__read_back[0xfU] = __Vtask_ram_logic_tb__DOT__read_sample__11__data;
    VL_WRITEF("Read sample 15: 0x%08x, expected: 0x%08x\n",
              32,vlSelf->ram_logic_tb__DOT__read_back
              [0xfU],32,vlSelf->ram_logic_tb__DOT__test_data
              [0xfU]);
    if (VL_UNLIKELY((vlSelf->ram_logic_tb__DOT__read_back
                     [0xfU] != vlSelf->ram_logic_tb__DOT__test_data
                     [0xfU]))) {
        VL_WRITEF("ERROR: Data mismatch at 15\n");
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    if ((0U == vlSelf->ram_logic_tb__DOT__test_errors)) {
        VL_WRITEF("\342\234\223 Test PASSED\n\n");
        vlSelf->ram_logic_tb__DOT__test_passed = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_passed);
    } else {
        VL_WRITEF("\342\234\227 Test FAILED\n\n");
    }
    VL_WRITEF("========================================\nTEST 5: Ping-Pong Operation\n========================================\n");
    VL_WRITEF("========================================\nApplying Reset...\n========================================\n");
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->ram_logic_tb__DOT__write_data = 0U;
    vlSelf->ram_logic_tb__DOT__rst_n = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__rst_n = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       106);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       106);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("Reset complete\n\nFilling first buffer...\n");
    __Vtask_ram_logic_tb__DOT__write_sample__14__data = 0x4000U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__14__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__14__data = 0x4001U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__14__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__14__data = 0x4002U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__14__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__14__data = 0x4003U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__14__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__14__data = 0x4004U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__14__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__14__data = 0x4005U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__14__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__14__data = 0x4006U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__14__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__14__data = 0x4007U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__14__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__14__data = 0x4008U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__14__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__14__data = 0x4009U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__14__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__14__data = 0x400aU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__14__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__14__data = 0x400bU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__14__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__14__data = 0x400cU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__14__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__14__data = 0x400dU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__14__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__14__data = 0x400eU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__14__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__14__data = 0x400fU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__14__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       316);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       317);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("Concurrent read/write for buffer 2...\n");
    vlSelf->__Vfork_1__sync.init(2U, nullptr);
    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_1__0(vlSelf);
    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_1__1(vlSelf);
    co_await vlSelf->__Vfork_1__sync.join(nullptr, 
                                          "ram_logic_tb.sv", 
                                          321);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if ((0U == vlSelf->ram_logic_tb__DOT__test_errors)) {
        VL_WRITEF("\342\234\223 Test PASSED\n\n");
        vlSelf->ram_logic_tb__DOT__test_passed = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_passed);
    } else {
        VL_WRITEF("\342\234\227 Test FAILED\n\n");
    }
    VL_WRITEF("========================================\nTEST 6: Continuous Write Operation\n========================================\n");
    VL_WRITEF("========================================\nApplying Reset...\n========================================\n");
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    vlSelf->ram_logic_tb__DOT__write_data = 0U;
    vlSelf->ram_logic_tb__DOT__rst_n = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       104);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__rst_n = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       106);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       106);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("Reset complete\n\nFilling first buffer...\n");
    __Vtask_ram_logic_tb__DOT__write_sample__19__data = 0x6000U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__19__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__19__data = 0x6001U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__19__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__19__data = 0x6002U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__19__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__19__data = 0x6003U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__19__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__19__data = 0x6004U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__19__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__19__data = 0x6005U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__19__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__19__data = 0x6006U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__19__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__19__data = 0x6007U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__19__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__19__data = 0x6008U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__19__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__19__data = 0x6009U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__19__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__19__data = 0x600aU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__19__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__19__data = 0x600bU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__19__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__19__data = 0x600cU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__19__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__19__data = 0x600dU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__19__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__19__data = 0x600eU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__19__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__19__data = 0x600fU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__19__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       368);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       369);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("Filling second buffer...\n");
    __Vtask_ram_logic_tb__DOT__write_sample__20__data = 0x7000U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__20__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__20__data = 0x7001U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__20__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__20__data = 0x7002U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__20__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__20__data = 0x7003U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__20__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__20__data = 0x7004U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__20__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__20__data = 0x7005U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__20__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__20__data = 0x7006U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__20__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__20__data = 0x7007U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__20__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__20__data = 0x7008U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__20__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__20__data = 0x7009U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__20__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__20__data = 0x700aU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__20__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__20__data = 0x700bU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__20__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__20__data = 0x700cU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__20__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__20__data = 0x700dU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__20__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__20__data = 0x700eU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__20__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__20__data = 0x700fU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__20__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       378);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       379);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q)))) {
        VL_WRITEF("ERROR: write_ready should be 1 for continuous operation\n");
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    if (VL_UNLIKELY((0U != (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q)))) {
        VL_WRITEF("ERROR: write_count should be 0 after swap\n");
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    if ((0U == vlSelf->ram_logic_tb__DOT__test_errors)) {
        VL_WRITEF("\342\234\223 Test PASSED\n\n");
        vlSelf->ram_logic_tb__DOT__test_passed = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_passed);
    } else {
        VL_WRITEF("\342\234\227 Test FAILED\n\n");
    }
    VL_WRITEF("\n\n================================================================================\nTEST SUMMARY\n================================================================================\nTests Passed: %0d/6\nErrors:       %0d\n================================================================================\n",
              32,vlSelf->ram_logic_tb__DOT__test_passed,
              32,vlSelf->ram_logic_tb__DOT__test_errors);
    if (((0U == vlSelf->ram_logic_tb__DOT__test_errors) 
         & (6U == vlSelf->ram_logic_tb__DOT__test_passed))) {
        VL_WRITEF("\342\234\223 ALL TESTS PASSED!\n");
    } else {
        VL_WRITEF("\342\234\227 SOME TESTS FAILED\n");
    }
    VL_WRITEF("================================================================================\n\n");
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       437);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       437);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       437);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       437);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       437);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       437);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       437);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       437);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       437);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       437);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_FINISH_MT("ram_logic_tb.sv", 438, "");
    vlSelf->__Vm_traceActivity[2U] = 1U;
}

VL_INLINE_OPT VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_1__1(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_1__1\n"); );
    // Init
    IData/*31:0*/ __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data;
    __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data = 0;
    IData/*31:0*/ __Vtask_ram_logic_tb__DOT__read_sample__16__data;
    __Vtask_ram_logic_tb__DOT__read_sample__16__data = 0;
    // Body
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
    }
    __Vtask_ram_logic_tb__DOT__read_sample__16__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data 
        = __Vtask_ram_logic_tb__DOT__read_sample__16__data;
    if (VL_UNLIKELY((0x4000U != __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data))) {
        VL_WRITEF("ERROR: Read mismatch at 0: got 0x%08x, expected 0x00004000\n",
                  32,__Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
    }
    __Vtask_ram_logic_tb__DOT__read_sample__16__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data 
        = __Vtask_ram_logic_tb__DOT__read_sample__16__data;
    if (VL_UNLIKELY((0x4001U != __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data))) {
        VL_WRITEF("ERROR: Read mismatch at 1: got 0x%08x, expected 0x00004001\n",
                  32,__Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
    }
    __Vtask_ram_logic_tb__DOT__read_sample__16__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data 
        = __Vtask_ram_logic_tb__DOT__read_sample__16__data;
    if (VL_UNLIKELY((0x4002U != __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data))) {
        VL_WRITEF("ERROR: Read mismatch at 2: got 0x%08x, expected 0x00004002\n",
                  32,__Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
    }
    __Vtask_ram_logic_tb__DOT__read_sample__16__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data 
        = __Vtask_ram_logic_tb__DOT__read_sample__16__data;
    if (VL_UNLIKELY((0x4003U != __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data))) {
        VL_WRITEF("ERROR: Read mismatch at 3: got 0x%08x, expected 0x00004003\n",
                  32,__Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
    }
    __Vtask_ram_logic_tb__DOT__read_sample__16__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data 
        = __Vtask_ram_logic_tb__DOT__read_sample__16__data;
    if (VL_UNLIKELY((0x4004U != __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data))) {
        VL_WRITEF("ERROR: Read mismatch at 4: got 0x%08x, expected 0x00004004\n",
                  32,__Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
    }
    __Vtask_ram_logic_tb__DOT__read_sample__16__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data 
        = __Vtask_ram_logic_tb__DOT__read_sample__16__data;
    if (VL_UNLIKELY((0x4005U != __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data))) {
        VL_WRITEF("ERROR: Read mismatch at 5: got 0x%08x, expected 0x00004005\n",
                  32,__Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
    }
    __Vtask_ram_logic_tb__DOT__read_sample__16__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data 
        = __Vtask_ram_logic_tb__DOT__read_sample__16__data;
    if (VL_UNLIKELY((0x4006U != __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data))) {
        VL_WRITEF("ERROR: Read mismatch at 6: got 0x%08x, expected 0x00004006\n",
                  32,__Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
    }
    __Vtask_ram_logic_tb__DOT__read_sample__16__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data 
        = __Vtask_ram_logic_tb__DOT__read_sample__16__data;
    if (VL_UNLIKELY((0x4007U != __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data))) {
        VL_WRITEF("ERROR: Read mismatch at 7: got 0x%08x, expected 0x00004007\n",
                  32,__Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
    }
    __Vtask_ram_logic_tb__DOT__read_sample__16__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data 
        = __Vtask_ram_logic_tb__DOT__read_sample__16__data;
    if (VL_UNLIKELY((0x4008U != __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data))) {
        VL_WRITEF("ERROR: Read mismatch at 8: got 0x%08x, expected 0x00004008\n",
                  32,__Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
    }
    __Vtask_ram_logic_tb__DOT__read_sample__16__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data 
        = __Vtask_ram_logic_tb__DOT__read_sample__16__data;
    if (VL_UNLIKELY((0x4009U != __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data))) {
        VL_WRITEF("ERROR: Read mismatch at 9: got 0x%08x, expected 0x00004009\n",
                  32,__Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
    }
    __Vtask_ram_logic_tb__DOT__read_sample__16__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data 
        = __Vtask_ram_logic_tb__DOT__read_sample__16__data;
    if (VL_UNLIKELY((0x400aU != __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data))) {
        VL_WRITEF("ERROR: Read mismatch at 10: got 0x%08x, expected 0x0000400a\n",
                  32,__Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
    }
    __Vtask_ram_logic_tb__DOT__read_sample__16__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data 
        = __Vtask_ram_logic_tb__DOT__read_sample__16__data;
    if (VL_UNLIKELY((0x400bU != __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data))) {
        VL_WRITEF("ERROR: Read mismatch at 11: got 0x%08x, expected 0x0000400b\n",
                  32,__Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
    }
    __Vtask_ram_logic_tb__DOT__read_sample__16__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data 
        = __Vtask_ram_logic_tb__DOT__read_sample__16__data;
    if (VL_UNLIKELY((0x400cU != __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data))) {
        VL_WRITEF("ERROR: Read mismatch at 12: got 0x%08x, expected 0x0000400c\n",
                  32,__Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
    }
    __Vtask_ram_logic_tb__DOT__read_sample__16__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data 
        = __Vtask_ram_logic_tb__DOT__read_sample__16__data;
    if (VL_UNLIKELY((0x400dU != __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data))) {
        VL_WRITEF("ERROR: Read mismatch at 13: got 0x%08x, expected 0x0000400d\n",
                  32,__Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
    }
    __Vtask_ram_logic_tb__DOT__read_sample__16__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data 
        = __Vtask_ram_logic_tb__DOT__read_sample__16__data;
    if (VL_UNLIKELY((0x400eU != __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data))) {
        VL_WRITEF("ERROR: Read mismatch at 14: got 0x%08x, expected 0x0000400e\n",
                  32,__Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->ram_logic_tb__DOT__read_ready = 1U;
    while ((1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__read_valid)))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           132);
    }
    __Vtask_ram_logic_tb__DOT__read_sample__16__data 
        = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
            ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                          >> 4U))] : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
               [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                          >> 4U))]) : 0U);
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       135);
    vlSelf->ram_logic_tb__DOT__read_ready = 0U;
    __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data 
        = __Vtask_ram_logic_tb__DOT__read_sample__16__data;
    if (VL_UNLIKELY((0x400fU != __Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data))) {
        VL_WRITEF("ERROR: Read mismatch at 15: got 0x%08x, expected 0x0000400f\n",
                  32,__Vtask_ram_logic_tb__DOT__test_ping_pong__12__unnamedblk7__DOT__unnamedblk8__DOT__data);
        vlSelf->ram_logic_tb__DOT__test_errors = ((IData)(1U) 
                                                  + vlSelf->ram_logic_tb__DOT__test_errors);
    }
    vlSelf->__Vfork_1__sync.done("ram_logic_tb.sv", 
                                 330);
}

VL_INLINE_OPT VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_1__0(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_1__0\n"); );
    // Init
    IData/*31:0*/ __Vtask_ram_logic_tb__DOT__write_sample__15__data;
    __Vtask_ram_logic_tb__DOT__write_sample__15__data = 0;
    // Body
    __Vtask_ram_logic_tb__DOT__write_sample__15__data = 0x5000U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__15__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__15__data = 0x5001U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__15__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__15__data = 0x5002U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__15__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__15__data = 0x5003U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__15__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__15__data = 0x5004U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__15__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__15__data = 0x5005U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__15__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__15__data = 0x5006U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__15__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__15__data = 0x5007U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__15__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__15__data = 0x5008U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__15__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__15__data = 0x5009U;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__15__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__15__data = 0x500aU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__15__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__15__data = 0x500bU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__15__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__15__data = 0x500cU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__15__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__15__data = 0x500dU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__15__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__15__data = 0x500eU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__15__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    __Vtask_ram_logic_tb__DOT__write_sample__15__data = 0x500fU;
    vlSelf->ram_logic_tb__DOT__write_data = __Vtask_ram_logic_tb__DOT__write_sample__15__data;
    vlSelf->ram_logic_tb__DOT__write_valid = 1U;
    while ((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
        co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge ram_logic_tb.clk)", 
                                                           "ram_logic_tb.sv", 
                                                           119);
    }
    co_await vlSelf->__VtrigSched_h108cd1ff__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge ram_logic_tb.clk)", 
                                                       "ram_logic_tb.sv", 
                                                       121);
    vlSelf->ram_logic_tb__DOT__write_valid = 0U;
    vlSelf->__Vfork_1__sync.done("ram_logic_tb.sv", 
                                 323);
}

VL_INLINE_OPT VlCoroutine Vram_logic_tb___024root___eval_initial__TOP__Vtiming__2(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0x3b9aca00ULL, 
                                       nullptr, "ram_logic_tb.sv", 
                                       445);
    VL_WRITEF("ERROR: Simulation timeout!\n");
    VL_FINISH_MT("ram_logic_tb.sv", 447, "");
}

VL_INLINE_OPT void Vram_logic_tb___024root___act_sequent__TOP__0(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___act_sequent__TOP__0\n"); );
    // Body
    vlSelf->ram_logic_tb__DOT__dut__DOT__write_accepted 
        = ((IData)(vlSelf->ram_logic_tb__DOT__write_valid) 
           & (0x10U > (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q)));
    vlSelf->ram_logic_tb__DOT__dut__DOT__read_accepted 
        = ((IData)(vlSelf->ram_logic_tb__DOT__read_ready) 
           & (IData)(vlSelf->ram_logic_tb__DOT__read_valid));
}

void Vram_logic_tb___024root___eval_act(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_act\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        Vram_logic_tb___024root___act_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*1:0*/, 128> Vram_logic_tb__ConstPool__TABLE_h22b180c3_0;

VL_INLINE_OPT void Vram_logic_tb___024root___nba_sequent__TOP__0(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*3:0*/ __Vdly__ram_logic_tb__DOT__dut__DOT__write_addr_q;
    __Vdly__ram_logic_tb__DOT__dut__DOT__write_addr_q = 0;
    CData/*4:0*/ __Vdly__ram_logic_tb__DOT__dut__DOT__write_count_q;
    __Vdly__ram_logic_tb__DOT__dut__DOT__write_count_q = 0;
    CData/*3:0*/ __Vdly__ram_logic_tb__DOT__dut__DOT__read_addr_q;
    __Vdly__ram_logic_tb__DOT__dut__DOT__read_addr_q = 0;
    CData/*4:0*/ __Vdly__ram_logic_tb__DOT__dut__DOT__read_count_q;
    __Vdly__ram_logic_tb__DOT__dut__DOT__read_count_q = 0;
    SData/*8:0*/ __Vdlyvdim0__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem__v0;
    __Vdlyvdim0__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem__v0;
    __Vdlyvval__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem__v0;
    __Vdlyvset__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem__v0 = 0;
    SData/*8:0*/ __Vdlyvdim0__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem__v0;
    __Vdlyvdim0__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem__v0;
    __Vdlyvval__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem__v0;
    __Vdlyvset__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem__v0 = 0;
    // Body
    __Vdlyvset__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem__v0 = 0U;
    __Vdlyvset__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem__v0 = 0U;
    __Vdly__ram_logic_tb__DOT__dut__DOT__read_count_q 
        = vlSelf->ram_logic_tb__DOT__dut__DOT__read_count_q;
    __Vdly__ram_logic_tb__DOT__dut__DOT__write_count_q 
        = vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q;
    __Vdly__ram_logic_tb__DOT__dut__DOT__read_addr_q 
        = vlSelf->ram_logic_tb__DOT__dut__DOT__read_addr_q;
    __Vdly__ram_logic_tb__DOT__dut__DOT__write_addr_q 
        = vlSelf->ram_logic_tb__DOT__dut__DOT__write_addr_q;
    if (((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_accepted) 
         & (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_buf_sel_q))) {
        __Vdlyvval__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem__v0 
            = vlSelf->ram_logic_tb__DOT__write_data;
        __Vdlyvset__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem__v0 = 1U;
        __Vdlyvdim0__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem__v0 
            = (0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                        >> 4U));
    }
    if (((~ (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_buf_sel_q)) 
         & (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_accepted))) {
        __Vdlyvval__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem__v0 
            = vlSelf->ram_logic_tb__DOT__write_data;
        __Vdlyvset__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem__v0 = 1U;
        __Vdlyvdim0__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem__v0 
            = (0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                        >> 4U));
    }
    if (vlSelf->ram_logic_tb__DOT__rst_n) {
        vlSelf->ram_logic_tb__DOT__buffer_ready = 0U;
        vlSelf->ram_logic_tb__DOT__buffer_overflow = 0U;
        if ((1U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))) {
            vlSelf->ram_logic_tb__DOT__buffer_ready = 1U;
            vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q 
                = vlSelf->ram_logic_tb__DOT__dut__DOT__write_buf_sel_q;
            __Vdly__ram_logic_tb__DOT__dut__DOT__write_addr_q = 0U;
            __Vdly__ram_logic_tb__DOT__dut__DOT__write_count_q = 0U;
            __Vdly__ram_logic_tb__DOT__dut__DOT__read_addr_q = 0U;
            __Vdly__ram_logic_tb__DOT__dut__DOT__read_count_q = 0U;
            vlSelf->ram_logic_tb__DOT__read_valid = 1U;
            vlSelf->ram_logic_tb__DOT__dut__DOT__write_buf_sel_q 
                = (1U & (~ (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_buf_sel_q)));
        } else {
            if (vlSelf->ram_logic_tb__DOT__dut__DOT__write_accepted) {
                if ((0x10U > (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))) {
                    __Vdly__ram_logic_tb__DOT__dut__DOT__write_addr_q 
                        = (0xfU & ((IData)(1U) + (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_addr_q)));
                    __Vdly__ram_logic_tb__DOT__dut__DOT__write_count_q 
                        = (0x1fU & ((IData)(1U) + (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q)));
                } else {
                    vlSelf->ram_logic_tb__DOT__buffer_overflow = 1U;
                }
            }
            if (((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_accepted) 
                 & (2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q)))) {
                if ((0xfU > (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_count_q))) {
                    __Vdly__ram_logic_tb__DOT__dut__DOT__read_addr_q 
                        = (0xfU & ((IData)(1U) + (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_addr_q)));
                    __Vdly__ram_logic_tb__DOT__dut__DOT__read_count_q 
                        = (0x1fU & ((IData)(1U) + (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_count_q)));
                    vlSelf->ram_logic_tb__DOT__read_valid = 1U;
                } else {
                    __Vdly__ram_logic_tb__DOT__dut__DOT__read_addr_q = 0U;
                    __Vdly__ram_logic_tb__DOT__dut__DOT__read_count_q = 0U;
                    vlSelf->ram_logic_tb__DOT__read_valid = 0U;
                }
            } else {
                vlSelf->ram_logic_tb__DOT__read_valid 
                    = ((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q)) 
                       && (0x10U > (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_count_q)));
            }
        }
        vlSelf->ram_logic_tb__DOT__dut__DOT__state_q 
            = vlSelf->ram_logic_tb__DOT__dut__DOT__state_d;
    } else {
        vlSelf->ram_logic_tb__DOT__dut__DOT__write_buf_sel_q = 0U;
        __Vdly__ram_logic_tb__DOT__dut__DOT__write_addr_q = 0U;
        __Vdly__ram_logic_tb__DOT__dut__DOT__read_addr_q = 0U;
        __Vdly__ram_logic_tb__DOT__dut__DOT__write_count_q = 0U;
        __Vdly__ram_logic_tb__DOT__dut__DOT__read_count_q = 0U;
        vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q = 1U;
        vlSelf->ram_logic_tb__DOT__buffer_ready = 0U;
        vlSelf->ram_logic_tb__DOT__buffer_overflow = 0U;
        vlSelf->ram_logic_tb__DOT__read_valid = 0U;
        vlSelf->ram_logic_tb__DOT__dut__DOT__state_q = 0U;
    }
    if (__Vdlyvset__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem__v0) {
        vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem[__Vdlyvdim0__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem__v0] 
            = __Vdlyvval__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem__v0;
    }
    if (__Vdlyvset__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem__v0) {
        vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem[__Vdlyvdim0__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem__v0] 
            = __Vdlyvval__ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem__v0;
    }
    vlSelf->ram_logic_tb__DOT__dut__DOT__read_count_q 
        = __Vdly__ram_logic_tb__DOT__dut__DOT__read_count_q;
    vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q 
        = __Vdly__ram_logic_tb__DOT__dut__DOT__write_count_q;
    vlSelf->ram_logic_tb__DOT__dut__DOT__write_addr_q 
        = __Vdly__ram_logic_tb__DOT__dut__DOT__write_addr_q;
    vlSelf->ram_logic_tb__DOT__dut__DOT__read_addr_q 
        = __Vdly__ram_logic_tb__DOT__dut__DOT__read_addr_q;
    vlSelf->ram_logic_tb__DOT__dut__DOT__read_accepted 
        = ((IData)(vlSelf->ram_logic_tb__DOT__read_ready) 
           & (IData)(vlSelf->ram_logic_tb__DOT__read_valid));
    vlSelf->ram_logic_tb__DOT__dut__DOT__write_accepted 
        = ((IData)(vlSelf->ram_logic_tb__DOT__write_valid) 
           & (0x10U > (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q)));
    if (vlSelf->ram_logic_tb__DOT__dut__DOT__write_buf_sel_q) {
        vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__format_gowin_sp_ram_address__21__addr 
            = vlSelf->ram_logic_tb__DOT__dut__DOT__read_addr_q;
        vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__format_gowin_sp_ram_address__21__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__format_gowin_sp_ram_address__21__addr) 
               << 5U);
        vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr 
            = vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__format_gowin_sp_ram_address__21__Vfuncout;
        vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__format_gowin_sp_ram_address__22__addr 
            = vlSelf->ram_logic_tb__DOT__dut__DOT__write_addr_q;
        vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__format_gowin_sp_ram_address__22__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__format_gowin_sp_ram_address__22__addr) 
               << 5U);
        vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr 
            = vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__format_gowin_sp_ram_address__22__Vfuncout;
    } else {
        vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__format_gowin_sp_ram_address__23__addr 
            = vlSelf->ram_logic_tb__DOT__dut__DOT__write_addr_q;
        vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__format_gowin_sp_ram_address__23__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__format_gowin_sp_ram_address__23__addr) 
               << 5U);
        vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr 
            = vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__format_gowin_sp_ram_address__23__Vfuncout;
        vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__format_gowin_sp_ram_address__24__addr 
            = vlSelf->ram_logic_tb__DOT__dut__DOT__read_addr_q;
        vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__format_gowin_sp_ram_address__24__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__format_gowin_sp_ram_address__24__addr) 
               << 5U);
        vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr 
            = vlSelf->__Vfunc_ram_logic_tb__DOT__dut__DOT__format_gowin_sp_ram_address__24__Vfuncout;
    }
    __Vtableidx1 = (((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q) 
                     << 2U) | (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q));
    vlSelf->ram_logic_tb__DOT__dut__DOT__state_d = 
        Vram_logic_tb__ConstPool__TABLE_h22b180c3_0
        [__Vtableidx1];
}

void Vram_logic_tb___024root___eval_nba(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vram_logic_tb___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
}

void Vram_logic_tb___024root___timing_resume(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___timing_resume\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h108cd1ff__0.resume("@(posedge ram_logic_tb.clk)");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vram_logic_tb___024root___timing_commit(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h108cd1ff__0.commit("@(posedge ram_logic_tb.clk)");
    }
}

void Vram_logic_tb___024root___eval_triggers__act(Vram_logic_tb___024root* vlSelf);

bool Vram_logic_tb___024root___eval_phase__act(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vram_logic_tb___024root___eval_triggers__act(vlSelf);
    Vram_logic_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vram_logic_tb___024root___timing_resume(vlSelf);
        Vram_logic_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vram_logic_tb___024root___eval_phase__nba(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vram_logic_tb___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vram_logic_tb___024root___dump_triggers__nba(Vram_logic_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vram_logic_tb___024root___dump_triggers__act(Vram_logic_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vram_logic_tb___024root___eval(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vram_logic_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("ram_logic_tb.sv", 15, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vram_logic_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("ram_logic_tb.sv", 15, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vram_logic_tb___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vram_logic_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vram_logic_tb___024root___eval_debug_assertions(Vram_logic_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
