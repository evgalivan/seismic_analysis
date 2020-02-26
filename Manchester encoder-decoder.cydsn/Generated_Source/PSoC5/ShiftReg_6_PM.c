/*******************************************************************************
* File Name: ShiftReg_6_PM.c
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

#include "ShiftReg_6.h"

static ShiftReg_6_BACKUP_STRUCT ShiftReg_6_backup =
{
    ShiftReg_6_DISABLED,

    ((uint32) ShiftReg_6_DEFAULT_A0),
    ((uint32) ShiftReg_6_DEFAULT_A1),

    #if(CY_UDB_V0)
        ((uint32) ShiftReg_6_INT_SRC),
    #endif /* (CY_UDB_V0) */
};


/*******************************************************************************
* Function Name: ShiftReg_6_SaveConfig
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
void ShiftReg_6_SaveConfig(void) 
{
    /* Store working registers A0 and A1 */
    ShiftReg_6_backup.saveSrA0Reg   = CY_GET_REG32(ShiftReg_6_SHIFT_REG_LSB_PTR);
    ShiftReg_6_backup.saveSrA1Reg   = CY_GET_REG32(ShiftReg_6_SHIFT_REG_VALUE_LSB_PTR);

    #if(CY_UDB_V0)
        ShiftReg_6_backup.saveSrIntMask = ShiftReg_6_SR_STATUS_MASK;
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: ShiftReg_6_RestoreConfig
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
void ShiftReg_6_RestoreConfig(void) 
{
    /* Restore working registers A0 and A1 */
    CY_SET_REG32(ShiftReg_6_SHIFT_REG_LSB_PTR, ShiftReg_6_backup.saveSrA0Reg);
    CY_SET_REG32(ShiftReg_6_SHIFT_REG_VALUE_LSB_PTR, ShiftReg_6_backup.saveSrA1Reg);

    #if(CY_UDB_V0)
        ShiftReg_6_SR_STATUS_MASK = ((uint8) ShiftReg_6_backup.saveSrIntMask);
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: ShiftReg_6_Sleep
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
void ShiftReg_6_Sleep(void) 
{
    ShiftReg_6_backup.enableState = ((uint8) ShiftReg_6_IS_ENABLED);

    ShiftReg_6_Stop();
    ShiftReg_6_SaveConfig();
}


/*******************************************************************************
* Function Name: ShiftReg_6_Wakeup
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
void ShiftReg_6_Wakeup(void) 
{
    ShiftReg_6_RestoreConfig();

    if(0u != ShiftReg_6_backup.enableState)
    {
        ShiftReg_6_Enable();
    }
}


/* [] END OF FILE */
