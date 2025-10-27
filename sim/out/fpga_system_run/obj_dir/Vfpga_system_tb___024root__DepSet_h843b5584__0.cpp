// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpga_system_tb.h for the primary calling header

#include "Vfpga_system_tb__pch.h"
#include "Vfpga_system_tb__Syms.h"
#include "Vfpga_system_tb___024root.h"

VL_INLINE_OPT VlCoroutine Vfpga_system_tb___024root___eval_initial__TOP__Vtiming__1(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Init
    IData/*31:0*/ fpga_system_tb__DOT____Vrepeat2;
    fpga_system_tb__DOT____Vrepeat2 = 0;
    IData/*31:0*/ fpga_system_tb__DOT____Vrepeat3;
    fpga_system_tb__DOT____Vrepeat3 = 0;
    IData/*31:0*/ fpga_system_tb__DOT____Vrepeat4;
    fpga_system_tb__DOT____Vrepeat4 = 0;
    IData/*31:0*/ fpga_system_tb__DOT____Vrepeat5;
    fpga_system_tb__DOT____Vrepeat5 = 0;
    IData/*31:0*/ __Vtask_fpga_system_tb__DOT__wait_for_buffers__1__num_buffers;
    __Vtask_fpga_system_tb__DOT__wait_for_buffers__1__num_buffers = 0;
    IData/*31:0*/ __Vtask_fpga_system_tb__DOT__wait_for_buffers__1__start_count;
    __Vtask_fpga_system_tb__DOT__wait_for_buffers__1__start_count = 0;
    IData/*31:0*/ __Vtask_fpga_system_tb__DOT__wait_for_buffers__1__timeout;
    __Vtask_fpga_system_tb__DOT__wait_for_buffers__1__timeout = 0;
    IData/*31:0*/ __Vtask_fpga_system_tb__DOT__wait_for_buffers__1__max_timeout;
    __Vtask_fpga_system_tb__DOT__wait_for_buffers__1__max_timeout = 0;
    IData/*31:0*/ __Vtask_fpga_system_tb__DOT__wait_for_buffers__2__num_buffers;
    __Vtask_fpga_system_tb__DOT__wait_for_buffers__2__num_buffers = 0;
    IData/*31:0*/ __Vtask_fpga_system_tb__DOT__wait_for_buffers__2__start_count;
    __Vtask_fpga_system_tb__DOT__wait_for_buffers__2__start_count = 0;
    IData/*31:0*/ __Vtask_fpga_system_tb__DOT__wait_for_buffers__2__timeout;
    __Vtask_fpga_system_tb__DOT__wait_for_buffers__2__timeout = 0;
    IData/*31:0*/ __Vtask_fpga_system_tb__DOT__wait_for_buffers__2__max_timeout;
    __Vtask_fpga_system_tb__DOT__wait_for_buffers__2__max_timeout = 0;
    VlWide<5>/*159:0*/ __Vtemp_1;
    // Body
    VL_WRITEF("================================================================================\nFPGA SYSTEM INTEGRATION TESTBENCH\n================================================================================\nTesting: Clock Gen -> I2S Capture -> RAM Logic -> VU Meter\nParameters: RAM_DEPTH=32, RAM_WIDTH=32\n================================================================================\n\n");
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x6d5f7462U;
    __Vtemp_1[2U] = 0x79737465U;
    __Vtemp_1[3U] = 0x67615f73U;
    __Vtemp_1[4U] = 0x6670U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(5, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSymsp->_traceDumpOpen();
    vlSymsp->_traceDumpOpen();
    vlSymsp->_traceDumpOpen();
    vlSymsp->_traceDumpOpen();
    VL_WRITEF("\n[TEST 1] Reset and Initialization\n");
    VL_WRITEF("[%0t] Applying reset...\n",64,VL_TIME_UNITED_Q(1000),
              -9);
    vlSelf->fpga_system_tb__DOT__rst_n = 0U;
    co_await vlSelf->__VtrigSched_ha159ce0d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_system_tb.clk)", 
                                                       "fpga_system_tb.sv", 
                                                       229);
    co_await vlSelf->__VtrigSched_ha159ce0d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_system_tb.clk)", 
                                                       "fpga_system_tb.sv", 
                                                       229);
    co_await vlSelf->__VtrigSched_ha159ce0d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_system_tb.clk)", 
                                                       "fpga_system_tb.sv", 
                                                       229);
    co_await vlSelf->__VtrigSched_ha159ce0d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_system_tb.clk)", 
                                                       "fpga_system_tb.sv", 
                                                       229);
    co_await vlSelf->__VtrigSched_ha159ce0d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_system_tb.clk)", 
                                                       "fpga_system_tb.sv", 
                                                       229);
    co_await vlSelf->__VtrigSched_ha159ce0d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_system_tb.clk)", 
                                                       "fpga_system_tb.sv", 
                                                       229);
    co_await vlSelf->__VtrigSched_ha159ce0d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_system_tb.clk)", 
                                                       "fpga_system_tb.sv", 
                                                       229);
    co_await vlSelf->__VtrigSched_ha159ce0d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_system_tb.clk)", 
                                                       "fpga_system_tb.sv", 
                                                       229);
    co_await vlSelf->__VtrigSched_ha159ce0d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_system_tb.clk)", 
                                                       "fpga_system_tb.sv", 
                                                       229);
    co_await vlSelf->__VtrigSched_ha159ce0d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_system_tb.clk)", 
                                                       "fpga_system_tb.sv", 
                                                       229);
    vlSelf->fpga_system_tb__DOT__rst_n = 1U;
    co_await vlSelf->__VtrigSched_ha159ce0d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_system_tb.clk)", 
                                                       "fpga_system_tb.sv", 
                                                       231);
    co_await vlSelf->__VtrigSched_ha159ce0d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_system_tb.clk)", 
                                                       "fpga_system_tb.sv", 
                                                       231);
    co_await vlSelf->__VtrigSched_ha159ce0d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_system_tb.clk)", 
                                                       "fpga_system_tb.sv", 
                                                       231);
    co_await vlSelf->__VtrigSched_ha159ce0d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_system_tb.clk)", 
                                                       "fpga_system_tb.sv", 
                                                       231);
    co_await vlSelf->__VtrigSched_ha159ce0d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_system_tb.clk)", 
                                                       "fpga_system_tb.sv", 
                                                       231);
    VL_WRITEF("[%0t] Reset released\n",64,VL_TIME_UNITED_Q(1000),
              -9);
    if (VL_UNLIKELY((0x20U <= (IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_count)))) {
        VL_WRITEF("[TEST 1] ERROR: RAM not ready after reset\n");
        vlSelf->fpga_system_tb__DOT__error_count = 
            ((IData)(1U) + vlSelf->fpga_system_tb__DOT__error_count);
    }
    if (VL_UNLIKELY(vlSelf->fpga_system_tb__DOT__ram_read_valid)) {
        VL_WRITEF("[TEST 1] ERROR: RAM read valid after reset\n");
        vlSelf->fpga_system_tb__DOT__error_count = 
            ((IData)(1U) + vlSelf->fpga_system_tb__DOT__error_count);
    }
    VL_WRITEF("[TEST 1] PASSED\n\n\n[TEST 2] I2S Clock Generation\n");
    fpga_system_tb__DOT____Vrepeat2 = 0x1f4U;
    while (VL_LTS_III(32, 0U, fpga_system_tb__DOT____Vrepeat2)) {
        co_await vlSelf->__VtrigSched_ha159ce0d__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge fpga_system_tb.clk)", 
                                                           "fpga_system_tb.sv", 
                                                           308);
        fpga_system_tb__DOT____Vrepeat2 = (fpga_system_tb__DOT____Vrepeat2 
                                           - (IData)(1U));
    }
    if (VL_GTS_III(32, 1U, vlSelf->fpga_system_tb__DOT__sample_count)) {
        VL_WRITEF("[TEST 2] ERROR: No samples captured\n");
        vlSelf->fpga_system_tb__DOT__error_count = 
            ((IData)(1U) + vlSelf->fpga_system_tb__DOT__error_count);
    } else {
        VL_WRITEF("[TEST 2] PASSED - %0d samples captured\n",
                  32,vlSelf->fpga_system_tb__DOT__sample_count);
    }
    VL_WRITEF("\n[TEST 3] First Buffer Fill\n");
    __Vtask_fpga_system_tb__DOT__wait_for_buffers__1__num_buffers = 1U;
    __Vtask_fpga_system_tb__DOT__wait_for_buffers__1__start_count 
        = vlSelf->fpga_system_tb__DOT__buffer_count;
    __Vtask_fpga_system_tb__DOT__wait_for_buffers__1__timeout = 0U;
    __Vtask_fpga_system_tb__DOT__wait_for_buffers__1__max_timeout = 0xf4240U;
    VL_WRITEF("[%0t] Waiting for %0d buffers to complete...\n",
              64,VL_TIME_UNITED_Q(1000),-9,32,__Vtask_fpga_system_tb__DOT__wait_for_buffers__1__num_buffers);
    while ((VL_LTS_III(32, (vlSelf->fpga_system_tb__DOT__buffer_count 
                            - __Vtask_fpga_system_tb__DOT__wait_for_buffers__1__start_count), __Vtask_fpga_system_tb__DOT__wait_for_buffers__1__num_buffers) 
            & VL_LTS_III(32, __Vtask_fpga_system_tb__DOT__wait_for_buffers__1__timeout, __Vtask_fpga_system_tb__DOT__wait_for_buffers__1__max_timeout))) {
        co_await vlSelf->__VtrigSched_ha159ce0d__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge fpga_system_tb.clk)", 
                                                           "fpga_system_tb.sv", 
                                                           243);
        __Vtask_fpga_system_tb__DOT__wait_for_buffers__1__timeout 
            = ((IData)(1U) + __Vtask_fpga_system_tb__DOT__wait_for_buffers__1__timeout);
    }
    if (VL_GTES_III(32, __Vtask_fpga_system_tb__DOT__wait_for_buffers__1__timeout, __Vtask_fpga_system_tb__DOT__wait_for_buffers__1__max_timeout)) {
        VL_WRITEF("[%0t] ERROR: Timeout waiting for buffers\n",
                  64,VL_TIME_UNITED_Q(1000),-9);
        vlSelf->fpga_system_tb__DOT__error_count = 
            ((IData)(1U) + vlSelf->fpga_system_tb__DOT__error_count);
    } else {
        VL_WRITEF("[%0t] %0d buffers completed\n",64,
                  VL_TIME_UNITED_Q(1000),-9,32,__Vtask_fpga_system_tb__DOT__wait_for_buffers__1__num_buffers);
    }
    if (VL_GTS_III(32, 1U, vlSelf->fpga_system_tb__DOT__buffer_count)) {
        VL_WRITEF("[TEST 3] ERROR: First buffer not filled\n");
        vlSelf->fpga_system_tb__DOT__error_count = 
            ((IData)(1U) + vlSelf->fpga_system_tb__DOT__error_count);
    } else {
        VL_WRITEF("[TEST 3] PASSED - First buffer filled after %0d samples\n",
                  32,vlSelf->fpga_system_tb__DOT__sample_count);
    }
    VL_WRITEF("\n[TEST 4] VU Meter Consumer Operation\n");
    fpga_system_tb__DOT____Vrepeat3 = 0x1388U;
    while (VL_LTS_III(32, 0U, fpga_system_tb__DOT____Vrepeat3)) {
        co_await vlSelf->__VtrigSched_ha159ce0d__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge fpga_system_tb.clk)", 
                                                           "fpga_system_tb.sv", 
                                                           337);
        fpga_system_tb__DOT____Vrepeat3 = (fpga_system_tb__DOT____Vrepeat3 
                                           - (IData)(1U));
    }
    if ((0U == (IData)(vlSelf->fpga_system_tb__DOT__leds))) {
        VL_WRITEF("[TEST 4] WARNING: LEDs still all zero (may be low signal)\n");
    } else {
        VL_WRITEF("[TEST 4] PASSED - VU meter active, LEDs = 0x%02x\n",
                  6,vlSelf->fpga_system_tb__DOT__leds);
    }
    VL_WRITEF("\n[TEST 5] Continuous Ping-Pong Operation\n");
    vlSelf->fpga_system_tb__DOT__unnamedblk1__DOT__start_buf_count 
        = vlSelf->fpga_system_tb__DOT__buffer_count;
    __Vtask_fpga_system_tb__DOT__wait_for_buffers__2__num_buffers = 2U;
    __Vtask_fpga_system_tb__DOT__wait_for_buffers__2__start_count 
        = vlSelf->fpga_system_tb__DOT__buffer_count;
    __Vtask_fpga_system_tb__DOT__wait_for_buffers__2__timeout = 0U;
    __Vtask_fpga_system_tb__DOT__wait_for_buffers__2__max_timeout = 0xf4240U;
    VL_WRITEF("[%0t] Waiting for %0d buffers to complete...\n",
              64,VL_TIME_UNITED_Q(1000),-9,32,__Vtask_fpga_system_tb__DOT__wait_for_buffers__2__num_buffers);
    while ((VL_LTS_III(32, (vlSelf->fpga_system_tb__DOT__buffer_count 
                            - __Vtask_fpga_system_tb__DOT__wait_for_buffers__2__start_count), __Vtask_fpga_system_tb__DOT__wait_for_buffers__2__num_buffers) 
            & VL_LTS_III(32, __Vtask_fpga_system_tb__DOT__wait_for_buffers__2__timeout, __Vtask_fpga_system_tb__DOT__wait_for_buffers__2__max_timeout))) {
        co_await vlSelf->__VtrigSched_ha159ce0d__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge fpga_system_tb.clk)", 
                                                           "fpga_system_tb.sv", 
                                                           243);
        __Vtask_fpga_system_tb__DOT__wait_for_buffers__2__timeout 
            = ((IData)(1U) + __Vtask_fpga_system_tb__DOT__wait_for_buffers__2__timeout);
    }
    if (VL_GTES_III(32, __Vtask_fpga_system_tb__DOT__wait_for_buffers__2__timeout, __Vtask_fpga_system_tb__DOT__wait_for_buffers__2__max_timeout)) {
        VL_WRITEF("[%0t] ERROR: Timeout waiting for buffers\n",
                  64,VL_TIME_UNITED_Q(1000),-9);
        vlSelf->fpga_system_tb__DOT__error_count = 
            ((IData)(1U) + vlSelf->fpga_system_tb__DOT__error_count);
    } else {
        VL_WRITEF("[%0t] %0d buffers completed\n",64,
                  VL_TIME_UNITED_Q(1000),-9,32,__Vtask_fpga_system_tb__DOT__wait_for_buffers__2__num_buffers);
    }
    if (VL_GTS_III(32, 2U, (vlSelf->fpga_system_tb__DOT__buffer_count 
                            - vlSelf->fpga_system_tb__DOT__unnamedblk1__DOT__start_buf_count))) {
        VL_WRITEF("[TEST 5] ERROR: Ping-pong not working\n");
        vlSelf->fpga_system_tb__DOT__error_count = 
            ((IData)(1U) + vlSelf->fpga_system_tb__DOT__error_count);
    } else {
        VL_WRITEF("[TEST 5] PASSED - Multiple buffers processed\n");
    }
    VL_WRITEF("\n[TEST 6] Overflow Prevention\n");
    fpga_system_tb__DOT____Vrepeat4 = 0x2710U;
    while (VL_LTS_III(32, 0U, fpga_system_tb__DOT____Vrepeat4)) {
        co_await vlSelf->__VtrigSched_ha159ce0d__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge fpga_system_tb.clk)", 
                                                           "fpga_system_tb.sv", 
                                                           369);
        fpga_system_tb__DOT____Vrepeat4 = (fpga_system_tb__DOT____Vrepeat4 
                                           - (IData)(1U));
    }
    co_await vlSelf->__VtrigSched_ha159ce0d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_system_tb.clk)", 
                                                       "fpga_system_tb.sv", 
                                                       256);
    if (VL_UNLIKELY(vlSelf->fpga_system_tb__DOT__ram_overflow)) {
        VL_WRITEF("[%0t] ERROR: Unexpected overflow\n",
                  64,VL_TIME_UNITED_Q(1000),-9);
        vlSelf->fpga_system_tb__DOT__error_count = 
            ((IData)(1U) + vlSelf->fpga_system_tb__DOT__error_count);
    }
    VL_WRITEF("[TEST 6] PASSED - No overflow detected\n");
    fpga_system_tb__DOT____Vrepeat5 = 0x64U;
    while (VL_LTS_III(32, 0U, fpga_system_tb__DOT____Vrepeat5)) {
        co_await vlSelf->__VtrigSched_ha159ce0d__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge fpga_system_tb.clk)", 
                                                           "fpga_system_tb.sv", 
                                                           377);
        fpga_system_tb__DOT____Vrepeat5 = (fpga_system_tb__DOT____Vrepeat5 
                                           - (IData)(1U));
    }
    VL_WRITEF("\n================================================================================\nTEST COMPLETE\n================================================================================\nTotal samples captured: %0d\nTotal buffers completed: %0d\nFinal LED state: 0x%02x (%06b)\nRAM write count: %0#\nRAM read count: %0#\nTotal errors: %0d\n",
              32,vlSelf->fpga_system_tb__DOT__sample_count,
              32,vlSelf->fpga_system_tb__DOT__buffer_count,
              6,(IData)(vlSelf->fpga_system_tb__DOT__leds),
              6,vlSelf->fpga_system_tb__DOT__leds,9,
              (IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_count),
              9,vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_count,
              32,vlSelf->fpga_system_tb__DOT__error_count);
    if ((0U == vlSelf->fpga_system_tb__DOT__error_count)) {
        VL_WRITEF("\n*** ALL TESTS PASSED ***\n");
    } else {
        VL_WRITEF("\n*** TESTS FAILED - %0d errors ***\n",
                  32,vlSelf->fpga_system_tb__DOT__error_count);
    }
    VL_WRITEF("================================================================================\n\n");
    VL_FINISH_MT("fpga_system_tb.sv", 396, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpga_system_tb___024root___dump_triggers__act(Vfpga_system_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vfpga_system_tb___024root___eval_triggers__act(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->fpga_system_tb__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__fpga_system_tb__DOT__clk__0))));
    vlSelf->__VactTriggered.set(1U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__fpga_system_tb__DOT__clk__0 
        = vlSelf->fpga_system_tb__DOT__clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vfpga_system_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}
