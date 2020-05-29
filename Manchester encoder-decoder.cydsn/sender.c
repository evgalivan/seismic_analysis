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



statReg curStat;
static volatile unsigned int count_to_send=0;
static volatile unsigned int status=0, NeedLoadFlag=0;
static uint32 *Current_word  = (uint32*)(0);
int stsh;
static volatile int buffer_busy = 0; //флаг ресурса буффера пердечи

void Load(void){
    isr_Load_TrShReg_Disable();
    if(buffer_busy == 0) {
        buffer_busy = 1;
    isr_Load_TrShReg_Enable();
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
        buffer_busy = 0;
        return;
    }
    isr_Load_TrShReg_Enable();
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
#define MESS_LEN 4

uint32 dummy_massage[ MESS_LEN]={0};
uint32 time_stmp_buf[ MESS_LEN]={};
uint32 addr_set_buf[ MESS_LEN]={};
uint32 selected_buf[ MESS_LEN]={};

void Prepare(uint32* buf, char mask){
    CyGlobalIntDisable;
    memcpy(selected_buf,buf,MESS_LEN);
    ControlReg_Regim_Write(mask);
    CyGlobalIntEnable;
}
void Prepare2(void){
    CyGlobalIntDisable;
    //selected_buf[3]=time_stamp_high;
    //selected_buf[2]=time_stamp_low;
    ControlReg_Regim_Write(0xf);
    CyGlobalIntEnable;
}

int GetStatus(void){
    CyGlobalIntDisable;
    int result = status;    
    CyGlobalIntEnable;
    return result;
}

void GeneralSend (enum Regim curRegim ){
    
    if(GetStatus() == 0) {
       
        uint32 *pselectedbuf = dummy_massage;
        switch (curRegim){
        default:
        case    DUMMY: Prepare(dummy_massage, 0xf);/*dO't forget about dectination selector */ break;
        case    TIME_STMP: Prepare2();/*dO't forget about dectination selector */ break;
        case    ADDR_SET1: Prepare(addr_set_buf, 0x1);/*dO't forget about dectination selector */ break;
        case    ADDR_SET2: Prepare(addr_set_buf, 0x2);/*dO't forget about dectination selector */ break;
        case    ADDR_SET3: Prepare(addr_set_buf, 0x4);/*dO't forget about dectination selector */ break;
        case    ADDR_SET4: Prepare(addr_set_buf, 0x8);/*dO't forget about dectination selector */ break;
        }
        PrepareToSend(selected_buf,MESS_LEN);
        Send();        
        return;
    }
    
}

void   ClearStatus(void){   //должна быть вызвана из прерывания bitcouner, когда сброшен StartTransmit
    status=0;        
}



int GetStatusFifoSender (void){
    return TransmitShiftReg_SR_STATUS;
}
/* [] END OF FILE */
   


