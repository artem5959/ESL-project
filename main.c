

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
#include "modes.h"
#include "hsv.h"
#include "cdc.h"









int main(void)
{
    /* Init */
    clocks_and_timers_init();
    make_leds_out();
    all_leds_off();
    make_button_in();
    pwm_setup();
    gpiote_setup();
    irq_on();
    logs_init();  
    pwm_start_main();
    pwm_start_indication();
    setup_default_hsv(&hsv, &actual, duty_cycle_led1);
    cdc_init();


    /* Toggle LEDs. */
    while (true)
    {

         

            while (app_usbd_event_queue_process())
            {
            /* Nothing to do */
            }
     
            if (mode_flag == CHANGED) {
                mode_handler();
            }
                
                
                LOG_BACKEND_USB_PROCESS();
                NRF_LOG_PROCESS();
                
                __WFI();
       

    }
}

/**
 *@}
 **/
