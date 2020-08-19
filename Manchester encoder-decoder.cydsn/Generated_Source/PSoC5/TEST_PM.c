/*******************************************************************************
* File Name: TEST_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "TEST.h"

static TEST_backupStruct TEST_backup;


/*******************************************************************************
* Function Name: TEST_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  TEST_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void TEST_SaveConfig(void) 
{

    #if(!TEST_UsingFixedFunction)
        #if(!TEST_PWMModeIsCenterAligned)
            TEST_backup.PWMPeriod = TEST_ReadPeriod();
        #endif /* (!TEST_PWMModeIsCenterAligned) */
        TEST_backup.PWMUdb = TEST_ReadCounter();
        #if (TEST_UseStatus)
            TEST_backup.InterruptMaskValue = TEST_STATUS_MASK;
        #endif /* (TEST_UseStatus) */

        #if(TEST_DeadBandMode == TEST__B_PWM__DBM_256_CLOCKS || \
            TEST_DeadBandMode == TEST__B_PWM__DBM_2_4_CLOCKS)
            TEST_backup.PWMdeadBandValue = TEST_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(TEST_KillModeMinTime)
             TEST_backup.PWMKillCounterPeriod = TEST_ReadKillTime();
        #endif /* (TEST_KillModeMinTime) */

        #if(TEST_UseControl)
            TEST_backup.PWMControlRegister = TEST_ReadControlRegister();
        #endif /* (TEST_UseControl) */
    #endif  /* (!TEST_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: TEST_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  TEST_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void TEST_RestoreConfig(void) 
{
        #if(!TEST_UsingFixedFunction)
            #if(!TEST_PWMModeIsCenterAligned)
                TEST_WritePeriod(TEST_backup.PWMPeriod);
            #endif /* (!TEST_PWMModeIsCenterAligned) */

            TEST_WriteCounter(TEST_backup.PWMUdb);

            #if (TEST_UseStatus)
                TEST_STATUS_MASK = TEST_backup.InterruptMaskValue;
            #endif /* (TEST_UseStatus) */

            #if(TEST_DeadBandMode == TEST__B_PWM__DBM_256_CLOCKS || \
                TEST_DeadBandMode == TEST__B_PWM__DBM_2_4_CLOCKS)
                TEST_WriteDeadTime(TEST_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(TEST_KillModeMinTime)
                TEST_WriteKillTime(TEST_backup.PWMKillCounterPeriod);
            #endif /* (TEST_KillModeMinTime) */

            #if(TEST_UseControl)
                TEST_WriteControlRegister(TEST_backup.PWMControlRegister);
            #endif /* (TEST_UseControl) */
        #endif  /* (!TEST_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: TEST_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  TEST_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void TEST_Sleep(void) 
{
    #if(TEST_UseControl)
        if(TEST_CTRL_ENABLE == (TEST_CONTROL & TEST_CTRL_ENABLE))
        {
            /*Component is enabled */
            TEST_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            TEST_backup.PWMEnableState = 0u;
        }
    #endif /* (TEST_UseControl) */

    /* Stop component */
    TEST_Stop();

    /* Save registers configuration */
    TEST_SaveConfig();
}


/*******************************************************************************
* Function Name: TEST_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  TEST_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void TEST_Wakeup(void) 
{
     /* Restore registers values */
    TEST_RestoreConfig();

    if(TEST_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        TEST_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
