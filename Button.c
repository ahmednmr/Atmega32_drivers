/*
 * Button.c
 *
 *  Created on: Sep 14, 2021
 *      Author: Embeddfab
 */
#include"Button.h"



void Button_Init(button_number_en button_select,button_Pull_type_en pull_type)
{

	if(button_select==BUTTON1_PIN)
	{
		DIO_Init_Pin(BUTTON1_PORT,BUTTON1_PIN,INPUT);
		if(pull_type==Button_Pull_up)
		{
			DIO_Set_Pin(BUTTON1_PORT,BUTTON1_PIN);
		}

	}

	else if(button_select==BUTTON2_PIN)
	{
		DIO_Init_Pin(BUTTON2_PORT,BUTTON2_PIN,INPUT);
		if(pull_type==Button_Pull_up)
		{
			DIO_Set_Pin(BUTTON2_PORT,BUTTON2_PIN);
		}

	}



}


bool Button_read_status(button_number_en button_select)
{
	bool button_status=FALSE;

	if(button_select==BUTTON1_PIN)
	{
		button_status=DIO_Get_Pin(BUTTON1_PORT,BUTTON1_PIN);
		DEBOUNCING_DELAY;

	}

	else if(button_select==BUTTON2_PIN)
	{
		button_status=DIO_Get_Pin(BUTTON2_PORT,BUTTON2_PIN);
		DEBOUNCING_DELAY;
	}

	return(button_status);

}
