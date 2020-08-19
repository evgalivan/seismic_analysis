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
#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

/***************************************
*        Data Struct Definition
***************************************/

typedef struct {
    uint32 status: 24;
    uint32 data0: 24;
    uint32 data1: 24;
    uint32 data2: 24;
    uint32 data3: 24;
    uint32 data4: 24;
    uint32 data5: 24;
    uint32 data6: 24;
    uint32 data7: 24;
}burst_read;

typedef union{
    uint8 array[27];
    burst_read Fields;
}exchanged_subject;

extern exchanged_subject Data_ADS131E08;

/* [] END OF FILE */
