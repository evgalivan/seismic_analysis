/*******************************************************************************
* File Name: EndFrame.h
* Version 1.71
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
#if !defined(CY_ISR_EndFrame_H)
#define CY_ISR_EndFrame_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void EndFrame_Start(void);
void EndFrame_StartEx(cyisraddress address);
void EndFrame_Stop(void);

CY_ISR_PROTO(EndFrame_Interrupt);

void EndFrame_SetVector(cyisraddress address);
cyisraddress EndFrame_GetVector(void);

void EndFrame_SetPriority(uint8 priority);
uint8 EndFrame_GetPriority(void);

void EndFrame_Enable(void);
uint8 EndFrame_GetState(void);
void EndFrame_Disable(void);

void EndFrame_SetPending(void);
void EndFrame_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the EndFrame ISR. */
#define EndFrame_INTC_VECTOR            ((reg32 *) EndFrame__INTC_VECT)

/* Address of the EndFrame ISR priority. */
#define EndFrame_INTC_PRIOR             ((reg8 *) EndFrame__INTC_PRIOR_REG)

/* Priority of the EndFrame interrupt. */
#define EndFrame_INTC_PRIOR_NUMBER      EndFrame__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable EndFrame interrupt. */
#define EndFrame_INTC_SET_EN            ((reg32 *) EndFrame__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the EndFrame interrupt. */
#define EndFrame_INTC_CLR_EN            ((reg32 *) EndFrame__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the EndFrame interrupt state to pending. */
#define EndFrame_INTC_SET_PD            ((reg32 *) EndFrame__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the EndFrame interrupt. */
#define EndFrame_INTC_CLR_PD            ((reg32 *) EndFrame__INTC_CLR_PD_REG)


#endif /* CY_ISR_EndFrame_H */


/* [] END OF FILE */
