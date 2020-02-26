/*******************************************************************************
* File Name: Word32bitCounter.c  
* Version 3.0
*
*  Description:
*     The Counter component consists of a 8, 16, 24 or 32-bit counter with
*     a selectable period between 2 and 2^Width - 1.  
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

uint8 Word32bitCounter_initVar = 0u;


/*******************************************************************************
* Function Name: Word32bitCounter_Init
********************************************************************************
* Summary:
*     Initialize to the schematic state
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void Word32bitCounter_Init(void) 
{
        #if (!Word32bitCounter_UsingFixedFunction && !Word32bitCounter_ControlRegRemoved)
            uint8 ctrl;
        #endif /* (!Word32bitCounter_UsingFixedFunction && !Word32bitCounter_ControlRegRemoved) */
        
        #if(!Word32bitCounter_UsingFixedFunction) 
            /* Interrupt State Backup for Critical Region*/
            uint8 Word32bitCounter_interruptState;
        #endif /* (!Word32bitCounter_UsingFixedFunction) */
        
        #if (Word32bitCounter_UsingFixedFunction)
            /* Clear all bits but the enable bit (if it's already set for Timer operation */
            Word32bitCounter_CONTROL &= Word32bitCounter_CTRL_ENABLE;
            
            /* Clear the mode bits for continuous run mode */
            #if (CY_PSOC5A)
                Word32bitCounter_CONTROL2 &= ((uint8)(~Word32bitCounter_CTRL_MODE_MASK));
            #endif /* (CY_PSOC5A) */
            #if (CY_PSOC3 || CY_PSOC5LP)
                Word32bitCounter_CONTROL3 &= ((uint8)(~Word32bitCounter_CTRL_MODE_MASK));                
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            /* Check if One Shot mode is enabled i.e. RunMode !=0*/
            #if (Word32bitCounter_RunModeUsed != 0x0u)
                /* Set 3rd bit of Control register to enable one shot mode */
                Word32bitCounter_CONTROL |= Word32bitCounter_ONESHOT;
            #endif /* (Word32bitCounter_RunModeUsed != 0x0u) */
            
            /* Set the IRQ to use the status register interrupts */
            Word32bitCounter_CONTROL2 |= Word32bitCounter_CTRL2_IRQ_SEL;
            
            /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
            Word32bitCounter_RT1 &= ((uint8)(~Word32bitCounter_RT1_MASK));
            Word32bitCounter_RT1 |= Word32bitCounter_SYNC;     
                    
            /*Enable DSI Sync all all inputs of the Timer*/
            Word32bitCounter_RT1 &= ((uint8)(~Word32bitCounter_SYNCDSI_MASK));
            Word32bitCounter_RT1 |= Word32bitCounter_SYNCDSI_EN;

        #else
            #if(!Word32bitCounter_ControlRegRemoved)
            /* Set the default compare mode defined in the parameter */
            ctrl = Word32bitCounter_CONTROL & ((uint8)(~Word32bitCounter_CTRL_CMPMODE_MASK));
            Word32bitCounter_CONTROL = ctrl | Word32bitCounter_DEFAULT_COMPARE_MODE;
            
            /* Set the default capture mode defined in the parameter */
            ctrl = Word32bitCounter_CONTROL & ((uint8)(~Word32bitCounter_CTRL_CAPMODE_MASK));
            
            #if( 0 != Word32bitCounter_CAPTURE_MODE_CONF)
                Word32bitCounter_CONTROL = ctrl | Word32bitCounter_DEFAULT_CAPTURE_MODE;
            #else
                Word32bitCounter_CONTROL = ctrl;
            #endif /* 0 != Word32bitCounter_CAPTURE_MODE */ 
            
            #endif /* (!Word32bitCounter_ControlRegRemoved) */
        #endif /* (Word32bitCounter_UsingFixedFunction) */
        
        /* Clear all data in the FIFO's */
        #if (!Word32bitCounter_UsingFixedFunction)
            Word32bitCounter_ClearFIFO();
        #endif /* (!Word32bitCounter_UsingFixedFunction) */
        
        /* Set Initial values from Configuration */
        Word32bitCounter_WritePeriod(Word32bitCounter_INIT_PERIOD_VALUE);
        #if (!(Word32bitCounter_UsingFixedFunction && (CY_PSOC5A)))
            Word32bitCounter_WriteCounter(Word32bitCounter_INIT_COUNTER_VALUE);
        #endif /* (!(Word32bitCounter_UsingFixedFunction && (CY_PSOC5A))) */
        Word32bitCounter_SetInterruptMode(Word32bitCounter_INIT_INTERRUPTS_MASK);
        
        #if (!Word32bitCounter_UsingFixedFunction)
            /* Read the status register to clear the unwanted interrupts */
            (void)Word32bitCounter_ReadStatusRegister();
            /* Set the compare value (only available to non-fixed function implementation */
            Word32bitCounter_WriteCompare(Word32bitCounter_INIT_COMPARE_VALUE);
            /* Use the interrupt output of the status register for IRQ output */
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            Word32bitCounter_interruptState = CyEnterCriticalSection();
            
            Word32bitCounter_STATUS_AUX_CTRL |= Word32bitCounter_STATUS_ACTL_INT_EN_MASK;
            
            /* Exit Critical Region*/
            CyExitCriticalSection(Word32bitCounter_interruptState);
            
        #endif /* (!Word32bitCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Word32bitCounter_Enable
