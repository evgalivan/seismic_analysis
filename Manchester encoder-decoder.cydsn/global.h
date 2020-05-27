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
#ifndef GLOBAL_H
    #define GLOBAL_H
    
#ifndef uint32 
    #include <project.h>
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum Regim {DUMMY, TIME_STMP, ADDR_SET1, ADDR_SET2, ADDR_SET3, ADDR_SET4};
char* strtok_e(char* pstr1, const char* pstr2);
void Load(void);
void GeneralSend(enum Regim);

extern uint32 dummy_massage[];
extern uint32 time_stmp_buf[];
extern uint32 addr_set_buf[];
extern uint32 selected_buf[];
extern uint32 incr_compare;
extern long long utc_time;
extern long long pps_time;
extern uint32 capture_flag; 
extern uint32 value_sec_gps, value_usec_gps;
extern uint32 UnixTime1, time_ready_flag;
extern uint8 GlobalPrepareFlag, GlobalTimeReady;
extern int delta_clock;
extern volatile long long period;
extern uint32 * p_ex_buf;
extern uint32 time_stamp_low, time_stamp_high, time_comp_ready_flag;

#endif

/* [] END OF FILE */
