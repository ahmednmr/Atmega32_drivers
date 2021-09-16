/*
 * buzzer.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nmr
 */

#include"buzzer.h"



void Buzzer_Init(void)
{

	DIO_Init_Pin(BUZZER_PORT,BUZZER_PIN,OUTPUT);

}
void Buzzer_ON(void)
{
	DIO_Set_Pin(BUZZER_PORT,BUZZER_PIN);

}
void Buzzer_OFF(void)
{
	DIO_Clear_Pin(BUZZER_PORT,BUZZER_PIN);

}
void Buzzer_Toggel(U8 iterations,U16 delay_time_ms)
{

	for(U8 i=0;i<iterations*2;i++)
	{
		DIO_Toggel_Pin(BUZZER_PORT,BUZZER_PIN);
		_delay_ms(delay_time_ms);
	}
}
