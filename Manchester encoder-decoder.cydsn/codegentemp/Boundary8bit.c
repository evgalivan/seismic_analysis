/*******************************************************************************
* File Name: Boundary8bit.c  
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

#include "Boundary8bit.h"

uint8 Boundary8bit_initVar = 0u;


/*******************************************************************************
* Function Name: Boundary8bit_Init
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
void Boundary8bit_Init(void) 
{
        #if (!Boundary8bit_UsingFixedFunction && !Boundary8bit_ControlRegRemoved)
            uint8 ctrl;
        #endif /* (!Boundary8bit_UsingFixedFunction && !Boundary8bit_ControlRegRemoved) */
        
        #if(!Boundary8bit_UsingFixedFunction) 
            /* Interrupt State Backup for Critical Region*/
            uint8 Boundary8bit_interruptState;
        #endif /* (!Boundary8bit_UsingFixedFunction) */
        
        #if (Boundary8bit_UsingFixedFunction)
            /* Clear all bits but the enable bit (if it's already set for Timer operation */
            Boundary8bit_CONTROL &= Boundary8bit_CTRL_ENABLE;
            
            /* Clear the mode bits for continuous run mode */
            #if (CY_PSOC5A)
                Boundary8bit_CONTROL2 &= ((uint8)(~Boundary8bit_CTRL_MODE_MASK));
            #endif /* (CY_PSOC5A) */
            #if (CY_PSOC3 || CY_PSOC5LP)
                Boundary8bit_CONTROL3 &= ((uint8)(~Boundary8bit_CTRL_MODE_MASK));                
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            /* Check if One Shot mode is enabled i.e. RunMode !=0*/
            #if (Boundary8bit_RunModeUsed != 0x0u)
                /* Set 3rd bit of Control register to enable one shot mode */
                Boundary8bit_CONTROL |= Boundary8bit_ONESHOT;
            #endif /* (Boundary8bit_RunModeUsed != 0x0u) */
            
            /* Set the IRQ to use the status register interrupts */
            Boundary8bit_CONTROL2 |= Boundary8bit_CTRL2_IRQ_SEL;
            
            /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
            Boundary8bit_RT1 &= ((uint8)(~Boundary8bit_RT1_MASK));
            Boundary8bit_RT1 |= Boundary8bit_SYNC;     
                    
            /*Enable DSI Sync all all inputs of the Timer*/
            Boundary8bit_RT1 &= ((uint8)(~Boundary8bit_SYNCDSI_MASK));
            Boundary8bit_RT1 |= Boundary8bit_SYNCDSI_EN;

        #else
            #if(!Boundary8bit_ControlRegRemoved)
            /* Set the default compare mode defined in the parameter */
            ctrl = Boundary8bit_CONTROL & ((uint8)(~Boundary8bit_CTRL_CMPMODE_MASK));
            Boundary8bit_CONTROL = ctrl | Boundary8bit_DEFAULT_COMPARE_MODE;
            
            /* Set the default capture mode defined in the parameter */
            ctrl = Boundary8bit_CONTROL & ((uint8)(~Boundary8bit_CTRL_CAPMODE_MASK));
            
            #if( 0 != Boundary8bit_CAPTURE_MODE_CONF)
                Boundary8bit_CONTROL = ctrl | Boundary8bit_DEFAULT_CAPTURE_MODE;
            #else
                Boundary8bit_CONTROL = ctrl;
            #endif /* 0 != Boundary8bit_CAPTURE_MODE */ 
            
            #endif /* (!Boundary8bit_ControlRegRemoved) */
        #endif /* (Boundary8bit_UsingFixedFunction) */
        
        /* Clear all data in the FIFO's */
        #if (!Boundary8bit_UsingFixedFunction)
            Boundary8bit_ClearFIFO();
        #endif /* (!Boundary8bit_UsingFixedFunction) */
        
        /* Set Initial values from Configuration */
        Boundary8bit_WritePeriod(Boundary8bit_INIT_PERIOD_VALUE);
        #if (!(Boundary8bit_UsingFixedFunction && (CY_PSOC5A)))
            Boundary8bit_WriteCounter(Boundary8bit_INIT_COUNTER_VALUE);
        #endif /* (!(Boundary8bit_UsingFixedFunction && (CY_PSOC5A))) */
        Boundary8bit_SetInterruptMode(Boundary8bit_INIT_INTERRUPTS_MASK);
        
        #if (!Boundary8bit_UsingFixedFunction)
            /* Read the status register to clear the unwanted interrupts */
            (void)Boundary8bit_ReadStatusRegister();
            /* Set the compare value (only available to non-fixed function implementation */
            Boundary8bit_WriteCompare(Boundary8bit_INIT_COMPARE_VALUE);
            /* Use the interrupt output of the status register for IRQ output */
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            Boundary8bit_interruptState = CyEnterCriticalSection();
            
            Boundary8bit_STATUS_AUX_CTRL |= Boundary8bit_STATUS_ACTL_INT_EN_MASK;
            
            /* Exit Critical Region*/
            CyExitCriticalSection(Boundary8bit_interruptState);
            
        #endif /* (!Boundary8bit_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Boundary8bit_Enable
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
void Boundary8bit_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (Boundary8bit_UsingFixedFunction)
        Boundary8bit_GLOBAL_ENABLE |= Boundary8bit_BLOCK_EN_MASK;
        Boundary8bit_GLOBAL_STBY_ENABLE |= Boundary8bit_BLOCK_STBY_EN_MASK;
    #endif /* (Boundary8bit_UsingFixedFunction) */  
        
    /* Enable the counter from the control register  */
    /* If Fixed Function then make sure Mode is set correctly */
    /* else make sure reset is clear */
    #if(!Boundary8bit_ControlRegRemoved || Boundary8bit_UsingFixedFunction)
        Boundary8bit_CONTROL |= Boundary8bit_CTRL_ENABLE;                
    #endif /* (!Boundary8bit_ControlRegRemoved || Boundary8bit_UsingFixedFunction) */
    
}


