/*******************************************************************************
* File Name: Control_DeltaReg_PM.c
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

#include "Control_DeltaReg.h"

/* Check for removal by optimization */
#if !defined(Control_DeltaReg_Sync_ctrl_reg__REMOVED)

static Control_DeltaReg_BACKUP_STRUCT  Control_DeltaReg_backup = {0u};

    
/*******************************************************************************
* Function Name: Control_DeltaReg_SaveConfig
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
void Control_DeltaReg_SaveConfig(void) 
{
    Control_DeltaReg_backup.controlState = Control_DeltaReg_Control;
}


/*******************************************************************************
* Function Name: Control_DeltaReg_RestoreConfig
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
void Control_DeltaReg_RestoreConfig(void) 
{
     Control_DeltaReg_Control = Control_DeltaReg_backup.controlState;
}


/*******************************************************************************
* Function Name: Control_DeltaReg_Sleep
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
void Control_DeltaReg_Sleep(void) 
{
    Control_DeltaReg_SaveConfig();
}


/*******************************************************************************
* Function Name: Control_DeltaReg_Wakeup
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
void Control_DeltaReg_Wakeup(void)  
{
    Control_DeltaReg_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
