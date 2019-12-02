/*******************************************************************************
* File Name: Sh_isr.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Sh_isr_ALIASES_H) /* Pins Sh_isr_ALIASES_H */
#define CY_PINS_Sh_isr_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Sh_isr_0			(Sh_isr__0__PC)
#define Sh_isr_0_INTR	((uint16)((uint16)0x0001u << Sh_isr__0__SHIFT))

#define Sh_isr_INTR_ALL	 ((uint16)(Sh_isr_0_INTR))

#endif /* End Pins Sh_isr_ALIASES_H */


/* [] END OF FILE */
