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
exchange_unit RecivedData;
RecieveStatReg curStatRecive;

static volatile unsigned int AllowStoreFlag = 0, AllowPrepareToStoreFlag = 0, first = 0,data_recived=0 ;
static volatile unsigned int CountToRecieve, rcstatus=0, tmp;
static uint32 *current_word  = NULL;


void Store(void){
    tmp = RecieveShiftReg_SR_STATUS;
    while ( tmp & 0x40)// FULL or NOT_EMPTY
    {
        tmp = RecieveShiftReg_ReadData();
        if(first == 0)                 first = 1;
        else {
            if(CountToRecieve){
                *current_word = tmp;
                current_word++;
                CountToRecieve--;
                if(CountToRecieve==0)data_recived= 1;
            }
        }
    }
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
unsigned int isRecived(void){return data_recived;}
void ClearRecived(void){data_recived=0;}
void SetRecived(void){data_recived=1;}

RcResult PrepareToStore(uint32* recieve_buf, int LENGTH){
    if (rcstatus)
        return RCBUSY;
    rcstatus = 1;
    CountToRecieve = LENGTH;
    current_word = recieve_buf;
    first = 1;
    BitCounterDec_WriteCounter(31);
    return RCSUCCSSY;
}




/* [] END OF FILE */
