/*******************************************************************************
* File Name: TransmitShiftReg_PM.c
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

#include "TransmitShiftReg.h"

static TransmitShiftReg_BACKUP_STRUCT TransmitShiftReg_backup =
{
    TransmitShiftReg_DISABLED,

    ((uint32) TransmitShiftReg_DEFAULT_A0),
    ((uint32) TransmitShiftReg_DEFAULT_A1),

    #if(CY_UDB_V0)
        ((uint32) TransmitShiftReg_INT_SRC),
    #endif /* (CY_UDB_V0) */
};


/*******************************************************************************
* Function Name: TransmitShiftReg_SaveConfig
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
void TransmitShiftReg_SaveConfig(void) 
{
    /* Store working registers A0 and A1 */
    TransmitShiftReg_backup.saveSrA0Reg   = CY_GET_REG32(TransmitShiftReg_SHIFT_REG_LSB_PTR);
    TransmitShiftReg_backup.saveSrA1Reg   = CY_GET_REG32(TransmitShiftReg_SHIFT_REG_VALUE_LSB_PTR);

    #if(CY_UDB_V0)
        TransmitShiftReg_backup.saveSrIntMask = TransmitShiftReg_SR_STATUS_MASK;
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: TransmitShiftReg_RestoreConfig
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
void TransmitShiftReg_RestoreConfig(void) 
{
    /* Restore working registers A0 and A1 */
    CY_SET_REG32(TransmitShiftReg_SHIFT_REG_LSB_PTR, TransmitShiftReg_backup.saveSrA0Reg);
    CY_SET_REG32(TransmitShiftReg_SHIFT_REG_VALUE_LSB_PTR, TransmitShiftReg_backup.saveSrA1Reg);

    #if(CY_UDB_V0)
        TransmitShiftReg_SR_STATUS_MASK = ((uint8) TransmitShiftReg_backup.saveSrIntMask);
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: TransmitShiftReg_Sleep
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
void TransmitShiftReg_Sleep(void) 
{
    TransmitShiftReg_backup.enableState = ((uint8) TransmitShiftReg_IS_ENABLED);

    TransmitShiftReg_Stop();
    TransmitShiftReg_SaveConfig();
}


/*******************************************************************************
* Function Name: TransmitShiftReg_Wakeup
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
void TransmitShiftReg_Wakeup(void) 
{
    TransmitShiftReg_RestoreConfig();

    if(0u != TransmitShiftReg_backup.enableState)
    {
        TransmitShiftReg_Enable();
    }
}


/* [] END OF FILE */
