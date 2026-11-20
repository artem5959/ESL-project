#include "hsv.h"

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb_t;

typedef struct {
    uint16_t hue_value;        // 0–359
    uint8_t saturation_value;  // 0–100
    uint8_t brightness_value;       // 0–100
} hsv_t;

static rgb_t actual = {0, 0, 0};

static hsv_t hsv = {
    .hue_value = DEFAULT_HUE,
    .saturation_value = 100,
    .brightness_value = 100

};


void hsv_to_rgb(hsv_t hsv_structure, rgb_t *rgb_actual_structure)
{
    uint16_t hue = hsv_structure.hue_value;
    uint8_t sat = hsv_structure.saturation_value;
    uint8_t val = hsv_structure.brightness_value;

    uint8_t sector = hue / 60;
    uint8_t remainder = hue % 60;

    uint16_t p = val * (100 - sat) / 100;
    uint16_t q = val * (100 - sat * remainder / 60) / 100;
    uint16_t t = val * (100 - sat * (60 - remainder) / 60) / 100;

    switch (sector)
    {
        case 0:
            rgb_actual_structure->r = val * 255 / 100;
            rgb_actual_structure->g = t * 255 / 100;
            rgb_actual_structure->b = p * 255 / 100;
            break;

        case 1:
            rgb_actual_structure->r = q * 255 / 100;
            rgb_actual_structure->g = val * 255 / 100;
            rgb_actual_structure->b = p * 255 / 100;
            break;

        case 2:
            rgb_actual_structure->r = p * 255 / 100;
            rgb_actual_structure->g = val * 255 / 100;
            rgb_actual_structure->b = t * 255 / 100;
            break;

        case 3:
            rgb_actual_structure->r = p * 255 / 100;
            rgb_actual_structure->g = q * 255 / 100;
            rgb_actual_structure->b = val * 255 / 100;
            break;

        case 4:
            rgb_actual_structure->r = t * 255 / 100;
            rgb_actual_structure->g = p * 255 / 100;
            rgb_actual_structure->b = val * 255 / 100;
            break;

        default:
            rgb_actual_structure->r = val * 255 / 100;
            rgb_actual_structure->g = p * 255 / 100;
            rgb_actual_structure->b = q * 255 / 100;
            break;
    }
}

void rgb_to_duty_cycle_values(rgb_t *rgb_actual_structure, nrf_pwm_values_individual_t *duty_cycle_ar)
{
    duty_cycle_ar[0].channel_1 = rgb_actual_structure->r;
    duty_cycle_ar[0].channel_2 = rgb_actual_structure->g;
    duty_cycle_ar[0].channel_3 = rgb_actual_structure->b;
}

void hue_modification_one_up(hsv_t *hsv_structure,
                            rgb_t *rgb_actual_structure,
                            nrf_pwm_values_individual_t *duty_cycle_ar)
{
    hsv_structure->hue_value++; // Change Hue value

     if(hsv_structure->hue_value >= 360) {
        hsv_structure->hue_value = 0;
    }

    hsv_to_rgb(*hsv_structure, rgb_actual_structure); // Convert hsv values(hue in this) to rgb actual massive

    rgb_to_duty_cycle_values(rgb_actual_structure, duty_cycle_ar); // write rgb to duty cycle values massive

    
}

void saturation_modification_one_up(hsv_t *hsv_structure,
                            rgb_t *rgb_actual_structure,
                            nrf_pwm_values_individual_t *duty_cycle_ar)
{
    hsv_structure->saturation_value++; // Change saturation value

     if(hsv_structure->saturation_value > 100) {
        hsv_structure->saturation_value = 0;
    }

    hsv_to_rgb(*hsv_structure, rgb_actual_structure); // Convert hsv values(saturation in this) to rgb actual massive

    rgb_to_duty_cycle_values(*rgb_actual_structure, duty_cycle_ar); // write rgb to duty cycle values massive

    
}

void brightness_modification_one_up(hsv_t *hsv_structure,
                            rgb_t *rgb_actual_structure,
                            nrf_pwm_values_individual_t *duty_cycle_ar)
{
    hsv_structure->brightness_value++; // Change saturation value

     if(hsv_structure->brightness_value > 100) {
        hsv_structure->brightness_value = 0;
    }

    hsv_to_rgb(*hsv_structure, rgb_actual_structure); // Convert hsv values(brightness in this) to rgb actual massive

    rgb_to_duty_cycle_values(*rgb_actual_structure, duty_cycle_ar); // write rgb to duty cycle values massive

    
}