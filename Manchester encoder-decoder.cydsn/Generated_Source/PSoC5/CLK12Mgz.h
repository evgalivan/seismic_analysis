/*******************************************************************************
* File Name: CLK12Mgz.h  
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

#if !defined(CY_PINS_CLK12Mgz_H) /* Pins CLK12Mgz_H */
#define CY_PINS_CLK12Mgz_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CLK12Mgz_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CLK12Mgz__PORT == 15 && ((CLK12Mgz__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    CLK12Mgz_Write(uint8 value);
void    CLK12Mgz_SetDriveMode(uint8 mode);
uint8   CLK12Mgz_ReadDataReg(void);
uint8   CLK12Mgz_Read(void);
void    CLK12Mgz_SetInterruptMode(uint16 position, uint16 mode);
uint8   CLK12Mgz_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the CLK12Mgz_SetDriveMode() function.
     *  @{
     */
        #define CLK12Mgz_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define CLK12Mgz_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define CLK12Mgz_DM_RES_UP          PIN_DM_RES_UP
        #define CLK12Mgz_DM_RES_DWN         PIN_DM_RES_DWN
        #define CLK12Mgz_DM_OD_LO           PIN_DM_OD_LO
        #define CLK12Mgz_DM_OD_HI           PIN_DM_OD_HI
        #define CLK12Mgz_DM_STRONG          PIN_DM_STRONG
        #define CLK12Mgz_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define CLK12Mgz_MASK               CLK12Mgz__MASK
#define CLK12Mgz_SHIFT              CLK12Mgz__SHIFT
#define CLK12Mgz_WIDTH              1u

/* Interrupt constants */
#if defined(CLK12Mgz__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CLK12Mgz_SetInterruptMode() function.
     *  @{
     */
        #define CLK12Mgz_INTR_NONE      (uint16)(0x0000u)
        #define CLK12Mgz_INTR_RISING    (uint16)(0x0001u)
        #define CLK12Mgz_INTR_FALLING   (uint16)(0x0002u)
        #define CLK12Mgz_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define CLK12Mgz_INTR_MASK      (0x01u) 
#endif /* (CLK12Mgz__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CLK12Mgz_PS                     (* (reg8 *) CLK12Mgz__PS)
/* Data Register */
#define CLK12Mgz_DR                     (* (reg8 *) CLK12Mgz__DR)
/* Port Number */
#define CLK12Mgz_PRT_NUM                (* (reg8 *) CLK12Mgz__PRT) 
/* Connect to Analog Globals */                                                  
#define CLK12Mgz_AG                     (* (reg8 *) CLK12Mgz__AG)                       
/* Analog MUX bux enable */
#define CLK12Mgz_AMUX                   (* (reg8 *) CLK12Mgz__AMUX) 
/* Bidirectional Enable */                                                        
#define CLK12Mgz_BIE                    (* (reg8 *) CLK12Mgz__BIE)
/* Bit-mask for Aliased Register Access */
#define CLK12Mgz_BIT_MASK               (* (reg8 *) CLK12Mgz__BIT_MASK)
/* Bypass Enable */
#define CLK12Mgz_BYP                    (* (reg8 *) CLK12Mgz__BYP)
/* Port wide control signals */                                                   
#define CLK12Mgz_CTL                    (* (reg8 *) CLK12Mgz__CTL)
/* Drive Modes */
#define CLK12Mgz_DM0                    (* (reg8 *) CLK12Mgz__DM0) 
#define CLK12Mgz_DM1                    (* (reg8 *) CLK12Mgz__DM1)
#define CLK12Mgz_DM2                    (* (reg8 *) CLK12Mgz__DM2) 
/* Input Buffer Disable Override */
#define CLK12Mgz_INP_DIS                (* (reg8 *) CLK12Mgz__INP_DIS)
/* LCD Common or Segment Drive */
#define CLK12Mgz_LCD_COM_SEG            (* (reg8 *) CLK12Mgz__LCD_COM_SEG)
/* Enable Segment LCD */
#define CLK12Mgz_LCD_EN                 (* (reg8 *) CLK12Mgz__LCD_EN)
/* Slew Rate Control */
#define CLK12Mgz_SLW                    (* (reg8 *) CLK12Mgz__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CLK12Mgz_PRTDSI__CAPS_SEL       (* (reg8 *) CLK12Mgz__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CLK12Mgz_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CLK12Mgz__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CLK12Mgz_PRTDSI__OE_SEL0        (* (reg8 *) CLK12Mgz__PRTDSI__OE_SEL0) 
#define CLK12Mgz_PRTDSI__OE_SEL1        (* (reg8 *) CLK12Mgz__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CLK12Mgz_PRTDSI__OUT_SEL0       (* (reg8 *) CLK12Mgz__PRTDSI__OUT_SEL0) 
#define CLK12Mgz_PRTDSI__OUT_SEL1       (* (reg8 *) CLK12Mgz__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CLK12Mgz_PRTDSI__SYNC_OUT       (* (reg8 *) CLK12Mgz__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(CLK12Mgz__SIO_CFG)
    #define CLK12Mgz_SIO_HYST_EN        (* (reg8 *) CLK12Mgz__SIO_HYST_EN)
    #define CLK12Mgz_SIO_REG_HIFREQ     (* (reg8 *) CLK12Mgz__SIO_REG_HIFREQ)
    #define CLK12Mgz_SIO_CFG            (* (reg8 *) CLK12Mgz__SIO_CFG)
    #define CLK12Mgz_SIO_DIFF           (* (reg8 *) CLK12Mgz__SIO_DIFF)
#endif /* (CLK12Mgz__SIO_CFG) */

/* Interrupt Registers */
#if defined(CLK12Mgz__INTSTAT)
    #define CLK12Mgz_INTSTAT            (* (reg8 *) CLK12Mgz__INTSTAT)
    #define CLK12Mgz_SNAP               (* (reg8 *) CLK12Mgz__SNAP)
    
	#define CLK12Mgz_0_INTTYPE_REG 		(* (reg8 *) CLK12Mgz__0__INTTYPE)
#endif /* (CLK12Mgz__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CLK12Mgz_H */


/* [] END OF FILE */
