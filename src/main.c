#include "MCAL/STD_Types_and_BIT_Math/STD_TYPES.h"
#include "MCAL/STD_Types_and_BIT_Math/BIT_MATH.h"
#include "MCAL/DIO_Driver/DIO_int.h"
#include "MCAL/UART_Driver/UART_int.h"
#include "MCAL/GIE_Driver/GIE_int.h"
#include "MCAL/Timer_Driver/Timer_int.h"

// دالة استقبال الأوامر عبر البلوتوث (ممكن تستخدمها لاحقاً أو تدمجها حسب الحاجة)
void Bluetooth_Command_Handler(u8 received_char)
{
    switch (received_char)
    {
        case 'F': // Forward
            DIO_voidSetPinValue(PORTA, PIN0, PIN_High);
            DIO_voidSetPinValue(PORTA, PIN1, PIN_Low);
            DIO_voidSetPinValue(PORTA, PIN2, PIN_High);
            DIO_voidSetPinValue(PORTA, PIN3, PIN_Low);
            break;
            
        case 'B': // Backward
            DIO_voidSetPinValue(PORTA, PIN0, PIN_Low);
            DIO_voidSetPinValue(PORTA, PIN1, PIN_High);
            DIO_voidSetPinValue(PORTA, PIN2, PIN_Low);
            DIO_voidSetPinValue(PORTA, PIN3, PIN_High);
            break;
            
        case 'S': // Stop
            TIM0_voidCTCSetCompareValue(0);
            DIO_voidSetPinValue(PORTA, PIN0, PIN_Low);
            DIO_voidSetPinValue(PORTA, PIN1, PIN_Low);
            DIO_voidSetPinValue(PORTA, PIN2, PIN_Low);
            DIO_voidSetPinValue(PORTA, PIN3, PIN_Low);
            break;
            
        default:
            break;
    }
}

int main(void)
{
    // 1. تهيئة الـ UART (مفعل لاستقبال أوامر البلوتوث)
    UART_voidInit();
    UART_voidSetCallBack(Bluetooth_Command_Handler);

    // 2. تهيئة الـ Timer0 على Fast PWM (بـ Prescaler 64 للتحكم في السرعة)
    TIM0_voidInit(Prescaller64);
    
    // 3. تهيئة الـ Timer1 (عشان الـ Delay الدقيق بالميليثانية والميكروثانية)
    TIM1_voidInit();

    // 4. ضبط أطراف المواتير والـ PWM (PB3) كـ Output
    DIO_voidSetPinDirection(PORTA, PIN0, PIN_Output);
    DIO_voidSetPinDirection(PORTA, PIN1, PIN_Output);
    DIO_voidSetPinDirection(PORTA, PIN2, PIN_Output);
    DIO_voidSetPinDirection(PORTA, PIN3, PIN_Output);
    DIO_voidSetPinDirection(PORTB, PIN3, PIN_Output); // طرف الـ OC0 للـ PWM

    // 5. تفعيل المقاطعات العامة
    GIE_voidEnableOrDisable(GIE_enable);

    while (1)
    {
        // ==========================================
        // المرحلة الأولى: الحركة للأمام وزيادة السرعة تدريجياً (Ramp Up)
        // ==========================================
        DIO_voidSetPinValue(PORTA, PIN0, PIN_High);
        DIO_voidSetPinValue(PORTA, PIN1, PIN_Low);
        DIO_voidSetPinValue(PORTA, PIN2, PIN_High);
        DIO_voidSetPinValue(PORTA, PIN3, PIN_Low);

        for (u16 i = 0; i <= 255; i++)
        {
            TIM0_voidCTCSetCompareValue((u8)i);
            TIM1_voidDelayMs(20); // تدرج السرعة باستخدام Timer1 Delay
        }

        // الثبات عند أقصى سرعة لمدة ثانية
        TIM1_voidDelayMs(1000);

        // ==========================================
        // المرحلة الثانية: وقوف تام (Stop)
        // ==========================================
        TIM0_voidCTCSetCompareValue(0);
        DIO_voidSetPinValue(PORTA, PIN0, PIN_Low);
        DIO_voidSetPinValue(PORTA, PIN1, PIN_Low);
        DIO_voidSetPinValue(PORTA, PIN2, PIN_Low);
        DIO_voidSetPinValue(PORTA, PIN3, PIN_Low);
        
        TIM1_voidDelayMs(1000);

        // ==========================================
        // المرحلة الثالثة: الحركة للخلف بأقصى سرعة وخفض السرعة تدريجياً (Ramp Down)
        // ==========================================
        DIO_voidSetPinValue(PORTA, PIN0, PIN_Low);
        DIO_voidSetPinValue(PORTA, PIN1, PIN_High);
        DIO_voidSetPinValue(PORTA, PIN2, PIN_Low);
        DIO_voidSetPinValue(PORTA, PIN3, PIN_High);

        for (int i = 255; i >= 0; i--)
        {
            TIM0_voidCTCSetCompareValue((u8)i);
            TIM1_voidDelayMs(20);
        }

        // ==========================================
        // المرحلة الرابعة: وقوف تام قبل إعادة اللوب
        // ==========================================
        TIM0_voidCTCSetCompareValue(0);
        DIO_voidSetPinValue(PORTA, PIN0, PIN_Low);
        DIO_voidSetPinValue(PORTA, PIN1, PIN_Low);
        DIO_voidSetPinValue(PORTA, PIN2, PIN_Low);
        DIO_voidSetPinValue(PORTA, PIN3, PIN_Low);

        TIM1_voidDelayMs(2000);
    }
}