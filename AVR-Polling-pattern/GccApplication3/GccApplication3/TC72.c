/*
 * TC72.c
 *
 * Created: 12/18/2022 12:40:26 AM
 *  Author: DELL
 */
#include <avr/io.h>
#include <util/delay.h>
#include "SPI.h"
#include "TC72.h"

void tc72Init(void)
{
    PORTB |= (1 << 4);
    /*Select Control Register*/
    masterTransmit(0x80);
    /*Select Continuous temperature Conversion*/
    masterTransmit(0x04);
    PORTB &= ~(1 << 4);
    _delay_ms(150);
}