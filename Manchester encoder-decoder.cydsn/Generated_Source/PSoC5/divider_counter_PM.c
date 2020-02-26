/*******************************************************************************
* File Name: divider_counter_PM.c  
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

#include "divider_counter.h"

static divider_counter_backupStruct divider_counter_backup;


/*******************************************************************************
* Function Name: divider_counter_SaveConfig
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
*  divider_counter_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void divider_counter_SaveConfig(void) 
{
    #if (!divider_counter_UsingFixedFunction)

        divider_counter_backup.CounterUdb = divider_counter_ReadCounter();

        #if(!divider_counter_ControlRegRemoved)
            divider_counter_backup.CounterControlRegister = divider_counter_ReadControlRegister();
        #endif /* (!divider_counter_ControlRegRemoved) */

    #endif /* (!divider_counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: divider_counter_RestoreConfig
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
*  divider_counter_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void divider_counter_RestoreConfig(void) 
{      
    #if (!divider_counter_UsingFixedFunction)

       divider_counter_WriteCounter(divider_counter_backup.CounterUdb);

        #if(!divider_counter_ControlRegRemoved)
            divider_counter_WriteControlRegister(divider_counter_backup.CounterControlRegister);
        #endif /* (!divider_counter_ControlRegRemoved) */

    #endif /* (!divider_counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: divider_counter_Sleep
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
*  divider_counter_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void divider_counter_Sleep(void) 
{
    #if(!divider_counter_ControlRegRemoved)
        /* Save Counter's enable state */
        if(divider_counter_CTRL_ENABLE == (divider_counter_CONTROL & divider_counter_CTRL_ENABLE))
        {
            /* Counter is enabled */
            divider_counter_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            divider_counter_backup.CounterEnableState = 0u;
        }
    #else
        divider_counter_backup.CounterEnableState = 1u;
        if(divider_counter_backup.CounterEnableState != 0u)
        {
            divider_counter_backup.CounterEnableState = 0u;
        }
    #endif /* (!divider_counter_ControlRegRemoved) */
    
    divider_counter_Stop();
    divider_counter_SaveConfig();
}


/*******************************************************************************
* Function Name: divider_counter_Wakeup
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
*  divider_counter_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void divider_counter_Wakeup(void) 
{
    divider_counter_RestoreConfig();
    #if(!divider_counter_ControlRegRemoved)
        if(divider_counter_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            divider_counter_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!divider_counter_ControlRegRemoved) */
    
}


/* [] END OF FILE */
