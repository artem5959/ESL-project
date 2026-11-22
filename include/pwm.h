
#ifndef PWM_H
#define PWM_H

#define NRF_PWM_VALUES_DUTY_CYCLE_VALUE 11
#define PWM_SEQUENCE_REPEATS 100
#define PWM_SEQUENCE_END_DELAY 0

#define PWM_AUTO NRF_PWM_STEP_AUTO
#define PWM_TRIG NRF_PWM_STEP_TRIGGERED




#include <stdint.h>
#include "leds.h"

#include "nrfx_pwm.h"

#define DEFAULT_HUE ((ID % 100) * 360 / 100)

extern const nrf_pwm_sequence_t seq_hue_modification;
extern const nrf_pwm_sequence_t seq_sat_modification;
extern const nrf_pwm_sequence_t seq_bright_modification;
extern const nrf_pwm_sequence_t no_input_modification;

extern nrf_pwm_values_individual_t duty_cycle_led1[];

extern nrfx_pwm_t pwm0;
extern nrfx_pwm_t pwm1_led_indication;

void pwm_setup(void);// Pwm init



void pwm_stop(void); // Pwm Stop (Main) sequence

void pwm_start_main(void); // Start main pwm sequence

void pwm_start_indication(void); // Start indication pwm sequence

void pwm_stop_indication(void); // Stop indication pwm sequence



#endif

