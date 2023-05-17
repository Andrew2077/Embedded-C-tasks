#ifndef INC_DELAYH
#define INC_DELAYH
#include "stm32f4xx.h"
#include <stdint.h>

__IO time_us, time_ms;

void delayInit(void);
void delay_us(uint32_t us_value);
void delay_ms(uint32_t);
void SysTick_Handler(void);
#endif /* INC_DELAYH */
