#ifndef __BSP_ADC_H
#define __BSP_ADC_H

#include "stm32f10x.h"
#include "stdio.h"

//ADC1
//引脚宏定义
#define ADCX_GPIO_PORT                 GPIOC
#define ADCX_GPIO_PIN                  GPIO_Pin_1
#define ADCX_GPIO_CLK                  RCC_APB2Periph_GPIOC
#define ADCX_GPIO_APBPERIPHCLOCKCMD    RCC_APB2PeriphClockCmd

//外设宏定义
#define ADCX                           ADC1
#define ADCX_AFIO_CLK                  RCC_APB2Periph_ADC1
#define ADCX_AFIO_APBPERIPHCLOCKCMD    RCC_APB2PeriphClockCmd

//ADC中断宏定义
// #define ADCX_IRQ                       ADC1_2_IRQn
// #define ADCX_IRQHANDLER                ADC1_2_IRQHandler

#define ADCX_CHANNEL                   ADC_Channel_11

#define ADC_DMA_CHANNEL                DMA1_Channel1    //ADC1使用DMA1的通道1

#endif


void ADCX_Init(void);


/*********************************************END OF FILE**********************/
   

