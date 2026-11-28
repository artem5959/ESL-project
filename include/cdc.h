#ifndef CDC_H
#define CDC_H
#include <stdbool.h>
#include <stdint.h>

#include "nordic_common.h"

#include "log.h"
#include "app_usbd_cdc_acm.h"


#define READ_SIZE 1


extern char m_rx_buffer[READ_SIZE];


extern void usb_ev_handler(app_usbd_class_inst_t const * p_inst,
                           app_usbd_cdc_acm_user_event_t event);

void cdc_init(void);


                            



#endif