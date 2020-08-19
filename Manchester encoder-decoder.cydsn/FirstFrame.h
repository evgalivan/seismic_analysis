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

#include <cytypes.h>



typedef struct {
    uint32 gidrophone:24;
    uint32 subframe: 3;
    uint32 fake: 1;
    uint32 frame: 3;
    uint32 label: 1;
    //first word
    uint32 geophoneX: 24;
    uint32 crc:8;
    //second word
    uint32 geophoneY: 24;
    uint32 aux_data_low: 8;
    //third word
    uint32 geophoneZ: 24;
    uint32 aux_data_high: 8;
    //last word
}data_adc_result_frame;

extern uint32 last_adc_data_sended;

void PrepareFirstFrame(void);
void CopyFirstFrame(void);

/* [] END OF FILE */
