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
#include <Clock.h>

uint32 time_stamp_low, time_stamp_high;
    
long long convert_to_utc (uint32 high, uint32 low) {
    long long result = (((long long)high << usec_counter_Resolution) + low);
    result >>= 11;
    result /= 1000;
    result >>= 11;
    return result;
}

 long long convert_utc_to (uint32 sec){
    long long result = sec >> 2;
    result *= 1000;
    return result;
}

static volatile uint32 capture_high, capture_low1, capture_low2;
    
/* 
**********************************************************************
Функция compare_service меняет значение compare в счетчике 
usec_counter, если сработало прерывание по compare, а также .
Также если это событие произошло одновременно с capture не позволяет.
**********************************************************************
*/
void compare_service(uint32 tmp) 
{
    if ((tmp & usec_counter_STATUS_CMP) != 0)
    {
        capture_high = sec_counter_ReadCounter();
        uint32 compare =  capture_low2 = usec_counter_ReadCompare();
        compare += incr_compare;
        compare &= (1 << usec_counter_Resolution)-1; //накладываем маску, чтобы остаться внутри 24 разрядов
        usec_counter_WriteCompare(compare); 
        if (capture_flag == 0)
        {
            do{
                capture_low1 = capture_low2;
                capture_high = sec_counter_ReadCounter();
                capture_low2 = usec_counter_ReadCounter();                
            } while (capture_low1 > capture_low2);
            time_ready_flag = 1;
            *p_ex_buf = capture_high;
            *(p_ex_buf +1) = (capture_low2 << 8);
        }
        else{
            time_ready_flag = 1;
            *p_ex_buf = capture_high;
            *(p_ex_buf + 1) = (capture_low2 << 8);
        }
    }
    capture_flag = 0;
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
    
    
    
    uint8 tmp = usec_counter_ReadStatusRegister();
    cap_comp_tc_ClearPending();
    
    if ((tmp & usec_counter_STATUS_OVERFLOW) !=0){
        //здесь нужно заготовить кусок метки времени из страшего счетчика секунд.
        time_stamp_high = sec_counter_ReadCounter();
    }
    if ((tmp & usec_counter_STATUS_CAPTURE) != 0)
    {
        Control_Capture_Write(1);
        if (GlobalPrepareFlag) capture_flag = 1;
        capture_high = sec_counter_ReadCapture();
        capture_low2 = usec_counter_ReadCapture();
        if (GlobalPrepareFlag == 0){ /*должен быть флаг, была инициализация времени с GPS или нет?
                                                                        Есть ли реально время */
            if (GlobalTimeReady/* флаг факта наличия реалного времени с GPS*/){
                GlobalPrepareFlag = 1;
                //usec_counter_Stop();//because zero
                usec_counter_WriteCounter(0);
                sec_counter_WriteCounter(value_sec_gps);
                time_stamp_high = sec_counter_ReadCounter();
                time_stamp_low = 0;
                usec_counter_WriteCompare(time_stamp_low);
                //usec_counter_Start();;//because zero
            }
        }
        Control_Capture_Write(0);
    }
     
    //compare_service(tmp);
    
    //#define MAX_usec_VALUE ((1 << usec_counter_Resolution)-1)
    #define MAX_usec_VALUE (usec_counter_INIT_PERIOD_VALUE)
    if ((tmp & usec_counter_STATUS_CMP) != 0)
    {
        if (GlobalPrepareFlag){
            time_stamp_low += incr_compare;
            if (time_stamp_low > MAX_usec_VALUE){
                time_stamp_high++;
                time_stamp_low = 0;
            }
            usec_counter_WriteCompare(time_stamp_low);
//            time_stmp_buf[2] = time_stamp_high;
//            time_stmp_buf[3] = time_stamp_low;
        }
    }
    
    
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
