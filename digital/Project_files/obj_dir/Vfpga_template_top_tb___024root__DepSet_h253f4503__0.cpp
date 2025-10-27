// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpga_template_top_tb.h for the primary calling header

#include "Vfpga_template_top_tb__pch.h"
#include "Vfpga_template_top_tb__Syms.h"
#include "Vfpga_template_top_tb___024root.h"

VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_1__0(Vfpga_template_top_tb___024root* vlSelf, VlProcessRef vlProcess);
VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_1__1(Vfpga_template_top_tb___024root* vlSelf, VlProcessRef vlProcess);

VL_INLINE_OPT VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__1(Vfpga_template_top_tb___024root* vlSelf, VlProcessRef vlProcess) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Init
    IData/*31:0*/ __Vtask_fpga_template_top_tb__DOT__check_i2s_activity__2__start_sck;
    __Vtask_fpga_template_top_tb__DOT__check_i2s_activity__2__start_sck = 0;
    IData/*31:0*/ __Vtask_fpga_template_top_tb__DOT__check_i2s_activity__2__start_ws;
    __Vtask_fpga_template_top_tb__DOT__check_i2s_activity__2__start_ws = 0;
    IData/*31:0*/ __Vtask_fpga_template_top_tb__DOT__wait_cycles__3__num_cycles;
    __Vtask_fpga_template_top_tb__DOT__wait_cycles__3__num_cycles = 0;
    IData/*31:0*/ __Vtask_fpga_template_top_tb__DOT__wait_cycles__4__num_cycles;
    __Vtask_fpga_template_top_tb__DOT__wait_cycles__4__num_cycles = 0;
    IData/*31:0*/ __Vtask_fpga_template_top_tb__DOT__wait_cycles__6__num_cycles;
    __Vtask_fpga_template_top_tb__DOT__wait_cycles__6__num_cycles = 0;
    IData/*31:0*/ __Vtask_fpga_template_top_tb__DOT__wait_cycles__7__num_cycles;
    __Vtask_fpga_template_top_tb__DOT__wait_cycles__7__num_cycles = 0;
    IData/*31:0*/ __Vtask_fpga_template_top_tb__DOT__wait_cycles__8__num_cycles;
    __Vtask_fpga_template_top_tb__DOT__wait_cycles__8__num_cycles = 0;
    IData/*31:0*/ __Vtask_fpga_template_top_tb__DOT__wait_cycles__9__num_cycles;
    __Vtask_fpga_template_top_tb__DOT__wait_cycles__9__num_cycles = 0;
    VlWide<6>/*191:0*/ __Vtemp_1;
    // Body
    VL_WRITEF("================================================================================\nFPGA_TEMPLATE_TOP TESTBENCH\n================================================================================\nSystem Clock: 27 MHz (37 ns period)\nSimulation Duration: 10000 us\n================================================================================\n\n");
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x705f7462U;
    __Vtemp_1[2U] = 0x655f746fU;
    __Vtemp_1[3U] = 0x706c6174U;
    __Vtemp_1[4U] = 0x5f74656dU;
    __Vtemp_1[5U] = 0x66706761U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(6, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSymsp->_traceDumpOpen();
    vlSymsp->_traceDumpOpen();
    vlSymsp->_traceDumpOpen();
    vlSymsp->_traceDumpOpen();
    vlSymsp->_traceDumpOpen();
    vlSelf->fpga_template_top_tb__DOT__clk = 0U;
    VL_WRITEF("\n[TEST 1] Reset and Initialization\n");
    VL_WRITEF("[%0t] Applying reset...\n",64,VL_TIME_UNITED_Q(1000),
              -9);
    vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb = 1U;
    vlSelf->fpga_template_top_tb__DOT__btn_s2 = 0U;
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       vlProcess, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       224);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       vlProcess, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       224);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       vlProcess, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       224);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       vlProcess, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       224);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       vlProcess, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       224);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       vlProcess, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       224);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       vlProcess, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       224);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       vlProcess, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       224);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       vlProcess, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       224);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       vlProcess, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       224);
    vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb = 0U;
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       vlProcess, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       226);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       vlProcess, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       226);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       vlProcess, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       226);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       vlProcess, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       226);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       vlProcess, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       226);
    VL_WRITEF("[%0t] Reset released\n",64,VL_TIME_UNITED_Q(1000),
              -9);
    if (VL_UNLIKELY(vlSelf->fpga_template_top_tb__DOT__buffer_full)) {
        VL_WRITEF("[TEST 1] ERROR: buffer_full should be 0 after reset\n");
        vlSelf->fpga_template_top_tb__DOT__error_count 
            = ((IData)(1U) + vlSelf->fpga_template_top_tb__DOT__error_count);
    }
    VL_WRITEF("[TEST 1] PASSED - Reset complete\n\n\n[TEST 2] I2S Clock Generation\n");
    __Vtask_fpga_template_top_tb__DOT__check_i2s_activity__2__start_sck 
        = vlSelf->fpga_template_top_tb__DOT__sck_edge_count;
    __Vtask_fpga_template_top_tb__DOT__check_i2s_activity__2__start_ws 
        = vlSelf->fpga_template_top_tb__DOT__ws_transition_count;
    VL_WRITEF("[%0t] Checking I2S activity...\n",64,
              VL_TIME_UNITED_Q(1000),-9);
    __Vtask_fpga_template_top_tb__DOT__wait_cycles__3__num_cycles = 0x3e8U;
    vlSelf->fpga_template_top_tb__DOT____Vrepeat2 = __Vtask_fpga_template_top_tb__DOT__wait_cycles__3__num_cycles;
    while (VL_LTS_III(32, 0U, vlSelf->fpga_template_top_tb__DOT____Vrepeat2)) {
        co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                           vlProcess, 
                                                           "@(posedge fpga_template_top_tb.clk)", 
                                                           "fpga_template_top_tb.sv", 
                                                           231);
        vlSelf->fpga_template_top_tb__DOT____Vrepeat2 
            = (vlSelf->fpga_template_top_tb__DOT____Vrepeat2 
               - (IData)(1U));
    }
    if (VL_LTES_III(32, vlSelf->fpga_template_top_tb__DOT__sck_edge_count, __Vtask_fpga_template_top_tb__DOT__check_i2s_activity__2__start_sck)) {
        VL_WRITEF("[%0t] ERROR: I2S SCK not toggling!\n",
                  64,VL_TIME_UNITED_Q(1000),-9);
        vlSelf->fpga_template_top_tb__DOT__error_count 
            = ((IData)(1U) + vlSelf->fpga_template_top_tb__DOT__error_count);
    } else {
        VL_WRITEF("[%0t] I2S SCK active: %0d edges\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,(vlSelf->fpga_template_top_tb__DOT__sck_edge_count 
                                                   - __Vtask_fpga_template_top_tb__DOT__check_i2s_activity__2__start_sck));
    }
    if (VL_LTES_III(32, vlSelf->fpga_template_top_tb__DOT__ws_transition_count, __Vtask_fpga_template_top_tb__DOT__check_i2s_activity__2__start_ws)) {
        VL_WRITEF("[%0t] WARNING: I2S WS not toggling\n",
                  64,VL_TIME_UNITED_Q(1000),-9);
    } else {
        VL_WRITEF("[%0t] I2S WS active: %0d transitions\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,(vlSelf->fpga_template_top_tb__DOT__ws_transition_count 
                                                   - __Vtask_fpga_template_top_tb__DOT__check_i2s_activity__2__start_ws));
    }
    VL_WRITEF("[TEST 2] PASSED\n\n\n[TEST 3] Normal Operation - Run for 500us\n");
    __Vtask_fpga_template_top_tb__DOT__wait_cycles__4__num_cycles = 0x34bcU;
    vlSelf->fpga_template_top_tb__DOT____Vrepeat2 = __Vtask_fpga_template_top_tb__DOT__wait_cycles__4__num_cycles;
    while (VL_LTS_III(32, 0U, vlSelf->fpga_template_top_tb__DOT____Vrepeat2)) {
        co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                           vlProcess, 
                                                           "@(posedge fpga_template_top_tb.clk)", 
                                                           "fpga_template_top_tb.sv", 
                                                           231);
        vlSelf->fpga_template_top_tb__DOT____Vrepeat2 
            = (vlSelf->fpga_template_top_tb__DOT____Vrepeat2 
               - (IData)(1U));
    }
    VL_WRITEF("[TEST 3] Statistics:\n  SCK edges: %0d\n  WS transitions: %0d\n  Buffer overflows: %0d\n  Final LED state: 0x%02x\n",
              32,vlSelf->fpga_template_top_tb__DOT__sck_edge_count,
              32,vlSelf->fpga_template_top_tb__DOT__ws_transition_count,
              32,((IData)(vlSelf->fpga_template_top_tb__DOT__buffer_full)
                   ? 1U : 0U),6,(0x3fU & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__debug_sample_led))));
    if (VL_GTS_III(32, 0x64U, vlSelf->fpga_template_top_tb__DOT__sck_edge_count)) {
        VL_WRITEF("[TEST 3] ERROR: Too few SCK edges\n");
        vlSelf->fpga_template_top_tb__DOT__error_count 
            = ((IData)(1U) + vlSelf->fpga_template_top_tb__DOT__error_count);
    } else {
        VL_WRITEF("[TEST 3] PASSED\n\n");
    }
    VL_WRITEF("\n[TEST 4] Extended Operation - Waiting for RAM buffer swap\n  Need 256 samples @ 52.7kHz = ~4.85ms\n");
    vlSelf->__Vfork_1__sync.init(1U, vlProcess);
    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_1__0(vlSelf, std::make_shared<VlProcess>(vlProcess));
    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_1__1(vlSelf, std::make_shared<VlProcess>(vlProcess));
    co_await vlSelf->__Vfork_1__sync.join(vlProcess, 
                                          "fpga_template_top_tb.sv", 
                                          329);
    vlProcess->disableFork();
    __Vtask_fpga_template_top_tb__DOT__wait_cycles__6__num_cycles = 0x3e8U;
    vlSelf->fpga_template_top_tb__DOT____Vrepeat2 = __Vtask_fpga_template_top_tb__DOT__wait_cycles__6__num_cycles;
    while (VL_LTS_III(32, 0U, vlSelf->fpga_template_top_tb__DOT____Vrepeat2)) {
        co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                           vlProcess, 
                                                           "@(posedge fpga_template_top_tb.clk)", 
                                                           "fpga_template_top_tb.sv", 
                                                           231);
        vlSelf->fpga_template_top_tb__DOT____Vrepeat2 
            = (vlSelf->fpga_template_top_tb__DOT____Vrepeat2 
               - (IData)(1U));
    }
    VL_WRITEF("[TEST 4] Final Statistics:\n  Total SCK edges: %0d\n  Total WS transitions: %0d\n  LED state: 0x%02x (inverted, so 0x3F = all on)\n",
              32,vlSelf->fpga_template_top_tb__DOT__sck_edge_count,
              32,vlSelf->fpga_template_top_tb__DOT__ws_transition_count,
              6,(0x3fU & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__debug_sample_led))));
    if (VL_UNLIKELY(VL_GTS_III(32, 0x32U, vlSelf->fpga_template_top_tb__DOT__ws_transition_count))) {
        VL_WRITEF("[TEST 4] WARNING: Fewer WS transitions than expected\n");
    }
    VL_WRITEF("[TEST 4] PASSED\n\n\n[TEST 5] Button S2 Press Test\n");
    vlSelf->fpga_template_top_tb__DOT__btn_s2 = 1U;
    __Vtask_fpga_template_top_tb__DOT__wait_cycles__7__num_cycles = 0x64U;
    vlSelf->fpga_template_top_tb__DOT____Vrepeat2 = __Vtask_fpga_template_top_tb__DOT__wait_cycles__7__num_cycles;
    while (VL_LTS_III(32, 0U, vlSelf->fpga_template_top_tb__DOT____Vrepeat2)) {
        co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                           vlProcess, 
                                                           "@(posedge fpga_template_top_tb.clk)", 
                                                           "fpga_template_top_tb.sv", 
                                                           231);
        vlSelf->fpga_template_top_tb__DOT____Vrepeat2 
            = (vlSelf->fpga_template_top_tb__DOT____Vrepeat2 
               - (IData)(1U));
    }
    vlSelf->fpga_template_top_tb__DOT__btn_s2 = 0U;
    __Vtask_fpga_template_top_tb__DOT__wait_cycles__8__num_cycles = 0x64U;
    vlSelf->fpga_template_top_tb__DOT____Vrepeat2 = __Vtask_fpga_template_top_tb__DOT__wait_cycles__8__num_cycles;
    while (VL_LTS_III(32, 0U, vlSelf->fpga_template_top_tb__DOT____Vrepeat2)) {
        co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                           vlProcess, 
                                                           "@(posedge fpga_template_top_tb.clk)", 
                                                           "fpga_template_top_tb.sv", 
                                                           231);
        vlSelf->fpga_template_top_tb__DOT____Vrepeat2 
            = (vlSelf->fpga_template_top_tb__DOT____Vrepeat2 
               - (IData)(1U));
    }
    VL_WRITEF("[TEST 5] PASSED - Button handled\n\n");
    __Vtask_fpga_template_top_tb__DOT__wait_cycles__9__num_cycles = 0x64U;
    vlSelf->fpga_template_top_tb__DOT____Vrepeat2 = __Vtask_fpga_template_top_tb__DOT__wait_cycles__9__num_cycles;
    while (VL_LTS_III(32, 0U, vlSelf->fpga_template_top_tb__DOT____Vrepeat2)) {
        co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                           vlProcess, 
                                                           "@(posedge fpga_template_top_tb.clk)", 
                                                           "fpga_template_top_tb.sv", 
                                                           231);
        vlSelf->fpga_template_top_tb__DOT____Vrepeat2 
            = (vlSelf->fpga_template_top_tb__DOT____Vrepeat2 
               - (IData)(1U));
    }
    VL_WRITEF("\n================================================================================\nTEST COMPLETE\n================================================================================\nSimulation time: %0t\n\nI2S Clock Statistics:\n  Total SCK edges: %0d\n  Total WS transitions: %0d\n  Calculated sample rate: ~%0# Hz\n\nData Path Statistics:\n  Samples captured: %0d\n  RAM buffer swaps: %0d\n  Buffer overflows: %0d\n\nOutput State:\n  Final LED state: 0x%02x (inverted: 0x%02x active)\n  LED binary: %06b\n",
              64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->fpga_template_top_tb__DOT__sck_edge_count,
              32,vlSelf->fpga_template_top_tb__DOT__ws_transition_count,
              64,VL_DIV_QQQ(64, (0xf4240ULL * (QData)((IData)(vlSelf->fpga_template_top_tb__DOT__ws_transition_count))), 
                            VL_DIV_QQQ(64, (QData)(VL_TIME_UNITED_Q(1000)), 0x3e8ULL)),
              32,vlSelf->fpga_template_top_tb__DOT__captured_sample_count,
              32,vlSelf->fpga_template_top_tb__DOT__buffer_swap_count,
              32,((IData)(vlSelf->fpga_template_top_tb__DOT__buffer_full)
                   ? 1U : 0U),6,(0x3fU & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__debug_sample_led))),
              6,(IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__debug_sample_led),
              6,(0x3fU & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__debug_sample_led))));
    VL_WRITEF("\nTest Results:\n  Total errors: %0d\n",
              32,vlSelf->fpga_template_top_tb__DOT__error_count);
    if ((0U == vlSelf->fpga_template_top_tb__DOT__error_count)) {
        VL_WRITEF("\n*** ALL TESTS PASSED ***\n");
    } else {
        VL_WRITEF("\n*** TESTS FAILED - %0d errors ***\n",
                  32,vlSelf->fpga_template_top_tb__DOT__error_count);
    }
    VL_WRITEF("================================================================================\n\n");
    VL_FINISH_MT("fpga_template_top_tb.sv", 396, "");
    vlProcess->state(VlProcess::FINISHED);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpga_template_top_tb___024root___dump_triggers__act(Vfpga_template_top_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vfpga_template_top_tb___024root___eval_triggers__act(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->fpga_template_top_tb__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__clk__0))));
    vlSelf->__VactTriggered.set(1U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__VactTriggered.set(2U, ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w__0)));
    vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__clk__0 
        = vlSelf->fpga_template_top_tb__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w__0 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.set(2U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vfpga_template_top_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}
