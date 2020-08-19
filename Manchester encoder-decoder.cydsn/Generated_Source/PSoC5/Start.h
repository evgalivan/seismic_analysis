/*******************************************************************************
* File Name: START.h  
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

#if !defined(CY_PINS_START_H) /* Pins START_H */
#define CY_PINS_START_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "START_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 START__PORT == 15 && ((START__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    START_Write(uint8 value);
void    START_SetDriveMode(uint8 mode);
uint8   START_ReadDataReg(void);
uint8   START_Read(void);
void    START_SetInterruptMode(uint16 position, uint16 mode);
uint8   START_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the START_SetDriveMode() function.
     *  @{
     */
        #define START_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define START_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define START_DM_RES_UP          PIN_DM_RES_UP
        #define START_DM_RES_DWN         PIN_DM_RES_DWN
        #define START_DM_OD_LO           PIN_DM_OD_LO
        #define START_DM_OD_HI           PIN_DM_OD_HI
        #define START_DM_STRONG          PIN_DM_STRONG
        #define START_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define START_MASK               START__MASK
#define START_SHIFT              START__SHIFT
#define START_WIDTH              1u

/* Interrupt constants */
#if defined(START__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in START_SetInterruptMode() function.
     *  @{
     */
        #define START_INTR_NONE      (uint16)(0x0000u)
        #define START_INTR_RISING    (uint16)(0x0001u)
        #define START_INTR_FALLING   (uint16)(0x0002u)
        #define START_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define START_INTR_MASK      (0x01u) 
#endif /* (START__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define START_PS                     (* (reg8 *) START__PS)
/* Data Register */
#define START_DR                     (* (reg8 *) START__DR)
/* Port Number */
#define START_PRT_NUM                (* (reg8 *) START__PRT) 
/* Connect to Analog Globals */                                                  
#define START_AG                     (* (reg8 *) START__AG)                       
/* Analog MUX bux enable */
#define START_AMUX                   (* (reg8 *) START__AMUX) 
/* Bidirectional Enable */                                                        
#define START_BIE                    (* (reg8 *) START__BIE)
/* Bit-mask for Aliased Register Access */
#define START_BIT_MASK               (* (reg8 *) START__BIT_MASK)
/* Bypass Enable */
#define START_BYP                    (* (reg8 *) START__BYP)
/* Port wide control signals */                                                   
#define START_CTL                    (* (reg8 *) START__CTL)
/* Drive Modes */
#define START_DM0                    (* (reg8 *) START__DM0) 
#define START_DM1                    (* (reg8 *) START__DM1)
#define START_DM2                    (* (reg8 *) START__DM2) 
/* Input Buffer Disable Override */
#define START_INP_DIS                (* (reg8 *) START__INP_DIS)
/* LCD Common or Segment Drive */
#define START_LCD_COM_SEG            (* (reg8 *) START__LCD_COM_SEG)
/* Enable Segment LCD */
#define START_LCD_EN                 (* (reg8 *) START__LCD_EN)
/* Slew Rate Control */
#define START_SLW                    (* (reg8 *) START__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define START_PRTDSI__CAPS_SEL       (* (reg8 *) START__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define START_PRTDSI__DBL_SYNC_IN    (* (reg8 *) START__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define START_PRTDSI__OE_SEL0        (* (reg8 *) START__PRTDSI__OE_SEL0) 
#define START_PRTDSI__OE_SEL1        (* (reg8 *) START__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define START_PRTDSI__OUT_SEL0       (* (reg8 *) START__PRTDSI__OUT_SEL0) 
#define START_PRTDSI__OUT_SEL1       (* (reg8 *) START__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define START_PRTDSI__SYNC_OUT       (* (reg8 *) START__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(START__SIO_CFG)
    #define START_SIO_HYST_EN        (* (reg8 *) START__SIO_HYST_EN)
    #define START_SIO_REG_HIFREQ     (* (reg8 *) START__SIO_REG_HIFREQ)
    #define START_SIO_CFG            (* (reg8 *) START__SIO_CFG)
    #define START_SIO_DIFF           (* (reg8 *) START__SIO_DIFF)
#endif /* (START__SIO_CFG) */

/* Interrupt Registers */
#if defined(START__INTSTAT)
    #define START_INTSTAT            (* (reg8 *) START__INTSTAT)
    #define START_SNAP               (* (reg8 *) START__SNAP)
    
	#define START_0_INTTYPE_REG 		(* (reg8 *) START__0__INTTYPE)
#endif /* (START__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_START_H */


/* [] END OF FILE */
