/*
 * Interrupt_prog.c
 *
 *  Created on: Apr 9, 2020
 *      Author: AL-alamia
 */
void Interrupt_voidEnable(unsigned char INT_ID)
{
    volatile long int* reg = 0xE000E000 + 0x100 + (INT_ID/32);

    *reg |= (1 << (INT_ID%32));
}
void Interrupt_voidDisable(unsigned char INT_ID)
{
    volatile long int* reg = 0xE000E000 + 0x180 + (INT_ID/32);
    *reg |= (1 << (INT_ID%32));

}

void Interrupt_voidSetPending(unsigned char INT_ID)
{
    volatile long int* reg = 0xE000E000 + 0x200 + (INT_ID/32);
    *reg |= (1 << (INT_ID%32));

}

void Interrupt_voidClearPending(unsigned char INT_ID)
{
    volatile long int* reg = 0xE000E000 + 0x280 + (INT_ID/32);
    *reg |= (1 << (INT_ID%32));

}

unsigned char Interrupt_voidGetPending(unsigned char INT_ID)
{
    volatile long int* reg1 = 0xE000E000 + 0x200 + (INT_ID/32);
    volatile long int* reg2 = 0xE000E000 + 0x280 + (INT_ID/32);
    return ((*reg1 & (1 << INT_ID%32)) - (*reg2 & (1 << INT_ID%32)));
}
void Interrupt_voidSetActive(unsigned char INT_ID)
{
    volatile long int* reg = 0xE000E000 + 0x300 + (INT_ID/32);
    *reg |= (1 << (INT_ID%32));
}
unsigned char Interrupt_voidGetState(unsigned char INT_ID)
{
    volatile long int* reg = 0xE000E000 + 0x300 + (INT_ID/32);
    return (*reg & (1 << INT_ID%32));

}

