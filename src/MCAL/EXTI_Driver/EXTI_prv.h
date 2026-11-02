/*
 * EXTI_prv.h
 *
 * Created: 10/16/2026 6:32:04 PM
 *  Author: Ibrahim Haggag
 */ 


#ifndef EXTI_PRV_H_
#define EXTI_PRV_H_

typedef struct
{
	u8 MCUCSR;
	u8 MCUCR;
	u32 : 32;
	u8 GIFR;
	u8 GICR;
}EXTI_REG_t;



#define EXTI_BASE ((volatile u8*)(0x54))
#define EXTI_REG ((volatile EXTI_REG_t*)(EXTI_BASE))

#define ISC11 3
#define ISC10 2
#define ISC01 1
#define ISC00 0

#define ISC2 6

#define INT1 7
#define INT0 6
#define INT2 5

#define INTF1 7
#define INTF0 6
#define INTF2 5

#endif /* EXTI_PRV_H_ */