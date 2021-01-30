// ==============================================================
// File generated on Sat Jan 30 00:12:24 +0800 2021
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xplus_test.h"

extern XPlus_test_Config XPlus_test_ConfigTable[];

XPlus_test_Config *XPlus_test_LookupConfig(u16 DeviceId) {
	XPlus_test_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XPLUS_TEST_NUM_INSTANCES; Index++) {
		if (XPlus_test_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XPlus_test_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XPlus_test_Initialize(XPlus_test *InstancePtr, u16 DeviceId) {
	XPlus_test_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XPlus_test_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XPlus_test_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

