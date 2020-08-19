/*******************************************************************************
* File Name: TEST.c
* Version 3.30
*
* Description:
*  The PWM User Module consist of an 8 or 16-bit counter with two 8 or 16-bit
*  comparitors. Each instance of this user module is capable of generating
*  two PWM outputs with the same period. The pulse width is selectable between
*  1 and 255/65535. The period is selectable between 2 and 255/65536 clocks.
*  The compare value output may be configured to be active when the present
*  counter is less than or less than/equal to the compare value.
*  A terminal count output is also provided. It generates a pulse one clock
*  width wide when the counter is equal to zero.
*
* Note:
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "TEST.h"

/* Error message for removed <resource> through optimization */
#ifdef TEST_PWMUDB_genblk1_ctrlreg__REMOVED
    #error PWM_v3_30 detected with a constant 0 for the enable or \
         constant 1 for reset. This will prevent the component from operating.
#endif /* TEST_PWMUDB_genblk1_ctrlreg__REMOVED */

uint8 TEST_initVar = 0u;


/*******************************************************************************
* Function Name: TEST_Start
********************************************************************************
*
* Summary:
*  The start function initializes the pwm with the default values, the
*  enables the counter to begin counting.  It does not enable interrupts,
*  the EnableInt command should be called if interrupt generation is required.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  TEST_initVar: Is modified when this function is called for the
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void TEST_Start(void) 
{
    /* If not Initialized then initialize all required hardware and software */
    if(TEST_initVar == 0u)
    {
        TEST_Init();
        TEST_initVar = 1u;
    }
    TEST_Enable();

}


/*******************************************************************************
* Function Name: TEST_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the
*  customizer of the component placed onto schematic. Usually called in
*  TEST_Start().
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void TEST_Init(void) 
{
    #if (TEST_UsingFixedFunction || TEST_UseControl)
        uint8 ctrl;
    #endif /* (TEST_UsingFixedFunction || TEST_UseControl) */

    #if(!TEST_UsingFixedFunction)
        #if(TEST_UseStatus)
            /* Interrupt State Backup for Critical Region*/
            uint8 TEST_interruptState;
        #endif /* (TEST_UseStatus) */
    #endif /* (!TEST_UsingFixedFunction) */

    #if (TEST_UsingFixedFunction)
        /* You are allowed to write the compare value (FF only) */
        TEST_CONTROL |= TEST_CFG0_MODE;
        #if (TEST_DeadBand2_4)
            TEST_CONTROL |= TEST_CFG0_DB;
        #endif /* (TEST_DeadBand2_4) */

        ctrl = TEST_CONTROL3 & ((uint8 )(~TEST_CTRL_CMPMODE1_MASK));
        TEST_CONTROL3 = ctrl | TEST_DEFAULT_COMPARE1_MODE;

         /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
        TEST_RT1 &= ((uint8)(~TEST_RT1_MASK));
        TEST_RT1 |= TEST_SYNC;

        /*Enable DSI Sync all all inputs of the PWM*/
        TEST_RT1 &= ((uint8)(~TEST_SYNCDSI_MASK));
        TEST_RT1 |= TEST_SYNCDSI_EN;

    #elif (TEST_UseControl)
        /* Set the default compare mode defined in the parameter */
        ctrl = TEST_CONTROL & ((uint8)(~TEST_CTRL_CMPMODE2_MASK)) &
                ((uint8)(~TEST_CTRL_CMPMODE1_MASK));
        TEST_CONTROL = ctrl | TEST_DEFAULT_COMPARE2_MODE |
                                   TEST_DEFAULT_COMPARE1_MODE;
    #endif /* (TEST_UsingFixedFunction) */

    #if (!TEST_UsingFixedFunction)
        #if (TEST_Resolution == 8)
            /* Set FIFO 0 to 1 byte register for period*/
            TEST_AUX_CONTROLDP0 |= (TEST_AUX_CTRL_FIFO0_CLR);
        #else /* (TEST_Resolution == 16)*/
            /* Set FIFO 0 to 1 byte register for period */
            TEST_AUX_CONTROLDP0 |= (TEST_AUX_CTRL_FIFO0_CLR);
            TEST_AUX_CONTROLDP1 |= (TEST_AUX_CTRL_FIFO0_CLR);
        #endif /* (TEST_Resolution == 8) */

        TEST_WriteCounter(TEST_INIT_PERIOD_VALUE);
    #endif /* (!TEST_UsingFixedFunction) */

    TEST_WritePeriod(TEST_INIT_PERIOD_VALUE);

        #if (TEST_UseOneCompareMode)
            TEST_WriteCompare(TEST_INIT_COMPARE_VALUE1);
        #else
            TEST_WriteCompare1(TEST_INIT_COMPARE_VALUE1);
            TEST_WriteCompare2(TEST_INIT_COMPARE_VALUE2);
        #endif /* (TEST_UseOneCompareMode) */

        #if (TEST_KillModeMinTime)
            TEST_WriteKillTime(TEST_MinimumKillTime);
        #endif /* (TEST_KillModeMinTime) */

        #if (TEST_DeadBandUsed)
            TEST_WriteDeadTime(TEST_INIT_DEAD_TIME);
        #endif /* (TEST_DeadBandUsed) */

    #if (TEST_UseStatus || TEST_UsingFixedFunction)
        TEST_SetInterruptMode(TEST_INIT_INTERRUPTS_MODE);
    #endif /* (TEST_UseStatus || TEST_UsingFixedFunction) */

    #if (TEST_UsingFixedFunction)
        /* Globally Enable the Fixed Function Block chosen */
        TEST_GLOBAL_ENABLE |= TEST_BLOCK_EN_MASK;
        /* Set the Interrupt source to come from the status register */
        TEST_CONTROL2 |= TEST_CTRL2_IRQ_SEL;
    #else
        #if(TEST_UseStatus)

            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            TEST_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            TEST_STATUS_AUX_CTRL |= TEST_STATUS_ACTL_INT_EN_MASK;

             /* Exit Critical Region*/
            CyExitCriticalSection(TEST_interruptState);

            /* Clear the FIFO to enable the TEST_STATUS_FIFOFULL
                   bit to be set on FIFO full. */
            TEST_ClearFIFO();
        #endif /* (TEST_UseStatus) */
    #endif /* (TEST_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: TEST_Enable
