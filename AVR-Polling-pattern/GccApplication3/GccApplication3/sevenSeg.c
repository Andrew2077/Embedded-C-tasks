/*
 * _7SEGMENTS.c
 *
 * Created: 12/18/2022 12:40:56 AM
 *  Author: DELL
 */
#include <avr/io.h>
#include <util/delay.h>
#include "sevenSeg.h"

void displayTemperature(char msb, char lsb)
{
    // ssd is an array of 16 elements, each element is a byte
    char ssd[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D,
                    0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

    // sign is a char variable
    char sign;

    lsb >>= 6;

    // if msb is negative
    if (msb & 0x80)
    {
        msb = (~msb) + 1;
        sign = 1;

        if (lsb != 0)
            lsb = 75 / lsb;
    }
    else
    {
        sign = 0;
        lsb *= 25;
    }

    PORTD = 0x00;
    if (sign == 1)
        PORTC = 0x40;
    else if (msb >= 100)
        PORTC = ssd[msb / 100];
    else
        PORTC = 0x00;
    PORTD = (1 << 0);
    _delay_ms(5);

    PORTD = 0x00;
    if (msb >= 10)
        PORTC = ssd[(msb % 100) / 10];
    else
        PORTC = 0;
    PORTD = (1 << 1);
    _delay_ms(5);

    PORTD = 0x00;
    PORTC = ssd[msb % 10] | 0x80;
    PORTD = (1 << 2);
    _delay_ms(5);

    PORTD = 0x00;
    PORTC = ssd[lsb / 10];
    PORTD = (1 << 3);
    _delay_ms(5);

    PORTD = 0x00;
    PORTC = ssd[lsb % 10];
    PORTD = (1 << 4);
    _delay_ms(5);

    PORTD = 0x00;
    PORTC = 0x63;
    PORTD = (1 << 5);
    _delay_ms(5);

    PORTD = 0x00;
    PORTC = ssd[12];
    PORTD = (1 << 6);
    _delay_ms(5);
}
