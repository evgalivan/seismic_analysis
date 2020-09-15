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
#include <stdio_e.h>
#include <string.h>
#include <stdlib.h>
#include <frame.h>

#define RING_SIZE 64
#define IN_RING( B)  if (++(B)>=RING_SIZE)(B) -= RING_SIZE
#define LENGTH_OF(Array) (sizeof(Array)/sizeof(Array[0]))

typedef enum {WAITINGOFDOLLAR, WAITINGOFSTAR, WAITINGOFCHSUM, WAITINGOFCHSUM2} State;

typedef struct{
    uint8 buf[RING_SIZE];
    uint8 begin;
    uint8 end;
}RingBuff_t;

typedef struct{    
    RingBuff_t primary_buf;
    uint8 sentence[256];
    uint16 length;
    State state;
    uint16 count_char;
    uint16 checksum;
    uint8 sentence_ready;
    uint8* message_to_send;
    uint8 need_to_send;
    uint16 count_to_send;

} uart_context;

extern uart_context usb_context;


typedef struct {
    uint16 chanel;
    uint16 port;
    char multicast[4];
    char unicast[4];
    char mac[6];
}ip_set;

extern ip_set IP_Complete;

typedef struct {
    uint32 MacMiLo:8;
    uint32 MacMiHi:8;
    uint32 MacHiLo:8;
    uint32 MacHiHi:8;
    uint32 port:16;
    uint32 MacLoLo:8;
    uint32 MacLoHi:8;
    uint32 UniLoLo:8;
    uint32 UniLoHi:8;
    uint32 UniHiLo:8;
    uint32 UniHiHi:8;
    uint32 MulLoLo:8;
    uint32 MulLoHi:8;
    uint32 MulHiLo:8;
    uint32 MulHiHi:8;
}frame_recount;

typedef struct {
    uint32 Period_1024K:24;
    uint32 Frame_tag:8;
    uint32 Correction_72M:24;
    uint32 CRC_8:8;
    uint32 Seconds:32;
    uint32 Parts:24;
    uint32 :8;
}time_format;

typedef struct {
    uint32 Setting_1:24;
    uint32 Frame_tag:8;
    uint32 Setting_2:24;
    uint32 CRC_8:8;
    uint32 Setting_3:32;
    uint32 Setting_4:24;
    uint32 :8;
}tune_format;

typedef union {
    frame_t item;
    time_format pattern;
}time_stamp;

typedef union {
    frame_t item;
    frame_recount pattern;
}renumber;

typedef union {
    frame_t item;
    tune_format pattern;
}setting;




extern uint32 incr_compare;
extern long long utc_time;
extern long long pps_time;
extern uint32 capture_flag;
extern renumber renumber_frame;
extern setting setting_frame;
extern uint32 the_output_buffer_prepared_but_not_sended;

uint8 ByteToInt(uint8);
uint8 IsNotEmpty(RingBuff_t*);
uint8 InsertByte(RingBuff_t* , uint8);
uint8 ExtractByte(RingBuff_t*);
uint8 agg_sent(uart_context*);
void IpPars(uint8* sentence);

/*Clock.c*/

void Strobe ();
void UpdatePeriod(uint32 NewPeriod);
#endif

/* [] END OF FILE */
