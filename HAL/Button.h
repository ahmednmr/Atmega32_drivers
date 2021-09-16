/*
 * Button.h
 *
 *  Created on: Sep 14, 2021
 *      Author: Embeddfab
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "../Helpers/STD_TYPES.h"
#include "../Helpers/Utils.h"
#include "../MCAL/DIO.h"


#define BUTTON1_PORT PORT_D
#define BUTTON2_PORT PORT_D

#define DEBOUNCING_DELAY _delay_ms(40)

typedef enum
{
	BUTTON1_PIN=PIN_2,
    BUTTON2_PIN=PIN_3
}button_number_en;

typedef enum
{
	Button_Default=0,
	Button_Pull_up
}button_Pull_type_en;


void Button_Init(button_number_en button_select,button_Pull_type_en pull_type);
bool Button_read_status(button_number_en button_select);


#endif /* BUTTON_H_ */
