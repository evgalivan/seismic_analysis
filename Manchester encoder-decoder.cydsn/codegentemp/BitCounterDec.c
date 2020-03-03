/*******************************************************************************
* File Name: BitCounterDec.c  
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

#include "BitCounterDec.h"

uint8 BitCounterDec_initVar = 0u;


/*******************************************************************************
* Function Name: BitCounterDec_Init
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
void BitCounterDec_Init(void) 
{
        #if (!BitCounterDec_UsingFixedFunction && !BitCounterDec_ControlRegRemoved)
            uint8 ctrl;
        #endif /* (!BitCounterDec_UsingFixedFunction && !BitCounterDec_ControlRegRemoved) */
        
        #if(!BitCounterDec_UsingFixedFunction) 
            /* Interrupt State Backup for Critical Region*/
            uint8 BitCounterDec_interruptState;
        #endif /* (!BitCounterDec_UsingFixedFunction) */
        
        #if (BitCounterDec_UsingFixedFunction)
            /* Clear all bits but the enable bit (if it's already set for Timer operation */
            BitCounterDec_CONTROL &= BitCounterDec_CTRL_ENABLE;
            
            /* Clear the mode bits for continuous run mode */
            #if (CY_PSOC5A)
                BitCounterDec_CONTROL2 &= ((uint8)(~BitCounterDec_CTRL_MODE_MASK));
            #endif /* (CY_PSOC5A) */
            #if (CY_PSOC3 || CY_PSOC5LP)
                BitCounterDec_CONTROL3 &= ((uint8)(~BitCounterDec_CTRL_MODE_MASK));                
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            /* Check if One Shot mode is enabled i.e. RunMode !=0*/
            #if (BitCounterDec_RunModeUsed != 0x0u)
                /* Set 3rd bit of Control register to enable one shot mode */
                BitCounterDec_CONTROL |= BitCounterDec_ONESHOT;
            #endif /* (BitCounterDec_RunModeUsed != 0x0u) */
            
            /* Set the IRQ to use the status register interrupts */
            BitCounterDec_CONTROL2 |= BitCounterDec_CTRL2_IRQ_SEL;
            
            /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
            BitCounterDec_RT1 &= ((uint8)(~BitCounterDec_RT1_MASK));
            BitCounterDec_RT1 |= BitCounterDec_SYNC;     
                    
            /*Enable DSI Sync all all inputs of the Timer*/
            BitCounterDec_RT1 &= ((uint8)(~BitCounterDec_SYNCDSI_MASK));
            BitCounterDec_RT1 |= BitCounterDec_SYNCDSI_EN;

        #else
            #if(!BitCounterDec_ControlRegRemoved)
            /* Set the default compare mode defined in the parameter */
            ctrl = BitCounterDec_CONTROL & ((uint8)(~BitCounterDec_CTRL_CMPMODE_MASK));
            BitCounterDec_CONTROL = ctrl | BitCounterDec_DEFAULT_COMPARE_MODE;
            
            /* Set the default capture mode defined in the parameter */
            ctrl = BitCounterDec_CONTROL & ((uint8)(~BitCounterDec_CTRL_CAPMODE_MASK));
            
            #if( 0 != BitCounterDec_CAPTURE_MODE_CONF)
                BitCounterDec_CONTROL = ctrl | BitCounterDec_DEFAULT_CAPTURE_MODE;
            #else
                BitCounterDec_CONTROL = ctrl;
            #endif /* 0 != BitCounterDec_CAPTURE_MODE */ 
            
            #endif /* (!BitCounterDec_ControlRegRemoved) */
        #endif /* (BitCounterDec_UsingFixedFunction) */
        
        /* Clear all data in the FIFO's */
        #if (!BitCounterDec_UsingFixedFunction)
            BitCounterDec_ClearFIFO();
        #endif /* (!BitCounterDec_UsingFixedFunction) */
        
        /* Set Initial values from Configuration */
        BitCounterDec_WritePeriod(BitCounterDec_INIT_PERIOD_VALUE);
        #if (!(BitCounterDec_UsingFixedFunction && (CY_PSOC5A)))
            BitCounterDec_WriteCounter(BitCounterDec_INIT_COUNTER_VALUE);
        #endif /* (!(BitCounterDec_UsingFixedFunction && (CY_PSOC5A))) */
        BitCounterDec_SetInterruptMode(BitCounterDec_INIT_INTERRUPTS_MASK);
        
        #if (!BitCounterDec_UsingFixedFunction)
            /* Read the status register to clear the unwanted interrupts */
            (void)BitCounterDec_ReadStatusRegister();
            /* Set the compare value (only available to non-fixed function implementation */
            BitCounterDec_WriteCompare(BitCounterDec_INIT_COMPARE_VALUE);
            /* Use the interrupt output of the status register for IRQ output */
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            BitCounterDec_interruptState = CyEnterCriticalSection();
            
            BitCounterDec_STATUS_AUX_CTRL |= BitCounterDec_STATUS_ACTL_INT_EN_MASK;
            
            /* Exit Critical Region*/
            CyExitCriticalSection(BitCounterDec_interruptState);
            
        #endif /* (!BitCounterDec_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: BitCounterDec_Enable
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
void BitCounterDec_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (BitCounterDec_UsingFixedFunction)
        BitCounterDec_GLOBAL_ENABLE |= BitCounterDec_BLOCK_EN_MASK;
        BitCounterDec_GLOBAL_STBY_ENABLE |= BitCounterDec_BLOCK_STBY_EN_MASK;
    #endif /* (BitCounterDec_UsingFixedFunction) */  
        
    /* Enable the counter from the control register  */
    /* If Fixed Function then make sure Mode is set correctly */
    /* else make sure reset is clear */
    #if(!BitCounterDec_ControlRegRemoved || BitCounterDec_UsingFixedFunction)
        BitCounterDec_CONTROL |= BitCounterDec_CTRL_ENABLE;                
    #endif /* (!BitCounterDec_ControlRegRemoved || BitCounterDec_UsingFixedFunction) */
    
}