********************************************************************************
*
* Summary:
*  Enables the PWM block operation
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  This works only if software enable mode is chosen
*
*******************************************************************************/
void TEST_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (TEST_UsingFixedFunction)
        TEST_GLOBAL_ENABLE |= TEST_BLOCK_EN_MASK;
        TEST_GLOBAL_STBY_ENABLE |= TEST_BLOCK_STBY_EN_MASK;
    #endif /* (TEST_UsingFixedFunction) */

    /* Enable the PWM from the control register  */
    #if (TEST_UseControl || TEST_UsingFixedFunction)
        TEST_CONTROL |= TEST_CTRL_ENABLE;
    #endif /* (TEST_UseControl || TEST_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: TEST_Stop
********************************************************************************
*
* Summary:
*  The stop function halts the PWM, but does not change any modes or disable
*  interrupts.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  If the Enable mode is set to Hardware only then this function
*  has no effect on the operation of the PWM
*
*******************************************************************************/
void TEST_Stop(void) 
{
    #if (TEST_UseControl || TEST_UsingFixedFunction)
        TEST_CONTROL &= ((uint8)(~TEST_CTRL_ENABLE));
    #endif /* (TEST_UseControl || TEST_UsingFixedFunction) */

    /* Globally disable the Fixed Function Block chosen */
    #if (TEST_UsingFixedFunction)
        TEST_GLOBAL_ENABLE &= ((uint8)(~TEST_BLOCK_EN_MASK));
        TEST_GLOBAL_STBY_ENABLE &= ((uint8)(~TEST_BLOCK_STBY_EN_MASK));
    #endif /* (TEST_UsingFixedFunction) */
}

