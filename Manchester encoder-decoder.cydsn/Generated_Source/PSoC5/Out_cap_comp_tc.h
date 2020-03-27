/*******************************************************************************
* File Name: Out_cap_comp_tc.h  
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

#if !defined(CY_PINS_Out_cap_comp_tc_H) /* Pins Out_cap_comp_tc_H */
#define CY_PINS_Out_cap_comp_tc_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Out_cap_comp_tc_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Out_cap_comp_tc__PORT == 15 && ((Out_cap_comp_tc__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Out_cap_comp_tc_Write(uint8 value);
void    Out_cap_comp_tc_SetDriveMode(uint8 mode);
uint8   Out_cap_comp_tc_ReadDataReg(void);
uint8   Out_cap_comp_tc_Read(void);
void    Out_cap_comp_tc_SetInterruptMode(uint16 position, uint16 mode);
uint8   Out_cap_comp_tc_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Out_cap_comp_tc_SetDriveMode() function.
     *  @{
     */
        #define Out_cap_comp_tc_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Out_cap_comp_tc_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Out_cap_comp_tc_DM_RES_UP          PIN_DM_RES_UP
        #define Out_cap_comp_tc_DM_RES_DWN         PIN_DM_RES_DWN
        #define Out_cap_comp_tc_DM_OD_LO           PIN_DM_OD_LO
        #define Out_cap_comp_tc_DM_OD_HI           PIN_DM_OD_HI
        #define Out_cap_comp_tc_DM_STRONG          PIN_DM_STRONG
        #define Out_cap_comp_tc_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Out_cap_comp_tc_MASK               Out_cap_comp_tc__MASK
#define Out_cap_comp_tc_SHIFT              Out_cap_comp_tc__SHIFT
#define Out_cap_comp_tc_WIDTH              1u

/* Interrupt constants */
#if defined(Out_cap_comp_tc__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Out_cap_comp_tc_SetInterruptMode() function.
     *  @{
     */
        #define Out_cap_comp_tc_INTR_NONE      (uint16)(0x0000u)
        #define Out_cap_comp_tc_INTR_RISING    (uint16)(0x0001u)
        #define Out_cap_comp_tc_INTR_FALLING   (uint16)(0x0002u)
        #define Out_cap_comp_tc_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Out_cap_comp_tc_INTR_MASK      (0x01u) 
#endif /* (Out_cap_comp_tc__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Out_cap_comp_tc_PS                     (* (reg8 *) Out_cap_comp_tc__PS)
/* Data Register */
#define Out_cap_comp_tc_DR                     (* (reg8 *) Out_cap_comp_tc__DR)
/* Port Number */
#define Out_cap_comp_tc_PRT_NUM                (* (reg8 *) Out_cap_comp_tc__PRT) 
/* Connect to Analog Globals */                                                  
#define Out_cap_comp_tc_AG                     (* (reg8 *) Out_cap_comp_tc__AG)                       
/* Analog MUX bux enable */
#define Out_cap_comp_tc_AMUX                   (* (reg8 *) Out_cap_comp_tc__AMUX) 
/* Bidirectional Enable */                                                        
#define Out_cap_comp_tc_BIE                    (* (reg8 *) Out_cap_comp_tc__BIE)
/* Bit-mask for Aliased Register Access */
#define Out_cap_comp_tc_BIT_MASK               (* (reg8 *) Out_cap_comp_tc__BIT_MASK)
/* Bypass Enable */
#define Out_cap_comp_tc_BYP                    (* (reg8 *) Out_cap_comp_tc__BYP)
/* Port wide control signals */                                                   
#define Out_cap_comp_tc_CTL                    (* (reg8 *) Out_cap_comp_tc__CTL)
/* Drive Modes */
#define Out_cap_comp_tc_DM0                    (* (reg8 *) Out_cap_comp_tc__DM0) 
#define Out_cap_comp_tc_DM1                    (* (reg8 *) Out_cap_comp_tc__DM1)
#define Out_cap_comp_tc_DM2                    (* (reg8 *) Out_cap_comp_tc__DM2) 
/* Input Buffer Disable Override */
#define Out_cap_comp_tc_INP_DIS                (* (reg8 *) Out_cap_comp_tc__INP_DIS)
/* LCD Common or Segment Drive */
#define Out_cap_comp_tc_LCD_COM_SEG            (* (reg8 *) Out_cap_comp_tc__LCD_COM_SEG)
/* Enable Segment LCD */
#define Out_cap_comp_tc_LCD_EN                 (* (reg8 *) Out_cap_comp_tc__LCD_EN)
/* Slew Rate Control */
#define Out_cap_comp_tc_SLW                    (* (reg8 *) Out_cap_comp_tc__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Out_cap_comp_tc_PRTDSI__CAPS_SEL       (* (reg8 *) Out_cap_comp_tc__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Out_cap_comp_tc_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Out_cap_comp_tc__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Out_cap_comp_tc_PRTDSI__OE_SEL0        (* (reg8 *) Out_cap_comp_tc__PRTDSI__OE_SEL0) 
#define Out_cap_comp_tc_PRTDSI__OE_SEL1        (* (reg8 *) Out_cap_comp_tc__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Out_cap_comp_tc_PRTDSI__OUT_SEL0       (* (reg8 *) Out_cap_comp_tc__PRTDSI__OUT_SEL0) 
#define Out_cap_comp_tc_PRTDSI__OUT_SEL1       (* (reg8 *) Out_cap_comp_tc__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Out_cap_comp_tc_PRTDSI__SYNC_OUT       (* (reg8 *) Out_cap_comp_tc__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Out_cap_comp_tc__SIO_CFG)
    #define Out_cap_comp_tc_SIO_HYST_EN        (* (reg8 *) Out_cap_comp_tc__SIO_HYST_EN)
    #define Out_cap_comp_tc_SIO_REG_HIFREQ     (* (reg8 *) Out_cap_comp_tc__SIO_REG_HIFREQ)
    #define Out_cap_comp_tc_SIO_CFG            (* (reg8 *) Out_cap_comp_tc__SIO_CFG)
    #define Out_cap_comp_tc_SIO_DIFF           (* (reg8 *) Out_cap_comp_tc__SIO_DIFF)
#endif /* (Out_cap_comp_tc__SIO_CFG) */

/* Interrupt Registers */
#if defined(Out_cap_comp_tc__INTSTAT)
    #define Out_cap_comp_tc_INTSTAT            (* (reg8 *) Out_cap_comp_tc__INTSTAT)
    #define Out_cap_comp_tc_SNAP               (* (reg8 *) Out_cap_comp_tc__SNAP)
    
	#define Out_cap_comp_tc_0_INTTYPE_REG 		(* (reg8 *) Out_cap_comp_tc__0__INTTYPE)
#endif /* (Out_cap_comp_tc__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Out_cap_comp_tc_H */


/* [] END OF FILE */
