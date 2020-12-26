/*
***********************************************************************************
*文件名：main.c
*作者：QFB
*版本：V1.0
*日期：2020-12-25
*说明：使用M3的基本定时器实现延时，使得LED闪烁间隔为1s
*平台：野火M3开发板
***********************************************************************************
*/
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_timer.h"

extern __IO uint32_t times;

int main(void)
{
    LED_GPIO_Config();
    TIMER_NVIC_Config();
    TIMER_Config();
    while(1)
    {
        if(times == 1000)   // 1000 * 1ms = 1s
        {
            LED1_TOGGLE;
            times = 0;
        }
    }
	
}




