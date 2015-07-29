/* 
 * File:   hardware.h
 * Author: mondul
 *
 * Created on 29 Jul 2015, 11:52
 */

#ifndef HARDWARE_H
#define	HARDWARE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "config.h"

	/**
	 * Osc frequency for delays
     */
#define _XTAL_FREQ 16E6

	/**
	 * Pin aliases
     */
#define SD_CS	LATCbits.LATC2

	/**
	 * Function declarations
     */
	inline void configOsc();
	inline void initPorts();

#ifdef	__cplusplus
}
#endif

#endif	/* HARDWARE_H */

