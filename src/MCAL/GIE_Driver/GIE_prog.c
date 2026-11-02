/*
 * GIE_prog.c
 *
 * Created: 10/16/2026 9:33:18 PM
 *  Author: Ibrahim Haggag
 */ 
#include "../STD_Types_and_BIT_Math/STD_TYPES.h"
#include "../STD_Types_and_BIT_Math/BIT_MATH.h"

#include "GIE_prv.h"
#include "GIE_int.h"

void GIE_voidEnableOrDisable(GIE_state Copy_uddtState)
{
	switch(Copy_uddtState){
		case GIE_enable:
		SREG->I =1;
		break;
		case GIE_disable:
		SREG->I =0;
		break;
	}
}