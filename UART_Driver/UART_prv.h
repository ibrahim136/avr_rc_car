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
		struct{
			u8 UBRR :8;
		};
	};
		
	
	
	}UART_Registers_t;




#endif /* UART_PRV_H_ */