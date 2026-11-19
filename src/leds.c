#include "leds.h"
#include "log.h"







//gpio_setup
void make_leds_out(void){
     nrf_gpio_cfg_output(LED_GR);
     nrf_gpio_cfg_output(LED_R);
     nrf_gpio_cfg_output(LED_G);
     nrf_gpio_cfg_output(LED_B);    
}

void all_leds_off(void){
    nrf_gpio_pin_write(LED_GR, OFF_LED);
    nrf_gpio_pin_write(LED_R, OFF_LED);
    nrf_gpio_pin_write(LED_G, OFF_LED);
    nrf_gpio_pin_write(LED_B, OFF_LED);

    NRF_LOG_INFO("All leds pins is off");
}
////
void gpio_setup(void) {
    make_leds_out();
    all_leds_off();
    NRF_LOG_INFO("Gpio setup");
}
//

// check led_status
uint32_t check_led_status(uint32_t pin){
   

   if (nrf_gpio_pin_read(pin) == ON_LED)
   return ON_LED; // return 0

   return OFF_LED; //  return 1
}
//


uint32_t id_index (uint32_t led_index1)
{
    return ((ID / (1000 / (int)pow(10, led_index1) ) ) % 10);
}






