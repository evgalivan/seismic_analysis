/*******************************************************************************
* File Name: Waiter_PM.c  
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

#include "Waiter.h"

static Waiter_backupStruct Waiter_backup;


/*******************************************************************************
* Function Name: Waiter_SaveConfig
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
*  Waiter_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Waiter_SaveConfig(void) 
{
    #if (!Waiter_UsingFixedFunction)

        Waiter_backup.CounterUdb = Waiter_ReadCounter();

        #if(!Waiter_ControlRegRemoved)
            Waiter_backup.CounterControlRegister = Waiter_ReadControlRegister();
        #endif /* (!Waiter_ControlRegRemoved) */

    #endif /* (!Waiter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Waiter_RestoreConfig
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
*  Waiter_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Waiter_RestoreConfig(void) 
{      
    #if (!Waiter_UsingFixedFunction)

       Waiter_WriteCounter(Waiter_backup.CounterUdb);

        #if(!Waiter_ControlRegRemoved)
            Waiter_WriteControlRegister(Waiter_backup.CounterControlRegister);
        #endif /* (!Waiter_ControlRegRemoved) */

    #endif /* (!Waiter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Waiter_Sleep
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
*  Waiter_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Waiter_Sleep(void) 
{
    #if(!Waiter_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Waiter_CTRL_ENABLE == (Waiter_CONTROL & Waiter_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Waiter_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Waiter_backup.CounterEnableState = 0u;
        }
    #else
        Waiter_backup.CounterEnableState = 1u;
        if(Waiter_backup.CounterEnableState != 0u)
        {
            Waiter_backup.CounterEnableState = 0u;
        }
    #endif /* (!Waiter_ControlRegRemoved) */
    
    Waiter_Stop();
    Waiter_SaveConfig();
}


/*******************************************************************************
* Function Name: Waiter_Wakeup
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
*  Waiter_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Waiter_Wakeup(void) 
{
    Waiter_RestoreConfig();
    #if(!Waiter_ControlRegRemoved)
        if(Waiter_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Waiter_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Waiter_ControlRegRemoved) */
    
}


/* [] END OF FILE */
