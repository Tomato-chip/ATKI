// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpga_template_top_tb.h for the primary calling header

#include "Vfpga_template_top_tb__pch.h"
#include "Vfpga_template_top_tb___024root.h"

VL_ATTR_COLD void Vfpga_template_top_tb___024root___eval_initial__TOP(Vfpga_template_top_tb___024root* vlSelf);
VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__0(Vfpga_template_top_tb___024root* vlSelf);
VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__1(Vfpga_template_top_tb___024root* vlSelf, VlProcessRef vlProcess);
VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__2(Vfpga_template_top_tb___024root* vlSelf);

void Vfpga_template_top_tb___024root___eval_initial(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_initial\n"); );
    // Body
    Vfpga_template_top_tb___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf, std::make_shared<VlProcess>());
    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__clk__0 
        = vlSelf->fpga_template_top_tb__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w__0 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w;
}

VL_INLINE_OPT VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__0(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->fpga_template_top_tb__DOT__clk = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x4650ULL, 
                                           nullptr, 
                                           "fpga_template_top_tb.sv", 
                                           50);
        vlSelf->fpga_template_top_tb__DOT__clk = (1U 
                                                  & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__clk)));
    }
}

VL_INLINE_OPT VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_1__1(Vfpga_template_top_tb___024root* vlSelf, VlProcessRef vlProcess) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_1__1\n"); );
    // Init
    IData/*31:0*/ __Vtask_fpga_template_top_tb__DOT__wait_cycles__5__num_cycles;
    __Vtask_fpga_template_top_tb__DOT__wait_cycles__5__num_cycles = 0;
    // Body
    __Vtask_fpga_template_top_tb__DOT__wait_cycles__5__num_cycles = 0x278d0U;
    vlSelf->fpga_template_top_tb__DOT____Vrepeat2 = __Vtask_fpga_template_top_tb__DOT__wait_cycles__5__num_cycles;
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
    VL_WRITEF("[%0t] Timeout waiting for buffer swap\n",
              64,VL_TIME_UNITED_Q(1000),-9);
    vlSelf->__Vfork_1__sync.done("fpga_template_top_tb.sv", 
                                 334);
    vlProcess->state(VlProcess::FINISHED);
}

VL_INLINE_OPT VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_1__0(Vfpga_template_top_tb___024root* vlSelf, VlProcessRef vlProcess) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__1____Vfork_1__0\n"); );
    // Body
    while ((1U & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w)))) {
        co_await vlSelf->__VtrigSched_hbe0e6d50__0.trigger(1U, 
                                                           vlProcess, 
                                                           "@([changed] fpga_template_top_tb.dut.ram_to_6led_buffer_ready_w)", 
                                                           "fpga_template_top_tb.sv", 
                                                           331);
    }
    VL_WRITEF("[%0t] *** BUFFER SWAP DETECTED ***\n",
              64,VL_TIME_UNITED_Q(1000),-9);
    vlSelf->__Vfork_1__sync.done("fpga_template_top_tb.sv", 
                                 330);
    vlProcess->state(VlProcess::FINISHED);
}

