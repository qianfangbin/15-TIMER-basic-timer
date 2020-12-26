#ifndef __BSP_TIMER_H
#define __BSP_TIMER_H

#include "stm32f10x.h"
#include "stdio.h"


//外设宏定义
#define TIMER                           TIM6


//中断宏定义
#define TIMER_IRQ                       TIM6_IRQn
#define TIMER_IRQHANDLER                TIM6_IRQHandler


#endif

void TIMER_NVIC_Config(void);
void TIMER_Config(void);



/*********************************************END OF FILE**********************/
   

