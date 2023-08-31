/* 
 * File:   ECU_DC_motor.c
 * Author: Merlin
 *
 * Created on July 1, 2023, 4:45 AM
 */

#include "ECU_DC_motor.h"



Std_ReturnType dc_motor_init(const dc_motor *_dc_motor)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _dc_motor)
    {
        ret = E_NOT_OK;
    }
    else
    {
        gpio_pin_Intit (&(_dc_motor->dc_motor_pin[dc_motor_pin1]));
        gpio_pin_Intit (&(_dc_motor->dc_motor_pin[dc_motor_pin2]));
    }
    return ret;
}
Std_ReturnType dc_motor_fwd(const dc_motor *_dc_motor)
{
        Std_ReturnType ret = E_OK;
    if (NULL == _dc_motor)
    {
        ret = E_NOT_OK;
    }
    else
    {
        gpio_pin_Write_logic (&(_dc_motor->dc_motor_pin[dc_motor_pin1]),HIGH);
        gpio_pin_Write_logic (&(_dc_motor->dc_motor_pin[dc_motor_pin2]),LOW);
    }
    return ret;
}
Std_ReturnType dc_motor_back(const dc_motor *_dc_motor)
{
        Std_ReturnType ret = E_OK;
    if (NULL == _dc_motor)
    {
        ret = E_NOT_OK;
    }
    else
    {
        gpio_pin_Write_logic (&(_dc_motor->dc_motor_pin[dc_motor_pin1]),LOW);
        gpio_pin_Write_logic (&(_dc_motor->dc_motor_pin[dc_motor_pin2]),HIGH);
    }
    return ret;
}

Std_ReturnType dc_motor_right(const dc_motor *_dc_motor1,const dc_motor *_dc_motor2)
{
            Std_ReturnType ret = E_OK;
    if ((NULL == _dc_motor1) || (NULL == _dc_motor2))
    {
        ret = E_NOT_OK;
    }
    else
    {
        gpio_pin_Write_logic (&(_dc_motor1->dc_motor_pin[dc_motor_pin1]),LOW);
        gpio_pin_Write_logic (&(_dc_motor1->dc_motor_pin[dc_motor_pin1]),HIGH);
        gpio_pin_Write_logic (&(_dc_motor2->dc_motor_pin[dc_motor_pin2]),HIGH);
        gpio_pin_Write_logic (&(_dc_motor2->dc_motor_pin[dc_motor_pin2]),LOW);
    }
    return ret;
}

Std_ReturnType dc_motor_left(const dc_motor *_dc_motor1,const dc_motor *_dc_motor2)
{
            Std_ReturnType ret = E_OK;
    if ((NULL == _dc_motor1) || (NULL == _dc_motor2))
    {
        ret = E_NOT_OK;
    }
    else
    {
        gpio_pin_Write_logic (&(_dc_motor1->dc_motor_pin[dc_motor_pin1]),HIGH);
        gpio_pin_Write_logic (&(_dc_motor1->dc_motor_pin[dc_motor_pin1]),LOW);
        gpio_pin_Write_logic (&(_dc_motor2->dc_motor_pin[dc_motor_pin2]),LOW);
        gpio_pin_Write_logic (&(_dc_motor2->dc_motor_pin[dc_motor_pin2]),HIGH);
    }
    return ret;
}

Std_ReturnType dc_motor_stop(const dc_motor *_dc_motor)
{
        Std_ReturnType ret = E_OK;
    if (NULL == _dc_motor)
    {
        ret = E_NOT_OK;
    }
    else
    {
        gpio_pin_Write_logic (&(_dc_motor->dc_motor_pin[dc_motor_pin1]),LOW);
        gpio_pin_Write_logic (&(_dc_motor->dc_motor_pin[dc_motor_pin2]),LOW);
    }
    return ret;
}