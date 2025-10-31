// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpga_template_top_tb.h for the primary calling header

#include "Vfpga_template_top_tb__pch.h"
#include "Vfpga_template_top_tb__Syms.h"
#include "Vfpga_template_top_tb___024root.h"

VL_INLINE_OPT VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__5(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__5\n"); );
    // Body
    vlSelf->fpga_template_top_tb__DOT__handshake_count = 0U;
    vlSelf->fpga_template_top_tb__DOT__ready_low_cycles = 0U;
    vlSelf->fpga_template_top_tb__DOT__monitor_handshake = 0U;
    vlSelf->fpga_template_top_tb__DOT__prev_sample_valid = 0U;
    while ((1U & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb)))) {
        co_await vlSelf->__VtrigSched_h904cec7c__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] fpga_template_top_tb.btn_s1_resetb)", 
                                                           "fpga_template_top_tb.sv", 
                                                           203);
    }
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       204);
    while (1U) {
        co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge fpga_template_top_tb.clk)", 
                                                           "fpga_template_top_tb.sv", 
                                                           207);
        co_await vlSelf->__VdlySched.delay(0x3e8ULL, 
                                           nullptr, 
                                           "fpga_template_top_tb.sv", 
                                           208);
        if (((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__sample_valid) 
             & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__prev_sample_valid)))) {
            vlSelf->fpga_template_top_tb__DOT__handshake_count 
                = ((IData)(1U) + vlSelf->fpga_template_top_tb__DOT__handshake_count);
            vlSelf->fpga_template_top_tb__DOT__monitor_handshake = 1U;
            vlSelf->fpga_template_top_tb__DOT__ready_low_cycles = 0U;
            if (VL_UNLIKELY(VL_GTES_III(32, 5U, vlSelf->fpga_template_top_tb__DOT__handshake_count))) {
                VL_WRITEF("[%0t] VU Handshake %0d: Sample accepted\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,32,vlSelf->fpga_template_top_tb__DOT__handshake_count);
            }
        }
        vlSelf->fpga_template_top_tb__DOT__prev_sample_valid 
            = vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__sample_valid;
        if (vlSelf->fpga_template_top_tb__DOT__monitor_handshake) {
            if (((0U == vlSelf->fpga_template_top_tb__DOT__ready_low_cycles) 
                 & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__prev_sample_valid)))) {
                if (VL_UNLIKELY(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__ram_ready_q)) {
                    VL_WRITEF("[%0t] %%Error: fpga_template_top_tb.sv:229: Assertion failed in %Nfpga_template_top_tb: [%0t] TIMING ERROR: Ready should be LOW in cycle 1 after handshake!\n",
                              64,VL_TIME_UNITED_Q(1000),
                              -9,vlSymsp->name(),64,
                              VL_TIME_UNITED_Q(1000),
                              -9);
                    VL_STOP_MT("fpga_template_top_tb.sv", 229, "");
                    vlSelf->fpga_template_top_tb__DOT__monitor_handshake = 0U;
                } else {
                    vlSelf->fpga_template_top_tb__DOT__ready_low_cycles = 1U;
                }
            } else if ((1U == vlSelf->fpga_template_top_tb__DOT__ready_low_cycles)) {
                if (VL_UNLIKELY(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__ram_ready_q)) {
                    VL_WRITEF("[%0t] %%Error: fpga_template_top_tb.sv:237: Assertion failed in %Nfpga_template_top_tb: [%0t] TIMING ERROR: Ready should be LOW in cycle 2 after handshake!\n",
                              64,VL_TIME_UNITED_Q(1000),
                              -9,vlSymsp->name(),64,
                              VL_TIME_UNITED_Q(1000),
                              -9);
                    VL_STOP_MT("fpga_template_top_tb.sv", 237, "");
                    vlSelf->fpga_template_top_tb__DOT__monitor_handshake = 0U;
                } else {
                    vlSelf->fpga_template_top_tb__DOT__ready_low_cycles = 2U;
                }
            } else if ((2U == vlSelf->fpga_template_top_tb__DOT__ready_low_cycles)) {
                if (VL_LIKELY(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__ram_ready_q)) {
                    if (VL_UNLIKELY(VL_GTES_III(32, 5U, vlSelf->fpga_template_top_tb__DOT__handshake_count))) {
                        VL_WRITEF("[%0t]    PASS: Correct 2-cycle handshake delay (ready LOW for 2 cycles)\n",
                                  64,VL_TIME_UNITED_Q(1000),
                                  -9);
                    }
                } else {
                    VL_WRITEF("[%0t] %%Error: fpga_template_top_tb.sv:247: Assertion failed in %Nfpga_template_top_tb: [%0t] TIMING ERROR: Ready should be HIGH in cycle 3 after handshake!\n",
                              64,VL_TIME_UNITED_Q(1000),
                              -9,vlSymsp->name(),64,
                              VL_TIME_UNITED_Q(1000),
                              -9);
                    VL_STOP_MT("fpga_template_top_tb.sv", 247, "");
                }
                vlSelf->fpga_template_top_tb__DOT__monitor_handshake = 0U;
            }
        }
    }
}

