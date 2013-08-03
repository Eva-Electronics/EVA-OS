/*
 * PinFunctions.c
 *
 * Created: 7/8/2013 10:11:17 PM
 *  Author: Elmar
 */ 

#include "PinFunctions.h"

void setPins(uint32_t pins, Pio *pio, uint8_t level){
	if (level == HIGH) {
		pio->PIO_SODR = pins;
	} else {
		pio->PIO_CODR = pins;
	}	
}

void setSinglePin(uint32_t pin, Pio *pio, uint8_t level){
	if (level == HIGH) {
		pio->PIO_SODR = (1<<pin);
	} else {
		pio->PIO_CODR = (1<<pin);
	}	
}

void togglePin(uint32_t pin, Pio *pio){
	if (pio->PIO_ODSR & (1 << pin)) {	// Pin output data status register 
		pio->PIO_CODR = (1 << pin);		// Pin clear output register (set low)
	} else {
		pio->PIO_SODR = (1 << pin);		// Pin set output register (set high)
	}
}

void toggleLed(uint8_t ledNr){
	switch(ledNr){
		case 1:
			togglePin(LED0PIN,LEDPORT);
		break;
		case 2:
			togglePin(LED1PIN,LEDPORT);
		break;
	}
}