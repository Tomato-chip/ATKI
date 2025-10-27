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
        CData/*0:0*/ fpga_template_top_tb__DOT__btn_s2;
        CData/*0:0*/ fpga_template_top_tb__DOT__buffer_full;
        CData/*0:0*/ fpga_template_top_tb__DOT__mic_sd_0;
        CData/*5:0*/ fpga_template_top_tb__DOT__bit_counter;
        CData/*0:0*/ fpga_template_top_tb__DOT__sck_prev;
        CData/*0:0*/ fpga_template_top_tb__DOT__ws_prev_mic;
        CData/*0:0*/ fpga_template_top_tb__DOT__is_left_channel;
        CData/*0:0*/ fpga_template_top_tb__DOT__sck_prev_mon;
        CData/*0:0*/ fpga_template_top_tb__DOT__ws_prev;
        CData/*5:0*/ fpga_template_top_tb__DOT__debug_led_prev;
        CData/*5:0*/ fpga_template_top_tb__DOT__dut__DOT__debug_sample_led;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__sampler_to_ram_write_request_w;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_read_valid_w;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__sck_d;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__ws_d;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__ws_edge;
        CData/*5:0*/ fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__cnt_q;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__left_done_q;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__right_done_q;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_sampler__DOT__channel_q;
        CData/*7:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_address;
        CData/*7:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_address;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_buffer_sel;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_sel;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_buffer_valid;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_in_progress;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_accepted;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_accepted;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_write_enable;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_write_enable;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__vu__DOT__tick;
        CData/*5:0*/ fpga_template_top_tb__DOT__dut__DOT__vu__DOT__leds_next;
        CData/*2:0*/ fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_ctr_q;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_q;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_tick;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__sck_prev_q;
        CData/*5:0*/ fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_ctr_q;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__ws_q;
        CData/*0:0*/ fpga_template_top_tb__DOT__dut__DOT__u_i2s_clock__DOT__frame_start_q;
        CData/*7:0*/ __Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__10__addr;
        CData/*7:0*/ __Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__11__addr;
        CData/*7:0*/ __Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__12__addr;
        CData/*7:0*/ __Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__13__addr;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__fpga_template_top_tb__DOT__dut__DOT__ram_to_6led_buffer_ready_w__0;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactContinue;
        SData/*8:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__write_count;
        SData/*8:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__read_count;
        SData/*13:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram0_address;
        SData/*13:0*/ fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__ram1_address;
        SData/*13:0*/ __Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__10__Vfuncout;
        SData/*13:0*/ __Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__11__Vfuncout;
        SData/*13:0*/ __Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__12__Vfuncout;
        SData/*13:0*/ __Vfunc_fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__pack_address__13__Vfuncout;
        IData/*31:0*/ fpga_template_top_tb__DOT__error_count;
        IData/*24:0*/ fpga_template_top_tb__DOT__mic_shift_reg;
        IData/*31:0*/ fpga_template_top_tb__DOT__sample_number;
        IData/*23:0*/ fpga_template_top_tb__DOT__test_sample;
        IData/*31:0*/ fpga_template_top_tb__DOT__sck_edge_count;
    };
    struct {
        IData/*31:0*/ fpga_template_top_tb__DOT__ws_transition_count;
        IData/*31:0*/ fpga_template_top_tb__DOT__captured_sample_count;
        IData/*31:0*/ fpga_template_top_tb__DOT__buffer_swap_count;
        IData/*31:0*/ fpga_template_top_tb__DOT____Vrepeat2;
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
        IData/*31:0*/ __VdfgTmp_hb1fddee5__0;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 512> fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram0__DOT__mem;
        VlUnpacked<IData/*31:0*/, 512> fpga_template_top_tb__DOT__dut__DOT__u_ram__DOT__u_ram1__DOT__mem;
        VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h52ecb243__0;
    VlTriggerScheduler __VtrigSched_hbe0e6d50__0;
    VlForkSync __Vfork_1__sync;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

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
