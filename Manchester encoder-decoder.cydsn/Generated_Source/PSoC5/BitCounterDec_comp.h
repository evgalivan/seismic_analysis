/*******************************************************************************
* File Name: BitCounterDec_comp.h  
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

#if !defined(CY_PINS_BitCounterDec_comp_H) /* Pins BitCounterDec_comp_H */
#define CY_PINS_BitCounterDec_comp_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BitCounterDec_comp_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BitCounterDec_comp__PORT == 15 && ((BitCounterDec_comp__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    BitCounterDec_comp_Write(uint8 value);
void    BitCounterDec_comp_SetDriveMode(uint8 mode);
uint8   BitCounterDec_comp_ReadDataReg(void);
uint8   BitCounterDec_comp_Read(void);
void    BitCounterDec_comp_SetInterruptMode(uint16 position, uint16 mode);
uint8   BitCounterDec_comp_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the BitCounterDec_comp_SetDriveMode() function.
     *  @{
     */
        #define BitCounterDec_comp_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define BitCounterDec_comp_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define BitCounterDec_comp_DM_RES_UP          PIN_DM_RES_UP
        #define BitCounterDec_comp_DM_RES_DWN         PIN_DM_RES_DWN
        #define BitCounterDec_comp_DM_OD_LO           PIN_DM_OD_LO
        #define BitCounterDec_comp_DM_OD_HI           PIN_DM_OD_HI
        #define BitCounterDec_comp_DM_STRONG          PIN_DM_STRONG
        #define BitCounterDec_comp_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define BitCounterDec_comp_MASK               BitCounterDec_comp__MASK
#define BitCounterDec_comp_SHIFT              BitCounterDec_comp__SHIFT
#define BitCounterDec_comp_WIDTH              1u

/* Interrupt constants */
#if defined(BitCounterDec_comp__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BitCounterDec_comp_SetInterruptMode() function.
     *  @{
     */
        #define BitCounterDec_comp_INTR_NONE      (uint16)(0x0000u)
        #define BitCounterDec_comp_INTR_RISING    (uint16)(0x0001u)
        #define BitCounterDec_comp_INTR_FALLING   (uint16)(0x0002u)
        #define BitCounterDec_comp_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define BitCounterDec_comp_INTR_MASK      (0x01u) 
#endif /* (BitCounterDec_comp__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BitCounterDec_comp_PS                     (* (reg8 *) BitCounterDec_comp__PS)
/* Data Register */
#define BitCounterDec_comp_DR                     (* (reg8 *) BitCounterDec_comp__DR)
/* Port Number */
#define BitCounterDec_comp_PRT_NUM                (* (reg8 *) BitCounterDec_comp__PRT) 
/* Connect to Analog Globals */                                                  
#define BitCounterDec_comp_AG                     (* (reg8 *) BitCounterDec_comp__AG)                       
/* Analog MUX bux enable */
#define BitCounterDec_comp_AMUX                   (* (reg8 *) BitCounterDec_comp__AMUX) 
/* Bidirectional Enable */                                                        
#define BitCounterDec_comp_BIE                    (* (reg8 *) BitCounterDec_comp__BIE)
/* Bit-mask for Aliased Register Access */
#define BitCounterDec_comp_BIT_MASK               (* (reg8 *) BitCounterDec_comp__BIT_MASK)
/* Bypass Enable */
#define BitCounterDec_comp_BYP                    (* (reg8 *) BitCounterDec_comp__BYP)
/* Port wide control signals */                                                   
#define BitCounterDec_comp_CTL                    (* (reg8 *) BitCounterDec_comp__CTL)
/* Drive Modes */
#define BitCounterDec_comp_DM0                    (* (reg8 *) BitCounterDec_comp__DM0) 
#define BitCounterDec_comp_DM1                    (* (reg8 *) BitCounterDec_comp__DM1)
#define BitCounterDec_comp_DM2                    (* (reg8 *) BitCounterDec_comp__DM2) 
/* Input Buffer Disable Override */
#define BitCounterDec_comp_INP_DIS                (* (reg8 *) BitCounterDec_comp__INP_DIS)
/* LCD Common or Segment Drive */
#define BitCounterDec_comp_LCD_COM_SEG            (* (reg8 *) BitCounterDec_comp__LCD_COM_SEG)
/* Enable Segment LCD */
#define BitCounterDec_comp_LCD_EN                 (* (reg8 *) BitCounterDec_comp__LCD_EN)
/* Slew Rate Control */
#define BitCounterDec_comp_SLW                    (* (reg8 *) BitCounterDec_comp__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BitCounterDec_comp_PRTDSI__CAPS_SEL       (* (reg8 *) BitCounterDec_comp__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BitCounterDec_comp_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BitCounterDec_comp__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BitCounterDec_comp_PRTDSI__OE_SEL0        (* (reg8 *) BitCounterDec_comp__PRTDSI__OE_SEL0) 
#define BitCounterDec_comp_PRTDSI__OE_SEL1        (* (reg8 *) BitCounterDec_comp__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BitCounterDec_comp_PRTDSI__OUT_SEL0       (* (reg8 *) BitCounterDec_comp__PRTDSI__OUT_SEL0) 
#define BitCounterDec_comp_PRTDSI__OUT_SEL1       (* (reg8 *) BitCounterDec_comp__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BitCounterDec_comp_PRTDSI__SYNC_OUT       (* (reg8 *) BitCounterDec_comp__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(BitCounterDec_comp__SIO_CFG)
    #define BitCounterDec_comp_SIO_HYST_EN        (* (reg8 *) BitCounterDec_comp__SIO_HYST_EN)
    #define BitCounterDec_comp_SIO_REG_HIFREQ     (* (reg8 *) BitCounterDec_comp__SIO_REG_HIFREQ)
    #define BitCounterDec_comp_SIO_CFG            (* (reg8 *) BitCounterDec_comp__SIO_CFG)
    #define BitCounterDec_comp_SIO_DIFF           (* (reg8 *) BitCounterDec_comp__SIO_DIFF)
#endif /* (BitCounterDec_comp__SIO_CFG) */

/* Interrupt Registers */
#if defined(BitCounterDec_comp__INTSTAT)
    #define BitCounterDec_comp_INTSTAT            (* (reg8 *) BitCounterDec_comp__INTSTAT)
    #define BitCounterDec_comp_SNAP               (* (reg8 *) BitCounterDec_comp__SNAP)
    
	#define BitCounterDec_comp_0_INTTYPE_REG 		(* (reg8 *) BitCounterDec_comp__0__INTTYPE)
#endif /* (BitCounterDec_comp__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BitCounterDec_comp_H */


/* [] END OF FILE */
