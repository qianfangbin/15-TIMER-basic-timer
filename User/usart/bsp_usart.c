/*
***********************************************************************************
*�ļ�����bsp_led.c
*���ߣ�QFB
*�汾��V1.0
*���ڣ�2020-12-16
*˵��������USART��ʼ���Լ��շ�ʵ��
*ƽ̨��Ұ��M3������
***********************************************************************************
*/

#include "stm32f10x.h"    
#include "bsp_usart.h"


void USART_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructrue;

    USART_InitTypeDef USART_InitStructure;

    USART_GPIO_APBPERIPHCLOCKCMD(USART_GPIO_CLK, ENABLE);

    USART_AFIO_APBPERIPHCLOCKCMD(USART_AFIO_CLK, ENABLE);

    /*TX GPIO��ʼ��*/
    GPIO_InitStructrue.GPIO_Pin = USART_TX_GPIO_PIN;
    GPIO_InitStructrue.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructrue.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_Init(USART_TX_GPIO_PORT,&GPIO_InitStructrue);  
    
    /*RX GPIO��ʼ��*/
    GPIO_InitStructrue.GPIO_Pin = USART_RX_GPIO_PIN;
    GPIO_InitStructrue.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(USART_RX_GPIO_PORT,&GPIO_InitStructrue);  
    
    //UASART�����ʼ��
    USART_InitStructure.USART_BaudRate = USART_BAUDRATE;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_Init(USART,&USART_InitStructure);
    
    //ʹ�ܴ���
    USART_Cmd(USART,ENABLE);
    
}

//�ض���C�⺯��printf�����ڣ�ʵ�ִ��ڷ���
int fputc(int ch, FILE *f)                  //FILE�ؼ����Ƕ�����stdio.h��
{
    //����һ���ֽ����ݵ�����
    USART_SendData(USART,(uint8_t) ch);
    //�ȴ����ڷ��ͼĴ���Ϊ�գ�����ʾ���
    while(USART_GetFlagStatus(USART,USART_FLAG_TXE) == RESET)
        ;
    return (ch);

}

//�ض���C�⺯��scanf��getchar�����ڣ�ʵ�ִ��ڽ���
int fgetc(FILE *f)
{   
    //�ȴ����ڽ�������
    while(USART_GetFlagStatus(USART, USART_FLAG_RXNE) == RESET)
        ;
    return (int)USART_ReceiveData(USART);
}

//����һ���ַ�
void USART_SendByte(USART_TypeDef *pUSARTx, uint8_t ch)
{
    USART_SendData(pUSARTx,ch);

    while(USART_GetFlagStatus(USART, USART_FLAG_TXE) == RESET)
        ;
}

//�����ַ���
void USART_SendString(USART_TypeDef *pUSARTx, char *str)
{
    uint8_t k = 0;
    do
    {
        USART_SendByte(pUSARTx, *(str + k ));
        k++;

    } while (*(str + k ) != '\0');
    
    while(USART_GetFlagStatus(USART,USART_FLAG_TC) == RESET)
        ;
}


//����һ��16λ��
void USART_SendHalfWord(USART_TypeDef *pUSARTx, uint16_t ch)
{
    uint8_t temp_h, temp_l;
    //ȡ����8λ
    temp_h = (ch & 0xff00) >> 8;
    //ȡ����8λ
    temp_l = ch & 0x00ff;
    //�ȷ��͵�8λ
    USART_SendData(pUSARTx,temp_l);
    while(USART_GetFlagStatus(USART, USART_FLAG_TXE) == RESET)
        ;
    //�ٷ��͸�8λ
    USART_SendData(pUSARTx,temp_h);
    while(USART_GetFlagStatus(USART, USART_FLAG_TXE) == RESET)
        ;
}


/*********************************************END OF FILE****************************************/
