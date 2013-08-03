/*
 * PinFunctions.h
 *
 * Created: 7/8/2013 10:11:01 PM
 *  Author: Elmar
 */ 


#ifndef PINFUNCTIONS_H_
#define PINFUNCTIONS_H_

#include <sam4s.h>
#include "Commons.h"

void setSinglePin(uint32_t pin, Pio *pio, uint8_t level);
void setPins(uint32_t pins, Pio *pio, uint8_t level);
void togglePin(uint32_t pin, Pio *pio);
void toggleLed(uint8_t ledNr);

#endif /* PINFUNCTIONS_H_ */