// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vram_vu_handshake_tb.h for the primary calling header

#ifndef VERILATED_VRAM_VU_HANDSHAKE_TB___024ROOT_H_
#define VERILATED_VRAM_VU_HANDSHAKE_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vram_vu_handshake_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vram_vu_handshake_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ ram_vu_handshake_tb__DOT__clk;
    CData/*0:0*/ ram_vu_handshake_tb__DOT__rst_n;
    CData/*0:0*/ ram_vu_handshake_tb__DOT__sample_valid;
    CData/*0:0*/ ram_vu_handshake_tb__DOT__buffer_ready;
    CData/*0:0*/ ram_vu_handshake_tb__DOT__read_enable;
    CData/*0:0*/ ram_vu_handshake_tb__DOT__read_ack;
    CData/*5:0*/ ram_vu_handshake_tb__DOT__leds;
    CData/*7:0*/ ram_vu_handshake_tb__DOT__u_ram__DOT__write_address;
    CData/*7:0*/ ram_vu_handshake_tb__DOT__u_ram__DOT__read_address;
    CData/*0:0*/ ram_vu_handshake_tb__DOT__u_ram__DOT__write_buffer_sel;
    CData/*0:0*/ ram_vu_handshake_tb__DOT__u_ram__DOT__read_buffer_sel;
    CData/*0:0*/ ram_vu_handshake_tb__DOT__u_ram__DOT__valid_read_out;
    CData/*0:0*/ ram_vu_handshake_tb__DOT__u_ram__DOT__read_in_progress;
    CData/*0:0*/ ram_vu_handshake_tb__DOT__u_ram__DOT__buffer_full;
    CData/*1:0*/ ram_vu_handshake_tb__DOT__u_vu__DOT__read_state_q;
    CData/*0:0*/ ram_vu_handshake_tb__DOT__u_vu__DOT__read_req;
    CData/*0:0*/ ram_vu_handshake_tb__DOT__u_vu__DOT__tick;
    CData/*5:0*/ ram_vu_handshake_tb__DOT__u_vu__DOT__leds_next;
    CData/*7:0*/ __Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__0__a8;
    CData/*7:0*/ __Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__1__a8;
    CData/*7:0*/ __Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__2__a8;
    CData/*7:0*/ __Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__3__a8;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__ram_vu_handshake_tb__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr_hbeb878a1__0;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ ram_vu_handshake_tb__DOT__sample_data;
    SData/*15:0*/ ram_vu_handshake_tb__DOT__read_data;
    SData/*8:0*/ ram_vu_handshake_tb__DOT__u_ram__DOT__read_count;
    SData/*13:0*/ ram_vu_handshake_tb__DOT__u_ram__DOT__address_RAM_0;
    SData/*13:0*/ ram_vu_handshake_tb__DOT__u_ram__DOT__address_RAM_1;
    SData/*9:0*/ ram_vu_handshake_tb__DOT__u_vu__DOT__div_q;
    SData/*13:0*/ __Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__0__Vfuncout;
    SData/*13:0*/ __Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__1__Vfuncout;
    SData/*13:0*/ __Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__2__Vfuncout;
    SData/*13:0*/ __Vfunc_ram_vu_handshake_tb__DOT__u_ram__DOT__pack_addr__3__Vfuncout;
    IData/*31:0*/ ram_vu_handshake_tb__DOT__errors;
    IData/*31:0*/ ram_vu_handshake_tb__DOT__warnings;
    IData/*31:0*/ ram_vu_handshake_tb__DOT__sample_count;
    IData/*31:0*/ ram_vu_handshake_tb__DOT__read_count;
    IData/*31:0*/ ram_vu_handshake_tb__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ ram_vu_handshake_tb__DOT__unnamedblk2__DOT__i;
    IData/*31:0*/ ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__do_reg;
    IData/*31:0*/ ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__do_pipe;
    IData/*31:0*/ ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__i;
    IData/*31:0*/ ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__do_reg;
    IData/*31:0*/ ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__do_pipe;
    IData/*31:0*/ ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__i;
    IData/*31:0*/ ram_vu_handshake_tb__DOT__u_vu__DOT__level_q;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 1024> ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram0__DOT__mem;
    VlUnpacked<IData/*31:0*/, 1024> ram_vu_handshake_tb__DOT__u_ram__DOT__u_ram1__DOT__mem;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h62688261__0;
    VlTriggerScheduler __VtrigSched_h267faeff__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vram_vu_handshake_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vram_vu_handshake_tb___024root(Vram_vu_handshake_tb__Syms* symsp, const char* v__name);
    ~Vram_vu_handshake_tb___024root();
    VL_UNCOPYABLE(Vram_vu_handshake_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
