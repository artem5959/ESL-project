#ifndef MODES_H
#define MODES_H

#define NO_INPUT_MODE 0
#define HUE_MODIFICATION 1
#define SAT_MODIFICATION 2
#define BRIGHT_MODIFICATION 3

#define NO_CHANGED 0 
#define CHANGED 1

#include <stdint.h>

extern volatile uint16_t mode; // use only 0 - 3 values NO_INPUT_MODE 
//                              HUE_MODIFICATION SAT_MODIFICATION BRIGHT_MODIFICATION 

extern volatile uint16_t mode_flag; // use only NO_CHANGED or CHANGED value

static const uint32_t modes[4] = {NO_INPUT_MODE, HUE_MODIFICATION, SAT_MODIFICATION, BRIGHT_MODIFICATION};

/*This function reads the value of the variable mode and runs one of the corresponding 
functions for the corresponding modes.*/
void mode_handler(void); // Mode handler , use with "mode_flag" ,if mode flag == CHANGED, 
/**/                    // (not use in IRQ function)


/*FUNCTIONS FOR THE SAME MODES*/
void hue_modification_mode_on(void); // Hue modifcitaion function - on hue modifcation mode 

void sat_modification_mode_on(void); // Saturation modifcitaion function - on sat modifcation mode 

void brightness_modification_mode_on(void); // Brightness modifcitaion function - on sat modifcation mode 

void no_input_mode_on(void); // No input mode function 
/**/

#endif
