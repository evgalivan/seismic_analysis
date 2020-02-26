/*******************************************************************************
* File Name: Control_Period_PM.c
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

#include "Control_Period.h"

/* Check for removal by optimization */
#if !defined(Control_Period_Sync_ctrl_reg__REMOVED)

static Control_Period_BACKUP_STRUCT  Control_Period_backup = {0u};

    
/*******************************************************************************
* Function Name: Control_Period_SaveConfig
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
void Control_Period_SaveConfig(void) 
{
    Control_Period_backup.controlState = Control_Period_Control;
}


/*******************************************************************************
* Function Name: Control_Period_RestoreConfig
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
void Control_Period_RestoreConfig(void) 
{
     Control_Period_Control = Control_Period_backup.controlState;
}


/*******************************************************************************
* Function Name: Control_Period_Sleep
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
void Control_Period_Sleep(void) 
{
    Control_Period_SaveConfig();
}


/*******************************************************************************
* Function Name: Control_Period_Wakeup
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
void Control_Period_Wakeup(void)  
{
    Control_Period_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
