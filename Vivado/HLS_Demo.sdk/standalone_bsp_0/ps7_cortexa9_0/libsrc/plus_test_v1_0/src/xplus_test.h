// ==============================================================
// File generated on Sat Jan 30 00:12:24 +0800 2021
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XPLUS_TEST_H
#define XPLUS_TEST_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xplus_test_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Axilites_BaseAddress;
} XPlus_test_Config;
#endif

typedef struct {
    u32 Axilites_BaseAddress;
    u32 IsReady;
} XPlus_test;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XPlus_test_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XPlus_test_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XPlus_test_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XPlus_test_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XPlus_test_Initialize(XPlus_test *InstancePtr, u16 DeviceId);
XPlus_test_Config* XPlus_test_LookupConfig(u16 DeviceId);
int XPlus_test_CfgInitialize(XPlus_test *InstancePtr, XPlus_test_Config *ConfigPtr);
#else
int XPlus_test_Initialize(XPlus_test *InstancePtr, const char* InstanceName);
int XPlus_test_Release(XPlus_test *InstancePtr);
#endif

void XPlus_test_Start(XPlus_test *InstancePtr);
u32 XPlus_test_IsDone(XPlus_test *InstancePtr);
u32 XPlus_test_IsIdle(XPlus_test *InstancePtr);
u32 XPlus_test_IsReady(XPlus_test *InstancePtr);
void XPlus_test_EnableAutoRestart(XPlus_test *InstancePtr);
void XPlus_test_DisableAutoRestart(XPlus_test *InstancePtr);
u32 XPlus_test_Get_return(XPlus_test *InstancePtr);

void XPlus_test_Set_x(XPlus_test *InstancePtr, u32 Data);
u32 XPlus_test_Get_x(XPlus_test *InstancePtr);

void XPlus_test_InterruptGlobalEnable(XPlus_test *InstancePtr);
void XPlus_test_InterruptGlobalDisable(XPlus_test *InstancePtr);
void XPlus_test_InterruptEnable(XPlus_test *InstancePtr, u32 Mask);
void XPlus_test_InterruptDisable(XPlus_test *InstancePtr, u32 Mask);
void XPlus_test_InterruptClear(XPlus_test *InstancePtr, u32 Mask);
u32 XPlus_test_InterruptGetEnabled(XPlus_test *InstancePtr);
u32 XPlus_test_InterruptGetStatus(XPlus_test *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
