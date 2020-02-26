/*******************************************************************************
* File Name: Period.c
* Version 2.30
*
* Description:
*  This file provides the API source code for the Shift Register component.
*
* Note: none
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Period.h"

uint8 Period_initVar = 0u;


/*******************************************************************************
* Function Name: Period_Start
********************************************************************************
*
* Summary:
*  Starts the Shift Register.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Period_initVar - used to check initial configuration, modified on
*  first function call.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Period_Start(void) 
{
    if(0u == Period_initVar)
    {
        Period_Init();
        Period_initVar = 1u; /* Component initialized */
    }

    Period_Enable();
}


/*******************************************************************************
* Function Name: Period_Enable
********************************************************************************
*
* Summary:
*  Enables the Shift Register.
*
* Parameters:
*  void.
*
* Return:
*  void.
*
*******************************************************************************/
void Period_Enable(void) 
{
    /* Changing address in Datapath Control Store
       from NOP to component state machine commands space */
    Period_SR_CONTROL |= Period_CLK_EN;

    Period_EnableInt();
}


/*******************************************************************************
* Function Name: Period_Init
********************************************************************************
*
* Summary:
*  Initializes Tx and/or Rx interrupt sources with initial values.
*
* Parameters:
*  void.
*
* Return:
*  void.
*
*******************************************************************************/
void Period_Init(void) 
{
    Period_SetIntMode(Period_INT_SRC);
}


/*******************************************************************************
* Function Name: Period_Stop
********************************************************************************
*
* Summary:
*  Disables the Shift Register
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Period_Stop(void) 
{
    /*changing Datapath Control Store address to NOP space*/
    Period_SR_CONTROL &= ((uint8) ~Period_CLK_EN);
    Period_DisableInt();
}


/*******************************************************************************
* Function Name: Period_EnableInt
********************************************************************************
*
* Summary:
*  Enables the Shift Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Period_EnableInt(void) 
{
    uint8 interruptState;

    interruptState = CyEnterCriticalSection();
    Period_SR_AUX_CONTROL |= Period_INTERRUPTS_ENABLE;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Period_DisableInt
********************************************************************************
*
* Summary:
*  Disables the Shift Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Period_DisableInt(void) 
{
    uint8 interruptState;

    interruptState = CyEnterCriticalSection();
    Period_SR_AUX_CONTROL &= ((uint8) ~Period_INTERRUPTS_ENABLE);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Period_GetFIFOStatus
********************************************************************************
*
* Summary:
*  Returns current status of input or output FIFO.
*
* Parameters:
*  fifoId.
*
* Return:
*  FIFO status.
*
*******************************************************************************/
uint8 Period_GetFIFOStatus(uint8 fifoId) 
{
    uint8 result;

    result = Period_RET_FIFO_NOT_DEFINED;

    #if(0u != Period_USE_INPUT_FIFO)
        if(Period_IN_FIFO == fifoId)
        {
            switch(Period_GET_IN_FIFO_STS)
            {
                case Period_IN_FIFO_FULL :
                    result = Period_RET_FIFO_FULL;
                    break;

                case Period_IN_FIFO_EMPTY :
                    result = Period_RET_FIFO_EMPTY;
                    break;

                case Period_IN_FIFO_PARTIAL:
                    result = Period_RET_FIFO_PARTIAL;
                    break;
                    
                default:
                    /* Initial result value, while 
                       IN_FIFO_EMPTY case is false 
                     */
                    result = Period_RET_FIFO_EMPTY;
                    break;
            }   
        }
    #endif /* (0u != Period_USE_INPUT_FIFO) */

    if(Period_OUT_FIFO == fifoId)
    {
        switch(Period_GET_OUT_FIFO_STS)
        {
            case Period_OUT_FIFO_FULL :
                result = Period_RET_FIFO_FULL;
                break;

            case Period_OUT_FIFO_EMPTY :
                result = Period_RET_FIFO_EMPTY;
                break;

            case Period_OUT_FIFO_PARTIAL :
                result = Period_RET_FIFO_PARTIAL;
                break;

            default:
                /* Initial result value, while 
                   OUT_FIFO_FULL case is false 
                 */
                result = Period_RET_FIFO_FULL;
                break;
        }
    }

    return(result);
}


