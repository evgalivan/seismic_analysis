/*******************************************************************************
* File Name: PPS.h  
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

#if !defined(CY_PINS_PPS_H) /* Pins PPS_H */
#define CY_PINS_PPS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PPS_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PPS__PORT == 15 && ((PPS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PPS_Write(uint8 value);
void    PPS_SetDriveMode(uint8 mode);
uint8   PPS_ReadDataReg(void);
uint8   PPS_Read(void);
void    PPS_SetInterruptMode(uint16 position, uint16 mode);
uint8   PPS_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PPS_SetDriveMode() function.
     *  @{
     */
        #define PPS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PPS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PPS_DM_RES_UP          PIN_DM_RES_UP
        #define PPS_DM_RES_DWN         PIN_DM_RES_DWN
        #define PPS_DM_OD_LO           PIN_DM_OD_LO
        #define PPS_DM_OD_HI           PIN_DM_OD_HI
        #define PPS_DM_STRONG          PIN_DM_STRONG
        #define PPS_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PPS_MASK               PPS__MASK
#define PPS_SHIFT              PPS__SHIFT
#define PPS_WIDTH              1u

/* Interrupt constants */
#if defined(PPS__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PPS_SetInterruptMode() function.
     *  @{
     */
        #define PPS_INTR_NONE      (uint16)(0x0000u)
        #define PPS_INTR_RISING    (uint16)(0x0001u)
        #define PPS_INTR_FALLING   (uint16)(0x0002u)
        #define PPS_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PPS_INTR_MASK      (0x01u) 
#endif /* (PPS__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PPS_PS                     (* (reg8 *) PPS__PS)
/* Data Register */
#define PPS_DR                     (* (reg8 *) PPS__DR)
/* Port Number */
#define PPS_PRT_NUM                (* (reg8 *) PPS__PRT) 
/* Connect to Analog Globals */                                                  
#define PPS_AG                     (* (reg8 *) PPS__AG)                       
/* Analog MUX bux enable */
#define PPS_AMUX                   (* (reg8 *) PPS__AMUX) 
/* Bidirectional Enable */                                                        
#define PPS_BIE                    (* (reg8 *) PPS__BIE)
/* Bit-mask for Aliased Register Access */
#define PPS_BIT_MASK               (* (reg8 *) PPS__BIT_MASK)
/* Bypass Enable */
#define PPS_BYP                    (* (reg8 *) PPS__BYP)
/* Port wide control signals */                                                   
#define PPS_CTL                    (* (reg8 *) PPS__CTL)
/* Drive Modes */
#define PPS_DM0                    (* (reg8 *) PPS__DM0) 
#define PPS_DM1                    (* (reg8 *) PPS__DM1)
#define PPS_DM2                    (* (reg8 *) PPS__DM2) 
/* Input Buffer Disable Override */
#define PPS_INP_DIS                (* (reg8 *) PPS__INP_DIS)
/* LCD Common or Segment Drive */
#define PPS_LCD_COM_SEG            (* (reg8 *) PPS__LCD_COM_SEG)
/* Enable Segment LCD */
#define PPS_LCD_EN                 (* (reg8 *) PPS__LCD_EN)
/* Slew Rate Control */
#define PPS_SLW                    (* (reg8 *) PPS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PPS_PRTDSI__CAPS_SEL       (* (reg8 *) PPS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PPS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PPS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PPS_PRTDSI__OE_SEL0        (* (reg8 *) PPS__PRTDSI__OE_SEL0) 
#define PPS_PRTDSI__OE_SEL1        (* (reg8 *) PPS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PPS_PRTDSI__OUT_SEL0       (* (reg8 *) PPS__PRTDSI__OUT_SEL0) 
#define PPS_PRTDSI__OUT_SEL1       (* (reg8 *) PPS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PPS_PRTDSI__SYNC_OUT       (* (reg8 *) PPS__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PPS__SIO_CFG)
    #define PPS_SIO_HYST_EN        (* (reg8 *) PPS__SIO_HYST_EN)
    #define PPS_SIO_REG_HIFREQ     (* (reg8 *) PPS__SIO_REG_HIFREQ)
    #define PPS_SIO_CFG            (* (reg8 *) PPS__SIO_CFG)
    #define PPS_SIO_DIFF           (* (reg8 *) PPS__SIO_DIFF)
#endif /* (PPS__SIO_CFG) */

/* Interrupt Registers */
#if defined(PPS__INTSTAT)
    #define PPS_INTSTAT            (* (reg8 *) PPS__INTSTAT)
    #define PPS_SNAP               (* (reg8 *) PPS__SNAP)
    
	#define PPS_0_INTTYPE_REG 		(* (reg8 *) PPS__0__INTTYPE)
#endif /* (PPS__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PPS_H */


/* [] END OF FILE */
