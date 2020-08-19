/*******************************************************************************
* File Name: DOUT.h  
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

#if !defined(CY_PINS_DOUT_H) /* Pins DOUT_H */
#define CY_PINS_DOUT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DOUT_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DOUT__PORT == 15 && ((DOUT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DOUT_Write(uint8 value);
void    DOUT_SetDriveMode(uint8 mode);
uint8   DOUT_ReadDataReg(void);
uint8   DOUT_Read(void);
void    DOUT_SetInterruptMode(uint16 position, uint16 mode);
uint8   DOUT_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DOUT_SetDriveMode() function.
     *  @{
     */
        #define DOUT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DOUT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DOUT_DM_RES_UP          PIN_DM_RES_UP
        #define DOUT_DM_RES_DWN         PIN_DM_RES_DWN
        #define DOUT_DM_OD_LO           PIN_DM_OD_LO
        #define DOUT_DM_OD_HI           PIN_DM_OD_HI
        #define DOUT_DM_STRONG          PIN_DM_STRONG
        #define DOUT_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DOUT_MASK               DOUT__MASK
#define DOUT_SHIFT              DOUT__SHIFT
#define DOUT_WIDTH              1u

/* Interrupt constants */
#if defined(DOUT__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DOUT_SetInterruptMode() function.
     *  @{
     */
        #define DOUT_INTR_NONE      (uint16)(0x0000u)
        #define DOUT_INTR_RISING    (uint16)(0x0001u)
        #define DOUT_INTR_FALLING   (uint16)(0x0002u)
        #define DOUT_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DOUT_INTR_MASK      (0x01u) 
#endif /* (DOUT__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DOUT_PS                     (* (reg8 *) DOUT__PS)
/* Data Register */
#define DOUT_DR                     (* (reg8 *) DOUT__DR)
/* Port Number */
#define DOUT_PRT_NUM                (* (reg8 *) DOUT__PRT) 
/* Connect to Analog Globals */                                                  
#define DOUT_AG                     (* (reg8 *) DOUT__AG)                       
/* Analog MUX bux enable */
#define DOUT_AMUX                   (* (reg8 *) DOUT__AMUX) 
/* Bidirectional Enable */                                                        
#define DOUT_BIE                    (* (reg8 *) DOUT__BIE)
/* Bit-mask for Aliased Register Access */
#define DOUT_BIT_MASK               (* (reg8 *) DOUT__BIT_MASK)
/* Bypass Enable */
#define DOUT_BYP                    (* (reg8 *) DOUT__BYP)
/* Port wide control signals */                                                   
#define DOUT_CTL                    (* (reg8 *) DOUT__CTL)
/* Drive Modes */
#define DOUT_DM0                    (* (reg8 *) DOUT__DM0) 
#define DOUT_DM1                    (* (reg8 *) DOUT__DM1)
#define DOUT_DM2                    (* (reg8 *) DOUT__DM2) 
/* Input Buffer Disable Override */
#define DOUT_INP_DIS                (* (reg8 *) DOUT__INP_DIS)
/* LCD Common or Segment Drive */
#define DOUT_LCD_COM_SEG            (* (reg8 *) DOUT__LCD_COM_SEG)
/* Enable Segment LCD */
#define DOUT_LCD_EN                 (* (reg8 *) DOUT__LCD_EN)
/* Slew Rate Control */
#define DOUT_SLW                    (* (reg8 *) DOUT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DOUT_PRTDSI__CAPS_SEL       (* (reg8 *) DOUT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DOUT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DOUT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DOUT_PRTDSI__OE_SEL0        (* (reg8 *) DOUT__PRTDSI__OE_SEL0) 
#define DOUT_PRTDSI__OE_SEL1        (* (reg8 *) DOUT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DOUT_PRTDSI__OUT_SEL0       (* (reg8 *) DOUT__PRTDSI__OUT_SEL0) 
#define DOUT_PRTDSI__OUT_SEL1       (* (reg8 *) DOUT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DOUT_PRTDSI__SYNC_OUT       (* (reg8 *) DOUT__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DOUT__SIO_CFG)
    #define DOUT_SIO_HYST_EN        (* (reg8 *) DOUT__SIO_HYST_EN)
    #define DOUT_SIO_REG_HIFREQ     (* (reg8 *) DOUT__SIO_REG_HIFREQ)
    #define DOUT_SIO_CFG            (* (reg8 *) DOUT__SIO_CFG)
    #define DOUT_SIO_DIFF           (* (reg8 *) DOUT__SIO_DIFF)
#endif /* (DOUT__SIO_CFG) */

/* Interrupt Registers */
#if defined(DOUT__INTSTAT)
    #define DOUT_INTSTAT            (* (reg8 *) DOUT__INTSTAT)
    #define DOUT_SNAP               (* (reg8 *) DOUT__SNAP)
    
	#define DOUT_0_INTTYPE_REG 		(* (reg8 *) DOUT__0__INTTYPE)
#endif /* (DOUT__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DOUT_H */


/* [] END OF FILE */
