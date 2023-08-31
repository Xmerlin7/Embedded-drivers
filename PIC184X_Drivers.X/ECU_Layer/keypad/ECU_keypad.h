/* 
 * File:   ECU_keypad.h
 * Author: Merlin
 * Created on July 14, 2023, 5:06 AM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

/* ?Section : Includes*/

#include "ECU_keypad_cfg.h"
#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"
/* ?Section : Macro Declarations*/
#define Keypad_row    4
#define Keypad_column 4
/* ?Section : Macro  Like function Declarations*/

/* ?Section : Data type Declarations*/
typedef struct {
    pin_config keypad_row_pins[Keypad_row];
    pin_config keypad_column_pins[Keypad_column];
}keypad;

/* ?Section : Functions Declarations*/

Std_ReturnType keypad_init(const keypad *_keypad);
Std_ReturnType keypad_get_value(const keypad *_keypad, uint8 *value);

#endif	/* ECU_KEYPAD_H */

