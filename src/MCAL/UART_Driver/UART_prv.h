/*
* UART_prv.h
*
* Created: 10/18/2026 2:04:58 PM
*  Author: Ibrahim Haggag
*/
#include "../STD_Types_and_BIT_Math/STD_TYPES.h"

#ifndef UART_PRV_H_
#define UART_PRV_H_

typedef struct{
	u8 UBRRL;
	u8 UCSRB;
	u8 UCSRA;
	u8 UDR;
	u8 Reserved[19];
	union
	{
		u8 UCSRC;
		u8 UBRRH;
	};
	
}USART_Registers_t;

#define USART_BASE ((volatile u8*) (0x29))
#define USART_Registers ((volatile USART_Registers_t *) (USART_BASE))

#define RXC 7
#define UDRE 5
#define RXEN 4
#define TXEN 3
#define UCSZ2 2
#define URSEL 7
#define UMSEL 6
#define UPM1 5
#define UPM0 4
#define USBS 3
#define UCSZ0 1
#define UCSZ2 2
#define UCSZ0_1_Bits_Mask (0x03<< UCSZ0)



#endif /* UART_PRV_H_ */