/*
 * UartFunctions.c
 *
 * Created: 7/9/2013 1:28:22 PM
 *  Author: Elmar
 */ 
#include <sam4s.h>
#include "UartFunctions.h"
#include "PinFunctions.h"
#include "CircularBuffer.h"

CircularBuffer uart_inBuffer;
CircularBuffer uart_outBuffer;
static Uart *uart;
static void (*receiveEvent) (char);

void uart_init(uint32_t address){	
	uart = (Uart *) address;
	uart->UART_CR = UART_CR_TXEN | UART_CR_RXEN;		//enable transmiting and receiving
	uart->UART_MR = UART_MR_PAR_NO;						//no parity
	uart->UART_BRGR = 65;								//Pre scaler for 38kBaud
	//PMC->PMC_WPMR = PMC->PMC_WPMR | (1<<0);				//disable write protect
	PMC->PMC_PCER0 = 1 << ID_UART1;						//Enable UART1 clock
	circularBuffer_init(&uart_inBuffer);
	circularBuffer_init(&uart_outBuffer);
}

void UART1_Handler(){	
	uint32_t interruptStatus = uart->UART_SR;
	if(interruptStatus & UART_SR_RXRDY){
		char data = uart->UART_RHR;
		circularBuffer_writeByte(&uart_inBuffer, data);
		receiveEvent(data);
	}
	if(interruptStatus & UART_SR_TXRDY && uart->UART_IMR & UART_IMR_TXRDY){
		static char data;
		int8_t dataLeft = circularBuffer_readByte(&uart_outBuffer, & data);
 		if(dataLeft == 1){
			uart->UART_THR = data;
		} else{
			uart->UART_IDR = UART_IDR_TXRDY;
		}		
	}
	
}

void uart_interruptInit(){
	NVIC_EnableIRQ(9);
	uart->UART_IER = UART_IER_RXRDY;	//interrupt on new read and write
}

void uart_sendBytesBlocking(char * data, uint8_t length){
	uint8_t index = 0;
	while(index<length){
		uart->UART_THR = data[index];
		while((uart->UART_SR & UART_SR_TXRDY) == 0);
		index++;
	}	
}

void uart_readBytesBlocking(char * data, uint8_t length){
	uint8_t index = 0;
	while (index<length){
		while((uart->UART_SR & UART_SR_RXRDY) == 0);
		data[index] = uart->UART_RHR;
		index++;
	}	
}

void uart_sendBytes(char *start, uint8_t size){
	int index = 0;
	while(index<size){
		circularBuffer_writeByte(&uart_outBuffer,start[index]);
		index++;
	}
	uart->UART_IER = UART_IER_TXRDY;
}

uint8_t uart_receiveBytes(char * startAdress, uint8_t size){
	return circularBuffer_read(&uart_inBuffer,&startAdress, size);
}

void uart_setReceiveEvent(void (*_receiveEvent) (char)){
	receiveEvent = _receiveEvent;
}

