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

statReg curStat;
static volatile unsigned int count_to_send=0;
static volatile unsigned int status=0, NeedLoadFlag=0;
static long *Current_word  = (long*)(0);
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


TrResult  PrepareToSend(long* ex_buf,int LENGTH){
    if (status)
        return BUSY;
    *ex_buf|=0x80000000;
    count_to_send  = LENGTH;
    Current_word = ex_buf;
    //TO DO emptyes FIFO
    Load();
    return SUCCSSY;
}


void   Send(){
    status=1;    
    BitCounterEnc_WriteCounter(BitCounterEnc_ReadCompare());
    StartTransmit_Write(1);
}

void   ClearStatus(void){   //должна быть вызвана из прерывания bitcouner, когда сброшен StartTransmit
    status=0;        
}

void SetNeedLoadFlag(void){
    NeedLoadFlag = 1;
}

void ClearNeedLoadFlag(void){
    NeedLoadFlag = 0;
}

int     CheckNeedLoadFlag (void){
    return NeedLoadFlag;
}

int GetStatusFifoSender (void){
    return TransmitShiftReg_SR_STATUS;
}
/* [] END OF FILE */
   


