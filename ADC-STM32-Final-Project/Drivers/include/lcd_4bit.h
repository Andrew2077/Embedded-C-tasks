/*
 * LCD-4bit.h
 *
 *  Created on: May 27, 2022
 *      Author: mohab
 */

#ifndef INC_LCD_4BIT_H_
#define INC_LCD_4BIT_H_

void HIGH_NIBBLE(unsigned char high_nibble,unsigned char cmd);
void LOW_NIBBLE(unsigned char low_nibble,unsigned char cmd);
void lcd_sendCommand(unsigned char cmd);
void lcd_displayChar(unsigned char data);
void lcd_init(void);
void lcd_gotoxy(unsigned char x , unsigned char y );
void lcd_clrScreen(void);
void lcd_dispString(char * ptr);
void lcd_disp_string_xy(char * ptr , int y , int x);




#endif /* INC_LCD_4BIT_H_ */
