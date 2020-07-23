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
#include "sender.h"
#include <TransmitShiftReg.h>
#include <BitCounterEnc.h>
#include <StartTransmit.h>
#include <FrameAllow.h>

exchange_unit DataToTransmit;

statReg curStat;
static volatile unsigned int count_to_send=0;
static volatile unsigned int status=0;
static uint32 *Current_word  = (uint32*)(0);
int stsh;

void Load(void){
    while(count_to_send){
        *(char*)(&curStat)=TransmitShiftReg_SR_STATUS;
        if( 0 != curStat.F0_not_full){
            TransmitShiftReg_WriteData(*Current_word);
            Current_word++;
            count_to_send--;
        }else{
            count_to_send=count_to_send;
            break;
        }
    }
}


TrResult  PrepareToSend(uint32* ex_buf,int LENGTH){
    if (status)
        return TRBUSY;
    //status=1;
    *ex_buf |= 0x80000000;
    count_to_send  = LENGTH;
    Current_word = ex_buf;
    //TO DO emptyes FIFO
    Load();
    return TRSUCCSSY;
}


void   Send(){
    StartTransmit_Write(0);
    status=1;    
    BitCounterEnc_WriteCounter(BitCounterEnc_ReadCompare());
    StartTransmit_Write(1);
}

void   ClearStatus(void){   //должна быть вызвана из прерывания bitcouner, когда сброшен StartTransmit
    status=0;        
}

int GetStatusFifoSender (void){
    return TransmitShiftReg_SR_STATUS;
}
/* [] END OF FILE */
   