/*******************************************************************************
* Function Name: Boundary8bit_Start
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
*  Boundary8bit_initVar: Is modified when this function is called for the  
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void Boundary8bit_Start(void) 
{
    if(Boundary8bit_initVar == 0u)
    {
        Boundary8bit_Init();
        
        Boundary8bit_initVar = 1u; /* Clear this bit for Initialization */        
    }
    
    /* Enable the Counter */
    Boundary8bit_Enable();        
}


/*******************************************************************************
* Function Name: Boundary8bit_Stop
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
void Boundary8bit_Stop(void) 
{
    /* Disable Counter */
    #if(!Boundary8bit_ControlRegRemoved || Boundary8bit_UsingFixedFunction)
        Boundary8bit_CONTROL &= ((uint8)(~Boundary8bit_CTRL_ENABLE));        
    #endif /* (!Boundary8bit_ControlRegRemoved || Boundary8bit_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (Boundary8bit_UsingFixedFunction)
        Boundary8bit_GLOBAL_ENABLE &= ((uint8)(~Boundary8bit_BLOCK_EN_MASK));
        Boundary8bit_GLOBAL_STBY_ENABLE &= ((uint8)(~Boundary8bit_BLOCK_STBY_EN_MASK));
    #endif /* (Boundary8bit_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Boundary8bit_SetInterruptMode
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
void Boundary8bit_SetInterruptMode(uint8 interruptsMask) 
{
    Boundary8bit_STATUS_MASK = interruptsMask;
}


/*******************************************************************************
* Function Name: Boundary8bit_ReadStatusRegister
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
uint8   Boundary8bit_ReadStatusRegister(void) 
{
    return Boundary8bit_STATUS;
}


#if(!Boundary8bit_ControlRegRemoved)
/*******************************************************************************
* Function Name: Boundary8bit_ReadControlRegister
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
uint8   Boundary8bit_ReadControlRegister(void) 
{
    return Boundary8bit_CONTROL;
}


/*******************************************************************************
* Function Name: Boundary8bit_WriteControlRegister
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
void    Boundary8bit_WriteControlRegister(uint8 control) 
{
    Boundary8bit_CONTROL = control;
}

#endif  /* (!Boundary8bit_ControlRegRemoved) */


#if (!(Boundary8bit_UsingFixedFunction && (CY_PSOC5A)))
/*******************************************************************************
* Function Name: Boundary8bit_WriteCounter
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
void Boundary8bit_WriteCounter(uint8 counter) \
                                   
{
    #if(Boundary8bit_UsingFixedFunction)
        /* assert if block is already enabled */
        CYASSERT (0u == (Boundary8bit_GLOBAL_ENABLE & Boundary8bit_BLOCK_EN_MASK));
        /* If block is disabled, enable it and then write the counter */
        Boundary8bit_GLOBAL_ENABLE |= Boundary8bit_BLOCK_EN_MASK;
        CY_SET_REG16(Boundary8bit_COUNTER_LSB_PTR, (uint16)counter);
        Boundary8bit_GLOBAL_ENABLE &= ((uint8)(~Boundary8bit_BLOCK_EN_MASK));
    #else
        CY_SET_REG8(Boundary8bit_COUNTER_LSB_PTR, counter);
    #endif /* (Boundary8bit_UsingFixedFunction) */
}
#endif /* (!(Boundary8bit_UsingFixedFunction && (CY_PSOC5A))) */


