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
#ifndef uint32 
    #include "cytypes.h"
#endif

#define PACKET_LENGTH (44)

extern uint32 line_buf[];
extern volatile uint32 *current_write;
extern volatile uint32 *current_read;
extern volatile uint8 flag_read_done, flag_write_done;


/* [] END OF FILE */
