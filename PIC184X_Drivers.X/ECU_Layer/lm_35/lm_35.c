/* 
 * File:   lm_35.c
 * Author: Merlin
 *
 * Created on August 4, 2023, 12:47 AM
 */
#include "lm_35.h"

Std_ReturnType lm_35_get_result(const uint16 lm_res, float *temp)
{
   float temp_val = 0.0f;
    Std_ReturnType ret = E_OK;

    if (lm_res == NULL || temp == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        temp_val = lm_res * 4.88f;
        temp_val /= 10;
        *temp = temp_val;
    }
}