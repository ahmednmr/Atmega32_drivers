/*
 * led.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nmr
 */

#ifndef LED_H_
#define LED_H_


#include "../Helpers/STD_TYPES.h"
#include "../Helpers/Utils.h"
#include "../MCAL/DIO.h"

#define First_LED_Port    PORT_D
#define Second_LED_Port   PORT_D
#define Third_LED_Port    PORT_D
#define Forth_LED_Port    PORT_D

typedef enum
{
	First_LED=PIN_7,
	Second_LED=PIN_6,
	Third_LED=PIN_5,
	Forth_LED=PIN_4,
}LED_en_leds;



void Led_Init(LED_en_leds LedSelected);
void Led_ON(LED_en_leds LedSelected);
void Led_OFF(LED_en_leds LedSelected);
void Led_Toggel(LED_en_leds LedSelected);

#endif /* LED_H_ */
