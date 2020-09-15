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

#include <FirstFrame.h>
#include <SPI_ADC_ADS131E08.h>
#include <line_buf.h>
#include "cytypes.h"



uint32 last_adc_data_sended = 1;
static uint32 subframe_counter=0;
data_adc_result_frame Result;



void PrepareFirstFrame(void){
    subframe_counter++;
    if(subframe_counter >= 8) subframe_counter=0;
    Result.label = 1;
    Result.fake = last_adc_data_sended;
    Result.subframe = subframe_counter;
    Result.frame = 7;
    Result.gidrophone = Data_ADS131E08.data_ch1;
    Result.geophoneX = Data_ADS131E08.data_ch2;
    Result.geophoneY = Data_ADS131E08.data_ch3;
    Result.geophoneZ = Data_ADS131E08.data_ch4;
    switch(subframe_counter){
    case 0:
        /*
            !! These fields have been empty yet !!
        */
        //Result.aux_data_low = ADS131E08_CurSet.regim.;
        //Result.aux_data_high = Data_ADS131E08.Fields.data3;
        break;
    case 1:
        //Result.aux_data_low = Data_LIS2DH12TR.Ox;
        //Result.aux_data_high = Data_LIS2DH12TR.Ox;
        break;
    case 2:
         //Result.aux_data_low = Data_LIS2DH12TR.Oy;
        //Result.aux_data_high = Data_LIS2DH12TR.Oy;
        break;
    case 3:
         //Result.aux_data_low = Data_LIS2DH12TR.Oz;
        //Result.aux_data_high = Data_LIS2DH12TR.Oz;
        break;
    case 4:
        Result.aux_data_low = ADS131E08_CurSet.array[ADS131E08_CH1SET_ADDRESS-1];
        Result.aux_data_high = ADS131E08_CurSet.array[ADS131E08_CH2SET_ADDRESS-1];
        break;
    case 5:
        Result.aux_data_low = ADS131E08_CurSet.array[ADS131E08_CONFIG1_ADDRESS-1];
        Result.aux_data_high = ADS131E08_CurSet.array[ADS131E08_CONFIG2_ADDRESS-1];
        break;
    case 6:
        Result.aux_data_low = ADS131E08_CurSet.array[ADS131E08_CONFIG3_ADDRESS-1];
        break;
    case 7:
        break;
    }
}
void CopyFirstFrame(void){
    memcpy( (void*)line_buf, (void*)&Result, sizeof(Result));
    last_adc_data_sended = 1;
}


/* [] END OF FILE */
