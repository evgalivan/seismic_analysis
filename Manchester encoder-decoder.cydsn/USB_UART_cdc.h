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
#include "USBUART_cdc.h"

#define LENGTH_OF(Array) (sizeof(Array)/sizeof(Array[0]))
#define USBUART_BUFFER_SIZE (64u)
#define LENGTH_OF(Array) (sizeof(Array)/sizeof(Array[0]))

extern int32 say_hello_flag;
extern uint16 count;
extern uint8 buffer[USBUART_BUFFER_SIZE];

void USBUARTInitCDC(void);
void Service_USB(void);

/* [] END OF FILE */
