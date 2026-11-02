#include "MCAL/STD_Types_and_BIT_Math/STD_TYPES.h"
#include "MCAL/STD_Types_and_BIT_Math/BIT_MATH.h"
#include "MCAL/DIO_Driver/DIO_int.h"
#include "MCAL/GIE_Driver/GIE_int.h"
#include "MCAL/EXTI_Driver/EXTI_int.h"
#include "MCAL/ADC_Driver/ADC_int.h"
#include "MCAL/Timer_driver/Timer_int.h"
#include "MCAL/UART_Driver/UART_int.h"
#define F_CPU 8000000
#include <util/delay.h>

// Tick Time = 8 /8Mhz = 1ms
// overflow time = 256
// desired time = 1sec
// overflow count = 3906.25

//preload (1-0.25) * 256 = 192
// counter = 3907



int main(void)
{
	/*DIO_voidSetPinDirection(PORTA,PIN7,PIN_Input);
	DIO_voidSetPinDirection(PORTB,PIN3,PIN_Output);
	//DIO_voidSetPinDirection(PORTD,PIN0,PIN_Input);
	ADC_voidInit();
	u16 reading;
	u8 value;
	TIM0_voidInit(Prescaller8);
	
	while(1)
	{
		
		reading = ADC_u16StartConversion(channel_7);
		value = Mapping(1023,0,255,0,reading);
		TIM0_voidCTCSetCompareValue(255-value);
	}*/
	DIO_voidSetPinDirection(PORTA,PIN0,PIN_Output);
	DIO_voidSetPinDirection(PORTA,PIN1,PIN_Output);
	while(1){
		_delay_ms(500);
		DIO_voidSetPinValue(PORTA,PIN0,PIN_High);
		DIO_voidSetPinValue(PORTA,PIN1,PIN_Low);
		_delay_ms(500);
		DIO_voidSetPinValue(PORTA,PIN0,PIN_Low);
		DIO_voidSetPinValue(PORTA,PIN1,PIN_High);
		
	}
}

