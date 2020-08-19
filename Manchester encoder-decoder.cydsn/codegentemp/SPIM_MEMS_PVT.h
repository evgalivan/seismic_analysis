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

#if !defined(CY_SPIM_PVT_SPIM_MEMS_H)
#define CY_SPIM_PVT_SPIM_MEMS_H

#include "SPIM_MEMS.h"


/**********************************
*   Functions with external linkage
**********************************/


/**********************************
*   Variables with external linkage
**********************************/

extern volatile uint8 SPIM_MEMS_swStatusTx;
extern volatile uint8 SPIM_MEMS_swStatusRx;

#if(SPIM_MEMS_TX_SOFTWARE_BUF_ENABLED)
    extern volatile uint8 SPIM_MEMS_txBuffer[SPIM_MEMS_TX_BUFFER_SIZE];
    extern volatile uint8 SPIM_MEMS_txBufferRead;
    extern volatile uint8 SPIM_MEMS_txBufferWrite;
    extern volatile uint8 SPIM_MEMS_txBufferFull;
#endif /* (SPIM_MEMS_TX_SOFTWARE_BUF_ENABLED) */

#if(SPIM_MEMS_RX_SOFTWARE_BUF_ENABLED)
    extern volatile uint8 SPIM_MEMS_rxBuffer[SPIM_MEMS_RX_BUFFER_SIZE];
    extern volatile uint8 SPIM_MEMS_rxBufferRead;
    extern volatile uint8 SPIM_MEMS_rxBufferWrite;
    extern volatile uint8 SPIM_MEMS_rxBufferFull;
#endif /* (SPIM_MEMS_RX_SOFTWARE_BUF_ENABLED) */

#endif /* CY_SPIM_PVT_SPIM_MEMS_H */


/* [] END OF FILE */
