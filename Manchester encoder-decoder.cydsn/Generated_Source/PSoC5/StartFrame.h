/*******************************************************************************
* File Name: StartFrame.h
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
#if !defined(CY_ISR_StartFrame_H)
#define CY_ISR_StartFrame_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void StartFrame_Start(void);
void StartFrame_StartEx(cyisraddress address);
void StartFrame_Stop(void);

CY_ISR_PROTO(StartFrame_Interrupt);

void StartFrame_SetVector(cyisraddress address);
cyisraddress StartFrame_GetVector(void);

void StartFrame_SetPriority(uint8 priority);
uint8 StartFrame_GetPriority(void);

void StartFrame_Enable(void);
uint8 StartFrame_GetState(void);
void StartFrame_Disable(void);

void StartFrame_SetPending(void);
void StartFrame_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the StartFrame ISR. */
#define StartFrame_INTC_VECTOR            ((reg32 *) StartFrame__INTC_VECT)

/* Address of the StartFrame ISR priority. */
#define StartFrame_INTC_PRIOR             ((reg8 *) StartFrame__INTC_PRIOR_REG)

/* Priority of the StartFrame interrupt. */
#define StartFrame_INTC_PRIOR_NUMBER      StartFrame__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable StartFrame interrupt. */
#define StartFrame_INTC_SET_EN            ((reg32 *) StartFrame__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the StartFrame interrupt. */
#define StartFrame_INTC_CLR_EN            ((reg32 *) StartFrame__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the StartFrame interrupt state to pending. */
#define StartFrame_INTC_SET_PD            ((reg32 *) StartFrame__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the StartFrame interrupt. */
#define StartFrame_INTC_CLR_PD            ((reg32 *) StartFrame__INTC_CLR_PD_REG)


#endif /* CY_ISR_StartFrame_H */


/* [] END OF FILE */
