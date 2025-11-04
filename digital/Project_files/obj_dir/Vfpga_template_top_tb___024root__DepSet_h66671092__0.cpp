// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpga_template_top_tb.h for the primary calling header

#include "Vfpga_template_top_tb__pch.h"
#include "Vfpga_template_top_tb___024root.h"

VL_ATTR_COLD void Vfpga_template_top_tb___024root___eval_initial__TOP(Vfpga_template_top_tb___024root* vlSelf);
VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__0(Vfpga_template_top_tb___024root* vlSelf);
VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__1(Vfpga_template_top_tb___024root* vlSelf);
VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__2(Vfpga_template_top_tb___024root* vlSelf);
VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__3(Vfpga_template_top_tb___024root* vlSelf);
VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__4(Vfpga_template_top_tb___024root* vlSelf);
VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__5(Vfpga_template_top_tb___024root* vlSelf);
VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__6(Vfpga_template_top_tb___024root* vlSelf);
VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__7(Vfpga_template_top_tb___024root* vlSelf);
VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__8(Vfpga_template_top_tb___024root* vlSelf);
VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__9(Vfpga_template_top_tb___024root* vlSelf);

void Vfpga_template_top_tb___024root___eval_initial(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_initial\n"); );
    // Body
    Vfpga_template_top_tb___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__3(vlSelf);
    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__4(vlSelf);
    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__5(vlSelf);
    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__6(vlSelf);
    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__7(vlSelf);
    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__8(vlSelf);
    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__9(vlSelf);
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
    vlSelf->__Vtrigprevexpr_he4466ec5__0 = VL_LTES_III(32, 0x50U, vlSelf->fpga_template_top_tb__DOT__sample_count);
}

VL_INLINE_OPT VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__0(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->fpga_template_top_tb__DOT__clk = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x4857ULL, 
                                           nullptr, 
                                           "fpga_template_top_tb.sv", 
                                           70);
        vlSelf->fpga_template_top_tb__DOT__clk = (1U 
                                                  & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__clk)));
    }
}

VL_INLINE_OPT VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__1(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb = 0U;
    vlSelf->fpga_template_top_tb__DOT__btn_s2 = 0U;
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       79);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       79);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       79);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       79);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       79);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       79);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       79);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       79);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       79);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       79);
    vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb = 1U;
    VL_WRITEF("[%0t] Reset released\n",64,VL_TIME_UNITED_Q(1000),
              -9);
}

VL_INLINE_OPT VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__2(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Body
    vlSelf->fpga_template_top_tb__DOT__left_sample = 0U;
    vlSelf->fpga_template_top_tb__DOT__right_sample = 0U;
    while ((1U & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb)))) {
        co_await vlSelf->__VtrigSched_h904cec7c__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] fpga_template_top_tb.btn_s1_resetb)", 
                                                           "fpga_template_top_tb.sv", 
                                                           101);
    }
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       102);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       102);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       102);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       102);
    co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge fpga_template_top_tb.clk)", 
                                                       "fpga_template_top_tb.sv", 
                                                       102);
    while (1U) {
        co_await vlSelf->__VtrigSched_ha0e3b59f__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(negedge fpga_template_top_tb.dut.u_i2s_clock.ws_q)", 
                                                           "fpga_template_top_tb.sv", 
                                                           105);
        vlSelf->fpga_template_top_tb__DOT__left_sample 
            = (VL_GTS_III(32, 0x32U, vlSelf->fpga_template_top_tb__DOT__sample_count)
                ? 0x1000U : (VL_GTS_III(32, 0x64U, vlSelf->fpga_template_top_tb__DOT__sample_count)
                              ? 0x10000U : (VL_GTS_III(32, 0x96U, vlSelf->fpga_template_top_tb__DOT__sample_count)
                                             ? 0x50000U
                                             : (VL_GTS_III(32, 0xc8U, vlSelf->fpga_template_top_tb__DOT__sample_count)
                                                 ? 0x100000U
                                                 : 0x200000U))));
        vlSelf->fpga_template_top_tb__DOT__left_sample 
            = (0xffffffU & (vlSelf->fpga_template_top_tb__DOT__left_sample 
                            + vlSelf->fpga_template_top_tb__DOT__sample_count));
        vlSelf->fpga_template_top_tb__DOT__right_sample 
            = (0xffffffU & ((IData)(1U) + vlSelf->fpga_template_top_tb__DOT__left_sample));
        vlSelf->fpga_template_top_tb__DOT__sample_count 
            = ((IData)(1U) + vlSelf->fpga_template_top_tb__DOT__sample_count);
    }
}

