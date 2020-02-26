/*******************************************************************************
* File Name: BitCounterEnc.c  
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

#include "BitCounterEnc.h"

uint8 BitCounterEnc_initVar = 0u;


/*******************************************************************************
* Function Name: BitCounterEnc_Init
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
void BitCounterEnc_Init(void) 
{
        #if (!BitCounterEnc_UsingFixedFunction && !BitCounterEnc_ControlRegRemoved)
            uint8 ctrl;
        #endif /* (!BitCounterEnc_UsingFixedFunction && !BitCounterEnc_ControlRegRemoved) */
        
        #if(!BitCounterEnc_UsingFixedFunction) 
            /* Interrupt State Backup for Critical Region*/
            uint8 BitCounterEnc_interruptState;
        #endif /* (!BitCounterEnc_UsingFixedFunction) */
        
        #if (BitCounterEnc_UsingFixedFunction)
            /* Clear all bits but the enable bit (if it's already set for Timer operation */
            BitCounterEnc_CONTROL &= BitCounterEnc_CTRL_ENABLE;
            
            /* Clear the mode bits for continuous run mode */
            #if (CY_PSOC5A)
                BitCounterEnc_CONTROL2 &= ((uint8)(~BitCounterEnc_CTRL_MODE_MASK));
            #endif /* (CY_PSOC5A) */
            #if (CY_PSOC3 || CY_PSOC5LP)
                BitCounterEnc_CONTROL3 &= ((uint8)(~BitCounterEnc_CTRL_MODE_MASK));                
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            /* Check if One Shot mode is enabled i.e. RunMode !=0*/
            #if (BitCounterEnc_RunModeUsed != 0x0u)
                /* Set 3rd bit of Control register to enable one shot mode */
                BitCounterEnc_CONTROL |= BitCounterEnc_ONESHOT;
            #endif /* (BitCounterEnc_RunModeUsed != 0x0u) */
            
            /* Set the IRQ to use the status register interrupts */
            BitCounterEnc_CONTROL2 |= BitCounterEnc_CTRL2_IRQ_SEL;
            
            /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
            BitCounterEnc_RT1 &= ((uint8)(~BitCounterEnc_RT1_MASK));
            BitCounterEnc_RT1 |= BitCounterEnc_SYNC;     
                    
            /*Enable DSI Sync all all inputs of the Timer*/
            BitCounterEnc_RT1 &= ((uint8)(~BitCounterEnc_SYNCDSI_MASK));
            BitCounterEnc_RT1 |= BitCounterEnc_SYNCDSI_EN;

        #else
            #if(!BitCounterEnc_ControlRegRemoved)
            /* Set the default compare mode defined in the parameter */
            ctrl = BitCounterEnc_CONTROL & ((uint8)(~BitCounterEnc_CTRL_CMPMODE_MASK));
            BitCounterEnc_CONTROL = ctrl | BitCounterEnc_DEFAULT_COMPARE_MODE;
            
            /* Set the default capture mode defined in the parameter */
            ctrl = BitCounterEnc_CONTROL & ((uint8)(~BitCounterEnc_CTRL_CAPMODE_MASK));
            
            #if( 0 != BitCounterEnc_CAPTURE_MODE_CONF)
                BitCounterEnc_CONTROL = ctrl | BitCounterEnc_DEFAULT_CAPTURE_MODE;
            #else
                BitCounterEnc_CONTROL = ctrl;
            #endif /* 0 != BitCounterEnc_CAPTURE_MODE */ 
            
            #endif /* (!BitCounterEnc_ControlRegRemoved) */
        #endif /* (BitCounterEnc_UsingFixedFunction) */
        
        /* Clear all data in the FIFO's */
        #if (!BitCounterEnc_UsingFixedFunction)
            BitCounterEnc_ClearFIFO();
        #endif /* (!BitCounterEnc_UsingFixedFunction) */
        
        /* Set Initial values from Configuration */
        BitCounterEnc_WritePeriod(BitCounterEnc_INIT_PERIOD_VALUE);
        #if (!(BitCounterEnc_UsingFixedFunction && (CY_PSOC5A)))
            BitCounterEnc_WriteCounter(BitCounterEnc_INIT_COUNTER_VALUE);
        #endif /* (!(BitCounterEnc_UsingFixedFunction && (CY_PSOC5A))) */
        BitCounterEnc_SetInterruptMode(BitCounterEnc_INIT_INTERRUPTS_MASK);
        
        #if (!BitCounterEnc_UsingFixedFunction)
            /* Read the status register to clear the unwanted interrupts */
            (void)BitCounterEnc_ReadStatusRegister();
            /* Set the compare value (only available to non-fixed function implementation */
            BitCounterEnc_WriteCompare(BitCounterEnc_INIT_COMPARE_VALUE);
            /* Use the interrupt output of the status register for IRQ output */
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            BitCounterEnc_interruptState = CyEnterCriticalSection();
            
            BitCounterEnc_STATUS_AUX_CTRL |= BitCounterEnc_STATUS_ACTL_INT_EN_MASK;
            
            /* Exit Critical Region*/
            CyExitCriticalSection(BitCounterEnc_interruptState);
            
        #endif /* (!BitCounterEnc_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: BitCounterEnc_Enable
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
void BitCounterEnc_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (BitCounterEnc_UsingFixedFunction)
        BitCounterEnc_GLOBAL_ENABLE |= BitCounterEnc_BLOCK_EN_MASK;
        BitCounterEnc_GLOBAL_STBY_ENABLE |= BitCounterEnc_BLOCK_STBY_EN_MASK;
    #endif /* (BitCounterEnc_UsingFixedFunction) */  
        
    /* Enable the counter from the control register  */
    /* If Fixed Function then make sure Mode is set correctly */
    /* else make sure reset is clear */
    #if(!BitCounterEnc_ControlRegRemoved || BitCounterEnc_UsingFixedFunction)
        BitCounterEnc_CONTROL |= BitCounterEnc_CTRL_ENABLE;                
    #endif /* (!BitCounterEnc_ControlRegRemoved || BitCounterEnc_UsingFixedFunction) */
    
}


