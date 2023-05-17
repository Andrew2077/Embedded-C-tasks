#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

/* Required 3 tasks each one toggles a led with diff speed*/
/*add timer config to freertosconfiq */

// Function prototypes.
// fcpu clock speed for atmega32

#define F_CPU 1000000

void Task1_Func(void);
// TaskHandle_t is a typedef for a pointer to a TCB (task control block).
TaskHandle_t task1ptr;

void Task2_Func(void);
TaskHandle_t task2ptr;

void Task3_Func(void);
TaskHandle_t task3ptr;

int main(void)
{

	DDRC = 0xFF; // Configure all PORTC pins as output pins

	// TimerHandle_t xTimer = xTimerCreate("timer1",10,pdTRUE,1,Task1_Func);
	// xTimerStart(xTimer, 10 );

	xTaskCreate(Task1_Func, "Task1", configMINIMAL_STACK_SIZE, NULL, 0, &task1ptr);
	xTaskCreate(Task2_Func, "Task2", configMINIMAL_STACK_SIZE, NULL, 0, &task2ptr);
	xTaskCreate(Task3_Func, "Task3", configMINIMAL_STACK_SIZE, NULL, 0, &task3ptr);
	// xTaskCreate(Task3_Func, "Task3", configMINIMAL_STACK_SIZE, NULL, 0, &task3ptr);

	vTaskStartScheduler();
	while(1)
	{

	}
}

void Task1_Func(void)
{
	TickType_t xLastWakeTime;
	const TickType_t xPeriod = pdMS_TO_TICKS( 20 );
	xLastWakeTime = xTaskGetTickCount();
	while (1)
	{
		PORTC ^= (1u<<3);
		//vTaskDelay( 20 );//pdMS_TO_TICKS( 20 )
		// PORTC ^= (1u<<5);
		vTaskDelayUntil( &xLastWakeTime, xPeriod );
	}
}

void Task2_Func(void)
{
	TickType_t xLastWakeTime;
	const TickType_t xPeriod = pdMS_TO_TICKS( 35 );
	xLastWakeTime = xTaskGetTickCount();

	// while (1)
	// {
	// 	PORTC ^= (1u << 3);
	// 	vTaskDelayUntil(&xLastWakeTime, xPeriod);
	// }
	while (1)
	{
		PORTC ^= (1u<<4);
		//vTaskDelay( 50 );//pdMS_TO_TICKS( 20 )
		// PORTC ^= (1u<<5);
		vTaskDelayUntil( &xLastWakeTime, xPeriod );
	}
}

void Task3_Func(void)
{
	TickType_t xLastWakeTime;
	const TickType_t xPeriod = pdMS_TO_TICKS( 60 );
	xLastWakeTime = xTaskGetTickCount();

	while (1)
	{
		PORTC ^= (1u<<5);
		//vTaskDelay( 70 );//pdMS_TO_TICKS( 20 )
		vTaskDelayUntil( &xLastWakeTime, xPeriod );
	}
}
