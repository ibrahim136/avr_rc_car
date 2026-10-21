/*
 * Timer_prog.c
 *
 * Created: 10/21/2026 9:19:32 AM
 *  Author: Ibrahim Haggag
 */ 
#include "../STD_Types_and_BIT_Math/STD_TYPES.h"
#include "../STD_Types_and_BIT_Math/BIT_MATH.h"
#include "Timer_prv.h"
#include "Timer_int.h"
#include "Timer_cfg.h"

void(*GlobalOVF_ptr)(void) = NULL_PTR;

void TIM0_voidInit(Prescaller_t Copy_uddtPrescaller)
{
	//select normal mode
	#if Waveform_Generation_Mode == Normal
	CLR_BIT(Timer0_Registers->TCCR0,TCCR0_WGM01);
	CLR_BIT(Timer0_Registers->TCCR0,TCCR0_WGM00);
	#elif Waveform_Generation_Mode == CTC
	SET_BIT(Timer0_Registers->TCCR0,TCCR0_WGM01);
	CLR_BIT(Timer0_Registers->TCCR0,TCCR0_WGM00);
	#if CTC_Mode == Toggle
	SET_BIT(Timer0_Registers->TCCR0,TCCR0_COM00);
	CLR_BIT(Timer0_Registers->TCCR0,TCCR0_COM01);
	#endif
	#endif
	Timer0_Registers->TCCR0 &= ~Prescaller_Mask;
	Timer0_Registers->TCCR0 |= (Copy_uddtPrescaller << 0);
}
void TIM0_voidOVFIntEnable(void)
{
	SET_BIT(Timer0_Registers->TIMSK,TIMSK_TOIE0);
}
void TIM0_voidOVFCallBack(void(*ptr)(void))
{
	GlobalOVF_ptr = ptr;
}
void TIM0_voidSetPreloadValue(u8 Copy_u8Preload)
{
	Timer0_Registers->TCNT0 = Copy_u8Preload;
}

void __vector_11(void) __attribute__ ((signal,used,externally_visible)); 
void __vector_11(void)
{
	if (GlobalOVF_ptr != NULL_PTR){
		GlobalOVF_ptr();	
	}
}

void TIM0_voidCTCIntEnable(void)
{
	
}
void TIM0_voidCTCCallBack(void(*ptr)(void))
{
	
}
void TIM0_voidCTCSetCompareValue(u8 Copy_u8CompareValue)
{
	Timer0_Registers->OCR0 = Copy_u8CompareValue;
}