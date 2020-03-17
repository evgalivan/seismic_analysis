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

#include <global.h>



typedef	signed short			s16_t;
typedef	signed long			s32_t;

typedef struct {
    char sentence_id[7];
    char utc_time[10];
    char status[2];
    char shirota[20];
    char s_or_n[2];
    char dogota[20];
    char w_or_e[2];
    char v_g[10];
    char v_w[10];
    char data[7];
    char xx[4];
    char n[2];
    char m[2];
    char chesum[4];
}gps_rmc;

gps_rmc GPS_RMC, *GPS_rmc;

typedef enum {RMC, VTG, GGA, GSA, GSV, GLL, ERROR} Sentence;

void Strobe ();
void UpdatePeriod(uint32 NewPeriod);
gps_rmc ReadGpsTime(char *gps);
uint32 GpsTimeToInt(char time[]);
uint32 GpsDataToInt(char *data);
Sentence WhatSentence (char *pstr);

/* [] END OF FILE */
