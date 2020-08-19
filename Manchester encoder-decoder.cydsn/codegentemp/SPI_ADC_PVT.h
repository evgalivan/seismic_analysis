/*******************************************************************************
* File Name: .h
* Version 2.50
*
* Description:
*  This private header file contains internal definitions for the SPIM
*  component. Do not use these definitions directly in your application.
*
* Note:
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SPIM_PVT_SPI_ADC_H)
#define CY_SPIM_PVT_SPI_ADC_H

#include "SPI_ADC.h"


/**********************************
*   Functions with external linkage
**********************************/


/**********************************
*   Variables with external linkage
**********************************/

extern volatile uint8 SPI_ADC_swStatusTx;
extern volatile uint8 SPI_ADC_swStatusRx;

#if(SPI_ADC_TX_SOFTWARE_BUF_ENABLED)
    extern volatile uint8 SPI_ADC_txBuffer[SPI_ADC_TX_BUFFER_SIZE];
    extern volatile uint8 SPI_ADC_txBufferRead;
    extern volatile uint8 SPI_ADC_txBufferWrite;
    extern volatile uint8 SPI_ADC_txBufferFull;
#endif /* (SPI_ADC_TX_SOFTWARE_BUF_ENABLED) */

#if(SPI_ADC_RX_SOFTWARE_BUF_ENABLED)
    extern volatile uint8 SPI_ADC_rxBuffer[SPI_ADC_RX_BUFFER_SIZE];
    extern volatile uint8 SPI_ADC_rxBufferRead;
    extern volatile uint8 SPI_ADC_rxBufferWrite;
    extern volatile uint8 SPI_ADC_rxBufferFull;
#endif /* (SPI_ADC_RX_SOFTWARE_BUF_ENABLED) */

#endif /* CY_SPIM_PVT_SPI_ADC_H */


/* [] END OF FILE */
