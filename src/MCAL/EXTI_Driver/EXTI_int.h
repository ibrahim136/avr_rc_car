/*
 * EXTI_int.h
 *
 * Created: 10/16/2026 6:32:34 PM
 *  Author: Ibrahim Haggag
 */ 


#ifndef EXTI_INT_H_
#define EXTI_INT_H_

typedef enum{
	EXTI0,EXTI1,EXTI2
}EXTI_t;

#define Falling_Edge 0
#define Rising_Edge 1
#define ON_Change 2
#define Low_Level 3

void EXTI_voidInit(void);
void EXTI_voidEnable(EXTI_t Copy_uddtEXTI );
void EXTI_voidDisable(EXTI_t Copy_uddtEXTI );
void EXTI_voidChangeTriggerMode(EXTI_t Copy_uddtEXTI,u8 Copy_u8TriggerMode);
void EXTI0_voidCallBackFunction(void(*ptr)(void));
void EXTI1_voidCallBackFunction(void(*ptr)(void));
void EXTI2_voidCallBackFunction(void(*ptr)(void));


#endif /* EXTI_INT_H_ */