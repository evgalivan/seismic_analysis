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
#include "project.h"
#include "sender.h"
#include "reciver.h"


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

long ex_buf[8] = { 0xAA000000 , 0xFFFFFFFF, 0x7F00FF01, 0x4F4F4F4E , 0x80000000 , 0xFAFAFAFA, 0x8000FFFF, 0x7EEEAAAA};
long massage[1] = { 0xAAAA5555 };
uint32 recieve_buf[8];

#define LENGTH_OF(Array) (sizeof(Array)/sizeof(Array[0]))
    int length = 1;

int main(void)
{
    CyGlobalIntDisable; /* Enable global interrupts. */
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    // Инициализация устройств Encoder
    TransmitShiftReg_Start( );
    BitCounterEnc_Start( );
    
	// Инициализация устройств Decoder
	RecieveShiftReg_Start() ;
	Waiter_Start() ;
    BitCounterDec_Start() ;
//    VDAC8_1_Start();
//    Comp_1_Start();
//    Comp_2_Start();
    
    // Инициализация прерываний
    isr_Load_TrShReg_Start();
	WordShifted_Start();
    TransmitWordShift_Start( );
    TransmitWordShift_Disable( );
    int delay = 0xFFFFFF;
    
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
    
    FrameAllow_Write(0);
    
    PrepareToSend(massage,0);
    Send();
    
    while(PrepareToSend(massage,0)==BUSY);
    
    FrameAllow_Write(1);
    
    ClearShiftRecieverError((uint32*)massage, LENGTH_OF(massage));
    
    //int massage = 0xAAAA5555;
    int flag = 0;
    int store = 0;
    uint8 RecieverFIFO[1]= {0x0};
    
    while(1) 
    {
        
        //PrepareToSend(ex_buf,LENGTH_OF(ex_buf));
        
        //          *******Передатчик*******
        
        if (StartButton_Read() != 0)
        {
            while (delay--);
            delay = 0xffffff;
            flag++;
        }
        else if (flag != 0)
        {
            flag = 0;
        
            
            PrepareToSend(ex_buf,length); 
            Send();
            
                
            /*
            TransmitShiftReg_WriteData(massage);
            BitCounterEnc_WriteCounter(BitCounterEnc_ReadCompare());
            StartTransmit_Write(1);
            
            starttransmit_write(0);
            wordshifted_clearpending();
            */
        }

        if (CheckNeedLoadFlag()){
            ClearNeedLoadFlag();
            Load();
        }
        
        //                  ********КОНЕЦ Передатчика********
        
        
        //                  *******Приемник*******               
        
        if (CheckNumberOfWords() <= 0) {
                //ClearShiftRecieverError((uint32*)massage, LENGTH_OF(massage));
                PrepareToStore(recieve_buf, LENGTH_OF(recieve_buf));
        }
                
        
        if (CheckAllowStoreFlag())
        {
            ClearAllowStoreFlag();
            Store();
        }
        
        GetStatusFifoReciever(RecieverFIFO);
        GetStatusFifoReciever(RecieverFIFO);
        //                  ********КОНЕЦ Приемника********
        
    }
}

/* [] END OF FILE */
