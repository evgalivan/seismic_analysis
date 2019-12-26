/*******************************************************************************
* File Name: DATA_111.h  
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

#if !defined(CY_PINS_DATA_111_H) /* Pins DATA_111_H */
#define CY_PINS_DATA_111_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DATA_111_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DATA_111__PORT == 15 && ((DATA_111__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DATA_111_Write(uint8 value);
void    DATA_111_SetDriveMode(uint8 mode);
uint8   DATA_111_ReadDataReg(void);
uint8   DATA_111_Read(void);
void    DATA_111_SetInterruptMode(uint16 position, uint16 mode);
uint8   DATA_111_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DATA_111_SetDriveMode() function.
     *  @{
     */
        #define DATA_111_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DATA_111_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DATA_111_DM_RES_UP          PIN_DM_RES_UP
        #define DATA_111_DM_RES_DWN         PIN_DM_RES_DWN
        #define DATA_111_DM_OD_LO           PIN_DM_OD_LO
        #define DATA_111_DM_OD_HI           PIN_DM_OD_HI
        #define DATA_111_DM_STRONG          PIN_DM_STRONG
        #define DATA_111_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DATA_111_MASK               DATA_111__MASK
#define DATA_111_SHIFT              DATA_111__SHIFT
#define DATA_111_WIDTH              1u

/* Interrupt constants */
#if defined(DATA_111__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DATA_111_SetInterruptMode() function.
     *  @{
     */
        #define DATA_111_INTR_NONE      (uint16)(0x0000u)
        #define DATA_111_INTR_RISING    (uint16)(0x0001u)
        #define DATA_111_INTR_FALLING   (uint16)(0x0002u)
        #define DATA_111_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DATA_111_INTR_MASK      (0x01u) 
#endif /* (DATA_111__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DATA_111_PS                     (* (reg8 *) DATA_111__PS)
/* Data Register */
#define DATA_111_DR                     (* (reg8 *) DATA_111__DR)
/* Port Number */
#define DATA_111_PRT_NUM                (* (reg8 *) DATA_111__PRT) 
/* Connect to Analog Globals */                                                  
#define DATA_111_AG                     (* (reg8 *) DATA_111__AG)                       
/* Analog MUX bux enable */
#define DATA_111_AMUX                   (* (reg8 *) DATA_111__AMUX) 
/* Bidirectional Enable */                                                        
#define DATA_111_BIE                    (* (reg8 *) DATA_111__BIE)
/* Bit-mask for Aliased Register Access */
#define DATA_111_BIT_MASK               (* (reg8 *) DATA_111__BIT_MASK)
/* Bypass Enable */
#define DATA_111_BYP                    (* (reg8 *) DATA_111__BYP)
/* Port wide control signals */                                                   
#define DATA_111_CTL                    (* (reg8 *) DATA_111__CTL)
/* Drive Modes */
#define DATA_111_DM0                    (* (reg8 *) DATA_111__DM0) 
#define DATA_111_DM1                    (* (reg8 *) DATA_111__DM1)
#define DATA_111_DM2                    (* (reg8 *) DATA_111__DM2) 
/* Input Buffer Disable Override */
#define DATA_111_INP_DIS                (* (reg8 *) DATA_111__INP_DIS)
/* LCD Common or Segment Drive */
#define DATA_111_LCD_COM_SEG            (* (reg8 *) DATA_111__LCD_COM_SEG)
/* Enable Segment LCD */
#define DATA_111_LCD_EN                 (* (reg8 *) DATA_111__LCD_EN)
/* Slew Rate Control */
#define DATA_111_SLW                    (* (reg8 *) DATA_111__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DATA_111_PRTDSI__CAPS_SEL       (* (reg8 *) DATA_111__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DATA_111_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DATA_111__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DATA_111_PRTDSI__OE_SEL0        (* (reg8 *) DATA_111__PRTDSI__OE_SEL0) 
#define DATA_111_PRTDSI__OE_SEL1        (* (reg8 *) DATA_111__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DATA_111_PRTDSI__OUT_SEL0       (* (reg8 *) DATA_111__PRTDSI__OUT_SEL0) 
#define DATA_111_PRTDSI__OUT_SEL1       (* (reg8 *) DATA_111__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DATA_111_PRTDSI__SYNC_OUT       (* (reg8 *) DATA_111__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DATA_111__SIO_CFG)
    #define DATA_111_SIO_HYST_EN        (* (reg8 *) DATA_111__SIO_HYST_EN)
    #define DATA_111_SIO_REG_HIFREQ     (* (reg8 *) DATA_111__SIO_REG_HIFREQ)
    #define DATA_111_SIO_CFG            (* (reg8 *) DATA_111__SIO_CFG)
    #define DATA_111_SIO_DIFF           (* (reg8 *) DATA_111__SIO_DIFF)
#endif /* (DATA_111__SIO_CFG) */

/* Interrupt Registers */
#if defined(DATA_111__INTSTAT)
    #define DATA_111_INTSTAT            (* (reg8 *) DATA_111__INTSTAT)
    #define DATA_111_SNAP               (* (reg8 *) DATA_111__SNAP)
    
	#define DATA_111_0_INTTYPE_REG 		(* (reg8 *) DATA_111__0__INTTYPE)
#endif /* (DATA_111__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DATA_111_H */


/* [] END OF FILE */
