/*
 * lcdlib.h
 *
 *  Created on: ٢٤‏/٠٤‏/٢٠١٧
 *      Author: ENG.RAGAB
 */

#ifndef LCDLIB_H_
#define LCDLIB_H_





#include "libpic30.h"
#include "i2c.h"
#include"PLATFORM_CONFIGRATION.h"

#define RS 0
#define RW 1
#define E  2
#define FOUR_BITS_DATA_MODE 0x02
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80


void LCD_init();
void LCD_command(unsigned char command);
void LCD_Data(unsigned char data);
void LCD_displayString( unsigned char *str );
void LCD_displayCharacter(unsigned char Byte );
void LCD_goToRowCol(unsigned char row ,unsigned char col );
void LCD_intToString(int data);
void LCD_clearScreen(void);
void LCD_displayStringRowCol(unsigned char row , unsigned char col , unsigned char *str );



#endif /* LCDLIB_H_ */