/*******************************************************************************
* Function Name: BitCounterDec_Start
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
*  BitCounterDec_initVar: Is modified when this function is called for the  
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void BitCounterDec_Start(void) 
{
    if(BitCounterDec_initVar == 0u)
    {
        BitCounterDec_Init();
        
        BitCounterDec_initVar = 1u; /* Clear this bit for Initialization */        
    }
    
    /* Enable the Counter */
    BitCounterDec_Enable();        
}


/*******************************************************************************
* Function Name: BitCounterDec_Stop
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
void BitCounterDec_Stop(void) 
{
    /* Disable Counter */
    #if(!BitCounterDec_ControlRegRemoved || BitCounterDec_UsingFixedFunction)
        BitCounterDec_CONTROL &= ((uint8)(~BitCounterDec_CTRL_ENABLE));        
    #endif /* (!BitCounterDec_ControlRegRemoved || BitCounterDec_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (BitCounterDec_UsingFixedFunction)
        BitCounterDec_GLOBAL_ENABLE &= ((uint8)(~BitCounterDec_BLOCK_EN_MASK));
        BitCounterDec_GLOBAL_STBY_ENABLE &= ((uint8)(~BitCounterDec_BLOCK_STBY_EN_MASK));
    #endif /* (BitCounterDec_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: BitCounterDec_SetInterruptMode
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
void BitCounterDec_SetInterruptMode(uint8 interruptsMask) 
{
    BitCounterDec_STATUS_MASK = interruptsMask;
}


/*******************************************************************************
* Function Name: BitCounterDec_ReadStatusRegister
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
uint8   BitCounterDec_ReadStatusRegister(void) 
{
    return BitCounterDec_STATUS;
}


#if(!BitCounterDec_ControlRegRemoved)
/*******************************************************************************
* Function Name: BitCounterDec_ReadControlRegister
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
uint8   BitCounterDec_ReadControlRegister(void) 
{
    return BitCounterDec_CONTROL;
}


/*******************************************************************************
* Function Name: BitCounterDec_WriteControlRegister
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
void    BitCounterDec_WriteControlRegister(uint8 control) 
{
    BitCounterDec_CONTROL = control;
}

#endif  /* (!BitCounterDec_ControlRegRemoved) */


#if (!(BitCounterDec_UsingFixedFunction && (CY_PSOC5A)))
/*******************************************************************************
* Function Name: BitCounterDec_WriteCounter
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
void BitCounterDec_WriteCounter(uint8 counter) \
                                   
{
    #if(BitCounterDec_UsingFixedFunction)
        /* assert if block is already enabled */
        CYASSERT (0u == (BitCounterDec_GLOBAL_ENABLE & BitCounterDec_BLOCK_EN_MASK));
        /* If block is disabled, enable it and then write the counter */
        BitCounterDec_GLOBAL_ENABLE |= BitCounterDec_BLOCK_EN_MASK;
        CY_SET_REG16(BitCounterDec_COUNTER_LSB_PTR, (uint16)counter);
        BitCounterDec_GLOBAL_ENABLE &= ((uint8)(~BitCounterDec_BLOCK_EN_MASK));
    #else
        CY_SET_REG8(BitCounterDec_COUNTER_LSB_PTR, counter);
    #endif /* (BitCounterDec_UsingFixedFunction) */
}
#endif /* (!(BitCounterDec_UsingFixedFunction && (CY_PSOC5A))) */


