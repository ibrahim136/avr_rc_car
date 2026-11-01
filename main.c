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
	u16 reading=0;
	u16 value = 0;
	ADC_voidInit();
	TIM0_voidInit(Prescaller8);
	
	DIO_voidSetPinDirection(PORTA,PIN0,PIN_Input);
	
	DIO_voidSetPinDirection(PORTB,PIN3,PIN_Output);
	while(1)
	{
		reading= ADC_u16StartConversion(channel_0);
		value = Mapping(1023,0,255,0,reading);
		TIM0_voidCTCSetCompareValue(value);
	}
}

