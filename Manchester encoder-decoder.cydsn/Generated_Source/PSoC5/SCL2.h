/*******************************************************************************
* File Name: SCL2.h  
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

#if !defined(CY_PINS_SCL2_H) /* Pins SCL2_H */
#define CY_PINS_SCL2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SCL2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SCL2__PORT == 15 && ((SCL2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SCL2_Write(uint8 value);
void    SCL2_SetDriveMode(uint8 mode);
uint8   SCL2_ReadDataReg(void);
uint8   SCL2_Read(void);
void    SCL2_SetInterruptMode(uint16 position, uint16 mode);
uint8   SCL2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SCL2_SetDriveMode() function.
     *  @{
     */
        #define SCL2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SCL2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SCL2_DM_RES_UP          PIN_DM_RES_UP
        #define SCL2_DM_RES_DWN         PIN_DM_RES_DWN
        #define SCL2_DM_OD_LO           PIN_DM_OD_LO
        #define SCL2_DM_OD_HI           PIN_DM_OD_HI
        #define SCL2_DM_STRONG          PIN_DM_STRONG
        #define SCL2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SCL2_MASK               SCL2__MASK
#define SCL2_SHIFT              SCL2__SHIFT
#define SCL2_WIDTH              1u

/* Interrupt constants */
#if defined(SCL2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SCL2_SetInterruptMode() function.
     *  @{
     */
        #define SCL2_INTR_NONE      (uint16)(0x0000u)
        #define SCL2_INTR_RISING    (uint16)(0x0001u)
        #define SCL2_INTR_FALLING   (uint16)(0x0002u)
        #define SCL2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SCL2_INTR_MASK      (0x01u) 
#endif /* (SCL2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SCL2_PS                     (* (reg8 *) SCL2__PS)
/* Data Register */
#define SCL2_DR                     (* (reg8 *) SCL2__DR)
/* Port Number */
#define SCL2_PRT_NUM                (* (reg8 *) SCL2__PRT) 
/* Connect to Analog Globals */                                                  
#define SCL2_AG                     (* (reg8 *) SCL2__AG)                       
/* Analog MUX bux enable */
#define SCL2_AMUX                   (* (reg8 *) SCL2__AMUX) 
/* Bidirectional Enable */                                                        
#define SCL2_BIE                    (* (reg8 *) SCL2__BIE)
/* Bit-mask for Aliased Register Access */
#define SCL2_BIT_MASK               (* (reg8 *) SCL2__BIT_MASK)
/* Bypass Enable */
#define SCL2_BYP                    (* (reg8 *) SCL2__BYP)
/* Port wide control signals */                                                   
#define SCL2_CTL                    (* (reg8 *) SCL2__CTL)
/* Drive Modes */
#define SCL2_DM0                    (* (reg8 *) SCL2__DM0) 
#define SCL2_DM1                    (* (reg8 *) SCL2__DM1)
#define SCL2_DM2                    (* (reg8 *) SCL2__DM2) 
/* Input Buffer Disable Override */
#define SCL2_INP_DIS                (* (reg8 *) SCL2__INP_DIS)
/* LCD Common or Segment Drive */
#define SCL2_LCD_COM_SEG            (* (reg8 *) SCL2__LCD_COM_SEG)
/* Enable Segment LCD */
#define SCL2_LCD_EN                 (* (reg8 *) SCL2__LCD_EN)
/* Slew Rate Control */
#define SCL2_SLW                    (* (reg8 *) SCL2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SCL2_PRTDSI__CAPS_SEL       (* (reg8 *) SCL2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SCL2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SCL2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SCL2_PRTDSI__OE_SEL0        (* (reg8 *) SCL2__PRTDSI__OE_SEL0) 
#define SCL2_PRTDSI__OE_SEL1        (* (reg8 *) SCL2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SCL2_PRTDSI__OUT_SEL0       (* (reg8 *) SCL2__PRTDSI__OUT_SEL0) 
#define SCL2_PRTDSI__OUT_SEL1       (* (reg8 *) SCL2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SCL2_PRTDSI__SYNC_OUT       (* (reg8 *) SCL2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SCL2__SIO_CFG)
    #define SCL2_SIO_HYST_EN        (* (reg8 *) SCL2__SIO_HYST_EN)
    #define SCL2_SIO_REG_HIFREQ     (* (reg8 *) SCL2__SIO_REG_HIFREQ)
    #define SCL2_SIO_CFG            (* (reg8 *) SCL2__SIO_CFG)
    #define SCL2_SIO_DIFF           (* (reg8 *) SCL2__SIO_DIFF)
#endif /* (SCL2__SIO_CFG) */

/* Interrupt Registers */
#if defined(SCL2__INTSTAT)
    #define SCL2_INTSTAT            (* (reg8 *) SCL2__INTSTAT)
    #define SCL2_SNAP               (* (reg8 *) SCL2__SNAP)
    
	#define SCL2_0_INTTYPE_REG 		(* (reg8 *) SCL2__0__INTTYPE)
#endif /* (SCL2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SCL2_H */


/* [] END OF FILE */
