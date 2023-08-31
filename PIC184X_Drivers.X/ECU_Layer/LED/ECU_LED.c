/* 
 * File:   application.c
 * Author: Merlin
 *
 * Created on May 3, 2023, 4:11 AM
 */

#include "ECU_LED.h"





/**
 * @brief Initialize the assigned pin to be output and turn the led off.
 * @param _led : pointer to the led module configurations
 * @return status of the function 
 *         (E_OK)     : The function done successfully
 *         (E_NOT_OK) : The function has issue
 */
Std_ReturnType led_init(const led_t *_led)
{
    Std_ReturnType ret = E_OK;
    
    if (NULL == _led)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config pin_obj = { .port = _led ->port_name,
                               .pin = _led ->pin,
                               .direction = OUTPUT,
                               .logic = _led -> led_status
                             }; 
        gpio_pin_Intit (&pin_obj);
    }
    
    return ret;
}
/**
 * @brief  Turn the led on.
 * @param _led : pointer to the led module configurations
 * @return status of the function 
 *         (E_OK)     : The function done successfully
 *         (E_NOT_OK) : The function has issue
 */
Std_ReturnType led_on(const led_t *_led)
{
       Std_ReturnType ret = E_OK;
    
    if (NULL == _led)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config pin_obj = { .port = _led -> port_name,
                               .pin  = _led -> pin,
                               .direction = OUTPUT,
                               .logic = _led ->led_status
                             };
        gpio_pin_Write_logic (&pin_obj, HIGH);
    }
    
    return ret; 
}
/**
 * @brief  Turn the led off.
 * @param _led : pointer to the led module configurations
 * @return status of the function 
 *         (E_OK)     : The function done successfully
 *         (E_NOT_OK) : The function has issue
 */
Std_ReturnType led_off(const led_t *_led)
{
        Std_ReturnType ret = E_OK;
    
    if (NULL == _led)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config pin_obj = { .port = _led -> port_name,
                               .pin  = _led -> pin,
                               .direction = OUTPUT,
                               .logic = _led ->led_status
                             };
        gpio_pin_Write_logic (&pin_obj, LOW);        
    }
    
    return ret;
}
/**
 * @brief Toggle the led .
 * @param _led : pointer to the led module configurations
 * @return status of the function 
 *         (E_OK)     : The function done successfully
 *         (E_NOT_OK) : The function has issue
 */
Std_ReturnType led_toggle(const led_t *_led)
{
        Std_ReturnType ret = E_OK;
    
    if (NULL == _led)
    {
        ret = E_NOT_OK;
    }
    else
    {
                pin_config pin_obj = { .port = _led -> port_name,
                               .pin  = _led -> pin,
                               .direction = OUTPUT,
                               .logic = _led ->led_status
                             };
        gpio_pin_Toggle_logic (&pin_obj);        
    }
    
    
    return ret;
}
