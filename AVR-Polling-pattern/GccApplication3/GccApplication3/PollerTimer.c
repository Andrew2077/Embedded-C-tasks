/*
 * CFile2.c
 *
 * Created: 12/16/2022 12:03:01 PM
 *  Author: DELL
 */

#include <avr/io.h>
#include <avr/iom16.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "SPI.h"
#include "PollerTimer.h"
#include "poller.h"

void StartTimer(void)
{
	/*Clear timer counter*/
	TCNT1 = 0;
	/*Set compare value*/
	OCR1A = 391;
	/*Clear OC1A on compare match, set OC1A at BOTTOM (non-inverting mode)*/
	TCCR1A = (1 << FOC1A);
	/*FCPU/256
	 * number of clocks per 100ms is 390.6*/
	TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS11) | (1 << CS10);
}

void StopTimer(void)
{
	TCCR1B &= ~((1 << WGM12) | (1 << CS12) | (1 << CS11) | (1 << CS10));
}
void EnableInterrupt(void)
{
	// enable overflow interrupt
	// sei();
	// TIMSK |= (1 << TOIE1);
	/*Enable timer interrupt*/
	TIMSK |= (1 << OCIE1A);
	//sei();
	// Enable interrupts by setting I-bit
	SREG  |= (1<<7);
}

void DisableInterrupt(void)
{
	// enable overflow interrupt
	// TIMSK &=~ (1 << TOIE1);
	TIMSK &= ~(1 << OCIE1A);
}

void CallPollingFunction(void)
{
	Poll();
}
