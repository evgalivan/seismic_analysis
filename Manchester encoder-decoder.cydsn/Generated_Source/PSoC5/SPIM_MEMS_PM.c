/*******************************************************************************
* File Name: SPIM_MEMS_PM.c
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

#include "SPIM_MEMS_PVT.h"

static SPIM_MEMS_BACKUP_STRUCT SPIM_MEMS_backup =
{
    SPIM_MEMS_DISABLED,
    SPIM_MEMS_BITCTR_INIT,
};


/*******************************************************************************
* Function Name: SPIM_MEMS_SaveConfig
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
void SPIM_MEMS_SaveConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPIM_MEMS_RestoreConfig
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
void SPIM_MEMS_RestoreConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPIM_MEMS_Sleep
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
*  SPIM_MEMS_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_MEMS_Sleep(void) 
{
    /* Save components enable state */
    SPIM_MEMS_backup.enableState = ((uint8) SPIM_MEMS_IS_ENABLED);

    SPIM_MEMS_Stop();
}


/*******************************************************************************
* Function Name: SPIM_MEMS_Wakeup
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
*  SPIM_MEMS_backup - used when non-retention registers are restored.
*  SPIM_MEMS_txBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_MEMS_txBufferRead - modified every function call - resets to
*  zero.
*  SPIM_MEMS_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_MEMS_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_MEMS_Wakeup(void) 
{
    #if(SPIM_MEMS_RX_SOFTWARE_BUF_ENABLED)
        SPIM_MEMS_rxBufferFull  = 0u;
        SPIM_MEMS_rxBufferRead  = 0u;
        SPIM_MEMS_rxBufferWrite = 0u;
    #endif /* (SPIM_MEMS_RX_SOFTWARE_BUF_ENABLED) */

    #if(SPIM_MEMS_TX_SOFTWARE_BUF_ENABLED)
        SPIM_MEMS_txBufferFull  = 0u;
        SPIM_MEMS_txBufferRead  = 0u;
        SPIM_MEMS_txBufferWrite = 0u;
    #endif /* (SPIM_MEMS_TX_SOFTWARE_BUF_ENABLED) */

    /* Clear any data from the RX and TX FIFO */
    SPIM_MEMS_ClearFIFO();

    /* Restore components block enable state */
    if(0u != SPIM_MEMS_backup.enableState)
    {
        SPIM_MEMS_Enable();
    }
}


/* [] END OF FILE */
