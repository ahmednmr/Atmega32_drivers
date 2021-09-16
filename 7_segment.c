/*
 * 7_segment.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nmr
 */

#include "7_segment.h"


void segment_init(en_segment seg_number)
{


	DIO_Init_Pin(SEG1_PORT ,SEG1_PIN ,OUTPUT);
	DIO_Init_Pin(SEG2_PORT ,SEG2_PIN ,OUTPUT);
	DIO_Init_Pin(SEG3_PORT ,SEG3_PIN ,OUTPUT);
	DIO_Init_Pin(SEG4_PORT ,SEG4_PIN ,OUTPUT);

	switch(seg_number)
	{
	case seg1:
		DIO_Init_Pin(SEG_EN1_PORT ,SEG1_EN_PIN ,OUTPUT);
		break;

	case seg2:
		DIO_Init_Pin(SEG_EN2_PORT ,SEG2_EN_PIN ,OUTPUT);
		break;


	case seg3:
		DIO_Init_Pin(SEG_EN3_PORT ,SEG3_EN_PIN ,OUTPUT);
		break;


	case seg4:
		DIO_Init_Pin(SEG_EN4_PORT ,SEG4_EN_PIN ,OUTPUT);
		break;




	}






}
void segment_write(en_segment seg_number, U8 data)
{

	DIO_Write_Pin( SEG1_PORT,SEG1_PIN, GET_BIT(data,0) );
	DIO_Write_Pin( SEG2_PORT,SEG2_PIN, GET_BIT(data,1) );
	DIO_Write_Pin( SEG3_PORT,SEG3_PIN, GET_BIT(data,2) );
	DIO_Write_Pin( SEG4_PORT,SEG4_PIN, GET_BIT(data,3) );



	DIO_Write_Pin( SEG_EN1_PORT,SEG1_EN_PIN, HIGH );
	DIO_Write_Pin( SEG_EN2_PORT,SEG2_EN_PIN, HIGH);
	DIO_Write_Pin( SEG_EN3_PORT,SEG3_EN_PIN, HIGH );
	DIO_Write_Pin( SEG_EN4_PORT,SEG4_EN_PIN, HIGH );

	switch(seg_number)
	{
	case seg1:
		DIO_Write_Pin( SEG_EN1_PORT,SEG1_EN_PIN, LOW );
		break;

	case seg2:
		DIO_Write_Pin(SEG_EN2_PORT ,SEG2_EN_PIN ,LOW);
		break;


	case seg3:
		DIO_Write_Pin(SEG_EN3_PORT ,SEG3_EN_PIN ,LOW);
		break;


	case seg4:
		DIO_Write_Pin(SEG_EN4_PORT ,SEG4_EN_PIN ,LOW);
		break;




	}




}
//void segment_Deinit(en_segment seg_number);
