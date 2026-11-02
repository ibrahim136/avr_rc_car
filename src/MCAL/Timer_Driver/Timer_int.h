/*
 * Timer_int.h
 * Created: 10/21/2026 9:20:35 AM
 * Author: Ibrahim Haggag
 */ 

#ifndef TIMER_INT_H_
#define TIMER_INT_H_

#include "../STD_Types_and_BIT_Math/STD_TYPES.h"

typedef enum{
	Prescaller0 = 1,
	Prescaller8 = 2,
	Prescaller64 = 3,
	Prescaller256 = 4,
	Prescaller1024 = 5,
} Prescaller_t;

// --- Timer0 APIs (مخصص للـ PWM والمواتير) ---
void TIM0_voidInit(Prescaller_t Copy_uddtPrescaller);
void TIM0_voidOVFIntEnable(void); 
void TIM0_voidOVFCallBack(void(*ptr)(void));
void TIM0_voidSetPreloadValue(u8 Copy_u8Preload);
void TIM0_voidCTCIntEnable(void);
void TIM0_voidCTCCallBack(void(*ptr)(void));
void TIM0_voidCTCSetCompareValue(u8 Copy_u8CompareValue);

// --- Timer1 APIs (مخصص للـ Delays الدقيقة للـ Ultrasonic وغيره) ---
void TIM1_voidInit(void);
void TIM1_voidDelayUs(u16 Copy_u16Micros);
void TIM1_voidDelayMs(u16 Copy_u16Millis);

#endif /* TIMER_INT_H_ */