/*******************************************************************************
* Function Name: BitCounterEnc_Start
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
*  BitCounterEnc_initVar: Is modified when this function is called for the  
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void BitCounterEnc_Start(void) 
{
    if(BitCounterEnc_initVar == 0u)
    {
        BitCounterEnc_Init();
        
        BitCounterEnc_initVar = 1u; /* Clear this bit for Initialization */        
    }
    
    /* Enable the Counter */
    BitCounterEnc_Enable();        
}


/*******************************************************************************
* Function Name: BitCounterEnc_Stop
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
void BitCounterEnc_Stop(void) 
{
    /* Disable Counter */
    #if(!BitCounterEnc_ControlRegRemoved || BitCounterEnc_UsingFixedFunction)
        BitCounterEnc_CONTROL &= ((uint8)(~BitCounterEnc_CTRL_ENABLE));        
    #endif /* (!BitCounterEnc_ControlRegRemoved || BitCounterEnc_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (BitCounterEnc_UsingFixedFunction)
        BitCounterEnc_GLOBAL_ENABLE &= ((uint8)(~BitCounterEnc_BLOCK_EN_MASK));
        BitCounterEnc_GLOBAL_STBY_ENABLE &= ((uint8)(~BitCounterEnc_BLOCK_STBY_EN_MASK));
    #endif /* (BitCounterEnc_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: BitCounterEnc_SetInterruptMode
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
void BitCounterEnc_SetInterruptMode(uint8 interruptsMask) 
{
    BitCounterEnc_STATUS_MASK = interruptsMask;
}


/*******************************************************************************
* Function Name: BitCounterEnc_ReadStatusRegister
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
uint8   BitCounterEnc_ReadStatusRegister(void) 
{
    return BitCounterEnc_STATUS;
}


#if(!BitCounterEnc_ControlRegRemoved)
/*******************************************************************************
* Function Name: BitCounterEnc_ReadControlRegister
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
uint8   BitCounterEnc_ReadControlRegister(void) 
{
    return BitCounterEnc_CONTROL;
}


/*******************************************************************************
* Function Name: BitCounterEnc_WriteControlRegister
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
void    BitCounterEnc_WriteControlRegister(uint8 control) 
{
    BitCounterEnc_CONTROL = control;
}

#endif  /* (!BitCounterEnc_ControlRegRemoved) */


#if (!(BitCounterEnc_UsingFixedFunction && (CY_PSOC5A)))
/*******************************************************************************
* Function Name: BitCounterEnc_WriteCounter
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
void BitCounterEnc_WriteCounter(uint8 counter) \
                                   
{
    #if(BitCounterEnc_UsingFixedFunction)
        /* assert if block is already enabled */
        CYASSERT (0u == (BitCounterEnc_GLOBAL_ENABLE & BitCounterEnc_BLOCK_EN_MASK));
        /* If block is disabled, enable it and then write the counter */
        BitCounterEnc_GLOBAL_ENABLE |= BitCounterEnc_BLOCK_EN_MASK;
        CY_SET_REG16(BitCounterEnc_COUNTER_LSB_PTR, (uint16)counter);
        BitCounterEnc_GLOBAL_ENABLE &= ((uint8)(~BitCounterEnc_BLOCK_EN_MASK));
    #else
        CY_SET_REG8(BitCounterEnc_COUNTER_LSB_PTR, counter);
    #endif /* (BitCounterEnc_UsingFixedFunction) */
}
#endif /* (!(BitCounterEnc_UsingFixedFunction && (CY_PSOC5A))) */


