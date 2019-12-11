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
#include <StartTransmit.h>
#include <FrameAllow.h>

RecieveStatReg curStatRecive;

static volatile unsigned int AllowStoreFlag = 0;
static volatile unsigned int CountToRecieve;
static uint32 *current_word  = (uint32*)(0);


void Store(void){
    while (CountToRecieve)
    {
        *(char*)(&curStatRecive) = RecieveShiftReg_SR_STATUS;
        if(curStatRecive.F1_partial)      
            {
                *current_word = RecieveShiftReg_ReadData();
                current_word++;
                CountToRecieve--;                
            }
        else break;
    }
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

void PrepareToStore(uint32* recieve_buf, int LENGTH){
    CountToRecieve = LENGTH;
    current_word = recieve_buf;
    Store();
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
