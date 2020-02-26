/*******************************************************************************
* File Name: SigmaReg.c
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

#include "SigmaReg.h"

uint8 SigmaReg_initVar = 0u;


/*******************************************************************************
* Function Name: SigmaReg_Start
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
*  SigmaReg_initVar - used to check initial configuration, modified on
*  first function call.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SigmaReg_Start(void) 
{
    if(0u == SigmaReg_initVar)
    {
        SigmaReg_Init();
        SigmaReg_initVar = 1u; /* Component initialized */
    }

    SigmaReg_Enable();
}


/*******************************************************************************
* Function Name: SigmaReg_Enable
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
void SigmaReg_Enable(void) 
{
    /* Changing address in Datapath Control Store
       from NOP to component state machine commands space */
    SigmaReg_SR_CONTROL |= SigmaReg_CLK_EN;

    SigmaReg_EnableInt();
}


/*******************************************************************************
* Function Name: SigmaReg_Init
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
void SigmaReg_Init(void) 
{
    SigmaReg_SetIntMode(SigmaReg_INT_SRC);
}


/*******************************************************************************
* Function Name: SigmaReg_Stop
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
void SigmaReg_Stop(void) 
{
    /*changing Datapath Control Store address to NOP space*/
    SigmaReg_SR_CONTROL &= ((uint8) ~SigmaReg_CLK_EN);
    SigmaReg_DisableInt();
}


/*******************************************************************************
* Function Name: SigmaReg_EnableInt
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
void SigmaReg_EnableInt(void) 
{
    uint8 interruptState;

    interruptState = CyEnterCriticalSection();
    SigmaReg_SR_AUX_CONTROL |= SigmaReg_INTERRUPTS_ENABLE;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: SigmaReg_DisableInt
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
void SigmaReg_DisableInt(void) 
{
    uint8 interruptState;

    interruptState = CyEnterCriticalSection();
    SigmaReg_SR_AUX_CONTROL &= ((uint8) ~SigmaReg_INTERRUPTS_ENABLE);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: SigmaReg_GetFIFOStatus
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
uint8 SigmaReg_GetFIFOStatus(uint8 fifoId) 
{
    uint8 result;

    result = SigmaReg_RET_FIFO_NOT_DEFINED;

    #if(0u != SigmaReg_USE_INPUT_FIFO)
        if(SigmaReg_IN_FIFO == fifoId)
        {
            switch(SigmaReg_GET_IN_FIFO_STS)
            {
                case SigmaReg_IN_FIFO_FULL :
                    result = SigmaReg_RET_FIFO_FULL;
                    break;

                case SigmaReg_IN_FIFO_EMPTY :
                    result = SigmaReg_RET_FIFO_EMPTY;
                    break;

                case SigmaReg_IN_FIFO_PARTIAL:
                    result = SigmaReg_RET_FIFO_PARTIAL;
                    break;
                    
                default:
                    /* Initial result value, while 
                       IN_FIFO_EMPTY case is false 
                     */
                    result = SigmaReg_RET_FIFO_EMPTY;
                    break;
            }   
        }
    #endif /* (0u != SigmaReg_USE_INPUT_FIFO) */

    if(SigmaReg_OUT_FIFO == fifoId)
    {
        switch(SigmaReg_GET_OUT_FIFO_STS)
        {
            case SigmaReg_OUT_FIFO_FULL :
                result = SigmaReg_RET_FIFO_FULL;
                break;

            case SigmaReg_OUT_FIFO_EMPTY :
                result = SigmaReg_RET_FIFO_EMPTY;
                break;

            case SigmaReg_OUT_FIFO_PARTIAL :
                result = SigmaReg_RET_FIFO_PARTIAL;
                break;

            default:
                /* Initial result value, while 
                   OUT_FIFO_FULL case is false 
                 */
                result = SigmaReg_RET_FIFO_FULL;
                break;
        }
    }

    return(result);
}


/*******************************************************************************
* Function Name: SigmaReg_SetIntMode
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
void SigmaReg_SetIntMode(uint8 interruptSource) 
{
    SigmaReg_SR_STATUS_MASK &= ((uint8) ~SigmaReg_INTS_EN_MASK);          /* Clear existing int */
    SigmaReg_SR_STATUS_MASK |= (interruptSource & SigmaReg_INTS_EN_MASK); /* Set int */
}


/*******************************************************************************
* Function Name: SigmaReg_GetIntStatus
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
uint8 SigmaReg_GetIntStatus(void) 
{
    return(SigmaReg_SR_STATUS & SigmaReg_INTS_EN_MASK);
}


/*******************************************************************************
* Function Name: SigmaReg_WriteRegValue
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
void SigmaReg_WriteRegValue(uint32 shiftData)
                                                                     
{
    CY_SET_REG32(SigmaReg_SHIFT_REG_LSB_PTR, shiftData);
}


#if(0u != SigmaReg_USE_INPUT_FIFO)
    /*******************************************************************************
    * Function Name: SigmaReg_WriteData
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
    cystatus SigmaReg_WriteData(uint32 shiftData)
                                                                         
    {
        cystatus result;

        result = CYRET_INVALID_STATE;

        /* Writes data into the input FIFO if it is not FULL */
        if(SigmaReg_RET_FIFO_FULL != (SigmaReg_GetFIFOStatus(SigmaReg_IN_FIFO)))
        {
            CY_SET_REG32(SigmaReg_IN_FIFO_VAL_LSB_PTR, shiftData);
            result = CYRET_SUCCESS;
        }

        return(result);
    }
#endif /* (0u != SigmaReg_USE_INPUT_FIFO) */


#if(0u != SigmaReg_USE_OUTPUT_FIFO)
    /*******************************************************************************
    * Function Name: SigmaReg_ReadData
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
    uint32 SigmaReg_ReadData(void) 
    {
        return(CY_GET_REG32(SigmaReg_OUT_FIFO_VAL_LSB_PTR));
    }
#endif /* (0u != SigmaReg_USE_OUTPUT_FIFO) */


/*******************************************************************************
* Function Name: SigmaReg_ReadRegValue
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
uint32 SigmaReg_ReadRegValue(void) 
{
    uint32 result;

    /* Clear FIFO before software capture */
    while(SigmaReg_RET_FIFO_EMPTY != SigmaReg_GetFIFOStatus(SigmaReg_OUT_FIFO))
    {
        (void) CY_GET_REG32(SigmaReg_OUT_FIFO_VAL_LSB_PTR);
    }

    /* Read of 8 bits from A1 causes capture to output FIFO */
    (void) CY_GET_REG8(SigmaReg_SHIFT_REG_CAPTURE_PTR);

    /* Read output FIFO */
    result  = CY_GET_REG32(SigmaReg_OUT_FIFO_VAL_LSB_PTR);
    
    #if(0u != (SigmaReg_SR_SIZE % 8u))
        result &= ((uint32) SigmaReg_SR_MASK);
    #endif /* (0u != (SigmaReg_SR_SIZE % 8u)) */
    
    return(result);
}


/* [] END OF FILE */
