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

static unsigned int count_to_send=0;
static unsigned int status=0;
static long *Current_word  = (long*)(0);

void Preload(void){
    while(count_to_send){
        if( CYRET_SUCCESS == TransmitShiftReg_WriteData(*Current_word)){
            Current_word++;
            count_to_send--;
        }else{
            break;
        }
    }
}


TrResult  PrepareToSend(long* ex_buf,int LENGTH){
    if (status)
        return BUSY;
    count_to_send  = LENGTH;
    Current_word = ex_buf;
    //TO DO emptyes FIFO
    Preload();
    return SUCCSSY;
}

void   Send(void){
    status=1;    
    BitCounterEnc_WriteCounter(BitCounterEnc_ReadCompare());
    StartTransmit_Write(1);
}

void   ClearStatus(void){   //должна быть вызвана из прерывания bitcouner, когда сброшен StartTransmit
    status=0;        
}
/* [] END OF FILE */
   


