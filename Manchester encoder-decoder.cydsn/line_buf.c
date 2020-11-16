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
#include <line_buf.h>

uint32 line_buf[PACKET_LENGTH + 4];
volatile uint32* current_write = line_buf;
volatile uint32* current_read = line_buf;
volatile uint8 flag_read_done = 0, flag_write_done = 0;



/* [] END OF FILE */
