// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsoc_top.h for the primary calling header

#ifndef VERILATED_VSOC_TOP___024ROOT_H_
#define VERILATED_VSOC_TOP___024ROOT_H_  // guard

#include "verilated.h"


class Vsoc_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsoc_top___024root final {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst_n,0,0);
        VL_IN8(spi_miso,0,0);
        VL_OUT8(spi_mosi,0,0);
        VL_OUT8(spi_sclk,0,0);
        VL_OUT8(motor_pwm,3,0);
        CData/*0:0*/ soc_top__DOT__dcache_we;
        CData/*0:0*/ soc_top__DOT__dcache_req;
        CData/*7:0*/ soc_top__DOT__uart_mock_rx_buffer;
        CData/*0:0*/ soc_top__DOT__l1_mem_valid;
        CData/*3:0*/ soc_top__DOT__mem_delay_cnt;
        CData/*0:0*/ soc_top__DOT__mem_pending;
        CData/*6:0*/ soc_top__DOT__u_core__DOT__id_alu_op;
        CData/*1:0*/ soc_top__DOT__u_core__DOT__id_op_a_sel;
        CData/*1:0*/ soc_top__DOT__u_core__DOT__id_op_b_sel;
        CData/*0:0*/ soc_top__DOT__u_core__DOT__id_pid_en;
        CData/*0:0*/ soc_top__DOT__u_core__DOT__id_wb_en;
        CData/*1:0*/ soc_top__DOT__u_core__DOT__id_wb_mux;
        CData/*0:0*/ soc_top__DOT__u_core__DOT__u_fetch__DOT__stall;
        CData/*6:0*/ __VdfgRegularize_hebeb780c_0_0;
        CData/*2:0*/ __VdfgRegularize_hebeb780c_0_1;
        CData/*4:0*/ __VdfgRegularize_hebeb780c_0_2;
        CData/*6:0*/ __VdfgRegularize_hebeb780c_0_3;
        CData/*4:0*/ __VdfgRegularize_hebeb780c_0_4;
        CData/*4:0*/ __VdfgRegularize_hebeb780c_0_5;
        CData/*0:0*/ __VdfgRegularize_hebeb780c_0_12;
        CData/*0:0*/ __VdfgRegularize_hebeb780c_0_20;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__spi_miso__0;
        CData/*0:0*/ __VicoDidInit;
        CData/*0:0*/ __VicoPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__1;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        VL_IN(ext_sensor_data,31,0);
        IData/*31:0*/ soc_top__DOT__io_rdata;
        IData/*31:0*/ soc_top__DOT__u_core__DOT__dcache_rdata;
        IData/*31:0*/ soc_top__DOT__u_core__DOT__pid_integ;
        IData/*31:0*/ soc_top__DOT__u_core__DOT__pid_integ_next;
        IData/*31:0*/ soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result;
        IData/*31:0*/ soc_top__DOT__u_core__DOT__u_execute__DOT__std_result;
        IData/*31:0*/ soc_top__DOT__u_core__DOT__u_execute__DOT__pid_result;
        IData/*31:0*/ soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__error;
        IData/*31:0*/ soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__prev_error;
        IData/*31:0*/ soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__error_diff;
        IData/*31:0*/ soc_top__DOT__u_core__DOT__u_decode__DOT__imm;
        IData/*31:0*/ soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a;
        IData/*31:0*/ soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b;
        IData/*31:0*/ soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__wdata;
        IData/*31:0*/ soc_top__DOT__u_core__DOT__u_fetch__DOT__pc;
        IData/*31:0*/ soc_top__DOT__u_core__DOT__u_fetch__DOT__next_pc;
        IData/*31:0*/ __Vtrigprevexpr___TOP__ext_sensor_data__0;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__p_term;
        QData/*63:0*/ soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__i_term;
        QData/*63:0*/ soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__d_term;
        QData/*63:0*/ soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__integral_accum;
        VlUnpacked<IData/*31:0*/, 4096> soc_top__DOT__ram;
        VlUnpacked<IData/*31:0*/, 32> soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    };
    struct {
        VlUnpacked<QData/*63:0*/, 2> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
        VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    };

    // INTERNAL VARIABLES
    Vsoc_top__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vsoc_top___024root(Vsoc_top__Syms* symsp, const char* namep);
    ~Vsoc_top___024root();
    VL_UNCOPYABLE(Vsoc_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
