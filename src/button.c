#include "button.h"
#include "nrfx_gpiote.h"
#include "nrf_gpio.h"
#include "app_timer.h"
#include "nrf_drv_clock.h"
#include "app_error.h"
#include "log.h"
#include "modes.h"

APP_TIMER_DEF(debounce_timer);
APP_TIMER_DEF(double_click_timer);
APP_TIMER_DEF(button_pressed_timer);






void event_handler(event_t event)
{
    switch (event)
    {
        case EVENT_DOUBLE_CLICK:
            mode++;
            NRF_LOG_INFO("MODE CHANGED");
            if(mode > BRIGHT_MODIFICATION) {
                mode = NO_INPUT_MODE;
            }
            mode_flag = CHANGED;
            break;

        case EVENT_BUTTON_PRESSED:
            button_status = PRESSED;
            NRF_LOG_INFO("BUTTON PRESSED");
            break;
    }
}


void make_button_in(void){

    nrf_gpio_cfg_input(BUTTON_PIN, NRF_GPIO_PIN_PULLUP);

}

uint32_t check_button_status(uint32_t pin){
    if (nrf_gpio_pin_read(pin) == ON_BUTTON)
    return ON_BUTTON; //  return 0


    return OFF_BUTTON; // return 1
}

uint16_t check_mode_status(void){
   return mode;
}


volatile uint16_t button_status = OFF_BUTTON;

volatile uint16_t button_clics = 0;

volatile uint16_t on_off_status = OFF_STATUS;

volatile uint16_t debounce_flag = 0;

void clocks_and_timers_init(void)
{
    nrf_drv_clock_init();
    nrf_drv_clock_lfclk_request(NULL);
    while (!nrf_drv_clock_lfclk_is_running()) {}
    app_timer_init();
    NRF_LOG_INFO("clock and timers init");
}

void reset_button_count(void){
    button_clics = 0;
}

static void double_click_handler(void * p_context)
{
    button_clics = 0;
}

static void button_pressed_handler(void * p_context)
{
    if (check_button_status(BUTTON_PIN) == ON_BUTTON) {
        event_handler(EVENT_BUTTON_PRESSED);
        //NRF_LOG_INFO("EVENT: BUTTON PRESSED");
    }
}

static void debounce_handler(void * p_context)
{
    button_status = check_button_status(BUTTON_PIN);
    //NRF_LOG_INFO("BUTTON STATUS = ON BUTTON");

    if (button_status != ON_BUTTON) return; 

    if(button_status == ON_BUTTON && button_clics < 2) {
        button_clics++;
       // NRF_LOG_INFO("First click");
        }

    if (button_clics == 1){
        app_timer_start(double_click_timer, APP_TIMER_TICKS(400), NULL);
        app_timer_start(button_pressed_timer, APP_TIMER_TICKS(1000), NULL);
        //NRF_LOG_INFO("double click timer start");
        //NRF_LOG_INFO("button pressed timer start");
        
    }

    if(button_clics == 2){

        app_timer_stop(double_click_timer);
        app_timer_stop(button_pressed_timer);
        button_clics = 0;

        event_handler(EVENT_DOUBLE_CLICK);

        //NRF_LOG_INFO("Double click");
    }

}


static void button_func(nrfx_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{   
    //NRF_LOG_INFO("Start irq func");
    button_status = check_button_status(BUTTON_PIN);
    if(button_status == ON_BUTTON) {
    app_timer_start(debounce_timer, APP_TIMER_TICKS(50), NULL);
    //NRF_LOG_INFO("debounce timer started");
    }
    //else NRF_LOG_INFO("BUTTON STATUS = OFF BUTTON");

    //NRF_LOG_INFO("End irq func")

}

void gpiote_setup(void)
{


nrfx_gpiote_init();

nrfx_gpiote_in_config_t cfg = NRFX_GPIOTE_CONFIG_IN_SENSE_TOGGLE(false);
cfg.pull = NRF_GPIO_PIN_PULLUP;

nrfx_gpiote_in_init(BUTTON_PIN, &cfg, button_func);

app_timer_create(&debounce_timer, APP_TIMER_MODE_SINGLE_SHOT, debounce_handler);

app_timer_create(&double_click_timer, APP_TIMER_MODE_SINGLE_SHOT, double_click_handler);

app_timer_create(&button_pressed_timer, APP_TIMER_MODE_SINGLE_SHOT, button_pressed_handler);

NRF_LOG_INFO("GPIOTE init");
}

void irq_on(void)
{
nrfx_gpiote_in_event_enable(BUTTON_PIN, true);
NRF_LOG_INFO("irq on");
}

void irq_off(void)
{
nrfx_gpiote_in_event_enable(BUTTON_PIN, false);
NRF_LOG_INFO("irq off");
}