/*
* UART_int.h
*
* Created: 10/18/2026 2:05:12 PM
*  Author: Ibrahim Haggag
*/



#ifndef UART_INT_H_
#define UART_INT_H_

#include "../STD_Types_and_BIT_Math/STD_TYPES.h"

typedef enum{
	bit_5=0,
	bit_6=1,
	bit_7=2,
	bit_8=3,
	bit_9=3
	
}UCSZ_Bits_Settings_t;

void UART_voidInit(void);
void UART_voidTransmit(u8 Copy_u8Data);
u8 UART_u8Recieve(void);
void UART_voidSetCallBack(void (*Copy_pVoidCallBack)(u8));

#endif 