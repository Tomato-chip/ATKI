// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfpga_system_tb.h for the primary calling header

#include "Vfpga_system_tb__pch.h"
#include "Vfpga_system_tb___024root.h"

VL_ATTR_COLD void Vfpga_system_tb___024root___eval_initial__TOP(Vfpga_system_tb___024root* vlSelf);
VlCoroutine Vfpga_system_tb___024root___eval_initial__TOP__Vtiming__0(Vfpga_system_tb___024root* vlSelf);
VlCoroutine Vfpga_system_tb___024root___eval_initial__TOP__Vtiming__1(Vfpga_system_tb___024root* vlSelf);
VlCoroutine Vfpga_system_tb___024root___eval_initial__TOP__Vtiming__2(Vfpga_system_tb___024root* vlSelf);

void Vfpga_system_tb___024root___eval_initial(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___eval_initial\n"); );
    // Body
    Vfpga_system_tb___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    Vfpga_system_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vfpga_system_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vfpga_system_tb___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__fpga_system_tb__DOT__clk__0 
        = vlSelf->fpga_system_tb__DOT__clk;
}

VL_INLINE_OPT VlCoroutine Vfpga_system_tb___024root___eval_initial__TOP__Vtiming__0(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->fpga_system_tb__DOT__clk = 0U;
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x4650ULL, 
                                           nullptr, 
                                           "fpga_system_tb.sv", 
                                           68);
        vlSelf->fpga_system_tb__DOT__clk = (1U & (~ (IData)(vlSelf->fpga_system_tb__DOT__clk)));
    }
}

VL_INLINE_OPT VlCoroutine Vfpga_system_tb___024root___eval_initial__TOP__Vtiming__2(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0x12a05f200ULL, 
                                       nullptr, "fpga_system_tb.sv", 
                                       403);
    VL_WRITEF("\n*** TIMEOUT - Simulation took too long ***\n");
    VL_FINISH_MT("fpga_system_tb.sv", 405, "");
}

void Vfpga_system_tb___024root___eval_act(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___eval_act\n"); );
}

extern const VlUnpacked<CData/*2:0*/, 32> Vfpga_system_tb__ConstPool__TABLE_hb31b5e30_0;
extern const VlUnpacked<CData/*1:0*/, 32> Vfpga_system_tb__ConstPool__TABLE_h11502f1d_0;
extern const VlUnpacked<CData/*0:0*/, 32> Vfpga_system_tb__ConstPool__TABLE_h56c82868_0;

