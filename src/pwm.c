
// pwm

#include "pwm.h"
#include "nrf_pwm.h"
#include "leds.h"
#include "log.h"

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
    .repeats = PWM_SEQUENCE_REPEATS,
    .end_delay = PWM_SEQUENCE_END_DELAY,
};


void pwm_setup(void) {

    nrf_pwm_enable(NRF_PWM0);

    nrf_pwm_pins_set(NRF_PWM0, pins);

    NRF_LOG_INFO("PWM init");

}


void configure_pwm(void) {

    nrf_pwm_configure(NRF_PWM0, NRF_PWM_CLK_1MHz, NRF_PWM_MODE_UP, 1000);

    nrf_pwm_decoder_set(NRF_PWM0, NRF_PWM_LOAD_INDIVIDUAL, PWM_TRIG);

    nrf_pwm_sequence_set(NRF_PWM0, 0, &seq1);

    NRF_LOG_INFO("PWM config");

}

void pwm_seqtable_set(uint16_t count)
{
nrf_pwm_seq_ptr_set(NRF_PWM0, 0, (uint16_t const *)duty_cycle_leds[count]);
//nrf_pwm_seq_ptr_set(NRF_PWM0, 1, (uint16_t const *)duty_cycle_leds[count]);
}

void pwm_start(void)
{
nrf_pwm_task_trigger(NRF_PWM0, NRF_PWM_TASK_SEQSTART0);

NRF_LOG_INFO("PWM seq started");
}

void pwm_seq_next_step(void)
{
    nrf_pwm_task_trigger(NRF_PWM0, NRF_PWM_TASK_NEXTSTEP);
}

void pwm_stop(void)
{
    nrf_pwm_task_trigger(NRF_PWM0, NRF_PWM_TASK_STOP);


    while (!nrf_pwm_event_check(NRF_PWM0, NRF_PWM_EVENT_STOPPED))

    {

    }

    nrf_pwm_event_clear(NRF_PWM0, NRF_PWM_EVENT_STOPPED);

    NRF_LOG_INFO("PWM seq stopped");

}