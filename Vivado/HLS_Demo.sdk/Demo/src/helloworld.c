/******************************************************************************
 *
 * Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * Use of the Software is limited solely to applications:
 * (a) running on a Xilinx device, or
 * (b) that interact with a Xilinx device through a bus or interconnect.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Except as contained in this notice, the name of the Xilinx shall not be used
 * in advertising or otherwise to promote the sale, use or other dealings in
 * this Software without prior written authorization from Xilinx.
 *
 ******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "stdio_d.h"
#include "platform.h"
#include "xil_printf.h"
#include "xplus_test.h"
#include "xparameters.h"
#include "xuartps.h"
#include "sleep.h"

int main()
{
	init_platform();

	xil_printf("This is Jack's first HLS Experiment:\n\r");


	//Resource Initialize
	XPlus_test HLS_XPlus_test;
	XPlus_test_Config* HLS_XPlus_test_ptr;
	HLS_XPlus_test_ptr = XPlus_test_LookupConfig(XPAR_PLUS_TEST_0_DEVICE_ID);
	if (!HLS_XPlus_test_ptr)
	{
		xil_printf("ERROR: Lookup of accelerator configuration failed.\n\r");
		return XST_FAILURE;
	}
	xil_printf("Initialize the device\n\r");
	long status = XPlus_test_CfgInitialize(&HLS_XPlus_test, HLS_XPlus_test_ptr);
	if (status != XST_SUCCESS)
	{
		xil_printf("ERROR: Could not initialize accelerator.\n\r");
		return(-1);
	}

	while(1){
		xil_printf("Input a num:");
		int x = getulong();

		XPlus_test_Set_x(&HLS_XPlus_test, x);
		XPlus_test_Initialize(&HLS_XPlus_test, XPAR_PLUS_TEST_0_DEVICE_ID);

		XPlus_test_Start(&HLS_XPlus_test);
		while(XPlus_test_IsDone(&HLS_XPlus_test) == 0);

		int result = XPlus_test_Get_return(&HLS_XPlus_test);
		xil_printf("Output:%d\n\r",result);
	}

	cleanup_platform();
	return 0;
}
