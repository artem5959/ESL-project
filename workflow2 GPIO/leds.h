#ifndef LEDS_H
#define LEDS_H

#include <stdint.h>
#include "nrf_gpio.h"

#define BUTTON_PIN NRF_GPIO_PIN_MAP(1, 6)

#define ON_BUTTON 0
#define OFF_BUTTON 1

#define LED_GR NRF_GPIO_PIN_MAP(0, 6)
#define LED_R NRF_GPIO_PIN_MAP(0, 8)
#define LED_G NRF_GPIO_PIN_MAP(1, 9)
#define LED_B NRF_GPIO_PIN_MAP(0, 12)

#define ON_LED 0
#define OFF_LED 1

void make_leds_out(void); // инициализация пинов led как выход

void led_on(uint32_t pin); // включение конкретного светодиода

void led_off(uint32_t pin); // выключение светодиода

void all_leds_off(void); // выключение всех светодиодов

uint32_t check_led_status(uint32_t pin); // проверка статуса светодиода

void make_button_in(void); // инициализация пина кнопки как входящего 

uint32_t check_button_status(uint32_t pin); // проверка статуса кнопки


#endif
