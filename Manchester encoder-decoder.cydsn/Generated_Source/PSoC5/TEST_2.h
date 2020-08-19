/*******************************************************************************
* File Name: TEST_2.h  
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

#if !defined(CY_PINS_TEST_2_H) /* Pins TEST_2_H */
#define CY_PINS_TEST_2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "TEST_2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 TEST_2__PORT == 15 && ((TEST_2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    TEST_2_Write(uint8 value);
void    TEST_2_SetDriveMode(uint8 mode);
uint8   TEST_2_ReadDataReg(void);
uint8   TEST_2_Read(void);
void    TEST_2_SetInterruptMode(uint16 position, uint16 mode);
uint8   TEST_2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the TEST_2_SetDriveMode() function.
     *  @{
     */
        #define TEST_2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define TEST_2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define TEST_2_DM_RES_UP          PIN_DM_RES_UP
        #define TEST_2_DM_RES_DWN         PIN_DM_RES_DWN
        #define TEST_2_DM_OD_LO           PIN_DM_OD_LO
        #define TEST_2_DM_OD_HI           PIN_DM_OD_HI
        #define TEST_2_DM_STRONG          PIN_DM_STRONG
        #define TEST_2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define TEST_2_MASK               TEST_2__MASK
#define TEST_2_SHIFT              TEST_2__SHIFT
#define TEST_2_WIDTH              1u

/* Interrupt constants */
#if defined(TEST_2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in TEST_2_SetInterruptMode() function.
     *  @{
     */
        #define TEST_2_INTR_NONE      (uint16)(0x0000u)
        #define TEST_2_INTR_RISING    (uint16)(0x0001u)
        #define TEST_2_INTR_FALLING   (uint16)(0x0002u)
        #define TEST_2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define TEST_2_INTR_MASK      (0x01u) 
#endif /* (TEST_2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TEST_2_PS                     (* (reg8 *) TEST_2__PS)
/* Data Register */
#define TEST_2_DR                     (* (reg8 *) TEST_2__DR)
/* Port Number */
#define TEST_2_PRT_NUM                (* (reg8 *) TEST_2__PRT) 
/* Connect to Analog Globals */                                                  
#define TEST_2_AG                     (* (reg8 *) TEST_2__AG)                       
/* Analog MUX bux enable */
#define TEST_2_AMUX                   (* (reg8 *) TEST_2__AMUX) 
/* Bidirectional Enable */                                                        
#define TEST_2_BIE                    (* (reg8 *) TEST_2__BIE)
/* Bit-mask for Aliased Register Access */
#define TEST_2_BIT_MASK               (* (reg8 *) TEST_2__BIT_MASK)
/* Bypass Enable */
#define TEST_2_BYP                    (* (reg8 *) TEST_2__BYP)
/* Port wide control signals */                                                   
#define TEST_2_CTL                    (* (reg8 *) TEST_2__CTL)
/* Drive Modes */
#define TEST_2_DM0                    (* (reg8 *) TEST_2__DM0) 
#define TEST_2_DM1                    (* (reg8 *) TEST_2__DM1)
#define TEST_2_DM2                    (* (reg8 *) TEST_2__DM2) 
/* Input Buffer Disable Override */
#define TEST_2_INP_DIS                (* (reg8 *) TEST_2__INP_DIS)
/* LCD Common or Segment Drive */
#define TEST_2_LCD_COM_SEG            (* (reg8 *) TEST_2__LCD_COM_SEG)
/* Enable Segment LCD */
#define TEST_2_LCD_EN                 (* (reg8 *) TEST_2__LCD_EN)
/* Slew Rate Control */
#define TEST_2_SLW                    (* (reg8 *) TEST_2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define TEST_2_PRTDSI__CAPS_SEL       (* (reg8 *) TEST_2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define TEST_2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) TEST_2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define TEST_2_PRTDSI__OE_SEL0        (* (reg8 *) TEST_2__PRTDSI__OE_SEL0) 
#define TEST_2_PRTDSI__OE_SEL1        (* (reg8 *) TEST_2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define TEST_2_PRTDSI__OUT_SEL0       (* (reg8 *) TEST_2__PRTDSI__OUT_SEL0) 
#define TEST_2_PRTDSI__OUT_SEL1       (* (reg8 *) TEST_2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define TEST_2_PRTDSI__SYNC_OUT       (* (reg8 *) TEST_2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(TEST_2__SIO_CFG)
    #define TEST_2_SIO_HYST_EN        (* (reg8 *) TEST_2__SIO_HYST_EN)
    #define TEST_2_SIO_REG_HIFREQ     (* (reg8 *) TEST_2__SIO_REG_HIFREQ)
    #define TEST_2_SIO_CFG            (* (reg8 *) TEST_2__SIO_CFG)
    #define TEST_2_SIO_DIFF           (* (reg8 *) TEST_2__SIO_DIFF)
#endif /* (TEST_2__SIO_CFG) */

/* Interrupt Registers */
#if defined(TEST_2__INTSTAT)
    #define TEST_2_INTSTAT            (* (reg8 *) TEST_2__INTSTAT)
    #define TEST_2_SNAP               (* (reg8 *) TEST_2__SNAP)
    
	#define TEST_2_0_INTTYPE_REG 		(* (reg8 *) TEST_2__0__INTTYPE)
#endif /* (TEST_2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_TEST_2_H */


/* [] END OF FILE */
