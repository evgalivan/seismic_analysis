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
#include <line_buf.h>


statReg curStat;
static volatile unsigned int count_to_send=0;
volatile unsigned int status=0, tmp_tr;
int stsh;

void Load(void){
    while(count_to_send){
        if(current_read < current_write){
            tmp_tr = TransmitShiftReg_SR_STATUS;
            if((tmp_tr & 0x10)/*|(!(tmp_tr & 0x8))*/) {
                CY_SET_REG32(TransmitShiftReg_IN_FIFO_VAL_LSB_PTR, *current_read);
                current_read++;
                count_to_send--;
            }else{
                break;
            }
        }else          break;
    }
}


TrResult  PrepareToSend(void){
    if (status)
        return TRBUSY;
    *line_buf |= 0x80000000;
    count_to_send  = PACKET_LENGTH;
    current_read = line_buf;    
    Load();
    return TRSUCCSSY;
}


void   Send(){
    status=1;    
    BitCounterEnc_WriteCounter(BitCounterEnc_ReadCompare());
    StartTransmit_Write(1);
}

void   ClearStatus(void){   //должна быть вызвана из прерывания bitcouner, когда сброшен StartTransmit
    status=0;        
}
/* [] END OF FILE */
   


