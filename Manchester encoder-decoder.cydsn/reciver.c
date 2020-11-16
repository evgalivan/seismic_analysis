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


volatile unsigned int first = 0;
volatile unsigned int CountToRecieve, rcstatus=0, tmp;



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

RcResult PrepareToStore(void){
    
    //fairies from past attarations
    rcstatus = 1;
    
    // clear error stayed data in shift register
    int tmp = RecieveShiftReg_SR_STATUS;
    while ((tmp&0x40)/*|(!(tmp&0x20))*/){ //api error |(!(tmp&0x20))
        tmp = RecieveShiftReg_ReadData(); //write error stayed data
        tmp = RecieveShiftReg_SR_STATUS;  //read status reg
    };
    
    // use line buf like in adc project
    CountToRecieve = PACKET_LENGTH;
    current_write = line_buf;
    first = 0;
    BitCounterDec_WriteCounter(31);
    return RCSUCCSSY;
}




/* [] END OF FILE */
