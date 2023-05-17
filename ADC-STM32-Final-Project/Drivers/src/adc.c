#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "adc.h"
#include "stm32f4xx.h"
#include "gpio.h"
#include "lcd_4bit.h"

void ADC1_Config(void)
{
  /* GPIO Configuration for PA0 */

  /* Enable port A clock */
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

  /* Select Analog mode of GPIOA Pin Number 0 */
  GPIOA->MODER |= GPIO_MODER_MODER0;

  /* Select no pull-up, pull-down (reset state) */
  GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR0;

  /* ADC Configuration for (PA0 -> ADC1_IN0) */

  /* Enable ADC1 clock */
  RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

  /* Enable ADC */
  ADC1->CR2 |= ADC_CR2_ADON;

  /* Setting Cycles */
  ADC1->SMPR2 &=~ (1<<0);

  /* Setting NVIC */
  NVIC->ISER[0]|=(1u<<(18));

  /* ADC prescaler PCLK2 divided by 2 */
  ADC->CCR &= ~ADC_CCR_ADCPRE;

  /* Select Right alignment */
  ADC1->CR2 &= ~ADC_CR2_ALIGN;
}

void ADC_Init(struct ADCConfigType* ConfigParamPtr)
{
	ConfigParamPtr->Mode = Continues;
	ConfigParamPtr->Resolution = res_12;
	ConfigParamPtr->Vref = 1.5;

	/* Set Resolution */
	ADC1 ->CR1 |= ConfigParamPtr->Resolution;

	/* Set Mode (Continues Or Single) */
	ADC1->CR2 |= ConfigParamPtr->Mode;

	/* Set Vref */
	Vref = ConfigParamPtr->Vref;
}

void ADC_StartConv(unsigned char ChannelNum){

	  //select channel
	  ADC1->SQR3 |= ChannelNum;

	  /* Setting interrupt for regular channels */
	  if (USE_POLLING){
		  ADC1->CR1 &=~ADC_CR1_EOCIE;
	  }
	  else{
		  ADC1->CR1 |= ADC_CR1_EOCIE;
	  }

	  /* Start conversion of regular channels */
	  ADC1->CR2 |= ADC_CR2_SWSTART;
}

void ADC_GetConversionState(unsigned char* ConversionStatePtr){

	  /* Check ADC1 EOC */
	  if((ADC1->SR & ADC_SR_EOC) == ADC_SR_EOC){
		  *ConversionStatePtr = 1;
	  }
	  else {
		  *ConversionStatePtr = 0;
	  }
}

unsigned char ADC_ReadData(unsigned short int* DataPtr)
{
	  if (USE_POLLING){
		  ADC_GetConversionState(&Ended_Conversion);
	  }

	  if (Ended_Conversion){
		  /* Read analog data and clear EOC flag */
		  *DataPtr = (unsigned short int)((ADC1->DR/(4095.0f))*(150*Vref));
			  return 0;
		  }

	  else{
			  return 1;
		  }
}
