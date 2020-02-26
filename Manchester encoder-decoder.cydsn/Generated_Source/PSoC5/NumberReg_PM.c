/*******************************************************************************
* File Name: NumberReg_PM.c
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

#include "NumberReg.h"

static NumberReg_BACKUP_STRUCT NumberReg_backup =
{
    NumberReg_DISABLED,

    ((uint32) NumberReg_DEFAULT_A0),
    ((uint32) NumberReg_DEFAULT_A1),

    #if(CY_UDB_V0)
        ((uint32) NumberReg_INT_SRC),
    #endif /* (CY_UDB_V0) */
};


/*******************************************************************************
* Function Name: NumberReg_SaveConfig
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
void NumberReg_SaveConfig(void) 
{
    /* Store working registers A0 and A1 */
    NumberReg_backup.saveSrA0Reg   = CY_GET_REG32(NumberReg_SHIFT_REG_LSB_PTR);
    NumberReg_backup.saveSrA1Reg   = CY_GET_REG32(NumberReg_SHIFT_REG_VALUE_LSB_PTR);

    #if(CY_UDB_V0)
        NumberReg_backup.saveSrIntMask = NumberReg_SR_STATUS_MASK;
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: NumberReg_RestoreConfig
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
void NumberReg_RestoreConfig(void) 
{
    /* Restore working registers A0 and A1 */
    CY_SET_REG32(NumberReg_SHIFT_REG_LSB_PTR, NumberReg_backup.saveSrA0Reg);
    CY_SET_REG32(NumberReg_SHIFT_REG_VALUE_LSB_PTR, NumberReg_backup.saveSrA1Reg);

    #if(CY_UDB_V0)
        NumberReg_SR_STATUS_MASK = ((uint8) NumberReg_backup.saveSrIntMask);
    #endif /* (CY_UDB_V0) */
}


/*******************************************************************************
* Function Name: NumberReg_Sleep
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
void NumberReg_Sleep(void) 
{
    NumberReg_backup.enableState = ((uint8) NumberReg_IS_ENABLED);

    NumberReg_Stop();
    NumberReg_SaveConfig();
}


/*******************************************************************************
* Function Name: NumberReg_Wakeup
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
void NumberReg_Wakeup(void) 
{
    NumberReg_RestoreConfig();

    if(0u != NumberReg_backup.enableState)
    {
        NumberReg_Enable();
    }
}


/* [] END OF FILE */
