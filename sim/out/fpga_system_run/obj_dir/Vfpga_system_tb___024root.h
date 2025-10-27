// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vfpga_system_tb.h for the primary calling header

#ifndef VERILATED_VFPGA_SYSTEM_TB___024ROOT_H_
#define VERILATED_VFPGA_SYSTEM_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vfpga_system_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vfpga_system_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ fpga_system_tb__DOT__clk;
        CData/*0:0*/ fpga_system_tb__DOT__rst_n;
        CData/*0:0*/ fpga_system_tb__DOT__mic_sd;
        CData/*5:0*/ fpga_system_tb__DOT__leds;
        CData/*0:0*/ fpga_system_tb__DOT__sample_ready;
        CData/*0:0*/ fpga_system_tb__DOT__ram_read_valid;
        CData/*0:0*/ fpga_system_tb__DOT__ram_buffer_ready;
        CData/*0:0*/ fpga_system_tb__DOT__ram_overflow;
        CData/*4:0*/ fpga_system_tb__DOT__bit_counter;
        CData/*0:0*/ fpga_system_tb__DOT__sck_prev;
        CData/*5:0*/ fpga_system_tb__DOT__leds_prev;
        CData/*2:0*/ fpga_system_tb__DOT__u_i2s_clock__DOT__sck_ctr_q;
        CData/*0:0*/ fpga_system_tb__DOT__u_i2s_clock__DOT__sck_q;
        CData/*0:0*/ fpga_system_tb__DOT__u_i2s_clock__DOT__sck_tick;
        CData/*0:0*/ fpga_system_tb__DOT__u_i2s_clock__DOT__sck_prev_q;
        CData/*5:0*/ fpga_system_tb__DOT__u_i2s_clock__DOT__ws_ctr_q;
        CData/*0:0*/ fpga_system_tb__DOT__u_i2s_clock__DOT__ws_q;
        CData/*0:0*/ fpga_system_tb__DOT__u_i2s_clock__DOT__frame_start_q;
        CData/*0:0*/ fpga_system_tb__DOT__u_sampler__DOT__sck_d;
        CData/*0:0*/ fpga_system_tb__DOT__u_sampler__DOT__ws_d;
        CData/*0:0*/ fpga_system_tb__DOT__u_sampler__DOT__ws_edge;
        CData/*5:0*/ fpga_system_tb__DOT__u_sampler__DOT__cnt_q;
        CData/*0:0*/ fpga_system_tb__DOT__u_sampler__DOT__left_done_q;
        CData/*0:0*/ fpga_system_tb__DOT__u_sampler__DOT__right_done_q;
        CData/*0:0*/ fpga_system_tb__DOT__u_sampler__DOT__channel_q;
        CData/*4:0*/ fpga_system_tb__DOT__u_ram__DOT__write_address;
        CData/*4:0*/ fpga_system_tb__DOT__u_ram__DOT__read_address;
        CData/*5:0*/ fpga_system_tb__DOT__u_ram__DOT__write_count;
        CData/*5:0*/ fpga_system_tb__DOT__u_ram__DOT__read_count;
        CData/*0:0*/ fpga_system_tb__DOT__u_ram__DOT__write_buffer_sel;
        CData/*0:0*/ fpga_system_tb__DOT__u_ram__DOT__read_buffer_sel;
        CData/*0:0*/ fpga_system_tb__DOT__u_ram__DOT__read_buffer_valid;
        CData/*0:0*/ fpga_system_tb__DOT__u_ram__DOT__read_in_progress;
        CData/*0:0*/ fpga_system_tb__DOT__u_ram__DOT__write_accepted;
        CData/*0:0*/ fpga_system_tb__DOT__u_ram__DOT__read_accepted;
        CData/*0:0*/ fpga_system_tb__DOT__u_ram__DOT__ram0_write_enable;
        CData/*0:0*/ fpga_system_tb__DOT__u_ram__DOT__ram1_write_enable;
        CData/*0:0*/ fpga_system_tb__DOT__u_vu_meter__DOT__tick;
        CData/*5:0*/ fpga_system_tb__DOT__u_vu_meter__DOT__leds_next;
        CData/*4:0*/ __Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__4__addr;
        CData/*4:0*/ __Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__5__addr;
        CData/*4:0*/ __Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__6__addr;
        CData/*4:0*/ __Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__7__addr;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__fpga_system_tb__DOT__clk__0;
        CData/*0:0*/ __VactContinue;
        SData/*13:0*/ fpga_system_tb__DOT__u_ram__DOT__ram0_address;
        SData/*13:0*/ fpga_system_tb__DOT__u_ram__DOT__ram1_address;
        SData/*9:0*/ fpga_system_tb__DOT__u_vu_meter__DOT__div_q;
        SData/*13:0*/ __Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__4__Vfuncout;
        SData/*13:0*/ __Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__5__Vfuncout;
        SData/*13:0*/ __Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__6__Vfuncout;
        SData/*13:0*/ __Vfunc_fpga_system_tb__DOT__u_ram__DOT__pack_address__7__Vfuncout;
        IData/*23:0*/ fpga_system_tb__DOT__sample_left;
        IData/*23:0*/ fpga_system_tb__DOT__sample_right;
        IData/*31:0*/ fpga_system_tb__DOT__error_count;
        IData/*31:0*/ fpga_system_tb__DOT__buffer_count;
        IData/*31:0*/ fpga_system_tb__DOT__sample_count;
        IData/*23:0*/ fpga_system_tb__DOT____Vcellinp__u_vu_meter__ram_read_data_i;
        IData/*24:0*/ fpga_system_tb__DOT__mic_shift_reg;
        IData/*31:0*/ fpga_system_tb__DOT__unnamedblk1__DOT__start_buf_count;
        IData/*24:0*/ fpga_system_tb__DOT__u_sampler__DOT__shift25_q;
        IData/*31:0*/ fpga_system_tb__DOT__u_ram__DOT__ram0_data_out;
        IData/*31:0*/ fpga_system_tb__DOT__u_ram__DOT__ram1_data_out;
    };
    struct {
        IData/*31:0*/ fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__do_pipeline;
        IData/*31:0*/ fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__i;
        IData/*31:0*/ fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__do_pipeline;
        IData/*31:0*/ fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__i;
        IData/*31:0*/ fpga_system_tb__DOT__u_vu_meter__DOT__level_q;
        IData/*31:0*/ __VdfgTmp_h10302c67__0;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 512> fpga_system_tb__DOT__u_ram__DOT__u_ram0__DOT__mem;
        VlUnpacked<IData/*31:0*/, 512> fpga_system_tb__DOT__u_ram__DOT__u_ram1__DOT__mem;
        VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_ha159ce0d__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vfpga_system_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vfpga_system_tb___024root(Vfpga_system_tb__Syms* symsp, const char* v__name);
    ~Vfpga_system_tb___024root();
    VL_UNCOPYABLE(Vfpga_system_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
