/*******************************************************************************
* File Name: RecieveShiftReg.c
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

#include "RecieveShiftReg.h"

uint8 RecieveShiftReg_initVar = 0u;


/*******************************************************************************
* Function Name: RecieveShiftReg_Start
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
*  RecieveShiftReg_initVar - used to check initial configuration, modified on
*  first function call.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void RecieveShiftReg_Start(void) 
{
    if(0u == RecieveShiftReg_initVar)
    {
        RecieveShiftReg_Init();
        RecieveShiftReg_initVar = 1u; /* Component initialized */
    }

    RecieveShiftReg_Enable();
}


/*******************************************************************************
* Function Name: RecieveShiftReg_Enable
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
void RecieveShiftReg_Enable(void) 
{
    /* Changing address in Datapath Control Store
       from NOP to component state machine commands space */
    RecieveShiftReg_SR_CONTROL |= RecieveShiftReg_CLK_EN;

    RecieveShiftReg_EnableInt();
}


/*******************************************************************************
* Function Name: RecieveShiftReg_Init
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
void RecieveShiftReg_Init(void) 
{
    RecieveShiftReg_SetIntMode(RecieveShiftReg_INT_SRC);
}


/*******************************************************************************
* Function Name: RecieveShiftReg_Stop
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
void RecieveShiftReg_Stop(void) 
{
    /*changing Datapath Control Store address to NOP space*/
    RecieveShiftReg_SR_CONTROL &= ((uint8) ~RecieveShiftReg_CLK_EN);
    RecieveShiftReg_DisableInt();
}


/*******************************************************************************
* Function Name: RecieveShiftReg_EnableInt
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
void RecieveShiftReg_EnableInt(void) 
{
    uint8 interruptState;

    interruptState = CyEnterCriticalSection();
    RecieveShiftReg_SR_AUX_CONTROL |= RecieveShiftReg_INTERRUPTS_ENABLE;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: RecieveShiftReg_DisableInt
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
void RecieveShiftReg_DisableInt(void) 
{
    uint8 interruptState;

    interruptState = CyEnterCriticalSection();
    RecieveShiftReg_SR_AUX_CONTROL &= ((uint8) ~RecieveShiftReg_INTERRUPTS_ENABLE);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: RecieveShiftReg_GetFIFOStatus
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
uint8 RecieveShiftReg_GetFIFOStatus(uint8 fifoId) 
{
    uint8 result;

    result = RecieveShiftReg_RET_FIFO_NOT_DEFINED;

    #if(0u != RecieveShiftReg_USE_INPUT_FIFO)
        if(RecieveShiftReg_IN_FIFO == fifoId)
        {
            switch(RecieveShiftReg_GET_IN_FIFO_STS)
            {
                case RecieveShiftReg_IN_FIFO_FULL :
                    result = RecieveShiftReg_RET_FIFO_FULL;
                    break;

                case RecieveShiftReg_IN_FIFO_EMPTY :
                    result = RecieveShiftReg_RET_FIFO_EMPTY;
                    break;

                case RecieveShiftReg_IN_FIFO_PARTIAL:
                    result = RecieveShiftReg_RET_FIFO_PARTIAL;
                    break;
                    
                default:
                    /* Initial result value, while 
                       IN_FIFO_EMPTY case is false 
                     */
                    result = RecieveShiftReg_RET_FIFO_EMPTY;
                    break;
            }   
        }
    #endif /* (0u != RecieveShiftReg_USE_INPUT_FIFO) */

    if(RecieveShiftReg_OUT_FIFO == fifoId)
    {
        switch(RecieveShiftReg_GET_OUT_FIFO_STS)
        {
            case RecieveShiftReg_OUT_FIFO_FULL :
                result = RecieveShiftReg_RET_FIFO_FULL;
                break;

            case RecieveShiftReg_OUT_FIFO_EMPTY :
                result = RecieveShiftReg_RET_FIFO_EMPTY;
                break;

            case RecieveShiftReg_OUT_FIFO_PARTIAL :
                result = RecieveShiftReg_RET_FIFO_PARTIAL;
                break;

            default:
                /* Initial result value, while 
                   OUT_FIFO_FULL case is false 
                 */
                result = RecieveShiftReg_RET_FIFO_FULL;
                break;
        }
    }

    return(result);
}


