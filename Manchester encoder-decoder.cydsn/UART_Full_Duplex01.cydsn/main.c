/*****************************************************************************
* File Name: main.c
*
* Version: 1.10
*
* Description: 
*  This code example project demonstrates how to communicate between 
*  the PC and UART component in Full duplex mode. The UART has receiver(RX) and 
*  transmitter(TX) part. The data received by RX is looped back to the TX.
*
* Related Document: 
* CE210741_UART_Full_Duplex_and_printf_Support_with_PSoC_3_4_5LP.pdf
*
* Hardware Dependency: See 
* CE210741_UART_Full_Duplex_and_printf_Support_with_PSoC_3_4_5LP.pdf
*
*******************************************************************************
* Copyright (2017), Cypress Semiconductor Corporation. All rights reserved.
*******************************************************************************
* This software, including source code, documentation and related materials
* (“Software”), is owned by Cypress Semiconductor Corporation or one of its
* subsidiaries (“Cypress”) and is protected by and subject to worldwide patent
* protection (United States and foreign), United States copyright laws and
* international treaty provisions. Therefore, you may use this Software only
* as provided in the license agreement accompanying the software package from
* which you obtained this Software (“EULA”).
*
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software source
* code solely for use in connection with Cypress’s integrated circuit products.
* Any reproduction, modification, translation, compilation, or representation
* of this Software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND, 
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED 
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress 
* reserves the right to make changes to the Software without notice. Cypress 
* does not assume any liability arising out of the application or use of the 
* Software or any product or circuit described in the Software. Cypress does 
* not authorize its products for use in any products where a malfunction or 
* failure of the Cypress product may reasonably be expected to result in 
* significant property damage, injury or death (“High Risk Product”). By 
* including Cypress’s product in a High Risk Product, the manufacturer of such 
* system or application assumes all risk of such use and in doing so agrees to 
* indemnify Cypress against all liability. 
*******************************************************************************/

#include <project.h>
#include <stdio.h>
#include "common.h"


/* Add an explicit reference to the floating point printf library to allow
the usage of floating point conversion specifier */
#if defined (__GNUC__)
    asm (".global _printf_float");
#endif

uint8 errorStatus = 0u;


/*******************************************************************************
* Function Name: RxIsr
********************************************************************************
*
* Summary:
*  Interrupt Service Routine for RX portion of the UART
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
CY_ISR(RxIsr)
{
    uint8 rxStatus;         
    uint8 rxData;           
    
    do
    {
        /* Read receiver status register */
        rxStatus = UART_RXSTATUS_REG;

        if((rxStatus & (UART_RX_STS_BREAK      | UART_RX_STS_PAR_ERROR |
                        UART_RX_STS_STOP_ERROR | UART_RX_STS_OVERRUN)) != 0u)
        {
            /* ERROR handling. */
            errorStatus |= rxStatus & ( UART_RX_STS_BREAK      | UART_RX_STS_PAR_ERROR | 
                                        UART_RX_STS_STOP_ERROR | UART_RX_STS_OVERRUN);
        }
        
        if((rxStatus & UART_RX_STS_FIFO_NOTEMPTY) != 0u)
        {
            /* Read data from the RX data register */
            rxData = UART_RXDATA_REG;
            if(errorStatus == 0u)
            {
                /* Send data backward */
                UART_TXDATA_REG = rxData;
            }
        }
    }while((rxStatus & UART_RX_STS_FIFO_NOTEMPTY) != 0u);

}
    

/*******************************************************************************
* Function Name: main()
********************************************************************************
* Summary:
*  Main function for the project.
*
* Theory:
*  The function starts UART and interrupt components.
*
*******************************************************************************/
int main()
{
    uint8 button = 0u;
    uint8 buttonPre = 0u;
    
    LED_Write(LED_OFF);     /* Clear LED */

    UART_Start();           /* Start communication component */
    UART_PutString("UART Full Duplex and printf() support Code Example Project \r\n");

#if(INTERRUPT_CODE_ENABLED == ENABLED)
    isr_rx_StartEx(RxIsr);
#endif /* INTERRUPT_CODE_ENABLED == ENABLED */
    
    CyGlobalIntEnable;      /* Enable global interrupts. */
    
#if(UART_PRINTF_ENABLED == ENABLED)
{
    uint32 i = 444444444u;
    float f = 55.55555f;
    
    /* Use printf() function which will send formatted data through "UART" */
    printf("Test printf function. long:%ld, ", i);    
    /* PSoC 3: The total number of bytes that may be passed to this function is limited
       due to the memory restrictions imposed by the 8051. 
       A maximum of 40 bytes may be passed in LARGE model. 
    */
    printf("float:%2.5f \r\n", f);    
}
#endif /* UART_PRINTF_ENABLED == ENABLED */
    UART_PutString("Enter the characters to transmit \r\n");

    for(;;)
    {
        if(errorStatus != 0u)
        {
            /* Indicate an error on the LED */
            LED_Write(LED_ON);
            /* Clear error status */
            errorStatus = 0u;
        }
        
        /***********************************************************************
        * Handle SW2 press. 
        ***********************************************************************/
        button = SW2_Read();
        if((button == 0u) && (buttonPre != 0u))
        {
            LED_Write(LED_OFF);     /* Clear LED */
        }
        buttonPre = button;
        
        #if(INTERRUPT_CODE_ENABLED != ENABLED)
        {
            uint8 rxStatus;         
            uint8 rxData;           
            
            /* Read status register. */
            rxStatus = UART_ReadRxStatus();
            
            /* Check if data is received. */
            if((rxStatus & UART_RX_STS_FIFO_NOTEMPTY) != 0u)    
            {
                /* Read received data */
                rxData = UART_ReadRxData();

                /* Check status on error*/
                if((rxStatus & (UART_RX_STS_BREAK      | UART_RX_STS_PAR_ERROR |
                                UART_RX_STS_STOP_ERROR | UART_RX_STS_OVERRUN)) != 0u)
                {
                    errorStatus |= rxStatus & ( UART_RX_STS_BREAK      | UART_RX_STS_PAR_ERROR | 
                                                UART_RX_STS_STOP_ERROR | UART_RX_STS_OVERRUN);
                }
                else
                {
                    /* Send data backward */
                    UART_WriteTxData(rxData);
                }
            }
        }
        #endif /* INTERRUPT_CODE_ENABLED != ENABLED */
    }
}

/* [] END OF FILE */
