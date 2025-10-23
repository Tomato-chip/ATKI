// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vpingpong_buffer_sp_tb_simple.h for the primary calling header

#ifndef VERILATED_VPINGPONG_BUFFER_SP_TB_SIMPLE___024ROOT_H_
#define VERILATED_VPINGPONG_BUFFER_SP_TB_SIMPLE___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vpingpong_buffer_sp_tb_simple__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vpingpong_buffer_sp_tb_simple___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ pingpong_buffer_sp_tb_simple__DOT__clk;
    CData/*0:0*/ pingpong_buffer_sp_tb_simple__DOT__rst_n;
    CData/*0:0*/ pingpong_buffer_sp_tb_simple__DOT__wr_valid;
    CData/*0:0*/ pingpong_buffer_sp_tb_simple__DOT__wr_ready;
    CData/*0:0*/ pingpong_buffer_sp_tb_simple__DOT__sample_ready;
    CData/*0:0*/ pingpong_buffer_sp_tb_simple__DOT__frame_start;
    CData/*0:0*/ pingpong_buffer_sp_tb_simple__DOT__rd_valid;
    CData/*0:0*/ pingpong_buffer_sp_tb_simple__DOT__rd_ready;
    CData/*0:0*/ pingpong_buffer_sp_tb_simple__DOT__buf_ready;
    CData/*0:0*/ pingpong_buffer_sp_tb_simple__DOT__buf_id;
    CData/*0:0*/ pingpong_buffer_sp_tb_simple__DOT__buf_take;
    CData/*0:0*/ pingpong_buffer_sp_tb_simple__DOT__buf_empty;
    CData/*0:0*/ pingpong_buffer_sp_tb_simple__DOT__overrun;
    CData/*0:0*/ pingpong_buffer_sp_tb_simple__DOT__underrun;
    CData/*0:0*/ pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_sel;
    CData/*0:0*/ pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_buf_sel;
    CData/*7:0*/ pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_addr;
    CData/*7:0*/ pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_addr;
    CData/*1:0*/ pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf0_state;
    CData/*1:0*/ pingpong_buffer_sp_tb_simple__DOT__dut__DOT__buf1_state;
    CData/*0:0*/ pingpong_buffer_sp_tb_simple__DOT__dut__DOT__sample_beat;
    CData/*0:0*/ pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wr_buf_complete;
    CData/*1:0*/ pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_state;
    CData/*0:0*/ pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_beat;
    CData/*0:0*/ pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_buf_complete;
    CData/*0:0*/ pingpong_buffer_sp_tb_simple__DOT__dut__DOT__rd_buf_has_data;
    CData/*0:0*/ pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wre_ram0;
    CData/*0:0*/ pingpong_buffer_sp_tb_simple__DOT__dut__DOT__wre_ram1;
    CData/*7:0*/ __Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__0__addr;
    CData/*7:0*/ __Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__1__addr;
    CData/*7:0*/ __Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__2__addr;
    CData/*7:0*/ __Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__3__addr;
    CData/*0:0*/ __VstlDidInit;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__clk__0;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ pingpong_buffer_sp_tb_simple__DOT__wr_data;
    SData/*15:0*/ pingpong_buffer_sp_tb_simple__DOT__expected_data;
    SData/*13:0*/ pingpong_buffer_sp_tb_simple__DOT__dut__DOT__addr_ram0;
    SData/*13:0*/ pingpong_buffer_sp_tb_simple__DOT__dut__DOT__addr_ram1;
    SData/*13:0*/ __Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__0__Vfuncout;
    SData/*13:0*/ __Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__1__Vfuncout;
    SData/*13:0*/ __Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__2__Vfuncout;
    SData/*13:0*/ __Vfunc_pingpong_buffer_sp_tb_simple__DOT__dut__DOT__pack_addr__3__Vfuncout;
    IData/*31:0*/ pingpong_buffer_sp_tb_simple__DOT__errors;
    IData/*31:0*/ pingpong_buffer_sp_tb_simple__DOT__words_written;
    IData/*31:0*/ pingpong_buffer_sp_tb_simple__DOT__words_read;
    IData/*31:0*/ pingpong_buffer_sp_tb_simple__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ pingpong_buffer_sp_tb_simple__DOT__unnamedblk2__DOT__i;
    IData/*31:0*/ pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram0__DO;
    IData/*31:0*/ pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram1__DO;
    IData/*31:0*/ pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__read_data;
    IData/*31:0*/ pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__i;
    IData/*31:0*/ pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__read_data;
    IData/*31:0*/ pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__i;
    IData/*31:0*/ __Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram0__DO__0;
    IData/*31:0*/ __Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram1__DO__0;
    IData/*31:0*/ __Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram0__DO__1;
    IData/*31:0*/ __Vtrigprevexpr___TOP__pingpong_buffer_sp_tb_simple__DOT__dut__DOT____Vcellout__u_ram1__DO__1;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 1024> pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram0__DOT__mem;
    VlUnpacked<IData/*31:0*/, 1024> pingpong_buffer_sp_tb_simple__DOT__dut__DOT__u_ram1__DOT__mem;
    VlUnpacked<CData/*0:0*/, 5> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h28b425f1__0;
    VlTriggerVec<3> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vpingpong_buffer_sp_tb_simple__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vpingpong_buffer_sp_tb_simple___024root(Vpingpong_buffer_sp_tb_simple__Syms* symsp, const char* v__name);
    ~Vpingpong_buffer_sp_tb_simple___024root();
    VL_UNCOPYABLE(Vpingpong_buffer_sp_tb_simple___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
