/* 
 * File:   ECU_7_segment.h
 * Author: Merlin
 *
 * Created on July 1, 2023, 7:38 AM
 */
#include "ECU_sev_segment.h"

Std_ReturnType seven_seg_init(const segment *_seg)
{
       Std_ReturnType ret = E_OK;
    if (NULL == _seg)
    {
        ret = E_NOT_OK;
    }
    else
    {
       ret = gpio_pin_Intit (&(_seg->segment_pins[seg_pin0]));
       ret = gpio_pin_Intit (&(_seg->segment_pins[seg_pin1]));
       ret = gpio_pin_Intit (&(_seg->segment_pins[seg_pin2]));
       ret = gpio_pin_Intit (&(_seg->segment_pins[seg_pin3]));
    }
    return ret; 
}
Std_ReturnType seven_seg_write(const segment *_seg, uint8 number)
{
           Std_ReturnType ret = E_OK;
    if ((NULL == _seg) || number > 9)
    {
        ret = E_NOT_OK;
    }
    else
    {
   
       ret = gpio_pin_Write_logic (&(_seg->segment_pins[seg_pin0]), number &0x01);
       ret = gpio_pin_Write_logic (&(_seg->segment_pins[seg_pin1]), (number>>1)&0x01);
       ret = gpio_pin_Write_logic (&(_seg->segment_pins[seg_pin2]), (number>>2) &0x01);
       ret = gpio_pin_Write_logic (&(_seg->segment_pins[seg_pin3]), (number>>3) &0x01);

    }
    return ret; 
}