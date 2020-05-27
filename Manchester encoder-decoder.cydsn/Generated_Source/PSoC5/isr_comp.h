/*******************************************************************************
* File Name: isr_comp.h
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
#if !defined(CY_ISR_isr_comp_H)
#define CY_ISR_isr_comp_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isr_comp_Start(void);
void isr_comp_StartEx(cyisraddress address);
void isr_comp_Stop(void);

CY_ISR_PROTO(isr_comp_Interrupt);

void isr_comp_SetVector(cyisraddress address);
cyisraddress isr_comp_GetVector(void);

void isr_comp_SetPriority(uint8 priority);
uint8 isr_comp_GetPriority(void);

void isr_comp_Enable(void);
uint8 isr_comp_GetState(void);
void isr_comp_Disable(void);

void isr_comp_SetPending(void);
void isr_comp_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isr_comp ISR. */
#define isr_comp_INTC_VECTOR            ((reg32 *) isr_comp__INTC_VECT)

/* Address of the isr_comp ISR priority. */
#define isr_comp_INTC_PRIOR             ((reg8 *) isr_comp__INTC_PRIOR_REG)

/* Priority of the isr_comp interrupt. */
#define isr_comp_INTC_PRIOR_NUMBER      isr_comp__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isr_comp interrupt. */
#define isr_comp_INTC_SET_EN            ((reg32 *) isr_comp__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isr_comp interrupt. */
#define isr_comp_INTC_CLR_EN            ((reg32 *) isr_comp__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isr_comp interrupt state to pending. */
#define isr_comp_INTC_SET_PD            ((reg32 *) isr_comp__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isr_comp interrupt. */
#define isr_comp_INTC_CLR_PD            ((reg32 *) isr_comp__INTC_CLR_PD_REG)


#endif /* CY_ISR_isr_comp_H */


/* [] END OF FILE */
