/*******************************************************************************
* File Name: Start_frame.h  
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

#if !defined(CY_PINS_Start_frame_ALIASES_H) /* Pins Start_frame_ALIASES_H */
#define CY_PINS_Start_frame_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Start_frame_0			(Start_frame__0__PC)
#define Start_frame_0_INTR	((uint16)((uint16)0x0001u << Start_frame__0__SHIFT))

#define Start_frame_INTR_ALL	 ((uint16)(Start_frame_0_INTR))

#endif /* End Pins Start_frame_ALIASES_H */


/* [] END OF FILE */
