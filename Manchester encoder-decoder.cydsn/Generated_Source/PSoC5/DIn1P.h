/*******************************************************************************
* File Name: DIn1P.h  
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

#if !defined(CY_PINS_DIn1P_H) /* Pins DIn1P_H */
#define CY_PINS_DIn1P_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DIn1P_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DIn1P__PORT == 15 && ((DIn1P__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DIn1P_Write(uint8 value);
void    DIn1P_SetDriveMode(uint8 mode);
uint8   DIn1P_ReadDataReg(void);
uint8   DIn1P_Read(void);
void    DIn1P_SetInterruptMode(uint16 position, uint16 mode);
uint8   DIn1P_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DIn1P_SetDriveMode() function.
     *  @{
     */
        #define DIn1P_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DIn1P_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DIn1P_DM_RES_UP          PIN_DM_RES_UP
        #define DIn1P_DM_RES_DWN         PIN_DM_RES_DWN
        #define DIn1P_DM_OD_LO           PIN_DM_OD_LO
        #define DIn1P_DM_OD_HI           PIN_DM_OD_HI
        #define DIn1P_DM_STRONG          PIN_DM_STRONG
        #define DIn1P_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DIn1P_MASK               DIn1P__MASK
#define DIn1P_SHIFT              DIn1P__SHIFT
#define DIn1P_WIDTH              1u

/* Interrupt constants */
#if defined(DIn1P__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DIn1P_SetInterruptMode() function.
     *  @{
     */
        #define DIn1P_INTR_NONE      (uint16)(0x0000u)
        #define DIn1P_INTR_RISING    (uint16)(0x0001u)
        #define DIn1P_INTR_FALLING   (uint16)(0x0002u)
        #define DIn1P_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DIn1P_INTR_MASK      (0x01u) 
#endif /* (DIn1P__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DIn1P_PS                     (* (reg8 *) DIn1P__PS)
/* Data Register */
#define DIn1P_DR                     (* (reg8 *) DIn1P__DR)
/* Port Number */
#define DIn1P_PRT_NUM                (* (reg8 *) DIn1P__PRT) 
/* Connect to Analog Globals */                                                  
#define DIn1P_AG                     (* (reg8 *) DIn1P__AG)                       
/* Analog MUX bux enable */
#define DIn1P_AMUX                   (* (reg8 *) DIn1P__AMUX) 
/* Bidirectional Enable */                                                        
#define DIn1P_BIE                    (* (reg8 *) DIn1P__BIE)
/* Bit-mask for Aliased Register Access */
#define DIn1P_BIT_MASK               (* (reg8 *) DIn1P__BIT_MASK)
/* Bypass Enable */
#define DIn1P_BYP                    (* (reg8 *) DIn1P__BYP)
/* Port wide control signals */                                                   
#define DIn1P_CTL                    (* (reg8 *) DIn1P__CTL)
/* Drive Modes */
#define DIn1P_DM0                    (* (reg8 *) DIn1P__DM0) 
#define DIn1P_DM1                    (* (reg8 *) DIn1P__DM1)
#define DIn1P_DM2                    (* (reg8 *) DIn1P__DM2) 
/* Input Buffer Disable Override */
#define DIn1P_INP_DIS                (* (reg8 *) DIn1P__INP_DIS)
/* LCD Common or Segment Drive */
#define DIn1P_LCD_COM_SEG            (* (reg8 *) DIn1P__LCD_COM_SEG)
/* Enable Segment LCD */
#define DIn1P_LCD_EN                 (* (reg8 *) DIn1P__LCD_EN)
/* Slew Rate Control */
#define DIn1P_SLW                    (* (reg8 *) DIn1P__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DIn1P_PRTDSI__CAPS_SEL       (* (reg8 *) DIn1P__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DIn1P_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DIn1P__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DIn1P_PRTDSI__OE_SEL0        (* (reg8 *) DIn1P__PRTDSI__OE_SEL0) 
#define DIn1P_PRTDSI__OE_SEL1        (* (reg8 *) DIn1P__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DIn1P_PRTDSI__OUT_SEL0       (* (reg8 *) DIn1P__PRTDSI__OUT_SEL0) 
#define DIn1P_PRTDSI__OUT_SEL1       (* (reg8 *) DIn1P__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DIn1P_PRTDSI__SYNC_OUT       (* (reg8 *) DIn1P__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DIn1P__SIO_CFG)
    #define DIn1P_SIO_HYST_EN        (* (reg8 *) DIn1P__SIO_HYST_EN)
    #define DIn1P_SIO_REG_HIFREQ     (* (reg8 *) DIn1P__SIO_REG_HIFREQ)
    #define DIn1P_SIO_CFG            (* (reg8 *) DIn1P__SIO_CFG)
    #define DIn1P_SIO_DIFF           (* (reg8 *) DIn1P__SIO_DIFF)
#endif /* (DIn1P__SIO_CFG) */

/* Interrupt Registers */
#if defined(DIn1P__INTSTAT)
    #define DIn1P_INTSTAT            (* (reg8 *) DIn1P__INTSTAT)
    #define DIn1P_SNAP               (* (reg8 *) DIn1P__SNAP)
    
	#define DIn1P_0_INTTYPE_REG 		(* (reg8 *) DIn1P__0__INTTYPE)
#endif /* (DIn1P__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DIn1P_H */


/* [] END OF FILE */
