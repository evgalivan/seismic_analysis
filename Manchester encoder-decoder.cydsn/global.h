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

#define RING_SIZE 64
#define IN_RING( B)  if (++(B)>=RING_SIZE)(B) -= RING_SIZE

typedef struct{
    int load: 1;        //Load status bit
    int store: 1;       //Store status bit
    int reset: 1;       //Reset status bit
    int F0_empty: 1;    //Input FIFO is empty
    int F0_not_full: 1;  //Input FIFO is neither full nor empty
    int F1_full: 1;     //Output FIFO is full
    int F1_partial: 1;  //Output FIFO is neither full nor empty
    int : 1;         //empty bit
}statReg;

typedef enum {WAITINGOFDOLLAR, WAITINGOFSTAR, WAITINGOFCHSUM, WAITINGOFCHSUM2} State;
enum Regim {DUMMY, TIME_STMP, ADDR_SET1, ADDR_SET2, ADDR_SET3, ADDR_SET4};

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
} uart_context;

typedef struct {
    uint16 chanel;
    uint16 port;
    char multicast[4];
    char unicast[4];
    char mac[6];
}ip_set;

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

typedef union {
    uint32 buf[4];
    frame_recount pattern;
}renumber;


extern statReg curStatPeriod;
extern uint32 dummy_massage[];
extern uint32 time_stmp_buf[];
extern uint32* addr_set_buf;
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
extern uart_context usb_context, gps_context;
extern ip_set IP_Complete;
extern renumber renumber_frame;

void IpPars(uint8*);
char* strtok_e(char*, char);
void Load(void);
void GeneralSend(enum Regim);
uint8 ByteToInt(uint8);
uint8 IsNotEmpty(RingBuff_t*);
uint8 InsertByte(RingBuff_t* , uint8);
uint8 ExtractByte(RingBuff_t*);
uint8 agg_sent(uart_context*);

#endif

/* [] END OF FILE */
