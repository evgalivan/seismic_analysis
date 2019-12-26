/*******************************************************************************
* File Name: FirstLoad_PM.c
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

#include "FirstLoad.h"

/* Check for removal by optimization */
#if !defined(FirstLoad_Sync_ctrl_reg__REMOVED)

static FirstLoad_BACKUP_STRUCT  FirstLoad_backup = {0u};

    
/*******************************************************************************
* Function Name: FirstLoad_SaveConfig
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
void FirstLoad_SaveConfig(void) 
{
    FirstLoad_backup.controlState = FirstLoad_Control;
}


/*******************************************************************************
* Function Name: FirstLoad_RestoreConfig
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
void FirstLoad_RestoreConfig(void) 
{
     FirstLoad_Control = FirstLoad_backup.controlState;
}


/*******************************************************************************
* Function Name: FirstLoad_Sleep
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
void FirstLoad_Sleep(void) 
{
    FirstLoad_SaveConfig();
}


/*******************************************************************************
* Function Name: FirstLoad_Wakeup
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
void FirstLoad_Wakeup(void)  
{
    FirstLoad_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
