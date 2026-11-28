#ifndef HSV_H
#define HSV_H

#include <stdint.h>

#include "nrfx_pwm.h"
#include "nrfx_nvmc.h"

#define HSV_FLASH_ADDRESS 0x80000
#define WRITTEN_FLAG 0xA5B6C7D8

#define UP 1
#define DOWN 0

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb_t; // Structure rgb for pwm 

typedef struct {
    uint16_t hue_value;
    uint8_t saturation_value;
    uint8_t brightness_value;
} hsv_t; // Structure hsv for read and write hsv values

extern rgb_t actual;
extern hsv_t hsv;


void setup_default_hsv(hsv_t *hsv_structure,
                        rgb_t *rgb_actual_structure,
                        nrf_pwm_values_individual_t *duty_cycle_ar); // setup default values use
                                                                    // in start program


/*CONVERTATION FUNCS*/
void hsv_to_rgb(hsv_t hsv_structure, rgb_t *rgb_actual_structure); // Convertation hsv structure
                                                                    // to rgb structure

void rgb_to_hsv(rgb_t rgb_structure, hsv_t *hsv_actual_structure); // Convertation rgb structure
                                                                    // to hsv structure

void rgb_to_duty_cycle_values(rgb_t *rgb_actual_structure,
                            nrf_pwm_values_individual_t *duty_cycle_ar); // convertation rgb struct
                                                                        // to duty cycle vlues  massive

bool hsv_to_flash_write(hsv_t *hsv_structure); // Write Values of hsv to FLASH 
                                            //  on HSV_FLASH_ADDRESS adress and on WRITTEN_FLAG      

void flash_values_to_hsv(hsv_t *hsv_structure);  // Write flash values to hsv     


void rgb_set(rgb_t *rgb_actual_structure, int r, int g, int b,
                            hsv_t *hsv_structure,
                    nrf_pwm_values_individual_t *duty_cycle_ar);

void hsv_set(hsv_t *hsv_structure, int h ,int s, int v, 
                            rgb_t *rgb_actual_structure,
                        nrf_pwm_values_individual_t *duty_cycle_ar);
/**/


/*HSV VALUES MODIFICATION FUNCS*/
void hue_modification_one_up(hsv_t *hsv_structure,                       //functions for up +1 value of hsv
                            rgb_t *rgb_actual_structure,                 //
                            nrf_pwm_values_individual_t *duty_cycle_ar); //
                                                                         //  
                                                                         // and write values for pwm duty-
void saturation_modification_one_up(hsv_t *hsv_structure,               //
                            rgb_t *rgb_actual_structure,                //
                            nrf_pwm_values_individual_t *duty_cycle_ar); // cycle values massive (include hsv_to_rgb 
                                                                        //
void brightness_modification_one_up(hsv_t *hsv_structure,               //
                            rgb_t *rgb_actual_structure,                //
                            nrf_pwm_values_individual_t *duty_cycle_ar);//and gb_to_duty_cycle_values fucntions)       
/**/                            
                            

#endif