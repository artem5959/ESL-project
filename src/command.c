#include "command.h"
#include "hsv.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "log.h"
#include "pwm.h"

char command_buff[COMMAND_BUFF_SIZE];

char return_buffer[RETURN_BUFFER_SIZE];

void clear_command_buff(char*com_buff)
{
    for (uint16_t i = 0; i < COMMAND_BUFF_SIZE ; i++)
        com_buff[i] = '\0';
}

void send_commands(char*com_buff)
{
    unsigned int r, g, b;

    unsigned int h, s, v;

    if (sscanf(com_buff, "RGB %u %u %u", &r, &g, &b) == 3)
    {
        if(r > 255 || g > 255 || b > 255) {
            NRF_LOG_INFO("ERROR - RGB VALUES ");
            return;
        }
        rgb_set(&actual, r, g, b, &hsv, duty_cycle_led1);
        hsv_to_flash_write(&hsv);
        snprintf(return_buffer, sizeof(return_buffer),

         "Color set to R=%u G=%u B=%u\r\n", r, g, b);

        return;


        
    }

    if (sscanf(com_buff, "HSV %u %u %u", &h, &s, &v) == 3)
    {

        if (h > 360 || s > 100 || v > 100) {
            NRF_LOG_INFO("ERROR - HSV VALUES ");
            return;
        }


        hsv_set(&hsv , h, s, v, &actual, duty_cycle_led1);
        hsv_to_flash_write(&hsv);
        snprintf(return_buffer, sizeof(return_buffer),
         "Color set to H=%u S=%u V=%u\r\n",
         h, s, v);

        return;

    }

}
