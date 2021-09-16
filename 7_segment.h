/*
 * 7_segment.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nmr
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_

#include <util/delay.h>
#include <avr/io.h>
#include "STD_Types.h"
#include "Utils.h"
#include "DIO.h"

#define SEG1_PORT PORT_B
#define SEG2_PORT PORT_B
#define SEG3_PORT PORT_B
#define SEG4_PORT PORT_B

#define SEG1_PIN PIN_0
#define SEG2_PIN PIN_1
#define SEG3_PIN PIN_2
#define SEG4_PIN PIN_3


#define SEG_EN1_PORT PORT_C
#define SEG_EN2_PORT PORT_C
#define SEG_EN3_PORT PORT_C
#define SEG_EN4_PORT PORT_C

#define SEG1_EN_PIN PIN_5
#define SEG2_EN_PIN PIN_4
#define SEG3_EN_PIN PIN_3
#define SEG4_EN_PIN PIN_2


typedef enum
{
  seg1,
  seg2,
  seg3,
  seg4

}en_segment;


void segment_init(en_segment seg_number);
void segment_write(en_segment seg_number, U8 data);
void segment_Deinit(en_segment seg_number);

#endif /* 7_SEGMENT_H_ */
