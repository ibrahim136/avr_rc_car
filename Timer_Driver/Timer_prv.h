/*
 * Timer_prv.h
 *
 * Created: 10/21/2026 9:20:12 AM
 *  Author: Ibrahim Haggag
 */ 


#ifndef TIMER_PRV_H_
#define TIMER_PRV_H_

typedef struct {
	u8 SFIOR;
	u8 Reserved0;
	u8 TCNT0;
	u8 TCCR0;
	u8 Reserved1[4];
	u8 TIFR;
	u8 TIMSK;
	u8 Reserved2[2];
	u8 OCR0;
}Timer0_Registers_t;

#define Timer0_BASE ((volatile u8*) (0x50))
#define Timer0_Registers ((volatile Timer0_Registers_t *) (Timer0_BASE))

#define TCCR0_CS00 0
#define TCCR0_CS01	1
#define TCCR0_CS02 2
#define TCCR0_WGM01 3
#define TCCR0_WGM00 6
#define TCCR0_COM01 5
#define TCCR0_COM00 4
#define TIMSK_TOIE0 0
#define TIMSK_OCIE0 1

#define Prescaller_Mask 0x07

#define Normal 0
#define CTC 1
#define Toggle 2
#define Clear 3
#define Set 4

#endif /* TIMER_PRV_H_ */