#if (TEST_UseOneCompareMode)
    #if (TEST_CompareMode1SW)


        /*******************************************************************************
        * Function Name: TEST_SetCompareMode
        ********************************************************************************
        *
        * Summary:
        *  This function writes the Compare Mode for the pwm output when in Dither mode,
        *  Center Align Mode or One Output Mode.
        *
        * Parameters:
        *  comparemode:  The new compare mode for the PWM output. Use the compare types
        *                defined in the H file as input arguments.
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void TEST_SetCompareMode(uint8 comparemode) 
        {
            #if(TEST_UsingFixedFunction)

                #if(0 != TEST_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemodemasked = ((uint8)((uint8)comparemode << TEST_CTRL_CMPMODE1_SHIFT));
                #else
                    uint8 comparemodemasked = comparemode;
                #endif /* (0 != TEST_CTRL_CMPMODE1_SHIFT) */

                TEST_CONTROL3 &= ((uint8)(~TEST_CTRL_CMPMODE1_MASK)); /*Clear Existing Data */
                TEST_CONTROL3 |= comparemodemasked;

            #elif (TEST_UseControl)

                #if(0 != TEST_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemode1masked = ((uint8)((uint8)comparemode << TEST_CTRL_CMPMODE1_SHIFT)) &
                                                TEST_CTRL_CMPMODE1_MASK;
                #else
                    uint8 comparemode1masked = comparemode & TEST_CTRL_CMPMODE1_MASK;
                #endif /* (0 != TEST_CTRL_CMPMODE1_SHIFT) */

                #if(0 != TEST_CTRL_CMPMODE2_SHIFT)
                    uint8 comparemode2masked = ((uint8)((uint8)comparemode << TEST_CTRL_CMPMODE2_SHIFT)) &
                                               TEST_CTRL_CMPMODE2_MASK;
                #else
                    uint8 comparemode2masked = comparemode & TEST_CTRL_CMPMODE2_MASK;
                #endif /* (0 != TEST_CTRL_CMPMODE2_SHIFT) */

                /*Clear existing mode */
                TEST_CONTROL &= ((uint8)(~(TEST_CTRL_CMPMODE1_MASK |
                                            TEST_CTRL_CMPMODE2_MASK)));
                TEST_CONTROL |= (comparemode1masked | comparemode2masked);

            #else
                uint8 temp = comparemode;
            #endif /* (TEST_UsingFixedFunction) */
        }
    #endif /* TEST_CompareMode1SW */

#else /* UseOneCompareMode */

    #if (TEST_CompareMode1SW)


        /*******************************************************************************
        * Function Name: TEST_SetCompareMode1
        ********************************************************************************
        *
        * Summary:
        *  This function writes the Compare Mode for the pwm or pwm1 output
        *
        * Parameters:
        *  comparemode:  The new compare mode for the PWM output. Use the compare types
        *                defined in the H file as input arguments.
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void TEST_SetCompareMode1(uint8 comparemode) 
        {
            #if(0 != TEST_CTRL_CMPMODE1_SHIFT)
                uint8 comparemodemasked = ((uint8)((uint8)comparemode << TEST_CTRL_CMPMODE1_SHIFT)) &
                                           TEST_CTRL_CMPMODE1_MASK;
            #else
                uint8 comparemodemasked = comparemode & TEST_CTRL_CMPMODE1_MASK;
            #endif /* (0 != TEST_CTRL_CMPMODE1_SHIFT) */

            #if (TEST_UseControl)
                TEST_CONTROL &= ((uint8)(~TEST_CTRL_CMPMODE1_MASK)); /*Clear existing mode */
                TEST_CONTROL |= comparemodemasked;
            #endif /* (TEST_UseControl) */
        }
    #endif /* TEST_CompareMode1SW */

#if (TEST_CompareMode2SW)


    /*******************************************************************************
    * Function Name: TEST_SetCompareMode2
    ********************************************************************************
    *
    * Summary:
    *  This function writes the Compare Mode for the pwm or pwm2 output
    *
    * Parameters:
    *  comparemode:  The new compare mode for the PWM output. Use the compare types
    *                defined in the H file as input arguments.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void TEST_SetCompareMode2(uint8 comparemode) 
    {

        #if(0 != TEST_CTRL_CMPMODE2_SHIFT)
            uint8 comparemodemasked = ((uint8)((uint8)comparemode << TEST_CTRL_CMPMODE2_SHIFT)) &
                                                 TEST_CTRL_CMPMODE2_MASK;
        #else
            uint8 comparemodemasked = comparemode & TEST_CTRL_CMPMODE2_MASK;
        #endif /* (0 != TEST_CTRL_CMPMODE2_SHIFT) */

        #if (TEST_UseControl)
            TEST_CONTROL &= ((uint8)(~TEST_CTRL_CMPMODE2_MASK)); /*Clear existing mode */
            TEST_CONTROL |= comparemodemasked;
        #endif /* (TEST_UseControl) */
    }
    #endif /*TEST_CompareMode2SW */

#endif /* UseOneCompareMode */


