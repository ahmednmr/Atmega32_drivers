/*
 * leds.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nmr
 */
#include"led.h"


void Led_Init(LED_en_leds LedSelected)
{

	switch(LedSelected)
	{
	case First_LED:
		DIO_Init_Pin(First_LED_Port,First_LED,OUTPUT);
		break;
	case Second_LED:
		DIO_Init_Pin(Second_LED_Port,Second_LED,OUTPUT);
		break;
	case Third_LED:
		DIO_Init_Pin(Third_LED_Port,Third_LED,OUTPUT);
		break;
	case Forth_LED:
		DIO_Init_Pin(Forth_LED_Port,Forth_LED,OUTPUT);
		break;

	}

}
void Led_ON(LED_en_leds LedSelected)
{
	switch(LedSelected)
	{
	case First_LED:
		DIO_Set_Pin(First_LED_Port,First_LED);
		break;
	case Second_LED:
		DIO_Set_Pin(Second_LED_Port,Second_LED);
		break;
	case Third_LED:
		DIO_Set_Pin(Third_LED_Port,Third_LED);
		break;
	case Forth_LED:
		DIO_Set_Pin(Forth_LED_Port,Forth_LED);
		break;

	}

}
void Led_OFF(LED_en_leds LedSelected)
{

	switch(LedSelected)
	{
	case First_LED:
		DIO_Clear_Pin(First_LED_Port,First_LED);
		break;
	case Second_LED:
		DIO_Clear_Pin(Second_LED_Port,Second_LED);
		break;
	case Third_LED:
		DIO_Clear_Pin(Third_LED_Port,Third_LED);
		break;
	case Forth_LED:
		DIO_Clear_Pin(Forth_LED_Port,Forth_LED);
		break;

	}

}
void Led_Toggel(LED_en_leds LedSelected)
{


	switch(LedSelected)
	{
	case First_LED:
		DIO_Toggel_Pin(First_LED_Port,First_LED);
		break;
	case Second_LED:
		DIO_Toggel_Pin(Second_LED_Port,Second_LED);
		break;
	case Third_LED:
		DIO_Toggel_Pin(Third_LED_Port,Third_LED);
		break;
	case Forth_LED:
		DIO_Toggel_Pin(Forth_LED_Port,Forth_LED);
		break;

	}
}
