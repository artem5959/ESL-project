#include "button.h"

void make_button_in(void){

    nrf_gpio_cfg_input(BUTTON_PIN, NRF_GPIO_PIN_PULLUP);

}

uint32_t check_button_status(uint32_t pin){
    if (nrf_gpio_pin_read(pin) == ON_BUTTON)
    return ON_BUTTON; //  return 0


    return OFF_BUTTON; // return 1
}