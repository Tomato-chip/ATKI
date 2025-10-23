// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsp_ram_simple_tb__Syms.h"


void Vsp_ram_simple_tb___024root__trace_chg_0_sub_0(Vsp_ram_simple_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vsp_ram_simple_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root__trace_chg_0\n"); );
    // Init
    Vsp_ram_simple_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsp_ram_simple_tb___024root*>(voidSelf);
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vsp_ram_simple_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vsp_ram_simple_tb___024root__trace_chg_0_sub_0(Vsp_ram_simple_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+0,(vlSelf->sp_ram_simple_tb__DOT__rst_n));
        bufp->chgSData(oldp+1,(vlSelf->sp_ram_simple_tb__DOT__sample_in),16);
        bufp->chgBit(oldp+2,(vlSelf->sp_ram_simple_tb__DOT__sample_ready));
        bufp->chgIData(oldp+3,(vlSelf->sp_ram_simple_tb__DOT__sample_count),32);
        bufp->chgIData(oldp+4,(vlSelf->sp_ram_simple_tb__DOT__cycle_count),32);
        bufp->chgBit(oldp+5,((1U & (~ (IData)(vlSelf->sp_ram_simple_tb__DOT__rst_n)))));
        bufp->chgIData(oldp+6,(vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__buffer),32);
        bufp->chgIData(oldp+7,(vlSelf->sp_ram_simple_tb__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgSData(oldp+8,(vlSelf->sp_ram_simple_tb__DOT__read_data),16);
        bufp->chgBit(oldp+9,(vlSelf->sp_ram_simple_tb__DOT__buffer_ready));
        bufp->chgSData(oldp+10,(vlSelf->sp_ram_simple_tb__DOT__read_data_prev),16);
        bufp->chgCData(oldp+11,(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_address),8);
        bufp->chgCData(oldp+12,(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__read_address),8);
        bufp->chgBit(oldp+13,(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__rw_sel));
        bufp->chgBit(oldp+14,(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__rw_sel_read));
        bufp->chgBit(oldp+15,(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__valid_read_out));
        bufp->chgSData(oldp+16,(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__address_RAM_0),14);
        bufp->chgSData(oldp+17,(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__address_RAM_1),14);
        bufp->chgSData(oldp+18,(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__data_out_RAM_0),16);
        bufp->chgSData(oldp+19,(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__data_out_RAM_1),16);
        bufp->chgSData(oldp+20,(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__data_out_reg),16);
        bufp->chgSData(oldp+21,(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__data_out_reg),16);
    }
    bufp->chgBit(oldp+22,(vlSelf->sp_ram_simple_tb__DOT__clk));
    bufp->chgBit(oldp+23,(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__buffer_full));
    bufp->chgBit(oldp+24,(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_enable_RAM_0));
    bufp->chgBit(oldp+25,(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__write_enable_RAM_1));
    bufp->chgIData(oldp+26,(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram0__DOT__i),32);
    bufp->chgIData(oldp+27,(vlSelf->sp_ram_simple_tb__DOT__dut__DOT__u_ram1__DOT__i),32);
}

void Vsp_ram_simple_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsp_ram_simple_tb___024root__trace_cleanup\n"); );
    // Init
    Vsp_ram_simple_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsp_ram_simple_tb___024root*>(voidSelf);
    Vsp_ram_simple_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
