#ifndef ESL_BUTTON_H
#define ESL_BUTTON_H

#include <stdint.h>
#include "nrf_gpio.h"

#define BUTTON_PIN NRF_GPIO_PIN_MAP(1, 6)

#define ON_BUTTON 0
#define OFF_BUTTON 1

void make_button_in(void); // инициализация пина кнопки как входящего 

uint32_t check_button_status(uint32_t pin); // проверка статуса кнопки

#endif