/*
 * GPIO_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: 7
 */
#include "GPIO_priv.h"
#include "GPIO_int.h"
#include "GPIO_config.h"
#include "RegisterMap.h"
#include "utils.h"
#define CONCBIT_HELPER(P7,P6,P5,P4,P3,P2,P1,P0) 0b##P7#P6#P5#P4#P3#P2#P1#P0
#define CONCBIT(P7,P6,P5,P4,P3,P2,P1,P0)        CONCBIT_HELPER(P7,P6,P5,P4,P3,P2,P1,P0)

gpio_BUS_t  bus;
volatile long int PORT_APB[6] = {0x40004000,0x40005000,0x40006000,0x40007000,0x40024000,0x40025000};
volatile long int PORT_AHB[6] = {0x40058000,0x40059000,0x4005A000,0x4005B000,0x4005C000,0x4005D000};

void GPIO_voidSetBus(gpio_port_t PORT,gpio_BUS_t busUsed)
{
    bus = busUsed;

    GPIOHBCTL |= ((bus&(1 << PORT)));

}

void GPIO_voidSetPinDir(gpio_port_t port,char pin,gpio_portDirection_t MODE)
{

    volatile long int* reg = ((bus&PORT_AHB[port]) | ((~bus)&PORT_APB[port])) + PORT_DIR;

    *reg = ((*reg) & (~(1 << pin))) | ((1 << pin) & MODE);

}

void GPIO_voidPadSet(gpio_port_t port,char pin,gpio_drive_t drive)
{
    volatile long int* reg = ((bus&PORT_AHB[port]) | ((~bus)&PORT_APB[port])) + PORT_DRR + drive;
    *reg = ((*reg) & (~(1 << pin))) | ((1 << pin));


}

void GPIO_voidEnableDigitalFunction(gpio_port_t port,char pin)
{
    volatile long int* reg = ((bus&PORT_AHB[port]) | ((~bus)&PORT_APB[port])) + PORT_AFSEL;
    *reg = ((*reg) & (~(1 << pin)));
    volatile long int* reg2 = ((bus&PORT_AHB[port]) | ((~bus)&PORT_APB[port])) + PORT_DEN;
    *reg2 = ((*reg2) & (~(1 << pin))) | ((1 << pin));

}

void GPIO_voidSetPin(gpio_port_t port,char pin,gpio_portValue_t value)
{

    volatile long int* reg = ((bus&PORT_AHB[port]) | ((~bus)&PORT_APB[port])) + PORT_DATA;

    *reg = ((*reg) & (~(1 << pin))) | ((1 << pin) & value);

}
void GPIO_voidConnectClock(gpio_port_t PORT)
{
    RCGCGPIO |= (1 << PORT);

}
void GPIO_voidInitializeDigitalPin(gpio_port_t PORT,char pin,gpio_portDirection_t MODE,gpio_drive_t drive)
{
     GPIO_voidConnectClock(PORT);
     volatile long int* reg = ((bus&PORT_AHB[PORT]) | ((~bus)&PORT_APB[PORT])) + PORT_DRR + drive;
     *reg = 0xFF;
     volatile long int* reg2 = ((bus&PORT_AHB[PORT]) | ((~bus)&PORT_APB[PORT])) + GPIOCR;
     *reg = 0xFF;
     GPIO_voidEnableDigitalFunction(PORT,pin);
     GPIO_voidSetMODE(PORT,pin,NAF);
     GPIO_voidSetPinDir(PORT,pin,MODE);
}
char GPIO_u8ReadPin(gpio_port_t port,char pin)
{
    volatile long int* reg = ((bus&PORT_AHB[port]) | ((~bus)&PORT_APB[port])) + PORT_DATA;
    return ((*reg) & (1 << pin));
}
void GPIO_voidSetPULL_UP_DN(gpio_port_t port,char pin,gpio_PULL_UP_DN_t resistance)
{
    volatile long int* reg = ((bus&PORT_AHB[port]) | ((~bus)&PORT_APB[port])) + resistance;
    *reg |= (1 << pin);

}

void GPIO_voidSetMODE(gpio_port_t port,char pin,gpio_MODE_t mode)
{

    volatile long int* reg = ((bus&PORT_AHB[port]) | ((~bus)&PORT_APB[port])) + PORT_AFSEL;

    char temp1 = (*reg) |(1 << pin);
    char temp2 = (*reg) & (~(1 << pin));
    reg = ((mode&temp1) | ((~mode)&temp2));



}

void GPIO_voidSetInterruptEvent(gpio_port_t port,char pin,interrupt_t event)
{
    volatile long int* reg = ((bus&PORT_AHB[port]) | ((~bus)&PORT_APB[port])) + GPIO_IM;
    *reg |= (1 << pin);
    if(event != FallingEdge)
    {
    volatile long int* reg = ((bus&PORT_AHB[port]) | ((~bus)&PORT_APB[port])) + 0x404 + (4 * event);
    *reg |= (1 << pin);
    }
    else
    {
        volatile long int* reg = ((bus&PORT_AHB[port]) | ((~bus)&PORT_APB[port])) + 0x40C;
        *reg &= ~(1 << pin);
    }

}

