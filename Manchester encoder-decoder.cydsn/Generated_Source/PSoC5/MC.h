/*******************************************************************************
* File Name: MC.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_MC_H)
#define CY_CLOCK_MC_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void MC_Start(void) ;
void MC_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void MC_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void MC_StandbyPower(uint8 state) ;
void MC_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 MC_GetDividerRegister(void) ;
void MC_SetModeRegister(uint8 modeBitMask) ;
void MC_ClearModeRegister(uint8 modeBitMask) ;
uint8 MC_GetModeRegister(void) ;
void MC_SetSourceRegister(uint8 clkSource) ;
uint8 MC_GetSourceRegister(void) ;
#if defined(MC__CFG3)
void MC_SetPhaseRegister(uint8 clkPhase) ;
uint8 MC_GetPhaseRegister(void) ;
#endif /* defined(MC__CFG3) */

#define MC_Enable()                       MC_Start()
#define MC_Disable()                      MC_Stop()
#define MC_SetDivider(clkDivider)         MC_SetDividerRegister(clkDivider, 1u)
#define MC_SetDividerValue(clkDivider)    MC_SetDividerRegister((clkDivider) - 1u, 1u)
#define MC_SetMode(clkMode)               MC_SetModeRegister(clkMode)
#define MC_SetSource(clkSource)           MC_SetSourceRegister(clkSource)
#if defined(MC__CFG3)
#define MC_SetPhase(clkPhase)             MC_SetPhaseRegister(clkPhase)
#define MC_SetPhaseValue(clkPhase)        MC_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(MC__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define MC_CLKEN              (* (reg8 *) MC__PM_ACT_CFG)
#define MC_CLKEN_PTR          ((reg8 *) MC__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define MC_CLKSTBY            (* (reg8 *) MC__PM_STBY_CFG)
#define MC_CLKSTBY_PTR        ((reg8 *) MC__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define MC_DIV_LSB            (* (reg8 *) MC__CFG0)
#define MC_DIV_LSB_PTR        ((reg8 *) MC__CFG0)
#define MC_DIV_PTR            ((reg16 *) MC__CFG0)

/* Clock MSB divider configuration register. */
#define MC_DIV_MSB            (* (reg8 *) MC__CFG1)
#define MC_DIV_MSB_PTR        ((reg8 *) MC__CFG1)

/* Mode and source configuration register */
#define MC_MOD_SRC            (* (reg8 *) MC__CFG2)
#define MC_MOD_SRC_PTR        ((reg8 *) MC__CFG2)

#if defined(MC__CFG3)
/* Analog clock phase configuration register */
#define MC_PHASE              (* (reg8 *) MC__CFG3)
#define MC_PHASE_PTR          ((reg8 *) MC__CFG3)
#endif /* defined(MC__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define MC_CLKEN_MASK         MC__PM_ACT_MSK
#define MC_CLKSTBY_MASK       MC__PM_STBY_MSK

/* CFG2 field masks */
#define MC_SRC_SEL_MSK        MC__CFG2_SRC_SEL_MASK
#define MC_MODE_MASK          (~(MC_SRC_SEL_MSK))

#if defined(MC__CFG3)
/* CFG3 phase mask */
#define MC_PHASE_MASK         MC__CFG3_PHASE_DLY_MASK
#endif /* defined(MC__CFG3) */

#endif /* CY_CLOCK_MC_H */


/* [] END OF FILE */
