/*******************************************************************************
* File Name: FrameAllow_PM.c
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

#include "FrameAllow.h"

/* Check for removal by optimization */
#if !defined(FrameAllow_Sync_ctrl_reg__REMOVED)

static FrameAllow_BACKUP_STRUCT  FrameAllow_backup = {0u};

    
/*******************************************************************************
* Function Name: FrameAllow_SaveConfig
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
void FrameAllow_SaveConfig(void) 
{
    FrameAllow_backup.controlState = FrameAllow_Control;
}


/*******************************************************************************
* Function Name: FrameAllow_RestoreConfig
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
void FrameAllow_RestoreConfig(void) 
{
     FrameAllow_Control = FrameAllow_backup.controlState;
}


/*******************************************************************************
* Function Name: FrameAllow_Sleep
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
void FrameAllow_Sleep(void) 
{
    FrameAllow_SaveConfig();
}


/*******************************************************************************
* Function Name: FrameAllow_Wakeup
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
void FrameAllow_Wakeup(void)  
{
    FrameAllow_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
