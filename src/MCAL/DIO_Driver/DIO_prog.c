#include "../STD_Types_and_BIT_Math/STD_TYPES.h"
#include "../STD_Types_and_BIT_Math/BIT_MATH.h"
#include "DIO_int.h"
#include "DIO_prv.h"

void DIO_voidSetPinDirection(PORT_t Copy_enuPort, PIN_Number_t Copy_enuPINNumber, PIN_Direction_t Copy_enuPINDirection)
{
	switch (Copy_enuPort)
	{
	case PORTA:
		if (Copy_enuPINDirection == PIN_Output)
		{
			SET_BIT(GPIO_REG->DDRA_Register, Copy_enuPINNumber);
		}
		else if (Copy_enuPINDirection == PIN_Input)
		{
			CLR_BIT(GPIO_REG->DDRA_Register, Copy_enuPINNumber);
		}
		break;
	case PORTB:
		if (Copy_enuPINDirection == PIN_Output)
		{
			SET_BIT(GPIO_REG->DDRB_Register, Copy_enuPINNumber);
		}
		else if (Copy_enuPINDirection == PIN_Input)
		{
			CLR_BIT(GPIO_REG->DDRB_Register, Copy_enuPINNumber);
		}
		break;
	case PORTC:
		if (Copy_enuPINDirection == PIN_Output)
		{
			SET_BIT(GPIO_REG->DDRC_Register, Copy_enuPINNumber);
		}
		else if (Copy_enuPINDirection == PIN_Input)
		{
			CLR_BIT(GPIO_REG->DDRC_Register, Copy_enuPINNumber);
		}
		break;
	case PORTD:
		if (Copy_enuPINDirection == PIN_Output)
		{
			SET_BIT(GPIO_REG->DDRD_Register, Copy_enuPINNumber);
		}
		else if (Copy_enuPINDirection == PIN_Input)
		{
			CLR_BIT(GPIO_REG->DDRD_Register, Copy_enuPINNumber);
		}
		break;
	}
}

// set Pin value
void DIO_voidSetPinValue(PORT_t Copy_enuPort, PIN_Number_t Copy_enuPINNumber, PIN_State_t Copy_enuPINState)
{
	switch (Copy_enuPort)
	{
	case PORTA:
		if (Copy_enuPINState == PIN_High)
		{
			SET_BIT(GPIO_REG->PORTA_Register, Copy_enuPINNumber);
		}
		else if (Copy_enuPINState == PIN_Low)
		{
			CLR_BIT(GPIO_REG->PORTA_Register, Copy_enuPINNumber);
		}
		break;
	case PORTB:
		if (Copy_enuPINState == PIN_High)
		{
			SET_BIT(GPIO_REG->PORTB_Register, Copy_enuPINNumber);
		}
		else if (Copy_enuPINState == PIN_Low)
		{
			CLR_BIT(GPIO_REG->PORTB_Register, Copy_enuPINNumber);
		}
		break;
	case PORTC:
		if (Copy_enuPINState == PIN_High)
		{
			SET_BIT(GPIO_REG->PORTC_Register, Copy_enuPINNumber);
		}
		else if (Copy_enuPINState == PIN_Low)
		{
			CLR_BIT(GPIO_REG->PORTC_Register, Copy_enuPINNumber);
		}
		break;
	case PORTD:
		if (Copy_enuPINState == PIN_High)
		{
			SET_BIT(GPIO_REG->PORTD_Register, Copy_enuPINNumber);
		}
		else if (Copy_enuPINState == PIN_Low)
		{
			CLR_BIT(GPIO_REG->PORTD_Register, Copy_enuPINNumber);
		}
		break;
	}
}

