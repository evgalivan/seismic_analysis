/*******************************************************************************
* File Name: SPI_ADC_PM.c
* Version 2.50
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPI_ADC_PVT.h"

static SPI_ADC_BACKUP_STRUCT SPI_ADC_backup =
{
    SPI_ADC_DISABLED,
    SPI_ADC_BITCTR_INIT,
};


/*******************************************************************************
* Function Name: SPI_ADC_SaveConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SPI_ADC_SaveConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPI_ADC_RestoreConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SPI_ADC_RestoreConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPI_ADC_Sleep
********************************************************************************
*
* Summary:
*  Prepare SPIM Component goes to sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPI_ADC_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPI_ADC_Sleep(void) 
{
    /* Save components enable state */
    SPI_ADC_backup.enableState = ((uint8) SPI_ADC_IS_ENABLED);

    SPI_ADC_Stop();
}


/*******************************************************************************
* Function Name: SPI_ADC_Wakeup
********************************************************************************
*
* Summary:
*  Prepare SPIM Component to wake up.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPI_ADC_backup - used when non-retention registers are restored.
*  SPI_ADC_txBufferWrite - modified every function call - resets to
*  zero.
*  SPI_ADC_txBufferRead - modified every function call - resets to
*  zero.
*  SPI_ADC_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPI_ADC_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPI_ADC_Wakeup(void) 
{
    #if(SPI_ADC_RX_SOFTWARE_BUF_ENABLED)
        SPI_ADC_rxBufferFull  = 0u;
        SPI_ADC_rxBufferRead  = 0u;
        SPI_ADC_rxBufferWrite = 0u;
    #endif /* (SPI_ADC_RX_SOFTWARE_BUF_ENABLED) */

    #if(SPI_ADC_TX_SOFTWARE_BUF_ENABLED)
        SPI_ADC_txBufferFull  = 0u;
        SPI_ADC_txBufferRead  = 0u;
        SPI_ADC_txBufferWrite = 0u;
    #endif /* (SPI_ADC_TX_SOFTWARE_BUF_ENABLED) */

    /* Clear any data from the RX and TX FIFO */
    SPI_ADC_ClearFIFO();

    /* Restore components block enable state */
    if(0u != SPI_ADC_backup.enableState)
    {
        SPI_ADC_Enable();
    }
}


/* [] END OF FILE */
