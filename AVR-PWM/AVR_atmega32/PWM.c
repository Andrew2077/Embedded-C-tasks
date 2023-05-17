#define F_CPU 1000000 /* ask */ 

/* include io header and delay functions header */ 

#include <avr/io.h>
#include <util/delay.h>

void INITIALZIE_PWM(void);
void SET_PWM_OUTPUT(uint8_t duty);


void INITIALZIE_PWM(void){
	/*
	Registers  :
	
	DDRB -> Data Direction Reg -- Datasheet p63
	TCCR0 -> Counter Control Reg -- Datasheet p77-80
	TCNT0 -> Counter Reg -- Datasheet p80
	
	Bits : 
	unit8_t -> 8-bit unsigned typed
	WGM1:0 -> Wave Form Generation Mode - Datasheet p78
			-= choosen mode : 11 - Fast PWM mode 
		00 - Nomral counter of operation
		01 - PMW , correct phase
		10 - Compare match mode
		11 - Fast PWM
		
	COM01:0 -> Compare Output mode - Datasheet p79
			-= choosen mode 10 , set on TOP
		OC0 -> output compare bin 
		00 - Normal port / OC0 is disconnected 
		01 - Reversed
		10 - Clear OC0 on compare , set OC0 at TOP
		11 - Set OC0 on comapre , clear OC0 at Top
		
	CS02:0 - clock select - preScaler -  datasheet p79-80
			-= 010 clk/8
	PB3 - Port B bin
		- AIN1 (analog comparator Negative input)
		- OC0 - output pin 
	
	function:
	1- Select Rising Up wave generation form
	2- set prescaler value
	
	*/ 
	
	/* configure TCCR0 reg -- TIMER 0
	/* TCCR0 = (1<<WGM00) | (1<<WGM01) |  (1<<COM01) | (1 <<CS01); */ 
	TCCR0 =(uint8_t) ((uint8_t) (((uint8_t)1)<<WGM00) |(uint8_t) (((uint8_t)1)<<WGM01) |(uint8_t) (((uint8_t)1)<<COM01) |(uint8_t) (((uint8_t)1)<<CS01) );
	/* Set direction of PB3 bin output*/ 
	DDRB |=(uint8_t) (((uint8_t)1)<<PB3);
	
	/* intialize 0 timer*/ 
	TCNT0 = (uint8_t) 0;	
}


void SET_PWM_OUTPUT(uint8_t duty){
	/*
	DataSheep p73, p80
	OCR0 - Output reg 
	
	function , choose Duty cycle and write on the OCR0 reg 
	*/
	
	OCR0 = (uint8_t)duty;
}