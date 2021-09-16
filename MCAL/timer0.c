/*
 * timer.c
 *
 *  Created on: Sep 16, 2021
 *      Author: Embeddfab
 */
#include"timer0.h"


void (*timer0_OVF_callback_fun)(void);
void (*timer0_Compare_matching_callback_fun)(void);

void timer0_init(timer0_struct_st * obj)
{

	switch(obj->timer0_mode)
	{
	case timer0_normal_mode:
		CLEAR_BIT(TCCR0,3);
		CLEAR_BIT(TCCR0,6);
		break;
	case timer0_PWM_PhaseCorrect_mode:
		CLEAR_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);
		break;

	case timer0_CTC_mode:
		SET_BIT(TCCR0,3);
		CLEAR_BIT(TCCR0,6);
		break;

	case timer0_fast_pwm_mode:
		SET_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);
		break;

	}


	switch(obj->timer0_prescaler)
	{
	case TIMER0_PRESCALER_DISABLE:
		CLEAR_BIT(TCCR0,0);
		CLEAR_BIT(TCCR0,1);
		CLEAR_BIT(TCCR0,2);
		break;
	case TIMER0_PRESCALER_1:
		SET_BIT(TCCR0,0);
		CLEAR_BIT(TCCR0,1);
		CLEAR_BIT(TCCR0,2);
		break;
	case TIMER0_PRESCALER_8:
		CLEAR_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		CLEAR_BIT(TCCR0,2);
		break;
	case TIMER0_PRESCALER_64:
		SET_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		CLEAR_BIT(TCCR0,2);
		break;
	case TIMER0_PRESCALER_256:
		CLEAR_BIT(TCCR0,0);
		CLEAR_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
		break;
	case TIMER0_PRESCALER_1024:
		SET_BIT(TCCR0,0);
		CLEAR_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
		break;
	case TIMER0_EXTERNAL_CLOCK_SOURCE_FALLING_EDGE:
		CLEAR_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
		break;
	case TIMER0_EXTERNAL_CLOCK_SOURCE_RISING_EDGE:
		SET_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
		break;
	}

	switch(obj->timer0_oc0_action)
	{
	case TIMER0_OC0_DISCONNECT:
		CLEAR_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);
		break;
	case TIMER0_OC0_TOGGLE:
		CLEAR_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);
		break;

	case TIMER0_OC0_CLEAR:
		SET_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);
		break;

	case TIMER0_OC0_SET:
		SET_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);
		break;

	}



}




void TIMER0_overflow_interrupt_enable(void (*callback_fun)(void))
{
	timer0_OVF_callback_fun=callback_fun;
	SET_BIT(TIMSK,0);

}
void TIMER0_overflow_interrupt_disable()
{
	CLEAR_BIT(TIMSK,0);
}

void TIMER0_matching_interrupt_enable(void (*callback_fun)(void))
{
	timer0_Compare_matching_callback_fun=callback_fun;
	SET_BIT(TIMSK,1);

}
void TIMER0_matching_interrupt_disable()
{
	CLEAR_BIT(TIMSK,1);
}



void TIMER0_count_from(U8 start_value)
{
	WRITE_PORT(TCNT0,start_value);

}
void TIMER0_compare_value(U8 compare_value)
{
	WRITE_PORT(OCR0,compare_value);

}




ISR(TIMER0_OVF_vect)
{
	timer0_OVF_callback_fun();
}

ISR(TIMER0_COMP_vect)
{
	timer0_OVF_callback_fun();
}