/*******************************************************************************
* Function Name: Boundary8bit_ReadCounter
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
uint8 Boundary8bit_ReadCounter(void) 
{
    /* Force capture by reading Accumulator */
    /* Must first do a software capture to be able to read the counter */
    /* It is up to the user code to make sure there isn't already captured data in the FIFO */
    #if(Boundary8bit_UsingFixedFunction)
		(void)CY_GET_REG16(Boundary8bit_COUNTER_LSB_PTR);
	#else
		(void)CY_GET_REG8(Boundary8bit_COUNTER_LSB_PTR_8BIT);
	#endif/* (Boundary8bit_UsingFixedFunction) */
    
    /* Read the data from the FIFO (or capture register for Fixed Function)*/
    #if(Boundary8bit_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(Boundary8bit_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG8(Boundary8bit_STATICCOUNT_LSB_PTR));
    #endif /* (Boundary8bit_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Boundary8bit_ReadCapture
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
uint8 Boundary8bit_ReadCapture(void) 
{
    #if(Boundary8bit_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(Boundary8bit_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG8(Boundary8bit_STATICCOUNT_LSB_PTR));
    #endif /* (Boundary8bit_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Boundary8bit_WritePeriod
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
void Boundary8bit_WritePeriod(uint8 period) 
{
    #if(Boundary8bit_UsingFixedFunction)
        CY_SET_REG16(Boundary8bit_PERIOD_LSB_PTR,(uint16)period);
    #else
        CY_SET_REG8(Boundary8bit_PERIOD_LSB_PTR, period);
    #endif /* (Boundary8bit_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Boundary8bit_ReadPeriod
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
uint8 Boundary8bit_ReadPeriod(void) 
{
    #if(Boundary8bit_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(Boundary8bit_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG8(Boundary8bit_PERIOD_LSB_PTR));
    #endif /* (Boundary8bit_UsingFixedFunction) */
}


#if (!Boundary8bit_UsingFixedFunction)
/*******************************************************************************
* Function Name: Boundary8bit_WriteCompare
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
void Boundary8bit_WriteCompare(uint8 compare) \
                                   
{
    #if(Boundary8bit_UsingFixedFunction)
        CY_SET_REG16(Boundary8bit_COMPARE_LSB_PTR, (uint16)compare);
    #else
        CY_SET_REG8(Boundary8bit_COMPARE_LSB_PTR, compare);
    #endif /* (Boundary8bit_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Boundary8bit_ReadCompare
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
uint8 Boundary8bit_ReadCompare(void) 
{
    return (CY_GET_REG8(Boundary8bit_COMPARE_LSB_PTR));
}


#if (Boundary8bit_COMPARE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: Boundary8bit_SetCompareMode
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
void Boundary8bit_SetCompareMode(uint8 compareMode) 
{
    /* Clear the compare mode bits in the control register */
    Boundary8bit_CONTROL &= ((uint8)(~Boundary8bit_CTRL_CMPMODE_MASK));
    
    /* Write the new setting */
    Boundary8bit_CONTROL |= compareMode;
}
#endif  /* (Boundary8bit_COMPARE_MODE_SOFTWARE) */


#if (Boundary8bit_CAPTURE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: Boundary8bit_SetCaptureMode
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
void Boundary8bit_SetCaptureMode(uint8 captureMode) 
{
    /* Clear the capture mode bits in the control register */
    Boundary8bit_CONTROL &= ((uint8)(~Boundary8bit_CTRL_CAPMODE_MASK));
    
    /* Write the new setting */
    Boundary8bit_CONTROL |= ((uint8)((uint8)captureMode << Boundary8bit_CTRL_CAPMODE0_SHIFT));
}
#endif  /* (Boundary8bit_CAPTURE_MODE_SOFTWARE) */


/*******************************************************************************
* Function Name: Boundary8bit_ClearFIFO
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
void Boundary8bit_ClearFIFO(void) 
{

    while(0u != (Boundary8bit_ReadStatusRegister() & Boundary8bit_STATUS_FIFONEMP))
    {
        (void)Boundary8bit_ReadCapture();
    }

}
#endif  /* (!Boundary8bit_UsingFixedFunction) */


/* [] END OF FILE */

