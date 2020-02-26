/*******************************************************************************
* File Name: SigmaReg_PM.c
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

#include "SigmaReg.h"

static SigmaReg_BACKUP_STRUCT SigmaReg_backup =
{
    SigmaReg_DISABLED,

    ((uint32) SigmaReg_DEFAULT_A0),
    ((uint32) SigmaReg_DEFAULT_A1),

    #if(CY_UDB_V0)
        ((uint32) SigmaReg_INT_SRC),
    #endif /* (CY_UDB_V0) */
};


/*******************************************************************************
* Function Name: SigmaReg_SaveConfig
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
void SigmaReg_SaveConfig(void) 
{
    /* Store working registers A0 and A1 */
    SigmaReg_backup.saveSrA0Reg   = CY_GET_REG32(SigmaReg_SHIFT_REG_LSB_PTR);
    SigmaReg_backup.saveSrA1Reg   = CY_GET_REG32(SigmaReg_SHIFT_REG_VALUE_LSB_PTR);

    #if(CY_UDB_V0)
        SigmaReg_backup.saveSrIntMask = SigmaReg_SR_STATUS_MASK;
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: SigmaReg_RestoreConfig
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
void SigmaReg_RestoreConfig(void) 
{
    /* Restore working registers A0 and A1 */
    CY_SET_REG32(SigmaReg_SHIFT_REG_LSB_PTR, SigmaReg_backup.saveSrA0Reg);
    CY_SET_REG32(SigmaReg_SHIFT_REG_VALUE_LSB_PTR, SigmaReg_backup.saveSrA1Reg);

    #if(CY_UDB_V0)
        SigmaReg_SR_STATUS_MASK = ((uint8) SigmaReg_backup.saveSrIntMask);
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: SigmaReg_Sleep
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
void SigmaReg_Sleep(void) 
{
    SigmaReg_backup.enableState = ((uint8) SigmaReg_IS_ENABLED);

    SigmaReg_Stop();
    SigmaReg_SaveConfig();
}


/*******************************************************************************
* Function Name: SigmaReg_Wakeup
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
void SigmaReg_Wakeup(void) 
{
    SigmaReg_RestoreConfig();

    if(0u != SigmaReg_backup.enableState)
    {
        SigmaReg_Enable();
    }
}


/* [] END OF FILE */
