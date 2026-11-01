/*
 * UART_prv.h
 *
 * Created: 10/18/2026 2:04:58 PM
 *  Author: Ibrahim Haggag
 */ 


#ifndef UART_PRV_H_
#define UART_PRV_H_

typedef struct{
	union
	{
		u8 UBRRL;
		u8 UCSRB;
		u8 UCSRA;
		u8 UDR;
		
	};
		
	
	
	}UART_Registers_t;




#endif /* UART_PRV_H_ */