#ifndef HSV_H
#define HSV_H

#include <stdint.h>

#include "nrfx_pwm.h"

#define UP 1
#define DOWN 0
typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb_t;

typedef struct {
    uint16_t hue_value;
    uint8_t saturation_value;
    uint8_t brightness_value;
} hsv_t;

extern rgb_t actual;
extern hsv_t hsv;

void hsv_to_rgb(hsv_t hsv_structure, rgb_t *rgb_actual_structure);

void setup_default_hsv(hsv_t *hsv_structure,
                        rgb_t *rgb_actual_structure,
                        nrf_pwm_values_individual_t *duty_cycle_ar);

void rgb_to_duty_cycle_values(rgb_t *rgb_actual_structure,
                            nrf_pwm_values_individual_t *duty_cycle_ar);

void hue_modification_one_up(hsv_t *hsv_structure,
                            rgb_t *rgb_actual_structure,
                            nrf_pwm_values_individual_t *duty_cycle_ar);

void saturation_modification_one_up(hsv_t *hsv_structure,
                            rgb_t *rgb_actual_structure,
                            nrf_pwm_values_individual_t *duty_cycle_ar);

void brightness_modification_one_up(hsv_t *hsv_structure,
                            rgb_t *rgb_actual_structure,
                            nrf_pwm_values_individual_t *duty_cycle_ar);         
                            
                            

#endif