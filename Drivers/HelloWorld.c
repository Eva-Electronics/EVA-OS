#include <sam4s.h>
#include "Commons.h"
#include "UartFunctions.h"
#include "PinFunctions.h"
#include "I2C.h"

#define TERMINATIONCHAR '\n'

enum ReceiveUartState {
	NONE, I, ID;
} receiveUartState;

void uartReact(char data)
{
	if(data == TERMINATIONCHAR){
		char data = circularBuffer_readByte(uart_rec);
		int8_t len = 0;
		do {
			switch (receiveUartState){
				case NONE:
					if(data == 'i' || data == 'I')
						receiveUartState = I;
				break;
				case I:
					if(data == 'd' || data == 'D')
						receiveUartState = ID;
				break;
				case ID: 
					uart_sendBytes()
					uart_sendBytes();
					receiveUartState = NONE;
				break;
			}
		} while ((len = circularBuffer_read(,data,1)) != -1);
		char hello[5] = "hello";
		uart_sendBytes(hello, 5);	
	}	
}

int main(void)
{
	SystemInit();										//Initialize the SAM system
	WDT->WDT_MR = WDT_MR_WDDIS;							//Disable watchdog
	
	PIOA->PIO_PDR = (1<<TWIDATAPIN) | (1<<TWICLOCKPIN); //disable pio for peripheral use
	PIOB->PIO_PDR = (1<<UARTTXPIN) | (1<<UARTRXPIN);	//disable pio for peripheral use
	
	PIOC->PIO_PER = (1<<LED0PIN)|(1<<LED1PIN);			// enable register
	PIOC->PIO_OER = (1<<LED0PIN)|(1<<LED1PIN);			// Output Enable Register
	PIOC->PIO_SODR	= (1<<LED0PIN)|(1<<LED1PIN);		// Set output data register
	
	PIOA->PIO_PER = (1<<TWIDATAPIN) | (1<<TWICLOCKPIN); // enable register
	PIOA->PIO_OER = (1<<TWIDATAPIN) | (1<<TWICLOCKPIN); // Output Enable Register
	PIOA->PIO_SODR = (1<<TWIDATAPIN) | (1<<TWICLOCKPIN); // Set output data register
	
	//i2c_setUp((uint32_t)TWI0);
	//uart_setReceiveEvent(uartReact);					// Set up
	//uart_init((uint32_t)UART1);							// Set up UART registers
	//uart_interruptInit();								// Set up UART interrupt registers
	
	while (1) {	
		setSinglePin(TWIDATAPIN,PIOA,HIGH);
		setSinglePin(TWIDATAPIN,PIOA,LOW);
		PIOA->PIO_T
	}
}
