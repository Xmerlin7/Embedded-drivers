/* 
 * File:   HAL_GPIO.c
 * Author: Merlin
 *
 * Created on May 3, 2023, 4:11 AM
 */

#include "HAL_GPIO.h"
/**
 * 
 * @param _pin_config
 * @return 
 */

/* Reference to the data direction i/p or o/p */

volatile uint8 *TRIS_REGS [] = {&TRISA, &TRISB, &TRISC, &TRISD,&TRISE};

/* Reference to the Data Latch Register Write( LOw , High )*/

volatile uint8 *lAT_REGS  [] = {&LATA, &LATB, &LATC, &LATD,&LATE};

/* Reference to the port status Register (Low , High ) */

volatile uint8 *PORT_REGS [] = {&PORTA, &PORTB, &PORTC, &PORTD,&PORTE};

/**
 * @breif it initializes the pin i/p or o/p as it in the application.c
 * @param _pin_config
 * @return 
 */

#if GPIO_pin_Config == CONFIG_ENABLE
Std_ReturnType  gpio_pin_Direction(const pin_config *_pin_config)
{
    Std_ReturnType ret = E_OK;
    
    if ((NULL == _pin_config) || ((_pin_config -> pin) > (port_pinMax-1)))
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (_pin_config ->direction)
        {
            case OUTPUT :
                CLEAR_BIT(*TRIS_REGS[_pin_config ->port], _pin_config ->pin);
                break;
            
            case INPUT :
                SET_BIT(*TRIS_REGS[_pin_config ->port], _pin_config ->pin);
                break;
            
            default : ret = E_NOT_OK;
        }
    }
    
    return ret;
}
#endif
/**
 * 
 * @param _pin_config
 * @param _status
 * @return 
 */
#if GPIO_pin_Config == CONFIG_ENABLE
Std_ReturnType  gpio_pin_Get_direction(const pin_config *_pin_config, direction *_status)
{
    Std_ReturnType ret = E_OK;
    
    if ((NULL == _pin_config) || (_pin_config -> pin > port_pinMax-1))
    {
        ret = E_NOT_OK;
    }
    else
    {
       *_status = READ_BIT(*TRIS_REGS[_pin_config ->port], _pin_config ->pin);
    }
    
    return ret;
}
#endif
/**
 * 
 * @param _pin_config
 * @param _logic
 * @return 
 */
#if GPIO_pin_Config == CONFIG_ENABLE

Std_ReturnType  gpio_pin_Write_logic(const pin_config *_pin_config, logic_t _logic)
{
    Std_ReturnType ret = E_OK;
    
    if ((NULL == _pin_config) || (_pin_config -> pin > port_pinMax-1))
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (_logic)
        {
            case HIGH:
               SET_BIT(*lAT_REGS[_pin_config -> port], _pin_config -> pin);
               break;
               
             case LOW:
               CLEAR_BIT(*lAT_REGS[_pin_config -> port], _pin_config -> pin);
               break;
               
            default :   ret = E_NOT_OK;
        }
    }
     
    return ret;
}
#endif

/**
 * @berif Initialize the pin (i/p or o/p) & write a logic ZERO_INIT or one. 
 * @param _pin_config
 * @return  status of the function
 *         (E_OK)     : The function done successfully
 *         (E_NOT_OK) : The function has issue    
 */
#if GPIO_pin_Config == CONFIG_ENABLE

Std_ReturnType  gpio_pin_Intit(const pin_config *_pin_config)
{
    Std_ReturnType ret = E_OK;
    
    if ((NULL == _pin_config) || (_pin_config -> pin > port_pinMax-1))
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret  = gpio_pin_Direction(_pin_config);
        ret |= gpio_pin_Write_logic(_pin_config, _pin_config ->logic);
    }
    
    return ret;
}

#endif


/**
 * 
 * @param _pin_config pointer to the configurations @ref pin_config
 * @param _logic
 * @return status of the function
 *         (E_OK)     : The function done successfully
 *         (E_NOT_OK) : The function has issue    
 */
#if GPIO_pin_Config == CONFIG_ENABLE

Std_ReturnType  gpio_pin_Read_logic(const pin_config *_pin_config, logic_t *_logic)
{
    Std_ReturnType ret = E_OK;
    
    if ((NULL == _pin_config) || (NULL == _logic) || (_pin_config -> pin > port_pinMax-1))
    {
        ret = E_NOT_OK;
    }
    else
    {
         *_logic = READ_BIT(*PORT_REGS[_pin_config -> port], _pin_config -> pin);
    }
    
    return ret;    
}
#endif
/**
 * 
 * @param _pin_config
 * @return 
 */


#if GPIO_pin_Config == CONFIG_ENABLE

Std_ReturnType  gpio_pin_Toggle_logic(const pin_config *_pin_config)
{
    Std_ReturnType ret = E_OK;
    
    if ((NULL == _pin_config) || (_pin_config -> pin > port_pinMax-1))
    {
        ret = E_NOT_OK;
    }
    else
    {
        TOGGLE_BIT(*lAT_REGS[_pin_config -> port], _pin_config -> pin);
    }
    
    return ret;   
}
#endif
/*************Port Implementations******************/


#if GPIO_port_Config == CONFIG_ENABLE

Std_ReturnType  gpio_port_Init(const port_index port, uint8 value)
{
    Std_ReturnType ret = E_OK;
    
    if (port > port_Max-1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *TRIS_REGS[port] = value;
    }
    
    return ret;     
}
#endif
/**
 * 
 * @param port
 * @param _status
 * @return 
 */
#if GPIO_port_Config == CONFIG_ENABLE

Std_ReturnType  gpio_port_Get_direction(const port_index port, uint8 *_status)
{
    Std_ReturnType ret = E_OK;
    
    if (NULL == _status || (port > port_pinMax-1))
    {
        ret = E_NOT_OK;
    }
    else
    {
        *_status = *TRIS_REGS[port]; 
    }
    
    return ret;    
}
#endif
/**
 * 
 * @param port
 * @param value
 * @return 
 */
#if GPIO_port_Config == CONFIG_ENABLE

Std_ReturnType  gpio_port_Write_logic(const port_index port, uint8 value)
{
    Std_ReturnType ret = E_OK;
    
    if (port > port_pinMax-1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *lAT_REGS[port] = value;
    }
    
    return ret;    
}
#endif
/**
 * 
 * @param port
 * @param value
 * @return 
 */

#if GPIO_port_Config == CONFIG_ENABLE

Std_ReturnType  gpio_port_Read_logic(const port_index port, uint8 *value)
{
    Std_ReturnType ret = E_OK;
    
    if ((NULL == value) || (port > port_pinMax-1))
    {
        ret = E_NOT_OK;
    }
    else
    {
        *value = *TRIS_REGS[port];
    }
    
    return ret;    
}
#endif
/**
 * 
 * @param port
 * @return 
 */
#if GPIO_port_Config == CONFIG_ENABLE

Std_ReturnType  gpio_port_Toggle_logic(const port_index port)
{
    Std_ReturnType ret = E_OK;
    
    if (port> port_pinMax-1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *lAT_REGS[port] ^= port_Musk;
    }
    
    return ret;    
}
#endif