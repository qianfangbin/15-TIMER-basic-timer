#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"

#define LED1_GPIO_PORT    GPIOC
#define LED1_GPIO_CLK     RCC_APB2Periph_GPIOC
#define LED1_GPIO_PIN     GPIO_Pin_3

#define LED2_GPIO_PORT    GPIOC
#define LED2_GPIO_CLK     RCC_APB2Periph_GPIOC
#define LED2_GPIO_PIN     GPIO_Pin_4

#define LED3_GPIO_PORT    GPIOC
#define LED3_GPIO_CLK     RCC_APB2Periph_GPIOC
#define LED3_GPIO_PIN     GPIO_Pin_5

#define ON   0      //�͵�ƽ����
#define OFF  1      //�ߵ�ƽ����


/*ʹ�ÿ⺯������IO�����ô��κ�ķ�ʽ*/
#define LED1(a)      if(a) GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);\
                    else GPIO_ResetBits(LED1_GPIO_PORT,LED1_GPIO_PIN)
                        
#define LED2(a)      if(a) GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);\
                    else GPIO_ResetBits(LED2_GPIO_PORT,LED2_GPIO_PIN)
                        
#define LED3(a)      if(a) GPIO_SetBits(LED3_GPIO_PORT,LED3_GPIO_PIN);\
                    else GPIO_ResetBits(LED3_GPIO_PORT,LED3_GPIO_PIN)
                        
/*ֱ�Ӳ����Ĵ�������IO��ʵ�ʺͿ⺯��ʵ�ַ���һ��*/      
#define digitHi(p,i)            {p->BSRR = i;} 
#define digitLo(p,i)            {p->BRR = i;} 
#define digitToggle(p,i)        {p->ODR ^= i;} 
                    
#define LED1_ON                 digitLo(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_OFF                digitHi(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_TOGGLE             digitToggle(LED1_GPIO_PORT,LED1_GPIO_PIN)

#define LED2_ON                 digitLo(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_OFF                digitHi(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_TOGGLE             digitToggle(LED2_GPIO_PORT,LED2_GPIO_PIN)

#define LED3_ON                 digitLo(LED3_GPIO_PORT,LED3_GPIO_PIN)
#define LED3_OFF                digitHi(LED3_GPIO_PORT,LED3_GPIO_PIN)
#define LED3_TOGGLE             digitToggle(LED3_GPIO_PORT,LED3_GPIO_PIN)

/*��ͷ�ļ�����������������ֲ*/
void LED_GPIO_Config(void);

#endif

/*********************************************END OF FILE**********************/
   

