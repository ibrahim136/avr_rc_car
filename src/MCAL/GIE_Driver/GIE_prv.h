/*
 * GIE_prv.h
 *
 * Created: 10/16/2026 9:33:48 PM
 *  Author: Ibrahim Haggag
 */ 


#ifndef GIE_PRV_H_
#define GIE_PRV_H_

typedef struct{ // to access every bit
		u8  :7;
		u8 I:1;
	}SREG_t;

#define SREG ((volatile SREG_t*)(0x5F))


#define I_bit 7

#endif /* GIE_PRV_H_ */