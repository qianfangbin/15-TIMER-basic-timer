/*
***********************************************************************************
*�ļ�����main.c
*���ߣ�QFB
*�汾��V1.0
*���ڣ�2020-12-25
*˵����ʹ��M3�Ļ�����ʱ��ʵ����ʱ��ʹ��LED��˸���Ϊ1s
*ƽ̨��Ұ��M3������
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




