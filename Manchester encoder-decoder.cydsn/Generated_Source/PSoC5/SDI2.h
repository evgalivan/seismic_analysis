/*******************************************************************************
* File Name: SDI2.h  
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

#if !defined(CY_PINS_SDI2_H) /* Pins SDI2_H */
#define CY_PINS_SDI2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SDI2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SDI2__PORT == 15 && ((SDI2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SDI2_Write(uint8 value);
void    SDI2_SetDriveMode(uint8 mode);
uint8   SDI2_ReadDataReg(void);
uint8   SDI2_Read(void);
void    SDI2_SetInterruptMode(uint16 position, uint16 mode);
uint8   SDI2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SDI2_SetDriveMode() function.
     *  @{
     */
        #define SDI2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SDI2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SDI2_DM_RES_UP          PIN_DM_RES_UP
        #define SDI2_DM_RES_DWN         PIN_DM_RES_DWN
        #define SDI2_DM_OD_LO           PIN_DM_OD_LO
        #define SDI2_DM_OD_HI           PIN_DM_OD_HI
        #define SDI2_DM_STRONG          PIN_DM_STRONG
        #define SDI2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SDI2_MASK               SDI2__MASK
#define SDI2_SHIFT              SDI2__SHIFT
#define SDI2_WIDTH              1u

/* Interrupt constants */
#if defined(SDI2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SDI2_SetInterruptMode() function.
     *  @{
     */
        #define SDI2_INTR_NONE      (uint16)(0x0000u)
        #define SDI2_INTR_RISING    (uint16)(0x0001u)
        #define SDI2_INTR_FALLING   (uint16)(0x0002u)
        #define SDI2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SDI2_INTR_MASK      (0x01u) 
#endif /* (SDI2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SDI2_PS                     (* (reg8 *) SDI2__PS)
/* Data Register */
#define SDI2_DR                     (* (reg8 *) SDI2__DR)
/* Port Number */
#define SDI2_PRT_NUM                (* (reg8 *) SDI2__PRT) 
/* Connect to Analog Globals */                                                  
#define SDI2_AG                     (* (reg8 *) SDI2__AG)                       
/* Analog MUX bux enable */
#define SDI2_AMUX                   (* (reg8 *) SDI2__AMUX) 
/* Bidirectional Enable */                                                        
#define SDI2_BIE                    (* (reg8 *) SDI2__BIE)
/* Bit-mask for Aliased Register Access */
#define SDI2_BIT_MASK               (* (reg8 *) SDI2__BIT_MASK)
/* Bypass Enable */
#define SDI2_BYP                    (* (reg8 *) SDI2__BYP)
/* Port wide control signals */                                                   
#define SDI2_CTL                    (* (reg8 *) SDI2__CTL)
/* Drive Modes */
#define SDI2_DM0                    (* (reg8 *) SDI2__DM0) 
#define SDI2_DM1                    (* (reg8 *) SDI2__DM1)
#define SDI2_DM2                    (* (reg8 *) SDI2__DM2) 
/* Input Buffer Disable Override */
#define SDI2_INP_DIS                (* (reg8 *) SDI2__INP_DIS)
/* LCD Common or Segment Drive */
#define SDI2_LCD_COM_SEG            (* (reg8 *) SDI2__LCD_COM_SEG)
/* Enable Segment LCD */
#define SDI2_LCD_EN                 (* (reg8 *) SDI2__LCD_EN)
/* Slew Rate Control */
#define SDI2_SLW                    (* (reg8 *) SDI2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SDI2_PRTDSI__CAPS_SEL       (* (reg8 *) SDI2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SDI2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SDI2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SDI2_PRTDSI__OE_SEL0        (* (reg8 *) SDI2__PRTDSI__OE_SEL0) 
#define SDI2_PRTDSI__OE_SEL1        (* (reg8 *) SDI2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SDI2_PRTDSI__OUT_SEL0       (* (reg8 *) SDI2__PRTDSI__OUT_SEL0) 
#define SDI2_PRTDSI__OUT_SEL1       (* (reg8 *) SDI2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SDI2_PRTDSI__SYNC_OUT       (* (reg8 *) SDI2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SDI2__SIO_CFG)
    #define SDI2_SIO_HYST_EN        (* (reg8 *) SDI2__SIO_HYST_EN)
    #define SDI2_SIO_REG_HIFREQ     (* (reg8 *) SDI2__SIO_REG_HIFREQ)
    #define SDI2_SIO_CFG            (* (reg8 *) SDI2__SIO_CFG)
    #define SDI2_SIO_DIFF           (* (reg8 *) SDI2__SIO_DIFF)
#endif /* (SDI2__SIO_CFG) */

/* Interrupt Registers */
#if defined(SDI2__INTSTAT)
    #define SDI2_INTSTAT            (* (reg8 *) SDI2__INTSTAT)
    #define SDI2_SNAP               (* (reg8 *) SDI2__SNAP)
    
	#define SDI2_0_INTTYPE_REG 		(* (reg8 *) SDI2__0__INTTYPE)
#endif /* (SDI2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SDI2_H */


/* [] END OF FILE */
