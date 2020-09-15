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

#define FRAME_TAG_MASK (0xF0000000)
#define FRAME_TAG_CONTROL (0x90000000)
#define SUBFRAME_TAG_MASK (0x07000000)
#define SUBFRAME_TAG_IND_CONTROL (0x0100000)
#define SUBFRAME_TAG_GEN_CONTROL (0x0200000)

typedef struct {
    uint32 : 8;
    uint32 mux_gidro: 8;
    uint32 gain_gidro: 8;
    uint32 subframe: 3;
    uint32 fake: 1;
    uint32 frame: 3;
    uint32 label: 1;
    //first word
    uint32 gain_geophone3: 8;
    uint32 gain_geophone2: 8;
    uint32 gain_geophone1: 8;
    uint32 crc:8;
    //second word
    uint32 mux_geophone3: 8;
    uint32 mux_geophone2: 8;
    uint32 mux_geophone1: 8;
    uint32 aux_data_low: 8;
    //third word
    uint32 : 32;
    //last word
}control_ind_adc_frame;

typedef struct {
    uint32 TEST_FREQ: 8;
    uint32 TEST_AMP: 8;
    uint32 INT_TEST: 8;
    uint32 subframe: 3;
    uint32 fake: 1;
    uint32 frame: 3;
    uint32 label: 1;
    //first word
    uint32 : 8;
    uint32 CMRR_SIGNAL: 8;
    uint32 VIBRATOR_SIGNAL: 8;
    uint32 crc:8;
    //second word
    uint32 : 32;
    //third word
    uint32 : 32;
    //last word
}control_gen_adc_frame;

extern control_ind_adc_frame ind_control_adc;
extern control_gen_adc_frame gen_control;

void CopyFirstFrame(void);

/* [] END OF FILE */
