/*
 * lcd.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nmr
 */

#ifndef LCD_H_
#define LCD_H_

#include "STD_TYPES.h"
#include "Utils.h"
#include "DIO.h"


#define LCD_PORT			PORT_B // data wires on portA
#define LCD_PORT_CONTROL	PORT_C // RS RW EN portB

#define D0
#define D1
#define D2
#define D3
#define D4  PIN_4
#define D5  PIN_5
#define D6  PIN_6
#define D7  PIN_7

#define RS  PIN_6
#define RW
#define EN  PIN_7


void LCD_VidInit(void);
void LCD_vidSendCommand(unsigned char command);
void LCD_vidsendData(unsigned char character);
void LCD_vidsendword(char * word);
void LCD_sendNumber(U32 num);
void LCD_vidClear(void);
void LCD_vid_Save_in_CGRAM(void);
void LCD_vidGoTo(unsigned char col,unsigned char Row);


#endif /* LCD_H_ */
