/*******************************************************************************
* File Name: DInN.h  
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

#if !defined(CY_PINS_DInN_H) /* Pins DInN_H */
#define CY_PINS_DInN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DInN_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DInN__PORT == 15 && ((DInN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DInN_Write(uint8 value);
void    DInN_SetDriveMode(uint8 mode);
uint8   DInN_ReadDataReg(void);
uint8   DInN_Read(void);
void    DInN_SetInterruptMode(uint16 position, uint16 mode);
uint8   DInN_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DInN_SetDriveMode() function.
     *  @{
     */
        #define DInN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DInN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DInN_DM_RES_UP          PIN_DM_RES_UP
        #define DInN_DM_RES_DWN         PIN_DM_RES_DWN
        #define DInN_DM_OD_LO           PIN_DM_OD_LO
        #define DInN_DM_OD_HI           PIN_DM_OD_HI
        #define DInN_DM_STRONG          PIN_DM_STRONG
        #define DInN_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DInN_MASK               DInN__MASK
#define DInN_SHIFT              DInN__SHIFT
#define DInN_WIDTH              1u

/* Interrupt constants */
#if defined(DInN__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DInN_SetInterruptMode() function.
     *  @{
     */
        #define DInN_INTR_NONE      (uint16)(0x0000u)
        #define DInN_INTR_RISING    (uint16)(0x0001u)
        #define DInN_INTR_FALLING   (uint16)(0x0002u)
        #define DInN_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DInN_INTR_MASK      (0x01u) 
#endif /* (DInN__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DInN_PS                     (* (reg8 *) DInN__PS)
/* Data Register */
#define DInN_DR                     (* (reg8 *) DInN__DR)
/* Port Number */
#define DInN_PRT_NUM                (* (reg8 *) DInN__PRT) 
/* Connect to Analog Globals */                                                  
#define DInN_AG                     (* (reg8 *) DInN__AG)                       
/* Analog MUX bux enable */
#define DInN_AMUX                   (* (reg8 *) DInN__AMUX) 
/* Bidirectional Enable */                                                        
#define DInN_BIE                    (* (reg8 *) DInN__BIE)
/* Bit-mask for Aliased Register Access */
#define DInN_BIT_MASK               (* (reg8 *) DInN__BIT_MASK)
/* Bypass Enable */
#define DInN_BYP                    (* (reg8 *) DInN__BYP)
/* Port wide control signals */                                                   
#define DInN_CTL                    (* (reg8 *) DInN__CTL)
/* Drive Modes */
#define DInN_DM0                    (* (reg8 *) DInN__DM0) 
#define DInN_DM1                    (* (reg8 *) DInN__DM1)
#define DInN_DM2                    (* (reg8 *) DInN__DM2) 
/* Input Buffer Disable Override */
#define DInN_INP_DIS                (* (reg8 *) DInN__INP_DIS)
/* LCD Common or Segment Drive */
#define DInN_LCD_COM_SEG            (* (reg8 *) DInN__LCD_COM_SEG)
/* Enable Segment LCD */
#define DInN_LCD_EN                 (* (reg8 *) DInN__LCD_EN)
/* Slew Rate Control */
#define DInN_SLW                    (* (reg8 *) DInN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DInN_PRTDSI__CAPS_SEL       (* (reg8 *) DInN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DInN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DInN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DInN_PRTDSI__OE_SEL0        (* (reg8 *) DInN__PRTDSI__OE_SEL0) 
#define DInN_PRTDSI__OE_SEL1        (* (reg8 *) DInN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DInN_PRTDSI__OUT_SEL0       (* (reg8 *) DInN__PRTDSI__OUT_SEL0) 
#define DInN_PRTDSI__OUT_SEL1       (* (reg8 *) DInN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DInN_PRTDSI__SYNC_OUT       (* (reg8 *) DInN__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DInN__SIO_CFG)
    #define DInN_SIO_HYST_EN        (* (reg8 *) DInN__SIO_HYST_EN)
    #define DInN_SIO_REG_HIFREQ     (* (reg8 *) DInN__SIO_REG_HIFREQ)
    #define DInN_SIO_CFG            (* (reg8 *) DInN__SIO_CFG)
    #define DInN_SIO_DIFF           (* (reg8 *) DInN__SIO_DIFF)
#endif /* (DInN__SIO_CFG) */

/* Interrupt Registers */
#if defined(DInN__INTSTAT)
    #define DInN_INTSTAT            (* (reg8 *) DInN__INTSTAT)
    #define DInN_SNAP               (* (reg8 *) DInN__SNAP)
    
	#define DInN_0_INTTYPE_REG 		(* (reg8 *) DInN__0__INTTYPE)
#endif /* (DInN__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DInN_H */


/* [] END OF FILE */
