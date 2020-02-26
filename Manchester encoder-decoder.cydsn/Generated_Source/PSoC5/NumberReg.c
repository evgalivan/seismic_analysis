/*******************************************************************************
* File Name: NumberReg.c
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

#include "NumberReg.h"

uint8 NumberReg_initVar = 0u;


/*******************************************************************************
* Function Name: NumberReg_Start
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
*  NumberReg_initVar - used to check initial configuration, modified on
*  first function call.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void NumberReg_Start(void) 
{
    if(0u == NumberReg_initVar)
    {
        NumberReg_Init();
        NumberReg_initVar = 1u; /* Component initialized */
    }

    NumberReg_Enable();
}


/*******************************************************************************
* Function Name: NumberReg_Enable
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
void NumberReg_Enable(void) 
{
    /* Changing address in Datapath Control Store
       from NOP to component state machine commands space */
    NumberReg_SR_CONTROL |= NumberReg_CLK_EN;

    NumberReg_EnableInt();
}


/*******************************************************************************
* Function Name: NumberReg_Init
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
void NumberReg_Init(void) 
{
    NumberReg_SetIntMode(NumberReg_INT_SRC);
}


/*******************************************************************************
* Function Name: NumberReg_Stop
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
void NumberReg_Stop(void) 
{
    /*changing Datapath Control Store address to NOP space*/
    NumberReg_SR_CONTROL &= ((uint8) ~NumberReg_CLK_EN);
    NumberReg_DisableInt();
}


/*******************************************************************************
* Function Name: NumberReg_EnableInt
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
void NumberReg_EnableInt(void) 
{
    uint8 interruptState;

    interruptState = CyEnterCriticalSection();
    NumberReg_SR_AUX_CONTROL |= NumberReg_INTERRUPTS_ENABLE;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: NumberReg_DisableInt
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
void NumberReg_DisableInt(void) 
{
    uint8 interruptState;

    interruptState = CyEnterCriticalSection();
    NumberReg_SR_AUX_CONTROL &= ((uint8) ~NumberReg_INTERRUPTS_ENABLE);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: NumberReg_GetFIFOStatus
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
uint8 NumberReg_GetFIFOStatus(uint8 fifoId) 
{
    uint8 result;

    result = NumberReg_RET_FIFO_NOT_DEFINED;

    #if(0u != NumberReg_USE_INPUT_FIFO)
        if(NumberReg_IN_FIFO == fifoId)
        {
            switch(NumberReg_GET_IN_FIFO_STS)
            {
                case NumberReg_IN_FIFO_FULL :
                    result = NumberReg_RET_FIFO_FULL;
                    break;

                case NumberReg_IN_FIFO_EMPTY :
                    result = NumberReg_RET_FIFO_EMPTY;
                    break;

                case NumberReg_IN_FIFO_PARTIAL:
                    result = NumberReg_RET_FIFO_PARTIAL;
                    break;
                    
                default:
                    /* Initial result value, while 
                       IN_FIFO_EMPTY case is false 
                     */
                    result = NumberReg_RET_FIFO_EMPTY;
                    break;
            }   
        }
    #endif /* (0u != NumberReg_USE_INPUT_FIFO) */

    if(NumberReg_OUT_FIFO == fifoId)
    {
        switch(NumberReg_GET_OUT_FIFO_STS)
        {
            case NumberReg_OUT_FIFO_FULL :
                result = NumberReg_RET_FIFO_FULL;
                break;

            case NumberReg_OUT_FIFO_EMPTY :
                result = NumberReg_RET_FIFO_EMPTY;
                break;

            case NumberReg_OUT_FIFO_PARTIAL :
                result = NumberReg_RET_FIFO_PARTIAL;
                break;

            default:
                /* Initial result value, while 
                   OUT_FIFO_FULL case is false 
                 */
                result = NumberReg_RET_FIFO_FULL;
                break;
        }
    }

    return(result);
}


/*******************************************************************************
* Function Name: NumberReg_SetIntMode
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
void NumberReg_SetIntMode(uint8 interruptSource) 
{
    NumberReg_SR_STATUS_MASK &= ((uint8) ~NumberReg_INTS_EN_MASK);          /* Clear existing int */
    NumberReg_SR_STATUS_MASK |= (interruptSource & NumberReg_INTS_EN_MASK); /* Set int */
}


/*******************************************************************************
* Function Name: NumberReg_GetIntStatus
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
uint8 NumberReg_GetIntStatus(void) 
{
    return(NumberReg_SR_STATUS & NumberReg_INTS_EN_MASK);
}


/*******************************************************************************
* Function Name: NumberReg_WriteRegValue
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
void NumberReg_WriteRegValue(uint32 shiftData)
                                                                     
{
    CY_SET_REG32(NumberReg_SHIFT_REG_LSB_PTR, shiftData);
}


#if(0u != NumberReg_USE_INPUT_FIFO)
    /*******************************************************************************
    * Function Name: NumberReg_WriteData
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
    cystatus NumberReg_WriteData(uint32 shiftData)
                                                                         
    {
        cystatus result;

        result = CYRET_INVALID_STATE;

        /* Writes data into the input FIFO if it is not FULL */
        if(NumberReg_RET_FIFO_FULL != (NumberReg_GetFIFOStatus(NumberReg_IN_FIFO)))
        {
            CY_SET_REG32(NumberReg_IN_FIFO_VAL_LSB_PTR, shiftData);
            result = CYRET_SUCCESS;
        }

        return(result);
    }
#endif /* (0u != NumberReg_USE_INPUT_FIFO) */


#if(0u != NumberReg_USE_OUTPUT_FIFO)
    /*******************************************************************************
    * Function Name: NumberReg_ReadData
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
    uint32 NumberReg_ReadData(void) 
    {
        return(CY_GET_REG32(NumberReg_OUT_FIFO_VAL_LSB_PTR));
    }
#endif /* (0u != NumberReg_USE_OUTPUT_FIFO) */


/*******************************************************************************
* Function Name: NumberReg_ReadRegValue
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
uint32 NumberReg_ReadRegValue(void) 
{
    uint32 result;

    /* Clear FIFO before software capture */
    while(NumberReg_RET_FIFO_EMPTY != NumberReg_GetFIFOStatus(NumberReg_OUT_FIFO))
    {
        (void) CY_GET_REG32(NumberReg_OUT_FIFO_VAL_LSB_PTR);
    }

    /* Read of 8 bits from A1 causes capture to output FIFO */
    (void) CY_GET_REG8(NumberReg_SHIFT_REG_CAPTURE_PTR);

    /* Read output FIFO */
    result  = CY_GET_REG32(NumberReg_OUT_FIFO_VAL_LSB_PTR);
    
    #if(0u != (NumberReg_SR_SIZE % 8u))
        result &= ((uint32) NumberReg_SR_MASK);
    #endif /* (0u != (NumberReg_SR_SIZE % 8u)) */
    
    return(result);
}


/* [] END OF FILE */
