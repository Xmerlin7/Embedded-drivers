/* 
 * File:   ECU_LED.h
 * Author: Merlin
 *
 * Created on May 3, 2023, 5:29 AM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

/* ?Section : Includes*/

#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"
#include "ECU_LED_cfg.h"
/* ?Section : Macro Declarations*/

/* ?Section : Macro  Like function Declarations*/

/* ?Section : Data type Declarations*/

typedef enum{
    LED_OFF = 0,
    LED_ON
}led_s;

typedef struct
{
    uint8 port_name   : 4;
    uint8 pin         : 3;
    uint8 led_status  : 1;
}led_t;

typedef enum {
    up = 0,
    down
}leds_dir;

/* ?Section : Functions Declarations*/

Std_ReturnType led_init(const led_t *_led);
Std_ReturnType led_on(const led_t *_led);
Std_ReturnType led_off(const led_t *_led);
Std_ReturnType led_toggle(const led_t *_led);



#endif	/* ECU_LED_H */

