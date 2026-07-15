// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsoc_top.h for the primary calling header

#include "Vsoc_top__pch.h"

bool Vsoc_top___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((2U > n));
    return (0U);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vsoc_top___024root___eval_phase__ico(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_phase__ico\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__ico
        vlSelfRef.__VicoTriggered[0U] = (QData)((IData)(
                                                        (((((IData)(vlSelfRef.spi_miso) 
                                                            != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__spi_miso__0)) 
                                                           << 3U) 
                                                          | ((vlSelfRef.ext_sensor_data 
                                                              != vlSelfRef.__Vtrigprevexpr___TOP__ext_sensor_data__0) 
                                                             << 2U)) 
                                                         | ((((IData)(vlSelfRef.rst_n) 
                                                              != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0)) 
                                                             << 1U) 
                                                            | ((IData)(vlSelfRef.clk) 
                                                               != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))))));
        vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
        vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
        vlSelfRef.__Vtrigprevexpr___TOP__ext_sensor_data__0 
            = vlSelfRef.ext_sensor_data;
        vlSelfRef.__Vtrigprevexpr___TOP__spi_miso__0 
            = vlSelfRef.spi_miso;
        if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VicoDidInit)))))) {
            vlSelfRef.__VicoDidInit = 1U;
            vlSelfRef.__VicoTriggered[0U] = (1ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (2ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (4ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (8ULL | vlSelfRef.__VicoTriggered[0U]);
        }
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsoc_top___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vsoc_top___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        {
            // Inlined CFunc: _eval_ico
            if ((4ULL & vlSelfRef.__VicoTriggered[0U])) {
                {
                    // Inlined CFunc: _ico_sequent__TOP__0
                    vlSelfRef.soc_top__DOT__io_rdata = 0U;
                    if ((0x40000000U == vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)) {
                        vlSelfRef.soc_top__DOT__io_rdata 
                            = vlSelfRef.ext_sensor_data;
                    } else if ((0x40000204U == vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)) {
                        vlSelfRef.soc_top__DOT__io_rdata 
                            = vlSelfRef.soc_top__DOT__uart_mock_rx_buffer;
                    } else if ((0x40000208U == vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)) {
                        vlSelfRef.soc_top__DOT__io_rdata = 3U;
                    }
                    vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                        = ((0x4000U == (vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result 
                                        >> 0x00000010U))
                            ? vlSelfRef.soc_top__DOT__io_rdata
                            : vlSelfRef.soc_top__DOT__ram
                           [(0x00000fffU & (vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result 
                                            >> 2U))]);
                    vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__wdata 
                        = ((0U == (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_wb_mux))
                            ? vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result
                            : ((1U == (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_wb_mux))
                                ? ((3U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))
                                    ? ((0U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1))
                                        ? ((2U & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)
                                            ? ((1U 
                                                & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)
                                                ? (
                                                   ((- (IData)(
                                                               (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                                >> 0x0000001fU))) 
                                                    << 8U) 
                                                   | (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                      >> 0x00000018U))
                                                : (
                                                   ((- (IData)(
                                                               (1U 
                                                                & (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                                   >> 0x00000017U)))) 
                                                    << 8U) 
                                                   | (0x000000ffU 
                                                      & (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                         >> 0x00000010U))))
                                            : ((1U 
                                                & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)
                                                ? (
                                                   ((- (IData)(
                                                               (1U 
                                                                & (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                                   >> 0x0000000fU)))) 
                                                    << 8U) 
                                                   | (0x000000ffU 
                                                      & (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                         >> 8U)))
                                                : (
                                                   ((- (IData)(
                                                               (1U 
                                                                & (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                                   >> 7U)))) 
                                                    << 8U) 
                                                   | (0x000000ffU 
                                                      & vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata))))
                                        : ((4U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1))
                                            ? (0x000000ffU 
                                               & ((2U 
                                                   & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)
                                                   ? 
                                                  ((1U 
                                                    & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)
                                                    ? 
                                                   (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                    >> 0x00000018U)
                                                    : 
                                                   (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                    >> 0x00000010U))
                                                   : 
                                                  ((1U 
                                                    & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)
                                                    ? 
                                                   (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                    >> 8U)
                                                    : vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata)))
                                            : vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata))
                                    : vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata)
                                : ((2U == (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_wb_mux))
                                    ? ((IData)(4U) 
                                       + vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc)
                                    : vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)));
                }
            }
        }
    }
    return (__VicoExecute);
}

bool Vsoc_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const VlUnpacked<CData/*2:0*/, 128> Vsoc_top__ConstPool__TABLE_h1142c3db_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vsoc_top__ConstPool__TABLE_h839cdb80_0;
extern const VlUnpacked<CData/*3:0*/, 128> Vsoc_top__ConstPool__TABLE_h5d634b6d_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vsoc_top__ConstPool__TABLE_he3a1c648_0;

void Vsoc_top___024root___nba_sequent__TOP__0(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___nba_sequent__TOP__0\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    IData/*31:0*/ __VdlyVal__soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs__v0;
    __VdlyVal__soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs__v0 = 0;
    CData/*4:0*/ __VdlyDim0__soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs__v0;
    __VdlyDim0__soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs__v0 = 0;
    CData/*0:0*/ __VdlySet__soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs__v0;
    __VdlySet__soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs__v0 = 0;
    CData/*0:0*/ __VdlySet__soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs__v1;
    __VdlySet__soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs__v1 = 0;
    // Body
    __VdlySet__soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs__v0 = 0U;
    __VdlySet__soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs__v1 = 0U;
    if (vlSelfRef.rst_n) {
        if ((((~ (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__stall)) 
              & (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_wb_en)) 
             & (0U != (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)))) {
            __VdlyVal__soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs__v0 
                = vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__wdata;
            __VdlyDim0__soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs__v0 
                = vlSelfRef.__VdfgRegularize_hebeb780c_0_2;
            __VdlySet__soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs__v0 = 1U;
        }
        if ((1U & (~ (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__stall)))) {
            vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                = vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__next_pc;
        }
    } else {
        __VdlySet__soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs__v1 = 1U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc = 0U;
    }
    __Vtableidx1 = (((IData)(vlSelfRef.soc_top__DOT__mem_delay_cnt) 
                     << 3U) | (((IData)(vlSelfRef.soc_top__DOT__mem_pending) 
                                << 2U) | (((IData)(vlSelfRef.soc_top__DOT__dcache_req) 
                                           << 1U) | (IData)(vlSelfRef.rst_n))));
    if ((1U & Vsoc_top__ConstPool__TABLE_h1142c3db_0
         [__Vtableidx1])) {
        vlSelfRef.soc_top__DOT__mem_pending = Vsoc_top__ConstPool__TABLE_h839cdb80_0
            [__Vtableidx1];
    }
    if ((2U & Vsoc_top__ConstPool__TABLE_h1142c3db_0
         [__Vtableidx1])) {
        vlSelfRef.soc_top__DOT__mem_delay_cnt = Vsoc_top__ConstPool__TABLE_h5d634b6d_0
            [__Vtableidx1];
    }
    vlSelfRef.soc_top__DOT__l1_mem_valid = Vsoc_top__ConstPool__TABLE_he3a1c648_0
        [__Vtableidx1];
    if (__VdlySet__soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs__v0) {
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[__VdlyDim0__soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs__v0] 
            = __VdlyVal__soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs__v0;
    }
    if (__VdlySet__soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs__v1) {
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[0U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[1U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[2U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[3U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[4U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[5U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[6U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[7U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[8U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[9U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[10U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[11U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[12U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[13U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[14U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[15U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[16U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[17U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[18U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[19U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[20U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[21U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[22U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[23U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[24U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[25U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[26U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[27U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[28U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[29U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[30U] = 0U;
        vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs[31U] = 0U;
    }
}

void Vsoc_top___024root___nba_comb__TOP__0(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___nba_comb__TOP__0\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_6;
    __VdfgRegularize_hebeb780c_0_6 = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_10;
    __VdfgRegularize_hebeb780c_0_10 = 0;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_11;
    __VdfgRegularize_hebeb780c_0_11 = 0;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_13;
    __VdfgRegularize_hebeb780c_0_13 = 0;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_16;
    __VdfgRegularize_hebeb780c_0_16 = 0;
    IData/*31:0*/ __VdfgRegularize_hebeb780c_0_17;
    __VdfgRegularize_hebeb780c_0_17 = 0;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_18;
    __VdfgRegularize_hebeb780c_0_18 = 0;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_19;
    __VdfgRegularize_hebeb780c_0_19 = 0;
    // Body
    vlSelfRef.__VdfgRegularize_hebeb780c_0_12 = (1U 
                                                 & (vlSelfRef.soc_top__DOT__ram
                                                    [
                                                    (0x00000fffU 
                                                     & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                                        >> 2U))] 
                                                    >> 0x0000000cU));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_20 = (1U 
                                                 & (vlSelfRef.soc_top__DOT__ram
                                                    [
                                                    (0x00000fffU 
                                                     & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                                        >> 2U))] 
                                                    >> 0x0000000dU));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_1 = (7U 
                                                & (vlSelfRef.soc_top__DOT__ram
                                                   [
                                                   (0x00000fffU 
                                                    & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                                       >> 2U))] 
                                                   >> 0x0000000cU));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_4 = (0x0000001fU 
                                                & (vlSelfRef.soc_top__DOT__ram
                                                   [
                                                   (0x00000fffU 
                                                    & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                                       >> 2U))] 
                                                   >> 0x0000000fU));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_5 = (0x0000001fU 
                                                & (vlSelfRef.soc_top__DOT__ram
                                                   [
                                                   (0x00000fffU 
                                                    & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                                       >> 2U))] 
                                                   >> 0x00000014U));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_2 = (0x0000001fU 
                                                & (vlSelfRef.soc_top__DOT__ram
                                                   [
                                                   (0x00000fffU 
                                                    & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                                       >> 2U))] 
                                                   >> 7U));
    __VdfgRegularize_hebeb780c_0_6 = (1U & (vlSelfRef.soc_top__DOT__ram
                                            [(0x00000fffU 
                                              & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                                 >> 2U))] 
                                            >> 2U));
    __VdfgRegularize_hebeb780c_0_11 = (1U & (vlSelfRef.soc_top__DOT__ram
                                             [(0x00000fffU 
                                               & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                                  >> 2U))] 
                                             >> 4U));
    __VdfgRegularize_hebeb780c_0_18 = (1U & (vlSelfRef.soc_top__DOT__ram
                                             [(0x00000fffU 
                                               & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                                  >> 2U))] 
                                             >> 3U));
    __VdfgRegularize_hebeb780c_0_19 = (1U & (vlSelfRef.soc_top__DOT__ram
                                             [(0x00000fffU 
                                               & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                                  >> 2U))] 
                                             >> 5U));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_3 = (vlSelfRef.soc_top__DOT__ram
                                                [(0x00000fffU 
                                                  & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                                     >> 2U))] 
                                                >> 0x00000019U);
    __VdfgRegularize_hebeb780c_0_13 = (vlSelfRef.soc_top__DOT__ram
                                       [(0x00000fffU 
                                         & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                            >> 2U))] 
                                       >> 0x0000001fU);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_0 = (0x0000007fU 
                                                & vlSelfRef.soc_top__DOT__ram
                                                [(0x00000fffU 
                                                  & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                                     >> 2U))]);
    __VdfgRegularize_hebeb780c_0_16 = (3U == (3U & vlSelfRef.soc_top__DOT__ram
                                              [(0x00000fffU 
                                                & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                                   >> 2U))]));
    vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a 
        = (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs
           [vlSelfRef.__VdfgRegularize_hebeb780c_0_4] 
           & (- (IData)((0U != (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_4)))));
    vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b 
        = (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__regs
           [vlSelfRef.__VdfgRegularize_hebeb780c_0_5] 
           & (- (IData)((0U != (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_5)))));
    vlSelfRef.soc_top__DOT__u_core__DOT__id_wb_en = 0U;
    vlSelfRef.soc_top__DOT__dcache_we = 0U;
    vlSelfRef.soc_top__DOT__dcache_req = 0U;
    vlSelfRef.soc_top__DOT__u_core__DOT__id_wb_mux = 0U;
    vlSelfRef.soc_top__DOT__u_core__DOT__id_pid_en = 0U;
    vlSelfRef.soc_top__DOT__u_core__DOT__id_alu_op = 0x18U;
    if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                  >> 6U)))) {
        if ((0x00000020U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
            if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                            if ((1U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                                vlSelfRef.soc_top__DOT__dcache_we = 1U;
                            }
                        }
                    }
                }
            }
            if ((0x00000010U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                            if ((1U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                                vlSelfRef.soc_top__DOT__u_core__DOT__id_alu_op 
                                    = ((4U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1))
                                        ? ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1))
                                                ? 0x21U
                                                : 0x20U)
                                            : ((1U 
                                                & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1))
                                                ? (
                                                   (0x00000020U 
                                                    & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3))
                                                    ? 0x1fU
                                                    : 0x1eU)
                                                : 0x1dU))
                                        : ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1))
                                                ? 0x1cU
                                                : 0x1bU)
                                            : ((1U 
                                                & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1))
                                                ? 0x1aU
                                                : (
                                                   (0x00000020U 
                                                    & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3))
                                                    ? 0x19U
                                                    : 0x18U))));
                            }
                        }
                    }
                }
            }
        } else if ((0x00000010U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
            if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                    if ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                        if ((1U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                            vlSelfRef.soc_top__DOT__u_core__DOT__id_alu_op = 0x18U;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                    if ((1U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                        vlSelfRef.soc_top__DOT__u_core__DOT__id_alu_op 
                            = ((4U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1))
                                ? ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1))
                                    ? ((1U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1))
                                        ? 0x21U : 0x20U)
                                    : ((1U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1))
                                        ? ((0x00000020U 
                                            & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3))
                                            ? 0x1fU
                                            : 0x1eU)
                                        : 0x1dU)) : 
                               ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1))
                                 ? ((1U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1))
                                     ? 0x1cU : 0x1bU)
                                 : ((1U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1))
                                     ? 0x1aU : 0x18U)));
                    }
                }
            }
        } else if ((8U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
            if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                    if ((1U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                        vlSelfRef.soc_top__DOT__u_core__DOT__id_alu_op = 0x7fU;
                    }
                }
            }
        }
        if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                      >> 5U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                            if ((1U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                                vlSelfRef.soc_top__DOT__dcache_req = 1U;
                            }
                        }
                    }
                }
                if ((8U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                            if ((1U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                                vlSelfRef.soc_top__DOT__u_core__DOT__id_pid_en = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.soc_top__DOT__u_core__DOT__id_op_a_sel = 0U;
    vlSelfRef.soc_top__DOT__u_core__DOT__id_op_b_sel = 0U;
    if ((0x00000040U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
        if ((0x00000020U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
            if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                          >> 4U)))) {
                if ((4U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                    if ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                        if ((1U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                            vlSelfRef.soc_top__DOT__u_core__DOT__id_wb_en = 1U;
                            vlSelfRef.soc_top__DOT__u_core__DOT__id_wb_mux = 2U;
                        }
                    }
                }
                if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                            if ((1U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                                vlSelfRef.soc_top__DOT__u_core__DOT__id_op_a_sel = 0U;
                                vlSelfRef.soc_top__DOT__u_core__DOT__id_op_b_sel = 0U;
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((0x00000020U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
            if ((0x00000010U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                              >> 3U)))) {
                    if ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                        if ((1U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                            vlSelfRef.soc_top__DOT__u_core__DOT__id_wb_en = 1U;
                        }
                    }
                    if ((4U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                        if ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                            if ((1U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                                vlSelfRef.soc_top__DOT__u_core__DOT__id_op_a_sel = 2U;
                                vlSelfRef.soc_top__DOT__u_core__DOT__id_op_b_sel = 1U;
                            }
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                                 >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                        if ((1U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                            vlSelfRef.soc_top__DOT__u_core__DOT__id_op_b_sel = 1U;
                        }
                    }
                }
            }
        } else if ((0x00000010U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
            if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                          >> 3U)))) {
                if ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                    if ((1U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                        vlSelfRef.soc_top__DOT__u_core__DOT__id_wb_en = 1U;
                        vlSelfRef.soc_top__DOT__u_core__DOT__id_op_b_sel = 1U;
                    }
                }
                if ((4U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                    if ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                        if ((1U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                            vlSelfRef.soc_top__DOT__u_core__DOT__id_op_a_sel = 1U;
                        }
                    }
                }
            }
        } else {
            if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                    if ((1U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                        vlSelfRef.soc_top__DOT__u_core__DOT__id_wb_en = 1U;
                    }
                }
            }
            if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                        if ((1U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                            vlSelfRef.soc_top__DOT__u_core__DOT__id_op_b_sel = 1U;
                        }
                    }
                }
            }
        }
        if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                      >> 5U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                            if ((1U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                                vlSelfRef.soc_top__DOT__u_core__DOT__id_wb_mux = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    __VdfgRegularize_hebeb780c_0_17 = (0xfffff000U 
                                       & (vlSelfRef.soc_top__DOT__ram
                                          [(0x00000fffU 
                                            & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                               >> 2U))] 
                                          & (- (IData)((IData)(__VdfgRegularize_hebeb780c_0_16)))));
    __VdfgRegularize_hebeb780c_0_10 = ((((- (IData)((IData)(__VdfgRegularize_hebeb780c_0_13))) 
                                         << 0x0000000cU) 
                                        | (vlSelfRef.soc_top__DOT__ram
                                           [(0x00000fffU 
                                             & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                                >> 2U))] 
                                           >> 0x00000014U)) 
                                       & (- (IData)((IData)(__VdfgRegularize_hebeb780c_0_16))));
    vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__stall 
        = ((~ (IData)(vlSelfRef.soc_top__DOT__l1_mem_valid)) 
           & (IData)(vlSelfRef.soc_top__DOT__dcache_req));
    vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__error 
        = ((0U == (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_op_a_sel))
            ? vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a
            : (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
               & (- (IData)((1U == (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_op_a_sel))))));
    vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__imm 
        = ((0x00000040U & vlSelfRef.soc_top__DOT__ram
            [(0x00000fffU & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                             >> 2U))]) ? ((- (IData)(
                                                     (1U 
                                                      & (~ (IData)(__VdfgRegularize_hebeb780c_0_11))))) 
                                          & (((IData)(__VdfgRegularize_hebeb780c_0_18)
                                               ? ((
                                                   ((- (IData)((IData)(__VdfgRegularize_hebeb780c_0_13))) 
                                                    << 0x00000014U) 
                                                   | ((((0x000001feU 
                                                         & (vlSelfRef.soc_top__DOT__ram
                                                            [
                                                            (0x00000fffU 
                                                             & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                                                >> 2U))] 
                                                            >> 0x0000000bU)) 
                                                        | (1U 
                                                           & (vlSelfRef.soc_top__DOT__ram
                                                              [
                                                              (0x00000fffU 
                                                               & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                                                  >> 2U))] 
                                                              >> 0x00000014U))) 
                                                       << 0x0000000bU) 
                                                      | (0x000007feU 
                                                         & (vlSelfRef.soc_top__DOT__ram
                                                            [
                                                            (0x00000fffU 
                                                             & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                                                >> 2U))] 
                                                            >> 0x00000014U)))) 
                                                  & (- (IData)(
                                                               (7U 
                                                                == 
                                                                (7U 
                                                                 & vlSelfRef.soc_top__DOT__ram
                                                                 [
                                                                 (0x00000fffU 
                                                                  & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                                                     >> 2U))])))))
                                               : ((IData)(__VdfgRegularize_hebeb780c_0_6)
                                                   ? __VdfgRegularize_hebeb780c_0_10
                                                   : 
                                                  ((((- (IData)((IData)(__VdfgRegularize_hebeb780c_0_13))) 
                                                     << 0x0000000cU) 
                                                    | ((0x00000800U 
                                                        & (vlSelfRef.soc_top__DOT__ram
                                                           [
                                                           (0x00000fffU 
                                                            & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                                               >> 2U))] 
                                                           << 4U)) 
                                                       | ((0x000007e0U 
                                                           & (vlSelfRef.soc_top__DOT__ram
                                                              [
                                                              (0x00000fffU 
                                                               & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                                                  >> 2U))] 
                                                              >> 0x00000014U)) 
                                                          | (0x0000001eU 
                                                             & (vlSelfRef.soc_top__DOT__ram
                                                                [
                                                                (0x00000fffU 
                                                                 & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                                                    >> 2U))] 
                                                                >> 7U))))) 
                                                   & (- (IData)((IData)(__VdfgRegularize_hebeb780c_0_16)))))) 
                                             & (- (IData)((IData)(__VdfgRegularize_hebeb780c_0_19)))))
            : ((IData)(__VdfgRegularize_hebeb780c_0_19)
                ? ((IData)(__VdfgRegularize_hebeb780c_0_11)
                    ? ((- (IData)(((~ (IData)(__VdfgRegularize_hebeb780c_0_18)) 
                                   & (IData)(__VdfgRegularize_hebeb780c_0_6)))) 
                       & __VdfgRegularize_hebeb780c_0_17)
                    : ((((- (IData)((IData)(__VdfgRegularize_hebeb780c_0_13))) 
                         << 0x0000000cU) | (((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3) 
                                             << 5U) 
                                            | (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2))) 
                       & (- (IData)(((~ (IData)(__VdfgRegularize_hebeb780c_0_6)) 
                                     & ((~ (IData)(__VdfgRegularize_hebeb780c_0_18)) 
                                        & (IData)(__VdfgRegularize_hebeb780c_0_16)))))))
                : ((IData)(__VdfgRegularize_hebeb780c_0_11)
                    ? (((IData)(__VdfgRegularize_hebeb780c_0_6)
                         ? __VdfgRegularize_hebeb780c_0_17
                         : __VdfgRegularize_hebeb780c_0_10) 
                       & (- (IData)((1U & (~ (IData)(__VdfgRegularize_hebeb780c_0_18))))))
                    : (__VdfgRegularize_hebeb780c_0_10 
                       & ((- (IData)((1U & (~ (IData)(__VdfgRegularize_hebeb780c_0_18))))) 
                          & (- (IData)((1U & (~ (IData)(__VdfgRegularize_hebeb780c_0_6))))))))));
    vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__next_pc 
        = (((0x6fU == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0)) 
            | ((0x67U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0)) 
               | ((0x63U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0)) 
                  & ((0x00004000U & vlSelfRef.soc_top__DOT__ram
                      [(0x00000fffU & (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                                       >> 2U))]) ? 
                     ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_20)
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
                ? (0xfffffffeU & (vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__imm 
                                  + vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_a))
                : (vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc 
                   + vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__imm))
            : ((IData)(4U) + vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc));
    vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__prev_error 
        = ((0U == (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_op_b_sel))
            ? vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b
            : vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__imm);
    vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__std_result 
        = (((0x00000020U & (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_alu_op))
             ? ((- (IData)((1U & (~ ((IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_alu_op) 
                                     >> 3U))))) & (
                                                   (- (IData)(
                                                              (1U 
                                                               & (~ 
                                                                  ((IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_alu_op) 
                                                                   >> 2U))))) 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & (~ 
                                                                     ((IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_alu_op) 
                                                                      >> 1U))))) 
                                                      & (((1U 
                                                           & (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_alu_op))
                                                           ? 
                                                          (vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__error 
                                                           & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__prev_error)
                                                           : 
                                                          (vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__error 
                                                           | vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__prev_error)) 
                                                         & (- (IData)(
                                                                      (1U 
                                                                       & (~ 
                                                                          ((IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_alu_op) 
                                                                           >> 4U)))))))))
             : (((4U & (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_alu_op))
                  ? ((2U & (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_alu_op))
                      ? ((1U & (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_alu_op))
                          ? VL_SHIFTRS_III(32,32,5, vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__error, 
                                           (0x0000001fU 
                                            & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__prev_error))
                          : (vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__error 
                             >> (0x0000001fU & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__prev_error)))
                      : ((1U & (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_alu_op))
                          ? (vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__error 
                             ^ vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__prev_error)
                          : (1U & (- (IData)((vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__error 
                                              < vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__prev_error))))))
                  : ((2U & (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_alu_op))
                      ? ((1U & (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_alu_op))
                          ? (1U & (- (IData)(VL_LTS_III(32, vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__error, vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__prev_error))))
                          : (vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__error 
                             << (0x0000001fU & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__prev_error)))
                      : ((1U & (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_alu_op))
                          ? (vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__error 
                             - vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__prev_error)
                          : (vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__error 
                             + vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__prev_error)))) 
                & (- (IData)((3U == (3U & ((IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_alu_op) 
                                           >> 3U))))))) 
           & (- (IData)((1U & (~ ((IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_alu_op) 
                                  >> 6U))))));
    vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__p_term 
        = VL_MULS_QQQ(64, 0x0000000000050000ULL, VL_EXTENDS_QI(64,32, vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__error));
    vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__integral_accum 
        = VL_MULS_QQQ(64, 0x0000000000010000ULL, VL_EXTENDS_QI(64,32, vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__error));
    vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__i_term 
        = VL_MULS_QQQ(64, 0x0000000000004cccULL, VL_EXTENDS_QI(64,32, (IData)(
                                                                              (vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__integral_accum 
                                                                               >> 0x10U))));
    vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__error_diff 
        = (vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__error 
           - vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__prev_error);
    vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__d_term 
        = VL_MULS_QQQ(64, 0x0000000000028000ULL, VL_EXTENDS_QI(64,32, vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__error_diff));
    vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__pid_result 
        = (((IData)((vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__p_term 
                     >> 0x10U)) + (IData)((vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__i_term 
                                           >> 0x10U))) 
           + (IData)((vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__d_term 
                      >> 0x10U)));
    if (VL_LTS_III(32, 0x00320000U, vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__pid_result)) {
        vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__pid_result = 0x00320000U;
    } else if (VL_GTS_III(32, 0xffce0000U, vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__pid_result)) {
        vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__pid_result = 0xffce0000U;
    }
    vlSelfRef.soc_top__DOT__u_core__DOT__pid_integ_next 
        = (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__u_pid_alu__DOT__integral_accum);
    vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result 
        = ((IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_pid_en)
            ? vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__pid_result
            : vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__std_result);
    vlSelfRef.soc_top__DOT__io_rdata = 0U;
    if ((0x40000000U == vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)) {
        vlSelfRef.soc_top__DOT__io_rdata = vlSelfRef.ext_sensor_data;
    } else if ((0x40000204U == vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)) {
        vlSelfRef.soc_top__DOT__io_rdata = vlSelfRef.soc_top__DOT__uart_mock_rx_buffer;
    } else if ((0x40000208U == vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)) {
        vlSelfRef.soc_top__DOT__io_rdata = 3U;
    }
    vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
        = ((0x4000U == (vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result 
                        >> 0x00000010U)) ? vlSelfRef.soc_top__DOT__io_rdata
            : vlSelfRef.soc_top__DOT__ram[(0x00000fffU 
                                           & (vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result 
                                              >> 2U))]);
    vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__wdata 
        = ((0U == (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_wb_mux))
            ? vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result
            : ((1U == (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_wb_mux))
                ? ((3U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))
                    ? ((0U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1))
                        ? ((2U & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)
                            ? ((1U & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)
                                ? (((- (IData)((vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                >> 0x0000001fU))) 
                                    << 8U) | (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                              >> 0x00000018U))
                                : (((- (IData)((1U 
                                                & (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                   >> 0x00000017U)))) 
                                    << 8U) | (0x000000ffU 
                                              & (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                 >> 0x00000010U))))
                            : ((1U & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)
                                ? (((- (IData)((1U 
                                                & (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                   >> 0x0000000fU)))) 
                                    << 8U) | (0x000000ffU 
                                              & (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                 >> 8U)))
                                : (((- (IData)((1U 
                                                & (vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata 
                                                   >> 7U)))) 
                                    << 8U) | (0x000000ffU 
                                              & vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata))))
                        : ((4U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1))
                            ? (0x000000ffU & ((2U & vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)
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
                    : vlSelfRef.soc_top__DOT__u_core__DOT__dcache_rdata)
                : ((2U == (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_wb_mux))
                    ? ((IData)(4U) + vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__pc)
                    : vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)));
}

