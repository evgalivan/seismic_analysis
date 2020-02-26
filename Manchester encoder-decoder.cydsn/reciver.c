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
#include <BitCounterDec.h>
#include <StartTransmit.h>
#include <FrameAllow.h>

RecieveStatReg curStatRecive;

static volatile unsigned int AllowStoreFlag = 0, AllowPrepareToStoreFlag = 0, first = 0, second =0, third = 0;
static volatile unsigned int CountToRecieve, rcstatus=0;
static uint32 *current_word  = (uint32*)(0), trash;


void Store(void){
//    while (CountToRecieve)
//    {
        if(first == 0) {
                first = 1;
                trash = RecieveShiftReg_ReadData() | 0x80000000;
               }
        else {
//            *(char*)(&curStatRecive) = RecieveShiftReg_SR_STATUS;
//            if(curStatRecive.F1_partial)      
//                {
//                    if(first == 0) {
//                        first = 1;                
//                        trash = RecieveShiftReg_ReadData() | 0x80000000;
//                        //current_word--;
//                    }
//                    else {
                        if (second == 0){
                        second = 1;
                        *current_word = RecieveShiftReg_ReadData() | 0x80000000;
                        }
                        else {
                            *current_word = RecieveShiftReg_ReadData();
                        }
                        current_word++;
                        //CountToRecieve--;
//                    }
//                }
//            else{
//                CountToRecieve=CountToRecieve;
//                break;            
            }
//        }
//    }
}

void SetAllowPrepareToStoreFlag(void){
    AllowPrepareToStoreFlag = 1;
}

int CheckAllowPrepareToStoreFlag(void){
    return AllowPrepareToStoreFlag;
}

void ClearAllowPrepareToStoreFlag(void){
    AllowPrepareToStoreFlag = 0;
}

void SetAllowStoreFlag(void){
    AllowStoreFlag = 1;
}

int CheckAllowStoreFlag(void){
    return AllowStoreFlag;
}

void ClearAllowStoreFlag(void){
    AllowStoreFlag = 0;
}

int CheckNumberOfWords(void){
    return CountToRecieve;
}

void ClearRcStatus(void){
    rcstatus = 0;
}

RcResult PrepareToStore(uint32* recieve_buf){//, int LENGTH){
    if (rcstatus)
        return RCBUSY;
    rcstatus = 1;
    //CountToRecieve = LENGTH;
    current_word = recieve_buf;
    //BitCounterDec_WriteCounter(31);
    first = 0;
    second = 0;
//    Store();
    return RCSUCCSSY;
}


void ClearShiftRecieverError(uint32* recieve_buf, int LENGTH){
    CountToRecieve = LENGTH;
    current_word = recieve_buf;
    Store();
}

void GetStatusFifoReciever (uint8 *RecieverFifo){
    *RecieverFifo = RecieveShiftReg_SR_STATUS;    
}

/* [] END OF FILE */
