/*******************************************************************************
* File Name: TC_word.h  
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

#if !defined(CY_PINS_TC_word_H) /* Pins TC_word_H */
#define CY_PINS_TC_word_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "TC_word_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 TC_word__PORT == 15 && ((TC_word__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    TC_word_Write(uint8 value);
void    TC_word_SetDriveMode(uint8 mode);
uint8   TC_word_ReadDataReg(void);
uint8   TC_word_Read(void);
void    TC_word_SetInterruptMode(uint16 position, uint16 mode);
uint8   TC_word_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the TC_word_SetDriveMode() function.
     *  @{
     */
        #define TC_word_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define TC_word_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define TC_word_DM_RES_UP          PIN_DM_RES_UP
        #define TC_word_DM_RES_DWN         PIN_DM_RES_DWN
        #define TC_word_DM_OD_LO           PIN_DM_OD_LO
        #define TC_word_DM_OD_HI           PIN_DM_OD_HI
        #define TC_word_DM_STRONG          PIN_DM_STRONG
        #define TC_word_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define TC_word_MASK               TC_word__MASK
#define TC_word_SHIFT              TC_word__SHIFT
#define TC_word_WIDTH              1u

/* Interrupt constants */
#if defined(TC_word__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in TC_word_SetInterruptMode() function.
     *  @{
     */
        #define TC_word_INTR_NONE      (uint16)(0x0000u)
        #define TC_word_INTR_RISING    (uint16)(0x0001u)
        #define TC_word_INTR_FALLING   (uint16)(0x0002u)
        #define TC_word_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define TC_word_INTR_MASK      (0x01u) 
#endif /* (TC_word__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TC_word_PS                     (* (reg8 *) TC_word__PS)
/* Data Register */
#define TC_word_DR                     (* (reg8 *) TC_word__DR)
/* Port Number */
#define TC_word_PRT_NUM                (* (reg8 *) TC_word__PRT) 
/* Connect to Analog Globals */                                                  
#define TC_word_AG                     (* (reg8 *) TC_word__AG)                       
/* Analog MUX bux enable */
#define TC_word_AMUX                   (* (reg8 *) TC_word__AMUX) 
/* Bidirectional Enable */                                                        
#define TC_word_BIE                    (* (reg8 *) TC_word__BIE)
/* Bit-mask for Aliased Register Access */
#define TC_word_BIT_MASK               (* (reg8 *) TC_word__BIT_MASK)
/* Bypass Enable */
#define TC_word_BYP                    (* (reg8 *) TC_word__BYP)
/* Port wide control signals */                                                   
#define TC_word_CTL                    (* (reg8 *) TC_word__CTL)
/* Drive Modes */
#define TC_word_DM0                    (* (reg8 *) TC_word__DM0) 
#define TC_word_DM1                    (* (reg8 *) TC_word__DM1)
#define TC_word_DM2                    (* (reg8 *) TC_word__DM2) 
/* Input Buffer Disable Override */
#define TC_word_INP_DIS                (* (reg8 *) TC_word__INP_DIS)
/* LCD Common or Segment Drive */
#define TC_word_LCD_COM_SEG            (* (reg8 *) TC_word__LCD_COM_SEG)
/* Enable Segment LCD */
#define TC_word_LCD_EN                 (* (reg8 *) TC_word__LCD_EN)
/* Slew Rate Control */
#define TC_word_SLW                    (* (reg8 *) TC_word__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define TC_word_PRTDSI__CAPS_SEL       (* (reg8 *) TC_word__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define TC_word_PRTDSI__DBL_SYNC_IN    (* (reg8 *) TC_word__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define TC_word_PRTDSI__OE_SEL0        (* (reg8 *) TC_word__PRTDSI__OE_SEL0) 
#define TC_word_PRTDSI__OE_SEL1        (* (reg8 *) TC_word__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define TC_word_PRTDSI__OUT_SEL0       (* (reg8 *) TC_word__PRTDSI__OUT_SEL0) 
#define TC_word_PRTDSI__OUT_SEL1       (* (reg8 *) TC_word__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define TC_word_PRTDSI__SYNC_OUT       (* (reg8 *) TC_word__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(TC_word__SIO_CFG)
    #define TC_word_SIO_HYST_EN        (* (reg8 *) TC_word__SIO_HYST_EN)
    #define TC_word_SIO_REG_HIFREQ     (* (reg8 *) TC_word__SIO_REG_HIFREQ)
    #define TC_word_SIO_CFG            (* (reg8 *) TC_word__SIO_CFG)
    #define TC_word_SIO_DIFF           (* (reg8 *) TC_word__SIO_DIFF)
#endif /* (TC_word__SIO_CFG) */

/* Interrupt Registers */
#if defined(TC_word__INTSTAT)
    #define TC_word_INTSTAT            (* (reg8 *) TC_word__INTSTAT)
    #define TC_word_SNAP               (* (reg8 *) TC_word__SNAP)
    
	#define TC_word_0_INTTYPE_REG 		(* (reg8 *) TC_word__0__INTTYPE)
#endif /* (TC_word__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_TC_word_H */


/* [] END OF FILE */
