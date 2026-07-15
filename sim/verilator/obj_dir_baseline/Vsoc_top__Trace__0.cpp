// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vsoc_top__Syms.h"


void Vsoc_top___024root__trace_chg_0_sub_0(Vsoc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vsoc_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_chg_0\n"); );
    // Body
    Vsoc_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsoc_top___024root*>(voidSelf);
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vsoc_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vsoc_top___024root__trace_chg_dtype____0(Vsoc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar);

void Vsoc_top___024root__trace_chg_0_sub_0(Vsoc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_chg_0_sub_0\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc),32);
        bufp->chgBit(oldp+1,(vlSelfRef.soc_top__DOT__l1_mem_valid));
        bufp->chgCData(oldp+2,(vlSelfRef.soc_top__DOT__mem_delay_cnt),4);
        bufp->chgBit(oldp+3,(vlSelfRef.soc_top__DOT__mem_pending));
        bufp->chgIData(oldp+4,(((IData)(4U) + vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc)),32);
        Vsoc_top___024root__trace_chg_dtype____0(vlSelf, bufp, 5, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+37,(vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result),32);
        bufp->chgIData(oldp+38,(vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b),32);
        bufp->chgBit(oldp+39,(vlSelfRef.soc_top__DOT__dcache_we));
        bufp->chgBit(oldp+40,(vlSelfRef.soc_top__DOT__dcache_req));
        bufp->chgCData(oldp+41,(vlSelfRef.soc_top__DOT__u_core__DOT__id_alu_op),7);
        bufp->chgCData(oldp+42,(vlSelfRef.soc_top__DOT__u_core__DOT__id_op_a_sel),2);
        bufp->chgCData(oldp+43,(vlSelfRef.soc_top__DOT__u_core__DOT__id_op_b_sel),2);
        bufp->chgIData(oldp+44,(vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a),32);
        bufp->chgIData(oldp+45,(vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__imm),32);
        bufp->chgIData(oldp+46,(vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__error),32);
        bufp->chgIData(oldp+47,(vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__prev_error),32);
        bufp->chgBit(oldp+48,(vlSelfRef.soc_top__DOT__u_core__DOT__id_pid_en));
        bufp->chgCData(oldp+49,(vlSelfRef.__VdfgRegularize_hebeb780c_0_2),5);
        bufp->chgBit(oldp+50,(vlSelfRef.soc_top__DOT__u_core__DOT__id_wb_en));
        bufp->chgCData(oldp+51,(vlSelfRef.soc_top__DOT__u_core__DOT__id_wb_mux),2);
        bufp->chgIData(oldp+52,(vlSelfRef.soc_top__DOT__u_core__DOT__pid_integ_next),32);
        bufp->chgCData(oldp+53,(vlSelfRef.__VdfgRegularize_hebeb780c_0_0),7);
        bufp->chgCData(oldp+54,(vlSelfRef.__VdfgRegularize_hebeb780c_0_1),3);
        bufp->chgBit(oldp+55,((0x63U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))));
        bufp->chgBit(oldp+56,((0x6fU == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))));
        bufp->chgBit(oldp+57,((0x67U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))));
        bufp->chgBit(oldp+58,(vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__stall));
        bufp->chgBit(oldp+59,(((~ (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__stall)) 
                               & (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_wb_en))));
        bufp->chgCData(oldp+60,(vlSelfRef.__VdfgRegularize_hebeb780c_0_4),5);
        bufp->chgCData(oldp+61,(vlSelfRef.__VdfgRegularize_hebeb780c_0_5),5);
        bufp->chgCData(oldp+62,(vlSelfRef.__VdfgRegularize_hebeb780c_0_3),7);
        bufp->chgIData(oldp+63,(vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__std_result),32);
        bufp->chgIData(oldp+64,(vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__pid_result),32);
        bufp->chgQData(oldp+65,(vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__p_term),64);
        bufp->chgQData(oldp+67,(vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__i_term),64);
        bufp->chgQData(oldp+69,(vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__d_term),64);
        bufp->chgQData(oldp+71,(vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__integral_accum),64);
        bufp->chgIData(oldp+73,(vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__error_diff),32);
    }
    bufp->chgBit(oldp+74,(vlSelfRef.clk));
    bufp->chgBit(oldp+75,(vlSelfRef.rst_n));
    bufp->chgIData(oldp+76,(vlSelfRef.ext_sensor_data),32);
    bufp->chgBit(oldp+77,(vlSelfRef.spi_miso));
    bufp->chgBit(oldp+78,(vlSelfRef.spi_mosi));
    bufp->chgBit(oldp+79,(vlSelfRef.spi_sclk));
    bufp->chgCData(oldp+80,(vlSelfRef.motor_pwm),4);
    bufp->chgIData(oldp+81,(vlSelfRef.soc_top__DOT__ram
                            [(0x00000fffU & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                             >> 2U))]),32);
    bufp->chgIData(oldp+82,(vlSelfRef.soc_top__DOT__ram
                            [(0x00000fffU & (vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result 
                                             >> 2U))]),32);
    bufp->chgIData(oldp+83,(vlSelfRef.soc_top__DOT__io_rdata),32);
    bufp->chgCData(oldp+84,(vlSelfRef.soc_top__DOT__uart_mock_rx_buffer),8);
    bufp->chgIData(oldp+85,(vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata),32);
    bufp->chgIData(oldp+86,(vlSelfRef.soc_top__DOT__u_core__DOT__pid_integ),32);
    bufp->chgBit(oldp+87,(((0x63U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0)) 
                           & ((0x00004000U & vlSelfRef.soc_top__DOT__ram
                               [(0x00000fffU & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                                >> 2U))])
                               ? ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_20)
                                   ? ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_12)
                                       ? (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a 
                                          >= vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b)
                                       : (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a 
                                          < vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b))
                                   : ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_12)
                                       ? VL_GTES_III(32, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b)
                                       : VL_LTS_III(32, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b)))
                               : ((~ (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_20)) 
                                  & ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_12)
                                      ? (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b 
                                         != vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a)
                                      : (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b 
                                         == vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a)))))));
    bufp->chgBit(oldp+88,(((0x6fU == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0)) 
                           | ((0x67U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0)) 
                              | ((0x63U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0)) 
                                 & ((0x00004000U & vlSelfRef.soc_top__DOT__ram
                                     [(0x00000fffU 
                                       & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                          >> 2U))])
                                     ? ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_20)
                                         ? ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_12)
                                             ? (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a 
                                                >= vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b)
                                             : (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a 
                                                < vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b))
                                         : ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_12)
                                             ? VL_GTES_III(32, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b)
                                             : VL_LTS_III(32, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b)))
                                     : ((~ (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_20)) 
                                        & ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_12)
                                            ? (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b 
                                               != vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a)
                                            : (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b 
                                               == vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a)))))))));
    bufp->chgIData(oldp+89,(((0x67U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))
                              ? (0xfffffffeU & (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__imm 
                                                + vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a))
                              : (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                 + vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__imm))),32);
    bufp->chgIData(oldp+90,(((3U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))
                              ? ((0U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1))
                                  ? ((2U & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)
                                      ? ((1U & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)
                                          ? (((- (IData)(
                                                         (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                          >> 0x0000001fU))) 
                                              << 8U) 
                                             | (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                >> 0x00000018U))
                                          : (((- (IData)(
                                                         (1U 
                                                          & (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                             >> 0x00000017U)))) 
                                              << 8U) 
                                             | (0x000000ffU 
                                                & (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                   >> 0x00000010U))))
                                      : ((1U & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)
                                          ? (((- (IData)(
                                                         (1U 
                                                          & (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                             >> 0x0000000fU)))) 
                                              << 8U) 
                                             | (0x000000ffU 
                                                & (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                   >> 8U)))
                                          : (((- (IData)(
                                                         (1U 
                                                          & (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                             >> 7U)))) 
                                              << 8U) 
                                             | (0x000000ffU 
                                                & vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata))))
                                  : ((4U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1))
                                      ? (0x000000ffU 
                                         & ((2U & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)
                                             ? ((1U 
                                                 & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)
                                                 ? 
                                                (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                 >> 0x00000018U)
                                                 : 
                                                (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                 >> 0x00000010U))
                                             : ((1U 
                                                 & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)
                                                 ? 
                                                (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                 >> 8U)
                                                 : vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata)))
                                      : vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata))
                              : vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata)),32);
    bufp->chgIData(oldp+91,(vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__wdata),32);
    bufp->chgIData(oldp+92,((((0x6fU == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0)) 
                              | ((0x67U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0)) 
                                 | ((0x63U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0)) 
                                    & ((0x00004000U 
                                        & vlSelfRef.soc_top__DOT__ram
                                        [(0x00000fffU 
                                          & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                             >> 2U))])
                                        ? ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_20)
                                            ? ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_12)
                                                ? (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a 
                                                   >= vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b)
                                                : (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a 
                                                   < vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b))
                                            : ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_12)
                                                ? VL_GTES_III(32, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b)
                                                : VL_LTS_III(32, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a, vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b)))
                                        : ((~ (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_20)) 
                                           & ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_12)
                                               ? (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b 
                                                  != vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a)
                                               : (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b 
                                                  == vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a)))))))
                              ? ((0x67U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))
                                  ? (0xfffffffeU & 
                                     (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__imm 
                                      + vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a))
                                  : (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                     + vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__imm))
                              : ((IData)(4U) + vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc))),32);
}

