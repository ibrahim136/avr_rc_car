#include "STD_Types_and_BIT_Math/STD_TYPES.h"
#include "STD_Types_and_BIT_Math/BIT_MATH.h"
#include "DIO_Driver/DIO_int.h"
#include "GIE_Driver/GIE_int.h"
#include "EXTI_Driver/EXTI_int.h"
#include "ADC_Driver/ADC_int.h"
#include "Timer_driver/Timer_int.h"
#include "UART_Driver/UART_int.h"
#define F_CPU 8000000
//#include <util/delay.h>

// Tick Time = 8 /8Mhz = 1ms
// overflow time = 256
// desired time = 1sec
// overflow count = 3906.25

//preload (1-0.25) * 256 = 192
// counter = 3907



int main(void)
{
	u8 Loc_var =0;
	UART_voidInit();
	DIO_voidSetPinDirection(PORTA,PIN0,PIN_Output);
	DIO_voidSetPinDirection(PORTA,PIN1,PIN_Output);
	DIO_voidSetPinDirection(PORTA,PIN2,PIN_Output);
	
	DIO_voidSetPinDirection(PORTA,PIN7,PIN_Input);
	DIO_voidSetPinDirection(PORTB,PIN3,PIN_Output);
	//DIO_voidSetPinDirection(PORTD,PIN0,PIN_Input);
	ADC_voidInit();
	u16 reading;
	u8 value;
	TIM0_voidInit(Prescaller8);
	
	while(1)
	{
		Loc_var = UART_u8Recieve();
		switch(Loc_var)
		{
			case '1':
			DIO_voidTogglePinValue(PORTA,PIN0);
			break;
			case '2':
			DIO_voidTogglePinValue(PORTA,PIN1);
			break;
			case '3':
			DIO_voidTogglePinValue(PORTA,PIN2);
			break;
			default:
			break;
		}
		reading = ADC_u16StartConversion(channel_7);
		value = Mapping(1023,0,255,0,reading);
		TIM0_voidCTCSetCompareValue(255-value);
	}
}