VL_INLINE_OPT VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__3(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__3\n"); );
    // Body
    vlSelf->fpga_template_top_tb__DOT__sample_count = 0U;
    while ((1U & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb)))) {
        co_await vlSelf->__VtrigSched_h904cec7c__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] fpga_template_top_tb.btn_s1_resetb)", 
                                                           "fpga_template_top_tb.sv", 
                                                           172);
    }
    while (1U) {
        co_await vlSelf->__VtrigSched_h21ee7aaa__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge fpga_template_top_tb.dut.sampler_to_ram_write_request_w)", 
                                                           "fpga_template_top_tb.sv", 
                                                           175);
        VL_WRITEF("[%0t] Sample %0d captured: L=0x%06x R=0x%06x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->fpga_template_top_tb__DOT__sample_count,
                  24,vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_left,
                  24,vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_right);
    }
}

VL_INLINE_OPT VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__4(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__4\n"); );
    // Body
    vlSelf->fpga_template_top_tb__DOT__buffer_swap_count = 0U;
    while ((1U & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb)))) {
        co_await vlSelf->__VtrigSched_h904cec7c__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] fpga_template_top_tb.btn_s1_resetb)", 
                                                           "fpga_template_top_tb.sv", 
                                                           186);
    }
    while (1U) {
        co_await vlSelf->__VtrigSched_hbe0e6ec5__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge fpga_template_top_tb.dut.ram_to_6led_buffer_ready_w)", 
                                                           "fpga_template_top_tb.sv", 
                                                           189);
        vlSelf->fpga_template_top_tb__DOT__buffer_swap_count 
            = ((IData)(1U) + vlSelf->fpga_template_top_tb__DOT__buffer_swap_count);
        VL_WRITEF("[%0t] === Buffer swap %0d - Write buffer full, starting read phase ===\n         Write buffer was: RAM%0#, Read buffer now: RAM%0#\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->fpga_template_top_tb__DOT__buffer_swap_count,
                  1,(IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel),
                  1,vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_sel);
    }
}

VL_INLINE_OPT VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__6(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__6\n"); );
    // Body
    vlSelf->fpga_template_top_tb__DOT__prev_leds = 0U;
    while ((1U & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb)))) {
        co_await vlSelf->__VtrigSched_h904cec7c__0.trigger(1U, 
                                                           nullptr, 
                                                           "@([changed] fpga_template_top_tb.btn_s1_resetb)", 
                                                           "fpga_template_top_tb.sv", 
                                                           262);
    }
    while (1U) {
        co_await vlSelf->__VtrigSched_h52ecb243__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge fpga_template_top_tb.clk)", 
                                                           "fpga_template_top_tb.sv", 
                                                           265);
        if (VL_UNLIKELY(((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__debug_sample_led) 
                         != (IData)(vlSelf->fpga_template_top_tb__DOT__prev_leds)))) {
            VL_WRITEF("[%0t] VU LEDs changed: %06b (level=%0#)\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      6,(IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__debug_sample_led),
                      32,vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q);
            vlSelf->fpga_template_top_tb__DOT__prev_leds 
                = vlSelf->fpga_template_top_tb__DOT__dut__DOT__debug_sample_led;
        }
    }
}

void Vfpga_template_top_tb___024root___eval_act(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_act\n"); );
}

extern const VlUnpacked<CData/*2:0*/, 32> Vfpga_template_top_tb__ConstPool__TABLE_hb31b5e30_0;
extern const VlUnpacked<CData/*1:0*/, 32> Vfpga_template_top_tb__ConstPool__TABLE_h11502f1d_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vfpga_template_top_tb__ConstPool__TABLE_h56c82868_0;

