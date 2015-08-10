/**
  Generated Main Source File

  Company:
	Microchip Technology Inc.

  File Name:
	main.c

  Summary:
	This is the main file generated using MPLAB® Code Configurator

  Description:
	This header file provides implementations for driver APIs for all modules selected in the GUI.
	Generation Information :
		Product Revision  :  MPLAB® Code Configurator - v2.25.2
		Device            :  PIC18F25K20
		Driver Version    :  2.00
	The generated drivers are tested against the following:
		Compiler          :  XC8 v1.34
		MPLAB             :  MPLAB X v2.35 or v3.00
 */

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 */

#include "mcc_generated_files/mcc.h"
#include "ff.h"

FATFS FatFs;	/* FatFs work area needed for each volume */
FIL Fil;		/* File object needed for each open file */


/*
						 Main application
 */
void main(void) {
	UINT bw;

	// Initialize the device
	SYSTEM_Initialize();

	// If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
	// If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
	// Use the following macros to:

	// Enable high priority global interrupts
	//INTERRUPT_GlobalInterruptHighEnable();

	// Enable low priority global interrupts.
	//INTERRUPT_GlobalInterruptLowEnable();

	// Disable high priority global interrupts
	//INTERRUPT_GlobalInterruptHighDisable();

	// Disable low priority global interrupts.
	//INTERRUPT_GlobalInterruptLowDisable();

	// Enable the Global Interrupts
	//INTERRUPT_GlobalInterruptEnable();

	// Enable the Peripheral Interrupts
	//INTERRUPT_PeripheralInterruptEnable();

	// Disable the Global Interrupts
	//INTERRUPT_GlobalInterruptDisable();

	// Disable the Peripheral Interrupts
	//INTERRUPT_PeripheralInterruptDisable();

	if (f_mount(&FatFs, "", 1) == FR_OK) {	/* Mount SD */

		if (f_open(&Fil, "hello.txt", FA_OPEN_ALWAYS | FA_READ | FA_WRITE) == FR_OK) {	/* Open or create a file */

			if ((Fil.fsize != 0) && (f_lseek(&Fil, Fil.fsize) != FR_OK)) goto endSD;	/* Jump to the end of the file */

			f_write(&Fil, "Hello world!\r\n", 14, &bw);	/* Write data to the file */

			endSD: f_close(&Fil);								/* Close the file */
		}
	}

	while (1) {
		// Add your application code
	}
}
/**
 End of File
 */