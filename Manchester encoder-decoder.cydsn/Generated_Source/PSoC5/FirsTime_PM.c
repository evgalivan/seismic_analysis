/*******************************************************************************
* File Name: FirsTime_PM.c
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

#include "FirsTime.h"

/* Check for removal by optimization */
#if !defined(FirsTime_Sync_ctrl_reg__REMOVED)

static FirsTime_BACKUP_STRUCT  FirsTime_backup = {0u};

    
/*******************************************************************************
* Function Name: FirsTime_SaveConfig
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
void FirsTime_SaveConfig(void) 
{
    FirsTime_backup.controlState = FirsTime_Control;
}


/*******************************************************************************
* Function Name: FirsTime_RestoreConfig
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
void FirsTime_RestoreConfig(void) 
{
     FirsTime_Control = FirsTime_backup.controlState;
}


/*******************************************************************************
* Function Name: FirsTime_Sleep
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
void FirsTime_Sleep(void) 
{
    FirsTime_SaveConfig();
}


/*******************************************************************************
* Function Name: FirsTime_Wakeup
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
void FirsTime_Wakeup(void)  
{
    FirsTime_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
