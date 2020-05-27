/*******************************************************************************
* File Name: bit_overload.h  
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

#if !defined(CY_PINS_bit_overload_H) /* Pins bit_overload_H */
#define CY_PINS_bit_overload_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "bit_overload_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 bit_overload__PORT == 15 && ((bit_overload__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    bit_overload_Write(uint8 value);
void    bit_overload_SetDriveMode(uint8 mode);
uint8   bit_overload_ReadDataReg(void);
uint8   bit_overload_Read(void);
void    bit_overload_SetInterruptMode(uint16 position, uint16 mode);
uint8   bit_overload_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the bit_overload_SetDriveMode() function.
     *  @{
     */
        #define bit_overload_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define bit_overload_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define bit_overload_DM_RES_UP          PIN_DM_RES_UP
        #define bit_overload_DM_RES_DWN         PIN_DM_RES_DWN
        #define bit_overload_DM_OD_LO           PIN_DM_OD_LO
        #define bit_overload_DM_OD_HI           PIN_DM_OD_HI
        #define bit_overload_DM_STRONG          PIN_DM_STRONG
        #define bit_overload_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define bit_overload_MASK               bit_overload__MASK
#define bit_overload_SHIFT              bit_overload__SHIFT
#define bit_overload_WIDTH              1u

/* Interrupt constants */
#if defined(bit_overload__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in bit_overload_SetInterruptMode() function.
     *  @{
     */
        #define bit_overload_INTR_NONE      (uint16)(0x0000u)
        #define bit_overload_INTR_RISING    (uint16)(0x0001u)
        #define bit_overload_INTR_FALLING   (uint16)(0x0002u)
        #define bit_overload_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define bit_overload_INTR_MASK      (0x01u) 
#endif /* (bit_overload__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define bit_overload_PS                     (* (reg8 *) bit_overload__PS)
/* Data Register */
#define bit_overload_DR                     (* (reg8 *) bit_overload__DR)
/* Port Number */
#define bit_overload_PRT_NUM                (* (reg8 *) bit_overload__PRT) 
/* Connect to Analog Globals */                                                  
#define bit_overload_AG                     (* (reg8 *) bit_overload__AG)                       
/* Analog MUX bux enable */
#define bit_overload_AMUX                   (* (reg8 *) bit_overload__AMUX) 
/* Bidirectional Enable */                                                        
#define bit_overload_BIE                    (* (reg8 *) bit_overload__BIE)
/* Bit-mask for Aliased Register Access */
#define bit_overload_BIT_MASK               (* (reg8 *) bit_overload__BIT_MASK)
/* Bypass Enable */
#define bit_overload_BYP                    (* (reg8 *) bit_overload__BYP)
/* Port wide control signals */                                                   
#define bit_overload_CTL                    (* (reg8 *) bit_overload__CTL)
/* Drive Modes */
#define bit_overload_DM0                    (* (reg8 *) bit_overload__DM0) 
#define bit_overload_DM1                    (* (reg8 *) bit_overload__DM1)
#define bit_overload_DM2                    (* (reg8 *) bit_overload__DM2) 
/* Input Buffer Disable Override */
#define bit_overload_INP_DIS                (* (reg8 *) bit_overload__INP_DIS)
/* LCD Common or Segment Drive */
#define bit_overload_LCD_COM_SEG            (* (reg8 *) bit_overload__LCD_COM_SEG)
/* Enable Segment LCD */
#define bit_overload_LCD_EN                 (* (reg8 *) bit_overload__LCD_EN)
/* Slew Rate Control */
#define bit_overload_SLW                    (* (reg8 *) bit_overload__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define bit_overload_PRTDSI__CAPS_SEL       (* (reg8 *) bit_overload__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define bit_overload_PRTDSI__DBL_SYNC_IN    (* (reg8 *) bit_overload__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define bit_overload_PRTDSI__OE_SEL0        (* (reg8 *) bit_overload__PRTDSI__OE_SEL0) 
#define bit_overload_PRTDSI__OE_SEL1        (* (reg8 *) bit_overload__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define bit_overload_PRTDSI__OUT_SEL0       (* (reg8 *) bit_overload__PRTDSI__OUT_SEL0) 
#define bit_overload_PRTDSI__OUT_SEL1       (* (reg8 *) bit_overload__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define bit_overload_PRTDSI__SYNC_OUT       (* (reg8 *) bit_overload__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(bit_overload__SIO_CFG)
    #define bit_overload_SIO_HYST_EN        (* (reg8 *) bit_overload__SIO_HYST_EN)
    #define bit_overload_SIO_REG_HIFREQ     (* (reg8 *) bit_overload__SIO_REG_HIFREQ)
    #define bit_overload_SIO_CFG            (* (reg8 *) bit_overload__SIO_CFG)
    #define bit_overload_SIO_DIFF           (* (reg8 *) bit_overload__SIO_DIFF)
#endif /* (bit_overload__SIO_CFG) */

/* Interrupt Registers */
#if defined(bit_overload__INTSTAT)
    #define bit_overload_INTSTAT            (* (reg8 *) bit_overload__INTSTAT)
    #define bit_overload_SNAP               (* (reg8 *) bit_overload__SNAP)
    
	#define bit_overload_0_INTTYPE_REG 		(* (reg8 *) bit_overload__0__INTTYPE)
#endif /* (bit_overload__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_bit_overload_H */


/* [] END OF FILE */
