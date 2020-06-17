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
#include "Clock.h"

#define RING_SIZE 64
#define IN_RING( B)  if (++(B)>=RING_SIZE)(B) -= RING_SIZE

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
} uart_context;

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

extern uint32 incr_compare;
extern long long utc_time;
extern long long pps_time;
extern uint32 capture_flag;
extern renumber renumber_frame;

uint8 ByteToInt(uint8);
uint8 IsNotEmpty(RingBuff_t*);
uint8 InsertByte(RingBuff_t* , uint8);
uint8 ExtractByte(RingBuff_t*);
uint8 agg_sent(uart_context*);


/* [] END OF FILE */
