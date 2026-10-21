#include "STD_Types_and_BIT_Math/STD_TYPES.h"
#include "STD_Types_and_BIT_Math/BIT_MATH.h"
#include "DIO_Driver/DIO_int.h"
#include "GIE_Driver/GIE_int.h"
#include "EXTI_Driver/EXTI_int.h"
#include "ADC_Driver/ADC_int.h"
#include "Timer_driver/Timer_int.h"
#define F_CPU 8000000
#include <util/delay.h>


int main(void)
{
	TIM0_voidInit(Prescaller8);
	DIO_voidSetPinDirection(PORTB,PIN3,PORT_Output);
	
	
	
	while(1)
	{
		
	}
}
