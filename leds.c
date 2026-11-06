#include "leds.h"

void make_leds_out(void){
     nrf_gpio_cfg_output(LED_GR);
     nrf_gpio_cfg_output(LED_R);
     nrf_gpio_cfg_output(LED_G);
     nrf_gpio_cfg_output(LED_B);    
}

void led_on(uint32_t pin){
    nrf_gpio_pin_write(pin, ON_LED);
}

void led_off(uint32_t pin){
    nrf_gpio_pin_write(pin, OFF_LED);
}

void all_leds_off(void){
    nrf_gpio_pin_write(LED_GR, OFF_LED);
    nrf_gpio_pin_write(LED_R, OFF_LED);
    nrf_gpio_pin_write(LED_G, OFF_LED);
    nrf_gpio_pin_write(LED_B, OFF_LED);
}

uint32_t check_led_status(uint32_t pin){
   

   if (nrf_gpio_pin_read(pin) == ON_LED)
   return ON_LED; // return 0

   return OFF_LED; //  return 1
}


