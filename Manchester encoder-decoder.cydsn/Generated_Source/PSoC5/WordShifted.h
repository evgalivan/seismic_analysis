/*******************************************************************************
* File Name: WordShifted.h
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
#if !defined(CY_ISR_WordShifted_H)
#define CY_ISR_WordShifted_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void WordShifted_Start(void);
void WordShifted_StartEx(cyisraddress address);
void WordShifted_Stop(void);

CY_ISR_PROTO(WordShifted_Interrupt);

void WordShifted_SetVector(cyisraddress address);
cyisraddress WordShifted_GetVector(void);

void WordShifted_SetPriority(uint8 priority);
uint8 WordShifted_GetPriority(void);

void WordShifted_Enable(void);
uint8 WordShifted_GetState(void);
void WordShifted_Disable(void);

void WordShifted_SetPending(void);
void WordShifted_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the WordShifted ISR. */
#define WordShifted_INTC_VECTOR            ((reg32 *) WordShifted__INTC_VECT)

/* Address of the WordShifted ISR priority. */
#define WordShifted_INTC_PRIOR             ((reg8 *) WordShifted__INTC_PRIOR_REG)

/* Priority of the WordShifted interrupt. */
#define WordShifted_INTC_PRIOR_NUMBER      WordShifted__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable WordShifted interrupt. */
#define WordShifted_INTC_SET_EN            ((reg32 *) WordShifted__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the WordShifted interrupt. */
#define WordShifted_INTC_CLR_EN            ((reg32 *) WordShifted__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the WordShifted interrupt state to pending. */
#define WordShifted_INTC_SET_PD            ((reg32 *) WordShifted__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the WordShifted interrupt. */
#define WordShifted_INTC_CLR_PD            ((reg32 *) WordShifted__INTC_CLR_PD_REG)


#endif /* CY_ISR_WordShifted_H */


/* [] END OF FILE */
