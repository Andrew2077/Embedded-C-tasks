/*
 * SPI.h
 *
 * Created: 12/18/2022 12:40:09 AM
 *  Author: DELL
 */

#ifndef SPI_H_
#define SPI_H_

void masterInit(void);
void masterTransmit(char spiData);
char masterReceive(void);

#endif /* SPI_H_ */