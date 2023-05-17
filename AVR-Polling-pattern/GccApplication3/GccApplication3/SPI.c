/*
 * SPI.c
 *
 * Created: 12/18/2022 12:37:48 AM
 *  Author: DELL
 */
#include <avr/io.h>
#include "SPI.h"

void masterInit(void)
{
	/*Set MOSI, SCK and SS Output*/
	DDRB = (1 << 7) | (1 << 5) | (1 << 4);
	/*Enable SPI Master set clock rate fck/128 data is
	sample at falling edge*/
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR1) | (1 << SPR0) | (1 << CPHA);
	// SPSR|=(1<<0);
}

void masterTransmit(char spiData)
{
	// PORTB&=~(1<<5);
	/*Start the transmission*/
	SPDR = spiData;
	/*Wait for completion*/
	while (!(SPSR & (1 << SPIF)))
		;
	// PORTB&=~(1<<5);
}

char masterReceive(void)
{
	/*Wait for the SPI buffer's full*/
	while (!(SPSR & (1 << SPIF)))
		;
	/*return SPI Buffer*/
	return SPDR;
}