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
#ifndef FRAME_H
#define FRAME_H
#include "cytypes.h"
#define WORDS_QUANTITY 4
typedef struct{
    uint32 items[WORDS_QUANTITY];
}frame_t;
#define FRAMES_QUANTITY 11
typedef union{
    uint32    words[WORDS_QUANTITY*FRAMES_QUANTITY];
    frame_t     frames[FRAMES_QUANTITY];
}exchange_unit;
    
#endif
/* [] END OF FILE */
