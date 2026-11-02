/*
 * Timer_prv.h
 * Created: 10/21/2026 9:20:12 AM
 * Author: Ibrahim Haggag
 */ 

#ifndef TIMER_PRV_H_
#define TIMER_PRV_H_

// --- Timer0 Registers Struct ---
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
} Timer0_Registers_t;

#define Timer0_BASE ((volatile u8*) (0x50))
#define Timer0_Registers ((volatile Timer0_Registers_t *) (Timer0_BASE))

// --- Timer1 Direct Registers Mapping (طريقة مباشرة وآمنة تماماً) ---
#define TCCR1A   (*(volatile u8*)(0x4F))
#define TCCR1B   (*(volatile u8*)(0x4E))
#define TCNT1    (*(volatile u16*)(0x4C))
#define OCR1A    (*(volatile u16*)(0x4A))
#define OCR1B    (*(volatile u16*)(0x48))
#define ICR1     (*(volatile u16*)(0x46))

// مسجل الـ TIFR المشترك
#define TIFR     (*(volatile u8*)(0x58))

// Timer0 Defines
#define TCCR0_CS00 0
#define TCCR0_CS01 1
#define TCCR0_CS02 2
#define TCCR0_WGM01 3
#define TCCR0_WGM00 6
#define TCCR0_COM01 5
#define TCCR0_COM00 4
#define TIMSK_TOIE0 0
#define TIMSK_OCIE0 1
#define Prescaller_Mask (0x07<<TCCR0_CS00)

// Timer1 Defines
#define TCCR1A_WGM10 0
#define TCCR1A_WGM11 1
#define TCCR1B_WGM12 3
#define TCCR1B_WGM13 4
#define TCCR1B_CS10  0
#define TCCR1B_CS11  1
#define TCCR1B_CS12  2
#define TIFR_OCF1A   4

// Modes
#define Normal 0
#define CTC 1
#define Fast_PWM 5

#endif /* TIMER_PRV_H_ */