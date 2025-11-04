// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vram_logic_tb__Syms.h"


VL_ATTR_COLD void Vram_logic_tb___024root__trace_init_sub__TOP__0(Vram_logic_tb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("ram_logic_tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+66,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+67,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+68,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+69,0,"CLK_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+52,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+53,0,"write_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+54,0,"write_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"write_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+55,0,"read_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+56,0,"read_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"read_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"buffer_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"buffer_overflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+39,0,"write_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+40,0,"read_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+57,0,"test_errors",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+2,0,"test_passed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("test_data", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+3+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("read_back", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+19+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+70,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+71,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+72,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+52,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+53,0,"write_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+54,0,"write_valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"write_ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+55,0,"read_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+56,0,"read_ready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"read_valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"buffer_ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"buffer_overflow_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+39,0,"write_count_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+40,0,"read_count_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+41,0,"write_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+42,0,"read_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+39,0,"write_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+40,0,"read_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+43,0,"write_buffer_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"read_buffer_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"read_buffer_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"write_buffer_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"read_in_progress",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+58,0,"write_accepted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"read_accepted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+48,0,"ram0_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBus(c+49,0,"ram1_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBit(c+60,0,"ram0_write_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"ram1_write_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+62,0,"ram0_data_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+63,0,"ram1_data_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("pingpong_buffer_ram0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+73,0,"BIT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+74,0,"READ_MODE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+75,0,"WRITE_MODE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+76,0,"BLK_SEL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+52,0,"CLK",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"CE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"OCE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"RESET",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"WRE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+76,0,"BLKSEL",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+48,0,"AD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBus(c+53,0,"DI",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+62,0,"DO",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+79,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+80,0,"ADDR_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+50,0,"actual_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->pushPrefix("bypass_mode", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+62,0,"read_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+81,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+64,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("pingpong_buffer_ram1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+73,0,"BIT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+74,0,"READ_MODE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+75,0,"WRITE_MODE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+76,0,"BLK_SEL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+52,0,"CLK",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"CE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"OCE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"RESET",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"WRE",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+76,0,"BLKSEL",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+49,0,"AD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declBus(c+53,0,"DI",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+63,0,"DO",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+79,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+80,0,"ADDR_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+51,0,"actual_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->pushPrefix("bypass_mode", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+63,0,"read_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+82,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+65,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vram_logic_tb___024root__trace_init_top(Vram_logic_tb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root__trace_init_top\n"); );
    // Body
    Vram_logic_tb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vram_logic_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vram_logic_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vram_logic_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vram_logic_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vram_logic_tb___024root__trace_register(Vram_logic_tb___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vram_logic_tb___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vram_logic_tb___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vram_logic_tb___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vram_logic_tb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vram_logic_tb___024root__trace_const_0_sub_0(Vram_logic_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vram_logic_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root__trace_const_0\n"); );
    // Init
    Vram_logic_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vram_logic_tb___024root*>(voidSelf);
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vram_logic_tb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vram_logic_tb___024root__trace_const_0_sub_0(Vram_logic_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+66,(0x20U),32);
    bufp->fullIData(oldp+67,(0x10U),32);
    bufp->fullIData(oldp+68,(4U),32);
    bufp->fullIData(oldp+69,(0xaU),32);
    bufp->fullIData(oldp+70,(0x20U),32);
    bufp->fullIData(oldp+71,(0x10U),32);
    bufp->fullIData(oldp+72,(4U),32);
    bufp->fullIData(oldp+73,(0x20U),32);
    bufp->fullBit(oldp+74,(0U));
    bufp->fullCData(oldp+75,(0U),2);
    bufp->fullCData(oldp+76,(0U),3);
    bufp->fullBit(oldp+77,(1U));
    bufp->fullBit(oldp+78,(0U));
    bufp->fullIData(oldp+79,(0x200U),32);
    bufp->fullIData(oldp+80,(9U),32);
    bufp->fullIData(oldp+81,(vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+82,(vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__unnamedblk1__DOT__i),32);
}

VL_ATTR_COLD void Vram_logic_tb___024root__trace_full_0_sub_0(Vram_logic_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vram_logic_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root__trace_full_0\n"); );
    // Init
    Vram_logic_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vram_logic_tb___024root*>(voidSelf);
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vram_logic_tb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vram_logic_tb___024root__trace_full_0_sub_0(Vram_logic_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vram_logic_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vram_logic_tb___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->ram_logic_tb__DOT__rst_n));
    bufp->fullIData(oldp+2,(vlSelf->ram_logic_tb__DOT__test_passed),32);
    bufp->fullIData(oldp+3,(vlSelf->ram_logic_tb__DOT__test_data[0]),32);
    bufp->fullIData(oldp+4,(vlSelf->ram_logic_tb__DOT__test_data[1]),32);
    bufp->fullIData(oldp+5,(vlSelf->ram_logic_tb__DOT__test_data[2]),32);
    bufp->fullIData(oldp+6,(vlSelf->ram_logic_tb__DOT__test_data[3]),32);
    bufp->fullIData(oldp+7,(vlSelf->ram_logic_tb__DOT__test_data[4]),32);
    bufp->fullIData(oldp+8,(vlSelf->ram_logic_tb__DOT__test_data[5]),32);
    bufp->fullIData(oldp+9,(vlSelf->ram_logic_tb__DOT__test_data[6]),32);
    bufp->fullIData(oldp+10,(vlSelf->ram_logic_tb__DOT__test_data[7]),32);
    bufp->fullIData(oldp+11,(vlSelf->ram_logic_tb__DOT__test_data[8]),32);
    bufp->fullIData(oldp+12,(vlSelf->ram_logic_tb__DOT__test_data[9]),32);
    bufp->fullIData(oldp+13,(vlSelf->ram_logic_tb__DOT__test_data[10]),32);
    bufp->fullIData(oldp+14,(vlSelf->ram_logic_tb__DOT__test_data[11]),32);
    bufp->fullIData(oldp+15,(vlSelf->ram_logic_tb__DOT__test_data[12]),32);
    bufp->fullIData(oldp+16,(vlSelf->ram_logic_tb__DOT__test_data[13]),32);
    bufp->fullIData(oldp+17,(vlSelf->ram_logic_tb__DOT__test_data[14]),32);
    bufp->fullIData(oldp+18,(vlSelf->ram_logic_tb__DOT__test_data[15]),32);
    bufp->fullIData(oldp+19,(vlSelf->ram_logic_tb__DOT__read_back[0]),32);
    bufp->fullIData(oldp+20,(vlSelf->ram_logic_tb__DOT__read_back[1]),32);
    bufp->fullIData(oldp+21,(vlSelf->ram_logic_tb__DOT__read_back[2]),32);
    bufp->fullIData(oldp+22,(vlSelf->ram_logic_tb__DOT__read_back[3]),32);
    bufp->fullIData(oldp+23,(vlSelf->ram_logic_tb__DOT__read_back[4]),32);
    bufp->fullIData(oldp+24,(vlSelf->ram_logic_tb__DOT__read_back[5]),32);
    bufp->fullIData(oldp+25,(vlSelf->ram_logic_tb__DOT__read_back[6]),32);
    bufp->fullIData(oldp+26,(vlSelf->ram_logic_tb__DOT__read_back[7]),32);
    bufp->fullIData(oldp+27,(vlSelf->ram_logic_tb__DOT__read_back[8]),32);
    bufp->fullIData(oldp+28,(vlSelf->ram_logic_tb__DOT__read_back[9]),32);
    bufp->fullIData(oldp+29,(vlSelf->ram_logic_tb__DOT__read_back[10]),32);
    bufp->fullIData(oldp+30,(vlSelf->ram_logic_tb__DOT__read_back[11]),32);
    bufp->fullIData(oldp+31,(vlSelf->ram_logic_tb__DOT__read_back[12]),32);
    bufp->fullIData(oldp+32,(vlSelf->ram_logic_tb__DOT__read_back[13]),32);
    bufp->fullIData(oldp+33,(vlSelf->ram_logic_tb__DOT__read_back[14]),32);
    bufp->fullIData(oldp+34,(vlSelf->ram_logic_tb__DOT__read_back[15]),32);
    bufp->fullBit(oldp+35,((0x10U > (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count))));
    bufp->fullBit(oldp+36,(vlSelf->ram_logic_tb__DOT__read_valid));
    bufp->fullBit(oldp+37,(vlSelf->ram_logic_tb__DOT__buffer_ready));
    bufp->fullBit(oldp+38,(vlSelf->ram_logic_tb__DOT__buffer_overflow));
    bufp->fullCData(oldp+39,(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count),5);
    bufp->fullCData(oldp+40,(vlSelf->ram_logic_tb__DOT__dut__DOT__read_count),5);
    bufp->fullCData(oldp+41,(vlSelf->ram_logic_tb__DOT__dut__DOT__write_address),4);
    bufp->fullCData(oldp+42,(vlSelf->ram_logic_tb__DOT__dut__DOT__read_address),4);
    bufp->fullBit(oldp+43,(vlSelf->ram_logic_tb__DOT__dut__DOT__write_buffer_sel));
    bufp->fullBit(oldp+44,(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel));
    bufp->fullBit(oldp+45,(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid));
    bufp->fullBit(oldp+46,((0x10U <= (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_count))));
    bufp->fullBit(oldp+47,(vlSelf->ram_logic_tb__DOT__dut__DOT__read_in_progress));
    bufp->fullSData(oldp+48,(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_address),14);
    bufp->fullSData(oldp+49,(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_address),14);
    bufp->fullSData(oldp+50,((0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_address) 
                                       >> 4U))),9);
    bufp->fullSData(oldp+51,((0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_address) 
                                       >> 4U))),9);
    bufp->fullBit(oldp+52,(vlSelf->ram_logic_tb__DOT__clk));
    bufp->fullIData(oldp+53,(vlSelf->ram_logic_tb__DOT__write_data),32);
    bufp->fullBit(oldp+54,(vlSelf->ram_logic_tb__DOT__write_valid));
    bufp->fullIData(oldp+55,(((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_valid)
                               ? ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__read_buffer_sel)
                                   ? vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
                                  [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_address) 
                                             >> 4U))]
                                   : vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
                                  [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_address) 
                                             >> 4U))])
                               : 0U)),32);
    bufp->fullBit(oldp+56,(vlSelf->ram_logic_tb__DOT__read_ready));
    bufp->fullIData(oldp+57,(vlSelf->ram_logic_tb__DOT__test_errors),32);
    bufp->fullBit(oldp+58,(vlSelf->ram_logic_tb__DOT__dut__DOT__write_accepted));
    bufp->fullBit(oldp+59,(((IData)(vlSelf->ram_logic_tb__DOT__read_ready) 
                            & (IData)(vlSelf->ram_logic_tb__DOT__read_valid))));
    bufp->fullBit(oldp+60,(((~ (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_buffer_sel)) 
                            & (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_accepted))));
    bufp->fullBit(oldp+61,(((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_accepted) 
                            & (IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__write_buffer_sel))));
    bufp->fullIData(oldp+62,(vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__mem
                             [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram0_address) 
                                        >> 4U))]),32);
    bufp->fullIData(oldp+63,(vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__mem
                             [(0x1fU & ((IData)(vlSelf->ram_logic_tb__DOT__dut__DOT__ram1_address) 
                                        >> 4U))]),32);
    bufp->fullIData(oldp+64,(vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram0__DOT__unnamedblk2__DOT__i),32);
    bufp->fullIData(oldp+65,(vlSelf->ram_logic_tb__DOT__dut__DOT__pingpong_buffer_ram1__DOT__unnamedblk2__DOT__i),32);
}