VL_INLINE_OPT VlCoroutine Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__2(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0x2540be400ULL, 
                                       nullptr, "fpga_template_top_tb.sv", 
                                       403);
    VL_WRITEF("\n*** SIMULATION TIMEOUT at %0t ***\nTotal errors: %0d\n",
              64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->fpga_template_top_tb__DOT__error_count);
    VL_FINISH_MT("fpga_template_top_tb.sv", 406, "");
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
    IData/*23:0*/ __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__Vfuncout;
    __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__sample_num;
    __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__sample_num = 0;
    CData/*0:0*/ __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__is_left;
    __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__is_left = 0;
    IData/*23:0*/ __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__amplitude;
    __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__amplitude = 0;
    IData/*31:0*/ __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__phase;
    __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__phase = 0;
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*5:0*/ __Vdly__fpga_template_top_tb__DOT__bit_counter;
    __Vdly__fpga_template_top_tb__DOT__bit_counter = 0;
    IData/*24:0*/ __Vdly__fpga_template_top_tb__DOT__mic_shift_reg;
    __Vdly__fpga_template_top_tb__DOT__mic_shift_reg = 0;
    IData/*31:0*/ __Vdly__fpga_template_top_tb__DOT__captured_sample_count;
    __Vdly__fpga_template_top_tb__DOT__captured_sample_count = 0;
    IData/*31:0*/ __Vdly__fpga_template_top_tb__DOT__buffer_swap_count;
    __Vdly__fpga_template_top_tb__DOT__buffer_swap_count = 0;
    IData/*24:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q = 0;
    CData/*5:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q = 0;
    CData/*0:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q = 0;
    CData/*0:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__right_done_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__right_done_q = 0;
    CData/*7:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address = 0;
    CData/*7:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address = 0;
    SData/*8:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count = 0;
    SData/*8:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count = 0;
    CData/*0:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel = 0;
    CData/*0:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid = 0;
    CData/*0:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress = 0;
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
    IData/*31:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q = 0;
    IData/*19:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q = 0;
    CData/*0:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q = 0;
    CData/*5:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_ctr_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_ctr_q = 0;
    CData/*0:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q = 0;
    // Body
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_ctr_q 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_ctr_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q;
    __Vdly__fpga_template_top_tb__DOT__mic_shift_reg 
        = vlSelf->fpga_template_top_tb__DOT__mic_shift_reg;
    __Vdly__fpga_template_top_tb__DOT__bit_counter 
        = vlSelf->fpga_template_top_tb__DOT__bit_counter;
    if (VL_UNLIKELY(((0x3fU & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__debug_sample_led))) 
                     != (IData)(vlSelf->fpga_template_top_tb__DOT__debug_led_prev)))) {
        VL_WRITEF("[%0t] LED changed: 0x%02x (binary: %06b)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,6,(0x3fU 
                                                  & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__debug_sample_led))),
                  6,(0x3fU & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__debug_sample_led))));
    }
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid;
    if (VL_UNLIKELY(vlSelf->fpga_template_top_tb__DOT__buffer_full)) {
        VL_WRITEF("[%0t] !!! BUFFER OVERFLOW DETECTED !!!\n",
                  64,VL_TIME_UNITED_Q(1000),-9);
    }
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count;
    __Vdly__fpga_template_top_tb__DOT__buffer_swap_count 
        = vlSelf->fpga_template_top_tb__DOT__buffer_swap_count;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__right_done_q 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__right_done_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q;
    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q;
    __Vdlyvset__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 = 0U;
    __Vdlyvset__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 = 0U;
    __Vdly__fpga_template_top_tb__DOT__captured_sample_count 
        = vlSelf->fpga_template_top_tb__DOT__captured_sample_count;
    __Vtableidx1 = (((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_ctr_q) 
                     << 2U) | (((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q) 
                                << 1U) | (1U & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb)))));
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_ctr_q 
        = Vfpga_template_top_tb__ConstPool__TABLE_hb31b5e30_0
        [__Vtableidx1];
    if ((2U & Vfpga_template_top_tb__ConstPool__TABLE_h11502f1d_0
         [__Vtableidx1])) {
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q 
            = Vfpga_template_top_tb__ConstPool__TABLE_h56c82868_0
            [__Vtableidx1];
    }
    if (((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q) 
         != (IData)(vlSelf->fpga_template_top_tb__DOT__ws_prev))) {
        vlSelf->fpga_template_top_tb__DOT__ws_transition_count 
            = ((IData)(1U) + vlSelf->fpga_template_top_tb__DOT__ws_transition_count);
    }
    if (((~ (IData)(vlSelf->fpga_template_top_tb__DOT__sck_prev_mon)) 
         & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q))) {
        vlSelf->fpga_template_top_tb__DOT__sck_edge_count 
            = ((IData)(1U) + vlSelf->fpga_template_top_tb__DOT__sck_edge_count);
    }
    if (VL_UNLIKELY(vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w)) {
        __Vdly__fpga_template_top_tb__DOT__buffer_swap_count 
            = ((IData)(1U) + vlSelf->fpga_template_top_tb__DOT__buffer_swap_count);
        VL_WRITEF("[%0t] *** RAM BUFFER SWAP #%0d - Buffer full and ready for reading ***\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,vlSelf->fpga_template_top_tb__DOT__buffer_swap_count);
    }
    if (vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_write_enable) {
        __Vdlyvval__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 
            = vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_left;
        __Vdlyvset__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 = 1U;
        __Vdlyvdim0__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 
            = (0xffU & ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_address) 
                        >> 5U));
    }
    if (vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_write_enable) {
        __Vdlyvval__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 
            = vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_left;
        __Vdlyvset__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 = 1U;
        __Vdlyvdim0__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 
            = (0xffU & ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_address) 
                        >> 5U));
    }
    if (vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb) {
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q = 0U;
    } else if (vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_read_valid_w) {
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q 
            = ((vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q 
                - VL_SHIFTR_III(32,32,32, vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q, 0xbU)) 
               + VL_SHIFTR_III(32,32,32, (0xffffffU 
                                          & (((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid) 
                                              & (vlSelf->__VdfgTmp_hb1fddee5__0 
                                                 >> 0x17U))
                                              ? ((IData)(1U) 
                                                 + 
                                                 (~ vlSelf->fpga_template_top_tb__DOT__dut__DOT____Vcellinp__vu__ram_read_data_i))
                                              : vlSelf->fpga_template_top_tb__DOT__dut__DOT____Vcellinp__vu__ram_read_data_i)), 0xcU));
    }
    if (vlSelf->fpga_template_top_tb__DOT__dut__DOT__sampler_to_ram_write_request_w) {
        __Vdly__fpga_template_top_tb__DOT__captured_sample_count 
            = ((IData)(1U) + vlSelf->fpga_template_top_tb__DOT__captured_sample_count);
        if (VL_UNLIKELY(VL_GTS_III(32, 5U, vlSelf->fpga_template_top_tb__DOT__captured_sample_count))) {
            VL_WRITEF("[%0t] Sample captured: L=0x%06x (%0d), R=0x%06x (%0d)\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      24,vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_left,
                      24,vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_left,
                      24,vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_right,
                      24,vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_right);
        }
    }
    if ((1U & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_write_enable)))) {
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_data_out 
            = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem
            [(0xffU & ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_address) 
                       >> 5U))];
    }
    if ((1U & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_write_enable)))) {
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_data_out 
            = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem
            [(0xffU & ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_address) 
                       >> 5U))];
    }
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__ws_d 
        = ((1U & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb))) 
           && (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q));
    vlSelf->fpga_template_top_tb__DOT__debug_led_prev 
        = (0x3fU & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__debug_sample_led)));
    if (vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb) {
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_ctr_q = 0U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__frame_start_q = 0U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address = 0U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address = 0U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count = 0U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count = 0U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_sel = 1U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid = 0U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w = 0U;
        vlSelf->fpga_template_top_tb__DOT__buffer_full = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_read_valid_w = 0U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q = 0U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_left = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_right = 0U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q = 0U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__right_done_q = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__sampler_to_ram_write_request_w = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__debug_sample_led = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__channel_q = 0U;
        __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q = 0U;
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__tick = 0U;
    } else {
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__frame_start_q = 0U;
        if (((~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q)) 
             & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_prev_q))) {
            if ((0x1fU == (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_ctr_q))) {
                __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q 
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
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w = 0U;
        vlSelf->fpga_template_top_tb__DOT__buffer_full = 0U;
        if ((0x100U == (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count))) {
            if ((1U & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress)))) {
                vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w = 1U;
                __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid = 1U;
                __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress = 1U;
                vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_sel 
                    = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel;
                __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address = 0U;
                __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count = 0U;
                __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address = 0U;
                __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count = 0U;
                vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_read_valid_w = 1U;
                __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel 
                    = (1U & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel)));
            }
        } else {
            if (vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_accepted) {
                if ((0x100U > (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count))) {
                    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address 
                        = (0xffU & ((IData)(1U) + (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address)));
                    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count 
                        = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count)));
                } else {
                    vlSelf->fpga_template_top_tb__DOT__buffer_full = 1U;
                }
            }
            if (((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_accepted) 
                 & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid))) {
                if ((0xffU > (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count))) {
                    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address 
                        = (0xffU & ((IData)(1U) + (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address)));
                    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count 
                        = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count)));
                    vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_read_valid_w = 1U;
                } else {
                    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress = 0U;
                    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid = 0U;
                    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count = 0U;
                    __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address = 0U;
                    vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_read_valid_w = 0U;
                }
            } else {
                vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_read_valid_w 
                    = ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid) 
                       & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress));
            }
        }
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__sampler_to_ram_write_request_w = 0U;
        if ((0x19U == (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q))) {
            if (vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__channel_q) {
                vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_right 
                    = (0xffffffU & vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q);
                __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__right_done_q = 1U;
            } else {
                vlSelf->fpga_template_top_tb__DOT__dut__DOT__sample_left 
                    = (0xffffffU & vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q);
                __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q = 1U;
            }
        }
        if (vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__ws_edge) {
            __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q = 0U;
            __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q = 0U;
            vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__channel_q 
                = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q;
        } else if (((~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__sck_d)) 
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
        if (vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__tick) {
            vlSelf->fpga_template_top_tb__DOT__dut__DOT__debug_sample_led 
                = vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__leds_next;
        }
        if ((0x83d5fU == vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q)) {
            __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q = 0U;
            vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__tick = 1U;
        } else {
            __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q 
                = (0xfffffU & ((IData)(1U) + vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q));
            vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__tick = 0U;
        }
    }
    vlSelf->fpga_template_top_tb__DOT__buffer_swap_count 
        = __Vdly__fpga_template_top_tb__DOT__buffer_swap_count;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q;
    vlSelf->fpga_template_top_tb__DOT__captured_sample_count 
        = __Vdly__fpga_template_top_tb__DOT__captured_sample_count;
    if (__Vdlyvset__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem__v0) {
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem[__Vdlyvdim0__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem__v0] 
            = __Vdlyvval__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem__v0;
    }
    if (__Vdlyvset__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem__v0) {
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem[__Vdlyvdim0__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem__v0] 
            = __Vdlyvval__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem__v0;
    }
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_ctr_q 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_ctr_q;
    vlSelf->fpga_template_top_tb__DOT__ws_prev = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q;
    vlSelf->fpga_template_top_tb__DOT__sck_prev_mon 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_prev_q 
        = ((1U & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb))) 
           && (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q));
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__right_done_q 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__right_done_q;
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
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_accepted 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_read_valid_w;
    vlSelf->__VdfgTmp_hb1fddee5__0 = ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_sel)
                                       ? vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_data_out
                                       : vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_data_out);
    if (vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel) {
        vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__10__addr 
            = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address;
        vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__10__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__10__addr) 
               << 5U);
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_address 
            = vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__10__Vfuncout;
        vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__11__addr 
            = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address;
        vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__11__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__11__addr) 
               << 5U);
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_address 
            = vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__11__Vfuncout;
    } else {
        vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__12__addr 
            = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address;
        vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__12__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__12__addr) 
               << 5U);
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_address 
            = vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__12__Vfuncout;
        vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__13__addr 
            = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address;
        vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__13__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__13__addr) 
               << 5U);
        vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_address 
            = vlSelf->__Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__13__Vfuncout;
    }
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_accepted 
        = ((0x100U > (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count)) 
           & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__sampler_to_ram_write_request_w));
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__sck_d 
        = ((1U & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__btn_s1_resetb))) 
           && (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q));
    if (((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q) 
         != (IData)(vlSelf->fpga_template_top_tb__DOT__ws_prev_mic))) {
        __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__is_left 
            = (1U & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q)));
        __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__sample_num 
            = vlSelf->fpga_template_top_tb__DOT__sample_number;
        __Vdly__fpga_template_top_tb__DOT__bit_counter = 0U;
        vlSelf->fpga_template_top_tb__DOT__is_left_channel 
            = (1U & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q)));
        __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__phase 
            = VL_MODDIVS_III(32, __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__sample_num, (IData)(0x40U));
        __Vdly__fpga_template_top_tb__DOT__mic_shift_reg 
            = vlSelf->fpga_template_top_tb__DOT__test_sample;
        __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__amplitude 
            = (0xffffffU & ((IData)(__Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__is_left)
                             ? (VL_GTS_III(32, 0x10U, __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__phase)
                                 ? ((IData)(0x100000U) 
                                    + VL_MULS_III(32, (IData)(0x8000U), __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__phase))
                                 : (VL_GTS_III(32, 0x20U, __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__phase)
                                     ? ((IData)(0x180000U) 
                                        - VL_MULS_III(32, (IData)(0x8000U), 
                                                      (__Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__phase 
                                                       - (IData)(0x10U))))
                                     : (VL_GTS_III(32, 0x30U, __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__phase)
                                         ? ((IData)(0xe80000U) 
                                            - VL_MULS_III(32, (IData)(0x8000U), 
                                                          (__Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__phase 
                                                           - (IData)(0x20U))))
                                         : ((IData)(0xe00000U) 
                                            + VL_MULS_III(32, (IData)(0x8000U), 
                                                          (__Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__phase 
                                                           - (IData)(0x30U)))))))
                             : (VL_GTS_III(32, 0x20U, __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__phase)
                                 ? VL_MULS_III(32, (IData)(0x10000U), __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__phase)
                                 : VL_MULS_III(32, (IData)(0x10000U), 
                                               ((IData)(0x40U) 
                                                - __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__phase)))));
        __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__Vfuncout 
            = __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__amplitude;
        vlSelf->fpga_template_top_tb__DOT__test_sample 
            = __Vfunc_fpga_template_top_tb__DOT__generate_test_sample__0__Vfuncout;
        vlSelf->fpga_template_top_tb__DOT__sample_number 
            = ((IData)(1U) + vlSelf->fpga_template_top_tb__DOT__sample_number);
    }
    if (((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q) 
         & (~ (IData)(vlSelf->fpga_template_top_tb__DOT__sck_prev)))) {
        __Vdly__fpga_template_top_tb__DOT__bit_counter 
            = (0x3fU & ((IData)(1U) + (IData)(vlSelf->fpga_template_top_tb__DOT__bit_counter)));
        vlSelf->fpga_template_top_tb__DOT__mic_sd_0 
            = (1U & (vlSelf->fpga_template_top_tb__DOT__mic_shift_reg 
                     >> 0x18U));
        __Vdly__fpga_template_top_tb__DOT__mic_shift_reg 
            = (0x1fffffeU & (vlSelf->fpga_template_top_tb__DOT__mic_shift_reg 
                             << 1U));
    }
    vlSelf->fpga_template_top_tb__DOT__dut__DOT____Vcellinp__vu__ram_read_data_i 
        = ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid)
            ? (0xffffffU & vlSelf->__VdfgTmp_hb1fddee5__0)
            : 0U);
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_write_enable 
        = ((~ (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel)) 
           & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_accepted));
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_write_enable 
        = ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_accepted) 
           & (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel));
    vlSelf->fpga_template_top_tb__DOT__bit_counter 
        = __Vdly__fpga_template_top_tb__DOT__bit_counter;
    vlSelf->fpga_template_top_tb__DOT__mic_shift_reg 
        = __Vdly__fpga_template_top_tb__DOT__mic_shift_reg;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q;
    vlSelf->fpga_template_top_tb__DOT__ws_prev_mic 
        = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q;
    vlSelf->fpga_template_top_tb__DOT__sck_prev = vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q 
        = __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q;
    vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__ws_edge 
        = ((IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__ws_d) 
           != (IData)(vlSelf->fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q));
}

void Vfpga_template_top_tb___024root___eval_nba(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vfpga_template_top_tb___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
}

void Vfpga_template_top_tb___024root___timing_resume(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___timing_resume\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h52ecb243__0.resume("@(posedge fpga_template_top_tb.clk)");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_hbe0e6d50__0.resume("@([changed] fpga_template_top_tb.dut.ram_to_6led_buffer_ready_w)");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vfpga_template_top_tb___024root___timing_commit(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h52ecb243__0.commit("@(posedge fpga_template_top_tb.clk)");
    }
    if ((! (4ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_hbe0e6d50__0.commit("@([changed] fpga_template_top_tb.dut.ram_to_6led_buffer_ready_w)");
    }
}

void Vfpga_template_top_tb___024root___eval_triggers__act(Vfpga_template_top_tb___024root* vlSelf);

bool Vfpga_template_top_tb___024root___eval_phase__act(Vfpga_template_top_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_template_top_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_template_top_tb___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
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
            VL_FATAL_MT("fpga_template_top_tb.sv", 18, "", "NBA region did not converge.");
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
                VL_FATAL_MT("fpga_template_top_tb.sv", 18, "", "Active region did not converge.");
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
