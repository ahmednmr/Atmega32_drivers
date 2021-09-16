/*
 * timer.h
 *
 *  Created on: Sep 16, 2021
 *      Author: Embeddfab
 */

#ifndef TIMER0_H_
#define TIMER0_H_

#include <avr/interrupt.h>
#include "../Helpers/STD_TYPES.h"
#include "../Helpers/Utils.h"
#include "DIO.h"


typedef enum
{
	timer0_normal_mode=1,
	timer0_PWM_PhaseCorrect_mode,
	timer0_CTC_mode,
	timer0_fast_pwm_mode
}timer0_mode_en;


typedef enum
{

	TIMER0_PRESCALER_DISABLE =        1,
	TIMER0_PRESCALER_1 				   ,
	TIMER0_PRESCALER_8 				   ,
	TIMER0_PRESCALER_64 			   ,
	TIMER0_PRESCALER_256 			   ,
	TIMER0_PRESCALER_1024 			   ,
	TIMER0_EXTERNAL_CLOCK_SOURCE_FALLING_EDGE ,
	TIMER0_EXTERNAL_CLOCK_SOURCE_RISING_EDGE  ,

}timer0_prescaler_en;

typedef enum
{
	TIMER0_OC0_DISCONNECT =			  1,
	TIMER0_OC0_TOGGLE				   ,
	TIMER0_OC0_CLEAR				   ,
	TIMER0_OC0_SET					   ,

}timer0_oc0_acion_en;

typedef struct
{
	timer0_mode_en timer0_mode;
	timer0_prescaler_en timer0_prescaler;
	timer0_oc0_acion_en timer0_oc0_action;


}timer0_struct_st;




void timer0_init(timer0_struct_st * obj);
void TIMER0_overflow_interrupt_enable(void (*callback_fun)(void));
void TIMER0_overflow_interrupt_disable();
void TIMER0_matching_interrupt_enable(void (*callback_fun)(void));
void TIMER0_matching_interrupt_disable();
void TIMER0_count_from(U8 start_value);
void TIMER0_compare_value(U8 compare_value);

#endif /* TIMER0_H_ */
