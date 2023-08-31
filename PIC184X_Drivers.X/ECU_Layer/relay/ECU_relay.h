/* 
 * File:   ECU_relay.h
 * Author: Merlin
 *
 * Created on June 22, 2023, 6:59 PM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/* ?Section : Includes*/

#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"
#include "ECU_relay_cfg.h"
/* ?Section : Macro Declarations*/
#define relay_on_state  0x01U
#define relay_off_state 0x00U
/* ?Section : Macro  Like function Declarations*/

/* ?Section : Data type Declarations*/
typedef struct{
    uint8 relay_port   :4;
    uint8 relay_pin    :3;
    uint8 relay_status :1;
}relay;

/* ?Section : Functions Declarations*/
Std_ReturnType relay_init(const relay *_relay);
Std_ReturnType relay_on(const relay *_relay);
Std_ReturnType relay_off(const relay *_relay);
#endif	/* ECU_RELAY_H */

