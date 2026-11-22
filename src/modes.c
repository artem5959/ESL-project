#include "modes.h"
#include "pwm.h"
#include "hsv.h"
#include "button.h"
#include "log.h"
#include "nrf_delay.h"

volatile uint16_t mode = NO_INPUT_MODE;

volatile uint16_t mode_flag = NO_CHANGED;

void mode_handler(void)
{
    switch (mode)
    {
        case NO_INPUT_MODE:
        mode_flag = NO_CHANGED;
        NRF_LOG_INFO("NOW -  NO_INPUT_MODE ");
        no_input_mode_on();
        
        
        break;

        case HUE_MODIFICATION:
        mode_flag = NO_CHANGED;
        NRF_LOG_INFO("NOW -  HUE MODIFICATION MODE ");
        hue_modification_mode_on();
        
        break;

        case SAT_MODIFICATION:
        mode_flag = NO_CHANGED;
        NRF_LOG_INFO("NOW -  SAT MODIFICATION MODE ");
        sat_modification_mode_on();
        
        break;

        case BRIGHT_MODIFICATION:
        mode_flag = NO_CHANGED;
        NRF_LOG_INFO("NOW -  BRIGHTNESS MODIFICATION MODE ");
        brightness_modification_mode_on();
        
        break;

    }
}


void hue_modification_mode_on(void)
{       
    NRF_LOG_INFO("START_HUE_MODIFICATIONS");
        if(mode == HUE_MODIFICATION){

            nrfx_pwm_sequence_update(&pwm1_led_indication, 0, &seq_hue_modification); 

            while(mode == HUE_MODIFICATION) {
                NRF_LOG_PROCESS();
                if (button_status == PRESSED) {
                    hue_modification_one_up(&hsv, &actual, duty_cycle_led1);
                     nrf_delay_ms(10);
                    
                    
                    
                    
                }
                else {
                    NRF_LOG_INFO("WFI START ");
                    NRF_LOG_PROCESS();
                    nrf_delay_ms(30);
                    __WFI();
                }
                
            }
        
        }   
        //mode_flag = NO_CHANGED;

}

void sat_modification_mode_on(void)
{       
     NRF_LOG_INFO("START_SAT_MODIFICATIONS");
        if(mode == SAT_MODIFICATION){ 

            nrfx_pwm_sequence_update(&pwm1_led_indication, 0, &seq_sat_modification); 

            while (mode == SAT_MODIFICATION) {
                NRF_LOG_PROCESS();
                if(button_status == PRESSED) {
                    saturation_modification_one_up(&hsv, &actual, duty_cycle_led1);
                     nrf_delay_ms(10);
                     
                    
                }
                else {
                    NRF_LOG_INFO("WFI START ");
                    NRF_LOG_PROCESS();
                    nrf_delay_ms(30);
                    __WFI();
                }
                
            }
        
        }   

}

void brightness_modification_mode_on(void)
{       
    NRF_LOG_INFO("START_BRIGHT_MODIFICATIONS");
        if(mode == BRIGHT_MODIFICATION){  
            
            nrfx_pwm_sequence_update(&pwm1_led_indication, 0, &seq_bright_modification);

            while (mode == BRIGHT_MODIFICATION) {
                    NRF_LOG_PROCESS();
                if(button_status == PRESSED) {
                    brightness_modification_one_up(&hsv, &actual, duty_cycle_led1);
                    nrf_delay_ms(10);
                    
                    
                }
                 else {
                    NRF_LOG_INFO("WFI START ");
                    NRF_LOG_PROCESS();
                    nrf_delay_ms(30);
                    __WFI();
                }
            }
        
        }   

}

void no_input_mode_on(void)
{

        NRF_LOG_INFO("LAST CHANGES - HUE: %d SAT: %d BRIGHT: %d", 
                                hsv.hue_value,
                                hsv.saturation_value,
                                hsv.brightness_value);
        if(mode == NO_INPUT_MODE){
        nrfx_pwm_sequence_update(&pwm1_led_indication, 0, &no_input_modification);
        if(hsv_to_flash_write(&hsv)){
            NRF_LOG_INFO("HSV WRITE TO FLASH COMPLETED");
        };
        return;
    }
}

