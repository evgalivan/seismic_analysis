/*******************************************************************************
* File Name: DeltaReg.c
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

#include "DeltaReg.h"

uint8 DeltaReg_initVar = 0u;


/*******************************************************************************
* Function Name: DeltaReg_Start
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
*  DeltaReg_initVar - used to check initial configuration, modified on
*  first function call.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void DeltaReg_Start(void) 
{
    if(0u == DeltaReg_initVar)
    {
        DeltaReg_Init();
        DeltaReg_initVar = 1u; /* Component initialized */
    }

    DeltaReg_Enable();
}


/*******************************************************************************
* Function Name: DeltaReg_Enable
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
void DeltaReg_Enable(void) 
{
    /* Changing address in Datapath Control Store
       from NOP to component state machine commands space */
    DeltaReg_SR_CONTROL |= DeltaReg_CLK_EN;

    DeltaReg_EnableInt();
}


/*******************************************************************************
* Function Name: DeltaReg_Init
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
void DeltaReg_Init(void) 
{
    DeltaReg_SetIntMode(DeltaReg_INT_SRC);
}


/*******************************************************************************
* Function Name: DeltaReg_Stop
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
void DeltaReg_Stop(void) 
{
    /*changing Datapath Control Store address to NOP space*/
    DeltaReg_SR_CONTROL &= ((uint8) ~DeltaReg_CLK_EN);
    DeltaReg_DisableInt();
}


/*******************************************************************************
* Function Name: DeltaReg_EnableInt
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
void DeltaReg_EnableInt(void) 
{
    uint8 interruptState;

    interruptState = CyEnterCriticalSection();
    DeltaReg_SR_AUX_CONTROL |= DeltaReg_INTERRUPTS_ENABLE;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: DeltaReg_DisableInt
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
void DeltaReg_DisableInt(void) 
{
    uint8 interruptState;

    interruptState = CyEnterCriticalSection();
    DeltaReg_SR_AUX_CONTROL &= ((uint8) ~DeltaReg_INTERRUPTS_ENABLE);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: DeltaReg_GetFIFOStatus
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
uint8 DeltaReg_GetFIFOStatus(uint8 fifoId) 
{
    uint8 result;

    result = DeltaReg_RET_FIFO_NOT_DEFINED;

    #if(0u != DeltaReg_USE_INPUT_FIFO)
        if(DeltaReg_IN_FIFO == fifoId)
        {
            switch(DeltaReg_GET_IN_FIFO_STS)
            {
                case DeltaReg_IN_FIFO_FULL :
                    result = DeltaReg_RET_FIFO_FULL;
                    break;

                case DeltaReg_IN_FIFO_EMPTY :
                    result = DeltaReg_RET_FIFO_EMPTY;
                    break;

                case DeltaReg_IN_FIFO_PARTIAL:
                    result = DeltaReg_RET_FIFO_PARTIAL;
                    break;
                    
                default:
                    /* Initial result value, while 
                       IN_FIFO_EMPTY case is false 
                     */
                    result = DeltaReg_RET_FIFO_EMPTY;
                    break;
            }   
        }
    #endif /* (0u != DeltaReg_USE_INPUT_FIFO) */

    if(DeltaReg_OUT_FIFO == fifoId)
    {
        switch(DeltaReg_GET_OUT_FIFO_STS)
        {
            case DeltaReg_OUT_FIFO_FULL :
                result = DeltaReg_RET_FIFO_FULL;
                break;

            case DeltaReg_OUT_FIFO_EMPTY :
                result = DeltaReg_RET_FIFO_EMPTY;
                break;

            case DeltaReg_OUT_FIFO_PARTIAL :
                result = DeltaReg_RET_FIFO_PARTIAL;
                break;

            default:
                /* Initial result value, while 
                   OUT_FIFO_FULL case is false 
                 */
                result = DeltaReg_RET_FIFO_FULL;
                break;
        }
    }

    return(result);
}


/*******************************************************************************
* Function Name: DeltaReg_SetIntMode
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
void DeltaReg_SetIntMode(uint8 interruptSource) 
{
    DeltaReg_SR_STATUS_MASK &= ((uint8) ~DeltaReg_INTS_EN_MASK);          /* Clear existing int */
    DeltaReg_SR_STATUS_MASK |= (interruptSource & DeltaReg_INTS_EN_MASK); /* Set int */
}


/*******************************************************************************
* Function Name: DeltaReg_GetIntStatus
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
uint8 DeltaReg_GetIntStatus(void) 
{
    return(DeltaReg_SR_STATUS & DeltaReg_INTS_EN_MASK);
}


/*******************************************************************************
* Function Name: DeltaReg_WriteRegValue
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
void DeltaReg_WriteRegValue(uint32 shiftData)
                                                                     
{
    CY_SET_REG32(DeltaReg_SHIFT_REG_LSB_PTR, shiftData);
}


#if(0u != DeltaReg_USE_INPUT_FIFO)
    /*******************************************************************************
    * Function Name: DeltaReg_WriteData
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
    cystatus DeltaReg_WriteData(uint32 shiftData)
                                                                         
    {
        cystatus result;

        result = CYRET_INVALID_STATE;

        /* Writes data into the input FIFO if it is not FULL */
        if(DeltaReg_RET_FIFO_FULL != (DeltaReg_GetFIFOStatus(DeltaReg_IN_FIFO)))
        {
            CY_SET_REG32(DeltaReg_IN_FIFO_VAL_LSB_PTR, shiftData);
            result = CYRET_SUCCESS;
        }

        return(result);
    }
#endif /* (0u != DeltaReg_USE_INPUT_FIFO) */


#if(0u != DeltaReg_USE_OUTPUT_FIFO)
    /*******************************************************************************
    * Function Name: DeltaReg_ReadData
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
    uint32 DeltaReg_ReadData(void) 
    {
        return(CY_GET_REG32(DeltaReg_OUT_FIFO_VAL_LSB_PTR));
    }
#endif /* (0u != DeltaReg_USE_OUTPUT_FIFO) */


/*******************************************************************************
* Function Name: DeltaReg_ReadRegValue
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
uint32 DeltaReg_ReadRegValue(void) 
{
    uint32 result;

    /* Clear FIFO before software capture */
    while(DeltaReg_RET_FIFO_EMPTY != DeltaReg_GetFIFOStatus(DeltaReg_OUT_FIFO))
    {
        (void) CY_GET_REG32(DeltaReg_OUT_FIFO_VAL_LSB_PTR);
    }

    /* Read of 8 bits from A1 causes capture to output FIFO */
    (void) CY_GET_REG8(DeltaReg_SHIFT_REG_CAPTURE_PTR);

    /* Read output FIFO */
    result  = CY_GET_REG32(DeltaReg_OUT_FIFO_VAL_LSB_PTR);
    
    #if(0u != (DeltaReg_SR_SIZE % 8u))
        result &= ((uint32) DeltaReg_SR_MASK);
    #endif /* (0u != (DeltaReg_SR_SIZE % 8u)) */
    
    return(result);
}


/* [] END OF FILE */