#if (!TEST_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: TEST_WriteCounter
    ********************************************************************************
    *
    * Summary:
    *  Writes a new counter value directly to the counter register. This will be
    *  implemented for that currently running period and only that period. This API
    *  is valid only for UDB implementation and not available for fixed function
    *  PWM implementation.
    *
    * Parameters:
    *  counter:  The period new period counter value.
    *
    * Return:
    *  None
    *
    * Side Effects:
    *  The PWM Period will be reloaded when a counter value will be a zero
    *
    *******************************************************************************/
    void TEST_WriteCounter(uint16 counter) \
                                       
    {
        CY_SET_REG16(TEST_COUNTER_LSB_PTR, counter);
    }


    /*******************************************************************************
    * Function Name: TEST_ReadCounter
    ********************************************************************************
    *
    * Summary:
    *  This function returns the current value of the counter.  It doesn't matter
    *  if the counter is enabled or running.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  The current value of the counter.
    *
    *******************************************************************************/
    uint16 TEST_ReadCounter(void) 
    {
        /* Force capture by reading Accumulator */
        /* Must first do a software capture to be able to read the counter */
        /* It is up to the user code to make sure there isn't already captured data in the FIFO */
          (void)CY_GET_REG8(TEST_COUNTERCAP_LSB_PTR_8BIT);

        /* Read the data from the FIFO */
        return (CY_GET_REG16(TEST_CAPTURE_LSB_PTR));
    }

    #if (TEST_UseStatus)


        /*******************************************************************************
        * Function Name: TEST_ClearFIFO
        ********************************************************************************
        *
        * Summary:
        *  This function clears all capture data from the capture FIFO
        *
        * Parameters:
        *  None
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void TEST_ClearFIFO(void) 
        {
            while(0u != (TEST_ReadStatusRegister() & TEST_STATUS_FIFONEMPTY))
            {
                (void)TEST_ReadCapture();
            }
        }

    #endif /* TEST_UseStatus */

#endif /* !TEST_UsingFixedFunction */


/*******************************************************************************
* Function Name: TEST_WritePeriod
********************************************************************************
*
* Summary:
*  This function is used to change the period of the counter.  The new period
*  will be loaded the next time terminal count is detected.
*
* Parameters:
*  period:  Period value. May be between 1 and (2^Resolution)-1.  A value of 0
*           will result in the counter remaining at zero.
*
* Return:
*  None
*
*******************************************************************************/
void TEST_WritePeriod(uint16 period) 
{
    #if(TEST_UsingFixedFunction)
        CY_SET_REG16(TEST_PERIOD_LSB_PTR, (uint16)period);
    #else
        CY_SET_REG16(TEST_PERIOD_LSB_PTR, period);
    #endif /* (TEST_UsingFixedFunction) */
}

#if (TEST_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: TEST_WriteCompare
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare1 value when the PWM is in Dither
    *  mode. The compare output will reflect the new value on the next UDB clock.
    *  The compare output will be driven high when the present counter value is
    *  compared to the compare value based on the compare mode defined in
    *  Dither Mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    * Side Effects:
    *  This function is only available if the PWM mode parameter is set to
    *  Dither Mode, Center Aligned Mode or One Output Mode
    *
    *******************************************************************************/
    void TEST_WriteCompare(uint16 compare) \
                                       
    {
        #if(TEST_UsingFixedFunction)
            CY_SET_REG16(TEST_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG16(TEST_COMPARE1_LSB_PTR, compare);
        #endif /* (TEST_UsingFixedFunction) */

        #if (TEST_PWMMode == TEST__B_PWM__DITHER)
            #if(TEST_UsingFixedFunction)
                CY_SET_REG16(TEST_COMPARE2_LSB_PTR, (uint16)(compare + 1u));
            #else
                CY_SET_REG16(TEST_COMPARE2_LSB_PTR, (compare + 1u));
            #endif /* (TEST_UsingFixedFunction) */
        #endif /* (TEST_PWMMode == TEST__B_PWM__DITHER) */
    }


#else


    /*******************************************************************************
    * Function Name: TEST_WriteCompare1
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare1 value.  The compare output will
    *  reflect the new value on the next UDB clock.  The compare output will be
    *  driven high when the present counter value is less than or less than or
    *  equal to the compare register, depending on the mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void TEST_WriteCompare1(uint16 compare) \
                                        
    {
        #if(TEST_UsingFixedFunction)
            CY_SET_REG16(TEST_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG16(TEST_COMPARE1_LSB_PTR, compare);
        #endif /* (TEST_UsingFixedFunction) */
    }


    /*******************************************************************************
    * Function Name: TEST_WriteCompare2
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare value, for compare1 output.
    *  The compare output will reflect the new value on the next UDB clock.
    *  The compare output will be driven high when the present counter value is
    *  less than or less than or equal to the compare register, depending on the
    *  mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void TEST_WriteCompare2(uint16 compare) \
                                        
    {
        #if(TEST_UsingFixedFunction)
            CY_SET_REG16(TEST_COMPARE2_LSB_PTR, compare);
        #else
            CY_SET_REG16(TEST_COMPARE2_LSB_PTR, compare);
        #endif /* (TEST_UsingFixedFunction) */
    }
