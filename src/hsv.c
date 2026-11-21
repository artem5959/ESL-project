#include "hsv.h"
#include "pwm.h"
#include <math.h>


rgb_t actual = {0, 0, 0};

hsv_t hsv = {
    .hue_value = DEFAULT_HUE,
    .saturation_value = 100,
    .brightness_value = 100

};


void hsv_to_rgb(hsv_t hsv_structure, rgb_t *rgb_actual_structure)
{
    float h = hsv_structure.hue_value;
    float s = hsv_structure.saturation_value / 100.0f;
    float v = hsv_structure.brightness_value / 100.0f;

    float c = v * s;
    float x = c * (1.0f - fabsf(fmodf(h / 60.0f, 2.0f) - 1.0f));
    float m = v - c;

    float r = 0.0f;
    float g = 0.0f;
    float b = 0.0f;

    if (h < 60.0f)
    {
        r = c;
        g = x;
        b = 0.0f;
    }
    else if (h < 120.0f)
    {
        r = x;
        g = c;
        b = 0.0f;
    }
    else if (h < 180.0f)
    {
        r = 0.0f;
        g = c;
        b = x;
    }
    else if (h < 240.0f)
    {
        r = 0.0f;
        g = x;
        b = c;
    }
    else if (h < 300.0f)
    {
        r = x;
        g = 0.0f;
        b = c;
    }
    else
    {
        r = c;
        g = 0.0f;
        b = x;
    }

    rgb_actual_structure->r = (uint8_t)((r + m) * 255.0f);
    rgb_actual_structure->g = (uint8_t)((g + m) * 255.0f);
    rgb_actual_structure->b = (uint8_t)((b + m) * 255.0f);
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

    rgb_to_duty_cycle_values(rgb_actual_structure, duty_cycle_ar); // write rgb to duty cycle values massive

    
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

    rgb_to_duty_cycle_values(rgb_actual_structure, duty_cycle_ar); // write rgb to duty cycle values massive

    
}