/*******************************************************************************
* File Name: Period_PM.c
* Version 2.30
*
* Description:
*  This file provides the API source code for sleep mode support for Shift
*  Register component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Period.h"

static Period_BACKUP_STRUCT Period_backup =
{
    Period_DISABLED,

    ((uint16) Period_DEFAULT_A0),
    ((uint16) Period_DEFAULT_A1),

    #if(CY_UDB_V0)
        ((uint16) Period_INT_SRC),
    #endif /* (CY_UDB_V0) */
};


/*******************************************************************************
* Function Name: Period_SaveConfig
********************************************************************************
*
* Summary:
*  Saves Shift Register configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Period_SaveConfig(void) 
{
    /* Store working registers A0 and A1 */
    Period_backup.saveSrA0Reg   = CY_GET_REG16(Period_SHIFT_REG_LSB_PTR);
    Period_backup.saveSrA1Reg   = CY_GET_REG16(Period_SHIFT_REG_VALUE_LSB_PTR);

    #if(CY_UDB_V0)
        Period_backup.saveSrIntMask = Period_SR_STATUS_MASK;
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: Period_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores Shift Register configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Period_RestoreConfig(void) 
{
    /* Restore working registers A0 and A1 */
    CY_SET_REG16(Period_SHIFT_REG_LSB_PTR, Period_backup.saveSrA0Reg);
    CY_SET_REG16(Period_SHIFT_REG_VALUE_LSB_PTR, Period_backup.saveSrA1Reg);

    #if(CY_UDB_V0)
        Period_SR_STATUS_MASK = ((uint8) Period_backup.saveSrIntMask);
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: Period_Sleep
********************************************************************************
*
* Summary:
*  Prepare the component to enter a Sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Period_Sleep(void) 
{
    Period_backup.enableState = ((uint8) Period_IS_ENABLED);

    Period_Stop();
    Period_SaveConfig();
}


/*******************************************************************************
* Function Name: Period_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Period_Wakeup(void) 
{
    Period_RestoreConfig();

    if(0u != Period_backup.enableState)
    {
        Period_Enable();
    }
}


/* [] END OF FILE */
