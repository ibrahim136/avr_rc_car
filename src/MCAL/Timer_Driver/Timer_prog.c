/*
 * Timer_prog.c
 * Created: 10/21/2026 9:19:32 AM
 * Author: Ibrahim Haggag
 */ 
#include "../STD_Types_and_BIT_Math/STD_TYPES.h"
#include "../STD_Types_and_BIT_Math/BIT_MATH.h"
#include "Timer_prv.h"
#include "Timer_int.h"
#include "Timer_cfg.h"

void(*GlobalOVF_ptr)(void) = NULL_PTR;

// --- Timer0 Implementation (PWM & CTC) ---
void TIM0_voidInit(Prescaller_t Copy_uddtPrescaller)
{
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
	#elif Waveform_Generation_Mode == Fast_PWM
	SET_BIT(Timer0_Registers->TCCR0,TCCR0_WGM01);
	SET_BIT(Timer0_Registers->TCCR0,TCCR0_WGM00);
	
	CLR_BIT(Timer0_Registers->TCCR0,TCCR0_COM00);
	SET_BIT(Timer0_Registers->TCCR0,TCCR0_COM01);
	#endif
	
	CLEAR_MASK(Timer0_Registers->TCCR0,Prescaller_Mask);
	SET_MASK(Timer0_Registers->TCCR0,Copy_uddtPrescaller);
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
	SET_BIT(Timer0_Registers->TIMSK,TIMSK_OCIE0);
}

void TIM0_voidCTCCallBack(void(*ptr)(void))
{
	
}

void TIM0_voidCTCSetCompareValue(u8 Copy_u8CompareValue)
{
	Timer0_Registers->OCR0 = Copy_u8CompareValue;
}

// --- Timer1 Implementation (Delays) ---
void TIM1_voidInit(void)
{
    // اختيار CTC Mode (Mode 4) لـ Timer1
    CLR_BIT(TCCR1A, TCCR1A_WGM10);
    CLR_BIT(TCCR1A, TCCR1A_WGM11);
    SET_BIT(TCCR1B, TCCR1B_WGM12);
    CLR_BIT(TCCR1B, TCCR1B_WGM13);

    // ضبط Prescaler = 8 (لكريستالة 8MHz تعني 1 تكة = 1 ميكروثانية)
    CLR_BIT(TCCR1B, TCCR1B_CS10);
    SET_BIT(TCCR1B, TCCR1B_CS11);
    CLR_BIT(TCCR1B, TCCR1B_CS12);
}

void TIM1_voidDelayUs(u16 Copy_u16Micros)
{
    TCNT1 = 0;
    OCR1A = Copy_u16Micros;

    SET_BIT(TIFR, TIFR_OCF1A);

    while (GET_BIT(TIFR, TIFR_OCF1A) == 0);

    SET_BIT(TIFR, TIFR_OCF1A);
}

void TIM1_voidDelayMs(u16 Copy_u16Millis)
{
    while (Copy_u16Millis--)
    {
        TIM1_voidDelayUs(1000);
    }
}