/*******************************************************************************
* File Name: DeltaReg_PM.c
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

#include "DeltaReg.h"

static DeltaReg_BACKUP_STRUCT DeltaReg_backup =
{
    DeltaReg_DISABLED,

    ((uint32) DeltaReg_DEFAULT_A0),
    ((uint32) DeltaReg_DEFAULT_A1),

    #if(CY_UDB_V0)
        ((uint32) DeltaReg_INT_SRC),
    #endif /* (CY_UDB_V0) */
};


/*******************************************************************************
* Function Name: DeltaReg_SaveConfig
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
void DeltaReg_SaveConfig(void) 
{
    /* Store working registers A0 and A1 */
    DeltaReg_backup.saveSrA0Reg   = CY_GET_REG32(DeltaReg_SHIFT_REG_LSB_PTR);
    DeltaReg_backup.saveSrA1Reg   = CY_GET_REG32(DeltaReg_SHIFT_REG_VALUE_LSB_PTR);

    #if(CY_UDB_V0)
        DeltaReg_backup.saveSrIntMask = DeltaReg_SR_STATUS_MASK;
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: DeltaReg_RestoreConfig
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
void DeltaReg_RestoreConfig(void) 
{
    /* Restore working registers A0 and A1 */
    CY_SET_REG32(DeltaReg_SHIFT_REG_LSB_PTR, DeltaReg_backup.saveSrA0Reg);
    CY_SET_REG32(DeltaReg_SHIFT_REG_VALUE_LSB_PTR, DeltaReg_backup.saveSrA1Reg);

    #if(CY_UDB_V0)
        DeltaReg_SR_STATUS_MASK = ((uint8) DeltaReg_backup.saveSrIntMask);
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: DeltaReg_Sleep
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
void DeltaReg_Sleep(void) 
{
    DeltaReg_backup.enableState = ((uint8) DeltaReg_IS_ENABLED);

    DeltaReg_Stop();
    DeltaReg_SaveConfig();
}


/*******************************************************************************
* Function Name: DeltaReg_Wakeup
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
void DeltaReg_Wakeup(void) 
{
    DeltaReg_RestoreConfig();

    if(0u != DeltaReg_backup.enableState)
    {
        DeltaReg_Enable();
    }
}


/* [] END OF FILE */
