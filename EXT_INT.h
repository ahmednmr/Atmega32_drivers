/*
 * EXT_INT.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nmr
 */

#ifndef EXT_INT_H_
#define EXT_INT_H_
#include <avr/interrupt.h>
#include "DIO.h"

typedef enum {
EXT_INTERRPUT_INT0_PD2=1,
EXT_INTERRPUT_INT1_PD3,
EXT_INTERRPUT_INT3_PB2
}EXT_Interrupt_pin_en;

typedef enum {
EXT_LOW_LEVEL              =1,
EXT_ANY_LOGICAL_CHANGE          ,
EXT_FALLING_EDGE               ,
EXT_RISING_EDGE
}EXT_Interrupt_SenseControl_en;


typedef struct {
	EXT_Interrupt_pin_en InterruptSelect;
	EXT_Interrupt_SenseControl_en InterruSenseControl;
	void (*InterruptFunctionPtr)(void);
}EXT_interrupt_st;


void EXT_interrupt_init(EXT_interrupt_st *obj);
void EXT_interrupt_Enable(EXT_Interrupt_pin_en Interrupt_pin);
void EXT_interrupt_Disable(EXT_Interrupt_pin_en Interrupt_pin);
void EXT_interrupt_SetTriggerEdge(EXT_Interrupt_pin_en Interrupt_pin,EXT_Interrupt_SenseControl_en InterruptSenseControl);


#endif /* EXT_INT_H_ */