/*******************************************************************************
* Function Name: BitCounterEnc_ReadCounter
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
uint8 BitCounterEnc_ReadCounter(void) 
{
    /* Force capture by reading Accumulator */
    /* Must first do a software capture to be able to read the counter */
    /* It is up to the user code to make sure there isn't already captured data in the FIFO */
    #if(BitCounterEnc_UsingFixedFunction)
		(void)CY_GET_REG16(BitCounterEnc_COUNTER_LSB_PTR);
	#else
		(void)CY_GET_REG8(BitCounterEnc_COUNTER_LSB_PTR_8BIT);
	#endif/* (BitCounterEnc_UsingFixedFunction) */
    
    /* Read the data from the FIFO (or capture register for Fixed Function)*/
    #if(BitCounterEnc_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(BitCounterEnc_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG8(BitCounterEnc_STATICCOUNT_LSB_PTR));
    #endif /* (BitCounterEnc_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: BitCounterEnc_ReadCapture
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
uint8 BitCounterEnc_ReadCapture(void) 
{
    #if(BitCounterEnc_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(BitCounterEnc_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG8(BitCounterEnc_STATICCOUNT_LSB_PTR));
    #endif /* (BitCounterEnc_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: BitCounterEnc_WritePeriod
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
void BitCounterEnc_WritePeriod(uint8 period) 
{
    #if(BitCounterEnc_UsingFixedFunction)
        CY_SET_REG16(BitCounterEnc_PERIOD_LSB_PTR,(uint16)period);
    #else
        CY_SET_REG8(BitCounterEnc_PERIOD_LSB_PTR, period);
    #endif /* (BitCounterEnc_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: BitCounterEnc_ReadPeriod
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
uint8 BitCounterEnc_ReadPeriod(void) 
{
    #if(BitCounterEnc_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(BitCounterEnc_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG8(BitCounterEnc_PERIOD_LSB_PTR));
    #endif /* (BitCounterEnc_UsingFixedFunction) */
}


#if (!BitCounterEnc_UsingFixedFunction)
/*******************************************************************************
* Function Name: BitCounterEnc_WriteCompare
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
void BitCounterEnc_WriteCompare(uint8 compare) \
                                   
{
    #if(BitCounterEnc_UsingFixedFunction)
        CY_SET_REG16(BitCounterEnc_COMPARE_LSB_PTR, (uint16)compare);
    #else
        CY_SET_REG8(BitCounterEnc_COMPARE_LSB_PTR, compare);
    #endif /* (BitCounterEnc_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: BitCounterEnc_ReadCompare
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
uint8 BitCounterEnc_ReadCompare(void) 
{
    return (CY_GET_REG8(BitCounterEnc_COMPARE_LSB_PTR));
}


#if (BitCounterEnc_COMPARE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: BitCounterEnc_SetCompareMode
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
void BitCounterEnc_SetCompareMode(uint8 compareMode) 
{
    /* Clear the compare mode bits in the control register */
    BitCounterEnc_CONTROL &= ((uint8)(~BitCounterEnc_CTRL_CMPMODE_MASK));
    
    /* Write the new setting */
    BitCounterEnc_CONTROL |= compareMode;
}
#endif  /* (BitCounterEnc_COMPARE_MODE_SOFTWARE) */


#if (BitCounterEnc_CAPTURE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: BitCounterEnc_SetCaptureMode
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
void BitCounterEnc_SetCaptureMode(uint8 captureMode) 
{
    /* Clear the capture mode bits in the control register */
    BitCounterEnc_CONTROL &= ((uint8)(~BitCounterEnc_CTRL_CAPMODE_MASK));
    
    /* Write the new setting */
    BitCounterEnc_CONTROL |= ((uint8)((uint8)captureMode << BitCounterEnc_CTRL_CAPMODE0_SHIFT));
}
#endif  /* (BitCounterEnc_CAPTURE_MODE_SOFTWARE) */


/*******************************************************************************
* Function Name: BitCounterEnc_ClearFIFO
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
void BitCounterEnc_ClearFIFO(void) 
{

    while(0u != (BitCounterEnc_ReadStatusRegister() & BitCounterEnc_STATUS_FIFONEMP))
    {
        (void)BitCounterEnc_ReadCapture();
    }

}
#endif  /* (!BitCounterEnc_UsingFixedFunction) */


/* [] END OF FILE */

