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
#include "reciver.h"
#include <RecieveShiftReg.h>
#include <BitCounterDec.h>
//#include <StartTransmit.h>
//#include <FrameAllow.h>
#include <line_buf.h>
#include <Polarity_Control.h>


volatile unsigned int first = 1;
volatile unsigned int CountToRecieve, rcstatus=0;


inline void Store(uint32 tmp){
    
    if(CountToRecieve)
    {
        CountToRecieve--;
        *(current_write++) = tmp;
    }
}


void ClearRcStatus(void){
    rcstatus = 0;
}

/*
Func PrepareToStore 
*/

RcResult PrepareToStore(void){
    //if (rcstatus)
    //    return RCBUSY;
    //rcstatus = 1;
    BitCounterDec_WriteCounter(31);
    while(0x1f & BitCounterDec_ReadStatusRegister());
    
//    while (RecieveShiftReg_OUT_FIFO_EMPTY != (RecieveShiftReg_SR_STATUS&RecieveShiftReg_OUT_FIFO_MASK)){
    while ((RecieveShiftReg_SR_STATUS&0x40)/*|(!(tmp&0x20))*/){
        RecieveShiftReg_ReadData();
    };
    //Polarity_Control_Write(1);
    //Polarity_Control_Write(0);
    CountToRecieve = PACKET_LENGTH;
    current_write = line_buf;

    //first = 1;
    return RCSUCCSSY;
}

void ClearShiftRecieverError(uint32* recieve_buf, int LENGTH){
    CountToRecieve = LENGTH;
    current_write = recieve_buf;
    //Store();
}

void GetStatusFifoReciever (uint8 *RecieverFifo){
    *RecieverFifo = RecieveShiftReg_SR_STATUS;    
}

/* [] END OF FILE */
