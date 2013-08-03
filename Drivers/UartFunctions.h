/*
 * UartFunctions.h
 *
 * Created: 7/9/2013 9:48:24 PM
 *  Author: Elmar
 */ 


#ifndef UARTFUNCTIONS_H_
#define UARTFUNCTIONS_H_

void uart_interrupt_init();
void uart_init(uint32_t address);
void uart_setReceiveEvent(void (*_receiveEvent) (char));
void uart_sendBytes(char *start, uint8_t size);
void uart_readBytesBlocking(char * data, uint8_t length);
void uart_sendBytesBlocking(char * data, uint8_t length);
uint8_t uart_receiveBytes(char * startAdress, uint8_t size);

#endif /* UARTFUNCTIONS_H_ */