// get Pin value
u8 DIO_u8GetPinValue(PORT_t Copy_enuPort, PIN_Number_t Copy_enuPINNumber)
{
	u8 LOC_u8Value = 0;
	switch (Copy_enuPort)
	{
	case PORTA:
		LOC_u8Value = GET_BIT(GPIO_REG->PINA_Register, Copy_enuPINNumber);
		break;
	case PORTB:
		LOC_u8Value = GET_BIT(GPIO_REG->PINB_Register, Copy_enuPINNumber);
		break;
	case PORTC:
		LOC_u8Value = GET_BIT(GPIO_REG->PINC_Register, Copy_enuPINNumber);
		break;
	case PORTD:
		LOC_u8Value = GET_BIT(GPIO_REG->PIND_Register, Copy_enuPINNumber);
		break;
	}
	return LOC_u8Value;
}

// set PIN direction (input/output)
void DIO_voidSetPortDirection(PORT_t Copy_enuPort, PORT_Direction_t Copy_enuPORTDirection)
{
	switch (Copy_enuPort)
	{
	case PORTA:
		GPIO_REG->DDRA_Register = Copy_enuPORTDirection;
		break;
	case PORTB:
		GPIO_REG->DDRB_Register = Copy_enuPORTDirection;
		break;
	case PORTC:
		GPIO_REG->DDRC_Register = Copy_enuPORTDirection;
		break;
	case PORTD:
		GPIO_REG->DDRD_Register = Copy_enuPORTDirection;
		break;
	}
}
// set Pin value
void DIO_voidSetPortValue(PORT_t Copy_enuPort, u8 Copy_u8PortValue)
{
	switch (Copy_enuPort)
	{
	case PORTA:
		GPIO_REG->PORTA_Register = Copy_u8PortValue;
		break;
	case PORTB:
		GPIO_REG->PORTB_Register = Copy_u8PortValue;
		break;
	case PORTC:
		GPIO_REG->PORTC_Register = Copy_u8PortValue;
		break;
	case PORTD:
		GPIO_REG->PORTD_Register = Copy_u8PortValue;
		break;
	}
}
// get Pin value
u8 DIO_u8GetPortValue(PORT_t Copy_enuPort)
{
	u8 LOC_u8Value = 0;
	switch (Copy_enuPort)
	{
	case PORTA:
		LOC_u8Value = GPIO_REG->PINA_Register;
		break;
	case PORTB:
		LOC_u8Value = GPIO_REG->PINB_Register;
		break;
	case PORTC:
		LOC_u8Value = GPIO_REG->PINC_Register;
		break;
	case PORTD:
		LOC_u8Value = GPIO_REG->PIND_Register;
		break;
	}
	return LOC_u8Value;
}

// activate_pullup
void DIO_voidActivatePullUp(PORT_t Copy_enuPort, PIN_Number_t Copy_enuPINNumber)
{
	switch (Copy_enuPort)
	{
	case PORTA:
		CLR_BIT(GPIO_REG->DDRA_Register, Copy_enuPINNumber);
		SET_BIT(GPIO_REG->PORTA_Register, Copy_enuPINNumber);
		break;
	case PORTB:
		CLR_BIT(GPIO_REG->DDRB_Register, Copy_enuPINNumber);
		SET_BIT(GPIO_REG->PORTB_Register, Copy_enuPINNumber);
		break;
	case PORTC:
		CLR_BIT(GPIO_REG->DDRC_Register, Copy_enuPINNumber);
		SET_BIT(GPIO_REG->PORTC_Register, Copy_enuPINNumber);
		break;
	case PORTD:
		CLR_BIT(GPIO_REG->DDRD_Register, Copy_enuPINNumber);
		SET_BIT(GPIO_REG->PORTD_Register, Copy_enuPINNumber);
		break;
	}
}

void DIO_voidTogglePinValue(PORT_t Copy_enuPort, PIN_Number_t Copy_enuPINNumber)
{
	switch (Copy_enuPort)
	{
	case PORTA:
		TOG_BIT(GPIO_REG->PORTA_Register, Copy_enuPINNumber);
		break;
	case PORTB:
		TOG_BIT(GPIO_REG->PORTB_Register, Copy_enuPINNumber);
		break;
	case PORTC:
		TOG_BIT(GPIO_REG->PORTC_Register, Copy_enuPINNumber);
		break;
	case PORTD:
		TOG_BIT(GPIO_REG->PORTD_Register, Copy_enuPINNumber);
		break;
	}
}