VL_INLINE_OPT void Vfpga_system_tb___024root___nba_sequent__TOP__0(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    IData/*24:0*/ __Vdly__fpga_system_tb__DOT__mic_shift_reg;
    __Vdly__fpga_system_tb__DOT__mic_shift_reg = 0;
    CData/*4:0*/ __Vdly__fpga_system_tb__DOT__bit_counter;
    __Vdly__fpga_system_tb__DOT__bit_counter = 0;
    IData/*31:0*/ __Vdly__fpga_system_tb__DOT__sample_count;
    __Vdly__fpga_system_tb__DOT__sample_count = 0;
    IData/*31:0*/ __Vdly__fpga_system_tb__DOT__buffer_count;
    __Vdly__fpga_system_tb__DOT__buffer_count = 0;
    CData/*0:0*/ __Vdly__fpga_system_tb__DOT__u_i2s_clock__DOT__sck_q;
    __Vdly__fpga_system_tb__DOT__u_i2s_clock__DOT__sck_q = 0;
    CData/*0:0*/ __Vdly__fpga_system_tb__DOT__u_i2s_clock__DOT__ws_q;
    __Vdly__fpga_system_tb__DOT__u_i2s_clock__DOT__ws_q = 0;
    CData/*5:0*/ __Vdly__fpga_system_tb__DOT__u_i2s_clock__DOT__ws_ctr_q;
    __Vdly__fpga_system_tb__DOT__u_i2s_clock__DOT__ws_ctr_q = 0;
    CData/*5:0*/ __Vdly__fpga_system_tb__DOT__u_sampler__DOT__cnt_q;
    __Vdly__fpga_system_tb__DOT__u_sampler__DOT__cnt_q = 0;
    IData/*24:0*/ __Vdly__fpga_system_tb__DOT__u_sampler__DOT__shift25_q;
    __Vdly__fpga_system_tb__DOT__u_sampler__DOT__shift25_q = 0;
    CData/*0:0*/ __Vdly__fpga_system_tb__DOT__u_sampler__DOT__right_done_q;
    __Vdly__fpga_system_tb__DOT__u_sampler__DOT__right_done_q = 0;
    CData/*0:0*/ __Vdly__fpga_system_tb__DOT__u_sampler__DOT__left_done_q;
    __Vdly__fpga_system_tb__DOT__u_sampler__DOT__left_done_q = 0;
    CData/*0:0*/ __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_buffer_valid;
    __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_buffer_valid = 0;
    CData/*0:0*/ __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_in_progress;
    __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_in_progress = 0;
    CData/*4:0*/ __Vdly__fpga_system_tb__DOT__u_ram__DOT__write_address;
    __Vdly__fpga_system_tb__DOT__u_ram__DOT__write_address = 0;
    CData/*5:0*/ __Vdly__fpga_system_tb__DOT__u_ram__DOT__write_count;
    __Vdly__fpga_system_tb__DOT__u_ram__DOT__write_count = 0;
    CData/*4:0*/ __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_address;
    __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_address = 0;
    CData/*5:0*/ __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_count;
    __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_count = 0;
    SData/*8:0*/ __Vdlyvdim0__fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0;
    __Vdlyvdim0__fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0;
    __Vdlyvval__fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0;
    __Vdlyvset__fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 = 0;
    SData/*8:0*/ __Vdlyvdim0__fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0;
    __Vdlyvdim0__fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0;
    __Vdlyvval__fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0;
    __Vdlyvset__fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 = 0;
    SData/*9:0*/ __Vdly__fpga_system_tb__DOT__u_vu_meter__DOT__div_q;
    __Vdly__fpga_system_tb__DOT__u_vu_meter__DOT__div_q = 0;
    // Body
    __Vdly__fpga_system_tb__DOT__u_vu_meter__DOT__div_q 
        = vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__div_q;
    __Vdly__fpga_system_tb__DOT__u_i2s_clock__DOT__sck_q 
        = vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__sck_q;
    __Vdly__fpga_system_tb__DOT__bit_counter = vlSelf->fpga_system_tb__DOT__bit_counter;
    __Vdly__fpga_system_tb__DOT__mic_shift_reg = vlSelf->fpga_system_tb__DOT__mic_shift_reg;
    __Vdly__fpga_system_tb__DOT__u_i2s_clock__DOT__ws_ctr_q 
        = vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__ws_ctr_q;
    __Vdly__fpga_system_tb__DOT__u_i2s_clock__DOT__ws_q 
        = vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__ws_q;
    if (VL_UNLIKELY(((IData)(vlSelf->fpga_system_tb__DOT__rst_n) 
                     & ((IData)(vlSelf->fpga_system_tb__DOT__leds) 
                        != (IData)(vlSelf->fpga_system_tb__DOT__leds_prev))))) {
        VL_WRITEF("[%0t] LEDs changed: 0x%02x (binary: %06b)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,6,(IData)(vlSelf->fpga_system_tb__DOT__leds),
                  6,vlSelf->fpga_system_tb__DOT__leds);
    }
    __Vdly__fpga_system_tb__DOT__u_sampler__DOT__left_done_q 
        = vlSelf->fpga_system_tb__DOT__u_sampler__DOT__left_done_q;
    __Vdly__fpga_system_tb__DOT__u_sampler__DOT__right_done_q 
        = vlSelf->fpga_system_tb__DOT__u_sampler__DOT__right_done_q;
    __Vdly__fpga_system_tb__DOT__u_sampler__DOT__shift25_q 
        = vlSelf->fpga_system_tb__DOT__u_sampler__DOT__shift25_q;
    __Vdly__fpga_system_tb__DOT__u_sampler__DOT__cnt_q 
        = vlSelf->fpga_system_tb__DOT__u_sampler__DOT__cnt_q;
    __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_count 
        = vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_count;
    __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_in_progress 
        = vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_in_progress;
    __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_buffer_valid 
        = vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_buffer_valid;
    __Vdly__fpga_system_tb__DOT__u_ram__DOT__write_count 
        = vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_count;
    __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_address 
        = vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_address;
    __Vdly__fpga_system_tb__DOT__u_ram__DOT__write_address 
        = vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_address;
    __Vdlyvset__fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 = 0U;
    __Vdlyvset__fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 = 0U;
    __Vdly__fpga_system_tb__DOT__buffer_count = vlSelf->fpga_system_tb__DOT__buffer_count;
    __Vdly__fpga_system_tb__DOT__sample_count = vlSelf->fpga_system_tb__DOT__sample_count;
    __Vtableidx1 = (((IData)(vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__sck_ctr_q) 
                     << 2U) | (((IData)(vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__sck_q) 
                                << 1U) | (IData)(vlSelf->fpga_system_tb__DOT__rst_n)));
    vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__sck_ctr_q 
        = Vfpga_system_tb__ConstPool__TABLE_hb31b5e30_0
        [__Vtableidx1];
    if ((2U & Vfpga_system_tb__ConstPool__TABLE_h11502f1d_0
         [__Vtableidx1])) {
        __Vdly__fpga_system_tb__DOT__u_i2s_clock__DOT__sck_q 
            = Vfpga_system_tb__ConstPool__TABLE_h56c82868_0
            [__Vtableidx1];
    }
    if (vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram1_write_enable) {
        __Vdlyvval__fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 
            = vlSelf->fpga_system_tb__DOT__sample_left;
        __Vdlyvset__fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 = 1U;
        __Vdlyvdim0__fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0 
            = (0x1ffU & ((IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram1_address) 
                         >> 2U));
    }
    if (vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram0_write_enable) {
        __Vdlyvval__fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 
            = vlSelf->fpga_system_tb__DOT__sample_left;
        __Vdlyvset__fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 = 1U;
        __Vdlyvdim0__fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0 
            = (0x1ffU & ((IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram0_address) 
                         >> 2U));
    }
    if (VL_UNLIKELY(((IData)(vlSelf->fpga_system_tb__DOT__rst_n) 
                     & (IData)(vlSelf->fpga_system_tb__DOT__ram_overflow)))) {
        VL_WRITEF("[%0t] !!! RAM OVERFLOW DETECTED !!!\n",
                  64,VL_TIME_UNITED_Q(1000),-9);
        vlSelf->fpga_system_tb__DOT__error_count = 
            ((IData)(1U) + vlSelf->fpga_system_tb__DOT__error_count);
    }
    if (VL_UNLIKELY(((IData)(vlSelf->fpga_system_tb__DOT__rst_n) 
                     & (IData)(vlSelf->fpga_system_tb__DOT__ram_buffer_ready)))) {
        __Vdly__fpga_system_tb__DOT__buffer_count = 
            ((IData)(1U) + vlSelf->fpga_system_tb__DOT__buffer_count);
        VL_WRITEF("[%0t] *** BUFFER %0d READY *** (write_count=%0#, samples=%0d)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,((IData)(1U) 
                                                   + vlSelf->fpga_system_tb__DOT__buffer_count),
                  9,(IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_count),
                  32,vlSelf->fpga_system_tb__DOT__sample_count);
    }
    if (vlSelf->fpga_system_tb__DOT__rst_n) {
        if (vlSelf->fpga_system_tb__DOT__ram_read_valid) {
            vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__level_q 
                = ((vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__level_q 
                    - VL_SHIFTR_III(32,32,32, vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__level_q, 0xbU)) 
                   + VL_SHIFTR_III(32,32,32, (0xffffffU 
                                              & (((IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_buffer_valid) 
                                                  & (vlSelf->__VdfgTmp_h10302c67__0 
                                                     >> 0x17U))
                                                  ? 
                                                 ((IData)(1U) 
                                                  + 
                                                  (~ vlSelf->fpga_system_tb__DOT____Vcellinp__u_vu_meter__ram_read_data_i))
                                                  : vlSelf->fpga_system_tb__DOT____Vcellinp__u_vu_meter__ram_read_data_i)), 0xcU));
        }
    } else {
        vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__level_q = 0U;
    }
    if (VL_UNLIKELY(((IData)(vlSelf->fpga_system_tb__DOT__rst_n) 
                     & (IData)(vlSelf->fpga_system_tb__DOT__sample_ready)))) {
        __Vdly__fpga_system_tb__DOT__sample_count = 
            ((IData)(1U) + vlSelf->fpga_system_tb__DOT__sample_count);
        VL_WRITEF("[%0t] Sample %0d: L=0x%06x, R=0x%06x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,32,((IData)(1U) 
                                                   + vlSelf->fpga_system_tb__DOT__sample_count),
                  24,vlSelf->fpga_system_tb__DOT__sample_left,
                  24,vlSelf->fpga_system_tb__DOT__sample_right);
    }
    if ((1U & (~ (IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram1_write_enable)))) {
        vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram1_data_out 
            = vlSelf->fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__mem
            [(0x1ffU & ((IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram1_address) 
                        >> 2U))];
    }
    if ((1U & (~ (IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram0_write_enable)))) {
        vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram0_data_out 
            = vlSelf->fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__mem
            [(0x1ffU & ((IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram0_address) 
                        >> 2U))];
    }
    vlSelf->fpga_system_tb__DOT__u_sampler__DOT__ws_d 
        = ((IData)(vlSelf->fpga_system_tb__DOT__rst_n) 
           && (IData)(vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__ws_q));
    vlSelf->fpga_system_tb__DOT__leds_prev = vlSelf->fpga_system_tb__DOT__leds;
    if (vlSelf->fpga_system_tb__DOT__rst_n) {
        vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__frame_start_q = 0U;
        if (((~ (IData)(vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__sck_q)) 
             & (IData)(vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__sck_prev_q))) {
            if ((0x1fU == (IData)(vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__ws_ctr_q))) {
                __Vdly__fpga_system_tb__DOT__u_i2s_clock__DOT__ws_q 
                    = (1U & (~ (IData)(vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__ws_q)));
                __Vdly__fpga_system_tb__DOT__u_i2s_clock__DOT__ws_ctr_q = 0U;
                if (vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__ws_q) {
                    vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__frame_start_q = 1U;
                }
            } else {
                __Vdly__fpga_system_tb__DOT__u_i2s_clock__DOT__ws_ctr_q 
                    = (0x3fU & ((IData)(1U) + (IData)(vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__ws_ctr_q)));
            }
        }
        vlSelf->fpga_system_tb__DOT__ram_buffer_ready = 0U;
        vlSelf->fpga_system_tb__DOT__ram_overflow = 0U;
        if (((0x20U == (IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_count)) 
             & (~ (IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_in_progress)))) {
            vlSelf->fpga_system_tb__DOT__ram_buffer_ready = 1U;
            __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_buffer_valid = 1U;
            __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_in_progress = 1U;
            vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_buffer_sel 
                = vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_buffer_sel;
            __Vdly__fpga_system_tb__DOT__u_ram__DOT__write_address = 0U;
            __Vdly__fpga_system_tb__DOT__u_ram__DOT__write_count = 0U;
            __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_address = 0U;
            __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_count = 0U;
            vlSelf->fpga_system_tb__DOT__ram_read_valid = 0U;
            vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_buffer_sel 
                = (1U & (~ (IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_buffer_sel)));
        } else {
            if (((IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_accepted) 
                 & (IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_buffer_valid))) {
                if ((0x1fU > (IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_count))) {
                    __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_address 
                        = (0x1fU & ((IData)(1U) + (IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_address)));
                    __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_count 
                        = (0x3fU & ((IData)(1U) + (IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_count)));
                } else {
                    __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_in_progress = 0U;
                    __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_count = 0U;
                    __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_address = 0U;
                }
            }
            if (vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_accepted) {
                if ((0x20U > (IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_count))) {
                    __Vdly__fpga_system_tb__DOT__u_ram__DOT__write_address 
                        = (0x1fU & ((IData)(1U) + (IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_address)));
                    __Vdly__fpga_system_tb__DOT__u_ram__DOT__write_count 
                        = (0x3fU & ((IData)(1U) + (IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_count)));
                } else {
                    vlSelf->fpga_system_tb__DOT__ram_overflow = 1U;
                }
            }
            vlSelf->fpga_system_tb__DOT__ram_read_valid 
                = ((IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_buffer_valid) 
                   & (IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_in_progress));
        }
        vlSelf->fpga_system_tb__DOT__sample_ready = 0U;
        if ((0x19U == (IData)(vlSelf->fpga_system_tb__DOT__u_sampler__DOT__cnt_q))) {
            if (vlSelf->fpga_system_tb__DOT__u_sampler__DOT__channel_q) {
                vlSelf->fpga_system_tb__DOT__sample_right 
                    = (0xffffffU & vlSelf->fpga_system_tb__DOT__u_sampler__DOT__shift25_q);
                __Vdly__fpga_system_tb__DOT__u_sampler__DOT__right_done_q = 1U;
            } else {
                vlSelf->fpga_system_tb__DOT__sample_left 
                    = (0xffffffU & vlSelf->fpga_system_tb__DOT__u_sampler__DOT__shift25_q);
                __Vdly__fpga_system_tb__DOT__u_sampler__DOT__left_done_q = 1U;
            }
        }
        if (vlSelf->fpga_system_tb__DOT__u_sampler__DOT__ws_edge) {
            __Vdly__fpga_system_tb__DOT__u_sampler__DOT__cnt_q = 0U;
            __Vdly__fpga_system_tb__DOT__u_sampler__DOT__shift25_q = 0U;
            vlSelf->fpga_system_tb__DOT__u_sampler__DOT__channel_q 
                = vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__ws_q;
        } else if (((~ (IData)(vlSelf->fpga_system_tb__DOT__u_sampler__DOT__sck_d)) 
                    & (IData)(vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__sck_q))) {
            if ((0x19U > (IData)(vlSelf->fpga_system_tb__DOT__u_sampler__DOT__cnt_q))) {
                __Vdly__fpga_system_tb__DOT__u_sampler__DOT__shift25_q 
                    = ((0x1fffffeU & (vlSelf->fpga_system_tb__DOT__u_sampler__DOT__shift25_q 
                                      << 1U)) | (IData)(vlSelf->fpga_system_tb__DOT__mic_sd));
                __Vdly__fpga_system_tb__DOT__u_sampler__DOT__cnt_q 
                    = (0x3fU & ((IData)(1U) + (IData)(vlSelf->fpga_system_tb__DOT__u_sampler__DOT__cnt_q)));
            }
        }
        if (((IData)(vlSelf->fpga_system_tb__DOT__u_sampler__DOT__left_done_q) 
             & (IData)(vlSelf->fpga_system_tb__DOT__u_sampler__DOT__right_done_q))) {
            vlSelf->fpga_system_tb__DOT__sample_ready = 1U;
            __Vdly__fpga_system_tb__DOT__u_sampler__DOT__left_done_q = 0U;
            __Vdly__fpga_system_tb__DOT__u_sampler__DOT__right_done_q = 0U;
        }
        if (vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__tick) {
            vlSelf->fpga_system_tb__DOT__leds = vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__leds_next;
        }
        if ((0x3e7U == (IData)(vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__div_q))) {
            __Vdly__fpga_system_tb__DOT__u_vu_meter__DOT__div_q = 0U;
            vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__tick = 1U;
        } else {
            __Vdly__fpga_system_tb__DOT__u_vu_meter__DOT__div_q 
                = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__div_q)));
            vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__tick = 0U;
        }
    } else {
        __Vdly__fpga_system_tb__DOT__u_i2s_clock__DOT__ws_ctr_q = 0U;
        __Vdly__fpga_system_tb__DOT__u_i2s_clock__DOT__ws_q = 0U;
        vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__frame_start_q = 0U;
        vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_buffer_sel = 0U;
        __Vdly__fpga_system_tb__DOT__u_ram__DOT__write_address = 0U;
        __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_address = 0U;
        __Vdly__fpga_system_tb__DOT__u_ram__DOT__write_count = 0U;
        __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_count = 0U;
        vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_buffer_sel = 1U;
        __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_buffer_valid = 0U;
        __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_in_progress = 0U;
        vlSelf->fpga_system_tb__DOT__ram_buffer_ready = 0U;
        vlSelf->fpga_system_tb__DOT__ram_overflow = 0U;
        vlSelf->fpga_system_tb__DOT__ram_read_valid = 0U;
        __Vdly__fpga_system_tb__DOT__u_sampler__DOT__left_done_q = 0U;
        __Vdly__fpga_system_tb__DOT__u_sampler__DOT__right_done_q = 0U;
        __Vdly__fpga_system_tb__DOT__u_sampler__DOT__shift25_q = 0U;
        __Vdly__fpga_system_tb__DOT__u_sampler__DOT__cnt_q = 0U;
        vlSelf->fpga_system_tb__DOT__sample_left = 0U;
        vlSelf->fpga_system_tb__DOT__sample_right = 0U;
        vlSelf->fpga_system_tb__DOT__sample_ready = 0U;
        vlSelf->fpga_system_tb__DOT__leds = 0U;
        vlSelf->fpga_system_tb__DOT__u_sampler__DOT__channel_q = 0U;
        __Vdly__fpga_system_tb__DOT__u_vu_meter__DOT__div_q = 0U;
        vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__tick = 0U;
    }
    vlSelf->fpga_system_tb__DOT__buffer_count = __Vdly__fpga_system_tb__DOT__buffer_count;
    vlSelf->fpga_system_tb__DOT__sample_count = __Vdly__fpga_system_tb__DOT__sample_count;
    if (__Vdlyvset__fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0) {
        vlSelf->fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__mem[__Vdlyvdim0__fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0] 
            = __Vdlyvval__fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__mem__v0;
    }
    if (__Vdlyvset__fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0) {
        vlSelf->fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__mem[__Vdlyvdim0__fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0] 
            = __Vdlyvval__fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__mem__v0;
    }
    vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__ws_ctr_q 
        = __Vdly__fpga_system_tb__DOT__u_i2s_clock__DOT__ws_ctr_q;
    vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__sck_prev_q 
        = ((IData)(vlSelf->fpga_system_tb__DOT__rst_n) 
           && (IData)(vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__sck_q));
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_in_progress 
        = __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_in_progress;
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_count 
        = __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_count;
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_buffer_valid 
        = __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_buffer_valid;
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_count 
        = __Vdly__fpga_system_tb__DOT__u_ram__DOT__write_count;
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_address 
        = __Vdly__fpga_system_tb__DOT__u_ram__DOT__write_address;
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_address 
        = __Vdly__fpga_system_tb__DOT__u_ram__DOT__read_address;
    vlSelf->fpga_system_tb__DOT__u_sampler__DOT__cnt_q 
        = __Vdly__fpga_system_tb__DOT__u_sampler__DOT__cnt_q;
    vlSelf->fpga_system_tb__DOT__u_sampler__DOT__shift25_q 
        = __Vdly__fpga_system_tb__DOT__u_sampler__DOT__shift25_q;
    vlSelf->fpga_system_tb__DOT__u_sampler__DOT__right_done_q 
        = __Vdly__fpga_system_tb__DOT__u_sampler__DOT__right_done_q;
    vlSelf->fpga_system_tb__DOT__u_sampler__DOT__left_done_q 
        = __Vdly__fpga_system_tb__DOT__u_sampler__DOT__left_done_q;
    vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__leds_next 
        = ((0x38U & (IData)(vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__leds_next)) 
           | (((0x2328U < vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__level_q) 
               << 2U) | (((0xbb8U < vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__level_q) 
                          << 1U) | (0x3e8U < vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__level_q))));
    vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__leds_next 
        = ((7U & (IData)(vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__leds_next)) 
           | (((0x13880U < vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__level_q) 
               << 5U) | (((0x9c40U < vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__level_q) 
                          << 4U) | ((0x4e20U < vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__level_q) 
                                    << 3U))));
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_accepted 
        = vlSelf->fpga_system_tb__DOT__ram_read_valid;
    vlSelf->__VdfgTmp_h10302c67__0 = ((IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_buffer_sel)
                                       ? vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram1_data_out
                                       : vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram0_data_out);
    if (vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_buffer_sel) {
        vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__4__addr 
            = vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_address;
        vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__4__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__4__addr) 
               << 5U);
        vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram0_address 
            = vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__4__Vfuncout;
        vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__5__addr 
            = vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_address;
        vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__5__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__5__addr) 
               << 5U);
        vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram1_address 
            = vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__5__Vfuncout;
    } else {
        vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__6__addr 
            = vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_address;
        vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__6__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__6__addr) 
               << 5U);
        vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram0_address 
            = vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__6__Vfuncout;
        vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__7__addr 
            = vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_address;
        vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__7__Vfuncout 
            = ((IData)(vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__7__addr) 
               << 5U);
        vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram1_address 
            = vlSelf->__Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__7__Vfuncout;
    }
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_accepted 
        = ((0x20U > (IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_count)) 
           & (IData)(vlSelf->fpga_system_tb__DOT__sample_ready));
    vlSelf->fpga_system_tb__DOT__u_sampler__DOT__sck_d 
        = ((IData)(vlSelf->fpga_system_tb__DOT__rst_n) 
           && (IData)(vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__sck_q));
    if (((IData)(vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__sck_q) 
         & (~ (IData)(vlSelf->fpga_system_tb__DOT__sck_prev)))) {
        if ((0U == (IData)(vlSelf->fpga_system_tb__DOT__bit_counter))) {
            __Vdly__fpga_system_tb__DOT__mic_shift_reg 
                = (0x1ffffffU & (IData)((QData)((IData)(
                                                        VL_RANDOM_I()))));
        }
        vlSelf->fpga_system_tb__DOT__mic_sd = (1U & 
                                               (vlSelf->fpga_system_tb__DOT__mic_shift_reg 
                                                >> 0x18U));
        __Vdly__fpga_system_tb__DOT__mic_shift_reg 
            = (0x1fffffeU & (vlSelf->fpga_system_tb__DOT__mic_shift_reg 
                             << 1U));
        __Vdly__fpga_system_tb__DOT__bit_counter = 
            (0x1fU & ((IData)(1U) + (IData)(vlSelf->fpga_system_tb__DOT__bit_counter)));
        if ((0x18U <= (IData)(vlSelf->fpga_system_tb__DOT__bit_counter))) {
            __Vdly__fpga_system_tb__DOT__bit_counter = 0U;
        }
    }
    vlSelf->fpga_system_tb__DOT____Vcellinp__u_vu_meter__ram_read_data_i 
        = ((IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__read_buffer_valid)
            ? (0xffffffU & vlSelf->__VdfgTmp_h10302c67__0)
            : 0U);
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram0_write_enable 
        = ((~ (IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_buffer_sel)) 
           & (IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_accepted));
    vlSelf->fpga_system_tb__DOT__u_ram__DOT__ram1_write_enable 
        = ((IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_accepted) 
           & (IData)(vlSelf->fpga_system_tb__DOT__u_ram__DOT__write_buffer_sel));
    vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__ws_q 
        = __Vdly__fpga_system_tb__DOT__u_i2s_clock__DOT__ws_q;
    vlSelf->fpga_system_tb__DOT__mic_shift_reg = __Vdly__fpga_system_tb__DOT__mic_shift_reg;
    vlSelf->fpga_system_tb__DOT__bit_counter = __Vdly__fpga_system_tb__DOT__bit_counter;
    vlSelf->fpga_system_tb__DOT__u_vu_meter__DOT__div_q 
        = __Vdly__fpga_system_tb__DOT__u_vu_meter__DOT__div_q;
    vlSelf->fpga_system_tb__DOT__u_sampler__DOT__ws_edge 
        = ((IData)(vlSelf->fpga_system_tb__DOT__u_sampler__DOT__ws_d) 
           != (IData)(vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__ws_q));
    vlSelf->fpga_system_tb__DOT__sck_prev = vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__sck_q;
    vlSelf->fpga_system_tb__DOT__u_i2s_clock__DOT__sck_q 
        = __Vdly__fpga_system_tb__DOT__u_i2s_clock__DOT__sck_q;
}

