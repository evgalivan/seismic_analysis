/*******************************************************************************
* File Name: cap_comp_tc.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <cap_comp_tc.h>
#include "cyapicallbacks.h"

#if !defined(cap_comp_tc__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START cap_comp_tc_intc` */
    
    #include <global.h>
    #include <Capture_high.h>
    #include <Capture_low.h>
    #include <Clock.h>
    
    #define COUNTER_BITS 16
    #define COUNTER_PERIOD (1<<(COUNTER_BITS))
    #define HALF_PERIOD (1<<(COUNTER_BITS-1))
    
    #define ADC_SAMPLING_PERIOD_BITS (12)  // todo must be variable
    #define ADC_SAMPLING_PERIOD (1<<( ADC_SAMPLING_PERIOD_BITS))  // todo must be variable
    #define GAP ( ADC_SAMPLING_PERIOD >>7)  // todo must be variable
    
    #define ADC_SAMPLING_PERIOD_MASK (ADC_SAMPLING_PERIOD - 1)
    
    
    static int tmp;
    static uint32 ReEnter_flag = 0;
    int FirstTimeFlag= 0;
    uint32 UpdateFrequencyFlag=1;
    uint32 PrevCapture= COUNTER_PERIOD;
    int32 CurrentDelta;
    
    void PrepareNewFrequency(void){
        
        tmp = (uint32)Capture_high_Read()<<8;
        tmp += Capture_low_Read();
   
        if(FirstTimeFlag==0){
            FirstTimeFlag = 1;
            PrevCapture = tmp;
            UpdateFrequencyFlag = 0;
            return;
        }
            
        
        CurrentDelta = tmp - PrevCapture;
        PrevCapture = tmp;
        
//        UpdateFrequencyFlag = 1;

        if( CurrentDelta < 0) CurrentDelta += COUNTER_PERIOD;

            if((CurrentDelta > (ADC_SAMPLING_PERIOD<<1))||(CurrentDelta < (ADC_SAMPLING_PERIOD>>1))){
                PrevCapture = tmp;
                UpdateFrequencyFlag = 0;
                return;
            }

            CurrentDelta = (ADC_SAMPLING_PERIOD<<1) - CurrentDelta;
            //CurrentDelta = (ADC_SAMPLING_PERIOD);
            
            
            uint32 PlusDelta = PrevCapture & ADC_SAMPLING_PERIOD_MASK;
            
            if ((ADC_SAMPLING_PERIOD>>1) > PlusDelta) PlusDelta += ADC_SAMPLING_PERIOD;
            
            PlusDelta = (ADC_SAMPLING_PERIOD<<1) - PlusDelta;
            //PlusDelta = (ADC_SAMPLING_PERIOD);
            
            NewFrequency = ((((CurrentDelta*NewFrequency)) >> ADC_SAMPLING_PERIOD_BITS) * PlusDelta) >> ADC_SAMPLING_PERIOD_BITS;
            
            if(NewFrequency > HighFrequency) NewFrequency = HighFrequency;
            if(NewFrequency < LowFrequency) NewFrequency = LowFrequency;
            
    }
    
    
    
/* `#END` */

#ifndef CYINT_IRQ_BASE
#define CYINT_IRQ_BASE      16
#endif /* CYINT_IRQ_BASE */
#ifndef CYINT_VECT_TABLE
#define CYINT_VECT_TABLE    ((cyisraddress **) CYREG_NVIC_VECT_OFFSET)
#endif /* CYINT_VECT_TABLE */

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: cap_comp_tc_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it. This function disables the interrupt, 
*  sets the default interrupt vector, sets the priority from the value in the
*  Design Wide Resources Interrupt Editor, then enables the interrupt to the 
*  interrupt controller.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void cap_comp_tc_Start(void)
{
    /* For all we know the interrupt is active. */
    cap_comp_tc_Disable();

    /* Set the ISR to point to the cap_comp_tc Interrupt. */
    cap_comp_tc_SetVector(&cap_comp_tc_Interrupt);

    /* Set the priority. */
    cap_comp_tc_SetPriority((uint8)cap_comp_tc_INTC_PRIOR_NUMBER);

    /* Enable it. */
    cap_comp_tc_Enable();
}


/*******************************************************************************
* Function Name: cap_comp_tc_StartEx
********************************************************************************
*
* Summary:
*  Sets up the interrupt and enables it. This function disables the interrupt,
*  sets the interrupt vector based on the address passed in, sets the priority 
*  from the value in the Design Wide Resources Interrupt Editor, then enables 
*  the interrupt to the interrupt controller.
*  
*  When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*  used to provide consistent definition across compilers:
*  
*  Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*   Function prototype example:
*   CY_ISR_PROTO(MyISR);
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void cap_comp_tc_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    cap_comp_tc_Disable();

    /* Set the ISR to point to the cap_comp_tc Interrupt. */
    cap_comp_tc_SetVector(address);

    /* Set the priority. */
    cap_comp_tc_SetPriority((uint8)cap_comp_tc_INTC_PRIOR_NUMBER);

    /* Enable it. */
    cap_comp_tc_Enable();
}


