#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

/* Required 3 tasks each one toggles a led with diff speed*/
/*add timer config to freertosconfiq */

// Function prototypes.
// fcpu clock speed for atmega32

#define F_CPU 1000000
#define NUM_TIMERS 3
TimerHandle_t xTimers[NUM_TIMERS];

void Task1_Func(TimerHandle_t xTimers);
void Task2_Func(TimerHandle_t xTimers);
void Task3_Func(TimerHandle_t xTimers);

// array of pointers to timers
int *Call_backs[NUM_TIMERS] = {&Task1_Func, &Task2_Func, &Task3_Func};
int main(void)
{

	DDRC = 0xFF; // Configure all PORTC pins as output pins

	// Time Handlers
	// TimerHandle_t xTimer1 = xTimerCreate("timer1", 20, pdTRUE, (void *)0, &Task1_Func);
	// TimerHandle_t xTimer2 = xTimerCreate("timer2", 30, pdTRUE, (void *)1, &Task1_Func);
	// TimerHandle_t xTimer3 = xTimerCreate("timer3", 50, pdTRUE, (void *)2, &Task1_Func);
	// // TimerHandle_t xTimer2 = xTimerCreate("timer2", 10, pdTRUE, (void *)1, vTimerCallback);
	// // TimerHandle_t xTimer3 = xTimerCreate("timer3", 10, pdTRUE, (void *)2, vTimerCallback);
	// xTimerStart(xTimer1, 10);
	// xTimerStart(xTimer2, 15);
	// xTimerStart(xTimer3, 25);
	// create multiple timers
	for (int i = 0; i < NUM_TIMERS; i++)
	{
		xTimers[i] = xTimerCreate("timer1", 20, pdTRUE, (void *)i, Call_backs[i]);
		xTimerStart(xTimers[i], 10);
	}

	// for (int i = 0; i < NUM_TIMERS; i++)
	// {
	// 	TimerHandle_t xTimer1 = xTimerCreate("timer1", 50, pdTRUE, (void *)i, &Task1_Func);
	// 	xTimerStart(xTimer1, 10);
	// }
	vTaskStartScheduler();
	while (1)
	{
	}
}

void Task1_Func(TimerHandle_t xTimers)
{
	TickType_t xLastWakeTime;
	const TickType_t xPeriod = pdMS_TO_TICKS(10);
	xLastWakeTime = xTaskGetTickCount();
	// while (1)
	// {
	PORTC ^= (1u << 3);
	// delay
	// for (int i = 0; i < 1000; i++){}
	vTaskDelay(5);
	// pdMS_TO_TICKS( 20 )
	// PORTC ^= (1u<<5);
	// vTaskDelayUntil(&xLastWakeTime, xPeriod);
	// stop timer
	// xTimerStop(xTimers, 0);
	// }
}

void Task2_Func(TimerHandle_t xTimers)
{
	/*    */
	TickType_t xLastWakeTime;
	const TickType_t xPeriod = pdMS_TO_TICKS(20);
	xLastWakeTime = xTaskGetTickCount();

	// while (1)
	// {
	// 	PORTC ^= (1u << 3);
	// 	vTaskDelayUntil(&xLastWakeTime, xPeriod);
	// }
	// while (1)
	// {
	PORTC ^= (1u << 4);
	vTaskDelay(10); // pdMS_TO_TICKS( 20 )
					//  PORTC ^= (1u<<5);
					// vTaskDelayUntil(&xLastWakeTime, xPeriod);
					// }
}

void Task3_Func(TimerHandle_t xTimers)
{
	TickType_t xLastWakeTime;
	const TickType_t xPeriod = pdMS_TO_TICKS(30);
	xLastWakeTime = xTaskGetTickCount();

	// while (1)
	// {
	PORTC ^= (1u << 5);
	vTaskDelay(15); // pdMS_TO_TICKS( 20 )
					// vTaskDelayUntil(&xLastWakeTime, xPeriod);
					//  }
}
