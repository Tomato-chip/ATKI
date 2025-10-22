// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vi2s_capture_24_tb.h for the primary calling header

#include "Vi2s_capture_24_tb__pch.h"
#include "Vi2s_capture_24_tb__Syms.h"
#include "Vi2s_capture_24_tb___024root.h"

extern const VlWide<11>/*351:0*/ Vi2s_capture_24_tb__ConstPool__CONST_h5dfafddc_0;

VL_INLINE_OPT VlCoroutine Vi2s_capture_24_tb___024root___eval_initial__TOP__Vtiming__1(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Init
    IData/*31:0*/ i2s_capture_24_tb__DOT____Vrepeat0;
    i2s_capture_24_tb__DOT____Vrepeat0 = 0;
    // Body
    vlSelf->i2s_capture_24_tb__DOT__rst_ni = 0U;
    vlSelf->i2s_capture_24_tb__DOT__frame_count = 0U;
    vlSelf->i2s_capture_24_tb__DOT__test_running = 0U;
    vlSelf->i2s_capture_24_tb__DOT__left_captures = 0U;
    vlSelf->i2s_capture_24_tb__DOT__right_captures = 0U;
    vlSelf->i2s_capture_24_tb__DOT__ready_pulses = 0U;
    vlSelf->i2s_capture_24_tb__DOT__errors = 0U;
    VL_WRITEF("=============================================================================\nI2S Capture 24-bit Testbench\n=============================================================================\nSystem Clock: 27.000 MHz (period = 37.037 ns)\nSCK Clock:    3.375 MHz (period = 296.296 ns)\nFrame: 64 SCK cycles (32 per channel)\n=============================================================================\n\n");
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(11, Vi2s_capture_24_tb__ConstPool__CONST_h5dfafddc_0));
    vlSymsp->_traceDumpOpen();
    vlSelf->i2s_capture_24_tb__DOT__test_phase = 1U;
    VL_WRITEF("[%0t ns] TEST PHASE 1: Reset and Initialization\n",
              64,VL_TIME_UNITED_Q(1000),-9);
    co_await vlSelf->__VtrigSched_he7b63118__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_capture_24_tb.clk_i)", 
                                                       "../../digital/sampler/i2s_capture_24_tb.sv", 
                                                       250);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_he7b63118__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_capture_24_tb.clk_i)", 
                                                       "../../digital/sampler/i2s_capture_24_tb.sv", 
                                                       251);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_he7b63118__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_capture_24_tb.clk_i)", 
                                                       "../../digital/sampler/i2s_capture_24_tb.sv", 
                                                       252);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if ((((0U != vlSelf->i2s_capture_24_tb__DOT__left_o) 
          | (0U != vlSelf->i2s_capture_24_tb__DOT__right_o)) 
         | (IData)(vlSelf->i2s_capture_24_tb__DOT__ready_o))) {
        VL_WRITEF("  [ERROR] Outputs not zero during reset!\n    left_o  = 0x%06x (expected 0x000000)\n    right_o = 0x%06x (expected 0x000000)\n    ready_o = %b (expected 0)\n",
                  24,vlSelf->i2s_capture_24_tb__DOT__left_o,
                  24,vlSelf->i2s_capture_24_tb__DOT__right_o,
                  1,(IData)(vlSelf->i2s_capture_24_tb__DOT__ready_o));
        vlSelf->i2s_capture_24_tb__DOT__errors = ((IData)(1U) 
                                                  + vlSelf->i2s_capture_24_tb__DOT__errors);
    } else {
        VL_WRITEF("  [PASS] Reset state verified\n");
    }
    vlSelf->i2s_capture_24_tb__DOT__rst_ni = 1U;
    co_await vlSelf->__VtrigSched_he7b63118__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_capture_24_tb.clk_i)", 
                                                       "../../digital/sampler/i2s_capture_24_tb.sv", 
                                                       267);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_he7b63118__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_capture_24_tb.clk_i)", 
                                                       "../../digital/sampler/i2s_capture_24_tb.sv", 
                                                       268);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF("  [INFO] Reset released\n\n");
    vlSelf->i2s_capture_24_tb__DOT__test_phase = 2U;
    VL_WRITEF("[%0t ns] TEST PHASE 2: First Frame Capture\n  Testing pattern: Left=0x%06x, Right=0x%06x\n",
              64,VL_TIME_UNITED_Q(1000),-9,24,vlSelf->i2s_capture_24_tb__DOT__left_pattern_1,
              24,vlSelf->i2s_capture_24_tb__DOT__right_pattern_1);
    vlSelf->i2s_capture_24_tb__DOT__test_running = 1U;
    while ((1U & (~ (IData)(vlSelf->i2s_capture_24_tb__DOT__ready_o)))) {
        co_await vlSelf->__VtrigSched_h8d69a51b__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] i2s_capture_24_tb.ready_o)", 
                                                           "../../digital/sampler/i2s_capture_24_tb.sv", 
                                                           282);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_he7b63118__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_capture_24_tb.clk_i)", 
                                                       "../../digital/sampler/i2s_capture_24_tb.sv", 
                                                       283);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if ((vlSelf->i2s_capture_24_tb__DOT__left_o != vlSelf->i2s_capture_24_tb__DOT__left_pattern_1)) {
        VL_WRITEF("  [ERROR] Left channel mismatch!\n    Expected: 0x%06x\n    Got:      0x%06x\n",
                  24,vlSelf->i2s_capture_24_tb__DOT__left_pattern_1,
                  24,vlSelf->i2s_capture_24_tb__DOT__left_o);
        vlSelf->i2s_capture_24_tb__DOT__errors = ((IData)(1U) 
                                                  + vlSelf->i2s_capture_24_tb__DOT__errors);
    } else {
        VL_WRITEF("  [PASS] Left channel captured correctly: 0x%06x\n",
                  24,vlSelf->i2s_capture_24_tb__DOT__left_o);
        vlSelf->i2s_capture_24_tb__DOT__left_captures 
            = ((IData)(1U) + vlSelf->i2s_capture_24_tb__DOT__left_captures);
    }
    if ((vlSelf->i2s_capture_24_tb__DOT__right_o != vlSelf->i2s_capture_24_tb__DOT__right_pattern_1)) {
        VL_WRITEF("  [ERROR] Right channel mismatch!\n    Expected: 0x%06x\n    Got:      0x%06x\n",
                  24,vlSelf->i2s_capture_24_tb__DOT__right_pattern_1,
                  24,vlSelf->i2s_capture_24_tb__DOT__right_o);
        vlSelf->i2s_capture_24_tb__DOT__errors = ((IData)(1U) 
                                                  + vlSelf->i2s_capture_24_tb__DOT__errors);
    } else {
        VL_WRITEF("  [PASS] Right channel captured correctly: 0x%06x\n",
                  24,vlSelf->i2s_capture_24_tb__DOT__right_o);
        vlSelf->i2s_capture_24_tb__DOT__right_captures 
            = ((IData)(1U) + vlSelf->i2s_capture_24_tb__DOT__right_captures);
    }
    vlSelf->i2s_capture_24_tb__DOT__ready_pulses = 
        ((IData)(1U) + vlSelf->i2s_capture_24_tb__DOT__ready_pulses);
    vlSelf->i2s_capture_24_tb__DOT__frame_count = ((IData)(1U) 
                                                   + vlSelf->i2s_capture_24_tb__DOT__frame_count);
    VL_WRITEF("  [INFO] Frame %0d complete\n\n",32,
              vlSelf->i2s_capture_24_tb__DOT__frame_count);
    vlSelf->i2s_capture_24_tb__DOT__test_phase = 3U;
    VL_WRITEF("[%0t ns] TEST PHASE 3: Edge Case Patterns\n  Testing pattern: Left=0x000000, Right=0xffffff\n",
              64,VL_TIME_UNITED_Q(1000),-9);
    while (vlSelf->i2s_capture_24_tb__DOT__ready_o) {
        co_await vlSelf->__VtrigSched_h1a61c2e8__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] (~ i2s_capture_24_tb.ready_o))", 
                                                           "../../digital/sampler/i2s_capture_24_tb.sv", 
                                                           318);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_he7b63118__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_capture_24_tb.clk_i)", 
                                                       "../../digital/sampler/i2s_capture_24_tb.sv", 
                                                       319);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->i2s_capture_24_tb__DOT__left_pattern_1 = 0U;
    vlSelf->i2s_capture_24_tb__DOT__right_pattern_1 = 0xffffffU;
    while ((1U & (~ (IData)(vlSelf->i2s_capture_24_tb__DOT__ready_o)))) {
        co_await vlSelf->__VtrigSched_h8d69a51b__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] i2s_capture_24_tb.ready_o)", 
                                                           "../../digital/sampler/i2s_capture_24_tb.sv", 
                                                           324);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_he7b63118__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_capture_24_tb.clk_i)", 
                                                       "../../digital/sampler/i2s_capture_24_tb.sv", 
                                                       325);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if ((0U != vlSelf->i2s_capture_24_tb__DOT__left_o)) {
        VL_WRITEF("  [ERROR] Left channel (zero) mismatch!\n    Expected: 0x000000\n    Got:      0x%06x\n",
                  24,vlSelf->i2s_capture_24_tb__DOT__left_o);
        vlSelf->i2s_capture_24_tb__DOT__errors = ((IData)(1U) 
                                                  + vlSelf->i2s_capture_24_tb__DOT__errors);
    } else {
        VL_WRITEF("  [PASS] Left channel (zero) captured: 0x%06x\n",
                  24,vlSelf->i2s_capture_24_tb__DOT__left_o);
        vlSelf->i2s_capture_24_tb__DOT__left_captures 
            = ((IData)(1U) + vlSelf->i2s_capture_24_tb__DOT__left_captures);
    }
    if ((0xffffffU != vlSelf->i2s_capture_24_tb__DOT__right_o)) {
        VL_WRITEF("  [ERROR] Right channel (max) mismatch!\n    Expected: 0xffffff\n    Got:      0x%06x\n",
                  24,vlSelf->i2s_capture_24_tb__DOT__right_o);
        vlSelf->i2s_capture_24_tb__DOT__errors = ((IData)(1U) 
                                                  + vlSelf->i2s_capture_24_tb__DOT__errors);
    } else {
        VL_WRITEF("  [PASS] Right channel (max) captured: 0x%06x\n",
                  24,vlSelf->i2s_capture_24_tb__DOT__right_o);
        vlSelf->i2s_capture_24_tb__DOT__right_captures 
            = ((IData)(1U) + vlSelf->i2s_capture_24_tb__DOT__right_captures);
    }
    vlSelf->i2s_capture_24_tb__DOT__ready_pulses = 
        ((IData)(1U) + vlSelf->i2s_capture_24_tb__DOT__ready_pulses);
    vlSelf->i2s_capture_24_tb__DOT__frame_count = ((IData)(1U) 
                                                   + vlSelf->i2s_capture_24_tb__DOT__frame_count);
    VL_WRITEF("  [INFO] Frame %0d complete\n\n",32,
              vlSelf->i2s_capture_24_tb__DOT__frame_count);
    vlSelf->i2s_capture_24_tb__DOT__test_phase = 4U;
    VL_WRITEF("[%0t ns] TEST PHASE 4: Alternating Bit Patterns\n  Testing pattern: Left=0xaaaaaa, Right=0x555555\n",
              64,VL_TIME_UNITED_Q(1000),-9);
    while (vlSelf->i2s_capture_24_tb__DOT__ready_o) {
        co_await vlSelf->__VtrigSched_h1a61c2e8__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] (~ i2s_capture_24_tb.ready_o))", 
                                                           "../../digital/sampler/i2s_capture_24_tb.sv", 
                                                           358);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_he7b63118__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_capture_24_tb.clk_i)", 
                                                       "../../digital/sampler/i2s_capture_24_tb.sv", 
                                                       359);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->i2s_capture_24_tb__DOT__left_pattern_1 = 0xaaaaaaU;
    vlSelf->i2s_capture_24_tb__DOT__right_pattern_1 = 0x555555U;
    while ((1U & (~ (IData)(vlSelf->i2s_capture_24_tb__DOT__ready_o)))) {
        co_await vlSelf->__VtrigSched_h8d69a51b__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] i2s_capture_24_tb.ready_o)", 
                                                           "../../digital/sampler/i2s_capture_24_tb.sv", 
                                                           363);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_he7b63118__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_capture_24_tb.clk_i)", 
                                                       "../../digital/sampler/i2s_capture_24_tb.sv", 
                                                       364);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if ((0xaaaaaaU != vlSelf->i2s_capture_24_tb__DOT__left_o)) {
        VL_WRITEF("  [ERROR] Left channel (0xAAAAAA) mismatch!\n    Expected: 0xaaaaaa\n    Got:      0x%06x\n",
                  24,vlSelf->i2s_capture_24_tb__DOT__left_o);
        vlSelf->i2s_capture_24_tb__DOT__errors = ((IData)(1U) 
                                                  + vlSelf->i2s_capture_24_tb__DOT__errors);
    } else {
        VL_WRITEF("  [PASS] Left channel (0xAAAAAA) captured: 0x%06x\n",
                  24,vlSelf->i2s_capture_24_tb__DOT__left_o);
        vlSelf->i2s_capture_24_tb__DOT__left_captures 
            = ((IData)(1U) + vlSelf->i2s_capture_24_tb__DOT__left_captures);
    }
    if ((0x555555U != vlSelf->i2s_capture_24_tb__DOT__right_o)) {
        VL_WRITEF("  [ERROR] Right channel (0x555555) mismatch!\n    Expected: 0x555555\n    Got:      0x%06x\n",
                  24,vlSelf->i2s_capture_24_tb__DOT__right_o);
        vlSelf->i2s_capture_24_tb__DOT__errors = ((IData)(1U) 
                                                  + vlSelf->i2s_capture_24_tb__DOT__errors);
    } else {
        VL_WRITEF("  [PASS] Right channel (0x555555) captured: 0x%06x\n",
                  24,vlSelf->i2s_capture_24_tb__DOT__right_o);
        vlSelf->i2s_capture_24_tb__DOT__right_captures 
            = ((IData)(1U) + vlSelf->i2s_capture_24_tb__DOT__right_captures);
    }
    vlSelf->i2s_capture_24_tb__DOT__ready_pulses = 
        ((IData)(1U) + vlSelf->i2s_capture_24_tb__DOT__ready_pulses);
    vlSelf->i2s_capture_24_tb__DOT__frame_count = ((IData)(1U) 
                                                   + vlSelf->i2s_capture_24_tb__DOT__frame_count);
    VL_WRITEF("  [INFO] Frame %0d complete\n\n",32,
              vlSelf->i2s_capture_24_tb__DOT__frame_count);
    vlSelf->i2s_capture_24_tb__DOT__test_phase = 5U;
    VL_WRITEF("[%0t ns] TEST PHASE 5: Signed Value Patterns\n  Testing pattern: Left=0x7fffff (max+), Right=0x800000 (min-)\n",
              64,VL_TIME_UNITED_Q(1000),-9);
    while (vlSelf->i2s_capture_24_tb__DOT__ready_o) {
        co_await vlSelf->__VtrigSched_h1a61c2e8__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] (~ i2s_capture_24_tb.ready_o))", 
                                                           "../../digital/sampler/i2s_capture_24_tb.sv", 
                                                           398);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_he7b63118__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_capture_24_tb.clk_i)", 
                                                       "../../digital/sampler/i2s_capture_24_tb.sv", 
                                                       399);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->i2s_capture_24_tb__DOT__left_pattern_1 = 0x7fffffU;
    vlSelf->i2s_capture_24_tb__DOT__right_pattern_1 = 0x800000U;
    while ((1U & (~ (IData)(vlSelf->i2s_capture_24_tb__DOT__ready_o)))) {
        co_await vlSelf->__VtrigSched_h8d69a51b__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] i2s_capture_24_tb.ready_o)", 
                                                           "../../digital/sampler/i2s_capture_24_tb.sv", 
                                                           403);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    co_await vlSelf->__VtrigSched_he7b63118__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_capture_24_tb.clk_i)", 
                                                       "../../digital/sampler/i2s_capture_24_tb.sv", 
                                                       404);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if ((0x7fffffU != vlSelf->i2s_capture_24_tb__DOT__left_o)) {
        VL_WRITEF("  [ERROR] Left channel (max positive) mismatch!\n    Expected: 0x7fffff (8388607)\n    Got:      0x%06x (%0d)\n",
                  24,vlSelf->i2s_capture_24_tb__DOT__left_o,
                  24,vlSelf->i2s_capture_24_tb__DOT__left_o);
        vlSelf->i2s_capture_24_tb__DOT__errors = ((IData)(1U) 
                                                  + vlSelf->i2s_capture_24_tb__DOT__errors);
    } else {
        VL_WRITEF("  [PASS] Left channel (max positive) captured: 0x%06x (%0d)\n",
                  24,vlSelf->i2s_capture_24_tb__DOT__left_o,
                  24,vlSelf->i2s_capture_24_tb__DOT__left_o);
        vlSelf->i2s_capture_24_tb__DOT__left_captures 
            = ((IData)(1U) + vlSelf->i2s_capture_24_tb__DOT__left_captures);
    }
    if ((0x800000U != vlSelf->i2s_capture_24_tb__DOT__right_o)) {
        VL_WRITEF("  [ERROR] Right channel (min negative) mismatch!\n    Expected: 0x800000 (-8388608)\n    Got:      0x%06x (%0d)\n",
                  24,vlSelf->i2s_capture_24_tb__DOT__right_o,
                  24,vlSelf->i2s_capture_24_tb__DOT__right_o);
        vlSelf->i2s_capture_24_tb__DOT__errors = ((IData)(1U) 
                                                  + vlSelf->i2s_capture_24_tb__DOT__errors);
    } else {
        VL_WRITEF("  [PASS] Right channel (min negative) captured: 0x%06x (%0d)\n",
                  24,vlSelf->i2s_capture_24_tb__DOT__right_o,
                  24,vlSelf->i2s_capture_24_tb__DOT__right_o);
        vlSelf->i2s_capture_24_tb__DOT__right_captures 
            = ((IData)(1U) + vlSelf->i2s_capture_24_tb__DOT__right_captures);
    }
    vlSelf->i2s_capture_24_tb__DOT__ready_pulses = 
        ((IData)(1U) + vlSelf->i2s_capture_24_tb__DOT__ready_pulses);
    vlSelf->i2s_capture_24_tb__DOT__frame_count = ((IData)(1U) 
                                                   + vlSelf->i2s_capture_24_tb__DOT__frame_count);
    VL_WRITEF("  [INFO] Frame %0d complete\n\n",32,
              vlSelf->i2s_capture_24_tb__DOT__frame_count);
    vlSelf->i2s_capture_24_tb__DOT__test_phase = 6U;
    VL_WRITEF("[%0t ns] TEST PHASE 6: Ready Pulse Timing\n",
              64,VL_TIME_UNITED_Q(1000),-9);
    co_await vlSelf->__VtrigSched_he7b63118__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_capture_24_tb.clk_i)", 
                                                       "../../digital/sampler/i2s_capture_24_tb.sv", 
                                                       439);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    while ((1U & (~ (IData)(vlSelf->i2s_capture_24_tb__DOT__ready_o)))) {
        co_await vlSelf->__VtrigSched_he7b63118__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge i2s_capture_24_tb.clk_i)", 
                                                           "../../digital/sampler/i2s_capture_24_tb.sv", 
                                                           440);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    vlSelf->i2s_capture_24_tb__DOT__ready_pulse_width = 0U;
    while (vlSelf->i2s_capture_24_tb__DOT__ready_o) {
        vlSelf->i2s_capture_24_tb__DOT__ready_pulse_width 
            = ((IData)(1U) + vlSelf->i2s_capture_24_tb__DOT__ready_pulse_width);
        co_await vlSelf->__VtrigSched_he7b63118__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge i2s_capture_24_tb.clk_i)", 
                                                           "../../digital/sampler/i2s_capture_24_tb.sv", 
                                                           445);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if ((1U != vlSelf->i2s_capture_24_tb__DOT__ready_pulse_width)) {
        VL_WRITEF("  [ERROR] ready_o pulse width incorrect!\n    Expected: 1 cycle\n    Got:      %0d cycles\n",
                  32,vlSelf->i2s_capture_24_tb__DOT__ready_pulse_width);
        vlSelf->i2s_capture_24_tb__DOT__errors = ((IData)(1U) 
                                                  + vlSelf->i2s_capture_24_tb__DOT__errors);
    } else {
        VL_WRITEF("  [PASS] ready_o pulse width correct: %0d cycle\n",
                  32,vlSelf->i2s_capture_24_tb__DOT__ready_pulse_width);
    }
    vlSelf->i2s_capture_24_tb__DOT__ready_pulses = 
        ((IData)(1U) + vlSelf->i2s_capture_24_tb__DOT__ready_pulses);
    vlSelf->i2s_capture_24_tb__DOT__frame_count = ((IData)(1U) 
                                                   + vlSelf->i2s_capture_24_tb__DOT__frame_count);
    VL_WRITEF("  [INFO] Frame %0d complete\n\n",32,
              vlSelf->i2s_capture_24_tb__DOT__frame_count);
    i2s_capture_24_tb__DOT____Vrepeat0 = 0x64U;
    while (VL_LTS_III(32, 0U, i2s_capture_24_tb__DOT____Vrepeat0)) {
        co_await vlSelf->__VtrigSched_he7b63118__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge i2s_capture_24_tb.clk_i)", 
                                                           "../../digital/sampler/i2s_capture_24_tb.sv", 
                                                           464);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        i2s_capture_24_tb__DOT____Vrepeat0 = (i2s_capture_24_tb__DOT____Vrepeat0 
                                              - (IData)(1U));
    }
    vlSelf->i2s_capture_24_tb__DOT__test_running = 0U;
    VL_WRITEF("=============================================================================\nTEST COMPLETE\n=============================================================================\nFrames processed:      %0d\nLeft captures:         %0d\nRight captures:        %0d\nReady pulses observed: %0d\nTotal errors:          %0d\n=============================================================================\n",
              32,vlSelf->i2s_capture_24_tb__DOT__frame_count,
              32,vlSelf->i2s_capture_24_tb__DOT__left_captures,
              32,vlSelf->i2s_capture_24_tb__DOT__right_captures,
              32,vlSelf->i2s_capture_24_tb__DOT__ready_pulses,
              32,vlSelf->i2s_capture_24_tb__DOT__errors);
    if ((0U == vlSelf->i2s_capture_24_tb__DOT__errors)) {
        VL_WRITEF(">>> ALL TESTS PASSED <<<\n");
    } else {
        VL_WRITEF(">>> %0d TEST(S) FAILED <<<\n",32,
                  vlSelf->i2s_capture_24_tb__DOT__errors);
    }
    VL_WRITEF("=============================================================================\n\nWaveform saved to: sim/i2s_capture_24_tb/i2s_capture_24_tb.vcd\n");
    VL_FINISH_MT("../../digital/sampler/i2s_capture_24_tb.sv", 490, "");
    vlSelf->__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vi2s_capture_24_tb___024root___dump_triggers__act(Vi2s_capture_24_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vi2s_capture_24_tb___024root___eval_triggers__act(Vi2s_capture_24_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_capture_24_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_capture_24_tb___024root___eval_triggers__act\n"); );
    // Body
    CData/*0:0*/ __Vtrigcurrexpr_h8e568cca__0;
    __Vtrigcurrexpr_h8e568cca__0 = 0;
    __Vtrigcurrexpr_h8e568cca__0 = (1U & (~ (IData)(vlSelf->i2s_capture_24_tb__DOT__ready_o)));
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->i2s_capture_24_tb__DOT__clk_i) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__i2s_capture_24_tb__DOT__clk_i__0))));
    vlSelf->__VactTriggered.set(1U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__VactTriggered.set(2U, ((IData)(vlSelf->i2s_capture_24_tb__DOT__ready_o) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__i2s_capture_24_tb__DOT__ready_o__0)));
    vlSelf->__VactTriggered.set(3U, ((IData)(__Vtrigcurrexpr_h8e568cca__0) 
                                     != (IData)(vlSelf->__Vtrigprevexpr_h8e568cca__0)));
    vlSelf->__Vtrigprevexpr___TOP__i2s_capture_24_tb__DOT__clk_i__0 
        = vlSelf->i2s_capture_24_tb__DOT__clk_i;
    vlSelf->__Vtrigprevexpr___TOP__i2s_capture_24_tb__DOT__ready_o__0 
        = vlSelf->i2s_capture_24_tb__DOT__ready_o;
    vlSelf->__Vtrigprevexpr_h8e568cca__0 = __Vtrigcurrexpr_h8e568cca__0;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.set(2U, 1U);
        vlSelf->__VactTriggered.set(3U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vi2s_capture_24_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}