/*******************************************************************************
* Function Name: cap_comp_tc_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void cap_comp_tc_Stop(void)
{
    /* Disable this interrupt. */
    cap_comp_tc_Disable();

    /* Set the ISR to point to the passive one. */
    cap_comp_tc_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: cap_comp_tc_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for cap_comp_tc.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
* Parameters:  
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(cap_comp_tc_Interrupt)
{
    #ifdef cap_comp_tc_INTERRUPT_INTERRUPT_CALLBACK
        cap_comp_tc_Interrupt_InterruptCallback();
    #endif /* cap_comp_tc_INTERRUPT_INTERRUPT_CALLBACK */ 

    /*  Place your Interrupt code here. */
    /* `#START cap_comp_tc_Interrupt` */
    
    cap_comp_tc_ClearPending();     // must TO DO first!
    UpdateFrequencyFlag = 1;

//    tmp = (uint32)Capture_high_Read()<<8;
//    tmp += Capture_low_Read();
//   
//    if(FirstTimeFlag==0){
//        FirstTimeFlag = 1;
//        PrevCapture = tmp;
//        UpdateFrequencyFlag = 0;
//        return;
//    }
//    
//    
//    CurrentDelta = tmp - PrevCapture;
//    PrevCapture = tmp;
//    
//    UpdateFrequencyFlag = 1;
    
//    PrepareNewFrequency();
//    if(UpdateFrequencyFlag != 0){
//                UpdateFrequency(NewFrequency);
//                UpdateFrequencyFlag = 0;
//    }
    
    
        /*TO DO
            Если не было ни одного фрейма никогда, то мы ничего с нашим осциллятором не делаем
            Если пришел 1ый в истории фрейм , то мы сбрасываем (reset) счетик и уставнавливем ему период в соответсвии с перодом дискретизации.
            Если не 1ый, то берем capture и сравниваем с неким порогом (если он меньше половины периода, то мы должны уменьшить скорость генератора, а если больше, то увеличить на единичку) 
            2 опросить акселерометр и подготовить усредненные данные; (опрашивем чаще чем отсылаем, потому можно усреднить)
        */
    /* `#END` */
}


/*******************************************************************************
* Function Name: cap_comp_tc_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling cap_comp_tc_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use cap_comp_tc_StartEx instead.
* 
*   When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*   used to provide consistent definition across compilers:
*
*   Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*
*   Function prototype example:
*     CY_ISR_PROTO(MyISR);
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void cap_comp_tc_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)cap_comp_tc__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: cap_comp_tc_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress cap_comp_tc_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)cap_comp_tc__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: cap_comp_tc_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. 
*
*   Note calling cap_comp_tc_Start or cap_comp_tc_StartEx will 
*   override any effect this API would have had. This API should only be called
*   after cap_comp_tc_Start or cap_comp_tc_StartEx has been called. 
*   To set the initial priority for the component, use the Design-Wide Resources
*   Interrupt Editor.
*
*   Note This API has no effect on Non-maskable interrupt NMI).
*
* Parameters:
*   priority: Priority of the interrupt, 0 being the highest priority
*             PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*             PSoC 4: Priority is from 0 to 3.
*
* Return:
*   None
*
*******************************************************************************/
void cap_comp_tc_SetPriority(uint8 priority)
{
    *cap_comp_tc_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: cap_comp_tc_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt, 0 being the highest priority
*    PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*    PSoC 4: Priority is from 0 to 3.
*
*******************************************************************************/
uint8 cap_comp_tc_GetPriority(void)
{
    uint8 priority;


    priority = *cap_comp_tc_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: cap_comp_tc_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt to the interrupt controller. Do not call this function
*   unless ISR_Start() has been called or the functionality of the ISR_Start() 
*   function, which sets the vector and the priority, has been called.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void cap_comp_tc_Enable(void)
{
    /* Enable the general interrupt. */
    *cap_comp_tc_INTC_SET_EN = cap_comp_tc__INTC_MASK;
}


/*******************************************************************************
* Function Name: cap_comp_tc_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 cap_comp_tc_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*cap_comp_tc_INTC_SET_EN & (uint32)cap_comp_tc__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: cap_comp_tc_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt in the interrupt controller.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void cap_comp_tc_Disable(void)
{
    /* Disable the general interrupt. */
    *cap_comp_tc_INTC_CLR_EN = cap_comp_tc__INTC_MASK;
}


/*******************************************************************************
* Function Name: cap_comp_tc_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
* Side Effects:
*   If interrupts are enabled and the interrupt is set up properly, the ISR is
*   entered (depending on the priority of this interrupt and other pending 
*   interrupts).
*
*******************************************************************************/
void cap_comp_tc_SetPending(void)
{
    *cap_comp_tc_INTC_SET_PD = cap_comp_tc__INTC_MASK;
}


/*******************************************************************************
* Function Name: cap_comp_tc_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt in the interrupt controller.
*
*   Note Some interrupt sources are clear-on-read and require the block 
*   interrupt/status register to be read/cleared with the appropriate block API 
*   (GPIO, UART, and so on). Otherwise the ISR will continue to remain in 
*   pending state even though the interrupt itself is cleared using this API.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void cap_comp_tc_ClearPending(void)
{
    *cap_comp_tc_INTC_CLR_PD = cap_comp_tc__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */