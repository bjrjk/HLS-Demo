// ==============================================================
// File generated on Sat Jan 30 00:12:24 +0800 2021
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xplus_test.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XPlus_test_CfgInitialize(XPlus_test *InstancePtr, XPlus_test_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Axilites_BaseAddress = ConfigPtr->Axilites_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XPlus_test_Start(XPlus_test *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XPlus_test_ReadReg(InstancePtr->Axilites_BaseAddress, XPLUS_TEST_AXILITES_ADDR_AP_CTRL) & 0x80;
    XPlus_test_WriteReg(InstancePtr->Axilites_BaseAddress, XPLUS_TEST_AXILITES_ADDR_AP_CTRL, Data | 0x01);
}

u32 XPlus_test_IsDone(XPlus_test *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XPlus_test_ReadReg(InstancePtr->Axilites_BaseAddress, XPLUS_TEST_AXILITES_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XPlus_test_IsIdle(XPlus_test *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XPlus_test_ReadReg(InstancePtr->Axilites_BaseAddress, XPLUS_TEST_AXILITES_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XPlus_test_IsReady(XPlus_test *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XPlus_test_ReadReg(InstancePtr->Axilites_BaseAddress, XPLUS_TEST_AXILITES_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XPlus_test_EnableAutoRestart(XPlus_test *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XPlus_test_WriteReg(InstancePtr->Axilites_BaseAddress, XPLUS_TEST_AXILITES_ADDR_AP_CTRL, 0x80);
}

void XPlus_test_DisableAutoRestart(XPlus_test *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XPlus_test_WriteReg(InstancePtr->Axilites_BaseAddress, XPLUS_TEST_AXILITES_ADDR_AP_CTRL, 0);
}

u32 XPlus_test_Get_return(XPlus_test *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XPlus_test_ReadReg(InstancePtr->Axilites_BaseAddress, XPLUS_TEST_AXILITES_ADDR_AP_RETURN);
    return Data;
}
void XPlus_test_Set_x(XPlus_test *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XPlus_test_WriteReg(InstancePtr->Axilites_BaseAddress, XPLUS_TEST_AXILITES_ADDR_X_DATA, Data);
}

u32 XPlus_test_Get_x(XPlus_test *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XPlus_test_ReadReg(InstancePtr->Axilites_BaseAddress, XPLUS_TEST_AXILITES_ADDR_X_DATA);
    return Data;
}

void XPlus_test_InterruptGlobalEnable(XPlus_test *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XPlus_test_WriteReg(InstancePtr->Axilites_BaseAddress, XPLUS_TEST_AXILITES_ADDR_GIE, 1);
}

void XPlus_test_InterruptGlobalDisable(XPlus_test *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XPlus_test_WriteReg(InstancePtr->Axilites_BaseAddress, XPLUS_TEST_AXILITES_ADDR_GIE, 0);
}

void XPlus_test_InterruptEnable(XPlus_test *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XPlus_test_ReadReg(InstancePtr->Axilites_BaseAddress, XPLUS_TEST_AXILITES_ADDR_IER);
    XPlus_test_WriteReg(InstancePtr->Axilites_BaseAddress, XPLUS_TEST_AXILITES_ADDR_IER, Register | Mask);
}

void XPlus_test_InterruptDisable(XPlus_test *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XPlus_test_ReadReg(InstancePtr->Axilites_BaseAddress, XPLUS_TEST_AXILITES_ADDR_IER);
    XPlus_test_WriteReg(InstancePtr->Axilites_BaseAddress, XPLUS_TEST_AXILITES_ADDR_IER, Register & (~Mask));
}

void XPlus_test_InterruptClear(XPlus_test *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XPlus_test_WriteReg(InstancePtr->Axilites_BaseAddress, XPLUS_TEST_AXILITES_ADDR_ISR, Mask);
}

u32 XPlus_test_InterruptGetEnabled(XPlus_test *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XPlus_test_ReadReg(InstancePtr->Axilites_BaseAddress, XPLUS_TEST_AXILITES_ADDR_IER);
}

u32 XPlus_test_InterruptGetStatus(XPlus_test *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XPlus_test_ReadReg(InstancePtr->Axilites_BaseAddress, XPLUS_TEST_AXILITES_ADDR_ISR);
}

