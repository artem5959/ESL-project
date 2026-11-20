
#ifndef PWM_H
#define PWM_H

#define NRF_PWM_VALUES_DUTY_CYCLE_VALUE 11
#define PWM_SEQUENCE_REPEATS 100
#define PWM_SEQUENCE_END_DELAY 0

#define PWM_AUTO NRF_PWM_STEP_AUTO
#define PWM_TRIG NRF_PWM_STEP_TRIGGERED




#include <stdint.h>
#include "leds.h"

#define DEFAULT_HUE ((ID % 100) * 360 / 100)


void pwm_setup(void);// инициализация pwm и выходов


void pwm_start(void);

void pwm_stop(void);

void pwm_start_main(void);

void pwm_start_indication(void);

void pwm_stop_indication(void);



#endif

