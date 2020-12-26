#ifndef __BSP_USART_H
#define __BSP_USART_H

#include "stm32f10x.h"
#include "stdio.h"

//����1-USART1
//���ź궨��
#define USART_TX_GPIO_PORT              GPIOA
#define USART_TX_GPIO_PIN               GPIO_Pin_9
#define USART_RX_GPIO_PORT              GPIOA
#define USART_RX_GPIO_PIN               GPIO_Pin_10

#define USART_GPIO_CLK                  RCC_APB2Periph_GPIOA
#define USART_GPIO_APBPERIPHCLOCKCMD    RCC_APB2PeriphClockCmd

//��������궨��
#define USART                           USART1
#define USART_AFIO_CLK                  RCC_APB2Periph_USART1  //����1����ʹ�õ���APB2ʱ��
#define USART_AFIO_APBPERIPHCLOCKCMD    RCC_APB2PeriphClockCmd
#define USART_BAUDRATE                  115200


void USART_Config(void);

int fputc(int ch, FILE *f);
int fgetc(FILE *f);
void USART_SendByte(USART_TypeDef *pUSARTx, uint8_t ch);
void USART_SendString(USART_TypeDef *pUSARTx, char *str);
void USART_SendHalfWord(USART_TypeDef *pUSARTx, uint16_t ch);

#endif

/*********************************************END OF FILE**********************/
   