#endif /* UseOneCompareMode */

#if (TEST_DeadBandUsed)


    /*******************************************************************************
    * Function Name: TEST_WriteDeadTime
    ********************************************************************************
    *
    * Summary:
    *  This function writes the dead-band counts to the corresponding register
    *
    * Parameters:
    *  deadtime:  Number of counts for dead time
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void TEST_WriteDeadTime(uint8 deadtime) 
    {
        /* If using the Dead Band 1-255 mode then just write the register */
        #if(!TEST_DeadBand2_4)
            CY_SET_REG8(TEST_DEADBAND_COUNT_PTR, deadtime);
        #else
            /* Otherwise the data has to be masked and offset */
            /* Clear existing data */
            TEST_DEADBAND_COUNT &= ((uint8)(~TEST_DEADBAND_COUNT_MASK));

            /* Set new dead time */
            #if(TEST_DEADBAND_COUNT_SHIFT)
                TEST_DEADBAND_COUNT |= ((uint8)((uint8)deadtime << TEST_DEADBAND_COUNT_SHIFT)) &
                                                    TEST_DEADBAND_COUNT_MASK;
            #else
                TEST_DEADBAND_COUNT |= deadtime & TEST_DEADBAND_COUNT_MASK;
            #endif /* (TEST_DEADBAND_COUNT_SHIFT) */

        #endif /* (!TEST_DeadBand2_4) */
    }


    /*******************************************************************************
    * Function Name: TEST_ReadDeadTime
    ********************************************************************************
    *
    * Summary:
    *  This function reads the dead-band counts from the corresponding register
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Dead Band Counts
    *
    *******************************************************************************/
    uint8 TEST_ReadDeadTime(void) 
    {
        /* If using the Dead Band 1-255 mode then just read the register */
        #if(!TEST_DeadBand2_4)
            return (CY_GET_REG8(TEST_DEADBAND_COUNT_PTR));
        #else

            /* Otherwise the data has to be masked and offset */
            #if(TEST_DEADBAND_COUNT_SHIFT)
                return ((uint8)(((uint8)(TEST_DEADBAND_COUNT & TEST_DEADBAND_COUNT_MASK)) >>
                                                                           TEST_DEADBAND_COUNT_SHIFT));
            #else
                return (TEST_DEADBAND_COUNT & TEST_DEADBAND_COUNT_MASK);
            #endif /* (TEST_DEADBAND_COUNT_SHIFT) */
        #endif /* (!TEST_DeadBand2_4) */
    }
#endif /* DeadBandUsed */

#if (TEST_UseStatus || TEST_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: TEST_SetInterruptMode
    ********************************************************************************
    *
    * Summary:
    *  This function configures the interrupts mask control of theinterrupt
    *  source status register.
    *
    * Parameters:
    *  uint8 interruptMode: Bit field containing the interrupt sources enabled
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void TEST_SetInterruptMode(uint8 interruptMode) 
    {
        CY_SET_REG8(TEST_STATUS_MASK_PTR, interruptMode);
    }


    /*******************************************************************************
    * Function Name: TEST_ReadStatusRegister
    ********************************************************************************
    *
    * Summary:
    *  This function returns the current state of the status register.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8 : Current status register value. The status register bits are:
    *  [7:6] : Unused(0)
    *  [5]   : Kill event output
    *  [4]   : FIFO not empty
    *  [3]   : FIFO full
    *  [2]   : Terminal count
    *  [1]   : Compare output 2
    *  [0]   : Compare output 1
    *
    *******************************************************************************/
    uint8 TEST_ReadStatusRegister(void) 
    {
        return (CY_GET_REG8(TEST_STATUS_PTR));
    }

