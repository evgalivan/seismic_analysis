/*******************************************************************************
* File Name: Boundary32bit_PM.c  
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

#include "Boundary32bit.h"

static Boundary32bit_backupStruct Boundary32bit_backup;


/*******************************************************************************
* Function Name: Boundary32bit_SaveConfig
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
*  Boundary32bit_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Boundary32bit_SaveConfig(void) 
{
    #if (!Boundary32bit_UsingFixedFunction)

        Boundary32bit_backup.CounterUdb = Boundary32bit_ReadCounter();

        #if(!Boundary32bit_ControlRegRemoved)
            Boundary32bit_backup.CounterControlRegister = Boundary32bit_ReadControlRegister();
        #endif /* (!Boundary32bit_ControlRegRemoved) */

    #endif /* (!Boundary32bit_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Boundary32bit_RestoreConfig
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
*  Boundary32bit_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Boundary32bit_RestoreConfig(void) 
{      
    #if (!Boundary32bit_UsingFixedFunction)

       Boundary32bit_WriteCounter(Boundary32bit_backup.CounterUdb);

        #if(!Boundary32bit_ControlRegRemoved)
            Boundary32bit_WriteControlRegister(Boundary32bit_backup.CounterControlRegister);
        #endif /* (!Boundary32bit_ControlRegRemoved) */

    #endif /* (!Boundary32bit_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Boundary32bit_Sleep
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
*  Boundary32bit_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Boundary32bit_Sleep(void) 
{
    #if(!Boundary32bit_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Boundary32bit_CTRL_ENABLE == (Boundary32bit_CONTROL & Boundary32bit_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Boundary32bit_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Boundary32bit_backup.CounterEnableState = 0u;
        }
    #else
        Boundary32bit_backup.CounterEnableState = 1u;
        if(Boundary32bit_backup.CounterEnableState != 0u)
        {
            Boundary32bit_backup.CounterEnableState = 0u;
        }
    #endif /* (!Boundary32bit_ControlRegRemoved) */
    
    Boundary32bit_Stop();
    Boundary32bit_SaveConfig();
}


/*******************************************************************************
* Function Name: Boundary32bit_Wakeup
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
*  Boundary32bit_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Boundary32bit_Wakeup(void) 
{
    Boundary32bit_RestoreConfig();
    #if(!Boundary32bit_ControlRegRemoved)
        if(Boundary32bit_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Boundary32bit_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Boundary32bit_ControlRegRemoved) */
    
}


/* [] END OF FILE */
