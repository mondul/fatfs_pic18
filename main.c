/* 
 * File:   main.c
 * Author: mondul
 *
 * Created on 29 Jul 2015, 12:01
 */

#include "hardware.h"
#include "ff.h"

FATFS FatFs;	/* FatFs work area needed for each volume */
FIL Fil;		/* File object needed for each open file */

/*
 * 
 */
void main(void) {
	UINT bw;

	configOsc();
	initPorts();

	if (f_mount(&FatFs, "", 1) == FR_OK) {	/* Mount SD */

		if (f_open(&Fil, "hello.txt", FA_OPEN_ALWAYS | FA_READ | FA_WRITE) == FR_OK) {	/* Open or create a file */

			if ((Fil.fsize != 0) && (f_lseek(&Fil, Fil.fsize) != FR_OK)) goto endSD;	/* Jump to the end of the file */

			f_write(&Fil, "Hello world!\r\n", 14, &bw);	/* Write data to the file */

			endSD: f_close(&Fil);								/* Close the file */
		}
	}

	for (;;);

}
