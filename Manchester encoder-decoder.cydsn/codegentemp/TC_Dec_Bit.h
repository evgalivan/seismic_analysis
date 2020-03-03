/*******************************************************************************
* File Name: TC_Dec_Bit.h  
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

#if !defined(CY_PINS_TC_Dec_Bit_H) /* Pins TC_Dec_Bit_H */
#define CY_PINS_TC_Dec_Bit_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "TC_Dec_Bit_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 TC_Dec_Bit__PORT == 15 && ((TC_Dec_Bit__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    TC_Dec_Bit_Write(uint8 value);
void    TC_Dec_Bit_SetDriveMode(uint8 mode);
uint8   TC_Dec_Bit_ReadDataReg(void);
uint8   TC_Dec_Bit_Read(void);
void    TC_Dec_Bit_SetInterruptMode(uint16 position, uint16 mode);
uint8   TC_Dec_Bit_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the TC_Dec_Bit_SetDriveMode() function.
     *  @{
     */
        #define TC_Dec_Bit_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define TC_Dec_Bit_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define TC_Dec_Bit_DM_RES_UP          PIN_DM_RES_UP
        #define TC_Dec_Bit_DM_RES_DWN         PIN_DM_RES_DWN
        #define TC_Dec_Bit_DM_OD_LO           PIN_DM_OD_LO
        #define TC_Dec_Bit_DM_OD_HI           PIN_DM_OD_HI
        #define TC_Dec_Bit_DM_STRONG          PIN_DM_STRONG
        #define TC_Dec_Bit_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define TC_Dec_Bit_MASK               TC_Dec_Bit__MASK
#define TC_Dec_Bit_SHIFT              TC_Dec_Bit__SHIFT
#define TC_Dec_Bit_WIDTH              1u

/* Interrupt constants */
#if defined(TC_Dec_Bit__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in TC_Dec_Bit_SetInterruptMode() function.
     *  @{
     */
        #define TC_Dec_Bit_INTR_NONE      (uint16)(0x0000u)
        #define TC_Dec_Bit_INTR_RISING    (uint16)(0x0001u)
        #define TC_Dec_Bit_INTR_FALLING   (uint16)(0x0002u)
        #define TC_Dec_Bit_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define TC_Dec_Bit_INTR_MASK      (0x01u) 
#endif /* (TC_Dec_Bit__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TC_Dec_Bit_PS                     (* (reg8 *) TC_Dec_Bit__PS)
/* Data Register */
#define TC_Dec_Bit_DR                     (* (reg8 *) TC_Dec_Bit__DR)
/* Port Number */
#define TC_Dec_Bit_PRT_NUM                (* (reg8 *) TC_Dec_Bit__PRT) 
/* Connect to Analog Globals */                                                  
#define TC_Dec_Bit_AG                     (* (reg8 *) TC_Dec_Bit__AG)                       
/* Analog MUX bux enable */
#define TC_Dec_Bit_AMUX                   (* (reg8 *) TC_Dec_Bit__AMUX) 
/* Bidirectional Enable */                                                        
#define TC_Dec_Bit_BIE                    (* (reg8 *) TC_Dec_Bit__BIE)
/* Bit-mask for Aliased Register Access */
#define TC_Dec_Bit_BIT_MASK               (* (reg8 *) TC_Dec_Bit__BIT_MASK)
/* Bypass Enable */
#define TC_Dec_Bit_BYP                    (* (reg8 *) TC_Dec_Bit__BYP)
/* Port wide control signals */                                                   
#define TC_Dec_Bit_CTL                    (* (reg8 *) TC_Dec_Bit__CTL)
/* Drive Modes */
#define TC_Dec_Bit_DM0                    (* (reg8 *) TC_Dec_Bit__DM0) 
#define TC_Dec_Bit_DM1                    (* (reg8 *) TC_Dec_Bit__DM1)
#define TC_Dec_Bit_DM2                    (* (reg8 *) TC_Dec_Bit__DM2) 
/* Input Buffer Disable Override */
#define TC_Dec_Bit_INP_DIS                (* (reg8 *) TC_Dec_Bit__INP_DIS)
/* LCD Common or Segment Drive */
#define TC_Dec_Bit_LCD_COM_SEG            (* (reg8 *) TC_Dec_Bit__LCD_COM_SEG)
/* Enable Segment LCD */
#define TC_Dec_Bit_LCD_EN                 (* (reg8 *) TC_Dec_Bit__LCD_EN)
/* Slew Rate Control */
#define TC_Dec_Bit_SLW                    (* (reg8 *) TC_Dec_Bit__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define TC_Dec_Bit_PRTDSI__CAPS_SEL       (* (reg8 *) TC_Dec_Bit__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define TC_Dec_Bit_PRTDSI__DBL_SYNC_IN    (* (reg8 *) TC_Dec_Bit__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define TC_Dec_Bit_PRTDSI__OE_SEL0        (* (reg8 *) TC_Dec_Bit__PRTDSI__OE_SEL0) 
#define TC_Dec_Bit_PRTDSI__OE_SEL1        (* (reg8 *) TC_Dec_Bit__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define TC_Dec_Bit_PRTDSI__OUT_SEL0       (* (reg8 *) TC_Dec_Bit__PRTDSI__OUT_SEL0) 
#define TC_Dec_Bit_PRTDSI__OUT_SEL1       (* (reg8 *) TC_Dec_Bit__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define TC_Dec_Bit_PRTDSI__SYNC_OUT       (* (reg8 *) TC_Dec_Bit__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(TC_Dec_Bit__SIO_CFG)
    #define TC_Dec_Bit_SIO_HYST_EN        (* (reg8 *) TC_Dec_Bit__SIO_HYST_EN)
    #define TC_Dec_Bit_SIO_REG_HIFREQ     (* (reg8 *) TC_Dec_Bit__SIO_REG_HIFREQ)
    #define TC_Dec_Bit_SIO_CFG            (* (reg8 *) TC_Dec_Bit__SIO_CFG)
    #define TC_Dec_Bit_SIO_DIFF           (* (reg8 *) TC_Dec_Bit__SIO_DIFF)
#endif /* (TC_Dec_Bit__SIO_CFG) */

/* Interrupt Registers */
#if defined(TC_Dec_Bit__INTSTAT)
    #define TC_Dec_Bit_INTSTAT            (* (reg8 *) TC_Dec_Bit__INTSTAT)
    #define TC_Dec_Bit_SNAP               (* (reg8 *) TC_Dec_Bit__SNAP)
    
	#define TC_Dec_Bit_0_INTTYPE_REG 		(* (reg8 *) TC_Dec_Bit__0__INTTYPE)
#endif /* (TC_Dec_Bit__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_TC_Dec_Bit_H */


/* [] END OF FILE */
