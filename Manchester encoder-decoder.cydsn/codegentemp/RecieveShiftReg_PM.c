/*******************************************************************************
* File Name: RecieveShiftReg_PM.c
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

#include "RecieveShiftReg.h"

static RecieveShiftReg_BACKUP_STRUCT RecieveShiftReg_backup =
{
    RecieveShiftReg_DISABLED,

    ((uint32) RecieveShiftReg_DEFAULT_A0),
    ((uint32) RecieveShiftReg_DEFAULT_A1),

    #if(CY_UDB_V0)
        ((uint32) RecieveShiftReg_INT_SRC),
    #endif /* (CY_UDB_V0) */
};


/*******************************************************************************
* Function Name: RecieveShiftReg_SaveConfig
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
void RecieveShiftReg_SaveConfig(void) 
{
    /* Store working registers A0 and A1 */
    RecieveShiftReg_backup.saveSrA0Reg   = CY_GET_REG32(RecieveShiftReg_SHIFT_REG_LSB_PTR);
    RecieveShiftReg_backup.saveSrA1Reg   = CY_GET_REG32(RecieveShiftReg_SHIFT_REG_VALUE_LSB_PTR);

    #if(CY_UDB_V0)
        RecieveShiftReg_backup.saveSrIntMask = RecieveShiftReg_SR_STATUS_MASK;
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: RecieveShiftReg_RestoreConfig
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
void RecieveShiftReg_RestoreConfig(void) 
{
    /* Restore working registers A0 and A1 */
    CY_SET_REG32(RecieveShiftReg_SHIFT_REG_LSB_PTR, RecieveShiftReg_backup.saveSrA0Reg);
    CY_SET_REG32(RecieveShiftReg_SHIFT_REG_VALUE_LSB_PTR, RecieveShiftReg_backup.saveSrA1Reg);

    #if(CY_UDB_V0)
        RecieveShiftReg_SR_STATUS_MASK = ((uint8) RecieveShiftReg_backup.saveSrIntMask);
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: RecieveShiftReg_Sleep
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
void RecieveShiftReg_Sleep(void) 
{
    RecieveShiftReg_backup.enableState = ((uint8) RecieveShiftReg_IS_ENABLED);

    RecieveShiftReg_Stop();
    RecieveShiftReg_SaveConfig();
}


/*******************************************************************************
* Function Name: RecieveShiftReg_Wakeup
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
void RecieveShiftReg_Wakeup(void) 
{
    RecieveShiftReg_RestoreConfig();

    if(0u != RecieveShiftReg_backup.enableState)
    {
        RecieveShiftReg_Enable();
    }
}


/* [] END OF FILE */
