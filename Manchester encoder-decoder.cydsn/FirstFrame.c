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
    Result.gidrophone = Data_ADS131E08.Fields.data0;
    Result.geophoneX = Data_ADS131E08.Fields.data1;
    Result.geophoneY = Data_ADS131E08.Fields.data2;
    Result.geophoneZ = Data_ADS131E08.Fields.data3;
    switch(subframe_counter){
    case 0:
//        Result.aux_data_low = Data_ADS131E08.Fields.data2;
//        Result.aux_data_high = Data_ADS131E08.Fields.data3;
        break;
    case 1:
//        Result.aux_data_low = Data_ADS131E08.Fields.data2;
//        Result.aux_data_high = Data_ADS131E08.Fields.data3;
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
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