********************************************************************************
* Summary:
*     Enable the Counter
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: 
*   If the Enable mode is set to Hardware only then this function has no effect 
*   on the operation of the counter.
*
*******************************************************************************/
void Word32bitCounter_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (Word32bitCounter_UsingFixedFunction)
        Word32bitCounter_GLOBAL_ENABLE |= Word32bitCounter_BLOCK_EN_MASK;
        Word32bitCounter_GLOBAL_STBY_ENABLE |= Word32bitCounter_BLOCK_STBY_EN_MASK;
    #endif /* (Word32bitCounter_UsingFixedFunction) */  
        
    /* Enable the counter from the control register  */
    /* If Fixed Function then make sure Mode is set correctly */
    /* else make sure reset is clear */
    #if(!Word32bitCounter_ControlRegRemoved || Word32bitCounter_UsingFixedFunction)
        Word32bitCounter_CONTROL |= Word32bitCounter_CTRL_ENABLE;                
    #endif /* (!Word32bitCounter_ControlRegRemoved || Word32bitCounter_UsingFixedFunction) */
    
}


/*******************************************************************************
* Function Name: Word32bitCounter_Start
********************************************************************************
* Summary:
*  Enables the counter for operation 
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Global variables:
*  Word32bitCounter_initVar: Is modified when this function is called for the  
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void Word32bitCounter_Start(void) 
{
    if(Word32bitCounter_initVar == 0u)
    {
        Word32bitCounter_Init();
        
        Word32bitCounter_initVar = 1u; /* Clear this bit for Initialization */        
    }
    
    /* Enable the Counter */
    Word32bitCounter_Enable();        
}


