/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nmr
 */
#include "HAL/led.h"
#include "MCAL/timer0.h"

#define NUMBER_OF_COUNTS_FOR_1SECOND 62500
timer0_struct_st timer0_struct={timer0_normal_mode,TIMER0_PRESCALER_1,TIMER0_OC0_DISCONNECT};
volatile U32 counts_to_get_1Second=0;
volatile U64 Number_of_seconds=0;
void delay_1Second(void);

int main()
{


Led_Init(First_LED);
Led_Init(Second_LED);
Led_Init(Third_LED);
Led_Init(Forth_LED);
timer0_init(&timer0_struct);
TIMER0_overflow_interrupt_enable(delay_1Second);
sei();
//Led_ON(First_LED);

	while(1)
	{
		_delay_ms(1000);
			Led_Toggel(Second_LED);
//			Led_Toggel(Third_LED);
//			Led_Toggel(Forth_LED);


	}


	Led_OFF(Second_LED);
	Led_OFF(Third_LED);
	Led_OFF(Forth_LED);

	return 0;
}

void delay_1Second(void)
{
counts_to_get_1Second++;
if(counts_to_get_1Second==NUMBER_OF_COUNTS_FOR_1SECOND)
{
counts_to_get_1Second=0;
Number_of_seconds++;
Led_Toggel(First_LED);
}


}
