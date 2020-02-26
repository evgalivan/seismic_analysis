/*******************************************************************************
* File Name: sec_counter.c  
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

#include "sec_counter.h"

uint8 sec_counter_initVar = 0u;


/*******************************************************************************
* Function Name: sec_counter_Init
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
void sec_counter_Init(void) 
{
        #if (!sec_counter_UsingFixedFunction && !sec_counter_ControlRegRemoved)
            uint8 ctrl;
        #endif /* (!sec_counter_UsingFixedFunction && !sec_counter_ControlRegRemoved) */
        
        #if(!sec_counter_UsingFixedFunction) 
            /* Interrupt State Backup for Critical Region*/
            uint8 sec_counter_interruptState;
        #endif /* (!sec_counter_UsingFixedFunction) */
        
        #if (sec_counter_UsingFixedFunction)
            /* Clear all bits but the enable bit (if it's already set for Timer operation */
            sec_counter_CONTROL &= sec_counter_CTRL_ENABLE;
            
            /* Clear the mode bits for continuous run mode */
            #if (CY_PSOC5A)
                sec_counter_CONTROL2 &= ((uint8)(~sec_counter_CTRL_MODE_MASK));
            #endif /* (CY_PSOC5A) */
            #if (CY_PSOC3 || CY_PSOC5LP)
                sec_counter_CONTROL3 &= ((uint8)(~sec_counter_CTRL_MODE_MASK));                
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            /* Check if One Shot mode is enabled i.e. RunMode !=0*/
            #if (sec_counter_RunModeUsed != 0x0u)
                /* Set 3rd bit of Control register to enable one shot mode */
                sec_counter_CONTROL |= sec_counter_ONESHOT;
            #endif /* (sec_counter_RunModeUsed != 0x0u) */
            
            /* Set the IRQ to use the status register interrupts */
            sec_counter_CONTROL2 |= sec_counter_CTRL2_IRQ_SEL;
            
            /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
            sec_counter_RT1 &= ((uint8)(~sec_counter_RT1_MASK));
            sec_counter_RT1 |= sec_counter_SYNC;     
                    
            /*Enable DSI Sync all all inputs of the Timer*/
            sec_counter_RT1 &= ((uint8)(~sec_counter_SYNCDSI_MASK));
            sec_counter_RT1 |= sec_counter_SYNCDSI_EN;

        #else
            #if(!sec_counter_ControlRegRemoved)
            /* Set the default compare mode defined in the parameter */
            ctrl = sec_counter_CONTROL & ((uint8)(~sec_counter_CTRL_CMPMODE_MASK));
            sec_counter_CONTROL = ctrl | sec_counter_DEFAULT_COMPARE_MODE;
            
            /* Set the default capture mode defined in the parameter */
            ctrl = sec_counter_CONTROL & ((uint8)(~sec_counter_CTRL_CAPMODE_MASK));
            
            #if( 0 != sec_counter_CAPTURE_MODE_CONF)
                sec_counter_CONTROL = ctrl | sec_counter_DEFAULT_CAPTURE_MODE;
            #else
                sec_counter_CONTROL = ctrl;
            #endif /* 0 != sec_counter_CAPTURE_MODE */ 
            
            #endif /* (!sec_counter_ControlRegRemoved) */
        #endif /* (sec_counter_UsingFixedFunction) */
        
        /* Clear all data in the FIFO's */
        #if (!sec_counter_UsingFixedFunction)
            sec_counter_ClearFIFO();
        #endif /* (!sec_counter_UsingFixedFunction) */
        
        /* Set Initial values from Configuration */
        sec_counter_WritePeriod(sec_counter_INIT_PERIOD_VALUE);
        #if (!(sec_counter_UsingFixedFunction && (CY_PSOC5A)))
            sec_counter_WriteCounter(sec_counter_INIT_COUNTER_VALUE);
        #endif /* (!(sec_counter_UsingFixedFunction && (CY_PSOC5A))) */
        sec_counter_SetInterruptMode(sec_counter_INIT_INTERRUPTS_MASK);
        
        #if (!sec_counter_UsingFixedFunction)
            /* Read the status register to clear the unwanted interrupts */
            (void)sec_counter_ReadStatusRegister();
            /* Set the compare value (only available to non-fixed function implementation */
            sec_counter_WriteCompare(sec_counter_INIT_COMPARE_VALUE);
            /* Use the interrupt output of the status register for IRQ output */
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            sec_counter_interruptState = CyEnterCriticalSection();
            
            sec_counter_STATUS_AUX_CTRL |= sec_counter_STATUS_ACTL_INT_EN_MASK;
            
            /* Exit Critical Region*/
            CyExitCriticalSection(sec_counter_interruptState);
            
        #endif /* (!sec_counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: sec_counter_Enable
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
void sec_counter_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (sec_counter_UsingFixedFunction)
        sec_counter_GLOBAL_ENABLE |= sec_counter_BLOCK_EN_MASK;
        sec_counter_GLOBAL_STBY_ENABLE |= sec_counter_BLOCK_STBY_EN_MASK;
    #endif /* (sec_counter_UsingFixedFunction) */  
        
    /* Enable the counter from the control register  */
    /* If Fixed Function then make sure Mode is set correctly */
    /* else make sure reset is clear */
    #if(!sec_counter_ControlRegRemoved || sec_counter_UsingFixedFunction)
        sec_counter_CONTROL |= sec_counter_CTRL_ENABLE;                
    #endif /* (!sec_counter_ControlRegRemoved || sec_counter_UsingFixedFunction) */
    
}


