/* 
 * File:   Ecu_layer_init.c
 * Author: Merlin
 *
 * Created on July 14, 2023, 6:23 AM
 */
#include "Ecu_layer_init.h"
chr_lcd_4bit_t lcd1 = {
    .lcd_rs.port = PORTC_INDEX,
    .lcd_rs.pin = PIN0,
    .lcd_rs.direction = OUTPUT,
    .lcd_rs.logic = LOW,
    .lcd_en.port = PORTC_INDEX,
    .lcd_en.pin = PIN1,
    .lcd_en.direction = OUTPUT,
    .lcd_en.logic = LOW,
    .lcd_data[0].port = PORTC_INDEX,
    .lcd_data[0].pin = PIN2,
    .lcd_data[0].direction = OUTPUT,
    .lcd_data[0].logic = LOW,
    .lcd_data[1].port = PORTC_INDEX,
    .lcd_data[1].pin = PIN3,
    .lcd_data[1].direction = OUTPUT,
    .lcd_data[1].logic = LOW,
    .lcd_data[2].port = PORTC_INDEX,
    .lcd_data[2].pin = PIN4,
    .lcd_data[2].direction = OUTPUT,
    .lcd_data[2].logic = LOW,
    .lcd_data[3].port = PORTC_INDEX,
    .lcd_data[3].pin = PIN5,
    .lcd_data[3].direction = OUTPUT,
    .lcd_data[3].logic = LOW
};
adc_conf_t adc1 = {
  .ADC_InterruptHandler = NULL,
  .acquisition_time = ADC_12_TAD,
  .adc_channel = ADC_CHANNEL_AN0,
  .conversion_clock = ADC_CONVERSION_CLOCK_FOSC_DIV_16,
  .result_format = ADC_RESULT_RIGHT,
  .voltage_reference = ADC_VOLTAGE_REFERENCE_DISABLED
};
void ecu_layer_init(void)
{
   Std_ReturnType ret = E_OK;

}