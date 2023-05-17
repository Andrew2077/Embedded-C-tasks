#ifndef DIO_DRIVER_H_
#define DIO_DRIVER_H_

#define INPUT 0
typedef unsigned char u8;

void DIO_vSetPinDir (u8 PortName , u8 PinNumber , u8 Dir );
void DIO_vWritePin (u8 PortName , u8 PinNumber , u8 val);
u8 DIO_vReadPin (u8 PortName , u8 PinNumber);
void DIO_vToggle (u8 PortName , u8 PinNumber);
#endif
/* DIO_DRIVER_H_ */
