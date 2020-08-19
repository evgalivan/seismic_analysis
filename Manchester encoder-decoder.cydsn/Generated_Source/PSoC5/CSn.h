/*******************************************************************************
* File Name: CSn.h  
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

#if !defined(CY_PINS_CSn_H) /* Pins CSn_H */
#define CY_PINS_CSn_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CSn_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CSn__PORT == 15 && ((CSn__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    CSn_Write(uint8 value);
void    CSn_SetDriveMode(uint8 mode);
uint8   CSn_ReadDataReg(void);
uint8   CSn_Read(void);
void    CSn_SetInterruptMode(uint16 position, uint16 mode);
uint8   CSn_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the CSn_SetDriveMode() function.
     *  @{
     */
        #define CSn_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define CSn_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define CSn_DM_RES_UP          PIN_DM_RES_UP
        #define CSn_DM_RES_DWN         PIN_DM_RES_DWN
        #define CSn_DM_OD_LO           PIN_DM_OD_LO
        #define CSn_DM_OD_HI           PIN_DM_OD_HI
        #define CSn_DM_STRONG          PIN_DM_STRONG
        #define CSn_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define CSn_MASK               CSn__MASK
#define CSn_SHIFT              CSn__SHIFT
#define CSn_WIDTH              1u

/* Interrupt constants */
#if defined(CSn__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CSn_SetInterruptMode() function.
     *  @{
     */
        #define CSn_INTR_NONE      (uint16)(0x0000u)
        #define CSn_INTR_RISING    (uint16)(0x0001u)
        #define CSn_INTR_FALLING   (uint16)(0x0002u)
        #define CSn_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define CSn_INTR_MASK      (0x01u) 
#endif /* (CSn__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CSn_PS                     (* (reg8 *) CSn__PS)
/* Data Register */
#define CSn_DR                     (* (reg8 *) CSn__DR)
/* Port Number */
#define CSn_PRT_NUM                (* (reg8 *) CSn__PRT) 
/* Connect to Analog Globals */                                                  
#define CSn_AG                     (* (reg8 *) CSn__AG)                       
/* Analog MUX bux enable */
#define CSn_AMUX                   (* (reg8 *) CSn__AMUX) 
/* Bidirectional Enable */                                                        
#define CSn_BIE                    (* (reg8 *) CSn__BIE)
/* Bit-mask for Aliased Register Access */
#define CSn_BIT_MASK               (* (reg8 *) CSn__BIT_MASK)
/* Bypass Enable */
#define CSn_BYP                    (* (reg8 *) CSn__BYP)
/* Port wide control signals */                                                   
#define CSn_CTL                    (* (reg8 *) CSn__CTL)
/* Drive Modes */
#define CSn_DM0                    (* (reg8 *) CSn__DM0) 
#define CSn_DM1                    (* (reg8 *) CSn__DM1)
#define CSn_DM2                    (* (reg8 *) CSn__DM2) 
/* Input Buffer Disable Override */
#define CSn_INP_DIS                (* (reg8 *) CSn__INP_DIS)
/* LCD Common or Segment Drive */
#define CSn_LCD_COM_SEG            (* (reg8 *) CSn__LCD_COM_SEG)
/* Enable Segment LCD */
#define CSn_LCD_EN                 (* (reg8 *) CSn__LCD_EN)
/* Slew Rate Control */
#define CSn_SLW                    (* (reg8 *) CSn__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CSn_PRTDSI__CAPS_SEL       (* (reg8 *) CSn__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CSn_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CSn__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CSn_PRTDSI__OE_SEL0        (* (reg8 *) CSn__PRTDSI__OE_SEL0) 
#define CSn_PRTDSI__OE_SEL1        (* (reg8 *) CSn__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CSn_PRTDSI__OUT_SEL0       (* (reg8 *) CSn__PRTDSI__OUT_SEL0) 
#define CSn_PRTDSI__OUT_SEL1       (* (reg8 *) CSn__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CSn_PRTDSI__SYNC_OUT       (* (reg8 *) CSn__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(CSn__SIO_CFG)
    #define CSn_SIO_HYST_EN        (* (reg8 *) CSn__SIO_HYST_EN)
    #define CSn_SIO_REG_HIFREQ     (* (reg8 *) CSn__SIO_REG_HIFREQ)
    #define CSn_SIO_CFG            (* (reg8 *) CSn__SIO_CFG)
    #define CSn_SIO_DIFF           (* (reg8 *) CSn__SIO_DIFF)
#endif /* (CSn__SIO_CFG) */

/* Interrupt Registers */
#if defined(CSn__INTSTAT)
    #define CSn_INTSTAT            (* (reg8 *) CSn__INTSTAT)
    #define CSn_SNAP               (* (reg8 *) CSn__SNAP)
    
	#define CSn_0_INTTYPE_REG 		(* (reg8 *) CSn__0__INTTYPE)
#endif /* (CSn__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CSn_H */


/* [] END OF FILE */
