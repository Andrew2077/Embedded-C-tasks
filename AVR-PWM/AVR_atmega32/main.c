#define F_CPU 10000000

#include <avr/io.h>
#include <util/delay.h>
#include "DIO_driver.h"
#include "PWM.h"


int main(void);

int main(void)
{
	INITIALZIE_PWM();
	uint8_t brightness=0;
	SET_PWM_OUTPUT(brightness);
	DIO_vSetPinDir( (u8)'B' ,(u8) 0 ,(u8) INPUT);
	
	while(1)
	{
		if( DIO_vReadPin((u8) 'B' ,(u8) 0))
		{
			if(brightness >= (uint8_t) 250)
			{
				brightness= (uint8_t) 0;
			}
			else 
			{
				brightness += (uint8_t) 25;
			}
			SET_PWM_OUTPUT(brightness);
			/* holds button untill it to be 0 */
			while(DIO_vReadPin( (u8) 'B', (u8) 0) ){};
		}
	}
}