void Vfpga_system_tb___024root___eval_nba(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vfpga_system_tb___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
}

void Vfpga_system_tb___024root___timing_resume(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___timing_resume\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_ha159ce0d__0.resume("@(posedge fpga_system_tb.clk)");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vfpga_system_tb___024root___timing_commit(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_ha159ce0d__0.commit("@(posedge fpga_system_tb.clk)");
    }
}

void Vfpga_system_tb___024root___eval_triggers__act(Vfpga_system_tb___024root* vlSelf);

bool Vfpga_system_tb___024root___eval_phase__act(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vfpga_system_tb___024root___eval_triggers__act(vlSelf);
    Vfpga_system_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vfpga_system_tb___024root___timing_resume(vlSelf);
        Vfpga_system_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vfpga_system_tb___024root___eval_phase__nba(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vfpga_system_tb___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpga_system_tb___024root___dump_triggers__nba(Vfpga_system_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfpga_system_tb___024root___dump_triggers__act(Vfpga_system_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vfpga_system_tb___024root___eval(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vfpga_system_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("fpga_system_tb.sv", 11, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vfpga_system_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("fpga_system_tb.sv", 11, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vfpga_system_tb___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vfpga_system_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vfpga_system_tb___024root___eval_debug_assertions(Vfpga_system_tb___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfpga_system_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfpga_system_tb___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
