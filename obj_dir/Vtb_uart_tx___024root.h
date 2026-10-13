// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_uart_tx.h for the primary calling header

#ifndef VERILATED_VTB_UART_TX___024ROOT_H_
#define VERILATED_VTB_UART_TX___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_uart_tx__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_uart_tx___024root final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_uart_tx__DOT__clk;
    CData/*0:0*/ tb_uart_tx__DOT__rst_n;
    CData/*0:0*/ tb_uart_tx__DOT__tx_start;
    CData/*7:0*/ tb_uart_tx__DOT__tx_data;
    CData/*0:0*/ tb_uart_tx__DOT__tx_done;
    CData/*1:0*/ tb_uart_tx__DOT__dut__DOT__state;
    CData/*1:0*/ tb_uart_tx__DOT__dut__DOT__state_next;
    CData/*2:0*/ tb_uart_tx__DOT__dut__DOT__bit_idx;
    CData/*7:0*/ tb_uart_tx__DOT__dut__DOT__data_shift;
    CData/*7:0*/ __VdlyVal__tb_uart_tx__DOT__tx_data__v0;
    CData/*0:0*/ __VdlySet__tb_uart_tx__DOT__tx_data__v0;
    CData/*0:0*/ __VdlySet__tb_uart_tx__DOT__tx_start__v0;
    CData/*0:0*/ __VdlySet__tb_uart_tx__DOT__tx_start__v1;
    CData/*7:0*/ __VdlyVal__tb_uart_tx__DOT__tx_data__v1;
    CData/*0:0*/ __VdlySet__tb_uart_tx__DOT__tx_data__v1;
    CData/*0:0*/ __VdlySet__tb_uart_tx__DOT__tx_start__v2;
    CData/*0:0*/ __VdlySet__tb_uart_tx__DOT__tx_start__v3;
    CData/*7:0*/ __VdlyVal__tb_uart_tx__DOT__tx_data__v2;
    CData/*0:0*/ __VdlySet__tb_uart_tx__DOT__tx_data__v2;
    CData/*0:0*/ __VdlySet__tb_uart_tx__DOT__tx_start__v4;
    CData/*0:0*/ __VdlySet__tb_uart_tx__DOT__tx_start__v5;
    CData/*7:0*/ __VdlyVal__tb_uart_tx__DOT__tx_data__v3;
    CData/*0:0*/ __VdlySet__tb_uart_tx__DOT__tx_data__v3;
    CData/*0:0*/ __VdlySet__tb_uart_tx__DOT__tx_start__v6;
    CData/*0:0*/ __VdlySet__tb_uart_tx__DOT__tx_start__v7;
    CData/*7:0*/ __VdlyVal__tb_uart_tx__DOT__tx_data__v4;
    CData/*0:0*/ __VdlySet__tb_uart_tx__DOT__tx_data__v4;
    CData/*0:0*/ __VdlySet__tb_uart_tx__DOT__tx_start__v8;
    CData/*0:0*/ __VdlySet__tb_uart_tx__DOT__tx_start__v9;
    CData/*7:0*/ __VdlyVal__tb_uart_tx__DOT__tx_data__v5;
    CData/*0:0*/ __VdlySet__tb_uart_tx__DOT__tx_data__v5;
    CData/*0:0*/ __VdlySet__tb_uart_tx__DOT__tx_start__v10;
    CData/*0:0*/ __VdlySet__tb_uart_tx__DOT__tx_start__v11;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_uart_tx__DOT__clk__0;
    SData/*8:0*/ tb_uart_tx__DOT__dut__DOT__cycle_cnt;
    IData/*31:0*/ tb_uart_tx__DOT____VlemExpr_0;
    IData/*31:0*/ tb_uart_tx__DOT__errors;
    IData/*31:0*/ tb_uart_tx__DOT__tests_run;
    IData/*31:0*/ __Vi;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_ha6994d49__0;

    // INTERNAL VARIABLES
    Vtb_uart_tx__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_uart_tx___024root(Vtb_uart_tx__Syms* symsp, const char* namep);
    ~Vtb_uart_tx___024root();
    VL_UNCOPYABLE(Vtb_uart_tx___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
