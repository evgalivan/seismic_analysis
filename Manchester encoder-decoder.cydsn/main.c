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
#include "Clock.h"
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

uint32 ex_buf[72] = { 0xAA000005 , 0xFFFFFFFF, 0x7F00FF01, 0x4F4F4F4E , 0x80000000 , 0xFAFAFAFA, 0x8000FFFF, 0x7EEEAAAA, 
                         0xAA00000A , 0xFFFFFFFF, 0x7F00FF01, 0x4F4F4F4E , 0x80000000 , 0xFAFAFAFA, 0x8000FFFF, 0x7EEEAAAA,
                             0xAA00000A , 0xFFFFFFFF, 0x7F00FF01, 0x4F4F4F4E , 0x80000000 , 0xFAFAFAFA, 0x8000FFFF, 0x7EEEAAAA,
                         0xAA00000A , 0xFFFFFFFF, 0x7F00FF01, 0x4F4F4F4E , 0x80000000 , 0xFAFAFAFA, 0x8000FFFF, 0x7EEEAAAA,
                             0xAA00000A , 0xFFFFFFFF, 0x7F00FF01, 0x4F4F4F4E , 0x80000000 , 0xFAFAFAFA, 0x8000FFFF, 0x7EEEAAAA,
                         0xAA00000A , 0xFFFFFFFF, 0x7F00FF01, 0x4F4F4F4E , 0x80000000 , 0xFAFAFAFA, 0x8000FFFF, 0x7EEEAAAA,
                             0xAA00000A , 0xFFFFFFFF, 0x7F00FF01, 0x4F4F4F4E , 0x80000000 , 0xFAFAFAFA, 0x8000FFFF, 0x7EEEAAAA,
                         0xAA00000A , 0xFFFFFFFF, 0x7F00FF01, 0x4F4F4F4E , 0x80000000 , 0xFAFAFAFA, 0x8000FFFF, 0x7EEEAAAA,
                             0xAA00000A , 0xFFFFFFFF, 0x7F00FF01, 0x4F4F4F4E , 0x80000000 , 0xFAFAFAFA, 0x8000FFFF, 0x7EEEAAAA};
uint32 massage[1] = { 0xFAAAAAAF };

uint32 main_freq =  72000000LL;
uint32 desired_freq  = 1024000LL;
uint32 divider_freq = (32LL);
uint32 capacity = (0xffffffffLL);  //емкость сумматора 



#define LENGTH_OF(Array) (sizeof(Array)/sizeof(Array[0]))
#define SENDER      //RESIEVER or SENDER
volatile int storeflag=0, length = 72;
static volatile long long  period;


