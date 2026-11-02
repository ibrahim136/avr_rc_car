/*
 * EXTI_prog.c
 *
 * Created: 10/16/2026 6:34:52 PM
 *  Author: Ibrahim Haggag
 */ 
#include "../STD_Types_and_BIT_Math/STD_TYPES.h"
#include "../STD_Types_and_BIT_Math/BIT_MATH.h"
#include "EXTI_prv.h"
#include "EXTI_int.h"
#include "EXTI_cfg.h"

void (*EXTI0_GlobalPtr)(void) = NULL_PTR;
void (*EXTI1_GlobalPtr)(void) = NULL_PTR;
void (*EXTI2_GlobalPtr)(void) = NULL_PTR;

void EXTI_voidInit(void)
{
#if EXTI0_TriggerSource==Falling_Edge
CLR_BIT(EXTI_REG->MCUCR,ISC00);
SET_BIT(EXTI_REG->MCUCR,ISC01);
#elif EXTI0_TriggerSource==Rising_Edge
SET_BIT(EXTI_REG->MCUCR,ISC00);
SET_BIT(EXTI_REG->MCUCR,ISC01);
#elif EXTI0_TriggerSource==ON_Change
SET_BIT(EXTI_REG->MCUCR,ISC00);
CLR_BIT(EXTI_REG->MCUCR,ISC01);
#elif EXTI0_TriggerSource==Low_Level
CLR_BIT(EXTI_REG->MCUCR,ISC00);
CLR_BIT(EXTI_REG->MCUCR,ISC01);
#endif


#if EXTI1_TriggerSource==Falling_Edge
CLR_BIT(EXTI_REG->MCUCR,ISC10);
SET_BIT(EXTI_REG->MCUCR,ISC11);
#elif EXTI1_TriggerSource==Rising_Edge
SET_BIT(EXTI_REG->MCUCR,ISC10);
SET_BIT(EXTI_REG->MCUCR,ISC11);
#elif EXTI1_TriggerSource==ON_Change
SET_BIT(EXTI_REG->MCUCR,ISC10);
CLR_BIT(EXTI_REG->MCUCR,ISC11);
#elif EXTI1_TriggerSource==Low_Level
CLR_BIT(EXTI_REG->MCUCR,ISC10);
CLR_BIT(EXTI_REG->MCUCR,ISC11);
#endif

#if EXTI2_TriggerSource==Falling_Edge
CLR_BIT(EXTI_REG->MCUCSR,ISC2);
#elif EXTI2_TriggerSource==Rising_Edge
SET_BIT(EXTI_REG->MCUCSR,ISC2);
#endif
}

void EXTI_voidEnable(EXTI_t Copy_uddtEXTI )
{
	switch(Copy_uddtEXTI){
		case EXTI0:
		SET_BIT(EXTI_REG->GICR,INT0);
		break;	
		case EXTI1:
		SET_BIT(EXTI_REG->GICR,INT1);
		break;
		case EXTI2:
		SET_BIT(EXTI_REG->GICR,INT2);
		break;
	}
}



void EXTI_voidDisable(EXTI_t Copy_uddtEXTI )
{
	switch(Copy_uddtEXTI){
		case EXTI0:
		CLR_BIT(EXTI_REG->GICR,INT0);
		break;
		case EXTI1:
		CLR_BIT(EXTI_REG->GICR,INT1);
		break;
		case EXTI2:
		CLR_BIT(EXTI_REG->GICR,INT2);
		break;
	}
}
void EXTI_voidChangeTriggerMode(EXTI_t Copy_uddtEXTI,u8 Copy_u8TriggerMode)
{
	switch(Copy_uddtEXTI){
		case EXTI0:
		switch(Copy_u8TriggerMode){
			case Falling_Edge:
			CLR_BIT(EXTI_REG->MCUCR,ISC00);
			SET_BIT(EXTI_REG->MCUCR,ISC01);
			break;
			case Rising_Edge:
			SET_BIT(EXTI_REG->MCUCR,ISC00);
			SET_BIT(EXTI_REG->MCUCR,ISC01);
			break;
			case ON_Change:
			SET_BIT(EXTI_REG->MCUCR,ISC00);
			CLR_BIT(EXTI_REG->MCUCR,ISC01);
			break;
			case Low_Level:
			CLR_BIT(EXTI_REG->MCUCR,ISC00);
			CLR_BIT(EXTI_REG->MCUCR,ISC01);
			break;
		}
		break;
		case EXTI1:
		switch(Copy_u8TriggerMode){
			case Falling_Edge:
			CLR_BIT(EXTI_REG->MCUCR,ISC10);
			SET_BIT(EXTI_REG->MCUCR,ISC11);
			break;
			case Rising_Edge:
			SET_BIT(EXTI_REG->MCUCR,ISC10);
			SET_BIT(EXTI_REG->MCUCR,ISC11);
			break;
			case ON_Change:
			SET_BIT(EXTI_REG->MCUCR,ISC10);
			CLR_BIT(EXTI_REG->MCUCR,ISC11);
			break;
			case Low_Level:
			CLR_BIT(EXTI_REG->MCUCR,ISC10);
			CLR_BIT(EXTI_REG->MCUCR,ISC11);
			break;
		}
		break;
		case EXTI2:
		switch(Copy_u8TriggerMode){
			case Falling_Edge:
			CLR_BIT(EXTI_REG->MCUCSR,ISC2);
			break;
			case Rising_Edge:
			SET_BIT(EXTI_REG->MCUCSR,ISC2);
			break;
			default:
			break;
		}
		break;
	}
}

void EXTI0_voidCallBackFunction(void(*ptr)(void)){ EXTI0_GlobalPtr = ptr;}


void EXTI1_voidCallBackFunction(void(*ptr)(void)){ EXTI1_GlobalPtr = ptr;}
void EXTI2_voidCallBackFunction(void(*ptr)(void)){ EXTI2_GlobalPtr = ptr;}
	
void __vector_1(void) __attribute__ ((signal,used,externally_visible)); \
void __vector_1(void)
{
	if (EXTI0_GlobalPtr != NULL_PTR){
		EXTI0_GlobalPtr();	
	}
}

void __vector_2(void) __attribute__ ((signal,used,externally_visible)); \
void __vector_2(void)
{
	if (EXTI1_GlobalPtr != NULL_PTR){
		EXTI1_GlobalPtr();
	}
}

void __vector_3(void) __attribute__ ((signal,used,externally_visible)); \
void __vector_3(void)
{
	if (EXTI2_GlobalPtr != NULL_PTR){
		EXTI2_GlobalPtr();
	}
}

