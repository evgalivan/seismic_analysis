/*******************************************************************************
* File Name: capture.h
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
#if !defined(CY_ISR_capture_H)
#define CY_ISR_capture_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void capture_Start(void);
void capture_StartEx(cyisraddress address);
void capture_Stop(void);

CY_ISR_PROTO(capture_Interrupt);

void capture_SetVector(cyisraddress address);
cyisraddress capture_GetVector(void);

void capture_SetPriority(uint8 priority);
uint8 capture_GetPriority(void);

void capture_Enable(void);
uint8 capture_GetState(void);
void capture_Disable(void);

void capture_SetPending(void);
void capture_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the capture ISR. */
#define capture_INTC_VECTOR            ((reg32 *) capture__INTC_VECT)

/* Address of the capture ISR priority. */
#define capture_INTC_PRIOR             ((reg8 *) capture__INTC_PRIOR_REG)

/* Priority of the capture interrupt. */
#define capture_INTC_PRIOR_NUMBER      capture__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable capture interrupt. */
#define capture_INTC_SET_EN            ((reg32 *) capture__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the capture interrupt. */
#define capture_INTC_CLR_EN            ((reg32 *) capture__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the capture interrupt state to pending. */
#define capture_INTC_SET_PD            ((reg32 *) capture__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the capture interrupt. */
#define capture_INTC_CLR_PD            ((reg32 *) capture__INTC_CLR_PD_REG)


#endif /* CY_ISR_capture_H */


/* [] END OF FILE */
