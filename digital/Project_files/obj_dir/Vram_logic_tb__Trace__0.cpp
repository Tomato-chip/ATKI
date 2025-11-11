// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vram_logic_tb__Syms.h"


void Vram_logic_tb___024root__trace_chg_0_sub_0(Vram_logic_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vram_logic_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root__trace_chg_0\n"); );
    // Init
    Vram_logic_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vram_logic_tb___024root*>(voidSelf);
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vram_logic_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vram_logic_tb___024root__trace_chg_0_sub_0(Vram_logic_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+0,(vlSelf->ram_logic_tb__DOT__rst_n));
        bufp->chgIData(oldp+1,(vlSelf->ram_logic_tb__DOT__test_passed),32);
        bufp->chgIData(oldp+2,(vlSelf->ram_logic_tb__DOT__test_data[0]),32);
        bufp->chgIData(oldp+3,(vlSelf->ram_logic_tb__DOT__test_data[1]),32);
        bufp->chgIData(oldp+4,(vlSelf->ram_logic_tb__DOT__test_data[2]),32);
        bufp->chgIData(oldp+5,(vlSelf->ram_logic_tb__DOT__test_data[3]),32);
        bufp->chgIData(oldp+6,(vlSelf->ram_logic_tb__DOT__test_data[4]),32);
        bufp->chgIData(oldp+7,(vlSelf->ram_logic_tb__DOT__test_data[5]),32);
        bufp->chgIData(oldp+8,(vlSelf->ram_logic_tb__DOT__test_data[6]),32);
        bufp->chgIData(oldp+9,(vlSelf->ram_logic_tb__DOT__test_data[7]),32);
        bufp->chgIData(oldp+10,(vlSelf->ram_logic_tb__DOT__test_data[8]),32);
        bufp->chgIData(oldp+11,(vlSelf->ram_logic_tb__DOT__test_data[9]),32);
        bufp->chgIData(oldp+12,(vlSelf->ram_logic_tb__DOT__test_data[10]),32);
        bufp->chgIData(oldp+13,(vlSelf->ram_logic_tb__DOT__test_data[11]),32);
        bufp->chgIData(oldp+14,(vlSelf->ram_logic_tb__DOT__test_data[12]),32);
        bufp->chgIData(oldp+15,(vlSelf->ram_logic_tb__DOT__test_data[13]),32);
        bufp->chgIData(oldp+16,(vlSelf->ram_logic_tb__DOT__test_data[14]),32);
        bufp->chgIData(oldp+17,(vlSelf->ram_logic_tb__DOT__test_data[15]),32);
        bufp->chgIData(oldp+18,(vlSelf->ram_logic_tb__DOT__read_back[0]),32);
        bufp->chgIData(oldp+19,(vlSelf->ram_logic_tb__DOT__read_back[1]),32);
        bufp->chgIData(oldp+20,(vlSelf->ram_logic_tb__DOT__read_back[2]),32);
        bufp->chgIData(oldp+21,(vlSelf->ram_logic_tb__DOT__read_back[3]),32);
        bufp->chgIData(oldp+22,(vlSelf->ram_logic_tb__DOT__read_back[4]),32);
        bufp->chgIData(oldp+23,(vlSelf->ram_logic_tb__DOT__read_back[5]),32);
        bufp->chgIData(oldp+24,(vlSelf->ram_logic_tb__DOT__read_back[6]),32);
        bufp->chgIData(oldp+25,(vlSelf->ram_logic_tb__DOT__read_back[7]),32);
        bufp->chgIData(oldp+26,(vlSelf->ram_logic_tb__DOT__read_back[8]),32);
        bufp->chgIData(oldp+27,(vlSelf->ram_logic_tb__DOT__read_back[9]),32);
        bufp->chgIData(oldp+28,(vlSelf->ram_logic_tb__DOT__read_back[10]),32);
        bufp->chgIData(oldp+29,(vlSelf->ram_logic_tb__DOT__read_back[11]),32);
        bufp->chgIData(oldp+30,(vlSelf->ram_logic_tb__DOT__read_back[12]),32);
        bufp->chgIData(oldp+31,(vlSelf->ram_logic_tb__DOT__read_back[13]),32);
        bufp->chgIData(oldp+32,(vlSelf->ram_logic_tb__DOT__read_back[14]),32);
        bufp->chgIData(oldp+33,(vlSelf->ram_logic_tb__DOT__read_back[15]),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgBit(oldp+34,((0x10U > (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q))));
        bufp->chgBit(oldp+35,(vlSelf->ram_logic_tb__DOT__read_valid));
        bufp->chgBit(oldp+36,(vlSelf->ram_logic_tb__DOT__buffer_ready));
        bufp->chgBit(oldp+37,(vlSelf->ram_logic_tb__DOT__buffer_overflow));
        bufp->chgCData(oldp+38,(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count_q),5);
        bufp->chgCData(oldp+39,(vlSelf->ram_logic_tb__DOT__dut__DOT__read_count_q),5);
        bufp->chgCData(oldp+40,(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q),2);
        bufp->chgCData(oldp+41,(vlSelf->ram_logic_tb__DOT__dut__DOT__state_d),2);
        bufp->chgCData(oldp+42,(vlSelf->ram_logic_tb__DOT__dut__DOT__write_addr_q),4);
        bufp->chgCData(oldp+43,(vlSelf->ram_logic_tb__DOT__dut__DOT__read_addr_q),4);
        bufp->chgBit(oldp+44,(vlSelf->ram_logic_tb__DOT__dut__DOT__write_buf_sel_q));
        bufp->chgBit(oldp+45,(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q));
        bufp->chgSData(oldp+46,(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr),14);
        bufp->chgSData(oldp+47,(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr),14);
        bufp->chgSData(oldp+48,((0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                                          >> 4U))),9);
        bufp->chgSData(oldp+49,((0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                                          >> 4U))),9);
    }
    bufp->chgBit(oldp+50,(vlSelf->ram_logic_tb__DOT__clk));
    bufp->chgIData(oldp+51,(vlSelf->ram_logic_tb__DOT__write_data),32);
    bufp->chgBit(oldp+52,(vlSelf->ram_logic_tb__DOT__write_valid));
    bufp->chgIData(oldp+53,(((2U == (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__state_q))
                              ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buf_sel_q)
                                  ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
                                 [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                                            >> 4U))]
                                  : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
                                 [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                                            >> 4U))])
                              : 0U)),32);
    bufp->chgBit(oldp+54,(vlSelf->ram_logic_tb__DOT__read_ready));
    bufp->chgIData(oldp+55,(vlSelf->ram_logic_tb__DOT__test_errors),32);
    bufp->chgBit(oldp+56,(vlSelf->ram_logic_tb__DOT__dut__DOT__write_accepted));
    bufp->chgBit(oldp+57,(((IData)(vlSelf->ram_logic_tb__DOT__read_ready) 
                           & (IData)(vlSelf->ram_logic_tb__DOT__read_valid))));
    bufp->chgBit(oldp+58,(((~ (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_buf_sel_q)) 
                           & (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_accepted))));
    bufp->chgBit(oldp+59,(((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_accepted) 
                           & (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_buf_sel_q))));
    bufp->chgIData(oldp+60,(vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
                            [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_addr) 
                                       >> 4U))]),32);
    bufp->chgIData(oldp+61,(vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
                            [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_addr) 
                                       >> 4U))]),32);
    bufp->chgIData(oldp+62,(vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__unnamedblk2__DOT__i),32);
    bufp->chgIData(oldp+63,(vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__unnamedblk2__DOT__i),32);
}

void Vram_logic_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root__trace_cleanup\n"); );
    // Init
    Vram_logic_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vram_logic_tb___024root*>(voidSelf);
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
