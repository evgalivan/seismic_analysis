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
#include <Clock.h>

#define _TBIAS_DAYS		((70 * (uint32)365) + 17)
#define _TBIAS_SECS		(_TBIAS_DAYS * (s32_t)86400)
#define	_TBIAS_YEAR		1900
#define MONTAB(year)		((((year) & 03) || ((year) == 0)) ? mos : lmos)

const s16_t	lmos[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
const s16_t	mos[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

#define	Daysto32(year, mon)	(((year - 1) / 4) + MONTAB(year)[mon])


void Strobe () {
    Control_Period_Write(1);
    while ((Status_Period_Read()&1) == 0);
    Control_Period_Write(0);
    while ((Status_Period_Read()&1) != 0);
}

void UpdatePeriod(uint32 NewPeriod) {
    Period_WriteData(NewPeriod);
    Strobe();
}

gps_rmc ReadGpsTime(char *gps)
{
                GPS_rmc = &GPS_RMC;
                char *pstrtmp;
                pstrtmp = strtok_e (gps, ",");
                strcpy(GPS_rmc->sentence_id, pstrtmp);
                pstrtmp = strtok_e (NULL, ",");
                strcpy(GPS_rmc->utc_time, pstrtmp);
                pstrtmp = strtok_e (NULL, ",");
                strcpy(GPS_rmc->status, pstrtmp);
                pstrtmp = strtok_e (NULL, ",");
                strcpy(GPS_rmc->shirota, pstrtmp);
                pstrtmp = strtok_e (NULL, ",");
                strcpy(GPS_rmc->s_or_n, pstrtmp);
                pstrtmp = strtok_e (NULL, ",");
                strcpy(GPS_rmc->dogota, pstrtmp);
                pstrtmp = strtok_e (NULL, ",");
                strcpy(GPS_rmc->w_or_e, pstrtmp);
                pstrtmp = strtok_e (NULL, ",");
                strcpy(GPS_rmc->v_g, pstrtmp);
                pstrtmp = strtok_e (NULL, ",");
                strcpy(GPS_rmc->v_w, pstrtmp);
                pstrtmp = strtok_e (NULL, ",");
                strcpy(GPS_rmc->data, pstrtmp);
                pstrtmp = strtok_e (NULL, ",");
                strcpy(GPS_rmc->xx, pstrtmp);
                pstrtmp = strtok_e (NULL, ",");
                strcpy(GPS_rmc->n, pstrtmp);
                pstrtmp = strtok_e (NULL, "*");
                strcpy(GPS_rmc->m, pstrtmp);
                pstrtmp = strtok_e (NULL, "\r");
                strcpy(GPS_rmc->chesum, pstrtmp);
                return GPS_RMC;
}    

uint32 GpsTimeToInt(char *time)
{
    uint32 Int;
    int gpstime = atoi(time);
    int hour = gpstime/10000;
    int minute = (gpstime - hour*10000)/100; 
    //minute = (*(time+2))*10 + (*(time+3));
    int second = (gpstime - hour*10000 - minute*100);
    //second = (*(time+4))*10 + (*(time+5));
    int milisec = 0;
    //milisec = (*(time+7))*100 + (*(time+8))*10;
    /* Calculate number of seconds. */
	Int  = 3600 * hour;
	Int += 60 * minute;
	Int += second;
    return Int;
}

uint32 GpsDataToInt(char *data)
{
    s32_t		days;
    uint32		secs;
    s32_t		mon, year;
    
    uint32 Int;
    int gpsdata = atoi(data);
    int day = gpsdata/10000;
    int mounth = (gpsdata - day*10000)/100; 
    //minute = (*(time+2))*10 + (*(time+3));
    int year_gps = (gpsdata - day*10000 - mounth*100);

	/* Calculate number of days. */
	mon = mounth - 1;
	year = 2000 + year_gps - _TBIAS_YEAR;
	days  = Daysto32(year, mon) - 1;
	days += 365 * year;
	days += day;
	days -= _TBIAS_DAYS;
	secs += (days * (uint32)86400);
	return (secs);
}

Sentence WhatSentence (char *pstr)
{
    Sentence gps_sentence;
    if (strncmp(pstr, "$GPRMC", 6) == 0) 
    {
        gps_sentence = RMC;
        return gps_sentence;
    }
    
    if (strncmp(pstr, "$GPVTG", 6) == 0) 
    {
        gps_sentence = VTG;
        return gps_sentence;
    }
    
    if (strncmp(pstr, "$GPGGA", 6) == 0) 
    {
        gps_sentence = GGA;
        return gps_sentence;
    }
    
    if (strncmp(pstr, "$GPGSA", 6) == 0) 
    {
        gps_sentence = GSA;
        return gps_sentence;
    }
    if (strncmp(pstr, "$GPGSV", 6) == 0) 
    {
        gps_sentence = GSV;
        return gps_sentence;
    }
    if (strncmp(pstr, "$GPGLL", 6) == 0) 
    {
        gps_sentence = GLL;
        return gps_sentence;
    }
    return ERROR;
}

uint32 UnixToCountSec(uint32 time_stamp){
    long long _time_stamp;
    uint32 sec_count;
    sec_count = ((long long)time_stamp * 1000) >> 14;
    return sec_count;
}

uint32 UnixToCountuSec(uint32 time_stamp){
    long long _time_stamp;
    uint32 usec_count;
    usec_count = ((long long)time_stamp * 1000) - (UnixToCountSec(time_stamp) << 14);    
    usec_count <<= usec_counter_Resolution - 14u;
    return usec_count;
}

void SetupSpeedInternalClock (int delta){
    long long Speed;
    Speed = period + 2*delta;
    UpdatePeriod(Speed);
}

/* [] END OF FILE */
