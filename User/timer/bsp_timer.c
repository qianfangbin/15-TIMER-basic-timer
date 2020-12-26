/*
***********************************************************************************
*�ļ�����bsp_led.c
*���ߣ�QFB
*�汾��V1.0
*���ڣ�2020-12-25
*˵����������ʱ������
*ƽ̨��Ұ��M3������
***********************************************************************************
*/

#include "stm32f10x.h"    
#include "bsp_timer.h"


//��ʼ��NVICΪ�ж���׼��
void TIMER_NVIC_Config(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

    NVIC_InitStructure.NVIC_IRQChannel = TIMER_IRQ;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

    NVIC_Init(&NVIC_InitStructure);

}


void TIMER_Config(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitstructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);

    TIM_TimeBaseInitstructure.TIM_Prescaler = 72-1;    // CK_CNT = 72M / 72 = 1MHZ
    TIM_TimeBaseInitstructure.TIM_Period = 1000;       // ARR VALUE = 1000
    TIM_TimeBaseInitstructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitstructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitstructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIMER, &TIM_TimeBaseInitstructure);
    TIM_ClearFlag(TIMER, TIM_FLAG_Update);
    TIM_ITConfig(TIMER, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIMER, ENABLE);
    //RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, DISABLE);
}



/*********************************************END OF FILE****************************************/
