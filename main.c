

/** @file
 *
 * @defgroup blinky_example_main main.c
 * @{
 * @ingroup blinky_example
 * @brief Blinky Example Application main file.
 *
 * This file contains the source code for a sample application to blink LEDs.
 *
 */

#include <stdbool.h>
#include <stdint.h>
#include "nrf_gpio.h"
#include <math.h>
#include "leds.h"
#include "button.h"
#include "pwm.h"
#include "log.h"


#define ID 6616




int id_index (int led_index1)
{
    return ((ID / (1000 / (int)pow(10, led_index1) ) ) % 10);
}



int main(void)
{
    /* Configure board. */
    clocks_and_timers_init();
    make_leds_out();
    all_leds_off();
    make_button_in();
    pwm_setup();
    configure_pwm();
    gpiote_setup();
    irq_on();
    logs_init();  


    /* Toggle LEDs. */
    while (true)
    {
        for (uint16_t i = 0; i < LEDS_NUMBER; i++)
        {   
            uint32_t index = id_index(i); // setup index

            pwm_seqtable_set(i);
            

            for( uint32_t count = 0; count < index; ) {
                
                pwm_start();
               
                pwm_sequence_func();
                
                count++;
                pwm_stop();
            }

            
        }


       

    }
}

/**
 *@}
 **/
