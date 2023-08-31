/* 
 * File:   ECU_keypad.h
 * Author: Merlin
 * Created on July 14, 2023, 5:06 AM
 */
#include "ECU_keypad.h"

static const uint8 btn_values [Keypad_row][Keypad_column] = {
                                                                {'7', '8', '9', '/'},
                                                                {'4', '5', '6', '*'},
                                                                {'1', '2', '3', '-'},
                                                                {'#', '0', '=', '+'}
                                                             };
Std_ReturnType keypad_init(const keypad *_keypad)
{
    Std_ReturnType ret = E_OK;
    uint8 rows = ZERO_INIT, columns = ZERO_INIT;
    if (NULL == _keypad)
    {
        ret = E_NOT_OK;
    }
    else
    {
        for (rows = ZERO_INIT; rows < Keypad_row; rows++)
        {
            ret = gpio_pin_Intit (&(_keypad->keypad_row_pins[rows]));
        }
        for (columns = ZERO_INIT; columns < Keypad_column; columns++)
        {
            ret = gpio_pin_Direction (&(_keypad->keypad_column_pins[columns]));
        }
    }
    
    return 0;        
}
Std_ReturnType keypad_get_value(const keypad *_keypad, uint8 *value)
{
     Std_ReturnType ret = E_OK;
     uint8 rows = ZERO_INIT, columns = ZERO_INIT, counter = ZERO_INIT;
     uint8 logic;
    if ((NULL == _keypad) || (NULL == value))
    {
        ret = E_NOT_OK;
    }
    else
    {
        for (rows = ZERO_INIT; rows < Keypad_row; rows++)
        {
            for (counter = ZERO_INIT; counter < Keypad_row; counter++)
            {
                ret = gpio_pin_Write_logic (&(_keypad->keypad_row_pins[counter]), LOW);
            }
            ret = gpio_pin_Write_logic (&(_keypad->keypad_row_pins[rows]), HIGH);
            for (columns = ZERO_INIT; columns < Keypad_column; columns++)
            {
                ret = gpio_pin_Read_logic (&(_keypad->keypad_column_pins[columns]), &logic);
                if (HIGH == logic)
                {
                    *value = btn_values[rows][counter];
                }
                else
                {/*Nothing*/}

            }
        }
    }
    
    return 0;      
}