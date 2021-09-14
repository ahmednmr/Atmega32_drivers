/*
 * EXT_INT.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nmr
 */
#include"EXT_INT.h"

static void (*PTR_Fun_INT0_PD2)(void);
static void (*PTR_Fun_INT1_PD3)(void);
static void (*PTR_Fun_INT2_PB2)(void);

//PD2 Pd3 PB2

static void EXT_interrupt_init_INT0_PD2(EXT_interrupt_st* obj)
{
	PTR_Fun_INT0_PD2=obj->InterruptFunctionPtr;
	SET_BIT(GICR,6);


	switch(obj->InterruptSelect)
	{
	case EXT_LOW_LEVEL:
		CLEAR_BIT(MCUCR,0);
		CLEAR_BIT(MCUCR,1);
		break;
	case EXT_ANY_LOGICAL_CHANGE:
		SET_BIT(MCUCR,0);
		CLEAR_BIT(MCUCR,1);
		break;

	case EXT_FALLING_EDGE:
		CLEAR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
		break;

	case EXT_RISING_EDGE:
		SET_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
		break;

	}
}


static void EXT_interrupt_init_INT1_PD3(EXT_interrupt_st* obj)
{
	PTR_Fun_INT1_PD3=obj->InterruptFunctionPtr;
	SET_BIT(GICR,7);


	switch(obj->InterruptSelect)
	{
	case EXT_LOW_LEVEL:
		CLEAR_BIT(MCUCR,2);
		CLEAR_BIT(MCUCR,3);
		break;
	case EXT_ANY_LOGICAL_CHANGE:
		SET_BIT(MCUCR,2);
		CLEAR_BIT(MCUCR,3);
		break;

	case EXT_FALLING_EDGE:
		CLEAR_BIT(MCUCR,2);
		SET_BIT(MCUCR,3);
		break;

	case EXT_RISING_EDGE:
		SET_BIT(MCUCR,2);
		SET_BIT(MCUCR,3);
		break;

	}
}


static void EXT_interrupt_init_INT2_PB2(EXT_interrupt_st* obj)
{
	PTR_Fun_INT2_PB2=obj->InterruptFunctionPtr;
	SET_BIT(GICR,5);


	switch(obj->InterruptSelect)
	{

	case EXT_FALLING_EDGE:
		CLEAR_BIT(MCUCR,6);
		break;

	case EXT_RISING_EDGE:
		SET_BIT(MCUCSR,6);
		break;

	}
}



void EXT_interrupt_init(EXT_interrupt_st* obj)
{
	switch(obj->InterruptSelect)
	{
	case EXT_INTERRPUT_INT0_PD2:
		EXT_interrupt_init_INT0_PD2(obj);
		break;
	case EXT_INTERRPUT_INT1_PD3:
		EXT_interrupt_init_INT1_PD3(obj);
		break;

	case EXT_INTERRPUT_INT3_PB2:
		EXT_interrupt_init_INT2_PB2(obj);
		break;
	}



}




void EXT_interrupt_SetTriggerEdge(EXT_Interrupt_pin_en Interrupt_pin,EXT_Interrupt_SenseControl_en InterruptSenseControl)
{


	if(Interrupt_pin==EXT_INTERRPUT_INT0_PD2)
	{
		switch(InterruptSenseControl)
		{
		case EXT_LOW_LEVEL:
			CLEAR_BIT(MCUCR,0);
			CLEAR_BIT(MCUCR,1);
			break;
		case EXT_ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR,0);
			CLEAR_BIT(MCUCR,1);
			break;

		case EXT_FALLING_EDGE:
			CLEAR_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
			break;

		case EXT_RISING_EDGE:
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
			break;

		}


	}
	else if(Interrupt_pin==EXT_INTERRPUT_INT1_PD3)
	{

		switch(InterruptSenseControl)
		{
		case EXT_LOW_LEVEL:
			CLEAR_BIT(MCUCR,2);
			CLEAR_BIT(MCUCR,3);
			break;
		case EXT_ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR,2);
			CLEAR_BIT(MCUCR,3);
			break;

		case EXT_FALLING_EDGE:
			CLEAR_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
			break;

		case EXT_RISING_EDGE:
			SET_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
			break;

		}

	}
	else if(Interrupt_pin==EXT_INTERRPUT_INT3_PB2)
	{

		switch(InterruptSenseControl)
		{

		case EXT_FALLING_EDGE:
			CLEAR_BIT(MCUCR,6);
			break;

		case EXT_RISING_EDGE:
			SET_BIT(MCUCSR,6);
			break;

		}

	}


}

void EXT_interrupt_Enable(EXT_Interrupt_pin_en Interrupt_pin)
{
	switch(Interrupt_pin)
	{
	case EXT_INTERRPUT_INT0_PD2:
		SET_BIT(GICR,6);
		break;
	case EXT_INTERRPUT_INT1_PD3:
		SET_BIT(GICR,7);
		break;

	case EXT_INTERRPUT_INT3_PB2:
		SET_BIT(GICR,5);
		break;
	}



}

void EXT_interrupt_Disable(EXT_Interrupt_pin_en Interrupt_pin)
{
	switch(Interrupt_pin)
	{
	case EXT_INTERRPUT_INT0_PD2:
		CLEAR_BIT(GICR,6);
		break;
	case EXT_INTERRPUT_INT1_PD3:
		CLEAR_BIT(GICR,7);
		break;

	case EXT_INTERRPUT_INT3_PB2:
		CLEAR_BIT(GICR,5);
		break;
	}



}




//...............
ISR(INT0_vect){
	PTR_Fun_INT0_PD2();
}
//-------------------------------------
ISR(INT1_vect){
	PTR_Fun_INT1_PD3();
}
//-----------------------------------
ISR(INT2_vect){
	PTR_Fun_INT2_PB2();
}

