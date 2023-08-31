/*
 * File:   application.c
 * Author: Merlin
 *
 * Created on May 3, 2023, 4:11 AM
 */

#include "application.h"
#include "MCAL_Layer/Timer0/hal_timer0.h"
#include "MCAL_Layer/CCP/hal_ccp.h"
#include "MCAL_Layer/Timer1/hal_timer1.h"

void program1(void);
void program2(void);
void program3(void);
void TMR0_ISR_handler(void);
void TMR1_ISR_handler(void);

button_t btn_1 = {
  .button_connection = BUTTON_ACTIVE_HIGH,
  .button_pin.direction = INPUT,
  .button_pin.logic = LOW,
  .button_pin.pin = PIN0,
  .button_pin.port = PORTB_INDEX,
  .button_state = BUTTON_RELEASED
};

timer0_t tmr_0 = {
  .TMR0_InterruptHandler = TMR0_ISR_handler,
  .prescaler_enable = TIMER0_PRESCALER_DISABLE_CFG,
  .timer0_mode = TIMER0_TIMER_MODE,
  .timer0_register_size = TIMER0_16BIT_REGISTER_MODE,
  .timer0_preload_value = 45536
};

timer1_t tmr_1 = {
    .TMR1_InterruptHandler = TMR1_ISR_handler,
    .timer1_mode = TIMER1_TIMER_MODE,
    .timer1_osc_cfg = TIMER1_OSCILLATOR_DISABLE,
    .timer1_preload_value = 15536,
    .timer1_prescaler_value = TIMER1_PRESCALER_DIV_BY_2,
    .timer1_reg_wr_mode = TIMER1_RW_REG_16Bit_MODE,
};

led_t led1 = {.led_status = LED_OFF, .pin = PIN0, .port_name = PORTC_INDEX};
led_t led2 = {.led_status = LED_OFF, .pin = PIN1, .port_name = PORTC_INDEX};

uint8 program = 1;
uint8 btn_satuts = 0;
uint8 btn_pressed = 0;
uint8 enter_prog = 0;
volatile uint8 tics = 0;
volatile uint8 tics1 = 0;
volatile uint8 ctr = 0;
volatile uint8 ctr1 = 0;
volatile uint8 counter_checker = 0; /*counting the number of not pressed state of the button*/
volatile uint8 first_time = 1; /*An indication if it is the first not pressed state or not*/
volatile uint8 flag = 0; /* An indication if it is a connected not pressed state or not*/
Std_ReturnType ret = E_NOT_OK;

int main()
{
    App_Init();
    while(1)
    {
        ret = button_read_state(&btn_1, &btn_satuts);
        if(btn_satuts == BUTTON_PRESSED){
            TIMER0_MODULE_ENABLE();
            if(ctr >= 7){
                btn_pressed = 1;
                ctr = 0;
            }
        }
        if(btn_pressed){
            TIMER1_MODULE_ENABLE();
            if(ctr1 >= 30){
                program++;
                if(program > 3)
                    program = 1;
                btn_pressed = 0;
                ctr1 = 0;
            }else if(ctr1 < 30 && counter_checker >= 4){
                enter_prog = 1;
                TIMER1_MODULE_DISABLE();
                ctr1 = 0;
                tics1 = 0;
                counter_checker = 0;
            }
            else{
                /*Nothing*/
            }
        }

        if(enter_prog){
            switch (program){
                case 1:
                    program1();
                    break;
                case 2:
                    program2();
                    break;
                case 3:
                    program3();
                    break;
                default:/*Nothing*/;
            }
            enter_prog = 0;
        }
    }
    return (EXIT_SUCCESS);
}
void program1(void){
    led_on(&led1);
    __delay_ms(5000);
    led_off (&led1);
}

void program2(void){
    led_on(&led2);
    __delay_ms(10000);
    led_off (&led2);
}

void program3(void){
    led_on(&led1);
    __delay_ms(20000);
    led_off (&led1);
}

void TMR0_ISR_handler(void)
{
    tics++;
    if (tics < 10)
    {
        ret = button_read_state (&btn_1, &btn_satuts);
        if (btn_satuts == BUTTON_PRESSED)
        {
            ctr++;
        }else{
            /*Nothing*/
        }
    }else{
        tics = 0;
        TIMER0_MODULE_DISABLE();
    }
}

void TMR1_ISR_handler (void)
{
    tics1++;
    if (tics1 < 40)
    {
        ret = button_read_state (&btn_1, &btn_satuts);
        if (btn_satuts == BUTTON_PRESSED)
        {
            ctr1++;
        }else{
            if(first_time == 1){
                ++counter_checker;
            }
            else{
                if(flag == 1){
                    ++counter_checker;
                }
                else{
                    counter_checker = 0;
                    flag = 0;
                    first_time = 1;
                }
            }

        }
    }else{
        tics1 = 0;
        TIMER1_MODULE_DISABLE();
    }
}

void App_Init(void)
{
    ret = button_init(&btn_1);
    ret = led_init (&led1);
    ret = Timer0_Init(&tmr_0);

    ecu_layer_init ();
}
