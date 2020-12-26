/*
***********************************************************************************
*文件名：bsp_led.c
*作者：QFB
*版本：V1.0
*日期：2020-12-22
*说明：ADC外设初始化配置
*平台：野火M3开发板
***********************************************************************************
*/

#include "stm32f10x.h"    
#include "bsp_adc.h"

__IO uint16_t ADC_ConvertedValue;


void ADCX_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructrue;

    ADCX_GPIO_APBPERIPHCLOCKCMD(ADCX_GPIO_CLK, ENABLE);

    /* ADC GPIO配置*/
    GPIO_InitStructrue.GPIO_Pin = ADCX_GPIO_PIN;
    GPIO_InitStructrue.GPIO_Mode = GPIO_Mode_AIN;
    
    GPIO_Init(ADCX_GPIO_PORT,&GPIO_InitStructrue);  
      
}


void ADCX_Config(void)
{
    DMA_InitTypeDef DMA_InitStructure;
    ADC_InitTypeDef ADC_InitStructure;

    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
    ADCX_AFIO_APBPERIPHCLOCKCMD(ADCX_AFIO_CLK, ENABLE);

    DMA_DeInit(ADC_DMA_CHANNEL);

    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&(ADCX->DR));

    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)(&ADC_ConvertedValue);
    /* Initialize the DMA_DIR member */
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
    /* Initialize the DMA_BufferSize member */
    DMA_InitStructure.DMA_BufferSize = 1;
    /* Initialize the DMA_PeripheralInc member */
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    /* Initialize the DMA_MemoryInc member */
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable;
    /* Initialize the DMA_PeripheralDataSize member */
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;     //((uint32_t)0x00000100)
    /* Initialize the DMA_MemoryDataSize member */
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord; // ((uint32_t)0x00000400) do not copy from provious line paramter,they have different value
    /* Initialize the DMA_Mode member */
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
    /* Initialize the DMA_Priority member */
    DMA_InitStructure.DMA_Priority = DMA_Priority_High;
    /* Initialize the DMA_M2M member */
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;

    DMA_Init(ADC_DMA_CHANNEL, &DMA_InitStructure);

    DMA_Cmd(ADC_DMA_CHANNEL, ENABLE);

    //ADC 外设初始化
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_InitStructure.ADC_ScanConvMode =DISABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right ;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
    ADC_InitStructure.ADC_NbrOfChannel = 1;
    ADC_Init(ADCX,&ADC_InitStructure);
    // 配置ADC时钟为PCLK2的8分频，即9MHz
    RCC_ADCCLKConfig(RCC_PCLK2_Div8);
    // 配置 ADC 通道转换顺序为1，第一个转换，采样时间为55.5个时钟周期
    ADC_RegularChannelConfig(ADCX, ADCX_CHANNEL, 1, ADC_SampleTime_55Cycles5);
    //使能ADC DMA请求
    ADC_DMACmd(ADCX, ENABLE);
    //使能ADC
    ADC_Cmd(ADCX,ENABLE);
    // 初始化ADC 校准寄存器  
    ADC_ResetCalibration(ADCX);
    while(ADC_GetResetCalibrationStatus(ADCX));
    // ADC开始校准
    ADC_StartCalibration(ADCX);
    while(ADC_GetCalibrationStatus(ADCX));
    // 使用软件触发ADC转换 
    ADC_SoftwareStartConvCmd(ADCX, ENABLE);
        
}


void ADCX_Init(void)
{
    ADCX_GPIO_Config();
    ADCX_Config();

}

/*********************************************END OF FILE****************************************/
