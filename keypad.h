/*
 * keypad.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nmr
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "STD_TYPES.h"
#include "Utils.h"
#include "DIO.h"

#define KEYBAD_ROW_PORT     PORT_A
#define FIRST_ROW_PIN        5//0
#define SECOND_ROW_PIN       4//1
#define THIRD_ROW_PIN        3//2

#define KEYBAD_COLUMN_PORT  PORT_A
#define FIRST_COLUMN_PIN     0//5
#define SECOND_COLUMN_PIN    1//4
#define THIRD_COLUMN_PIN     2//3

#define NOT_PRESSED          0x0F
#define BOUNCING_DELAY       _delay_ms(50)

void EF_void_KeyPad_Init (void);
U8 EF_u8_KeyPad_Scan (void);


#endif /* KEYPAD_H_ */
