// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vi2s_clock_gen_tb_verilator.h for the primary calling header

#include "Vi2s_clock_gen_tb_verilator__pch.h"
#include "Vi2s_clock_gen_tb_verilator__Syms.h"
#include "Vi2s_clock_gen_tb_verilator___024root.h"

VL_INLINE_OPT VlCoroutine Vi2s_clock_gen_tb_verilator___024root___eval_initial__TOP__Vtiming__1(Vi2s_clock_gen_tb_verilator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Init
    CData/*0:0*/ i2s_clock_gen_tb_verilator__DOT__test_passed;
    i2s_clock_gen_tb_verilator__DOT__test_passed = 0;
    IData/*31:0*/ i2s_clock_gen_tb_verilator__DOT____Vrepeat1;
    i2s_clock_gen_tb_verilator__DOT____Vrepeat1 = 0;
    // Body
    i2s_clock_gen_tb_verilator__DOT__test_passed = 1U;
    vlSelf->i2s_clock_gen_tb_verilator__DOT__errors = 0U;
    VL_WRITEF("=================================================================\nI2S Clock Generator Testbench\n=================================================================\nConfiguration:\n  System Clock:      27000000 Hz (37.037 ns period)\n  SCK Divider:       8\n  SCKs per Frame:    64\n  Expected SCK:      3.375 MHz\n  Expected WS:       52.734 kHz\n=================================================================\n\n");
    vlSelf->i2s_clock_gen_tb_verilator__DOT__rst_ni = 0U;
    co_await vlSelf->__VtrigSched_hb7b23e70__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_clock_gen_tb_verilator.clk_i)", 
                                                       "sim/i2s_clock_gen_tb_verilator.sv", 
                                                       214);
    co_await vlSelf->__VtrigSched_hb7b23e70__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_clock_gen_tb_verilator.clk_i)", 
                                                       "sim/i2s_clock_gen_tb_verilator.sv", 
                                                       214);
    co_await vlSelf->__VtrigSched_hb7b23e70__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_clock_gen_tb_verilator.clk_i)", 
                                                       "sim/i2s_clock_gen_tb_verilator.sv", 
                                                       214);
    co_await vlSelf->__VtrigSched_hb7b23e70__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_clock_gen_tb_verilator.clk_i)", 
                                                       "sim/i2s_clock_gen_tb_verilator.sv", 
                                                       214);
    co_await vlSelf->__VtrigSched_hb7b23e70__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_clock_gen_tb_verilator.clk_i)", 
                                                       "sim/i2s_clock_gen_tb_verilator.sv", 
                                                       214);
    co_await vlSelf->__VtrigSched_hb7b23e70__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_clock_gen_tb_verilator.clk_i)", 
                                                       "sim/i2s_clock_gen_tb_verilator.sv", 
                                                       214);
    co_await vlSelf->__VtrigSched_hb7b23e70__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_clock_gen_tb_verilator.clk_i)", 
                                                       "sim/i2s_clock_gen_tb_verilator.sv", 
                                                       214);
    co_await vlSelf->__VtrigSched_hb7b23e70__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_clock_gen_tb_verilator.clk_i)", 
                                                       "sim/i2s_clock_gen_tb_verilator.sv", 
                                                       214);
    co_await vlSelf->__VtrigSched_hb7b23e70__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_clock_gen_tb_verilator.clk_i)", 
                                                       "sim/i2s_clock_gen_tb_verilator.sv", 
                                                       214);
    co_await vlSelf->__VtrigSched_hb7b23e70__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge i2s_clock_gen_tb_verilator.clk_i)", 
                                                       "sim/i2s_clock_gen_tb_verilator.sv", 
                                                       214);
    vlSelf->i2s_clock_gen_tb_verilator__DOT__rst_ni = 1U;
    VL_WRITEF("[%0t] Reset released\n",64,VL_TIME_UNITED_Q(1000),
              -9);
    while ((8U > vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_toggle_count)) {
        co_await vlSelf->__VtrigSched_h595187a8__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] (32'h8 <= i2s_clock_gen_tb_verilator.ws_toggle_count))", 
                                                           "sim/i2s_clock_gen_tb_verilator.sv", 
                                                           219);
    }
    i2s_clock_gen_tb_verilator__DOT____Vrepeat1 = 0x64U;
    while (VL_LTS_III(32, 0U, i2s_clock_gen_tb_verilator__DOT____Vrepeat1)) {
        co_await vlSelf->__VtrigSched_hb7b23e70__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge i2s_clock_gen_tb_verilator.clk_i)", 
                                                           "sim/i2s_clock_gen_tb_verilator.sv", 
                                                           220);
        i2s_clock_gen_tb_verilator__DOT____Vrepeat1 
            = (i2s_clock_gen_tb_verilator__DOT____Vrepeat1 
               - (IData)(1U));
    }
    VL_WRITEF("\n=================================================================\nMeasurement Results\n=================================================================\n");
    if (VL_UNLIKELY((0U < vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_period_count))) {
        vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk3__DOT__sck_period_avg 
            = (VL_ITOR_D_I(32, vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_period_sum) 
               / VL_ITOR_D_I(32, vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_period_count));
        VL_WRITEF("\nSCK Half-Period (sysclk cycles):\n  Expected:   4\n  Measured:   %.2f (avg)\n  High Time:  %0# cycles\n  Low Time:   %0# cycles\n  Full Period: %0# cycles\n",
                  64,vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk3__DOT__sck_period_avg,
                  32,vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_high_time,
                  32,vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_low_time,
                  32,(vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_high_time 
                      + vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_low_time));
        if (VL_UNLIKELY((8U != (vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_high_time 
                                + vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_low_time)))) {
            VL_WRITEF("[%0t] %%Error: i2s_clock_gen_tb_verilator.sv:240: Assertion failed in %Ni2s_clock_gen_tb_verilator.unnamedblk3: [FAIL] SCK full period is %0#, expected 8\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name(),32,(vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_high_time 
                                          + vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_low_time));
            VL_STOP_MT("sim/i2s_clock_gen_tb_verilator.sv", 240, "");
            i2s_clock_gen_tb_verilator__DOT__test_passed = 0U;
            vlSelf->i2s_clock_gen_tb_verilator__DOT__errors 
                = ((IData)(1U) + vlSelf->i2s_clock_gen_tb_verilator__DOT__errors);
        } else {
            VL_WRITEF("  [PASS] SCK period matches expected value\n");
        }
        vlSelf->i2s_clock_gen_tb_verilator__DOT__duty_diff_val 
            = ((vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_high_time 
                > vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_low_time)
                ? (vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_high_time 
                   - vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_low_time)
                : (vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_low_time 
                   - vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_high_time));
        if (VL_UNLIKELY((1U < vlSelf->i2s_clock_gen_tb_verilator__DOT__duty_diff_val))) {
            VL_WRITEF("[%0t] %%Error: i2s_clock_gen_tb_verilator.sv:252: Assertion failed in %Ni2s_clock_gen_tb_verilator.unnamedblk3: [FAIL] SCK duty cycle not balanced (diff = %0# cycles)\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name(),32,vlSelf->i2s_clock_gen_tb_verilator__DOT__duty_diff_val);
            VL_STOP_MT("sim/i2s_clock_gen_tb_verilator.sv", 252, "");
            i2s_clock_gen_tb_verilator__DOT__test_passed = 0U;
            vlSelf->i2s_clock_gen_tb_verilator__DOT__errors 
                = ((IData)(1U) + vlSelf->i2s_clock_gen_tb_verilator__DOT__errors);
        } else {
            VL_WRITEF("  [PASS] SCK duty cycle is balanced (diff = %0# cycle)\n",
                      32,vlSelf->i2s_clock_gen_tb_verilator__DOT__duty_diff_val);
        }
    }
    if (VL_UNLIKELY((0U < vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_period_count))) {
        vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk4__DOT__ws_period_avg 
            = (VL_ITOR_D_I(32, vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_period_sum) 
               / VL_ITOR_D_I(32, vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_period_count));
        VL_WRITEF("\nWS Half-Period (sysclk cycles):\n  Expected:   512\n  Measured:   %.2f (avg)\n",
                  64,vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk4__DOT__ws_period_avg);
        if (VL_UNLIKELY(((vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk4__DOT__ws_period_avg 
                          < 511.0) | (vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk4__DOT__ws_period_avg 
                                      > 513.0)))) {
            VL_WRITEF("[%0t] %%Error: i2s_clock_gen_tb_verilator.sv:272: Assertion failed in %Ni2s_clock_gen_tb_verilator.unnamedblk4: [FAIL] WS period is %.2f, expected 512\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name(),64,vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk4__DOT__ws_period_avg);
            VL_STOP_MT("sim/i2s_clock_gen_tb_verilator.sv", 272, "");
            i2s_clock_gen_tb_verilator__DOT__test_passed = 0U;
            vlSelf->i2s_clock_gen_tb_verilator__DOT__errors 
                = ((IData)(1U) + vlSelf->i2s_clock_gen_tb_verilator__DOT__errors);
        } else {
            VL_WRITEF("  [PASS] WS period matches expected value\n");
        }
        vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_to_sck_ratio_val 
            = (vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk4__DOT__ws_period_avg 
               / VL_ITOR_D_I(32, (vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_high_time 
                                  + vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_low_time)));
        VL_WRITEF("\nWS to SCK Relationship:\n  Expected SCKs per half-frame: 64\n  Measured ratio: %.2f\n",
                  64,vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_to_sck_ratio_val);
        if (VL_UNLIKELY(((vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_to_sck_ratio_val 
                          < 6.35000000000000000e+01) 
                         | (vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_to_sck_ratio_val 
                            > 6.45000000000000000e+01)))) {
            VL_WRITEF("[%0t] %%Error: i2s_clock_gen_tb_verilator.sv:286: Assertion failed in %Ni2s_clock_gen_tb_verilator.unnamedblk4: [FAIL] WS to SCK ratio incorrect\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("sim/i2s_clock_gen_tb_verilator.sv", 286, "");
            i2s_clock_gen_tb_verilator__DOT__test_passed = 0U;
            vlSelf->i2s_clock_gen_tb_verilator__DOT__errors 
                = ((IData)(1U) + vlSelf->i2s_clock_gen_tb_verilator__DOT__errors);
        } else {
            VL_WRITEF("  [PASS] WS to SCK ratio correct\n");
        }
    }
    VL_WRITEF("\nWS Transition Timing:\n  WS changes on SCK high: %0d\n",
              32,vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_change_on_sck_high_count);
    if (VL_UNLIKELY(VL_LTS_III(32, 0U, vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_change_on_sck_high_count))) {
        VL_WRITEF("[%0t] %%Error: i2s_clock_gen_tb_verilator.sv:298: Assertion failed in %Ni2s_clock_gen_tb_verilator: [FAIL] WS changed when SCK was high\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("sim/i2s_clock_gen_tb_verilator.sv", 298, "");
        i2s_clock_gen_tb_verilator__DOT__test_passed = 0U;
        vlSelf->i2s_clock_gen_tb_verilator__DOT__errors 
            = (vlSelf->i2s_clock_gen_tb_verilator__DOT__errors 
               + vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_change_on_sck_high_count);
    } else {
        VL_WRITEF("  [PASS] All WS transitions occurred on SCK falling edge\n");
    }
    VL_WRITEF("\nFrame Start Pulses:\n  Total pulses: %0#\n  Expected:     ~4\n",
              32,vlSelf->i2s_clock_gen_tb_verilator__DOT__frame_start_count);
    if (VL_UNLIKELY(((3U > vlSelf->i2s_clock_gen_tb_verilator__DOT__frame_start_count) 
                     | (5U < vlSelf->i2s_clock_gen_tb_verilator__DOT__frame_start_count)))) {
        VL_WRITEF("[%0t] %%Error: i2s_clock_gen_tb_verilator.sv:310: Assertion failed in %Ni2s_clock_gen_tb_verilator: [FAIL] Frame start pulse count unexpected\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("sim/i2s_clock_gen_tb_verilator.sv", 310, "");
        i2s_clock_gen_tb_verilator__DOT__test_passed = 0U;
        vlSelf->i2s_clock_gen_tb_verilator__DOT__errors 
            = ((IData)(1U) + vlSelf->i2s_clock_gen_tb_verilator__DOT__errors);
    } else {
        VL_WRITEF("  [PASS] Frame start pulse count correct\n");
    }
    VL_WRITEF("\n=================================================================\nTest Summary\n=================================================================\n");
    if (((IData)(i2s_clock_gen_tb_verilator__DOT__test_passed) 
         & (0U == vlSelf->i2s_clock_gen_tb_verilator__DOT__errors))) {
        VL_WRITEF("  \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227    \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227  \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227 \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\n  \342\225\232\342\225\220\342\225\220\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\235\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\225\232\342\225\220\342\225\220\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\235    \342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\n");
        VL_WRITEF("     \342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227  \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227   \342\226\210\342\226\210\342\225\221       \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\224\342\225\235\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\n     \342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\235  \342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\225\221       \342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\220\342\225\235 \342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\226\210\342\226\210\342\225\221\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\226\210\342\226\210\342\225\221\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\226\210\342\226\210\342\225\221\n");
        VL_WRITEF("     \342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\225\221       \342\226\210\342\226\210\342\225\221     \342\226\210\342\226\210\342\225\221  \342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\221\n     \342\225\232\342\225\220\342\225\235   \342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235   \342\225\232\342\225\220\342\225\235       \342\225\232\342\225\220\342\225\235     \342\225\232\342\225\220\342\225\235  \342\225\232\342\225\220\342\225\235\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\n\n  All tests passed successfully!\n  Errors: 0\n");
    } else {
        VL_WRITEF("  \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227    \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227 \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227 \342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\225\227     \n  \342\225\232\342\225\220\342\225\220\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\235\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\225\232\342\225\220\342\225\220\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\235    \342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\225\221     \n");
        VL_WRITEF("     \342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227  \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227   \342\226\210\342\226\210\342\225\221       \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227  \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\225\221     \n     \342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\235  \342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\225\221       \342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\225\235  \342\226\210\342\226\210\342\225\224\342\225\220\342\225\220\342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\225\221     \n     \342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\221   \342\226\210\342\226\210\342\225\221       \342\226\210\342\226\210\342\225\221     \342\226\210\342\226\210\342\225\221  \342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\225\221\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\226\210\342\225\227\n");
        VL_WRITEF("     \342\225\232\342\225\220\342\225\235   \342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235   \342\225\232\342\225\220\342\225\235       \342\225\232\342\225\220\342\225\235     \342\225\232\342\225\220\342\225\235  \342\225\232\342\225\220\342\225\235\342\225\232\342\225\220\342\225\235\342\225\232\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\220\342\225\235\n\n  Test failed with %0d errors\n",
                  32,vlSelf->i2s_clock_gen_tb_verilator__DOT__errors);
    }
    VL_WRITEF("=================================================================\n\n");
    VL_FINISH_MT("sim/i2s_clock_gen_tb_verilator.sv", 341, "");
}

VL_INLINE_OPT VlCoroutine Vi2s_clock_gen_tb_verilator___024root___eval_initial__TOP__Vtiming__2(Vi2s_clock_gen_tb_verilator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Init
    IData/*31:0*/ i2s_clock_gen_tb_verilator__DOT____Vrepeat2;
    i2s_clock_gen_tb_verilator__DOT____Vrepeat2 = 0;
    // Body
    i2s_clock_gen_tb_verilator__DOT____Vrepeat2 = 0x3000U;
    while (VL_LTS_III(32, 0U, i2s_clock_gen_tb_verilator__DOT____Vrepeat2)) {
        co_await vlSelf->__VtrigSched_hb7b23e70__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge i2s_clock_gen_tb_verilator.clk_i)", 
                                                           "sim/i2s_clock_gen_tb_verilator.sv", 
                                                           346);
        i2s_clock_gen_tb_verilator__DOT____Vrepeat2 
            = (i2s_clock_gen_tb_verilator__DOT____Vrepeat2 
               - (IData)(1U));
    }
    VL_WRITEF("[%0t] %%Error: i2s_clock_gen_tb_verilator.sv:347: Assertion failed in %Ni2s_clock_gen_tb_verilator: [TIMEOUT] Simulation exceeded maximum cycles\n",
              64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
    VL_STOP_MT("sim/i2s_clock_gen_tb_verilator.sv", 347, "");
    VL_WRITEF("\n=================================================================\nTEST FAIL - TIMEOUT\n=================================================================\n\n");
    VL_FINISH_MT("sim/i2s_clock_gen_tb_verilator.sv", 351, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vi2s_clock_gen_tb_verilator___024root___dump_triggers__act(Vi2s_clock_gen_tb_verilator___024root* vlSelf);
#endif  // VL_DEBUG

void Vi2s_clock_gen_tb_verilator___024root___eval_triggers__act(Vi2s_clock_gen_tb_verilator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root___eval_triggers__act\n"); );
    // Body
    CData/*0:0*/ __Vtrigcurrexpr_hcd664f0a__0;
    __Vtrigcurrexpr_hcd664f0a__0 = 0;
    __Vtrigcurrexpr_hcd664f0a__0 = (8U <= vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_toggle_count);
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->i2s_clock_gen_tb_verilator__DOT__clk_i) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__i2s_clock_gen_tb_verilator__DOT__clk_i__0))));
    vlSelf->__VactTriggered.set(1U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__VactTriggered.set(2U, ((IData)(__Vtrigcurrexpr_hcd664f0a__0) 
                                     != (IData)(vlSelf->__Vtrigprevexpr_hcd664f0a__0)));
    vlSelf->__Vtrigprevexpr___TOP__i2s_clock_gen_tb_verilator__DOT__clk_i__0 
        = vlSelf->i2s_clock_gen_tb_verilator__DOT__clk_i;
    vlSelf->__Vtrigprevexpr_hcd664f0a__0 = __Vtrigcurrexpr_hcd664f0a__0;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.set(2U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vi2s_clock_gen_tb_verilator___024root___dump_triggers__act(vlSelf);
    }
#endif
}

