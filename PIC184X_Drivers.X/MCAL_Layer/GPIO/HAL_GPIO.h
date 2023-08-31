/* 
 * File:   HAL_GPIO.h
 * Author: Merlin
 *
 * Created on May 3, 2023, 4:36 AM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/* ?Section : Includes */

#include "pic18f4620.h"
#include "../MCAL_std_types.h"
#include "../device_config.h"
#include "HAL_GPIO_cfc.h"

/* ?Section : Macro Declarations */

#define BIT_MASK (uint8)0x01

#define port_pinMax     8
#define port_Max        5
#define port_Musk       0xFF

#define GPIO_pin_Config  CONFIG_ENABLE
#define GPIO_port_Config CONFIG_ENABLE

/* ?Section : Macro Like function Declarations*/

#define HWREG8 (_X) (*(volatile uint8 *)(0x_X))

#define SET_BIT(REG, BIT_POS)    (REG |= (BIT_MASK << BIT_POS)) 
#define CLEAR_BIT(REG, BIT_POS)  (REG &= ~(BIT_MASK << BIT_POS))
#define TOGGLE_BIT(REG, BIT_POS) (REG ^= (BIT_MASK << BIT_POS))
#define READ_BIT(REG, BIT_POS)   ((REG >> BIT_POS) & BIT_MASK)


/* ?Section : Data type Declarations*/

typedef enum{
    LOW = 0,
    HIGH        
}logic_t;

typedef enum{
    OUTPUT = 0,
    INPUT
}direction;

typedef enum{
   PIN0 = 0,
   PIN1,
   PIN2,
   PIN3,
   PIN4,
   PIN5,
   PIN6,
   PIN7                   
}pin_index;

typedef enum{
   PORTA_INDEX = 0,
   PORTB_INDEX,
   PORTC_INDEX,
   PORTD_INDEX,
   PORTE_INDEX
           
}port_index;
typedef struct{
    uint8 port      : 3;        /* port_index */
    uint8 pin       : 3;       /* pin_index */
    uint8 direction : 1;      /* pin_direction */
    uint8 logic     : 1;     /* pin_logic */  
    
}pin_config;

/* ?Section : Functions Declarations*/

Std_ReturnType  gpio_pin_Direction(const pin_config *_pin_config);
Std_ReturnType  gpio_pin_Get_direction(const pin_config *_pin_config, direction *_status);
Std_ReturnType  gpio_pin_Intit(const pin_config *_pin_config);
Std_ReturnType  gpio_pin_Write_logic(const pin_config *_pin_config, logic_t _logic);
Std_ReturnType  gpio_pin_Read_logic(const pin_config *_pin_config, logic_t *_logic);
Std_ReturnType  gpio_pin_Toggle_logic(const pin_config *_pin_config);

Std_ReturnType  gpio_port_Init(const port_index port, uint8 value);
Std_ReturnType  gpio_port_Get_direction(const port_index port, uint8 *_status);
Std_ReturnType  gpio_port_Write_logic(const port_index port, uint8 value);
Std_ReturnType  gpio_port_Read_logic(const port_index port, uint8 *value);
Std_ReturnType  gpio_port_Toggle_logic(const port_index port);

#endif	/* HAL_GPIO_H */

