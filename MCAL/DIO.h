/*
 * DIO.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nmr
 */

#ifndef DIO_H_
#define DIO_H_

#include "../Helpers/STD_TYPES.h"
#include "../Helpers/Utils.h"
#include <avr/io.h>
#include <util/delay.h>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>

/*************Configuration Menu********/
#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

#define INPUT  0
#define OUTPUT 1

#define  PIN_0  0
#define  PIN_1  1
#define  PIN_2  2
#define  PIN_3  3
#define  PIN_4  4
#define  PIN_5  5
#define  PIN_6  6
#define  PIN_7  7


/***********************************************
* Name: DIO_Init_Pin(U8 port ,U8 pin ,U8 direction)

* INPUT:
   PORT:
        PORT_A
		PORT_B,
		PORT_C,
		PORT_D

   pin : 0:7
   direction : INPUT
               OUTPUT

* OUTPUT:   void

* DECS: function to make pin output or input

*  Example:
 			GPIO_initPin(GPIO_D,7,OUTPUT);

***********************************************/

void DIO_Init_Pin(U8 port ,U8 pin ,U8 direction);


/***********************************************
* Name: DIO_Set_Pin(U8 port ,U8 pin)

* INPUT:
   PORT:
        PORT_A
		PORT_B,
		PORT_C,
		PORT_D

   pin : 0:7

* OUTPUT:   void

* DECS: function to set pin Value

*  Example:
 			DIO_Set_Pin(DIO_D,7);

***********************************************/

void DIO_Set_Pin(U8 port ,U8 pin);

void DIO_Toggel_Pin(U8 port ,U8 pin);

void DIO_Write_Pin(U8 port ,U8 pin, U8 value);

/***********************************************
 * Name: DIO_Clear_Pin(U8 port ,U8 pin)

 * INPUT:
   PORT:
        PORT_A
		PORT_B,
		PORT_C,
		PORT_D

   pin : 0:7

 * OUTPUT:   void

 * DECS: function to clear pin value

 *  Example:
 			DIO_Clear_Pin(DIO_D,7);

 ***********************************************/

void DIO_Clear_Pin(U8 port ,U8 pin);


/***********************************************
 * Name: U8 DIO_Get_Pin(U8 port ,U8 pin)

 * INPUT:
   PORT:
        PORT_A
		PORT_B,
		PORT_C,
		PORT_D

   pin : 0:7

 * OUTPUT:   pin_value

 * DECS: function to Get pin value

 *  Example:
 			x= DIO_Get_Pin(PORT_C ,6);

 ***********************************************/

U8 DIO_Get_Pin(U8 port ,U8 pin);


/***********************************************
 * Name: DIO_Init_PORT(U8 port ,U8 Data);

 * INPUT:
   PORT:
        PORT_A
		PORT_B,
		PORT_C,
		PORT_D


   data  : 0bxxxxxxxx


 * OUTPUT:   void

 * DECS: function to define port direction

 *  Example:
 			DIO_Init_PORT(PORT_A,0b10100011);

 ***********************************************/

void DIO_Init_PORT(U8 port ,U8 Data);


/***********************************************
 * Name: DIO_Write_PORT_Value(U8 port ,U8 value)

 * INPUT:
   PORT:
        PORT_A
		PORT_B,
		PORT_C,
		PORT_D


   value  : 0bxxxxxxxx


 * OUTPUT:   void

 * DECS: function to write value to port

 *  Example:
 			DIO_Write_PORT_Value(PORT_A,0b10100011);

 ***********************************************/

void DIO_Write_PORT_Value(U8 port ,U8 value);


#endif /* DIO_H_ */
