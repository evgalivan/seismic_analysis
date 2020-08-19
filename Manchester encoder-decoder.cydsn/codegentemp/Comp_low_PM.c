/*******************************************************************************
* File Name: Comp_low_PM.c
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

#include "Comp_low.h"

/* Check for removal by optimization */
#if !defined(Comp_low_Sync_ctrl_reg__REMOVED)

static Comp_low_BACKUP_STRUCT  Comp_low_backup = {0u};

    
/*******************************************************************************
* Function Name: Comp_low_SaveConfig
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
void Comp_low_SaveConfig(void) 
{
    Comp_low_backup.controlState = Comp_low_Control;
}


/*******************************************************************************
* Function Name: Comp_low_RestoreConfig
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
void Comp_low_RestoreConfig(void) 
{
     Comp_low_Control = Comp_low_backup.controlState;
}


/*******************************************************************************
* Function Name: Comp_low_Sleep
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
void Comp_low_Sleep(void) 
{
    Comp_low_SaveConfig();
}


/*******************************************************************************
* Function Name: Comp_low_Wakeup
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
void Comp_low_Wakeup(void)  
{
    Comp_low_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
