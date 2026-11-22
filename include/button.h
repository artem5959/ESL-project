#ifndef ESL_BUTTON_H
#define ESL_BUTTON_H

#include <stdint.h>



#define BUTTON_PIN NRF_GPIO_PIN_MAP(1, 6)

#define ON_BUTTON 0
#define OFF_BUTTON 1
#define PRESSED 2

#define ON_STATUS 0
#define OFF_STATUS 1





extern volatile uint16_t button_status; // Status of Button - 0 - 2
                                        // (ON_BUTTON, OFF_BUTTON, PRESSED)

extern volatile uint16_t on_off_status;

typedef enum
{
    EVENT_DOUBLE_CLICK, // Event - double click of button - change "mode" value (+1)
    EVENT_BUTTON_PRESSED // Event - Button pressed - change status of "button_status"
} event_t; // Type of Events 




/*
This function reads events such as double-click or pressed button and triggers 
the corresponding changes or sets flags or changes the status of variables.*/
void event_handler(event_t event);
/**/

uint32_t check_button_status(uint32_t pin); // проверка статуса кнопки

/*INIT FUNCS*/
void make_button_in(void); 

void clocks_and_timers_init(void); 

void gpiote_setup(void);

void irq_on(void);

void irq_off(void);
/**/

#endif