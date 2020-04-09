/*
 * GPIO_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: 7
 */

#ifndef GPIO_INT_H_
#define GPIO_INT_H_

typedef enum{PORTA = 0,PORTB,PORTC,PORTD,PORTE,PORTF}gpio_port_t;
typedef enum{APB = 0,AHB= 0xFFFFFFFF}gpio_BUS_t;
typedef enum{INPUT = 0, OUTPUT = 0xFFFFFFFF,INPUT_PULLUP,INPUT_PULLDOWN,OUTPUT_OPEN_DRAIN}gpio_portDirection_t;
typedef enum{LOW = 0, HIGH = 0xFFFFFFFF}gpio_portValue_t;
typedef enum{Drive_2mA = 0,Drive_4mA = 4,Drive_8mA = 8}gpio_drive_t;
typedef enum{PULLDN = 0x514 , PULLUP = 0x510}gpio_PULL_UP_DN_t;
typedef enum{NAF = 0 , AF = 0xFFFFFFFF}gpio_MODE_t;

typedef enum{Level = 0,RisingEdge,BothEdges,FallingEdge}interrupt_t;

void GPIO_voidInitializeDigitalPin(gpio_port_t,char,gpio_portDirection_t,gpio_drive_t);
void GPIO_voidSetPinDir(gpio_port_t,char,gpio_portDirection_t);
void GPIO_voidSetPin(gpio_port_t,char,gpio_portValue_t);
void GPIO_voidSetBus(gpio_port_t,gpio_BUS_t);
void GPIO_voidPadSet(gpio_port_t,char,gpio_drive_t);
void GPIO_voidEnableDigitalFunction(gpio_port_t,char);
void GPIO_voidConnectClock(gpio_port_t);
char GPIO_u8ReadPin(gpio_port_t,char);
void GPIO_voidSetPULL_UP_DN(gpio_port_t,char,gpio_PULL_UP_DN_t);
void GPIO_voidSetMODE(gpio_port_t,char,gpio_MODE_t);

void GPIO_voidSetInterruptEvent(gpio_port_t,char,interrupt_t);
#endif /* GPIO_INT_H_ */