VL_INLINE_OPT void Vfpga_template_top_tb___024root___nba_sequent__TOP__0(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*5:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q = 0;
    IData/*24:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q = 0;
    CData/*0:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q = 0;
    CData/*0:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__right_done_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__right_done_q = 0;
    CData/*0:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid = 0;
    CData/*0:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress = 0;
    CData/*4:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address = 0;
    CData/*5:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count = 0;
    CData/*4:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address = 0;
    CData/*5:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count = 0;
    SData/*8:0*/ __Vdlyvdim0__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem__v0;
    __Vdlyvdim0__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem__v0;
    __Vdlyvval__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem__v0;
    __Vdlyvset__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 = 0;
    SData/*8:0*/ __Vdlyvdim0__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem__v0;
    __Vdlyvdim0__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem__v0;
    __Vdlyvval__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem__v0;
    __Vdlyvset__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__processing_delay_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__processing_delay_q = 0;
    IData/*19:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q = 0;
    CData/*0:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q = 0;
    CData/*5:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_ctr_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_ctr_q = 0;
    // Body
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__processing_delay_q 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__processing_delay_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_ctr_q 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_ctr_q;
    vlSelf->__Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__right_done_q 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__right_done_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q;
    __Vdlyvset__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 = 0U;
    __Vdlyvset__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 = 0U;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address;
    __Vtableidx1 = (((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_ctr_q) 
                     << 2U) | (((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q) 
                                << 1U) | (IData)(vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb)));
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_ctr_q 
        = Vfpga_template_top_tb__ConstPool__TABLE_hb31b5e30_0
        [__Vtableidx1];
    if ((2U & Vfpga_template_top_tb__ConstPool__TABLE_h11502f1d_0
         [__Vtableidx1])) {
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q 
            = Vfpga_template_top_tb__ConstPool__TABLE_h56c82868_0
            [__Vtableidx1];
    }
    if (vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_write_enable) {
        __Vdlyvval__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 
            = vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_left;
        __Vdlyvset__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 = 1U;
        __Vdlyvdim0__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 
            = (0x1ffU & ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_address) 
                         >> 5U));
    }
    if (vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_write_enable) {
        __Vdlyvval__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 
            = vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_left;
        __Vdlyvset__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 = 1U;
        __Vdlyvdim0__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 
            = (0x1ffU & ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_address) 
                         >> 5U));
    }
    if (vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb) {
        if (vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__sample_valid) {
            vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q 
                = ((vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q 
                    - VL_SHIFTR_III(32,32,32, vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q, 0x14U)) 
                   + VL_SHIFTR_III(32,32,32, (0xffffffU 
                                              & (((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid) 
                                                  & (vlSelf->__VdfgTmp_hb1fddee5__0 
                                                     >> 0x17U))
                                                  ? 
                                                 ((IData)(1U) 
                                                  + 
                                                  (~ vlSelf->fpga_template_top_tb__DOT__dut__DOT____Vcellinp__vu__ram_read_data_i))
                                                  : vlSelf->fpga_template_top_tb__DOT__dut__DOT____Vcellinp__vu__ram_read_data_i)), 0xcU));
            vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__ram_ready_q = 0U;
            __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__processing_delay_q = 1U;
        } else if (vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__processing_delay_q) {
            vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__ram_ready_q = 0U;
            __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__processing_delay_q = 0U;
        } else {
            vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__ram_ready_q = 1U;
        }
        if (vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__tick) {
            vlSelf->fpga_template_top_tb__DOT__dut__DOT__debug_sample_led 
                = vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__leds_next;
        }
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__frame_start_q = 0U;
        if (((~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q)) 
             & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_prev_q))) {
            if ((0x1fU == (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_ctr_q))) {
                vlSelf->__Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q 
                    = (1U & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q)));
                __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_ctr_q = 0U;
                if (vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q) {
                    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__frame_start_q = 1U;
                }
            } else {
                __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_ctr_q 
                    = (0x3fU & ((IData)(1U) + (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_ctr_q)));
            }
        }
        if (((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q) 
             != (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_prev_q))) {
            vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_period_cycles 
                = ((IData)(VL_DIV_QQQ(64, (QData)(VL_TIME_UNITED_Q(1000)), 0x3e8ULL)) 
                   - vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_last_toggle_time);
            vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_last_toggle_time 
                = (IData)(VL_DIV_QQQ(64, (QData)(VL_TIME_UNITED_Q(1000)), 0x3e8ULL));
        }
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w = 0U;
        vlSelf->fpga_template_top_tb__DOT__buffer_full = 0U;
        if ((0x10U == (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count))) {
            vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w = 1U;
            __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid = 1U;
            __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress = 1U;
            vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_sel 
                = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel;
            __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address = 0U;
            __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count = 0U;
            __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address = 0U;
            __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count = 0U;
            vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_read_valid_w = 0U;
            vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel 
                = (1U & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel)));
        } else {
            if (((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__sample_valid) 
                 & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid))) {
                if ((0xfU > (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count))) {
                    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address 
                        = (0x1fU & ((IData)(1U) + (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address)));
                    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count 
                        = (0x3fU & ((IData)(1U) + (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count)));
                } else {
                    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress = 0U;
                    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count = 0U;
                    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address = 0U;
                }
            }
            if (vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_accepted) {
                if ((0x10U > (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count))) {
                    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address 
                        = (0x1fU & ((IData)(1U) + (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address)));
                    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count 
                        = (0x3fU & ((IData)(1U) + (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count)));
                } else {
                    vlSelf->fpga_template_top_tb__DOT__buffer_full = 1U;
                }
            }
            vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_read_valid_w 
                = ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid) 
                   & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress));
        }
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__sampler_to_ram_write_request_w = 0U;
        if ((0x19U == (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q))) {
            if ((1U & ((~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__channel_q)) 
                       & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q))))) {
                vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_left 
                    = (0xffffffU & vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q);
                __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q = 1U;
            } else if (((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__channel_q) 
                        & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q))) {
                vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_right 
                    = (0xffffffU & vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q);
                __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__right_done_q = 1U;
            }
        }
        if (vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__ws_edge) {
            __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q = 0U;
            __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q = 0U;
            vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__channel_q 
                = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q;
        } else if (((~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_prev_q)) 
                    & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q))) {
            if ((0x19U > (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q))) {
                __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q 
                    = ((0x1fffffeU & (vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q 
                                      << 1U)) | (IData)(vlSelf->fpga_template_top_tb__DOT__mic_sd_0));
                __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q 
                    = (0x3fU & ((IData)(1U) + (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q)));
            }
        }
        if (((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q) 
             & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__right_done_q))) {
            vlSelf->fpga_template_top_tb__DOT__dut__DOT__sampler_to_ram_write_request_w = 1U;
            __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q = 0U;
            __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__right_done_q = 0U;
        }
        if ((0x83d5fU == vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q)) {
            __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q = 0U;
            vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__tick = 1U;
        } else {
            __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q 
                = (0xfffffU & ((IData)(1U) + vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q));
            vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__tick = 0U;
        }
    } else {
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__ram_ready_q = 1U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__processing_delay_q = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__debug_sample_led = 0U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_ctr_q = 0U;
        vlSelf->__Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__frame_start_q = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel = 0U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address = 0U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address = 0U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count = 0U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_sel = 1U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid = 0U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w = 0U;
        vlSelf->fpga_template_top_tb__DOT__buffer_full = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_read_valid_w = 0U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__right_done_q = 0U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q = 0U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_left = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_right = 0U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__sampler_to_ram_write_request_w = 0U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__tick = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_last_toggle_time = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__channel_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_write_enable)))) {
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_data_out 
            = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem
            [(0x1ffU & ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_address) 
                        >> 5U))];
    }
    if ((1U & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_write_enable)))) {
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_data_out 
            = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem
            [(0x1ffU & ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_address) 
                        >> 5U))];
    }
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__ws_d 
        = ((IData)(vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb) 
           && (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q));
    if (__Vdlyvset__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem__v0) {
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem[__Vdlyvdim0__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem__v0] 
            = __Vdlyvval__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem__v0;
    }
    if (__Vdlyvset__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem__v0) {
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem[__Vdlyvdim0__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem__v0] 
            = __Vdlyvval__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem__v0;
    }
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__processing_delay_q 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__processing_delay_q;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_ctr_q 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_ctr_q;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__leds_next 
        = ((0x38U & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__leds_next)) 
           | (((0x2328U < vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q) 
               << 2U) | (((0xbb8U < vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q) 
                          << 1U) | (0x3e8U < vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q))));
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__leds_next 
        = ((7U & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__leds_next)) 
           | (((0x13880U < vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q) 
               << 5U) | (((0x9c40U < vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q) 
                          << 4U) | ((0x4e20U < vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q) 
                                    << 3U))));
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__sample_valid 
        = ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_read_valid_w) 
           & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__ram_ready_q));
    vlSelf->__VdfgTmp_hb1fddee5__0 = ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_sel)
                                       ? vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_data_out
                                       : vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_data_out);
    if (vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel) {
        vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__0__addr 
            = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address;
        vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__0__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__0__addr) 
               << 5U);
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_address 
            = vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__0__Vfuncout;
        vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__1__addr 
            = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address;
        vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__1__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__1__addr) 
               << 5U);
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_address 
            = vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__1__Vfuncout;
    } else {
        vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__2__addr 
            = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address;
        vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__2__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__2__addr) 
               << 5U);
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_address 
            = vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__2__Vfuncout;
        vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__3__addr 
            = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address;
        vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__3__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__3__addr) 
               << 5U);
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_address 
            = vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__3__Vfuncout;
    }
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__right_done_q 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__right_done_q;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT____Vcellinp__vu__ram_read_data_i 
        = ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid)
            ? (0xffffffU & vlSelf->__VdfgTmp_hb1fddee5__0)
            : 0U);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_accepted 
        = ((0x10U > (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count)) 
           & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__sampler_to_ram_write_request_w));
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_prev_q 
        = ((IData)(vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb) 
           && (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q));
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_write_enable 
        = ((~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel)) 
           & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_accepted));
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_write_enable 
        = ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_accepted) 
           & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel));
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q;
}

VL_INLINE_OPT void Vfpga_template_top_tb___024root___nba_sequent__TOP__1(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___nba_sequent__TOP__1\n"); );
    // Body
    if (vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb) {
        if (((~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q)) 
             & (0U == vlSelf->fpga_template_top_tb__DOT__bit_counter))) {
            vlSelf->fpga_template_top_tb__DOT__left_shift_reg 
                = vlSelf->fpga_template_top_tb__DOT__left_sample;
            vlSelf->fpga_template_top_tb__DOT__bit_counter = 1U;
            vlSelf->fpga_template_top_tb__DOT__mic_sd_0 
                = (1U & (vlSelf->fpga_template_top_tb__DOT__left_shift_reg 
                         >> 0x18U));
        } else if (((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q) 
                    & (0U == vlSelf->fpga_template_top_tb__DOT__bit_counter))) {
            vlSelf->fpga_template_top_tb__DOT__right_shift_reg 
                = vlSelf->fpga_template_top_tb__DOT__right_sample;
            vlSelf->fpga_template_top_tb__DOT__bit_counter = 1U;
            vlSelf->fpga_template_top_tb__DOT__mic_sd_0 
                = (1U & (vlSelf->fpga_template_top_tb__DOT__right_shift_reg 
                         >> 0x18U));
        } else if ((VL_LTS_III(32, 0U, vlSelf->fpga_template_top_tb__DOT__bit_counter) 
                    & VL_GTS_III(32, 0x19U, vlSelf->fpga_template_top_tb__DOT__bit_counter))) {
            vlSelf->fpga_template_top_tb__DOT__bit_counter 
                = ((IData)(1U) + vlSelf->fpga_template_top_tb__DOT__bit_counter);
            if (vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q) {
                vlSelf->fpga_template_top_tb__DOT__right_shift_reg 
                    = (0x1fffffeU & (vlSelf->fpga_template_top_tb__DOT__right_shift_reg 
                                     << 1U));
                vlSelf->fpga_template_top_tb__DOT__mic_sd_0 
                    = (1U & (vlSelf->fpga_template_top_tb__DOT__right_shift_reg 
                             >> 0x18U));
            } else {
                vlSelf->fpga_template_top_tb__DOT__left_shift_reg 
                    = (0x1fffffeU & (vlSelf->fpga_template_top_tb__DOT__left_shift_reg 
                                     << 1U));
                vlSelf->fpga_template_top_tb__DOT__mic_sd_0 
                    = (1U & (vlSelf->fpga_template_top_tb__DOT__left_shift_reg 
                             >> 0x18U));
            }
        } else if (VL_LTES_III(32, 0x1fU, vlSelf->fpga_template_top_tb__DOT__bit_counter)) {
            vlSelf->fpga_template_top_tb__DOT__bit_counter = 0U;
            vlSelf->fpga_template_top_tb__DOT__mic_sd_0 = 0U;
        } else {
            vlSelf->fpga_template_top_tb__DOT__bit_counter 
                = ((IData)(1U) + vlSelf->fpga_template_top_tb__DOT__bit_counter);
        }
    } else {
        vlSelf->fpga_template_top_tb__DOT__bit_counter = 0U;
        vlSelf->fpga_template_top_tb__DOT__left_shift_reg = 0U;
        vlSelf->fpga_template_top_tb__DOT__right_shift_reg = 0U;
        vlSelf->fpga_template_top_tb__DOT__mic_sd_0 = 0U;
    }
}

VL_INLINE_OPT void Vfpga_template_top_tb___024root___nba_sequent__TOP__2(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___nba_sequent__TOP__2\n"); );
    // Body
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q 
        = vlSelf->__Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__ws_edge 
        = ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__ws_d) 
           != (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q));
}

void Vfpga_template_top_tb___024root___eval_nba(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vfpga_template_top_tb___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vfpga_template_top_tb___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vfpga_template_top_tb___024root___nba_sequent__TOP__2(vlSelf);
    }
}

void Vfpga_template_top_tb___024root___timing_resume(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___timing_resume\n"); );
    // Body
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h52ecb243__0.resume("@(posedge fpga_template_top_tb.clk)");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h904cec7c__0.resume("@([changed] fpga_template_top_tb.btn_s1_resetb)");
    }
    if ((0x10ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_ha0e3b59f__0.resume("@(negedge fpga_template_top_tb.dut.u_i2s_clock.ws_q)");
    }
    if ((0x20ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h21ee7aaa__0.resume("@(posedge fpga_template_top_tb.dut.sampler_to_ram_write_request_w)");
    }
    if ((0x40ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_hbe0e6ec5__0.resume("@(posedge fpga_template_top_tb.dut.ram_to_6led_buffer_ready_w)");
    }
    if ((0x80ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h10a6e2e3__0.resume("@(posedge fpga_template_top_tb.buffer_full)");
    }
    if ((0x100ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h43f1a8d3__0.resume("@([changed] (32'sh50 <= fpga_template_top_tb.sample_count))");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vfpga_template_top_tb___024root___timing_commit(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___timing_commit\n"); );
    // Body
    if ((! (2ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h52ecb243__0.commit("@(posedge fpga_template_top_tb.clk)");
    }
    if ((! (8ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h904cec7c__0.commit("@([changed] fpga_template_top_tb.btn_s1_resetb)");
    }
    if ((! (0x10ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_ha0e3b59f__0.commit("@(negedge fpga_template_top_tb.dut.u_i2s_clock.ws_q)");
    }
    if ((! (0x20ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h21ee7aaa__0.commit("@(posedge fpga_template_top_tb.dut.sampler_to_ram_write_request_w)");
    }
    if ((! (0x40ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_hbe0e6ec5__0.commit("@(posedge fpga_template_top_tb.dut.ram_to_6led_buffer_ready_w)");
    }
    if ((! (0x80ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h10a6e2e3__0.commit("@(posedge fpga_template_top_tb.buffer_full)");
    }
    if ((! (0x100ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h43f1a8d3__0.commit("@([changed] (32'sh50 <= fpga_template_top_tb.sample_count))");
    }
}

void Vfpga_template_top_tb___024root___eval_triggers__act(Vfpga_template_top_tb___024root* vlSelf);

bool Vfpga_template_top_tb___024root___eval_phase__act(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<9> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vfpga_template_top_tb___024root___eval_triggers__act(vlSelf);
    Vfpga_template_top_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vfpga_template_top_tb___024root___timing_resume(vlSelf);
        Vfpga_template_top_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vfpga_template_top_tb___024root___eval_phase__nba(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vfpga_template_top_tb___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpga_template_top_tb___024root___dump_triggers__nba(Vfpga_template_top_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpga_template_top_tb___024root___dump_triggers__act(Vfpga_template_top_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vfpga_template_top_tb___024root___eval(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vfpga_template_top_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("fpga_template_top_tb.sv", 17, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vfpga_template_top_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("fpga_template_top_tb.sv", 17, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vfpga_template_top_tb___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vfpga_template_top_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vfpga_template_top_tb___024root___eval_debug_assertions(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
