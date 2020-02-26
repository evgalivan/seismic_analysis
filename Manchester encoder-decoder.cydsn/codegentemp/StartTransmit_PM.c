/*******************************************************************************
* File Name: StartTransmit_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "StartTransmit.h"

/* Check for removal by optimization */
#if !defined(StartTransmit_Sync_ctrl_reg__REMOVED)

static StartTransmit_BACKUP_STRUCT  StartTransmit_backup = {0u};

    
/*******************************************************************************
* Function Name: StartTransmit_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void StartTransmit_SaveConfig(void) 
{
    StartTransmit_backup.controlState = StartTransmit_Control;
}


/*******************************************************************************
* Function Name: StartTransmit_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void StartTransmit_RestoreConfig(void) 
{
     StartTransmit_Control = StartTransmit_backup.controlState;
}


/*******************************************************************************
* Function Name: StartTransmit_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void StartTransmit_Sleep(void) 
{
    StartTransmit_SaveConfig();
}


/*******************************************************************************
* Function Name: StartTransmit_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void StartTransmit_Wakeup(void)  
{
    StartTransmit_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
