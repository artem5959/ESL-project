
// pwm

#include "pwm.h"
#include "nrfx_pwm.h"
#include "leds.h"
#include "log.h"


static nrfx_pwm_t pwm0 = NRFX_PWM_INSTANCE(0);

static nrfx_pwm_config_t config1 = NRFX_PWM_DEFAULT_CONFIG(1000, 25);

uint32_t pins[LEDS_NUMBER] = { LED_GR, LED_R, LED_G, LED_B };

static nrf_pwm_values_individual_t duty_cycle_led0[NRF_PWM_VALUES_DUTY_CYCLE_VALUE] = {
    {0, 0, 0, 0}, {200, 0, 0, 0}, {400, 0, 0, 0},  {600, 0, 0, 0}, {800, 0, 0, 0},  {1000, 0, 0, 0}, 
    {800, 0, 0, 0}, {600, 0, 0, 0}, {400, 0, 0, 0},  {200, 0, 0, 0}, {0, 0, 0, 0}
};

static nrf_pwm_values_individual_t duty_cycle_led1[NRF_PWM_VALUES_DUTY_CYCLE_VALUE] = {
    {0, 0, 0, 0}, {0, 200, 0, 0}, {0, 400, 0, 0},  {0, 600, 0, 0}, {0, 800, 0, 0},  {0, 1000, 0, 0}, 
    {0, 800, 0, 0}, {0, 600, 0, 0}, {0, 400, 0, 0},  {0, 200, 0, 0}, {0, 0, 0, 0}
};

static nrf_pwm_values_individual_t duty_cycle_led2[NRF_PWM_VALUES_DUTY_CYCLE_VALUE] = {
    {0, 0, 0, 0}, {0, 0, 200, 0}, {0, 0, 400, 0}, {0, 0, 600, 0}, {0, 0, 800, 0}, {0, 0, 1000, 0},
    {0, 0, 800, 0}, {0, 0, 600, 0}, {0, 0, 400, 0}, {0, 0, 200, 0}, {0, 0, 0, 0}
};

static nrf_pwm_values_individual_t duty_cycle_led3[NRF_PWM_VALUES_DUTY_CYCLE_VALUE] = {
    {0, 0, 0, 0}, {0, 0, 0, 200}, {0, 0, 0, 400}, {0, 0, 0, 600}, {0, 0, 0, 800}, {0, 0, 0, 1000},
    {0, 0, 0, 800}, {0, 0, 0, 600}, {0, 0, 0, 400}, {0, 0, 0, 200}, {0, 0, 0, 0}
};

static nrf_pwm_values_individual_t *const duty_cycle_leds[LEDS_NUMBER] = {
    duty_cycle_led0, duty_cycle_led1, duty_cycle_led2, duty_cycle_led3, 
};

static const nrf_pwm_sequence_t seq1 = {
    .values.p_individual = duty_cycle_led0,
    .length = NRF_PWM_VALUES_LENGTH(duty_cycle_led0),
    .repeats = 100,
    .end_delay = PWM_SEQUENCE_END_DELAY,
};


void pwm_setup(void) {

    nrfx_pwm_init(&pwm0, &config1, NULL);

    NRF_LOG_INFO("PWM init");

}


void pwm_start(void)
{
nrfx_pwm_simple_playback(&pwm0, &seq1, 6, NRFX_PWM_FLAG_STOP);

NRF_LOG_INFO("PWM seq started");
}

void pwm_stop(void)
{
  nrfx_pwm_stop(&pwm0, true);
  NRF_LOG_INFO("PWM seq stopped");

}


