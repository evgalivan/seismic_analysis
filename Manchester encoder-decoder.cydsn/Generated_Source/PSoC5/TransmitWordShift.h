/*******************************************************************************
* File Name: TransmitWordShift.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_TransmitWordShift_H)
#define CY_ISR_TransmitWordShift_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void TransmitWordShift_Start(void);
void TransmitWordShift_StartEx(cyisraddress address);
void TransmitWordShift_Stop(void);

CY_ISR_PROTO(TransmitWordShift_Interrupt);

void TransmitWordShift_SetVector(cyisraddress address);
cyisraddress TransmitWordShift_GetVector(void);

void TransmitWordShift_SetPriority(uint8 priority);
uint8 TransmitWordShift_GetPriority(void);

void TransmitWordShift_Enable(void);
uint8 TransmitWordShift_GetState(void);
void TransmitWordShift_Disable(void);

void TransmitWordShift_SetPending(void);
void TransmitWordShift_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the TransmitWordShift ISR. */
#define TransmitWordShift_INTC_VECTOR            ((reg32 *) TransmitWordShift__INTC_VECT)

/* Address of the TransmitWordShift ISR priority. */
#define TransmitWordShift_INTC_PRIOR             ((reg8 *) TransmitWordShift__INTC_PRIOR_REG)

/* Priority of the TransmitWordShift interrupt. */
#define TransmitWordShift_INTC_PRIOR_NUMBER      TransmitWordShift__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable TransmitWordShift interrupt. */
#define TransmitWordShift_INTC_SET_EN            ((reg32 *) TransmitWordShift__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the TransmitWordShift interrupt. */
#define TransmitWordShift_INTC_CLR_EN            ((reg32 *) TransmitWordShift__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the TransmitWordShift interrupt state to pending. */
#define TransmitWordShift_INTC_SET_PD            ((reg32 *) TransmitWordShift__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the TransmitWordShift interrupt. */
#define TransmitWordShift_INTC_CLR_PD            ((reg32 *) TransmitWordShift__INTC_CLR_PD_REG)


#endif /* CY_ISR_TransmitWordShift_H */


/* [] END OF FILE */
