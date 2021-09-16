/*
 * buzzer.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nmr
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "STD_TYPES.h"
#include "Utils.h"
#include "DIO.h"

#define BUZZER_PORT  PORT_D
#define BUZZER_PIN   PIN_7


void Buzzer_Init(void);
void Buzzer_ON(void);
void Buzzer_OFF(void);
void Buzzer_Toggel(U8 iterations,U16 delay_time_ms);


#endif /* BUZZER_H_ */
