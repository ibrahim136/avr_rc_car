/*
 * ADC_prog.c
 *
 * Created: 10/18/2026 10:55:19 AM
 *  Author: Ibrahim Haggag
 */ 
#include "../STD_Types_and_BIT_Math/STD_TYPES.h"
#include "../STD_Types_and_BIT_Math/BIT_MATH.h"
#include "ADC_cfg.h"
#include "ADC_prv.h"
#include "ADC_int.h"

void ADC_voidInit(void)
{
	ADC_Registers->REFS0 =1;
	ADC_Registers->REFS1 =0;
	ADC_Registers->ADLAR =0;
	ADC_Registers->ADPS = 0b111;
	
	
	ADC_Registers->ADEN=1;
}

u16 ADC_u16StartConversion(ADC_channels Copy_uddtChannel)
{
	ADC_Registers->MUX = Copy_uddtChannel;
		
	ADC_Registers->ADSC=1;
	
	while(ADC_Registers->ADIF ==0);
	
	ADC_Registers->ADIF |= 1;
	
	return ADC_Registers->ADC;
	
}