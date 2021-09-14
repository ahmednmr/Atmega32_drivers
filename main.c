/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nmr
 */
#include "led.h"
#include "Button.h"


int main()
{


	Led_Init(First_LED);
	Led_Init(Second_LED);
	Led_Init(Third_LED);
	Led_Init(Forth_LED);

	Button_Init(BUTTON1_PIN,Button_Default);


	while(1)
	{

		if(Button_read_status(BUTTON1_PIN))
		{
			while(Button_read_status(BUTTON1_PIN));
			Led_ON(First_LED);
			Led_Toggel(Second_LED);
			Led_Toggel(Third_LED);
			Led_Toggel(Forth_LED);
		}

	}
	_delay_ms(2000);

	Led_OFF(Second_LED);
	Led_OFF(Third_LED);
	Led_OFF(Forth_LED);

	return 0;
}

