/* 
 * File:   lm_35.h
 * Author: Merlin
 *
 * Created on August 4, 2023, 12:47 AM
 */

#ifndef LLM_35_H
#define	LLM_35_H
/* ?Section : Includes*/
#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"


/* ?Section : Macro Declarations*/

/* ?Section : Macro  Like function Declarations*/

/* ?Section : Data type Declarations*/
typedef struct {
    pin_config lm_pin;
    
}lm_35_t;

/* ?Section : Functions Declarations*/
Std_ReturnType lm_35_get_result(const uint16 lm_res, float *temp);

#endif	/* LLM_35_H */