/*******************************************************************************
* Function Name: Period_SetIntMode
********************************************************************************
*
* Summary:
*  Sets the Interrupt Source for the Shift Register interrupt. Multiple
*  sources may be ORed together
*
* Parameters:
*  interruptSource: Byte containing the constant for the selected interrupt
*  source/s.
*
* Return:
*  None.
*
*******************************************************************************/
void Period_SetIntMode(uint8 interruptSource) 
{
    Period_SR_STATUS_MASK &= ((uint8) ~Period_INTS_EN_MASK);          /* Clear existing int */
    Period_SR_STATUS_MASK |= (interruptSource & Period_INTS_EN_MASK); /* Set int */
}


/*******************************************************************************
* Function Name: Period_GetIntStatus
********************************************************************************
*
* Summary:
*  Gets the Shift Register Interrupt status.
*
* Parameters:
*  None.
*
* Return:
*  Byte containing the constant for the selected interrupt source/s.
*
*******************************************************************************/
uint8 Period_GetIntStatus(void) 
{
    return(Period_SR_STATUS & Period_INTS_EN_MASK);
}


/*******************************************************************************
* Function Name: Period_WriteRegValue
********************************************************************************
*
* Summary:
*  Send state directly to shift register
*
* Parameters:
*  shiftData: containing shift register state.
*
* Return:
*  None.
*
*******************************************************************************/
void Period_WriteRegValue(uint32 shiftData)
                                                                     
{
    CY_SET_REG32(Period_SHIFT_REG_LSB_PTR, shiftData);
}


#if(0u != Period_USE_INPUT_FIFO)
    /*******************************************************************************
    * Function Name: Period_WriteData
    ********************************************************************************
    *
    * Summary:
    *  Send state to FIFO for later transfer to shift register based on the Load
    *  input
    *
    * Parameters:
    *  shiftData: containing shift register state.
    *
    * Return:
    *  Indicates: successful execution of function
    *  when FIFO is empty; and error when FIFO is full.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    cystatus Period_WriteData(uint32 shiftData)
                                                                         
    {
        cystatus result;

        result = CYRET_INVALID_STATE;

        /* Writes data into the input FIFO if it is not FULL */
        if(Period_RET_FIFO_FULL != (Period_GetFIFOStatus(Period_IN_FIFO)))
        {
            CY_SET_REG32(Period_IN_FIFO_VAL_LSB_PTR, shiftData);
            result = CYRET_SUCCESS;
        }

        return(result);
    }
#endif /* (0u != Period_USE_INPUT_FIFO) */


#if(0u != Period_USE_OUTPUT_FIFO)
    /*******************************************************************************
    * Function Name: Period_ReadData
    ********************************************************************************
    *
    * Summary:
    *  Returns state in FIFO due to Store input.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Shift Register state
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    uint32 Period_ReadData(void) 
    {
        return(CY_GET_REG32(Period_OUT_FIFO_VAL_LSB_PTR));
    }
#endif /* (0u != Period_USE_OUTPUT_FIFO) */


/*******************************************************************************
* Function Name: Period_ReadRegValue
********************************************************************************
*
* Summary:
*  Directly returns current state in shift register, not data in FIFO due
*  to Store input.
*
* Parameters:
*  None.
*
* Return:
*  Shift Register state. Clears output FIFO.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint32 Period_ReadRegValue(void) 
{
    uint32 result;

    /* Clear FIFO before software capture */
    while(Period_RET_FIFO_EMPTY != Period_GetFIFOStatus(Period_OUT_FIFO))
    {
        (void) CY_GET_REG32(Period_OUT_FIFO_VAL_LSB_PTR);
    }

    /* Read of 8 bits from A1 causes capture to output FIFO */
    (void) CY_GET_REG8(Period_SHIFT_REG_CAPTURE_PTR);

    /* Read output FIFO */
    result  = CY_GET_REG32(Period_OUT_FIFO_VAL_LSB_PTR);
    
    #if(0u != (Period_SR_SIZE % 8u))
        result &= ((uint32) Period_SR_MASK);
    #endif /* (0u != (Period_SR_SIZE % 8u)) */
    
    return(result);
}


/* [] END OF FILE */
