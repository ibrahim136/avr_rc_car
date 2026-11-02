#include "../STD_Types_and_BIT_Math/STD_TYPES.h"
#include "../STD_Types_and_BIT_Math/BIT_MATH.h"
#include "UART_prv.h"
#include "UART_int.h"
#include "UART_cfg.h"

static void (*UART_GlobalCallBack)(u8) = NULL;

void UART_voidInit(void)
{
	u8 Loc_u8Var=0;
	SET_BIT(Loc_u8Var,URSEL);
	CLR_BIT(Loc_u8Var,UMSEL);
	CLR_BIT(Loc_u8Var,UPM0);
	CLR_BIT(Loc_u8Var,UPM1);
	CLR_BIT(Loc_u8Var,USBS);
	CLEAR_MASK(Loc_u8Var,UCSZ0_1_Bits_Mask);
	SET_MASK(Loc_u8Var,bit_8<<UCSZ0);
	CLR_BIT(USART_Registers->UCSRB,UCSZ2);	
	
	USART_Registers->UCSRC = Loc_u8Var;
	
	USART_Registers->UBRRL = 51;
	
	SET_BIT(USART_Registers->UCSRB,RXEN);
	SET_BIT(USART_Registers->UCSRB,TXEN);

	SET_BIT(USART_Registers->UCSRB, RXCIE);
}

void UART_voidTransmit(u8 Copy_u8Data)
{
	while (GET_BIT(USART_Registers->UCSRA,UDRE) == 0);
	USART_Registers->UDR = Copy_u8Data;
}

u8 UART_u8Recieve(void)
{
	while (GET_BIT(USART_Registers->UCSRA,RXC) == 0);
	return USART_Registers->UDR;
}

void UART_voidSetCallBack(void (*Copy_pVoidCallBack)(u8))
{
	if (Copy_pVoidCallBack != NULL_PTR)
	{
		UART_GlobalCallBack = Copy_pVoidCallBack;
	}
}

void __vector_13(void) __attribute__ ((signal,used,externally_visible)); \
void __vector_13(void)
{
	u8 Loc_u8ReceivedData = USART_Registers->UDR;
	if (UART_GlobalCallBack != NULL_PTR){
		UART_GlobalCallBack(Loc_u8ReceivedData);	
	}
}