/*
 * lcd.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nmr
 */

#include"lcd.h"

void LCD_VidInit(void)
{
	DIO_Init_Pin(LCD_PORT ,D4 ,OUTPUT);
	DIO_Init_Pin(LCD_PORT ,D5 ,OUTPUT);
	DIO_Init_Pin(LCD_PORT ,D6 ,OUTPUT);
	DIO_Init_Pin(LCD_PORT ,D7 ,OUTPUT);

	DIO_Init_Pin(LCD_PORT_CONTROL ,EN ,OUTPUT);
	DIO_Init_Pin(LCD_PORT_CONTROL ,RS ,OUTPUT);

	_delay_ms(50);          // said in Data sheet to delay after power on for 1st time
	LCD_vidSendCommand(0x02);//4 bit mode only
	_delay_ms(1);
	LCD_vidSendCommand(0x28); //N=1 , F=0
	_delay_ms(1);           //delay 1ms a must delay as said in Data sheet
	LCD_vidSendCommand(0x0c); //D=1(LCD itself on or off) C=0, B=0
	_delay_ms(1);    //delay 1ms
	LCD_vidSendCommand(0x01); //clear LCD
	_delay_ms(20);
	LCD_vidSendCommand(0x06);
	LCD_vidSendCommand(0x80);
}

void LCD_vidSendCommand(unsigned char command)
{

	//controls are low
	DIO_Write_Pin(LCD_PORT_CONTROL,RS,LOW);
	//data MSB write to lcd
	DIO_Write_Pin(LCD_PORT, D4, GET_BIT(command,4));
	DIO_Write_Pin(LCD_PORT, D5, GET_BIT(command,5));
	DIO_Write_Pin(LCD_PORT, D6, GET_BIT(command,6));
	DIO_Write_Pin(LCD_PORT, D7, GET_BIT(command,7));
	//pulse on enable
	DIO_Write_Pin(LCD_PORT_CONTROL,EN,HIGH);
	_delay_ms(2);
	DIO_Write_Pin(LCD_PORT_CONTROL,EN,LOW);
	_delay_ms(2);
	//write LSB command on pins
	DIO_Write_Pin(LCD_PORT,D4,GET_BIT(command,0));
	DIO_Write_Pin(LCD_PORT,D5,GET_BIT(command,1));
	DIO_Write_Pin(LCD_PORT,D6,GET_BIT(command,2));
	DIO_Write_Pin(LCD_PORT,D7,GET_BIT(command,3));
	//pulse on enable
	DIO_Write_Pin(LCD_PORT_CONTROL,EN,HIGH);
	_delay_ms(2);
	DIO_Write_Pin(LCD_PORT_CONTROL,EN,LOW);
	//wait to execute command
	_delay_ms(2);
	_delay_ms(10);



}


void LCD_vidsendData(unsigned char character)
{

	DIO_Write_Pin(LCD_PORT_CONTROL,RS,HIGH);

	DIO_Write_Pin(LCD_PORT,D4,GET_BIT(character,4));
	DIO_Write_Pin(LCD_PORT,D5,GET_BIT(character,5));
	DIO_Write_Pin(LCD_PORT,D6,GET_BIT(character,6));
	DIO_Write_Pin(LCD_PORT,D7,GET_BIT(character,7));
	DIO_Write_Pin(LCD_PORT_CONTROL,EN,HIGH);
	_delay_ms(2);
	DIO_Write_Pin(LCD_PORT_CONTROL,EN,LOW);
	_delay_ms(2);
	DIO_Write_Pin(LCD_PORT,D4,GET_BIT(character,0));
	DIO_Write_Pin(LCD_PORT,D5,GET_BIT(character,1));
	DIO_Write_Pin(LCD_PORT,D6,GET_BIT(character,2));
	DIO_Write_Pin(LCD_PORT,D7,GET_BIT(character,3));
	DIO_Write_Pin(LCD_PORT_CONTROL,EN,HIGH);
	_delay_ms(2);
	DIO_Write_Pin(LCD_PORT_CONTROL,EN,LOW);
	_delay_ms(2);


}

void LCD_vidsendword(char * word)
{
	while(*word!='\0')
	{
		LCD_vidsendData(*word);
		word++;

	}


}


void LCD_sendNumber(U32 num)
{
	char buffer[20];

	utoa(num,buffer,10);
	LCD_vidsendword(buffer);
}

void LCD_vidClear(void)
{
	LCD_vidSendCommand(0x01);
}



void LCD_vidGoTo(unsigned char col,unsigned char Row)
{
	if(col==0)
	{
		LCD_vidSendCommand(0b10000000|Row);
	}

	else if(col==1)
	{
		LCD_vidSendCommand(0b11000000|Row);

	}


}