#endif /* (TEST_UseStatus || TEST_UsingFixedFunction) */


#if (TEST_UseControl)


    /*******************************************************************************
    * Function Name: TEST_ReadControlRegister
    ********************************************************************************
    *
    * Summary:
    *  Returns the current state of the control register. This API is available
    *  only if the control register is not removed.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8 : Current control register value
    *
    *******************************************************************************/
    uint8 TEST_ReadControlRegister(void) 
    {
        uint8 result;

        result = CY_GET_REG8(TEST_CONTROL_PTR);
        return (result);
    }


    /*******************************************************************************
    * Function Name: TEST_WriteControlRegister
    ********************************************************************************
    *
    * Summary:
    *  Sets the bit field of the control register. This API is available only if
    *  the control register is not removed.
    *
    * Parameters:
    *  uint8 control: Control register bit field, The status register bits are:
    *  [7]   : PWM Enable
    *  [6]   : Reset
    *  [5:3] : Compare Mode2
    *  [2:0] : Compare Mode2
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void TEST_WriteControlRegister(uint8 control) 
    {
        CY_SET_REG8(TEST_CONTROL_PTR, control);
    }

#endif /* (TEST_UseControl) */


#if (!TEST_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: TEST_ReadCapture
    ********************************************************************************
    *
    * Summary:
    *  Reads the capture value from the capture FIFO.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: The current capture value
    *
    *******************************************************************************/
    uint16 TEST_ReadCapture(void) 
    {
        return (CY_GET_REG16(TEST_CAPTURE_LSB_PTR));
    }

#endif /* (!TEST_UsingFixedFunction) */


#if (TEST_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: TEST_ReadCompare
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare output when the PWM Mode parameter is
    *  set to Dither mode, Center Aligned mode, or One Output mode.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value
    *
    *******************************************************************************/
    uint16 TEST_ReadCompare(void) 
    {
        #if(TEST_UsingFixedFunction)
            return ((uint16)CY_GET_REG16(TEST_COMPARE1_LSB_PTR));
        #else
            return (CY_GET_REG16(TEST_COMPARE1_LSB_PTR));
        #endif /* (TEST_UsingFixedFunction) */
    }

#else


    /*******************************************************************************
    * Function Name: TEST_ReadCompare1
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare1 output.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value.
    *
    *******************************************************************************/
    uint16 TEST_ReadCompare1(void) 
    {
        return (CY_GET_REG16(TEST_COMPARE1_LSB_PTR));
    }


    /*******************************************************************************
    * Function Name: TEST_ReadCompare2
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare2 output.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value.
    *
    *******************************************************************************/
    uint16 TEST_ReadCompare2(void) 
    {
        return (CY_GET_REG16(TEST_COMPARE2_LSB_PTR));
    }

#endif /* (TEST_UseOneCompareMode) */


/*******************************************************************************
* Function Name: TEST_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the period value used by the PWM hardware.
*
* Parameters:
*  None
*
* Return:
*  uint8/16: Period value
*
*******************************************************************************/
uint16 TEST_ReadPeriod(void) 
{
    #if(TEST_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(TEST_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG16(TEST_PERIOD_LSB_PTR));
    #endif /* (TEST_UsingFixedFunction) */
}

#if ( TEST_KillModeMinTime)


    /*******************************************************************************
    * Function Name: TEST_WriteKillTime
    ********************************************************************************
    *
    * Summary:
    *  Writes the kill time value used by the hardware when the Kill Mode
    *  is set to Minimum Time.
    *
    * Parameters:
    *  uint8: Minimum Time kill counts
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void TEST_WriteKillTime(uint8 killtime) 
    {
        CY_SET_REG8(TEST_KILLMODEMINTIME_PTR, killtime);
    }


    /*******************************************************************************
    * Function Name: TEST_ReadKillTime
    ********************************************************************************
    *
    * Summary:
    *  Reads the kill time value used by the hardware when the Kill Mode is set
    *  to Minimum Time.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8: The current Minimum Time kill counts
    *
    *******************************************************************************/
    uint8 TEST_ReadKillTime(void) 
    {
        return (CY_GET_REG8(TEST_KILLMODEMINTIME_PTR));
    }

#endif /* ( TEST_KillModeMinTime) */

/* [] END OF FILE */
