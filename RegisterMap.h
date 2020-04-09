/*
 * CLK_RegisterMap.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: 7
 */

#ifndef REGISTERMAP_H_
#define REGISTERMAP_H_


#define SYS_CTRL_RCGC2  (*((volatile unsigned long *)0x400FE108))   //offset of RCGC2 register is 0x108
#define CLK_GPIOF   0x20

//---GPIO-F REGISTER---//
#define PORTF_DATA  (*((volatile unsigned long *)0x40025038))   //offset of DATA register for PF1, PF2, PF3 is 0x38 [PF7:PF0::9:2]
#define PORTF_DIR   (*((volatile unsigned long *)0x40025400))   //offset of DIR register is 0x400
#define PORTF_DEN   (*((volatile unsigned long *)0x4002551C))   //offset of DEN register is 0x51C

//---PORT-F I/O---//
#define PF1 0x02
#define PF2 0x04
#define PF3 0x08

#define CLK_BASE_ADD             (*((volatile unsigned int *)0x400FE000))
#define add_off(base,offset)          ( (offset)+base)

#define RCC               (*((volatile unsigned int *)0x400FE060))
#define RCC2              (*((volatile unsigned int *)0x400FE070))
#define MOSCCTL           (*((volatile unsigned int *)0x400FE07C))
#define PIOSCCAL          (*((volatile unsigned int *)0x400FE150))
#define PLLSTAT           (*((volatile unsigned int *)0x400FE168))
#define RCGCGPIO          (*((volatile unsigned int *)0x400FE608))
#define GPIOHBCTL         (*((volatile unsigned int *)0x400FE06C))


#define GPIO_A_APB_BASE_ADD             (*((volatile unsigned int *)0x40004000))

#define GPIO_B_APB_BASE_ADD             (*((volatile unsigned int *)0x40005000))

#define GPIO_C_APB_BASE_ADD             (*((volatile unsigned int *)0x40006000))

#define GPIO_D_APB_BASE_ADD             (*((volatile unsigned int *)0x40007000))

#define GPIO_E_APB_BASE_ADD             (*((volatile unsigned int *)0x40024000))

#define GPIO_F_APB_BASE_ADD             (*((volatile unsigned int *)0x40025000))


#define GPIO_A_AHB_BASE_ADD             (*((volatile unsigned int *)0x40058000))

#define GPIO_B_AHB_BASE_ADD             (*((volatile unsigned int *)0x40059000))

#define GPIO_C_AHB_BASE_ADD             (*((volatile unsigned int *)0x4005A000))

#define GPIO_D_AHB_BASE_ADD             (*((volatile unsigned int *)0x4005B000))

#define GPIO_E_AHB_BASE_ADD             (*((volatile unsigned int *)0x4005C000))

#define GPIO_F_AHB_BASE_ADD             (*((volatile unsigned int *)0x4005D000))




#define PORT_DATA                0x3FC
#define PORT_DIR                 0x400
#define PORT_AFSEL               0x420
#define PORT_DEN                 0x51C
#define PORT_DRR                 0x500
//#define PORT_LOCK
#define GPIOPUR                  0x510
#define GPIOPDN                  0x514
#define GPIOCR                   0x524
#define GPIO_IM                  0x410

#define GPIODIR_A_APB            add_off(GPIO_A_APB_BASE_ADD,0x400)
#define GPIOAFSEL_A_APB              add_off(GPIO_A_APB_BASE_ADD,0x420)
#define GPIODR8R_A_APB           add_off(GPIO_A_APB_BASE_ADD,0x508)
#define GPIODEN_A_APB          add_off(GPIO_A_APB_BASE_ADD,0x51C)

#define GPIODIR_A_AHB            add_off(GPIO_A_AHB_BASE_ADD,0x400)
#define GPIOAFSEL_A_AHB              add_off(GPIO_A_AHB_BASE_ADD,0x420)
#define GPIODR8R_A_AHB           add_off(GPIO_A_AHB_BASE_ADD,0x508)
#define GPIODEN_A_AHB          add_off(GPIO_A_AHB_BASE_ADD,0x51C)

#define GPIODIR_B_APB            add_off(GPIO_B_APB_BASE_ADD,0x400)
#define GPIOAFSEL_B_APB              add_off(GPIO_B_APB_BASE_ADD,0x420)
#define GPIODR8R_B_APB           add_off(GPIO_B_APB_BASE_ADD,0x508)
#define GPIODEN_B_APB          add_off(GPIO_B_APB_BASE_ADD,0x51C)

