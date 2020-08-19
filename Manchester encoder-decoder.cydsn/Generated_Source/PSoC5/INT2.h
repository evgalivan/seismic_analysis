/*******************************************************************************
* File Name: INT2.h  
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

#if !defined(CY_PINS_INT2_H) /* Pins INT2_H */
#define CY_PINS_INT2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "INT2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 INT2__PORT == 15 && ((INT2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    INT2_Write(uint8 value);
void    INT2_SetDriveMode(uint8 mode);
uint8   INT2_ReadDataReg(void);
uint8   INT2_Read(void);
void    INT2_SetInterruptMode(uint16 position, uint16 mode);
uint8   INT2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the INT2_SetDriveMode() function.
     *  @{
     */
        #define INT2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define INT2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define INT2_DM_RES_UP          PIN_DM_RES_UP
        #define INT2_DM_RES_DWN         PIN_DM_RES_DWN
        #define INT2_DM_OD_LO           PIN_DM_OD_LO
        #define INT2_DM_OD_HI           PIN_DM_OD_HI
        #define INT2_DM_STRONG          PIN_DM_STRONG
        #define INT2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define INT2_MASK               INT2__MASK
#define INT2_SHIFT              INT2__SHIFT
#define INT2_WIDTH              1u

/* Interrupt constants */
#if defined(INT2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in INT2_SetInterruptMode() function.
     *  @{
     */
        #define INT2_INTR_NONE      (uint16)(0x0000u)
        #define INT2_INTR_RISING    (uint16)(0x0001u)
        #define INT2_INTR_FALLING   (uint16)(0x0002u)
        #define INT2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define INT2_INTR_MASK      (0x01u) 
#endif /* (INT2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define INT2_PS                     (* (reg8 *) INT2__PS)
/* Data Register */
#define INT2_DR                     (* (reg8 *) INT2__DR)
/* Port Number */
#define INT2_PRT_NUM                (* (reg8 *) INT2__PRT) 
/* Connect to Analog Globals */                                                  
#define INT2_AG                     (* (reg8 *) INT2__AG)                       
/* Analog MUX bux enable */
#define INT2_AMUX                   (* (reg8 *) INT2__AMUX) 
/* Bidirectional Enable */                                                        
#define INT2_BIE                    (* (reg8 *) INT2__BIE)
/* Bit-mask for Aliased Register Access */
#define INT2_BIT_MASK               (* (reg8 *) INT2__BIT_MASK)
/* Bypass Enable */
#define INT2_BYP                    (* (reg8 *) INT2__BYP)
/* Port wide control signals */                                                   
#define INT2_CTL                    (* (reg8 *) INT2__CTL)
/* Drive Modes */
#define INT2_DM0                    (* (reg8 *) INT2__DM0) 
#define INT2_DM1                    (* (reg8 *) INT2__DM1)
#define INT2_DM2                    (* (reg8 *) INT2__DM2) 
/* Input Buffer Disable Override */
#define INT2_INP_DIS                (* (reg8 *) INT2__INP_DIS)
/* LCD Common or Segment Drive */
#define INT2_LCD_COM_SEG            (* (reg8 *) INT2__LCD_COM_SEG)
/* Enable Segment LCD */
#define INT2_LCD_EN                 (* (reg8 *) INT2__LCD_EN)
/* Slew Rate Control */
#define INT2_SLW                    (* (reg8 *) INT2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define INT2_PRTDSI__CAPS_SEL       (* (reg8 *) INT2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define INT2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) INT2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define INT2_PRTDSI__OE_SEL0        (* (reg8 *) INT2__PRTDSI__OE_SEL0) 
#define INT2_PRTDSI__OE_SEL1        (* (reg8 *) INT2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define INT2_PRTDSI__OUT_SEL0       (* (reg8 *) INT2__PRTDSI__OUT_SEL0) 
#define INT2_PRTDSI__OUT_SEL1       (* (reg8 *) INT2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define INT2_PRTDSI__SYNC_OUT       (* (reg8 *) INT2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(INT2__SIO_CFG)
    #define INT2_SIO_HYST_EN        (* (reg8 *) INT2__SIO_HYST_EN)
    #define INT2_SIO_REG_HIFREQ     (* (reg8 *) INT2__SIO_REG_HIFREQ)
    #define INT2_SIO_CFG            (* (reg8 *) INT2__SIO_CFG)
    #define INT2_SIO_DIFF           (* (reg8 *) INT2__SIO_DIFF)
#endif /* (INT2__SIO_CFG) */

/* Interrupt Registers */
#if defined(INT2__INTSTAT)
    #define INT2_INTSTAT            (* (reg8 *) INT2__INTSTAT)
    #define INT2_SNAP               (* (reg8 *) INT2__SNAP)
    
	#define INT2_0_INTTYPE_REG 		(* (reg8 *) INT2__0__INTTYPE)
#endif /* (INT2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_INT2_H */


/* [] END OF FILE */
