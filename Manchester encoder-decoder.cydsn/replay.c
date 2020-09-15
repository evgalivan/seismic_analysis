/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "global.h"

static char replay_msg[256];

int replay(void){
    if (usb_context.need_to_send) return 0;
    sprintf(replay_msg, "\n\r REPLAY MESSAGE \n");
    usb_context.count_to_send = strlen(replay_msg);
    usb_context.message_to_send = (uint8*)replay_msg;
    return usb_context.need_to_send = 1;
}

/* [] END OF FILE */
