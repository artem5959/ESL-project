
#ifndef PWM_H
#define PWM_H

#include <stdint.h>


void pwm_setup(void);// инициализация pwm и выходов

void configure_pwm(void); 

void pwm_seqtable_set(uint16_t count);

void pwm_start(void);

void pwm_seq_next_step(void);

void pwm_stop(void);

#endif

