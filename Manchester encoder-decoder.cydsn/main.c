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

// задание структуры для регистра статуса ShiftReg
struct control {
    int load: 1;        //Load status bit
    int store: 1;       //Store status bit
    int reset: 1;       //Reset status bit
    int F0_empty: 1;    //Input FIFO is empty
    int F0_partial: 1;  //Input FIFO is neither full nor empty
    int F1_full: 1;     //Output FIFO is full
    int F1_partial: 1;  //Output FIFO is neither full nor empty
    int XXX: 1;         //empty bit
} Control;

long ex_buf[4] = { 0xAA000000, 0xFFFFFFFF, 0x7F00FF01, 0x4F4F4F4E };

#define LENGTH_OF(a) (sizeof(a)/sizeof(a[0]))

int main(void)
{
    CyGlobalIntDisable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    // Инициализация устройств Encoder
    TransmitShiftReg_Start( );
    BitCounterEnc_Start( );
    
	// Инициализация устройств Decoder
	RecieveShiftReg_Start();
	Waiter_Start() ;
    BitCounterDec_Start() ;

    
    // Инициализация прерываний
    isr_Load_TrShReg_Start();
	WordShifted_Start();
    TransmitWordShift_Start( );
    TransmitWordShift_Disable( );
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    //int massage = 0xAAAA5555;
    int flag = 0;
    int delay = 0xFFFFFF;
    while(1) 
    {
        if (StartButton_Read() != 0)
        {
            while (delay--);
            delay = 0xFFFFFF;
            flag++;
        }
        else if (flag != 0)
        {
            flag = 0;
        
            PrepareToSend(ex_buf,LENGTH_OF(ex_buf)); 
            Send();
                
//            TransmitShiftReg_WriteData(massage);
//            BitCounterEnc_WriteCounter(BitCounterEnc_ReadCompare());
//            StartTransmit_Write(1);
            
            //StartTransmit_Write(0);
            //WordShifted_ClearPending();
        }
    }
    
}

/* [] END OF FILE */
