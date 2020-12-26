/*
***********************************************************************************
*�ļ�����bsp_led.c
*���ߣ�QFB
*�汾��V1.0
*���ڣ�2020-12-13
*˵����LED���Ƶײ㺯��ʵ��
*ƽ̨��Ұ��M3������
***********************************************************************************
*/

#include "stm32f10x.h"    //ʵ��bsp_led.h���Ѱ���stm32f10x.hͷ�ļ������п���ע�͵�
#include "bsp_led.h"

void LED_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructrue;
    
    RCC_APB2PeriphClockCmd(LED1_GPIO_CLK | LED2_GPIO_CLK | LED3_GPIO_CLK, ENABLE);
    
    /*�˴����ú�GPIO_Mode���void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)��������CRL/CRH�Ĵ���*/
    GPIO_InitStructrue.GPIO_Mode = GPIO_Mode_Out_PP;
    /*�˴����ú�GPIO_Speed���void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)��������CRL/CRH�Ĵ���*/
    GPIO_InitStructrue.GPIO_Speed = GPIO_Speed_50MHz;   
    
    /*LED1 GPIO��ʼ��*/
    GPIO_InitStructrue.GPIO_Pin = LED1_GPIO_PIN;
    GPIO_Init(LED1_GPIO_PORT,&GPIO_InitStructrue);  //GPIO_Init֮ǰ����ȫ�����ú����š�ģʽ���ٶ�
    
    /*LED2 GPIO��ʼ��*/
    GPIO_InitStructrue.GPIO_Pin = LED2_GPIO_PIN;    
    GPIO_Init(LED2_GPIO_PORT,&GPIO_InitStructrue);
    
    /*LED3 GPIO��ʼ��*/
    GPIO_InitStructrue.GPIO_Pin = LED3_GPIO_PIN;    
    GPIO_Init(LED3_GPIO_PORT,&GPIO_InitStructrue);
    
    /*�ر�ȫ��LED��*/
    GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);    
    GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);    
    GPIO_SetBits(LED3_GPIO_PORT,LED3_GPIO_PIN);
    
}


/*********************************************END OF FILE****************************************/
