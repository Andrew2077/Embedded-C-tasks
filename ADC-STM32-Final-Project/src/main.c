#include <stdlib.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "adc.h"
#include "gpio.h"
#include "lcd_4bit.h"
#include "delay.h"


int main(void)
{
	struct ADCConfigType* par = (struct ADCConfigType*) malloc(sizeof(struct ADCConfigType));

	Ended_Conversion = 1;

	ADC1_Config();
	ADC_Init(par);

	delayInit();
	lcd_init();
	lcd_gotoxy(0, 1);
    lcd_dispString("Temp:");

	ADC_StartConv(0);
	delay_ms(10);

	while(1)
	{
		if (USE_POLLING){
			  notValid = ADC_ReadData(&dataPtr);
		}

		  if(!notValid){
			   snprintf(displayText,7,"%d",dataPtr);
			   lcd_gotoxy(0, 7);
			   lcd_dispString(displayText);
			   lcd_displayChar(0xDF);
			   lcd_dispString("C   ");
			   notValid = 1;
		  }

		  if(!(ADC1->CR2 & ADC_CR2_CONT)){
			  ADC1->CR2 |= ADC_CR2_SWSTART;
		  }
    }
}

void ADC_IRQHandler(void)
{
	  /* Check ADC1 EOC */
	  notValid = ADC_ReadData(&dataPtr);
}