/*******************************************************************************
* Function Name: Word32bitCounter_Stop
********************************************************************************
* Summary:
* Halts the counter, but does not change any modes or disable interrupts.
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: If the Enable mode is set to Hardware only then this function
*               has no effect on the operation of the counter.
*
*******************************************************************************/
void Word32bitCounter_Stop(void) 
{
    /* Disable Counter */
    #if(!Word32bitCounter_ControlRegRemoved || Word32bitCounter_UsingFixedFunction)
        Word32bitCounter_CONTROL &= ((uint8)(~Word32bitCounter_CTRL_ENABLE));        
    #endif /* (!Word32bitCounter_ControlRegRemoved || Word32bitCounter_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (Word32bitCounter_UsingFixedFunction)
        Word32bitCounter_GLOBAL_ENABLE &= ((uint8)(~Word32bitCounter_BLOCK_EN_MASK));
        Word32bitCounter_GLOBAL_STBY_ENABLE &= ((uint8)(~Word32bitCounter_BLOCK_STBY_EN_MASK));
    #endif /* (Word32bitCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Word32bitCounter_SetInterruptMode
********************************************************************************
* Summary:
* Configures which interrupt sources are enabled to generate the final interrupt
*
* Parameters:  
*  InterruptsMask: This parameter is an or'd collection of the status bits
*                   which will be allowed to generate the counters interrupt.   
*
* Return: 
*  void
*
*******************************************************************************/
void Word32bitCounter_SetInterruptMode(uint8 interruptsMask) 
{
    Word32bitCounter_STATUS_MASK = interruptsMask;
}


/*******************************************************************************
* Function Name: Word32bitCounter_ReadStatusRegister
********************************************************************************
* Summary:
*   Reads the status register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the status register
*
* Side Effects:
*   Status register bits may be clear on read. 
*
*******************************************************************************/
uint8   Word32bitCounter_ReadStatusRegister(void) 
{
    return Word32bitCounter_STATUS;
}


#if(!Word32bitCounter_ControlRegRemoved)
/*******************************************************************************
* Function Name: Word32bitCounter_ReadControlRegister
********************************************************************************
* Summary:
*   Reads the control register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
uint8   Word32bitCounter_ReadControlRegister(void) 
{
    return Word32bitCounter_CONTROL;
}


/*******************************************************************************
* Function Name: Word32bitCounter_WriteControlRegister
********************************************************************************
* Summary:
*   Sets the bit-field of the control register.  This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
void    Word32bitCounter_WriteControlRegister(uint8 control) 
{
    Word32bitCounter_CONTROL = control;
}

#endif  /* (!Word32bitCounter_ControlRegRemoved) */


#if (!(Word32bitCounter_UsingFixedFunction && (CY_PSOC5A)))
/*******************************************************************************
* Function Name: Word32bitCounter_WriteCounter
********************************************************************************
* Summary:
*   This funtion is used to set the counter to a specific value
*
* Parameters:  
*  counter:  New counter value. 
*
* Return: 
*  void 
*
*******************************************************************************/
void Word32bitCounter_WriteCounter(uint8 counter) \
                                   
{
    #if(Word32bitCounter_UsingFixedFunction)
        /* assert if block is already enabled */
        CYASSERT (0u == (Word32bitCounter_GLOBAL_ENABLE & Word32bitCounter_BLOCK_EN_MASK));
        /* If block is disabled, enable it and then write the counter */
        Word32bitCounter_GLOBAL_ENABLE |= Word32bitCounter_BLOCK_EN_MASK;
        CY_SET_REG16(Word32bitCounter_COUNTER_LSB_PTR, (uint16)counter);
        Word32bitCounter_GLOBAL_ENABLE &= ((uint8)(~Word32bitCounter_BLOCK_EN_MASK));
    #else
        CY_SET_REG8(Word32bitCounter_COUNTER_LSB_PTR, counter);
    #endif /* (Word32bitCounter_UsingFixedFunction) */
}
#endif /* (!(Word32bitCounter_UsingFixedFunction && (CY_PSOC5A))) */


/*******************************************************************************
* Function Name: Word32bitCounter_ReadCounter
********************************************************************************
* Summary:
* Returns the current value of the counter.  It doesn't matter
* if the counter is enabled or running.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint8) The present value of the counter.
*
*******************************************************************************/
uint8 Word32bitCounter_ReadCounter(void) 
{
    /* Force capture by reading Accumulator */
    /* Must first do a software capture to be able to read the counter */
    /* It is up to the user code to make sure there isn't already captured data in the FIFO */
    #if(Word32bitCounter_UsingFixedFunction)
		(void)CY_GET_REG16(Word32bitCounter_COUNTER_LSB_PTR);
	#else
		(void)CY_GET_REG8(Word32bitCounter_COUNTER_LSB_PTR_8BIT);
	#endif/* (Word32bitCounter_UsingFixedFunction) */
    
    /* Read the data from the FIFO (or capture register for Fixed Function)*/
    #if(Word32bitCounter_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(Word32bitCounter_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG8(Word32bitCounter_STATICCOUNT_LSB_PTR));
    #endif /* (Word32bitCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Word32bitCounter_ReadCapture
********************************************************************************
* Summary:
*   This function returns the last value captured.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) Present Capture value.
*
*******************************************************************************/
uint8 Word32bitCounter_ReadCapture(void) 
{
    #if(Word32bitCounter_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(Word32bitCounter_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG8(Word32bitCounter_STATICCOUNT_LSB_PTR));
    #endif /* (Word32bitCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Word32bitCounter_WritePeriod
********************************************************************************
* Summary:
* Changes the period of the counter.  The new period 
* will be loaded the next time terminal count is detected.
*
* Parameters:  
*  period: (uint8) A value of 0 will result in
*         the counter remaining at zero.  
*
* Return: 
*  void
*
*******************************************************************************/
void Word32bitCounter_WritePeriod(uint8 period) 
{
    #if(Word32bitCounter_UsingFixedFunction)
        CY_SET_REG16(Word32bitCounter_PERIOD_LSB_PTR,(uint16)period);
    #else
        CY_SET_REG8(Word32bitCounter_PERIOD_LSB_PTR, period);
    #endif /* (Word32bitCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Word32bitCounter_ReadPeriod
********************************************************************************
* Summary:
* Reads the current period value without affecting counter operation.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint8) Present period value.
*
*******************************************************************************/
uint8 Word32bitCounter_ReadPeriod(void) 
{
    #if(Word32bitCounter_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(Word32bitCounter_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG8(Word32bitCounter_PERIOD_LSB_PTR));
    #endif /* (Word32bitCounter_UsingFixedFunction) */
}


#if (!Word32bitCounter_UsingFixedFunction)
/*******************************************************************************
* Function Name: Word32bitCounter_WriteCompare
********************************************************************************
* Summary:
* Changes the compare value.  The compare output will 
* reflect the new value on the next UDB clock.  The compare output will be 
* driven high when the present counter value compares true based on the 
* configured compare mode setting. 
*
* Parameters:  
*  Compare:  New compare value. 
*
* Return: 
*  void
*
*******************************************************************************/
void Word32bitCounter_WriteCompare(uint8 compare) \
                                   
{
    #if(Word32bitCounter_UsingFixedFunction)
        CY_SET_REG16(Word32bitCounter_COMPARE_LSB_PTR, (uint16)compare);
    #else
        CY_SET_REG8(Word32bitCounter_COMPARE_LSB_PTR, compare);
    #endif /* (Word32bitCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Word32bitCounter_ReadCompare
********************************************************************************
* Summary:
* Returns the compare value.
*
* Parameters:  
*  void:
*
* Return: 
*  (uint8) Present compare value.
*
*******************************************************************************/
uint8 Word32bitCounter_ReadCompare(void) 
{
    return (CY_GET_REG8(Word32bitCounter_COMPARE_LSB_PTR));
}


#if (Word32bitCounter_COMPARE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: Word32bitCounter_SetCompareMode
********************************************************************************
* Summary:
*  Sets the software controlled Compare Mode.
*
* Parameters:
*  compareMode:  Compare Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void Word32bitCounter_SetCompareMode(uint8 compareMode) 
{
    /* Clear the compare mode bits in the control register */
    Word32bitCounter_CONTROL &= ((uint8)(~Word32bitCounter_CTRL_CMPMODE_MASK));
    
    /* Write the new setting */
    Word32bitCounter_CONTROL |= compareMode;
}
#endif  /* (Word32bitCounter_COMPARE_MODE_SOFTWARE) */


#if (Word32bitCounter_CAPTURE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: Word32bitCounter_SetCaptureMode
********************************************************************************
* Summary:
*  Sets the software controlled Capture Mode.
*
* Parameters:
*  captureMode:  Capture Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void Word32bitCounter_SetCaptureMode(uint8 captureMode) 
{
    /* Clear the capture mode bits in the control register */
    Word32bitCounter_CONTROL &= ((uint8)(~Word32bitCounter_CTRL_CAPMODE_MASK));
    
    /* Write the new setting */
    Word32bitCounter_CONTROL |= ((uint8)((uint8)captureMode << Word32bitCounter_CTRL_CAPMODE0_SHIFT));
}
#endif  /* (Word32bitCounter_CAPTURE_MODE_SOFTWARE) */


/*******************************************************************************
* Function Name: Word32bitCounter_ClearFIFO
********************************************************************************
* Summary:
*   This function clears all capture data from the capture FIFO
*
* Parameters:  
*  void:
*
* Return: 
*  None
*
*******************************************************************************/
void Word32bitCounter_ClearFIFO(void) 
{

    while(0u != (Word32bitCounter_ReadStatusRegister() & Word32bitCounter_STATUS_FIFONEMP))
    {
        (void)Word32bitCounter_ReadCapture();
    }

}
#endif  /* (!Word32bitCounter_UsingFixedFunction) */


/* [] END OF FILE */