/*******************************************************************************
* Function Name: sec_counter_Start
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
*  sec_counter_initVar: Is modified when this function is called for the  
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void sec_counter_Start(void) 
{
    if(sec_counter_initVar == 0u)
    {
        sec_counter_Init();
        
        sec_counter_initVar = 1u; /* Clear this bit for Initialization */        
    }
    
    /* Enable the Counter */
    sec_counter_Enable();        
}


/*******************************************************************************
* Function Name: sec_counter_Stop
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
void sec_counter_Stop(void) 
{
    /* Disable Counter */
    #if(!sec_counter_ControlRegRemoved || sec_counter_UsingFixedFunction)
        sec_counter_CONTROL &= ((uint8)(~sec_counter_CTRL_ENABLE));        
    #endif /* (!sec_counter_ControlRegRemoved || sec_counter_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (sec_counter_UsingFixedFunction)
        sec_counter_GLOBAL_ENABLE &= ((uint8)(~sec_counter_BLOCK_EN_MASK));
        sec_counter_GLOBAL_STBY_ENABLE &= ((uint8)(~sec_counter_BLOCK_STBY_EN_MASK));
    #endif /* (sec_counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: sec_counter_SetInterruptMode
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
void sec_counter_SetInterruptMode(uint8 interruptsMask) 
{
    sec_counter_STATUS_MASK = interruptsMask;
}


/*******************************************************************************
* Function Name: sec_counter_ReadStatusRegister
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
uint8   sec_counter_ReadStatusRegister(void) 
{
    return sec_counter_STATUS;
}


#if(!sec_counter_ControlRegRemoved)
/*******************************************************************************
* Function Name: sec_counter_ReadControlRegister
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
uint8   sec_counter_ReadControlRegister(void) 
{
    return sec_counter_CONTROL;
}


/*******************************************************************************
* Function Name: sec_counter_WriteControlRegister
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
void    sec_counter_WriteControlRegister(uint8 control) 
{
    sec_counter_CONTROL = control;
}

#endif  /* (!sec_counter_ControlRegRemoved) */


#if (!(sec_counter_UsingFixedFunction && (CY_PSOC5A)))
/*******************************************************************************
* Function Name: sec_counter_WriteCounter
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
void sec_counter_WriteCounter(uint32 counter) \
                                   
{
    #if(sec_counter_UsingFixedFunction)
        /* assert if block is already enabled */
        CYASSERT (0u == (sec_counter_GLOBAL_ENABLE & sec_counter_BLOCK_EN_MASK));
        /* If block is disabled, enable it and then write the counter */
        sec_counter_GLOBAL_ENABLE |= sec_counter_BLOCK_EN_MASK;
        CY_SET_REG16(sec_counter_COUNTER_LSB_PTR, (uint16)counter);
        sec_counter_GLOBAL_ENABLE &= ((uint8)(~sec_counter_BLOCK_EN_MASK));
    #else
        CY_SET_REG32(sec_counter_COUNTER_LSB_PTR, counter);
    #endif /* (sec_counter_UsingFixedFunction) */
}
#endif /* (!(sec_counter_UsingFixedFunction && (CY_PSOC5A))) */


