/*******************************************************************************
* File Name: CAPT_MID.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware to read the value of a Status 
*  Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "CAPT_MID.h"

#if !defined(CAPT_MID_sts_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: CAPT_MID_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The current value in the Status Register.
*
*******************************************************************************/
uint8 CAPT_MID_Read(void) 
{ 
    return CAPT_MID_Status;
}


/*******************************************************************************
* Function Name: CAPT_MID_InterruptEnable
********************************************************************************
*
* Summary:
*  Enables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void CAPT_MID_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    CAPT_MID_Status_Aux_Ctrl |= CAPT_MID_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: CAPT_MID_InterruptDisable
********************************************************************************
*
* Summary:
*  Disables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void CAPT_MID_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    CAPT_MID_Status_Aux_Ctrl &= (uint8)(~CAPT_MID_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: CAPT_MID_WriteMask
********************************************************************************
*
* Summary:
*  Writes the current mask value assigned to the Status Register.
*
* Parameters:
*  mask:  Value to write into the mask register.
*
* Return:
*  None.
*
*******************************************************************************/
void CAPT_MID_WriteMask(uint8 mask) 
{
    #if(CAPT_MID_INPUTS < 8u)
    	mask &= ((uint8)(1u << CAPT_MID_INPUTS) - 1u);
	#endif /* End CAPT_MID_INPUTS < 8u */
    CAPT_MID_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: CAPT_MID_ReadMask
********************************************************************************
*
* Summary:
*  Reads the current interrupt mask assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The value of the interrupt mask of the Status Register.
*
*******************************************************************************/
uint8 CAPT_MID_ReadMask(void) 
{
    return CAPT_MID_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
