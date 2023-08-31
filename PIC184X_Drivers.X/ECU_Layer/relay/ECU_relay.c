/* 
 * File:   ECU_relay.c
 * Author: Merlin
 *
 * Created on June 22, 2023, 6:59 PM
 */
#include "ECU_relay.h"

/**
 * @berif Initialize the relay to be output and the relay on or off.
 * @param _relay pointer to the relay module configuration
 * @return  status of the function
 *         (E_OK)     : The function done successfully
 *         (E_NOT_OK) : The function has issue    
 */
Std_ReturnType relay_init(const relay *_relay)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _relay)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config pin_obj = { .port = _relay->relay_port,
                               .pin  = _relay->relay_pin,
                               .direction = OUTPUT,
                               .logic = _relay->relay_status     
        };
       ret = gpio_pin_Intit (&pin_obj);
    }
    return ret;
}

/**
 * @berif Turn the relay on
 * @param _relay pointer to the relay module configuration
 * @return  status of the function
 *         (E_OK)     : The function done successfully
 *         (E_NOT_OK) : The function has issue    
 */
Std_ReturnType relay_on(const relay *_relay)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _relay)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config pin_obj = { .port = _relay->relay_port,
                               .pin  = _relay->relay_pin,
                               .direction = OUTPUT,
                               .logic = _relay->relay_status     
        };
       ret = gpio_pin_Write_logic (&pin_obj, HIGH);
    }
    return ret;
}
/**
 * @berif Turn the relay off
 * @param _relay pointer to the relay module configuration
 * @return  status of the function
 *         (E_OK)     : The function done successfully
 *         (E_NOT_OK) : The function has issue    
 */
Std_ReturnType relay_off(const relay *_relay)
{
    Std_ReturnType ret = E_OK;
    if (NULL == _relay)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config pin_obj = { .port = _relay->relay_port,
                               .pin  = _relay->relay_pin,
                               .direction = OUTPUT,
                               .logic = _relay->relay_status     
        };
       ret = gpio_pin_Write_logic (&pin_obj, LOW);
    }
    return ret;
}
