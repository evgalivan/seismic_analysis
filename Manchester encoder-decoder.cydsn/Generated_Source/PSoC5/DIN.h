/*******************************************************************************
* File Name: DIN.h  
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

#if !defined(CY_PINS_DIN_H) /* Pins DIN_H */
#define CY_PINS_DIN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DIN_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DIN__PORT == 15 && ((DIN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DIN_Write(uint8 value);
void    DIN_SetDriveMode(uint8 mode);
uint8   DIN_ReadDataReg(void);
uint8   DIN_Read(void);
void    DIN_SetInterruptMode(uint16 position, uint16 mode);
uint8   DIN_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DIN_SetDriveMode() function.
     *  @{
     */
        #define DIN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DIN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DIN_DM_RES_UP          PIN_DM_RES_UP
        #define DIN_DM_RES_DWN         PIN_DM_RES_DWN
        #define DIN_DM_OD_LO           PIN_DM_OD_LO
        #define DIN_DM_OD_HI           PIN_DM_OD_HI
        #define DIN_DM_STRONG          PIN_DM_STRONG
        #define DIN_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DIN_MASK               DIN__MASK
#define DIN_SHIFT              DIN__SHIFT
#define DIN_WIDTH              1u

/* Interrupt constants */
#if defined(DIN__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DIN_SetInterruptMode() function.
     *  @{
     */
        #define DIN_INTR_NONE      (uint16)(0x0000u)
        #define DIN_INTR_RISING    (uint16)(0x0001u)
        #define DIN_INTR_FALLING   (uint16)(0x0002u)
        #define DIN_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DIN_INTR_MASK      (0x01u) 
#endif /* (DIN__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DIN_PS                     (* (reg8 *) DIN__PS)
/* Data Register */
#define DIN_DR                     (* (reg8 *) DIN__DR)
/* Port Number */
#define DIN_PRT_NUM                (* (reg8 *) DIN__PRT) 
/* Connect to Analog Globals */                                                  
#define DIN_AG                     (* (reg8 *) DIN__AG)                       
/* Analog MUX bux enable */
#define DIN_AMUX                   (* (reg8 *) DIN__AMUX) 
/* Bidirectional Enable */                                                        
#define DIN_BIE                    (* (reg8 *) DIN__BIE)
/* Bit-mask for Aliased Register Access */
#define DIN_BIT_MASK               (* (reg8 *) DIN__BIT_MASK)
/* Bypass Enable */
#define DIN_BYP                    (* (reg8 *) DIN__BYP)
/* Port wide control signals */                                                   
#define DIN_CTL                    (* (reg8 *) DIN__CTL)
/* Drive Modes */
#define DIN_DM0                    (* (reg8 *) DIN__DM0) 
#define DIN_DM1                    (* (reg8 *) DIN__DM1)
#define DIN_DM2                    (* (reg8 *) DIN__DM2) 
/* Input Buffer Disable Override */
#define DIN_INP_DIS                (* (reg8 *) DIN__INP_DIS)
/* LCD Common or Segment Drive */
#define DIN_LCD_COM_SEG            (* (reg8 *) DIN__LCD_COM_SEG)
/* Enable Segment LCD */
#define DIN_LCD_EN                 (* (reg8 *) DIN__LCD_EN)
/* Slew Rate Control */
#define DIN_SLW                    (* (reg8 *) DIN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DIN_PRTDSI__CAPS_SEL       (* (reg8 *) DIN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DIN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DIN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DIN_PRTDSI__OE_SEL0        (* (reg8 *) DIN__PRTDSI__OE_SEL0) 
#define DIN_PRTDSI__OE_SEL1        (* (reg8 *) DIN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DIN_PRTDSI__OUT_SEL0       (* (reg8 *) DIN__PRTDSI__OUT_SEL0) 
#define DIN_PRTDSI__OUT_SEL1       (* (reg8 *) DIN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DIN_PRTDSI__SYNC_OUT       (* (reg8 *) DIN__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DIN__SIO_CFG)
    #define DIN_SIO_HYST_EN        (* (reg8 *) DIN__SIO_HYST_EN)
    #define DIN_SIO_REG_HIFREQ     (* (reg8 *) DIN__SIO_REG_HIFREQ)
    #define DIN_SIO_CFG            (* (reg8 *) DIN__SIO_CFG)
    #define DIN_SIO_DIFF           (* (reg8 *) DIN__SIO_DIFF)
#endif /* (DIN__SIO_CFG) */

/* Interrupt Registers */
#if defined(DIN__INTSTAT)
    #define DIN_INTSTAT            (* (reg8 *) DIN__INTSTAT)
    #define DIN_SNAP               (* (reg8 *) DIN__SNAP)
    
	#define DIN_0_INTTYPE_REG 		(* (reg8 *) DIN__0__INTTYPE)
#endif /* (DIN__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DIN_H */


/* [] END OF FILE */
