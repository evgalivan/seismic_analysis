/*******************************************************************************
* File Name: BitCounterDec_PM.c  
* Version 3.0
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "BitCounterDec.h"

static BitCounterDec_backupStruct BitCounterDec_backup;


/*******************************************************************************
* Function Name: BitCounterDec_SaveConfig
********************************************************************************
* Summary:
*     Save the current user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  BitCounterDec_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void BitCounterDec_SaveConfig(void) 
{
    #if (!BitCounterDec_UsingFixedFunction)

        BitCounterDec_backup.CounterUdb = BitCounterDec_ReadCounter();

        #if(!BitCounterDec_ControlRegRemoved)
            BitCounterDec_backup.CounterControlRegister = BitCounterDec_ReadControlRegister();
        #endif /* (!BitCounterDec_ControlRegRemoved) */

    #endif /* (!BitCounterDec_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: BitCounterDec_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  BitCounterDec_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void BitCounterDec_RestoreConfig(void) 
{      
    #if (!BitCounterDec_UsingFixedFunction)

       BitCounterDec_WriteCounter(BitCounterDec_backup.CounterUdb);

        #if(!BitCounterDec_ControlRegRemoved)
            BitCounterDec_WriteControlRegister(BitCounterDec_backup.CounterControlRegister);
        #endif /* (!BitCounterDec_ControlRegRemoved) */

    #endif /* (!BitCounterDec_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: BitCounterDec_Sleep
********************************************************************************
* Summary:
*     Stop and Save the user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  BitCounterDec_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void BitCounterDec_Sleep(void) 
{
    #if(!BitCounterDec_ControlRegRemoved)
        /* Save Counter's enable state */
        if(BitCounterDec_CTRL_ENABLE == (BitCounterDec_CONTROL & BitCounterDec_CTRL_ENABLE))
        {
            /* Counter is enabled */
            BitCounterDec_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            BitCounterDec_backup.CounterEnableState = 0u;
        }
    #else
        BitCounterDec_backup.CounterEnableState = 1u;
        if(BitCounterDec_backup.CounterEnableState != 0u)
        {
            BitCounterDec_backup.CounterEnableState = 0u;
        }
    #endif /* (!BitCounterDec_ControlRegRemoved) */
    
    BitCounterDec_Stop();
    BitCounterDec_SaveConfig();
}


/*******************************************************************************
* Function Name: BitCounterDec_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  BitCounterDec_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void BitCounterDec_Wakeup(void) 
{
    BitCounterDec_RestoreConfig();
    #if(!BitCounterDec_ControlRegRemoved)
        if(BitCounterDec_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            BitCounterDec_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!BitCounterDec_ControlRegRemoved) */
    
}


/* [] END OF FILE */
