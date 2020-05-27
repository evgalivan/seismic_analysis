/*******************************************************************************
* File Name: tc_usec.h  
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

#if !defined(CY_PINS_tc_usec_H) /* Pins tc_usec_H */
#define CY_PINS_tc_usec_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "tc_usec_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 tc_usec__PORT == 15 && ((tc_usec__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    tc_usec_Write(uint8 value);
void    tc_usec_SetDriveMode(uint8 mode);
uint8   tc_usec_ReadDataReg(void);
uint8   tc_usec_Read(void);
void    tc_usec_SetInterruptMode(uint16 position, uint16 mode);
uint8   tc_usec_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the tc_usec_SetDriveMode() function.
     *  @{
     */
        #define tc_usec_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define tc_usec_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define tc_usec_DM_RES_UP          PIN_DM_RES_UP
        #define tc_usec_DM_RES_DWN         PIN_DM_RES_DWN
        #define tc_usec_DM_OD_LO           PIN_DM_OD_LO
        #define tc_usec_DM_OD_HI           PIN_DM_OD_HI
        #define tc_usec_DM_STRONG          PIN_DM_STRONG
        #define tc_usec_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define tc_usec_MASK               tc_usec__MASK
#define tc_usec_SHIFT              tc_usec__SHIFT
#define tc_usec_WIDTH              1u

/* Interrupt constants */
#if defined(tc_usec__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in tc_usec_SetInterruptMode() function.
     *  @{
     */
        #define tc_usec_INTR_NONE      (uint16)(0x0000u)
        #define tc_usec_INTR_RISING    (uint16)(0x0001u)
        #define tc_usec_INTR_FALLING   (uint16)(0x0002u)
        #define tc_usec_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define tc_usec_INTR_MASK      (0x01u) 
#endif /* (tc_usec__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define tc_usec_PS                     (* (reg8 *) tc_usec__PS)
/* Data Register */
#define tc_usec_DR                     (* (reg8 *) tc_usec__DR)
/* Port Number */
#define tc_usec_PRT_NUM                (* (reg8 *) tc_usec__PRT) 
/* Connect to Analog Globals */                                                  
#define tc_usec_AG                     (* (reg8 *) tc_usec__AG)                       
/* Analog MUX bux enable */
#define tc_usec_AMUX                   (* (reg8 *) tc_usec__AMUX) 
/* Bidirectional Enable */                                                        
#define tc_usec_BIE                    (* (reg8 *) tc_usec__BIE)
/* Bit-mask for Aliased Register Access */
#define tc_usec_BIT_MASK               (* (reg8 *) tc_usec__BIT_MASK)
/* Bypass Enable */
#define tc_usec_BYP                    (* (reg8 *) tc_usec__BYP)
/* Port wide control signals */                                                   
#define tc_usec_CTL                    (* (reg8 *) tc_usec__CTL)
/* Drive Modes */
#define tc_usec_DM0                    (* (reg8 *) tc_usec__DM0) 
#define tc_usec_DM1                    (* (reg8 *) tc_usec__DM1)
#define tc_usec_DM2                    (* (reg8 *) tc_usec__DM2) 
/* Input Buffer Disable Override */
#define tc_usec_INP_DIS                (* (reg8 *) tc_usec__INP_DIS)
/* LCD Common or Segment Drive */
#define tc_usec_LCD_COM_SEG            (* (reg8 *) tc_usec__LCD_COM_SEG)
/* Enable Segment LCD */
#define tc_usec_LCD_EN                 (* (reg8 *) tc_usec__LCD_EN)
/* Slew Rate Control */
#define tc_usec_SLW                    (* (reg8 *) tc_usec__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define tc_usec_PRTDSI__CAPS_SEL       (* (reg8 *) tc_usec__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define tc_usec_PRTDSI__DBL_SYNC_IN    (* (reg8 *) tc_usec__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define tc_usec_PRTDSI__OE_SEL0        (* (reg8 *) tc_usec__PRTDSI__OE_SEL0) 
#define tc_usec_PRTDSI__OE_SEL1        (* (reg8 *) tc_usec__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define tc_usec_PRTDSI__OUT_SEL0       (* (reg8 *) tc_usec__PRTDSI__OUT_SEL0) 
#define tc_usec_PRTDSI__OUT_SEL1       (* (reg8 *) tc_usec__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define tc_usec_PRTDSI__SYNC_OUT       (* (reg8 *) tc_usec__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(tc_usec__SIO_CFG)
    #define tc_usec_SIO_HYST_EN        (* (reg8 *) tc_usec__SIO_HYST_EN)
    #define tc_usec_SIO_REG_HIFREQ     (* (reg8 *) tc_usec__SIO_REG_HIFREQ)
    #define tc_usec_SIO_CFG            (* (reg8 *) tc_usec__SIO_CFG)
    #define tc_usec_SIO_DIFF           (* (reg8 *) tc_usec__SIO_DIFF)
#endif /* (tc_usec__SIO_CFG) */

/* Interrupt Registers */
#if defined(tc_usec__INTSTAT)
    #define tc_usec_INTSTAT            (* (reg8 *) tc_usec__INTSTAT)
    #define tc_usec_SNAP               (* (reg8 *) tc_usec__SNAP)
    
	#define tc_usec_0_INTTYPE_REG 		(* (reg8 *) tc_usec__0__INTTYPE)
#endif /* (tc_usec__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_tc_usec_H */


/* [] END OF FILE */
