/*******************************************************************************
* File Name: sec_counter_PM.c  
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

#include "sec_counter.h"

static sec_counter_backupStruct sec_counter_backup;


/*******************************************************************************
* Function Name: sec_counter_SaveConfig
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
*  sec_counter_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void sec_counter_SaveConfig(void) 
{
    #if (!sec_counter_UsingFixedFunction)

        sec_counter_backup.CounterUdb = sec_counter_ReadCounter();

        #if(!sec_counter_ControlRegRemoved)
            sec_counter_backup.CounterControlRegister = sec_counter_ReadControlRegister();
        #endif /* (!sec_counter_ControlRegRemoved) */

    #endif /* (!sec_counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: sec_counter_RestoreConfig
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
*  sec_counter_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void sec_counter_RestoreConfig(void) 
{      
    #if (!sec_counter_UsingFixedFunction)

       sec_counter_WriteCounter(sec_counter_backup.CounterUdb);

        #if(!sec_counter_ControlRegRemoved)
            sec_counter_WriteControlRegister(sec_counter_backup.CounterControlRegister);
        #endif /* (!sec_counter_ControlRegRemoved) */

    #endif /* (!sec_counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: sec_counter_Sleep
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
*  sec_counter_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void sec_counter_Sleep(void) 
{
    #if(!sec_counter_ControlRegRemoved)
        /* Save Counter's enable state */
        if(sec_counter_CTRL_ENABLE == (sec_counter_CONTROL & sec_counter_CTRL_ENABLE))
        {
            /* Counter is enabled */
            sec_counter_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            sec_counter_backup.CounterEnableState = 0u;
        }
    #else
        sec_counter_backup.CounterEnableState = 1u;
        if(sec_counter_backup.CounterEnableState != 0u)
        {
            sec_counter_backup.CounterEnableState = 0u;
        }
    #endif /* (!sec_counter_ControlRegRemoved) */
    
    sec_counter_Stop();
    sec_counter_SaveConfig();
}


/*******************************************************************************
* Function Name: sec_counter_Wakeup
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
*  sec_counter_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void sec_counter_Wakeup(void) 
{
    sec_counter_RestoreConfig();
    #if(!sec_counter_ControlRegRemoved)
        if(sec_counter_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            sec_counter_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!sec_counter_ControlRegRemoved) */
    
}


/* [] END OF FILE */
