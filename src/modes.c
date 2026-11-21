#include "modes.h"
#include "pwm.h"
#include "hsv.h"
#include "button.h"
#include "log.h"
#include "nrf_delay.h"
volatile uint16_t mode = NO_INPUT_MODE;


void hue_modification_mode_on(void)
{       
        if(mode == HUE_MODIFICATION){  
            nrfx_pwm_sequence_update(&pwm1_led_indication, 0, &seq_hue_modification); 
            while (mode == HUE_MODIFICATION) {
                while(check_button_status(BUTTON_PIN) == PRESSED) {
                    hue_modification_one_up(&hsv, &actual, duty_cycle_led1);
                    //nrfx_pwm_sequence_values_update(&pwm0, 0, (nrf_pwm_values_t)duty_cycle_led1[0]);  // update sequense
                }
            }
        
        }   
}

void sat_modification_mode_on(void)
{       
        if(mode == SAT_MODIFICATION){  
            nrfx_pwm_sequence_update(&pwm1_led_indication, 0, &seq_sat_modification); 
            while (mode == SAT_MODIFICATION) {
                while(check_button_status(BUTTON_PIN) == PRESSED) {
                    saturation_modification_one_up(&hsv, &actual, duty_cycle_led1);
                    //nrfx_pwm_sequence_values_update(&pwm0, 0, (nrf_pwm_values_t)duty_cycle_led1[0]);  // update sequense
                }
            }
        
        }   
}

void brightness_modification_mode_on(void)
{       
        if(mode == BRIGHT_MODIFICATION){  
            nrfx_pwm_sequence_update(&pwm1_led_indication, 0, &seq_bright_modification);
            while (mode == BRIGHT_MODIFICATION) {
                while(check_button_status(BUTTON_PIN) == PRESSED) {
                    brightness_modification_one_up(&hsv, &actual, duty_cycle_led1);
                    //nrfx_pwm_sequence_values_update(&pwm0, 0, (nrf_pwm_values_t)duty_cycle_led1[0]);  // update sequense
                }
            }
        
        }   
}

void no_input_mode_on(void)
{
        if(mode == NO_INPUT_MODE){
        pwm_stop_indication();
        return;
    }
}

