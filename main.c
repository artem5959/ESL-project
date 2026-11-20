

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
#include "leds.h"
#include "button.h"
#include "pwm.h"
#include "log.h"









int main(void)
{
    /* Configure board. */
    clocks_and_timers_init();
    make_leds_out();
    all_leds_off();
    make_button_in();
    pwm_setup();
    gpiote_setup();
    irq_on();
    logs_init();  
    pwm_start();

    /* Toggle LEDs. */
    while (true)
    {
     
        
      

                LOG_BACKEND_USB_PROCESS();
                NRF_LOG_PROCESS();
       

    }
}

/**
 *@}
 **/