extern const VlUnpacked<CData/*2:0*/, 32> Vi2s_clock_gen_tb_verilator__ConstPool__TABLE_hb31b5e30_0;
extern const VlUnpacked<CData/*1:0*/, 32> Vi2s_clock_gen_tb_verilator__ConstPool__TABLE_h11502f1d_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vi2s_clock_gen_tb_verilator__ConstPool__TABLE_h56c82868_0;

VL_INLINE_OPT void Vi2s_clock_gen_tb_verilator___024root___nba_sequent__TOP__0(Vi2s_clock_gen_tb_verilator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vi2s_clock_gen_tb_verilator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vi2s_clock_gen_tb_verilator___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*0:0*/ __Vdly__i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_q;
    __Vdly__i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_q = 0;
    CData/*0:0*/ __Vdly__i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_q;
    __Vdly__i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_q = 0;
    CData/*5:0*/ __Vdly__i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_ctr_q;
    __Vdly__i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_ctr_q = 0;
    // Body
    __Vdly__i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_q 
        = vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_q;
    __Vdly__i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_ctr_q 
        = vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_ctr_q;
    __Vdly__i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_q 
        = vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_q;
    if (vlSelf->i2s_clock_gen_tb_verilator__DOT__rst_ni) {
        vlSelf->i2s_clock_gen_tb_verilator__DOT__cycle_count 
            = ((IData)(1U) + vlSelf->i2s_clock_gen_tb_verilator__DOT__cycle_count);
        vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_prev 
            = vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_q;
        if ((((IData)(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_q) 
              != (IData)(vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_prev)) 
             & (0xaU < vlSelf->i2s_clock_gen_tb_verilator__DOT__cycle_count))) {
            vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk1__DOT__period 
                = (vlSelf->i2s_clock_gen_tb_verilator__DOT__cycle_count 
                   - vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_last_toggle_cycle);
            vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_period_count 
                = ((IData)(1U) + vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_period_count);
            vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_toggle_count 
                = ((IData)(1U) + vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_toggle_count);
            vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_period_sum 
                = (vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_period_sum 
                   + vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk1__DOT__period);
            vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_last_toggle_cycle 
                = vlSelf->i2s_clock_gen_tb_verilator__DOT__cycle_count;
            if (vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_q) {
                vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_low_time 
                    = vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk1__DOT__period;
            } else {
                vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_high_time 
                    = vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk1__DOT__period;
            }
        }
    } else {
        vlSelf->i2s_clock_gen_tb_verilator__DOT__cycle_count = 0U;
        vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_prev = 0U;
        vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_toggle_count = 0U;
        vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_last_toggle_cycle = 0U;
        vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_high_time = 0U;
        vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_low_time = 0U;
        vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_period_sum = 0U;
        vlSelf->i2s_clock_gen_tb_verilator__DOT__sck_period_count = 0U;
    }
    if (vlSelf->i2s_clock_gen_tb_verilator__DOT__rst_ni) {
        vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_prev 
            = vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_q;
        if ((((IData)(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_q) 
              != (IData)(vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_prev)) 
             & (0xaU < vlSelf->i2s_clock_gen_tb_verilator__DOT__cycle_count))) {
            vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk2__DOT__period 
                = (vlSelf->i2s_clock_gen_tb_verilator__DOT__cycle_count 
                   - vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_last_toggle_cycle);
            if (VL_UNLIKELY(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_q)) {
                VL_WRITEF("[%0t] %%Error: i2s_clock_gen_tb_verilator.sv:160: Assertion failed in %Ni2s_clock_gen_tb_verilator.unnamedblk2: [ERROR] WS changed when SCK was high at cycle %0#\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->i2s_clock_gen_tb_verilator__DOT__cycle_count);
                vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_change_on_sck_high_count 
                    = ((IData)(1U) + vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_change_on_sck_high_count);
                VL_STOP_MT("sim/i2s_clock_gen_tb_verilator.sv", 160, "");
            }
            vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_period_sum 
                = (vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_period_sum 
                   + vlSelf->i2s_clock_gen_tb_verilator__DOT__unnamedblk2__DOT__period);
            vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_period_count 
                = ((IData)(1U) + vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_period_count);
            vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_toggle_count 
                = ((IData)(1U) + vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_toggle_count);
            vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_last_toggle_cycle 
                = vlSelf->i2s_clock_gen_tb_verilator__DOT__cycle_count;
        }
    } else {
        vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_prev = 0U;
        vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_toggle_count = 0U;
        vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_last_toggle_cycle = 0U;
        vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_period_sum = 0U;
        vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_period_count = 0U;
        vlSelf->i2s_clock_gen_tb_verilator__DOT__ws_change_on_sck_high_count = 0U;
    }
    if (vlSelf->i2s_clock_gen_tb_verilator__DOT__rst_ni) {
        if (vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__frame_start_q) {
            if (VL_UNLIKELY(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_q)) {
                VL_WRITEF("[%0t] %%Error: i2s_clock_gen_tb_verilator.sv:177: Assertion failed in %Ni2s_clock_gen_tb_verilator: [ERROR] Frame start when not at left channel at cycle %0#\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name(),32,vlSelf->i2s_clock_gen_tb_verilator__DOT__cycle_count);
                vlSelf->i2s_clock_gen_tb_verilator__DOT__errors 
                    = ((IData)(1U) + vlSelf->i2s_clock_gen_tb_verilator__DOT__errors);
                VL_STOP_MT("sim/i2s_clock_gen_tb_verilator.sv", 177, "");
            }
            vlSelf->i2s_clock_gen_tb_verilator__DOT__frame_start_count 
                = ((IData)(1U) + vlSelf->i2s_clock_gen_tb_verilator__DOT__frame_start_count);
        }
    } else {
        vlSelf->i2s_clock_gen_tb_verilator__DOT__frame_start_count = 0U;
    }
    if (vlSelf->i2s_clock_gen_tb_verilator__DOT__rst_ni) {
        vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__frame_start_q = 0U;
        if (((~ (IData)(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_q)) 
             & (IData)(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_prev_q))) {
            if ((0x3fU == (IData)(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_ctr_q))) {
                __Vdly__i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_q 
                    = (1U & (~ (IData)(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_q)));
                __Vdly__i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_ctr_q = 0U;
                if (vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_q) {
                    vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__frame_start_q = 1U;
                }
            } else {
                __Vdly__i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_ctr_q 
                    = (0x3fU & ((IData)(1U) + (IData)(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_ctr_q)));
            }
        }
    } else {
        __Vdly__i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_ctr_q = 0U;
        __Vdly__i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_q = 0U;
        vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__frame_start_q = 0U;
    }
    __Vtableidx1 = (((IData)(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_ctr_q) 
                     << 2U) | (((IData)(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_q) 
                                << 1U) | (IData)(vlSelf->i2s_clock_gen_tb_verilator__DOT__rst_ni)));
    vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_ctr_q 
        = Vi2s_clock_gen_tb_verilator__ConstPool__TABLE_hb31b5e30_0
        [__Vtableidx1];
    if ((2U & Vi2s_clock_gen_tb_verilator__ConstPool__TABLE_h11502f1d_0
         [__Vtableidx1])) {
        __Vdly__i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_q 
            = Vi2s_clock_gen_tb_verilator__ConstPool__TABLE_h56c82868_0
            [__Vtableidx1];
    }
    vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_ctr_q 
        = __Vdly__i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_ctr_q;
    vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_q 
        = __Vdly__i2s_clock_gen_tb_verilator__DOT__dut__DOT__ws_q;
    vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_prev_q 
        = ((IData)(vlSelf->i2s_clock_gen_tb_verilator__DOT__rst_ni) 
           && (IData)(vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_q));
    vlSelf->i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_q 
        = __Vdly__i2s_clock_gen_tb_verilator__DOT__dut__DOT__sck_q;
}
