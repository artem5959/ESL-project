#ifndef ESL_BUTTON_H
#define ESL_BUTTON_H

#include <stdint.h>



#define BUTTON_PIN NRF_GPIO_PIN_MAP(1, 6)

#define ON_BUTTON 0
#define PRESSED 0
#define OFF_BUTTON 1

#define ON_STATUS 0
#define OFF_STATUS 1





extern volatile uint16_t button_status;



extern volatile uint16_t on_off_status;

typedef enum
{
    EVENT_DOUBLE_CLICK,
    EVENT_BUTTON_PRESSED
} event_t;



void mode_handler(void);

void event_handler(event_t event);

void make_button_in(void); // инициализация пина кнопки как входящего 

uint32_t check_button_status(uint32_t pin); // проверка статуса кнопки

void clocks_and_timers_init(void);

void gpiote_setup(void);

void irq_on(void);

void irq_off(void);

#endif