/*******************************************************************************
* Function Name: sec_counter_ReadCounter
********************************************************************************
* Summary:
* Returns the current value of the counter.  It doesn't matter
* if the counter is enabled or running.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint32) The present value of the counter.
*
*******************************************************************************/
uint32 sec_counter_ReadCounter(void) 
{
    /* Force capture by reading Accumulator */
    /* Must first do a software capture to be able to read the counter */
    /* It is up to the user code to make sure there isn't already captured data in the FIFO */
    #if(sec_counter_UsingFixedFunction)
		(void)CY_GET_REG16(sec_counter_COUNTER_LSB_PTR);
	#else
		(void)CY_GET_REG8(sec_counter_COUNTER_LSB_PTR_8BIT);
	#endif/* (sec_counter_UsingFixedFunction) */
    
    /* Read the data from the FIFO (or capture register for Fixed Function)*/
    #if(sec_counter_UsingFixedFunction)
        return ((uint32)CY_GET_REG16(sec_counter_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG32(sec_counter_STATICCOUNT_LSB_PTR));
    #endif /* (sec_counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: sec_counter_ReadCapture
********************************************************************************
* Summary:
*   This function returns the last value captured.
*
* Parameters:  
*  void
*
* Return: 
*  (uint32) Present Capture value.
*
*******************************************************************************/
uint32 sec_counter_ReadCapture(void) 
{
    #if(sec_counter_UsingFixedFunction)
        return ((uint32)CY_GET_REG16(sec_counter_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG32(sec_counter_STATICCOUNT_LSB_PTR));
    #endif /* (sec_counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: sec_counter_WritePeriod
********************************************************************************
* Summary:
* Changes the period of the counter.  The new period 
* will be loaded the next time terminal count is detected.
*
* Parameters:  
*  period: (uint32) A value of 0 will result in
*         the counter remaining at zero.  
*
* Return: 
*  void
*
*******************************************************************************/
void sec_counter_WritePeriod(uint32 period) 
{
    #if(sec_counter_UsingFixedFunction)
        CY_SET_REG16(sec_counter_PERIOD_LSB_PTR,(uint16)period);
    #else
        CY_SET_REG32(sec_counter_PERIOD_LSB_PTR, period);
    #endif /* (sec_counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: sec_counter_ReadPeriod
********************************************************************************
* Summary:
* Reads the current period value without affecting counter operation.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint32) Present period value.
*
*******************************************************************************/
uint32 sec_counter_ReadPeriod(void) 
{
    #if(sec_counter_UsingFixedFunction)
        return ((uint32)CY_GET_REG16(sec_counter_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG32(sec_counter_PERIOD_LSB_PTR));
    #endif /* (sec_counter_UsingFixedFunction) */
}


#if (!sec_counter_UsingFixedFunction)
/*******************************************************************************
* Function Name: sec_counter_WriteCompare
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
void sec_counter_WriteCompare(uint32 compare) \
                                   
{
    #if(sec_counter_UsingFixedFunction)
        CY_SET_REG16(sec_counter_COMPARE_LSB_PTR, (uint16)compare);
    #else
        CY_SET_REG32(sec_counter_COMPARE_LSB_PTR, compare);
    #endif /* (sec_counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: sec_counter_ReadCompare
********************************************************************************
* Summary:
* Returns the compare value.
*
* Parameters:  
*  void:
*
* Return: 
*  (uint32) Present compare value.
*
*******************************************************************************/
uint32 sec_counter_ReadCompare(void) 
{
    return (CY_GET_REG32(sec_counter_COMPARE_LSB_PTR));
}


#if (sec_counter_COMPARE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: sec_counter_SetCompareMode
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
void sec_counter_SetCompareMode(uint8 compareMode) 
{
    /* Clear the compare mode bits in the control register */
    sec_counter_CONTROL &= ((uint8)(~sec_counter_CTRL_CMPMODE_MASK));
    
    /* Write the new setting */
    sec_counter_CONTROL |= compareMode;
}
#endif  /* (sec_counter_COMPARE_MODE_SOFTWARE) */


#if (sec_counter_CAPTURE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: sec_counter_SetCaptureMode
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
void sec_counter_SetCaptureMode(uint8 captureMode) 
{
    /* Clear the capture mode bits in the control register */
    sec_counter_CONTROL &= ((uint8)(~sec_counter_CTRL_CAPMODE_MASK));
    
    /* Write the new setting */
    sec_counter_CONTROL |= ((uint8)((uint8)captureMode << sec_counter_CTRL_CAPMODE0_SHIFT));
}
#endif  /* (sec_counter_CAPTURE_MODE_SOFTWARE) */


/*******************************************************************************
* Function Name: sec_counter_ClearFIFO
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
void sec_counter_ClearFIFO(void) 
{

    while(0u != (sec_counter_ReadStatusRegister() & sec_counter_STATUS_FIFONEMP))
    {
        (void)sec_counter_ReadCapture();
    }

}
#endif  /* (!sec_counter_UsingFixedFunction) */


/* [] END OF FILE */

