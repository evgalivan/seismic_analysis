/*******************************************************************************
* File Name: ControlReg_Regim_PM.c
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

#include "ControlReg_Regim.h"

/* Check for removal by optimization */
#if !defined(ControlReg_Regim_Sync_ctrl_reg__REMOVED)

static ControlReg_Regim_BACKUP_STRUCT  ControlReg_Regim_backup = {0u};

    
/*******************************************************************************
* Function Name: ControlReg_Regim_SaveConfig
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
void ControlReg_Regim_SaveConfig(void) 
{
    ControlReg_Regim_backup.controlState = ControlReg_Regim_Control;
}


/*******************************************************************************
* Function Name: ControlReg_Regim_RestoreConfig
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
void ControlReg_Regim_RestoreConfig(void) 
{
     ControlReg_Regim_Control = ControlReg_Regim_backup.controlState;
}


/*******************************************************************************
* Function Name: ControlReg_Regim_Sleep
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
void ControlReg_Regim_Sleep(void) 
{
    ControlReg_Regim_SaveConfig();
}


/*******************************************************************************
* Function Name: ControlReg_Regim_Wakeup
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
void ControlReg_Regim_Wakeup(void)  
{
    ControlReg_Regim_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
