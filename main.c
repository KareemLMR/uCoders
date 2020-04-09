

/**
 * main.c
 */

/*
 * System control main features:
     1-Reset control
     2-NMI control
     3-Clock control  ---->  (Source,mode,PLL,Frequency) (Main OCs verification) (ADC,SPI,UART,....) (PWM source)
     4-Power control
     5-Low power
 */
#include "RegisterMap.h"
#include "GPIO_int.h"
#include "GPIO_priv.h"
#include "delay.h"
#include "Interrupt_int.h"
int x = 0;
int main(void)
{
//Clock set
    RCC |= (1 << 11);
    RCC &= ~(1 << 22);
    RCC |= (1 << 4);
    RCC &= ~(1 << 5);
    RCC |= (1 << 13);
// Timer set
    RCGCWTIMER |= (1 << 0);
    GPTMTAMR0_Wide |= (1 << 4)|(1 << 1)|(1 << 5);
    GPTMIMR0_Wide |= (1 << 16)|(1 << 4);
    GPTMCTL0_Wide = 1;

    //GPTMTAMATCHR0_Wide |= ();

    GPIO_voidSetBus(PORTF,AHB);
    GPIO_voidInitializeDigitalPin(PORTF,1,OUTPUT,Drive_8mA);
    GPIO_voidInitializeDigitalPin(PORTF,2,OUTPUT,Drive_8mA);
    GPIO_voidInitializeDigitalPin(PORTF,3,OUTPUT,Drive_8mA);
    GPIO_voidInitializeDigitalPin(PORTF,4,INPUT,Drive_8mA);

    //GPIOLOCK_F_AHB = 0;

    GPIO_voidSetPULL_UP_DN(PORTF,4,PULLUP);

    Interrupt_voidEnable(30);
    GPIO_voidSetInterruptEvent(PORTF,4,Level);


    while(1)
    {
//       if(!GPIO_u8ReadPin(PORTF,4))
//       {
//        GPIO_voidSetPin(PORTF,1,HIGH);
//        GPIO_voidSetPin(PORTF,2,HIGH);
//        GPIO_voidSetPin(PORTF,3,HIGH);
//       }
//       else
//       {
//           GPIO_voidSetPin(PORTF,1,LOW);
//           GPIO_voidSetPin(PORTF,2,LOW);
//           GPIO_voidSetPin(PORTF,3,LOW);
//       }
//
        GPIO_voidSetPin(PORTF,1,LOW);

    }
    return 0;
}
void Blink_LED()
{


        GPIO_voidSetPin(PORTF,1,HIGH);


}