/*******************************************************************************
* Function Name: RecieveShiftReg_SetIntMode
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
void RecieveShiftReg_SetIntMode(uint8 interruptSource) 
{
    RecieveShiftReg_SR_STATUS_MASK &= ((uint8) ~RecieveShiftReg_INTS_EN_MASK);          /* Clear existing int */
    RecieveShiftReg_SR_STATUS_MASK |= (interruptSource & RecieveShiftReg_INTS_EN_MASK); /* Set int */
}


/*******************************************************************************
* Function Name: RecieveShiftReg_GetIntStatus
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
uint8 RecieveShiftReg_GetIntStatus(void) 
{
    return(RecieveShiftReg_SR_STATUS & RecieveShiftReg_INTS_EN_MASK);
}


/*******************************************************************************
* Function Name: RecieveShiftReg_WriteRegValue
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
void RecieveShiftReg_WriteRegValue(uint32 shiftData)
                                                                     
{
    CY_SET_REG32(RecieveShiftReg_SHIFT_REG_LSB_PTR, shiftData);
}


#if(0u != RecieveShiftReg_USE_INPUT_FIFO)
    /*******************************************************************************
    * Function Name: RecieveShiftReg_WriteData
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
    cystatus RecieveShiftReg_WriteData(uint32 shiftData)
                                                                         
    {
        cystatus result;

        result = CYRET_INVALID_STATE;

        /* Writes data into the input FIFO if it is not FULL */
        if(RecieveShiftReg_RET_FIFO_FULL != (RecieveShiftReg_GetFIFOStatus(RecieveShiftReg_IN_FIFO)))
        {
            CY_SET_REG32(RecieveShiftReg_IN_FIFO_VAL_LSB_PTR, shiftData);
            result = CYRET_SUCCESS;
        }

        return(result);
    }
#endif /* (0u != RecieveShiftReg_USE_INPUT_FIFO) */


#if(0u != RecieveShiftReg_USE_OUTPUT_FIFO)
    /*******************************************************************************
    * Function Name: RecieveShiftReg_ReadData
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
    uint32 RecieveShiftReg_ReadData(void) 
    {
        return(CY_GET_REG32(RecieveShiftReg_OUT_FIFO_VAL_LSB_PTR));
    }
#endif /* (0u != RecieveShiftReg_USE_OUTPUT_FIFO) */


/*******************************************************************************
* Function Name: RecieveShiftReg_ReadRegValue
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
uint32 RecieveShiftReg_ReadRegValue(void) 
{
    uint32 result;

    /* Clear FIFO before software capture */
    while(RecieveShiftReg_RET_FIFO_EMPTY != RecieveShiftReg_GetFIFOStatus(RecieveShiftReg_OUT_FIFO))
    {
        (void) CY_GET_REG32(RecieveShiftReg_OUT_FIFO_VAL_LSB_PTR);
    }

    /* Read of 8 bits from A1 causes capture to output FIFO */
    (void) CY_GET_REG8(RecieveShiftReg_SHIFT_REG_CAPTURE_PTR);

    /* Read output FIFO */
    result  = CY_GET_REG32(RecieveShiftReg_OUT_FIFO_VAL_LSB_PTR);
    
    #if(0u != (RecieveShiftReg_SR_SIZE % 8u))
        result &= ((uint32) RecieveShiftReg_SR_MASK);
    #endif /* (0u != (RecieveShiftReg_SR_SIZE % 8u)) */
    
    return(result);
}


/* [] END OF FILE */
