/*******************************************************************************
* File Name: Start_frame.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Start_frame_H) /* Pins Start_frame_H */
#define CY_PINS_Start_frame_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Start_frame_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Start_frame__PORT == 15 && ((Start_frame__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Start_frame_Write(uint8 value);
void    Start_frame_SetDriveMode(uint8 mode);
uint8   Start_frame_ReadDataReg(void);
uint8   Start_frame_Read(void);
void    Start_frame_SetInterruptMode(uint16 position, uint16 mode);
uint8   Start_frame_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Start_frame_SetDriveMode() function.
     *  @{
     */
        #define Start_frame_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Start_frame_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Start_frame_DM_RES_UP          PIN_DM_RES_UP
        #define Start_frame_DM_RES_DWN         PIN_DM_RES_DWN
        #define Start_frame_DM_OD_LO           PIN_DM_OD_LO
        #define Start_frame_DM_OD_HI           PIN_DM_OD_HI
        #define Start_frame_DM_STRONG          PIN_DM_STRONG
        #define Start_frame_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Start_frame_MASK               Start_frame__MASK
#define Start_frame_SHIFT              Start_frame__SHIFT
#define Start_frame_WIDTH              1u

/* Interrupt constants */
#if defined(Start_frame__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Start_frame_SetInterruptMode() function.
     *  @{
     */
        #define Start_frame_INTR_NONE      (uint16)(0x0000u)
        #define Start_frame_INTR_RISING    (uint16)(0x0001u)
        #define Start_frame_INTR_FALLING   (uint16)(0x0002u)
        #define Start_frame_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Start_frame_INTR_MASK      (0x01u) 
#endif /* (Start_frame__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Start_frame_PS                     (* (reg8 *) Start_frame__PS)
/* Data Register */
#define Start_frame_DR                     (* (reg8 *) Start_frame__DR)
/* Port Number */
#define Start_frame_PRT_NUM                (* (reg8 *) Start_frame__PRT) 
/* Connect to Analog Globals */                                                  
#define Start_frame_AG                     (* (reg8 *) Start_frame__AG)                       
/* Analog MUX bux enable */
#define Start_frame_AMUX                   (* (reg8 *) Start_frame__AMUX) 
/* Bidirectional Enable */                                                        
#define Start_frame_BIE                    (* (reg8 *) Start_frame__BIE)
/* Bit-mask for Aliased Register Access */
#define Start_frame_BIT_MASK               (* (reg8 *) Start_frame__BIT_MASK)
/* Bypass Enable */
#define Start_frame_BYP                    (* (reg8 *) Start_frame__BYP)
/* Port wide control signals */                                                   
#define Start_frame_CTL                    (* (reg8 *) Start_frame__CTL)
/* Drive Modes */
#define Start_frame_DM0                    (* (reg8 *) Start_frame__DM0) 
#define Start_frame_DM1                    (* (reg8 *) Start_frame__DM1)
#define Start_frame_DM2                    (* (reg8 *) Start_frame__DM2) 
/* Input Buffer Disable Override */
#define Start_frame_INP_DIS                (* (reg8 *) Start_frame__INP_DIS)
/* LCD Common or Segment Drive */
#define Start_frame_LCD_COM_SEG            (* (reg8 *) Start_frame__LCD_COM_SEG)
/* Enable Segment LCD */
#define Start_frame_LCD_EN                 (* (reg8 *) Start_frame__LCD_EN)
/* Slew Rate Control */
#define Start_frame_SLW                    (* (reg8 *) Start_frame__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Start_frame_PRTDSI__CAPS_SEL       (* (reg8 *) Start_frame__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Start_frame_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Start_frame__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Start_frame_PRTDSI__OE_SEL0        (* (reg8 *) Start_frame__PRTDSI__OE_SEL0) 
#define Start_frame_PRTDSI__OE_SEL1        (* (reg8 *) Start_frame__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Start_frame_PRTDSI__OUT_SEL0       (* (reg8 *) Start_frame__PRTDSI__OUT_SEL0) 
#define Start_frame_PRTDSI__OUT_SEL1       (* (reg8 *) Start_frame__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Start_frame_PRTDSI__SYNC_OUT       (* (reg8 *) Start_frame__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Start_frame__SIO_CFG)
    #define Start_frame_SIO_HYST_EN        (* (reg8 *) Start_frame__SIO_HYST_EN)
    #define Start_frame_SIO_REG_HIFREQ     (* (reg8 *) Start_frame__SIO_REG_HIFREQ)
    #define Start_frame_SIO_CFG            (* (reg8 *) Start_frame__SIO_CFG)
    #define Start_frame_SIO_DIFF           (* (reg8 *) Start_frame__SIO_DIFF)
#endif /* (Start_frame__SIO_CFG) */

/* Interrupt Registers */
#if defined(Start_frame__INTSTAT)
    #define Start_frame_INTSTAT            (* (reg8 *) Start_frame__INTSTAT)
    #define Start_frame_SNAP               (* (reg8 *) Start_frame__SNAP)
    
	#define Start_frame_0_INTTYPE_REG 		(* (reg8 *) Start_frame__0__INTTYPE)
#endif /* (Start_frame__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Start_frame_H */


/* [] END OF FILE */
