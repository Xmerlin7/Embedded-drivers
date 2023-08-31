/* 
 * File:   Ecu_layer_init.h
 * Author: Merlin
 *
 * Created on July 14, 2023, 6:23 AM
 */

#ifndef ECU_LAYER_INIT_H
#define	ECU_LAYER_INIT_H

/* ?Section : Includes*/

#include "LED/ECU_LED.h"
#include "button/ECU_button.h"
#include "relay/ECU_relay.h"
#include "DC_motor/ECU_DC_motor.h"
#include "7_segment/ECU_sev_segment.h"
#include "keypad/ECU_keypad.h"
#include "chr_lcd/ECU_chr_lcd.h"
#include "lm_35/lm_35.h"


#include "../MCAL_Layer/ADC/hal_adc.h"
#include "../MCAL_Layer/interrupt/mcal_external_interrupt.h"
#include "../MCAL_Layer/EEPROM/hal_eeprom.h"

/* ?Section : Macro Declarations*/

/* ?Section : Macro  Like function Declarations*/

/* ?Section : Data type Declarations*/


/* ?Section : Functions Declarations*/
void ecu_layer_init(void);
extern dc_motor motor1;
extern led_t led1;
#endif	/* ECU_LAYER_INIT_H */

