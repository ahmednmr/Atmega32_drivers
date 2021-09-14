/*
 * DIO.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nmr
 */

#include "DIO.h"



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
 			DIO_Init_Pin(GPIO_D,7);

 ***********************************************/

void DIO_Init_Pin(U8 port ,U8 pin ,U8 direction)
{

	switch(port)
	{
	case PORT_A:

		if(direction==OUTPUT)
			SET_BIT(DDRA,pin);
		else if(direction==INPUT)
			CLEAR_BIT(DDRA,pin);

		break;

	case PORT_B:

		if(direction==OUTPUT)
			SET_BIT(DDRB,pin);
		else if(direction==INPUT)
			CLEAR_BIT(DDRB,pin);

		break;

	case PORT_C:

		if(direction==OUTPUT)
			SET_BIT(DDRC,pin);
		else if(direction==INPUT)
			CLEAR_BIT(DDRC,pin);

		break;

	case PORT_D:

		if(direction==OUTPUT)
			SET_BIT(DDRD,pin);
		else if(direction==INPUT)
			CLEAR_BIT(DDRD,pin);

		break;
	}

}



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

void DIO_Set_Pin(U8 port ,U8 pin)
{

	switch(port)
	{
	case PORT_A:
		SET_BIT(PORTA,pin);
		break;

	case PORT_B:
		SET_BIT(PORTB,pin);
		break;

	case PORT_C:
		SET_BIT(PORTC,pin);

		break;

	case PORT_D:
		SET_BIT(PORTD,pin);
		break;
	}

}





void DIO_Toggel_Pin(U8 port ,U8 pin)
{

	switch(port)
	{
	case PORT_A:
		TOG_BIT(PORTA,pin);
		break;

	case PORT_B:
		TOG_BIT(PORTB,pin);
		break;

	case PORT_C:
		TOG_BIT(PORTC,pin);

		break;

	case PORT_D:
		TOG_BIT(PORTD,pin);

	}
}


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

void DIO_Clear_Pin(U8 port ,U8 pin)
{

	switch(port)
	{
	case PORT_A:
		CLEAR_BIT(PORTA,pin);
		break;

	case PORT_B:
		CLEAR_BIT(PORTB,pin);
		break;

	case PORT_C:
		CLEAR_BIT(PORTC,pin);

		break;

	case PORT_D:
		CLEAR_BIT(PORTD,pin);
		break;
	}

}


void DIO_Write_Pin(U8 port ,U8 pin, U8 value)
{

	if(value==HIGH)
		DIO_Set_Pin(port,pin);

	else if(value==LOW)
		DIO_Clear_Pin(port,pin);




}

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

U8 DIO_Get_Pin(U8 port ,U8 pin)
{
	U8 pin_value=0;

	switch(port)
	{
	case PORT_A:
		pin_value=GET_BIT(PINA,pin);
		break;

	case PORT_B:
		pin_value=GET_BIT(PINB,pin);
		break;

	case PORT_C:
		pin_value=GET_BIT(PINC,pin);

		break;

	case PORT_D:
		pin_value=GET_BIT(PIND,pin);
		break;
	}


	return pin_value;
}







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

void DIO_Init_PORT(U8 port ,U8 Data)
{

	switch(port)
	{
	case PORT_A:

		DDRA=Data;

		break;

	case PORT_B:

		DDRB=Data;
		break;

	case PORT_C:

		DDRC=Data;
		break;

	case PORT_D:

		DDRD=Data;
		break;
	}

}



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

void DIO_Write_PORT_Value(U8 port ,U8 value)
{

	switch(port)
	{
	case PORT_A:

		PORTA=value;

		break;

	case PORT_B:

		PORTB=value;
		break;

	case PORT_C:

		PORTC=value;
		break;

	case PORT_D:

		PORTD=value;
		break;
	}

}