int main(void)
{
    incr_compare = desired_freq / 1234.5L; 
    period = ( long long ) capacity * divider_freq * desired_freq / (1 * main_freq);    //977343669
    CyGlobalIntDisable; /* Enable global interrupts. */
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    // Инициализация устройств Encoder
    TransmitShiftReg_Start( );
    BitCounterEnc_Start( );
    
	// Инициализация устройств Clock
    Period_Start();
    SigmaReg_Start();
    Boundary32bit_Start();
    usec_counter_Start();
    sec_counter_Start();
    cap_comp_tc_Start();
    
    // Инициализация прерываний
    //StartFrame_Start();
    
    isr_Load_TrShReg_Start();

    TransmitWordShift_Start( );
    TransmitWordShift_Disable( );
    int delay = 0xFFffff;
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    

//    TransmitShiftReg_WriteData(1);
//    BitCounterEnc_WriteCounter(BitCounterEnc_ReadCompare());
//    *(char*)(&curStat)=TransmitShiftReg_SR_STATUS;
//    while( 0 != curStat.F0_not_empty ){
//        StartTransmit_Write(1);
//        delay = 0xFFF;
//        while (delay--);
//        StartTransmit_Write(0);
//        *(char*)(&curStat)=TransmitShiftReg_SR_STATUS;
//    }
    
    #ifdef SENDER
        
    FrameAllow_Write(0);
    
    PrepareToSend(massage,0);
    Send();
    
    while(PrepareToSend(massage,0)==TRBUSY);
    
    FrameAllow_Write(1);
    
    
    //while (PrepareToStore(recieve_buf) == RCBUSY);
    
    //int massage = 0xAAAA5555;
    int flag = 0, true_word = 0;
    int store = 0;
    uint8 RecieverFIFO[1]= {0x0};
    uint32 *p1=ex_buf;
        
    
    while(1) 
    {
        UpdatePeriod(period);
        //int i=0;

        
        //if (CheckAllowStoreFlag()) 
            
        
        
        //, length);
        
        //PrepareToSend(ex_buf,LENGTH_OF(ex_buf));
        
        //          *******Передатчик*******
        //while (PrepareToStore(recieve_buf) == RCBUSY);
//        if (1)
//        {
//            //if (StartButton_Read() != 0)
//            if (PrepareToSend(ex_buf,length) == TRSUCCSSY )
//            {
//                
//    //            delay = 0x1; //‭44AA200‬
//    //            while (delay--);
//                //flag = 1;
//
////                for (int i = 0; i < 72; i++) recieve_buf[i] = 0x0;
//    //            LED = 0;
//    //            LED_ON_Write(LED);
//    //            delay = 0x1; //‭44AA200‬
//    //            while (delay--);
//                LED_ON_Write(0);
//    //            delay = 0x1;
//    //            while (delay--);
//                Send();
//                
//                
//    //            flag++;
//            }
//            
//        }
       /* else if (flag != 0)
        {
            flag = 0;
            
            //PrepareToStore(recieve_buf, length);
            //PrepareToSend(ex_buf, length); 
            Send();
            */
                
            /*
            TransmitShiftReg_WriteData(massage);
            BitCounterEnc_WriteCounter(BitCounterEnc_ReadCompare());
            StartTransmit_Write(1);
            
            starttransmit_write(0);
            wordshifted_clearpending();
            */
//        }

        if (CheckNeedLoadFlag()){
            ClearNeedLoadFlag();
            Load();
        }
        
        //                  ********КОНЕЦ Передатчика********
        
        
        //                  *******Приемник*******               
        
//        if (CheckAllowPrepareToStoreFlag()) {
//                //ClearShiftRecieverError((uint32*)massage, LENGTH_OF(massage));
//                ClearAllowPrepareToStoreFlag();
//                PrepareToStore(recieve_buf, length);
//      }
                
        
//        if (CheckAllowStoreFlag())
//        {
//            ClearAllowStoreFlag();
            //Store();
//        }
        
//        for (i = 0; i < length; i++){
//            if( *p1 == *p2 ) true_word++;
//                p1++;
//                p2++;
        
//        if (*(p1+length-1) == *(p2+length-1)){
//            LED = 1;
//            LED_ON_Write(LED);
//        }
        
            
//        
//        true_word = 0;
        
        
        
        

//        GetStatusFifoReciever(RecieverFIFO);
//        GetStatusFifoReciever(RecieverFIFO);
    }

    #else
            
    FrameAllow_Write(0);
    
    PrepareToSend(massage,0);
    Send();
    
    while(PrepareToSend(massage,0)==BUSY);
    
    FrameAllow_Write(1);
    
    ClearShiftRecieverError((uint32*)massage, LENGTH_OF(massage));
    
    //int massage = 0xAAAA5555;
    int flag = 0, LED = 0, true_word = 0;
    int store = 0;
    uint8 RecieverFIFO[1]= {0x0};    
    
    while(1) 
    {
        int i=0;
        //PrepareToSend(ex_buf,LENGTH_OF(ex_buf));
        
        //          *******Передатчик*******
        
        if (CheckAllowPrepareToStoreFlag())
        {
            ClearAllowPrepareToStoreFlag();
            for (int i = 0; i < 72; i++) recieve_buf[i] = 0x0;
            LED = 0;
            LED_ON_Write(LED);     
            PrepareToStore(recieve_buf, length);
            PrepareToSend(ex_buf, length); 
            Send();
        }
       
        if (CheckNeedLoadFlag()){
            ClearNeedLoadFlag();
            Load();
        }
        
        //                  ********КОНЕЦ Передатчика********
        
        
        //                  *******Приемник*******               
        
//        if (CheckNumberOfWords() <= 0) {
//                //ClearShiftRecieverError((uint32*)massage, LENGTH_OF(massage));
//                PrepareToStore(recieve_buf, length);
//        }
                
        
        if (CheckAllowStoreFlag())
        {
            ClearAllowStoreFlag();
            Store();
        }
        
//        for (i = 0; i < length; i++){
//            if( *p1 == *p2 ) true_word++;
//                p1++;
//                p2++;
            if (*(p1+length-1) == *(p2+length-1)){
                LED = 1;
                LED_ON_Write(LED);
            }
            
//        
//        true_word = 0;
        
        
        
        
        GetStatusFifoReciever(RecieverFIFO);
        GetStatusFifoReciever(RecieverFIFO);

       
        //                  ********КОНЕЦ Приемника********
        
        
    }
    #endif
}

/* [] END OF FILE */
