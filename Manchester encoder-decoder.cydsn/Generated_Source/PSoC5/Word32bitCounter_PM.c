/*******************************************************************************
* File Name: Word32bitCounter_PM.c  
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

#include "Word32bitCounter.h"

static Word32bitCounter_backupStruct Word32bitCounter_backup;


/*******************************************************************************
* Function Name: Word32bitCounter_SaveConfig
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
*  Word32bitCounter_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Word32bitCounter_SaveConfig(void) 
{
    #if (!Word32bitCounter_UsingFixedFunction)

        Word32bitCounter_backup.CounterUdb = Word32bitCounter_ReadCounter();

        #if(!Word32bitCounter_ControlRegRemoved)
            Word32bitCounter_backup.CounterControlRegister = Word32bitCounter_ReadControlRegister();
        #endif /* (!Word32bitCounter_ControlRegRemoved) */

    #endif /* (!Word32bitCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Word32bitCounter_RestoreConfig
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
*  Word32bitCounter_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Word32bitCounter_RestoreConfig(void) 
{      
    #if (!Word32bitCounter_UsingFixedFunction)

       Word32bitCounter_WriteCounter(Word32bitCounter_backup.CounterUdb);

        #if(!Word32bitCounter_ControlRegRemoved)
            Word32bitCounter_WriteControlRegister(Word32bitCounter_backup.CounterControlRegister);
        #endif /* (!Word32bitCounter_ControlRegRemoved) */

    #endif /* (!Word32bitCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Word32bitCounter_Sleep
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
*  Word32bitCounter_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Word32bitCounter_Sleep(void) 
{
    #if(!Word32bitCounter_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Word32bitCounter_CTRL_ENABLE == (Word32bitCounter_CONTROL & Word32bitCounter_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Word32bitCounter_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Word32bitCounter_backup.CounterEnableState = 0u;
        }
    #else
        Word32bitCounter_backup.CounterEnableState = 1u;
        if(Word32bitCounter_backup.CounterEnableState != 0u)
        {
            Word32bitCounter_backup.CounterEnableState = 0u;
        }
    #endif /* (!Word32bitCounter_ControlRegRemoved) */
    
    Word32bitCounter_Stop();
    Word32bitCounter_SaveConfig();
}


/*******************************************************************************
* Function Name: Word32bitCounter_Wakeup
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
*  Word32bitCounter_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Word32bitCounter_Wakeup(void) 
{
    Word32bitCounter_RestoreConfig();
    #if(!Word32bitCounter_ControlRegRemoved)
        if(Word32bitCounter_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Word32bitCounter_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Word32bitCounter_ControlRegRemoved) */
    
}


/* [] END OF FILE */
