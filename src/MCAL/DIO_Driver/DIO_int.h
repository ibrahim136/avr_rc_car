#ifndef DIO_INT_H_
#define DIO_INT_H_

typedef enum
{
    PORTA = 0,
    PORTB = 1,
    PORTC = 2,
    PORTD = 3
} PORT_t;

typedef enum
{
    PIN_Low = 0,
    PIN_High = 1
} PIN_State_t;

typedef enum
{
    PIN_Input = 0,
    PIN_Output = 1
} PIN_Direction_t;

typedef enum
{
    PIN0=0,
    PIN1=1,
    PIN2=2,
    PIN3=3,
    PIN4=4,
    PIN5=5,
    PIN6=6,
    PIN7=7
}PIN_Number_t;

typedef enum
{
    PORT_Input = 0,
    PORT_Output = 255
} PORT_Direction_t;

// set PIN direction (input/output)
void DIO_voidSetPinDirection(PORT_t Copy_enuPort, PIN_Number_t Copy_enuPINNumber, PIN_Direction_t Copy_enuPINDirection);

// set Pin value
void DIO_voidSetPinValue(PORT_t Copy_enuPort, PIN_Number_t Copy_enuPINNumber, PIN_State_t Copy_enuPINState);

// get Pin value
u8 DIO_u8GetPinValue(PORT_t Copy_enuPort, PIN_Number_t Copy_enuPINNumber);

// set PIN direction (input/output)
void DIO_voidSetPortDirection(PORT_t Copy_enuPort, PORT_Direction_t Copy_enuPORTDirection);

// set Pin value
void DIO_voidSetPortValue(PORT_t Copy_enuPort, u8 Copy_u8PortValue);

// get Pin value
u8 DIO_u8GetPortValue(PORT_t Copy_enuPort);

// activate_pullup
void DIO_voidActivatePullUp(PORT_t Copy_enuPort, PIN_Number_t Copy_enuPINNumber);

// toggle pin
void DIO_voidTogglePinValue(PORT_t Copy_enuPort, PIN_Number_t Copy_enuPINNumber);



#endif