void Vsoc_top___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vsoc_top___024root___eval_phase__act(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_phase__act\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((((~ (IData)(vlSelfRef.rst_n)) 
                                                           & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_n__1)) 
                                                          << 1U) 
                                                         | ((IData)(vlSelfRef.clk) 
                                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__1))))));
        vlSelfRef.__Vtrigprevexpr___TOP__clk__1 = vlSelfRef.clk;
        vlSelfRef.__Vtrigprevexpr___TOP__rst_n__1 = vlSelfRef.rst_n;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsoc_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vsoc_top___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vsoc_top___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vsoc_top___024root___eval_phase__nba(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_phase__nba\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vsoc_top___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_nba
            if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vsoc_top___024root___nba_sequent__TOP__0(vlSelf);
                vlSelfRef.__Vm_traceActivity[1U] = 1U;
            }
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                {
                    // Inlined CFunc: _nba_sequent__TOP__1
                    IData/*31:0*/ __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___VdlyVal__soc_top__DOT__ram__v0;
                    __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___VdlyVal__soc_top__DOT__ram__v0 = 0;
                    SData/*11:0*/ __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___VdlyDim0__soc_top__DOT__ram__v0;
                    __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___VdlyDim0__soc_top__DOT__ram__v0 = 0;
                    CData/*0:0*/ __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___VdlySet__soc_top__DOT__ram__v0;
                    __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___VdlySet__soc_top__DOT__ram__v0 = 0;
                    if (((((IData)(vlSelfRef.rst_n) 
                           & (IData)(vlSelfRef.soc_top__DOT__dcache_we)) 
                          & (IData)(vlSelfRef.soc_top__DOT__dcache_req)) 
                         & (0x40000200U == vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result))) {
                        if (VL_UNLIKELY((((0x20U <= 
                                           (0x000000ffU 
                                            & vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b)) 
                                          & (0x7eU 
                                             >= (0x000000ffU 
                                                 & vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b)))))) {
                            VL_WRITEF_NX("%c",1, '#',8,
                                         (0x000000ffU 
                                          & vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b));
                        }
                        if (VL_UNLIKELY(((0xffU == 
                                          (0x000000ffU 
                                           & vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b))))) {
                            VL_WRITEF_NX("\n[VERIFICATION] RESULT: PASS (0xFF detected)\n",0);
                            VL_FINISH_MT("../../rtl/core/../../rtl/soc_top.sv", 169, "");
                        } else if (VL_UNLIKELY(((0xeeU 
                                                 == 
                                                 (0x000000ffU 
                                                  & vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b))))) {
                            VL_WRITEF_NX("\n[VERIFICATION] RESULT: FAIL (0xEE detected)\n[%0t] %%Fatal: soc_top.sv:172: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"soc_top", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1));
                            VL_STOP_MT("../../rtl/core/../../rtl/soc_top.sv", 172, "", false);
                        }
                    }
                    __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___VdlySet__soc_top__DOT__ram__v0 = 0U;
                    if ((((IData)(vlSelfRef.soc_top__DOT__dcache_we) 
                          & (IData)(vlSelfRef.soc_top__DOT__dcache_req)) 
                         & (~ (vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result 
                               >> 0x1eU)))) {
                        __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___VdlyVal__soc_top__DOT__ram__v0 
                            = vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b;
                        __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___VdlyDim0__soc_top__DOT__ram__v0 
                            = (0x00000fffU & (vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result 
                                              >> 2U));
                        __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___VdlySet__soc_top__DOT__ram__v0 = 1U;
                    }
                    if (vlSelfRef.rst_n) {
                        if (((IData)(vlSelfRef.soc_top__DOT__u_core__DOT__id_pid_en) 
                             & (~ (IData)(vlSelfRef.soc_top__DOT__u_core__DOT__u_fetch__DOT__stall)))) {
                            vlSelfRef.soc_top__DOT__u_core__DOT__pid_integ 
                                = vlSelfRef.soc_top__DOT__u_core__DOT__pid_integ_next;
                        }
                        if (((IData)(vlSelfRef.soc_top__DOT__dcache_we) 
                             & (IData)(vlSelfRef.soc_top__DOT__dcache_req))) {
                            if ((0x40000100U == vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)) {
                                vlSelfRef.motor_pwm 
                                    = (0x0000000fU 
                                       & vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b);
                            }
                            if ((0x40000100U != vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)) {
                                if ((0x40000200U == vlSelfRef.soc_top__DOT__u_core__DOT__u_execute__DOT__alu_result)) {
                                    vlSelfRef.soc_top__DOT__uart_mock_rx_buffer 
                                        = (0x000000ffU 
                                           & vlSelfRef.soc_top__DOT__u_core__DOT__u_decode__DOT__u_regfile__DOT__rdata_b);
                                }
                            }
                        }
                    } else {
                        vlSelfRef.soc_top__DOT__u_core__DOT__pid_integ = 0U;
                        vlSelfRef.motor_pwm = 0U;
                        vlSelfRef.soc_top__DOT__uart_mock_rx_buffer = 0U;
                    }
                    if (__Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___VdlySet__soc_top__DOT__ram__v0) {
                        vlSelfRef.soc_top__DOT__ram[__Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___VdlyDim0__soc_top__DOT__ram__v0] 
                            = __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___VdlyVal__soc_top__DOT__ram__v0;
                    }
                }
            }
            if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vsoc_top___024root___nba_comb__TOP__0(vlSelf);
                vlSelfRef.__Vm_traceActivity[2U] = 1U;
            }
        }
        Vsoc_top___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vsoc_top___024root___eval(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vsoc_top___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("../../rtl/core/../../rtl/soc_top.sv", 1, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vsoc_top___024root___eval_phase__ico(vlSelf);
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vsoc_top___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("../../rtl/core/../../rtl/soc_top.sv", 1, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vsoc_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("../../rtl/core/../../rtl/soc_top.sv", 1, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vsoc_top___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vsoc_top___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vsoc_top___024root___eval_debug_assertions(Vsoc_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc_top___024root___eval_debug_assertions\n"); );
    Vsoc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");
    }
    if (VL_UNLIKELY(((vlSelfRef.spi_miso & 0xfeU)))) {
        Verilated::overWidthError("spi_miso");
    }
}
#endif  // VL_DEBUG
