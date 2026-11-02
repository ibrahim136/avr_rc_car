/*
 * ADC_prv.h
 *
 * Created: 10/18/2026 10:54:48 AM
 *  Author: Ibrahim Haggag
 */ 


#ifndef ADC_PRV_H_
#define ADC_PRV_H_


typedef struct {
	union{
		u16 ADC;
		struct{
			u8 ADCL;
			u8 ADCH;
		};
		
		};
		
	union{
		u8 ADCSRA;
		struct{
			u8 ADPS :3;
			u8 :5;
			};
		struct{
			u8 ADPS0 :1;
			u8 ADPS1 :1;
			u8 ADPS2 :1;
			u8 ADIE :1;
			u8 ADIF :1;
			u8 ADATE :1;
			u8 ADSC :1;
			u8 ADEN :1;
			};
	};
	
	union{	
		u8 ADMUX;
		struct{
			u8 MUX :5;
			u8 ADLAR :1;
			u8 REFS0:1;
			u8 REFS1:1;
		};
		struct{
			u8 MUX0 :1;
			u8 MUX1 :1;
			u8 MUX2 :1;
			u8 MUX3 :1;
			u8 MUX4 :1;
			u8 :3;
		};
	};
	
	u8 reserved[40];
	union{
		u8 SFIOR;
		struct{
			u8 :5;
			u8 ADTS0 :1;
			u8 ADTS1 :1;
			u8 ADTS2 :1;
			};
		struct{
			u8 :5;
			u8 ADTS;
			};
	};
	}ADC_Registers_t;

#define ADC_BASE ((volatile u8*)(0x24))
#define ADC_Registers ((volatile ADC_Registers_t*)(ADC_BASE))


#endif /* ADC_PRV_H_ */