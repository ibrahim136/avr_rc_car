/*
 * DIO_prv.h
 *
 * Created: 10/15/2026 12:51:27 PM
 *  Author: Ibrahim Haggag
 */ 


#ifndef DIO_PRV_H_
#define DIO_PRV_H_

typedef struct
{
	u8 PIND_Register;
	u8 DDRD_Register;
	u8 PORTD_Register;
	
	u8 PINC_Register;
	u8 DDRC_Register;
	u8 PORTC_Register;
	
	u8 PINB_Register;
	u8 DDRB_Register;
	u8 PORTB_Register;
	
	u8 PINA_Register;
	u8 DDRA_Register;
	u8 PORTA_Register;
}GPIO_REG_t;

#define GPIO_BASE ((volatile u8*)(0x30))
#define GPIO_REG ((volatile GPIO_REG_t*)(GPIO_BASE))

#endif /* DIO_PRV_H_ */