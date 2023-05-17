/* Define to prevent recursive inclusion */
#ifndef __INC_ADC_H_
#define __INC_ADC_H_

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
#include "stm32f4xx.h"
#include <stdlib.h>

#define USE_POLLING 1

struct ADCConfigType
{
	enum {res_6 = 0x03000000, res_8 = 0x02000000, res_10 = 0x01000000, res_12 = 0x00000000} Resolution;
	enum {Single = 0x0, Continues = 0x2} Mode;
	float Vref;
};

unsigned short int dataPtr;
unsigned char Ended_Conversion;
char displayText[16];
unsigned char Vref;
unsigned char notValid;
void ADC1_Config(void);
void ADC1_Main(void);
unsigned char ADC_ReadData(unsigned short int* DataPtr);
void ADC_Init(struct ADCConfigType* ADCConfigType);
void ADC_GetConversionState(unsigned char* ConversionStatePtr);
void ADC_StartConv(unsigned char ChannelNum);
void validity(void);

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif /*__INC_ADC_H_ */
