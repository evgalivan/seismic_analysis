/*******************************************************************************
* File Name: TransmitOver.h
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
#if !defined(CY_ISR_TransmitOver_H)
#define CY_ISR_TransmitOver_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void TransmitOver_Start(void);
void TransmitOver_StartEx(cyisraddress address);
void TransmitOver_Stop(void);

CY_ISR_PROTO(TransmitOver_Interrupt);

void TransmitOver_SetVector(cyisraddress address);
cyisraddress TransmitOver_GetVector(void);

void TransmitOver_SetPriority(uint8 priority);
uint8 TransmitOver_GetPriority(void);

void TransmitOver_Enable(void);
uint8 TransmitOver_GetState(void);
void TransmitOver_Disable(void);

void TransmitOver_SetPending(void);
void TransmitOver_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the TransmitOver ISR. */
#define TransmitOver_INTC_VECTOR            ((reg32 *) TransmitOver__INTC_VECT)

/* Address of the TransmitOver ISR priority. */
#define TransmitOver_INTC_PRIOR             ((reg8 *) TransmitOver__INTC_PRIOR_REG)

/* Priority of the TransmitOver interrupt. */
#define TransmitOver_INTC_PRIOR_NUMBER      TransmitOver__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable TransmitOver interrupt. */
#define TransmitOver_INTC_SET_EN            ((reg32 *) TransmitOver__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the TransmitOver interrupt. */
#define TransmitOver_INTC_CLR_EN            ((reg32 *) TransmitOver__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the TransmitOver interrupt state to pending. */
#define TransmitOver_INTC_SET_PD            ((reg32 *) TransmitOver__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the TransmitOver interrupt. */
#define TransmitOver_INTC_CLR_PD            ((reg32 *) TransmitOver__INTC_CLR_PD_REG)


#endif /* CY_ISR_TransmitOver_H */


/* [] END OF FILE */
