#include <avr/io.h>
#include <util/delay.h>
#include "SPI.h"
#include "PWM.h"
#include "PollerTimer.h"
#include "PollingDataClient.h"
#include "poller.h"
#include "HANDLER.h"
#include "TC72.h"
#include "sevenSeg.h"

//#define F_CPU 1000000


int main(void)
{
	
	DDRC = 0xFF;
	DDRD = 0xFF;
	DDRA = 0xFF;

	masterInit();
	tc72Init();

	PORTB |= (1 << 4);
	/*Read the MSB*/
	masterTransmit(0x02);
	/*Issue one more clock frame
	to force data out*/
	masterTransmit(0x00);
	PORTB &= ~(1 << 4);

	_delay_ms(1);
	msb = masterReceive();

	PORTB |= (1 << 4);
	/*Read The LSB*/
	masterTransmit(0x01);
	/*Issue one more clock frame
	to force data out*/
	masterTransmit(0x00);
	PORTB &= ~(1 << 4);

	_delay_ms(1);

	lsb = masterReceive();

	PORTB = lsb;

	displayTemperature(msb, lsb);

	X = (msb << 8) + lsb;

	_delay_ms(150);

	StartTimer();
	EnableInterrupt();
	SetPollingTime(2000);
	StartPolling();

	while (1)
	{
		INITIALZIE_PWM_TIMER(50);
		// X = HANDLE_DATA(X);
		// lsb = X;
		// msb = (X >> 8);
		//*idea that might wirk - load data into SPDR or any other register and then read it back out
		//  SPDR = (char)X;
		//  lsb = SPDR ; 
		//  SPDR =(char)(X>>8);
		//  msb = SPDR;
		// displayTemperature(msb, lsb);
		// X = (msb << 8) + lsb;
		Poll();
		//displayTemperature(msb, lsb);
	}
}
