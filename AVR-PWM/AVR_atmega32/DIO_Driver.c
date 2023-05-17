#include <avr/io.h>
#include "DIO_Driver.h"

void DIO_vSetPinDir (u8 PortName , u8 PinNumber , u8 Dir );
void DIO_vWritePin (u8 PortName , u8 PinNumber , u8 val);
u8 DIO_vReadPin (u8 PortName , u8 PinNumber);
void DIO_vToggle (u8 PortName , u8 PinNumber);

void DIO_vSetPinDir (u8 PortName , u8 PinNumber , u8 Dir ){
	
	switch(PortName){
		case (u8) 'A':
            if ((u8) 1==Dir){
                DDRA |= (u8)( ((u8)1) << PinNumber);
            }
            else{
                DDRA &= (u8) (~((u8)(((u8)1)<<PinNumber)));
            }
            break;
		
		
		case (u8) 'B':
            if ((u8) 1==Dir){
                DDRB |= (u8)( ((u8)1) << PinNumber);
            }
            else{
                DDRB &=(u8) (~((u8)(((u8)1)<<PinNumber)));
            }
            break;
		
		
		case (u8) 'C':
            if ((u8) 1==Dir){
                DDRC |= (u8)( ((u8)1) << PinNumber);
            }
            else{
                DDRC &=(u8) (~((u8)(((u8)1)<<PinNumber)));
            }
            break;
		
		
		case (u8)'D':
            if ((u8) 1==Dir){
                DDRD |= (u8)( ((u8)1) << PinNumber);
            }
            else{
                DDRD &=(u8) (~((u8)(((u8)1)<<PinNumber)));
            }
            break;
		default :
		    if ((u8) 1==Dir){
                DDRA |= (u8)( ((u8)1) << PinNumber);
            }
            else{
                DDRA &=(u8) (~((u8)(((u8)1)<<PinNumber)));
            }
            break;
	}
	
	
}



void DIO_vWritePin (u8 PortName , u8 PinNumber , u8 val){
	switch(PortName){
		case (u8)'A':
		if ((u8)1==val){
			PORTA |=(u8)( ((u8)1) << PinNumber);
		}
		else {
			PORTA &=(u8) (~((u8)(((u8)1)<<PinNumber)));
		}
		break;
		
		case (u8)'B':
		if ((u8)1==val){
			PORTB |=(u8)( ((u8)1) << PinNumber);
		}
		else {
			PORTB &=(u8) (~((u8)(((u8)1)<<PinNumber)));
		}
		break;
		
		case (u8)'C':
		if ((u8)1==val){
			PORTC |=(u8)( ((u8)1) << PinNumber);
		}
		else {
			PORTC &=(u8) (~((u8)(((u8)1)<<PinNumber)));
		}
		break;
		
			
		case (u8)'D':
		if ((u8)1==val){
			PORTD |=(u8)( ((u8)1) << PinNumber);
		}
		else {
			PORTD &=(u8) (~((u8)(((u8)1)<<PinNumber)));
		}
		break;

		default:
		    if ((u8)1==val){
                PORTA |=(u8)( ((u8)1) << PinNumber);
            }
            else {
                PORTA &=(u8) (~((u8)(((u8)1)<<PinNumber)));
            }
            break;

	}
	
}



u8 DIO_vReadPin (u8 PortName , u8 PinNumber){
	u8 val= (u8) 0;
	
	switch(PortName){
		case (u8)'A':
		val=(PINA & (u8)( ((u8)1) << PinNumber))>>PinNumber;
		break;
		case (u8)'B':
		val=(PINB & (u8)( ((u8)1) << PinNumber) )>>PinNumber;
		break;		
		case (u8)'C':
		val=(PINC & (u8)( ((u8)1) << PinNumber) )>>PinNumber;
		break;	
		case (u8)'D':
		val=(PIND & (u8)( ((u8)1) << PinNumber) )>>PinNumber;
		break;	
		default:
		    val=(PINA & (u8)( ((u8)1) << PinNumber) )>>PinNumber;
		    break;
	}		
	return val;
}





void DIO_vToggle (u8 PortName , u8 PinNumber){
		
	switch(PortName){
		case (u8)'A':
		(PORTA^=(u8)(((u8)1)<<PinNumber));
		break;
		case (u8)'B':
		(PORTB^=(u8)(((u8)1)<<PinNumber));
		break;
		case (u8)'C':
		(PORTC^=(u8)(((u8)1)<<PinNumber));
		break;
		case (u8)'D':
		(PORTD^=(u8)(((u8)1)<<PinNumber));
		break;
		default:
        (PORTA^=(u8)(((u8)1)<<PinNumber));
        break;
	}
}
