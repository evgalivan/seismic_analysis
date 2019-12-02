/*******************************************************************************
* File Name: Sh_isr.h  
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

#if !defined(CY_PINS_Sh_isr_H) /* Pins Sh_isr_H */
#define CY_PINS_Sh_isr_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Sh_isr_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Sh_isr__PORT == 15 && ((Sh_isr__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Sh_isr_Write(uint8 value);
void    Sh_isr_SetDriveMode(uint8 mode);
uint8   Sh_isr_ReadDataReg(void);
uint8   Sh_isr_Read(void);
void    Sh_isr_SetInterruptMode(uint16 position, uint16 mode);
uint8   Sh_isr_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Sh_isr_SetDriveMode() function.
     *  @{
     */
        #define Sh_isr_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Sh_isr_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Sh_isr_DM_RES_UP          PIN_DM_RES_UP
        #define Sh_isr_DM_RES_DWN         PIN_DM_RES_DWN
        #define Sh_isr_DM_OD_LO           PIN_DM_OD_LO
        #define Sh_isr_DM_OD_HI           PIN_DM_OD_HI
        #define Sh_isr_DM_STRONG          PIN_DM_STRONG
        #define Sh_isr_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Sh_isr_MASK               Sh_isr__MASK
#define Sh_isr_SHIFT              Sh_isr__SHIFT
#define Sh_isr_WIDTH              1u

/* Interrupt constants */
#if defined(Sh_isr__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Sh_isr_SetInterruptMode() function.
     *  @{
     */
        #define Sh_isr_INTR_NONE      (uint16)(0x0000u)
        #define Sh_isr_INTR_RISING    (uint16)(0x0001u)
        #define Sh_isr_INTR_FALLING   (uint16)(0x0002u)
        #define Sh_isr_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Sh_isr_INTR_MASK      (0x01u) 
#endif /* (Sh_isr__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Sh_isr_PS                     (* (reg8 *) Sh_isr__PS)
/* Data Register */
#define Sh_isr_DR                     (* (reg8 *) Sh_isr__DR)
/* Port Number */
#define Sh_isr_PRT_NUM                (* (reg8 *) Sh_isr__PRT) 
/* Connect to Analog Globals */                                                  
#define Sh_isr_AG                     (* (reg8 *) Sh_isr__AG)                       
/* Analog MUX bux enable */
#define Sh_isr_AMUX                   (* (reg8 *) Sh_isr__AMUX) 
/* Bidirectional Enable */                                                        
#define Sh_isr_BIE                    (* (reg8 *) Sh_isr__BIE)
/* Bit-mask for Aliased Register Access */
#define Sh_isr_BIT_MASK               (* (reg8 *) Sh_isr__BIT_MASK)
/* Bypass Enable */
#define Sh_isr_BYP                    (* (reg8 *) Sh_isr__BYP)
/* Port wide control signals */                                                   
#define Sh_isr_CTL                    (* (reg8 *) Sh_isr__CTL)
/* Drive Modes */
#define Sh_isr_DM0                    (* (reg8 *) Sh_isr__DM0) 
#define Sh_isr_DM1                    (* (reg8 *) Sh_isr__DM1)
#define Sh_isr_DM2                    (* (reg8 *) Sh_isr__DM2) 
/* Input Buffer Disable Override */
#define Sh_isr_INP_DIS                (* (reg8 *) Sh_isr__INP_DIS)
/* LCD Common or Segment Drive */
#define Sh_isr_LCD_COM_SEG            (* (reg8 *) Sh_isr__LCD_COM_SEG)
/* Enable Segment LCD */
#define Sh_isr_LCD_EN                 (* (reg8 *) Sh_isr__LCD_EN)
/* Slew Rate Control */
#define Sh_isr_SLW                    (* (reg8 *) Sh_isr__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Sh_isr_PRTDSI__CAPS_SEL       (* (reg8 *) Sh_isr__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Sh_isr_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Sh_isr__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Sh_isr_PRTDSI__OE_SEL0        (* (reg8 *) Sh_isr__PRTDSI__OE_SEL0) 
#define Sh_isr_PRTDSI__OE_SEL1        (* (reg8 *) Sh_isr__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Sh_isr_PRTDSI__OUT_SEL0       (* (reg8 *) Sh_isr__PRTDSI__OUT_SEL0) 
#define Sh_isr_PRTDSI__OUT_SEL1       (* (reg8 *) Sh_isr__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Sh_isr_PRTDSI__SYNC_OUT       (* (reg8 *) Sh_isr__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Sh_isr__SIO_CFG)
    #define Sh_isr_SIO_HYST_EN        (* (reg8 *) Sh_isr__SIO_HYST_EN)
    #define Sh_isr_SIO_REG_HIFREQ     (* (reg8 *) Sh_isr__SIO_REG_HIFREQ)
    #define Sh_isr_SIO_CFG            (* (reg8 *) Sh_isr__SIO_CFG)
    #define Sh_isr_SIO_DIFF           (* (reg8 *) Sh_isr__SIO_DIFF)
#endif /* (Sh_isr__SIO_CFG) */

/* Interrupt Registers */
#if defined(Sh_isr__INTSTAT)
    #define Sh_isr_INTSTAT            (* (reg8 *) Sh_isr__INTSTAT)
    #define Sh_isr_SNAP               (* (reg8 *) Sh_isr__SNAP)
    
	#define Sh_isr_0_INTTYPE_REG 		(* (reg8 *) Sh_isr__0__INTTYPE)
#endif /* (Sh_isr__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Sh_isr_H */


/* [] END OF FILE */