void Vsoc_top___024root__trace_chg_dtype____0(Vsoc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_chg_dtype____0\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[0]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+2,(__VdtypeVar[2]),32);
    bufp->chgIData(oldp+3,(__VdtypeVar[3]),32);
    bufp->chgIData(oldp+4,(__VdtypeVar[4]),32);
    bufp->chgIData(oldp+5,(__VdtypeVar[5]),32);
    bufp->chgIData(oldp+6,(__VdtypeVar[6]),32);
    bufp->chgIData(oldp+7,(__VdtypeVar[7]),32);
    bufp->chgIData(oldp+8,(__VdtypeVar[8]),32);
    bufp->chgIData(oldp+9,(__VdtypeVar[9]),32);
    bufp->chgIData(oldp+10,(__VdtypeVar[10]),32);
    bufp->chgIData(oldp+11,(__VdtypeVar[11]),32);
    bufp->chgIData(oldp+12,(__VdtypeVar[12]),32);
    bufp->chgIData(oldp+13,(__VdtypeVar[13]),32);
    bufp->chgIData(oldp+14,(__VdtypeVar[14]),32);
    bufp->chgIData(oldp+15,(__VdtypeVar[15]),32);
    bufp->chgIData(oldp+16,(__VdtypeVar[16]),32);
    bufp->chgIData(oldp+17,(__VdtypeVar[17]),32);
    bufp->chgIData(oldp+18,(__VdtypeVar[18]),32);
    bufp->chgIData(oldp+19,(__VdtypeVar[19]),32);
    bufp->chgIData(oldp+20,(__VdtypeVar[20]),32);
    bufp->chgIData(oldp+21,(__VdtypeVar[21]),32);
    bufp->chgIData(oldp+22,(__VdtypeVar[22]),32);
    bufp->chgIData(oldp+23,(__VdtypeVar[23]),32);
    bufp->chgIData(oldp+24,(__VdtypeVar[24]),32);
    bufp->chgIData(oldp+25,(__VdtypeVar[25]),32);
    bufp->chgIData(oldp+26,(__VdtypeVar[26]),32);
    bufp->chgIData(oldp+27,(__VdtypeVar[27]),32);
    bufp->chgIData(oldp+28,(__VdtypeVar[28]),32);
    bufp->chgIData(oldp+29,(__VdtypeVar[29]),32);
    bufp->chgIData(oldp+30,(__VdtypeVar[30]),32);
    bufp->chgIData(oldp+31,(__VdtypeVar[31]),32);
}

void Vsoc_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root__trace_cleanup\n"); );
    // Body
    Vsoc_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsoc_top___024root*>(voidSelf);
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
