/*******************************************************************************
* File Name: SDO2.h  
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

#if !defined(CY_PINS_SDO2_H) /* Pins SDO2_H */
#define CY_PINS_SDO2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SDO2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SDO2__PORT == 15 && ((SDO2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SDO2_Write(uint8 value);
void    SDO2_SetDriveMode(uint8 mode);
uint8   SDO2_ReadDataReg(void);
uint8   SDO2_Read(void);
void    SDO2_SetInterruptMode(uint16 position, uint16 mode);
uint8   SDO2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SDO2_SetDriveMode() function.
     *  @{
     */
        #define SDO2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SDO2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SDO2_DM_RES_UP          PIN_DM_RES_UP
        #define SDO2_DM_RES_DWN         PIN_DM_RES_DWN
        #define SDO2_DM_OD_LO           PIN_DM_OD_LO
        #define SDO2_DM_OD_HI           PIN_DM_OD_HI
        #define SDO2_DM_STRONG          PIN_DM_STRONG
        #define SDO2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SDO2_MASK               SDO2__MASK
#define SDO2_SHIFT              SDO2__SHIFT
#define SDO2_WIDTH              1u

/* Interrupt constants */
#if defined(SDO2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SDO2_SetInterruptMode() function.
     *  @{
     */
        #define SDO2_INTR_NONE      (uint16)(0x0000u)
        #define SDO2_INTR_RISING    (uint16)(0x0001u)
        #define SDO2_INTR_FALLING   (uint16)(0x0002u)
        #define SDO2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SDO2_INTR_MASK      (0x01u) 
#endif /* (SDO2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SDO2_PS                     (* (reg8 *) SDO2__PS)
/* Data Register */
#define SDO2_DR                     (* (reg8 *) SDO2__DR)
/* Port Number */
#define SDO2_PRT_NUM                (* (reg8 *) SDO2__PRT) 
/* Connect to Analog Globals */                                                  
#define SDO2_AG                     (* (reg8 *) SDO2__AG)                       
/* Analog MUX bux enable */
#define SDO2_AMUX                   (* (reg8 *) SDO2__AMUX) 
/* Bidirectional Enable */                                                        
#define SDO2_BIE                    (* (reg8 *) SDO2__BIE)
/* Bit-mask for Aliased Register Access */
#define SDO2_BIT_MASK               (* (reg8 *) SDO2__BIT_MASK)
/* Bypass Enable */
#define SDO2_BYP                    (* (reg8 *) SDO2__BYP)
/* Port wide control signals */                                                   
#define SDO2_CTL                    (* (reg8 *) SDO2__CTL)
/* Drive Modes */
#define SDO2_DM0                    (* (reg8 *) SDO2__DM0) 
#define SDO2_DM1                    (* (reg8 *) SDO2__DM1)
#define SDO2_DM2                    (* (reg8 *) SDO2__DM2) 
/* Input Buffer Disable Override */
#define SDO2_INP_DIS                (* (reg8 *) SDO2__INP_DIS)
/* LCD Common or Segment Drive */
#define SDO2_LCD_COM_SEG            (* (reg8 *) SDO2__LCD_COM_SEG)
/* Enable Segment LCD */
#define SDO2_LCD_EN                 (* (reg8 *) SDO2__LCD_EN)
/* Slew Rate Control */
#define SDO2_SLW                    (* (reg8 *) SDO2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SDO2_PRTDSI__CAPS_SEL       (* (reg8 *) SDO2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SDO2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SDO2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SDO2_PRTDSI__OE_SEL0        (* (reg8 *) SDO2__PRTDSI__OE_SEL0) 
#define SDO2_PRTDSI__OE_SEL1        (* (reg8 *) SDO2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SDO2_PRTDSI__OUT_SEL0       (* (reg8 *) SDO2__PRTDSI__OUT_SEL0) 
#define SDO2_PRTDSI__OUT_SEL1       (* (reg8 *) SDO2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SDO2_PRTDSI__SYNC_OUT       (* (reg8 *) SDO2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SDO2__SIO_CFG)
    #define SDO2_SIO_HYST_EN        (* (reg8 *) SDO2__SIO_HYST_EN)
    #define SDO2_SIO_REG_HIFREQ     (* (reg8 *) SDO2__SIO_REG_HIFREQ)
    #define SDO2_SIO_CFG            (* (reg8 *) SDO2__SIO_CFG)
    #define SDO2_SIO_DIFF           (* (reg8 *) SDO2__SIO_DIFF)
#endif /* (SDO2__SIO_CFG) */

/* Interrupt Registers */
#if defined(SDO2__INTSTAT)
    #define SDO2_INTSTAT            (* (reg8 *) SDO2__INTSTAT)
    #define SDO2_SNAP               (* (reg8 *) SDO2__SNAP)
    
	#define SDO2_0_INTTYPE_REG 		(* (reg8 *) SDO2__0__INTTYPE)
#endif /* (SDO2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SDO2_H */


/* [] END OF FILE */
