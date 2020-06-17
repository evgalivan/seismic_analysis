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
#include "Agg_sent.h"
#include "USB_UART_cdc.h"
#include "string.h"
#include "stdio.h"
#include "stdio_e.h"

uint8 welcome_massage[] = {"Text you command: "};
uint16 count, count2;
uint8 buffer[USBUART_BUFFER_SIZE];
uint8 buffer2[USBUART_BUFFER_SIZE];
uint8* token_buffer2 = buffer2;

void USBARTInitCDC(void){
        /* Host can send double SET_INTERFACE request. */
        if (0u != USBUART_IsConfigurationChanged())
        {
            /* Initialize IN endpoints when device is configured. */
            if (0u != USBUART_GetConfiguration())
            {
                /* Enumeration is done, enable OUT endpoint to receive data 
                 * from host. */
                USBUART_CDC_Init();
                
            }
        }
}

void Service_USB(void){
    if (0u != USBUART_GetConfiguration())
        {
           
            /* Check for input data from host. */
            if (0u != USBUART_DataIsReady())
            {
                uint8 tmp = 0;
                /* Read received data and re-enable OUT endpoint. */
                count = USBUART_GetAll(buffer);
                
                while (count--)
                {
                    if(0 != InsertByte(&usb_context.primary_buf, buffer[tmp++])){ 
                        if(1 == agg_sent(&usb_context)) usb_context.sentence_ready=1;
                        InsertByte(&usb_context.primary_buf, buffer[tmp-1]);
                    }
                }
            }
        }
}
#if 0
void Send_USB(){

    /* Wait until component is ready to send data to host. */
    while (0u == USBUART_CDCIsReady())
    {
    }
    
    /* Send data back to host. */
    USBUART_PutData(buffer, count);
    

    /* If the last sent packet is exactly the maximum packet 
    *  size, it is followed by a zero-length packet to assure
    *  that the end of the segment is properly identified by 
    *  the terminal.
    */
    if (USBUART_BUFFER_SIZE == count)
    {
        /* Wait until component is ready to send data to PC. */
        while (0u == USBUART_CDCIsReady())
        {
        }

        /* Send zero-length packet to PC. */
        USBUART_PutData(NULL, 0u);
    }
}
#endif
/* [] END OF FILE */
