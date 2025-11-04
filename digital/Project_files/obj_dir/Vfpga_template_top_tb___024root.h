// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vfpga_template_top_tb.h for the primary calling header

#ifndef VERILATED_VFPGA_TEMPLATE_TOP_TB___024ROOT_H_
#define VERILATED_VFPGA_TEMPLATE_TOP_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vfpga_template_top_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vfpga_template_top_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ fpga_template_top_tb__DOT__clk;
        CData/*0:0*/ fpga_template_top_tb__DOT__btn_s1_resetb;
        CData/*0:0*/ fpga_template_top_tb__DOT__buffer_full;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__sampler_to_ram_write_request_w;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q;
        CData/*0:0*/ fpga_template_top_tb__DOT__btn_s2;
        CData/*0:0*/ fpga_template_top_tb__DOT__mic_sd_0;
        CData/*0:0*/ fpga_template_top_tb__DOT__monitor_handshake;
        CData/*0:0*/ fpga_template_top_tb__DOT__prev_sample_valid;
        CData/*5:0*/ fpga_template_top_tb__DOT__prev_leds;
        CData/*5:0*/ fpga_template_top_tb__DOT__dut__DOT__debug_sample_led;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_read_valid_w;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__ws_d;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__ws_edge;
        CData/*5:0*/ fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__right_done_q;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__channel_q;
        CData/*4:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address;
        CData/*4:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address;
        CData/*5:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count;
        CData/*5:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_sel;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_accepted;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_accepted;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_write_enable;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_write_enable;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__vu__DOT__sample_valid;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__vu__DOT__ram_ready_q;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__vu__DOT__processing_delay_q;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__vu__DOT__tick;
        CData/*5:0*/ fpga_template_top_tb__DOT__dut__DOT__vu__DOT__leds_next;
        CData/*2:0*/ fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_ctr_q;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_tick;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_prev_q;
        CData/*5:0*/ fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_ctr_q;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__frame_start_q;
        CData/*4:0*/ __Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__0__addr;
        CData/*4:0*/ __Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__1__addr;
        CData/*4:0*/ __Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__2__addr;
        CData/*4:0*/ __Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__3__addr;
        CData/*0:0*/ __Vdly__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__btn_s1_resetb__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__dut__DOT__sampler_to_ram_write_request_w__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__buffer_full__0;
        CData/*0:0*/ __Vtrigprevexpr_he4466ec5__0;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactContinue;
        SData/*13:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_address;
        SData/*13:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_address;
        SData/*13:0*/ __Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__0__Vfuncout;
        SData/*13:0*/ __Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__1__Vfuncout;
        SData/*13:0*/ __Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__2__Vfuncout;
        SData/*13:0*/ __Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__3__Vfuncout;
    };
    struct {
        IData/*31:0*/ fpga_template_top_tb__DOT__sample_count;
        IData/*31:0*/ fpga_template_top_tb__DOT__buffer_swap_count;
        IData/*31:0*/ fpga_template_top_tb__DOT__handshake_count;
        IData/*31:0*/ fpga_template_top_tb__DOT__ready_low_cycles;
        IData/*23:0*/ fpga_template_top_tb__DOT__test_audio_value;
        IData/*31:0*/ fpga_template_top_tb__DOT__bit_counter;
        IData/*24:0*/ fpga_template_top_tb__DOT__left_shift_reg;
        IData/*24:0*/ fpga_template_top_tb__DOT__right_shift_reg;
        IData/*23:0*/ fpga_template_top_tb__DOT__left_sample;
        IData/*23:0*/ fpga_template_top_tb__DOT__right_sample;
        IData/*23:0*/ fpga_template_top_tb__DOT__dut__DOT__sample_left;
        IData/*23:0*/ fpga_template_top_tb__DOT__dut__DOT__sample_right;
        IData/*23:0*/ fpga_template_top_tb__DOT__dut__DOT____Vcellinp__vu__ram_read_data_i;
        IData/*24:0*/ fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__shift25_q;
        IData/*31:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_data_out;
        IData/*31:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_data_out;
        IData/*31:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__do_pipeline;
        IData/*31:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__i;
        IData/*31:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__do_pipeline;
        IData/*31:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__i;
        IData/*31:0*/ fpga_template_top_tb__DOT__dut__DOT__vu__DOT__level_q;
        IData/*19:0*/ fpga_template_top_tb__DOT__dut__DOT__vu__DOT__div_q;
        IData/*31:0*/ fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_period_cycles;
        IData/*31:0*/ fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_last_toggle_time;
        IData/*31:0*/ __VdfgTmp_hb1fddee5__0;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 512> fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem;
        VlUnpacked<IData/*31:0*/, 512> fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem;
        VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h52ecb243__0;
    VlTriggerScheduler __VtrigSched_h904cec7c__0;
    VlTriggerScheduler __VtrigSched_ha0e3b59f__0;
    VlTriggerScheduler __VtrigSched_h21ee7aaa__0;
    VlTriggerScheduler __VtrigSched_hbe0e6ec5__0;
    VlTriggerScheduler __VtrigSched_h10a6e2e3__0;
    VlTriggerScheduler __VtrigSched_h43f1a8d3__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<9> __VactTriggered;
    VlTriggerVec<9> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vfpga_template_top_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vfpga_template_top_tb___024root(Vfpga_template_top_tb__Syms* symsp, const char* v__name);
    ~Vfpga_template_top_tb___024root();
    VL_UNCOPYABLE(Vfpga_template_top_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
