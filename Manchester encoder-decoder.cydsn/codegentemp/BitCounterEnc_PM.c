/*******************************************************************************
* File Name: BitCounterEnc_PM.c  
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

#include "BitCounterEnc.h"

static BitCounterEnc_backupStruct BitCounterEnc_backup;


/*******************************************************************************
* Function Name: BitCounterEnc_SaveConfig
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
*  BitCounterEnc_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void BitCounterEnc_SaveConfig(void) 
{
    #if (!BitCounterEnc_UsingFixedFunction)

        BitCounterEnc_backup.CounterUdb = BitCounterEnc_ReadCounter();

        #if(!BitCounterEnc_ControlRegRemoved)
            BitCounterEnc_backup.CounterControlRegister = BitCounterEnc_ReadControlRegister();
        #endif /* (!BitCounterEnc_ControlRegRemoved) */

    #endif /* (!BitCounterEnc_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: BitCounterEnc_RestoreConfig
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
*  BitCounterEnc_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void BitCounterEnc_RestoreConfig(void) 
{      
    #if (!BitCounterEnc_UsingFixedFunction)

       BitCounterEnc_WriteCounter(BitCounterEnc_backup.CounterUdb);

        #if(!BitCounterEnc_ControlRegRemoved)
            BitCounterEnc_WriteControlRegister(BitCounterEnc_backup.CounterControlRegister);
        #endif /* (!BitCounterEnc_ControlRegRemoved) */

    #endif /* (!BitCounterEnc_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: BitCounterEnc_Sleep
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
*  BitCounterEnc_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void BitCounterEnc_Sleep(void) 
{
    #if(!BitCounterEnc_ControlRegRemoved)
        /* Save Counter's enable state */
        if(BitCounterEnc_CTRL_ENABLE == (BitCounterEnc_CONTROL & BitCounterEnc_CTRL_ENABLE))
        {
            /* Counter is enabled */
            BitCounterEnc_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            BitCounterEnc_backup.CounterEnableState = 0u;
        }
    #else
        BitCounterEnc_backup.CounterEnableState = 1u;
        if(BitCounterEnc_backup.CounterEnableState != 0u)
        {
            BitCounterEnc_backup.CounterEnableState = 0u;
        }
    #endif /* (!BitCounterEnc_ControlRegRemoved) */
    
    BitCounterEnc_Stop();
    BitCounterEnc_SaveConfig();
}


/*******************************************************************************
* Function Name: BitCounterEnc_Wakeup
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
*  BitCounterEnc_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void BitCounterEnc_Wakeup(void) 
{
    BitCounterEnc_RestoreConfig();
    #if(!BitCounterEnc_ControlRegRemoved)
        if(BitCounterEnc_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            BitCounterEnc_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!BitCounterEnc_ControlRegRemoved) */
    
}


/* [] END OF FILE */