/*******************************************************************************
* Function Name: BitCounterDec_ReadCounter
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
uint8 BitCounterDec_ReadCounter(void) 
{
    /* Force capture by reading Accumulator */
    /* Must first do a software capture to be able to read the counter */
    /* It is up to the user code to make sure there isn't already captured data in the FIFO */
    #if(BitCounterDec_UsingFixedFunction)
		(void)CY_GET_REG16(BitCounterDec_COUNTER_LSB_PTR);
	#else
		(void)CY_GET_REG8(BitCounterDec_COUNTER_LSB_PTR_8BIT);
	#endif/* (BitCounterDec_UsingFixedFunction) */
    
    /* Read the data from the FIFO (or capture register for Fixed Function)*/
    #if(BitCounterDec_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(BitCounterDec_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG8(BitCounterDec_STATICCOUNT_LSB_PTR));
    #endif /* (BitCounterDec_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: BitCounterDec_ReadCapture
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
uint8 BitCounterDec_ReadCapture(void) 
{
    #if(BitCounterDec_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(BitCounterDec_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG8(BitCounterDec_STATICCOUNT_LSB_PTR));
    #endif /* (BitCounterDec_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: BitCounterDec_WritePeriod
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
void BitCounterDec_WritePeriod(uint8 period) 
{
    #if(BitCounterDec_UsingFixedFunction)
        CY_SET_REG16(BitCounterDec_PERIOD_LSB_PTR,(uint16)period);
    #else
        CY_SET_REG8(BitCounterDec_PERIOD_LSB_PTR, period);
    #endif /* (BitCounterDec_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: BitCounterDec_ReadPeriod
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
uint8 BitCounterDec_ReadPeriod(void) 
{
    #if(BitCounterDec_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(BitCounterDec_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG8(BitCounterDec_PERIOD_LSB_PTR));
    #endif /* (BitCounterDec_UsingFixedFunction) */
}


#if (!BitCounterDec_UsingFixedFunction)
/*******************************************************************************
* Function Name: BitCounterDec_WriteCompare
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
void BitCounterDec_WriteCompare(uint8 compare) \
                                   
{
    #if(BitCounterDec_UsingFixedFunction)
        CY_SET_REG16(BitCounterDec_COMPARE_LSB_PTR, (uint16)compare);
    #else
        CY_SET_REG8(BitCounterDec_COMPARE_LSB_PTR, compare);
    #endif /* (BitCounterDec_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: BitCounterDec_ReadCompare
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
uint8 BitCounterDec_ReadCompare(void) 
{
    return (CY_GET_REG8(BitCounterDec_COMPARE_LSB_PTR));
}


#if (BitCounterDec_COMPARE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: BitCounterDec_SetCompareMode
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
void BitCounterDec_SetCompareMode(uint8 compareMode) 
{
    /* Clear the compare mode bits in the control register */
    BitCounterDec_CONTROL &= ((uint8)(~BitCounterDec_CTRL_CMPMODE_MASK));
    
    /* Write the new setting */
    BitCounterDec_CONTROL |= compareMode;
}
#endif  /* (BitCounterDec_COMPARE_MODE_SOFTWARE) */


#if (BitCounterDec_CAPTURE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: BitCounterDec_SetCaptureMode
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
void BitCounterDec_SetCaptureMode(uint8 captureMode) 
{
    /* Clear the capture mode bits in the control register */
    BitCounterDec_CONTROL &= ((uint8)(~BitCounterDec_CTRL_CAPMODE_MASK));
    
    /* Write the new setting */
    BitCounterDec_CONTROL |= ((uint8)((uint8)captureMode << BitCounterDec_CTRL_CAPMODE0_SHIFT));
}
#endif  /* (BitCounterDec_CAPTURE_MODE_SOFTWARE) */


/*******************************************************************************
* Function Name: BitCounterDec_ClearFIFO
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
void BitCounterDec_ClearFIFO(void) 
{

    while(0u != (BitCounterDec_ReadStatusRegister() & BitCounterDec_STATUS_FIFONEMP))
    {
        (void)BitCounterDec_ReadCapture();
    }

}
#endif  /* (!BitCounterDec_UsingFixedFunction) */


/* [] END OF FILE */

