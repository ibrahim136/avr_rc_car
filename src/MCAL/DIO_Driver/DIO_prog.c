/*
 * DIO_prog.c
 *
 * Created: 10/15/2026 12:52:35 PM
 *  Author: Ibrahim Haggag
 */ 

#include "../STD_Types_and_BIT_Math/STD_TYPES.h"
#include "../STD_Types_and_BIT_Math/BIT_MATH.h"
#include "DIO_int.h"
#include "DIO_prv.h"

void DIO_voidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Direction)
{
	switch(Copy_u8Port){
		case PORTA:
			if (Copy_u8Direction == PIN_Output){
				SET_BIT(GPIO_REG->DDRA_Register,Copy_u8Pin);
			}
			else if (Copy_u8Direction == PIN_Input){
				CLR_BIT(GPIO_REG->DDRA_Register,Copy_u8Pin);
			}
		break;
		case PORTB:
			if (Copy_u8Direction == PIN_Output){
				SET_BIT(GPIO_REG->DDRB_Register,Copy_u8Pin);
			}
			else if (Copy_u8Direction == PIN_Input){
				CLR_BIT(GPIO_REG->DDRB_Register,Copy_u8Pin);
			}
			break;
		break;
		case PORTC:
			if (Copy_u8Direction == PIN_Output){
				SET_BIT(GPIO_REG->DDRC_Register,Copy_u8Pin);
			}
			else if (Copy_u8Direction == PIN_Input){
				CLR_BIT(GPIO_REG->DDRC_Register,Copy_u8Pin);
			}
			break;
		break;
		case PORTD:
			if (Copy_u8Direction == PIN_Output){
				SET_BIT(GPIO_REG->DDRD_Register,Copy_u8Pin);
			}
			else if (Copy_u8Direction == PIN_Input){
				CLR_BIT(GPIO_REG->DDRD_Register,Copy_u8Pin);
			}
			break;
	}
}

//set Pin value
void DIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value)
{
	switch(Copy_u8Port){
		case PORTA:
			if (Copy_u8Value == PIN_High){
				SET_BIT(GPIO_REG->PORTA_Register,Copy_u8Pin);
			}
			else if (Copy_u8Value == PIN_Low){
				CLR_BIT(GPIO_REG->PORTA_Register,Copy_u8Pin);
			}
			break;
		case PORTB:
			if (Copy_u8Value == PIN_High){
				SET_BIT(GPIO_REG->PORTB_Register,Copy_u8Pin);
			}
			else if (Copy_u8Value == PIN_Low){
				CLR_BIT(GPIO_REG->PORTB_Register,Copy_u8Pin);
			}
			break;
		case PORTC:
			if (Copy_u8Value == PIN_High){
				SET_BIT(GPIO_REG->PORTC_Register,Copy_u8Pin);
			}
			else if (Copy_u8Value == PIN_Low){
				CLR_BIT(GPIO_REG->PORTC_Register,Copy_u8Pin);
			}
			break;
		case PORTD:
			if (Copy_u8Value == PIN_High){
				SET_BIT(GPIO_REG->PORTD_Register,Copy_u8Pin);
			}
			else if (Copy_u8Value == PIN_Low){
				CLR_BIT(GPIO_REG->PORTD_Register,Copy_u8Pin);
			}
			break;
	}
}

//get Pin value
u8 DIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin){
	u8 LOC_u8Value =0;
	switch(Copy_u8Port){
		case PORTA:
			LOC_u8Value= GET_BIT(GPIO_REG->PINA_Register,Copy_u8Pin);
			break;
		case PORTB:
			LOC_u8Value= GET_BIT(GPIO_REG->PINB_Register,Copy_u8Pin);
			break;
		case PORTC:
			LOC_u8Value= GET_BIT(GPIO_REG->PINC_Register,Copy_u8Pin);
			break;
		case PORTD:
			LOC_u8Value= GET_BIT(GPIO_REG->PIND_Register,Copy_u8Pin);
			break;
	}
	return LOC_u8Value;
}

// set PIN direction (input/output)
void DIO_voidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Direction)
{
	switch(Copy_u8Port){
		case PORTA:
			GPIO_REG->DDRA_Register = Copy_u8Direction;
			break;
		case PORTB:
			GPIO_REG->DDRB_Register = Copy_u8Direction;
			break;
		case PORTC:
			GPIO_REG->DDRC_Register = Copy_u8Direction;
			break;
		case PORTD:
			GPIO_REG->DDRD_Register = Copy_u8Direction;
			break;
	}
			
}
//set Pin value
void DIO_voidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value)
{
	switch(Copy_u8Port){
		case PORTA:
		GPIO_REG->PORTA_Register = Copy_u8Value;
		break;
		case PORTB:
		GPIO_REG->PORTB_Register = Copy_u8Value;
		break;
		case PORTC:
		GPIO_REG->PORTC_Register = Copy_u8Value;
		break;
		case PORTD:
		GPIO_REG->PORTD_Register = Copy_u8Value;
		break;
	}
	
}
//get Pin value
u8 DIO_u8GetPortValue(u8 Copy_u8Port)
{
	u8 LOC_u8Value =0;
	switch(Copy_u8Port){
		case PORTA:
		LOC_u8Value= GPIO_REG->PINA_Register;
		break;
		case PORTB:
		LOC_u8Value= GPIO_REG->PINB_Register;
		break;
		case PORTC:
		LOC_u8Value= GPIO_REG->PINC_Register;
		break;
		case PORTD:
		LOC_u8Value= GPIO_REG->PIND_Register;
		break;
	}
	return LOC_u8Value;
}

// activate_pullup
void DIO_voidActivatePullUp(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
		case PORTA:
			CLR_BIT(GPIO_REG->DDRA_Register,Copy_u8Pin);
			SET_BIT(GPIO_REG->PORTA_Register,Copy_u8Pin);
			break;
		case PORTB:
		CLR_BIT(GPIO_REG->DDRB_Register,Copy_u8Pin);
		SET_BIT(GPIO_REG->PORTB_Register,Copy_u8Pin);
		break;
		case PORTC:
		CLR_BIT(GPIO_REG->DDRC_Register,Copy_u8Pin);
		SET_BIT(GPIO_REG->PORTC_Register,Copy_u8Pin);
		break;
		case PORTD:
		CLR_BIT(GPIO_REG->DDRD_Register,Copy_u8Pin);
		SET_BIT(GPIO_REG->PORTD_Register,Copy_u8Pin);
		break;	
	}
}

void DIO_voidTogglePinValue(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	switch(Copy_u8Port){
		case PORTA:
			TOG_BIT(GPIO_REG->PORTA_Register,Copy_u8Pin);
			break;
		case PORTB:
			TOG_BIT(GPIO_REG->PORTB_Register,Copy_u8Pin);
			break;
		case PORTC:
			TOG_BIT(GPIO_REG->PORTC_Register,Copy_u8Pin);
			break;
		case PORTD:
			TOG_BIT(GPIO_REG->PORTD_Register,Copy_u8Pin);
			break;
	}
}