#define GPIODIR_B_AHB            add_off(GPIO_B_AHB_BASE_ADD,0x400)
#define GPIOAFSEL_B_AHB              add_off(GPIO_B_AHB_BASE_ADD,0x420)
#define GPIODR8R_B_AHB           add_off(GPIO_B_AHB_BASE_ADD,0x508)
#define GPIODEN_B_AHB          add_off(GPIO_B_AHB_BASE_ADD,0x51C)

#define GPIODIR_C_APB            add_off(GPIO_C_APB_BASE_ADD,0x400)
#define GPIOAFSEL_C_APB              add_off(GPIO_C_APB_BASE_ADD,0x420)
#define GPIODR8R_C_APB           add_off(GPIO_C_APB_BASE_ADD,0x508)
#define GPIODEN_C_APB          add_off(GPIO_C_APB_BASE_ADD,0x51C)

#define GPIODIR_C_AHB            add_off(GPIO_C_AHB_BASE_ADD,0x400)
#define GPIOAFSEL_C_AHB              add_off(GPIO_C_AHB_BASE_ADD,0x420)
#define GPIODR8R_C_AHB           add_off(GPIO_C_AHB_BASE_ADD,0x508)
#define GPIODEN_C_AHB          add_off(GPIO_C_AHB_BASE_ADD,0x51C)


#define GPIODIR_D_APB            add_off(GPIO_D_APB_BASE_ADD,0x400)
#define GPIOAFSEL_D_APB              add_off(GPIO_D_APB_BASE_ADD,0x420)
#define GPIODR8R_D_APB           add_off(GPIO_D_APB_BASE_ADD,0x508)
#define GPIODEN_D_APB          add_off(GPIO_D_APB_BASE_ADD,0x51C)

#define GPIODIR_D_AHB            add_off(GPIO_D_AHB_BASE_ADD,0x400)
#define GPIOAFSEL_D_AHB              add_off(GPIO_D_AHB_BASE_ADD,0x420)
#define GPIODR8R_D_AHB           add_off(GPIO_D_AHB_BASE_ADD,0x508)
#define GPIODEN_D_AHB          add_off(GPIO_D_AHB_BASE_ADD,0x51C)

#define GPIODIR_E_APB            add_off(GPIO_E_APB_BASE_ADD,0x400)
#define GPIOAFSEL_E_APB              add_off(GPIO_E_APB_BASE_ADD,0x420)
#define GPIODR8R_E_APB           add_off(GPIO_E_APB_BASE_ADD,0x508)
#define GPIODEN_E_APB          add_off(GPIO_E_APB_BASE_ADD,0x51C)

#define GPIODIR_E_AHB            add_off(GPIO_E_AHB_BASE_ADD,0x400)
#define GPIOAFSEL_E_AHB              add_off(GPIO_E_AHB_BASE_ADD,0x420)
#define GPIODR8R_E_AHB           add_off(GPIO_E_AHB_BASE_ADD,0x508)
#define GPIODEN_E_AHB          add_off(GPIO_E_AHB_BASE_ADD,0x51C)

#define GPIODIR_F_APB            add_off(GPIO_F_APB_BASE_ADD,0x400)
#define GPIOAFSEL_F_APB              add_off(GPIO_F_APB_BASE_ADD,0x420)
#define GPIODR8R_F_APB           add_off(GPIO_F_APB_BASE_ADD,0x508)
#define GPIODEN_F_APB          add_off(GPIO_F_APB_BASE_ADD,0x51C)
#define GPIODATA_F_APB        (*((volatile unsigned int *)0x40025038))

#define GPIODIR_F_AHB            (*((volatile unsigned int *)0x4005D400))
#define GPIOAFSEL_F_AHB          (*((volatile unsigned int *)0x4005D420))
#define GPIODR8R_F_AHB           (*((volatile unsigned int *)0x4005D508))
#define GPIODEN_F_AHB          (*((volatile unsigned int *)0x4005D51C))
#define GPIOLOCK_F_AHB        (*((volatile unsigned int *)0x4005D520))
#define GPIODATA_F_AHB        (*((volatile unsigned int *)0x4005D3FC))




#define GPTMTAMR0_Wide                  (*((volatile unsigned int*)0x40036004))
#define GPTMCTL0_Wide                   (*((volatile unsigned int*)0x4003600C))
#define GPTMIMR0_Wide                   (*((volatile unsigned int*)0x40036018))
#define GPTMTAMATCHR0_Wide              (*((volatile unsigned int*)0x40036030))
#define RCGCWTIMER                      (*((volatile unsigned int*)0x400FE65C))



//GPIO Interrupt Registers:
#define GPIOIS_PORTF_AHB                      (*((volatile unsigned int*) 0x4005D404))
#define GPIOIM_PORTF_AHB                      (*((volatile unsigned int*) 0x4005D410))
#define        EN0                            (*((volatile unsigned int*) 0xE000E100))





















#endif /* REGISTERMAP_H_ */
