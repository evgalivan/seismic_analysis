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

#include "global.h"
#include "sender.h"
#include "reciver.h"

#include <BitCounterDec.h>

uint32 incr_compare = 512; // зависит от той частоты, которую мы хотим получить

// задание структуры для регистра статуса ShiftReg
struct control {
    int load: 1;        //Load status bit
    int store: 1;       //Store status bit
    int reset: 1;       //Reset status bit
    int F0_not_empty: 1;    //Input FIFO is empty
    int F0_not_full: 1;  //Input FIFO is neither full nor empty
    int F1_full: 1;     //Output FIFO is full
    int F1_partial: 1;  //Output FIFO is neither full nor empty
    int : 1;         //empty bit
} Control;


uint32 massage[1] = { 0xFAAAAAAF };

uint32 main_freq =  72000000LL;
uint32 desired_freq  = 4096000LL;
uint32 divider_freq = (8LL);
uint32 capacity = (0xffLL);  //емкость сумматора 


#define LENGTH_OF(Array) (sizeof(Array)/sizeof(Array[0]))

volatile int storeflag=0, length = 72;
static volatile long long  period;


int main(void)
{
    incr_compare = desired_freq / 1L; 
    period = ( long long ) capacity * divider_freq * desired_freq / (1 * main_freq);    //977343669

    CyGlobalIntDisable; /* Enable global interrupts. */
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    // Инициализация устройств Encoder
    TransmitShiftReg_Start( );
    BitCounterEnc_Start( );
    
	// Инициализация устройств Decoder
	RecieveShiftReg_Start() ;
	Waiter_Start() ;
    BitCounterDec_Start() ;
    VDAC8_1_Start();
    Comp_1_Start();
    Comp_2_Start();
    Opamp_1_Start();
    
    Period_Start();
    SigmaReg_Start();
    Boundary8bit_Start();
    usec_counter_Start();
    cap_comp_tc_Start();
    
    // Инициализация прерываний
    //StartFrame_Start();
    EndFrame_Start();
    isr_Load_TrShReg_Start();
	WordShifted_Start();
    isr_TransmitWordShift_Start( );
    isr_TransmitWordShift_Disable( );
    int delay = 0xFFffff;
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    
        
    FrameAllow_Write(0);
    
    PrepareToSend(massage,0);
    Send();
    
    while(PrepareToSend(massage,0)==TRBUSY);
    
    FrameAllow_Write(1);
    
    ClearShiftRecieverError((uint32*)massage, LENGTH_OF(massage));
        
    int flag = 0, true_word = 0;
    int store = 0;
    uint8 RecieverFIFO[1]= {0x0};
    uint32 *p1=ex_buf, *p2=recieve_buf;
        
    BitCounterDec_WriteCounter(31);
    
    SetAllowStoreFlag();
    while(1) 
    {
        UpdatePeriod(period);
        PrepareToStore(recieve_buf);
        PrepareToSend(ex_buf,length);
    }
}

/* [] END OF FILE */
