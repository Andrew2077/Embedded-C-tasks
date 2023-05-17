#include "stm32f4xx.h"
#include "gpio.h"

void GPIO_Init (GPIO_TypeDef * GPIOx,char pin,char dir,char enable_pin)
{
	//Enable clock to GBIOx
	RCC->AHB1ENR |= (1u<<enable_pin);

	if(dir)
	{
		GPIOx->MODER |= (1u<<(2*pin));
		GPIOx->MODER &=~(1u<<(2*pin+1));

	}
	else
	{
		GPIOx->MODER &=~(1u<<(2*pin));
		GPIOx->MODER &=~(1u<<(2*pin+1));
	}

}

char GPIO_Write(GPIO_TypeDef * GPIOx,char pin,char state)
{
	if (GPIOx->MODER & (1u<<(2*pin)))
	{
		if(state)
			{
				GPIOx->ODR |=(1u<<pin);
			}
			else
			{
				GPIOx->ODR &=~(1u<<pin);
			}
		return 0;
	}
	else
	{
		return 1;
	}
}


char GPIO_Read(GPIO_TypeDef * GPIOx,char pin)
{
	if (GPIOx->MODER & (1u<<(2*pin))){
		if(GPIOx->ODR & (1<<pin)){
			return 1;
		}

		else{
			return 0;
		}
	}

	else{
		if(GPIOx->IDR & (1<<pin)){
			return 1;
		}

		else{
			return 0;
		}
	}
}