VL_INLINE_OPT VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__7(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__7\n"); );
    // Body
    while ((1U & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb)))) {
        co_await vlSelf->__VtrigSched_h904cec7c__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] fpga_template_top_tb.btn_s1_resetb)", 
                                                           "fpga_template_top_tb.sv", 
                                                           273);
    }
    while (1U) {
        co_await vlSelf->__VtrigSched_h10a6e2e3__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge fpga_template_top_tb.buffer_full)", 
                                                           "fpga_template_top_tb.sv", 
                                                           276);
        VL_WRITEF("[%0t] %%Error: fpga_template_top_tb.sv:277: Assertion failed in %Nfpga_template_top_tb: [%0t] BUFFER OVERFLOW DETECTED!\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  64,VL_TIME_UNITED_Q(1000),-9);
        VL_STOP_MT("fpga_template_top_tb.sv", 277, "");
    }
}

VL_INLINE_OPT VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__8(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__8\n"); );
    // Init
    IData/*31:0*/ fpga_template_top_tb__DOT____Vrepeat2;
    fpga_template_top_tb__DOT____Vrepeat2 = 0;
    // Body
    VL_WRITEF("=================================================================\nFPGA I2S Audio Capture System Testbench\n=================================================================\nClock: 27.000 MHz\nTest samples: 80 (5.0 buffers)\n=================================================================\n");
    while ((1U & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb)))) {
        co_await vlSelf->__VtrigSched_h904cec7c__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] fpga_template_top_tb.btn_s1_resetb)", 
                                                           "fpga_template_top_tb.sv", 
                                                           294);
    }
    VL_WRITEF("[%0t] Test started\n",64,VL_TIME_UNITED_Q(1000),
              -9);
    while (VL_GTS_III(32, 0x50U, vlSelf->fpga_template_top_tb__DOT__sample_count)) {
        co_await vlSelf->__VtrigSched_h43f1a8d3__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] (32'sh50 <= fpga_template_top_tb.sample_count))", 
                                                           "fpga_template_top_tb.sv", 
                                                           298);
    }
    fpga_template_top_tb__DOT____Vrepeat2 = 0x3e8U;
    while (VL_LTS_III(32, 0U, fpga_template_top_tb__DOT____Vrepeat2)) {
        co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge fpga_template_top_tb.clk)", 
                                                           "fpga_template_top_tb.sv", 
                                                           301);
        fpga_template_top_tb__DOT____Vrepeat2 = (fpga_template_top_tb__DOT____Vrepeat2 
                                                 - (IData)(1U));
    }
    VL_WRITEF("\n=================================================================\nTest Complete\n=================================================================\nSamples captured:      %0d\nBuffer swaps:          %0d\nVU handshakes:         %0d\nExpected buffer swaps: 5\n=================================================================\n",
              32,vlSelf->fpga_template_top_tb__DOT__sample_count,
              32,vlSelf->fpga_template_top_tb__DOT__buffer_swap_count,
              32,vlSelf->fpga_template_top_tb__DOT__handshake_count);
    if (VL_UNLIKELY(VL_GTS_III(32, 1U, vlSelf->fpga_template_top_tb__DOT__buffer_swap_count))) {
        VL_WRITEF("[%0t] %%Error: fpga_template_top_tb.sv:316: Assertion failed in %Nfpga_template_top_tb: FAIL: No buffer swaps occurred!\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("fpga_template_top_tb.sv", 316, "");
    } else if (VL_UNLIKELY(VL_LTS_III(32, vlSelf->fpga_template_top_tb__DOT__handshake_count, vlSelf->fpga_template_top_tb__DOT__buffer_swap_count))) {
        VL_WRITEF("[%0t] %%Error: fpga_template_top_tb.sv:318: Assertion failed in %Nfpga_template_top_tb: FAIL: VU meter did not consume data!\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("fpga_template_top_tb.sv", 318, "");
    } else {
        VL_WRITEF("PASS: All major tests passed\n");
    }
    VL_WRITEF("\n");
    VL_FINISH_MT("fpga_template_top_tb.sv", 324, "");
}

VL_INLINE_OPT VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__9(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__9\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0xba43b7400ULL, 
                                       nullptr, "fpga_template_top_tb.sv", 
                                       329);
    VL_WRITEF("[%0t] %%Error: fpga_template_top_tb.sv:330: Assertion failed in %Nfpga_template_top_tb: TIMEOUT: Simulation ran too long!\n",
              64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
    VL_STOP_MT("fpga_template_top_tb.sv", 330, "");
    VL_FINISH_MT("fpga_template_top_tb.sv", 331, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpga_template_top_tb___024root___dump_triggers__act(Vfpga_template_top_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vfpga_template_top_tb___024root___eval_triggers__act(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_triggers__act\n"); );
    // Body
    CData/*0:0*/ __Vtrigcurrexpr_he4466ec5__0;
    __Vtrigcurrexpr_he4466ec5__0 = 0;
    __Vtrigcurrexpr_he4466ec5__0 = VL_LTES_III(32, 0x50U, vlSelf->fpga_template_top_tb__DOT__sample_count);
    vlSelf->__VactTriggered.set(0U, (((~ (IData)(vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb)) 
                                      & (IData)(vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__btn_s1_resetb__0)) 
                                     | ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q) 
                                        & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q__0)))));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->fpga_template_top_tb__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__clk__0))));
    vlSelf->__VactTriggered.set(2U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__VactTriggered.set(3U, ((IData)(vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__btn_s1_resetb__0)));
    vlSelf->__VactTriggered.set(4U, ((~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q)) 
                                     & (IData)(vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q__0)));
    vlSelf->__VactTriggered.set(5U, ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__sampler_to_ram_write_request_w) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__dut__DOT__sampler_to_ram_write_request_w__0))));
    vlSelf->__VactTriggered.set(6U, ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w__0))));
    vlSelf->__VactTriggered.set(7U, ((IData)(vlSelf->fpga_template_top_tb__DOT__buffer_full) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__buffer_full__0))));
    vlSelf->__VactTriggered.set(8U, ((IData)(__Vtrigcurrexpr_he4466ec5__0) 
                                     != (IData)(vlSelf->__Vtrigprevexpr_he4466ec5__0)));
    vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__btn_s1_resetb__0 
        = vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb;
    vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q__0 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q;
    vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__clk__0 
        = vlSelf->fpga_template_top_tb__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q__0 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q;
    vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__dut__DOT__sampler_to_ram_write_request_w__0 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__sampler_to_ram_write_request_w;
    vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w__0 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w;
    vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__buffer_full__0 
        = vlSelf->fpga_template_top_tb__DOT__buffer_full;
    vlSelf->__Vtrigprevexpr_he4466ec5__0 = __Vtrigcurrexpr_he4466ec5__0;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.set(3U, 1U);
        vlSelf->__VactTriggered.set(8U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vfpga_template_top_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}
