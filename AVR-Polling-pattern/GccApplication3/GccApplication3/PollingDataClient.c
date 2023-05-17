/*
 * PollDataClient.c
 *
 *  Created on: Mar 31, 2022
 *      Author: moham
 */
#include "PWM.h"
#include "PollingDataClient.h"

#define F_CPU 1000000

#define KP 0.1f
#define KI 0.01f
float integral = 0;

int HANDLE_DATA(int temp)
{
	int C_temp = temp;
	int T_temp = 30;

	// if (C_temp < T_temp)
	// {
	// 	//return temp;
	// 	//return 5;
	// }
	int error = (C_temp - T_temp);
	integral = integral + error;
	int PWM_signal = (KP * error) + (KI * integral);
	if (PWM_signal > (255 * 0.73))
	{
		PWM_signal = (255 * 0.73);
	}
	else if (PWM_signal < 0)
	{
		PWM_signal = 0;
	}
	C_temp = C_temp - PWM_signal;
	return C_temp;
	
}