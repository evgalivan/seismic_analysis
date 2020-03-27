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
#include <project.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* strtok_e(char* pstr1, const char* pstr2);

extern uint32 incr_compare;
extern long long utc_time;
extern long long pps_time;
extern uint32 capture_flag; 
extern uint32 value_sec_gps, value_usec_gps;
extern uint32 UnixTime1, time_ready_flag;
extern uint8 GlobalPrepareFlag;
extern int delta_clock;
extern volatile long long period;
extern uint32 * p_ex_buf;



/* [] END OF FILE */
