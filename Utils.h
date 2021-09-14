/*
 * Utils.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nmr
 */

#ifndef UTILS_H_
#define UTILS_H_

/*        MACROS FOR PIN         */
#define  SET_BIT(REG,BIT)      REG |=(1<<BIT)
#define  CLEAR_BIT(REG,BIT)    REG &=~(1<<BIT)
#define  GET_BIT(REG,INDEX)      ((REG>>INDEX)&(0x01))
#define  TOG_BIT(REG,BIT)				REG^=(1<<(BIT))

/*         MACROS TO PORT        */

#endif /* UTILS_H_ */
