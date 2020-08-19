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
#include <Clock.h>
#include <BitCounterDec.h>
#include <line_buf.h>
#include <SPI_ADC_ADS131E08.h>
#include <FirstFrame.h>

uint32 incr_compare = 512; // зависит от той частоты, которую мы хотим получить

uint32 massage[1] = { 0xFAAAAAAF };

const uint32 main_freq =  72000000LL;
const uint32 desired_freq  = 4096000LL;
const uint32 low_freq  = 3400000LL;
const uint32 high_freq  = 4500000LL;
const uint32 divider_freq = (8LL);
const uint32 capacity = (0xffLL);  //capacity battery


#define LENGTH_OF(Array) (sizeof(Array)/sizeof(Array[0]))

volatile long   NewFrequency;
long   LowFrequency;
long   HighFrequency;
uint32 DRDY_flag = 0;

int main(void)
{
    
    incr_compare = desired_freq / 1L; 
    NewFrequency = ( long long ) capacity * divider_freq * desired_freq / (1 * main_freq);    //977343669
    LowFrequency = ( long long ) capacity * low_freq * divider_freq / (1 * main_freq);
    HighFrequency = ( long long ) capacity * high_freq * divider_freq / (1 * main_freq);
    
    CyGlobalIntDisable; /* Enable global interrupts. */
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    // Init Encoder devices
    TransmitShiftReg_Start( );
    BitCounterEnc_Start( );
    
	// Init Decoder devices
	RecieveShiftReg_Start() ;
	Waiter_Start() ;
    BitCounterDec_Start() ;
    VDAC8_1_Start();
    Comp_1_Start();
    Comp_2_Start();
    Opamp_1_Start();
    
    // Init Clock devices
    Period_Start();
    SigmaReg_Start();
    Boundary8bit_Start();


    
    // Init Interrupte
    
    cap_comp_tc_Start();
    EndFrame_Start();
    isr_Load_TrShReg_Start();
	WordShifted_Start();
    isr_TransmitWordShift_Start( );
    isr_TransmitWordShift_Disable( );
    Capture_low_InterruptEnable();
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    
    PrepareToSend();
    Send();
    FrameAllow_Write(0);
    
    while(status==TRBUSY);
    
    FrameAllow_Write(1);
           
    UpdateFrequency(NewFrequency); 
    
    /*Call func PrepareToStore until initialisation*/
    PrepareToStore();
    

    

    while(1) 
    {
        
        if (UpdateFrequencyFlag != 0){
            PrepareNewFrequency();
            if(UpdateFrequencyFlag != 0){
                UpdateFrequency(NewFrequency);
                UpdateFrequencyFlag = 0;
            }
        }
        
        if (DRDY_flag){
            DRDY_flag=0;
            SPI_ADC_ClearTxBuffer();
            SPI_ADC_ClearRxBuffer();
            SPI_ADC_PutArray((uint8*) Data_ADS131E08.array, sizeof(Data_ADS131E08.array));
        }
        /*TO DO     ===============================================
         *   1 Проанализировть флаг готовности АЦП и прочитать оттуда данные;
         *   2 опросить акселерометр и подготовить усредненные данные; (опрашивем чаще чем отсылаем, потому можно усреднить)
         *   ======================================================
        */
        
        /*  ======================================================
         *   flag_write_done set 1 in EndFrame interrupte
         *   flag_read_done set 1 in isr_Load_TrShReg interrupte
         *  ======================================================
        */
        if ((flag_read_done == 1) && (flag_write_done == 1)){
            flag_read_done = 0;
            flag_write_done = 0;
            /*copy least control frame*/
            
            /*TO DO
            1 Проанализировть фрейм управления и исполнить директивы;
            2 Подготовить фрейм для передачи и загрузить в FIFO передатчика;            
            */
            if(27 <= SPI_ADC_GetRxBufferSize()){
                int i = 0;
                while (SPI_ADC_GetRxBufferSize() != 0){
                    Data_ADS131E08.array[i] = SPI_ADC_ReadRxData();
                }
                last_adc_data_sended = 0;
            }
            PrepareFirstFrame();
            CopyFirstFrame();
            PrepareToStore();
            PrepareToSend();
            PrepareToStore();
            Send();
        }
    }
}

/* [] END OF FILE */
