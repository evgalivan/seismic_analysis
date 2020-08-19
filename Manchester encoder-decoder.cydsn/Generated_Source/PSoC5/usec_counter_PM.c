/*******************************************************************************
* File Name: usec_counter_PM.c  
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

#include "usec_counter.h"

static usec_counter_backupStruct usec_counter_backup;


/*******************************************************************************
* Function Name: usec_counter_SaveConfig
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
*  usec_counter_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void usec_counter_SaveConfig(void) 
{
    #if (!usec_counter_UsingFixedFunction)

        usec_counter_backup.CounterUdb = usec_counter_ReadCounter();

        #if(!usec_counter_ControlRegRemoved)
            usec_counter_backup.CounterControlRegister = usec_counter_ReadControlRegister();
        #endif /* (!usec_counter_ControlRegRemoved) */

    #endif /* (!usec_counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: usec_counter_RestoreConfig
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
*  usec_counter_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void usec_counter_RestoreConfig(void) 
{      
    #if (!usec_counter_UsingFixedFunction)

       usec_counter_WriteCounter(usec_counter_backup.CounterUdb);

        #if(!usec_counter_ControlRegRemoved)
            usec_counter_WriteControlRegister(usec_counter_backup.CounterControlRegister);
        #endif /* (!usec_counter_ControlRegRemoved) */

    #endif /* (!usec_counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: usec_counter_Sleep
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
*  usec_counter_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void usec_counter_Sleep(void) 
{
    #if(!usec_counter_ControlRegRemoved)
        /* Save Counter's enable state */
        if(usec_counter_CTRL_ENABLE == (usec_counter_CONTROL & usec_counter_CTRL_ENABLE))
        {
            /* Counter is enabled */
            usec_counter_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            usec_counter_backup.CounterEnableState = 0u;
        }
    #else
        usec_counter_backup.CounterEnableState = 1u;
        if(usec_counter_backup.CounterEnableState != 0u)
        {
            usec_counter_backup.CounterEnableState = 0u;
        }
    #endif /* (!usec_counter_ControlRegRemoved) */
    
    usec_counter_Stop();
    usec_counter_SaveConfig();
}


/*******************************************************************************
* Function Name: usec_counter_Wakeup
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
*  usec_counter_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void usec_counter_Wakeup(void) 
{
    usec_counter_RestoreConfig();
    #if(!usec_counter_ControlRegRemoved)
        if(usec_counter_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            usec_counter_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!usec_counter_ControlRegRemoved) */
    
}


/* [] END OF FILE */
