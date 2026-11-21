
// pwm

#include "pwm.h"
#include "nrfx_pwm.h"
#include "log.h"


nrfx_pwm_t pwm0 = NRFX_PWM_INSTANCE(0);
nrfx_pwm_t pwm1_led_indication = NRFX_PWM_INSTANCE(1);

//static nrfx_pwm_config_t config1 = NRFX_PWM_DEFAULT_CONFIG;


static nrfx_pwm_config_t config1 = {
    .output_pins = {
        31,
        LED_R,
        LED_G,
        LED_B
    },
    .irq_priority = 6,
    .base_clock = NRF_PWM_CLK_1MHz,
    .count_mode = NRF_PWM_MODE_UP,
    .top_value = 255,
    .load_mode = NRF_PWM_LOAD_INDIVIDUAL,
    .step_mode = NRF_PWM_STEP_AUTO
};

static nrfx_pwm_config_t config2 = {
    .output_pins = {
        LED_GR,
        31,
        31,
        31
    },
    .irq_priority = 6,
    .base_clock = NRF_PWM_CLK_1MHz,
    .count_mode = NRF_PWM_MODE_UP,
    .top_value = 255,
    .load_mode = NRF_PWM_LOAD_INDIVIDUAL,
    .step_mode = NRF_PWM_STEP_AUTO
};


uint32_t pins[LEDS_NUMBER] = { LED_GR, LED_R, LED_G, LED_B };

static nrf_pwm_values_individual_t duty_cycle_led_gr1[] = {
    {0, 0, 0, 0}, 
    {50, 0, 0, 0}, 
    {100, 0, 0, 0}, 
    {150, 0, 0, 0}, 
    {200, 0, 0, 0}, 
    {255, 0, 0, 0}, 
    {200, 0, 0, 0}, 
    {150, 0, 0, 0}, 
    {100, 0, 0, 0}, 
    {50, 0, 0, 0}, 
    {0, 0, 0, 0}, 
};

static nrf_pwm_values_individual_t duty_cycle_led_gr2[] = {
    {255, 0, 0, 0}
};

nrf_pwm_values_individual_t duty_cycle_led1[] = {
    {0, 0, 0, 0}
};


static const nrf_pwm_sequence_t seq1 = {
    .values.p_individual = duty_cycle_led1,
    .length = NRF_PWM_VALUES_LENGTH(duty_cycle_led1),
    .repeats = 100,
    .end_delay = 0,
};

const nrf_pwm_sequence_t seq_hue_modification = {
    .values.p_individual = duty_cycle_led_gr1,
    .length = NRF_PWM_VALUES_LENGTH(duty_cycle_led_gr1),
    .repeats = 100,
    .end_delay = 0,
};

const nrf_pwm_sequence_t seq_sat_modification = {
    .values.p_individual = duty_cycle_led_gr1,
    .length = NRF_PWM_VALUES_LENGTH(duty_cycle_led_gr1),
    .repeats = 50,
    .end_delay = 0,
};

const nrf_pwm_sequence_t seq_bright_modification = {
    .values.p_individual = duty_cycle_led_gr2,
    .length = NRF_PWM_VALUES_LENGTH(duty_cycle_led_gr2),
    .repeats = 100,
    .end_delay = 0,
};


void pwm_setup(void) {

    nrfx_pwm_init(&pwm0, &config1, NULL);
    nrfx_pwm_init(&pwm1_led_indication, &config2, NULL);

    NRF_LOG_INFO("PWM init");

}


void pwm_start_main(void)
{
nrfx_pwm_simple_playback(&pwm0, &seq1, 6, NRFX_PWM_FLAG_LOOP);

NRF_LOG_INFO("PWM main seq started");
}

void pwm_start_indication(void)
{
nrfx_pwm_simple_playback(&pwm1_led_indication, &seq_hue_modification, 6, NRFX_PWM_FLAG_LOOP);

NRF_LOG_INFO("PWM indication seq started");
}

void pwm_stop(void)
{
  nrfx_pwm_stop(&pwm0, true);
  NRF_LOG_INFO("PWM main seq stopped");

}

void pwm_stop_indication(void)
{
  nrfx_pwm_stop(&pwm1_led_indication, true);
  NRF_LOG_INFO("PWM indication seq stopped");

}








//nrfx_pwm_sequence_update(&pwm0, 0, &seq1);
//nrfx_pwm_sequence_values_update(&pwm0, 0, duty_cycle_led1);
/*
void modifications_start (void);
{
pwm_start_indication();

while(true){

if(mode == HUE_MODIFICATION){  
    nrfx_pwm_sequence_update(&pwm1, 0, &seq_hue_modification); 
    while (mode == HUE_MODIFICATION) {
        while(BUTTON_STATUS == PRESSED) {
            hue_modification_one_up();
            nrfx_pwm_sequence_values_update(&pwm0, 0, duty_cycle_led1);  // update sequense
        }
    }
  
}   


if(mode == SAT_MODIFICATION){
    saturation_modification_one_up();
    nrfx_pwm_sequence_values_update(&pwm0, 0, duty_cycle_led1);
    nrfx_pwm_sequence_update(&pwm1, 0, &seq_sat_modification);

}

if(mode == BRIGHT_MODIFICATION){

    brightness_modification_one_up_modification_one_up();
    nrfx_pwm_sequence_values_update(&pwm0, 0, duty_cycle_led1);
    nrfx_pwm_sequence_update(&pwm1, 0, &seq_bright_modification)
}

if(mode == NO_INPUT_MODE){
    pwm_stop_indication();
    return;
}
}
}


*/