#include "STD_Types_and_BIT_Math/STD_TYPES.h"
#include "STD_Types_and_BIT_Math/BIT_MATH.h"
#include "DIO_Driver/DIO_int.h"
#include "GIE_Driver/GIE_int.h"
#include "EXTI_Driver/EXTI_int.h"
#include "ADC_Driver/ADC_int.h"
#define F_CPU 8000000
#include <util/delay.h>


int main(void)
{
	u16 Digital_Value =0;
	u32 Analog_Value =0;
	DIO_voidSetPinDirection(PORTC,PIN0,PIN_Output);
	DIO_voidSetPinDirection(PORTC,PIN1,PIN_Output);
	DIO_voidSetPinDirection(PORTC,PIN2,PIN_Output);
	
	DIO_voidSetPinDirection(PORTA,PIN0,PIN_Input);
	
	ADC_voidInit();
	while(1)
	{
		Digital_Value= ADC_u16StartConversion(channel_0);
		Analog_Value =( ((u32)Digital_Value*5000)/1024);
		if (  (Analog_Value >=0) && (Analog_Value < 1500)  )
		{
			DIO_voidSetPinValue(PORTC,PIN0,PIN_High);
			DIO_voidSetPinValue(PORTC,PIN1,PIN_Low);
			DIO_voidSetPinValue(PORTC,PIN2,PIN_Low);
		}
		else if (  (Analog_Value >=1500) && (Analog_Value < 3000)  ) 
		{
			DIO_voidSetPinValue(PORTC,PIN0,PIN_Low);
			DIO_voidSetPinValue(PORTC,PIN1,PIN_High);
			DIO_voidSetPinValue(PORTC,PIN2,PIN_Low);
		}
		else
		{
			DIO_voidSetPinValue(PORTC,PIN0,PIN_Low);
			DIO_voidSetPinValue(PORTC,PIN1,PIN_Low);
			DIO_voidSetPinValue(PORTC,PIN2,PIN_High);
		}
	}
}