// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsp_ram_simple_tb.h for the primary calling header

#ifndef VERILATED_VSP_RAM_SIMPLE_TB___024ROOT_H_
#define VERILATED_VSP_RAM_SIMPLE_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vsp_ram_simple_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsp_ram_simple_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ sp_ram_simple_tb__DOT__clk;
    CData/*0:0*/ sp_ram_simple_tb__DOT__rst_n;
    CData/*0:0*/ sp_ram_simple_tb__DOT__sample_ready;
    CData/*0:0*/ sp_ram_simple_tb__DOT__buffer_ready;
    CData/*7:0*/ sp_ram_simple_tb__DOT__dut__DOT__write_address;
    CData/*7:0*/ sp_ram_simple_tb__DOT__dut__DOT__read_address;
    CData/*0:0*/ sp_ram_simple_tb__DOT__dut__DOT__rw_sel;
    CData/*0:0*/ sp_ram_simple_tb__DOT__dut__DOT__rw_sel_read;
    CData/*0:0*/ sp_ram_simple_tb__DOT__dut__DOT__valid_read_out;
    CData/*0:0*/ sp_ram_simple_tb__DOT__dut__DOT__buffer_full;
    CData/*0:0*/ sp_ram_simple_tb__DOT__dut__DOT__write_enable_RAM_0;
    CData/*0:0*/ sp_ram_simple_tb__DOT__dut__DOT__write_enable_RAM_1;
    CData/*7:0*/ __Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__0__a8;
    CData/*7:0*/ __Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__1__a8;
    CData/*7:0*/ __Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__2__a8;
    CData/*7:0*/ __Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__3__a8;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__sp_ram_simple_tb__DOT__clk__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ sp_ram_simple_tb__DOT__sample_in;
    SData/*15:0*/ sp_ram_simple_tb__DOT__read_data;
    SData/*15:0*/ sp_ram_simple_tb__DOT__read_data_prev;
    SData/*13:0*/ sp_ram_simple_tb__DOT__dut__DOT__address_RAM_0;
    SData/*13:0*/ sp_ram_simple_tb__DOT__dut__DOT__address_RAM_1;
    SData/*15:0*/ sp_ram_simple_tb__DOT__dut__DOT__data_out_RAM_0;
    SData/*15:0*/ sp_ram_simple_tb__DOT__dut__DOT__data_out_RAM_1;
    SData/*15:0*/ sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__data_out_reg;
    SData/*15:0*/ sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__data_out_reg;
    SData/*13:0*/ __Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__0__Vfuncout;
    SData/*13:0*/ __Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__1__Vfuncout;
    SData/*13:0*/ __Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__2__Vfuncout;
    SData/*13:0*/ __Vfunc_sp_ram_simple_tb__DOT__dut__DOT__pack_addr__3__Vfuncout;
    IData/*31:0*/ sp_ram_simple_tb__DOT__sample_count;
    IData/*31:0*/ sp_ram_simple_tb__DOT__cycle_count;
    IData/*31:0*/ sp_ram_simple_tb__DOT__unnamedblk1__DOT__buffer;
    IData/*31:0*/ sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i;
    IData/*31:0*/ sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__i;
    IData/*31:0*/ sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__i;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<SData/*15:0*/, 16384> sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__mem;
    VlUnpacked<SData/*15:0*/, 16384> sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__mem;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h73fcac0b__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vsp_ram_simple_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsp_ram_simple_tb___024root(Vsp_ram_simple_tb__Syms* symsp, const char* v__name);
    ~Vsp_ram_simple_tb___024root();
    VL_UNCOPYABLE(Vsp_ram_simple_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
