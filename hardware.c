/* 
 * File:   hardware.h
 * Author: mondul
 *
 * Created on 29 Jul 2015, 11:52
 */

#include "hardware.h"

/**
 * Internal osc configuration
 */
inline void configOsc() {
	OSCCONbits.IRCF = 0b111; // Internal osc at 16 MHz
	__delay_us(2);
}

/**
 * Function for init ports
 */
inline void initPorts() {
	// Port A
	// RA7 -> Not connected
	// RA6 -> Not connected
	// RA5 -> Not connected
	// RA4 -> Not connected
	// RA3 -> Not connected
	// RA2 -> Not connected
	// RA1 -> Not connected
	// RA0 -> Not connected
	PORTA = 0;
	LATA = 0;
	ANSEL = 0;
	TRISA = 0;

	// Port B
	// RB7 -> Not connected (PGD)
	// RB6 -> Not connected (PGC)
	// RB5 -> Not connected
	// RB4 -> Not connected
	// RB3 -> Not connected
	// RB2 -> Not connected
	// RB1 -> Not connected
	// RB0 -> Not connected
	PORTB = 0;
	LATB = 0;
	ANSELH = 0;
	TRISB = 0;

	// Port C
	// RC7 -> Not connected
	// RC6 -> Not connected
	// RC5 -> SD MOSI
	// RC4 <- SD MISO
	// RC3 -> SD SCK
	// RC2 -> SD CS
	// RC1 -> Not connected
	// RC0 -> Not connected
	PORTC = 0;
	LATC = 0;
	TRISC = 0b00010000;

	// Port E
	// RE3 <- Not connected (MCLR)

	// Disable SD by pulling high its chip selection pin
	SD_CS = 1;
}
