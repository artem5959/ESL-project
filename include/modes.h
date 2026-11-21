#ifndef MODES_H
#define MODES_H

#define NO_INPUT_MODE 0
#define HUE_MODIFICATION 1
#define SAT_MODIFICATION 2
#define BRIGHT_MODIFICATION 3

#define NO_CHANGED 0 
#define CHANGED 1

#include <stdint.h>

extern volatile uint16_t mode;

extern volatile uint16_t mode_flag;

static const uint32_t modes[4] = {NO_INPUT_MODE, HUE_MODIFICATION, SAT_MODIFICATION, BRIGHT_MODIFICATION};

void mode_handler(void);

void hue_modification_mode_on(void);

void sat_modification_mode_on(void);

void brightness_modification_mode_on(void);

void no_input_mode_on(void);

#endif
