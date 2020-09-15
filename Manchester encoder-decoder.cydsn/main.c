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


#include <global.h>
#include "sender.h"
#include "reciver.h"
#include <Clock.h>
#include <BitCounterDec.h>
#include <line_buf.h>
#include <SPI_ADC_ADS131E08.h>
#include <FirstFrame.h>
#include <ControlFrame.h>

uint32 incr_compare = 512; // зависит от той частоты, которую мы хотим получить

uint32 massage[1] = { 0xFAAAAAAF };

const uint32 main_freq =  72000000LL;
const uint32 desired_freq  = 4096000LL;
const uint32 low_freq  = 3400000LL;
const uint32 high_freq  = 4500000LL;
const uint32 divider_freq = (8LL);
const uint32 capacity = (0xffLL);  //capacity battery
const uint16 comp_capacity = 4096;

uint8 test_reg, test_reg2;

uint32 divide_stay;


#define LENGTH_OF(Array) (sizeof(Array)/sizeof(Array[0]))

volatile long   NewFrequency;
long   LowFrequency;
long   HighFrequency;
uint32 DRDY_flag = 0;

control_ind_adc_frame ind_control_adc;
control_gen_adc_frame gen_control;

adc_regim_set ADS131E08_CurSet = {ADS131E08_CONFIG1_DEFAULT, ADS131E08_CONFIG2_DEFAULT, ADS131E08_CONFIG3_DEFAULT, ADS131E08_FAULT_DEFAULT, 
                                    ADS131E08_CHSET_DEFAULT, ADS131E08_CHSET_DEFAULT, ADS131E08_CHSET_DEFAULT, ADS131E08_CHSET_DEFAULT, 
                                    ADS131E08_CHSET_POWERDOWN, ADS131E08_CHSET_POWERDOWN, ADS131E08_CHSET_POWERDOWN, ADS131E08_CHSET_POWERDOWN};

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

    SPI_ADC_Start();
    
    // Init Interrupte
    
    cap_comp_tc_Start();
    EndFrame_Start();
    isr_Load_TrShReg_Start();
	WordShifted_Start();
    isr_TransmitWordShift_Start( );
    isr_TransmitWordShift_Disable( );
    Capture_low_InterruptEnable();
    isr_DRDY_Start();
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    
    PrepareToSend();
    Send();
    FrameAllow_Write(0);
    
    while(status==TRBUSY);
    
    FrameAllow_Write(1);
           
    UpdateFrequency(NewFrequency); 
    
    /*Call func PrepareToStore until initialisation*/
    PrepareToStore();
    
    result cur_result = ERROR;
    
    //Setting time sinc adc DRDY
    
    divide_stay = (ADS131E08_SetTime_1KSPS * 2) % comp_capacity;
    
    
    //SPI_ADC_ADS131E08_RESET;
    //SPI_ADC_ADS131E08_OFFSETCAL;
    SPI_ADC_ADS131E08_SDataC;
    
    for (uint8 i=0; i < 12; i++){
        do{
            cur_result = SPI_ADC_ADS131E08_WReg_Check(ADS131E08_CurSet.array[i],ADS131E08_CONFIG1_ADDRESS+i);
        }while(cur_result == ERROR);
    }
    /*
    cur_result = SPI_ADC_ADS131E08_WReg_Check(ADS131E08_CONFIG1_DEFAULT,ADS131E08_CONFIG1_ADDRESS);
    cur_result = SPI_ADC_ADS131E08_WReg_Check(ADS131E08_CONFIG2_DEFAULT,ADS131E08_CONFIG2_ADDRESS);
    cur_result = SPI_ADC_ADS131E08_WReg_Check(ADS131E08_CONFIG3_DEFAULT,ADS131E08_CONFIG3_ADDRESS);
    cur_result = SPI_ADC_ADS131E08_WReg_Check(ADS131E08_FAULT_DEFAULT,ADS131E08_FAULT_ADDRESS);
    cur_result = SPI_ADC_ADS131E08_WReg_Check(ADS131E08_CHSET_DEFAULT,ADS131E08_CH1SET_ADDRESS);
    cur_result = SPI_ADC_ADS131E08_WReg_Check(ADS131E08_CHSET_DEFAULT,ADS131E08_CH2SET_ADDRESS);
    cur_result = SPI_ADC_ADS131E08_WReg_Check(ADS131E08_CHSET_DEFAULT,ADS131E08_CH3SET_ADDRESS);
    cur_result = SPI_ADC_ADS131E08_WReg_Check(ADS131E08_CHSET_DEFAULT,ADS131E08_CH4SET_ADDRESS);
    cur_result = SPI_ADC_ADS131E08_WReg_Check(ADS131E08_CHSET_POWERDOWN,ADS131E08_CH5SET_ADDRESS);
    cur_result = SPI_ADC_ADS131E08_WReg_Check(ADS131E08_CHSET_POWERDOWN,ADS131E08_CH6SET_ADDRESS);
    cur_result = SPI_ADC_ADS131E08_WReg_Check(ADS131E08_CHSET_POWERDOWN,ADS131E08_CH7SET_ADDRESS);
    cur_result = SPI_ADC_ADS131E08_WReg_Check(ADS131E08_CHSET_POWERDOWN,ADS131E08_CH8SET_ADDRESS);
    */
    //SPI_ADC_ADS131E08_RData;
    
    Comp_low_Write((uint8)divide_stay);
    divide_stay >>= 8; 
    Comp_high_Write((uint8)divide_stay);
    
    Control_Capture_3_Write(3);
    Control_Capture_3_Write(1);
    UpdateFrequency(NewFrequency);
    
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
            SPI_Data_ADS131E08[0] = ADS131E08_RDATA;
            SPI_Transaction((uint8*) SPI_Data_ADS131E08, ADC_SPI_PACKET_LENGTH); // may be optimize for ignore read pwdown chanels adc
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
            
            
            if((line_buf[PACKET_LENGTH - 4] & FRAME_TAG_MASK) == FRAME_TAG_CONTROL){
                if ((line_buf[PACKET_LENGTH - 4] & SUBFRAME_TAG_MASK) == SUBFRAME_TAG_IND_CONTROL)
                    memcpy(&ind_control_adc, (void*) &line_buf[PACKET_LENGTH - 4], 4);
                if ((line_buf[PACKET_LENGTH - 4] & SUBFRAME_TAG_MASK) == SUBFRAME_TAG_GEN_CONTROL)
                    memcpy(&gen_control, (void*) &line_buf[PACKET_LENGTH - 4], 4);
            }
            
            
            /*TO DO
            1 Проанализировть фрейм управления и исполнить директивы;
            2 Подготовить фрейм для передачи и загрузить в FIFO передатчика;            
            */
            if(ADC_SPI_PACKET_LENGTH <= SPI_ADC_GetRxBufferSize()){
                // may be optimize for ignore read pwdown chanels adc
                for (int i = 0; i < ADC_SPI_PACKET_LENGTH; i++){
                    SPI_Data_ADS131E08[i] = SPI_ADC_ReadRxData();
                }
                Data_ADS131E08.RData = SPI_Data_ADS131E08[0];
                Data_ADS131E08.adc_status = SPI_Data_ADS131E08[3] | (SPI_Data_ADS131E08[2] << 8) | (SPI_Data_ADS131E08[1] << 16);
                Data_ADS131E08.data_ch1 = SPI_Data_ADS131E08[6] | (SPI_Data_ADS131E08[5] << 8) | (SPI_Data_ADS131E08[4] << 16);
                Data_ADS131E08.data_ch2 = SPI_Data_ADS131E08[9] | (SPI_Data_ADS131E08[8] << 8) | (SPI_Data_ADS131E08[7] << 16);
                Data_ADS131E08.data_ch3 = SPI_Data_ADS131E08[12] | (SPI_Data_ADS131E08[11] << 8) | (SPI_Data_ADS131E08[10] << 16);
                Data_ADS131E08.data_ch4 = SPI_Data_ADS131E08[15] | (SPI_Data_ADS131E08[14] << 8) | (SPI_Data_ADS131E08[13] << 16);
                last_adc_data_sended = 0;
            }
            
            PrepareFirstFrame();
            CopyFirstFrame();
            PrepareToStore();
            
            PrepareToSend();
            Send();
            
            }
    }
}

/* [] END OF FILE */
