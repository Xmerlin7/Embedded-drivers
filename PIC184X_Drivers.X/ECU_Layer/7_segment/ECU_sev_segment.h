/* 
 * File:   ECU_7_segment.h
 * Author: Merlin
 *
 * Created on July 1, 2023, 7:38 AM
 */

#ifndef ECU_7_SEGMENT_H
#define	ECU_7_SEGMENT_H

/* ?Section : Includes*/

#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"

/* ?Section : Macro Declarations*/

#define seg_pin0 0
#define seg_pin1 1
#define seg_pin2 2
#define seg_pin3 3

/* ?Section : Macro  Like function Declarations*/

/* ?Section : Data type Declarations*/
typedef enum{
    seg_common_anode,
    seg_common_cathode
}segment_type_t;

typedef struct {
    pin_config segment_pins[4];
    segment_type_t segment_type;
}segment;
/* ?Section : Functions Declarations*/
Std_ReturnType seven_seg_init(const segment *_seg);
Std_ReturnType seven_seg_write(const segment *_seg, uint8 number);
#endif	/* ECU_7_SEGMENT_H */

