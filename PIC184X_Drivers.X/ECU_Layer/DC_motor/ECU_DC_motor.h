/* 
 * File:   ECU_DC_motor.h
 * Author: Merlin
 *
 * Created on July 1, 2023, 4:45 AM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/* ?Section : Includes*/
#include "ECU_DC_motor_cfg.h"
#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"

/* ?Section : Macro Declarations*/
#define dc_motor_on_state  0x01U
#define dc_motor_off_state 0x00U

#define dc_motor_pin1 0x00U
#define dc_motor_pin2 0x01U
/* ?Section : Macro  Like function Declarations*/

/* ?Section : Data type Declarations*/


typedef struct{
    pin_config dc_motor_pin[2];
}dc_motor;


/* ?Section : Functions Declarations*/
Std_ReturnType dc_motor_init(const dc_motor *_dc_motor);
Std_ReturnType dc_motor_fwd(const dc_motor *_dc_motor);
Std_ReturnType dc_motor_back(const dc_motor *_dc_motor);
Std_ReturnType dc_motor_right(const dc_motor *_dc_motor1,const dc_motor *_dc_motor2);
Std_ReturnType dc_motor_left(const dc_motor *_dc_motor1,const dc_motor *_dc_motor2);
Std_ReturnType dc_motor_stop(const dc_motor *_dc_motor);

#endif	/* ECU_DC_MOTOR_H */

