/*
 * GIE_int.h
 *
 * Created: 10/16/2026 9:34:37 PM
 *  Author: Ibrahim Haggag
 */ 


#ifndef GIE_INT_H_
#define GIE_INT_H_

typedef enum{
		GIE_disable,
		GIE_enable
	}GIE_state;

void GIE_voidEnableOrDisable(GIE_state Copy_uddtState);

#endif /* GIE_INT_H_ */