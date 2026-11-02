/*
 * DIO_int.h
 *
 * Created: 10/15/2026 12:52:13 PM
 *  Author: Ibrahim Haggag
 */ 


#ifndef DIO_INT_H_
#define DIO_INT_H_
// set PIN direction (input/output)
void DIO_voidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Direction);

//set Pin value
void DIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value);

//get Pin value
u8 DIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin);

// set PIN direction (input/output)
void DIO_voidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Direction);

//set Pin value
void DIO_voidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value);

//get Pin value
u8 DIO_u8GetPortValue(u8 Copy_u8Port);

// activate_pullup
void DIO_voidActivatePullUp(u8 Copy_u8Port,u8 Copy_u8Pin);

//toggle pin
void DIO_voidTogglePinValue(u8 Copy_u8Port,u8 Copy_u8Pin);

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define PIN_High 1
#define PIN_Low 0

#define PIN_Output 1
#define PIN_Input 0

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define PORT_Output 255
#define PORT_Input 0

#endif /* DIO_INT_H_ */