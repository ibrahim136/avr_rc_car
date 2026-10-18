/*
 * ADC_int.h
 *
 * Created: 10/18/2026 10:55:03 AM
 *  Author: Ibrahim Haggag
 */ 


#ifndef ADC_INT_H_
#define ADC_INT_H_

typedef enum{
	channel_0,channel_1,channel_2,channel_3,channel_4,channel_5,channel_6,channel_7
	}ADC_channels;

void ADC_voidInit(void);

u16 ADC_u16StartConversion(ADC_channels Copy_uddtChannel);



#endif /* ADC_INT_H_ */