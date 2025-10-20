// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vpingpong_sp_ram_tb.h for the primary calling header

#ifndef VERILATED_VPINGPONG_SP_RAM_TB___024ROOT_H_
#define VERILATED_VPINGPONG_SP_RAM_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vpingpong_sp_ram_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vpingpong_sp_ram_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ pingpong_sp_ram_tb__DOT__clk_i;
    CData/*0:0*/ pingpong_sp_ram_tb__DOT__rst_ni;
    CData/*0:0*/ pingpong_sp_ram_tb__DOT__in_valid_i;
    CData/*0:0*/ pingpong_sp_ram_tb__DOT__rd_en_i;
    CData/*7:0*/ pingpong_sp_ram_tb__DOT__rd_addr_i;
    CData/*0:0*/ pingpong_sp_ram_tb__DOT__active_buf_o;
    CData/*0:0*/ pingpong_sp_ram_tb__DOT__buf_ready_pulse_o;
    CData/*0:0*/ pingpong_sp_ram_tb__DOT__buf_ready_id_o;
    CData/*7:0*/ pingpong_sp_ram_tb__DOT__dut__DOT__write_addr;
    CData/*0:0*/ pingpong_sp_ram_tb__DOT__dut__DOT__write_last;
    CData/*0:0*/ pingpong_sp_ram_tb__DOT__dut__DOT__we_a;
    CData/*0:0*/ pingpong_sp_ram_tb__DOT__dut__DOT__we_b;
    CData/*7:0*/ pingpong_sp_ram_tb__DOT__dut__DOT__addr_a;
    CData/*7:0*/ pingpong_sp_ram_tb__DOT__dut__DOT__addr_b;
    CData/*0:0*/ pingpong_sp_ram_tb__DOT__dut__DOT__rd_valid_q;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__pingpong_sp_ram_tb__DOT__clk_i__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ pingpong_sp_ram_tb__DOT__in_data_i;
    SData/*15:0*/ pingpong_sp_ram_tb__DOT__rd_data_o;
    IData/*31:0*/ pingpong_sp_ram_tb__DOT__errors;
    IData/*31:0*/ pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__do_pipe;
    IData/*31:0*/ pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__do_pipe;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 1024> pingpong_sp_ram_tb__DOT__dut__DOT__ram_a__DOT__mem;
    VlUnpacked<IData/*31:0*/, 1024> pingpong_sp_ram_tb__DOT__dut__DOT__ram_b__DOT__mem;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h6eefdb72__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vpingpong_sp_ram_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vpingpong_sp_ram_tb___024root(Vpingpong_sp_ram_tb__Syms* symsp, const char* v__name);
    ~Vpingpong_sp_ram_tb___024root();
    VL_UNCOPYABLE(Vpingpong_sp_ram_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
