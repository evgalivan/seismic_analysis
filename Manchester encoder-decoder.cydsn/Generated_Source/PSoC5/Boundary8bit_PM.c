/*******************************************************************************
* File Name: Boundary8bit_PM.c  
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

#include "Boundary8bit.h"

static Boundary8bit_backupStruct Boundary8bit_backup;


/*******************************************************************************
* Function Name: Boundary8bit_SaveConfig
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
*  Boundary8bit_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Boundary8bit_SaveConfig(void) 
{
    #if (!Boundary8bit_UsingFixedFunction)

        Boundary8bit_backup.CounterUdb = Boundary8bit_ReadCounter();

        #if(!Boundary8bit_ControlRegRemoved)
            Boundary8bit_backup.CounterControlRegister = Boundary8bit_ReadControlRegister();
        #endif /* (!Boundary8bit_ControlRegRemoved) */

    #endif /* (!Boundary8bit_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Boundary8bit_RestoreConfig
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
*  Boundary8bit_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Boundary8bit_RestoreConfig(void) 
{      
    #if (!Boundary8bit_UsingFixedFunction)

       Boundary8bit_WriteCounter(Boundary8bit_backup.CounterUdb);

        #if(!Boundary8bit_ControlRegRemoved)
            Boundary8bit_WriteControlRegister(Boundary8bit_backup.CounterControlRegister);
        #endif /* (!Boundary8bit_ControlRegRemoved) */

    #endif /* (!Boundary8bit_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Boundary8bit_Sleep
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
*  Boundary8bit_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Boundary8bit_Sleep(void) 
{
    #if(!Boundary8bit_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Boundary8bit_CTRL_ENABLE == (Boundary8bit_CONTROL & Boundary8bit_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Boundary8bit_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Boundary8bit_backup.CounterEnableState = 0u;
        }
    #else
        Boundary8bit_backup.CounterEnableState = 1u;
        if(Boundary8bit_backup.CounterEnableState != 0u)
        {
            Boundary8bit_backup.CounterEnableState = 0u;
        }
    #endif /* (!Boundary8bit_ControlRegRemoved) */
    
    Boundary8bit_Stop();
    Boundary8bit_SaveConfig();
}


/*******************************************************************************
* Function Name: Boundary8bit_Wakeup
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
*  Boundary8bit_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Boundary8bit_Wakeup(void) 
{
    Boundary8bit_RestoreConfig();
    #if(!Boundary8bit_ControlRegRemoved)
        if(Boundary8bit_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Boundary8bit_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Boundary8bit_ControlRegRemoved) */
    
}


/* [] END OF FILE */
