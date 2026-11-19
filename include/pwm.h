
#ifndef PWM_H
#define PWM_H

#define NRF_PWM_VALUES_DUTY_CYCLE_VALUE 11
#define PWM_SEQUENCE_REPEATS 0
#define PWM_SEQUENCE_END_DELAY 0

#define PWM_AUTO NRF_PWM_STEP_AUTO
#define PWM_TRIG NRF_PWM_STEP_TRIGGERED


#include <stdint.h>


void pwm_setup(void);// инициализация pwm и выходов

void configure_pwm(void); 

void pwm_seqtable_set(uint16_t count);

void pwm_start(void);

void pwm_seq_next_step(void);

void pwm_stop(void);

#endif

