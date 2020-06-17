/*******************************************************************************
* File Name: Period.h
* Version 2.30
*
* Description:
*  This header file contains definitions associated with the Shift Register
*  component.
*
* Note: none
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/


#if !defined(CY_SHIFTREG_Period_H)
#define CY_SHIFTREG_Period_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h"


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define Period_FIFO_SIZE          (4u)
#define Period_USE_INPUT_FIFO     (1u)
#define Period_USE_OUTPUT_FIFO    (0u)
#define Period_SR_SIZE            (9u)


/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;

    uint16 saveSrA0Reg;
    uint16 saveSrA1Reg;

    #if(CY_UDB_V0)
        uint16 saveSrIntMask;
    #endif /* (CY_UDB_V0) */

} Period_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void  Period_Start(void)                              ;
void  Period_Stop(void)                               ;
void  Period_Init(void)                               ;
void  Period_Enable(void)                             ;
void  Period_RestoreConfig(void)                      ;
void  Period_SaveConfig(void)                         ;
void  Period_Sleep(void)                              ;
void  Period_Wakeup(void)                             ;
void  Period_EnableInt(void)                          ;
void  Period_DisableInt(void)                         ;
void  Period_SetIntMode(uint8 interruptSource)        ;
uint8 Period_GetIntStatus(void)                       ;
void  Period_WriteRegValue(uint16 shiftData) \
                                                                ;
uint16 Period_ReadRegValue(void) ;
uint8    Period_GetFIFOStatus(uint8 fifoId)           ;

#if(0u != Period_USE_INPUT_FIFO)
    cystatus Period_WriteData(uint16 shiftData) \
                                                                ;
#endif /* (0u != Period_USE_INPUT_FIFO) */

#if(0u != Period_USE_OUTPUT_FIFO)
    uint16 Period_ReadData(void) ;
#endif /* (0u != Period_USE_OUTPUT_FIFO) */


/**********************************
*   Variable with external linkage
**********************************/

extern uint8 Period_initVar;


/***************************************
*           API Constants
***************************************/

#define Period_LOAD                   (0x01u)
#define Period_STORE                  (0x02u)
#define Period_RESET                  (0x04u)

#define Period_IN_FIFO                (0x01u)
#define Period_OUT_FIFO               (0x02u)

#define Period_RET_FIFO_FULL          (0x00u)

/* This define is obsolete */
#define Period_RET_FIFO_NOT_EMPTY     (0x01u)

#define Period_RET_FIFO_PARTIAL       (0x01u)
#define Period_RET_FIFO_EMPTY         (0x02u)
#define Period_RET_FIFO_NOT_DEFINED   (0xFEu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define Period__LEFT 0
#define Period__RIGHT 1



/***************************************
*    Initial Parameter Constants
***************************************/

#define Period_SR_MASK    (0x1FFu) /* Unsigned is added to parameter */
#define Period_INT_SRC    (1u)
#define Period_DIRECTION  (1u)


/***************************************
*             Registers
***************************************/

/* Control register */
#define Period_SR_CONTROL_REG (* (reg8 *) \
                                           Period_bSR_SyncCtl_CtrlReg__CONTROL_REG)
#define Period_SR_CONTROL_PTR (  (reg8 *) \
                                           Period_bSR_SyncCtl_CtrlReg__CONTROL_REG)

/* Status register */
#define Period_SR_STATUS_REG      (* (reg8 *) Period_bSR_StsReg__STATUS_REG)
#define Period_SR_STATUS_PTR      (  (reg8 *) Period_bSR_StsReg__STATUS_REG)

/* Interrupt status register */
#define Period_SR_STATUS_MASK_REG (* (reg8 *) Period_bSR_StsReg__MASK_REG)
#define Period_SR_STATUS_MASK_PTR (  (reg8 *) Period_bSR_StsReg__MASK_REG)

/* Aux control register */
#define Period_SR_AUX_CONTROL_REG (* (reg8 *) Period_bSR_StsReg__STATUS_AUX_CTL_REG)
#define Period_SR_AUX_CONTROL_PTR (  (reg8 *) Period_bSR_StsReg__STATUS_AUX_CTL_REG)

/* A1 register: only used to implement capture function */
#define Period_SHIFT_REG_CAPTURE_PTR    ( (reg8 *) \
                                        Period_bSR_sC16_BShiftRegDp_u0__A1_REG )

#if(CY_PSOC3 || CY_PSOC5)
    #define Period_IN_FIFO_VAL_LSB_PTR        ( (reg16 *) \
                                        Period_bSR_sC16_BShiftRegDp_u0__F0_REG )

    #define Period_SHIFT_REG_LSB_PTR          ( (reg16 *) \
                                        Period_bSR_sC16_BShiftRegDp_u0__A0_REG )

    #define Period_SHIFT_REG_VALUE_LSB_PTR    ( (reg16 *) \
                                        Period_bSR_sC16_BShiftRegDp_u0__A1_REG )

    #define Period_OUT_FIFO_VAL_LSB_PTR       ( (reg16 *) \
                                        Period_bSR_sC16_BShiftRegDp_u0__F1_REG )

#else
    #if(Period_SR_SIZE <= 8u) /* 8bit - ShiftReg */
        #define Period_IN_FIFO_VAL_LSB_PTR        ( (reg8 *) \
                                        Period_bSR_sC16_BShiftRegDp_u0__F0_REG )

        #define Period_SHIFT_REG_LSB_PTR          ( (reg8 *) \
                                        Period_bSR_sC16_BShiftRegDp_u0__A0_REG )

        #define Period_SHIFT_REG_VALUE_LSB_PTR    ( (reg8 *) \
                                        Period_bSR_sC16_BShiftRegDp_u0__A1_REG )

        #define Period_OUT_FIFO_VAL_LSB_PTR       ( (reg8 *) \
                                        Period_bSR_sC16_BShiftRegDp_u0__F1_REG )

    #elif(Period_SR_SIZE <= 16u) /* 16bit - ShiftReg */
        #define Period_IN_FIFO_VAL_LSB_PTR        ( (reg16 *) \
                                  Period_bSR_sC16_BShiftRegDp_u0__16BIT_F0_REG )

        #define Period_SHIFT_REG_LSB_PTR          ( (reg16 *) \
                                  Period_bSR_sC16_BShiftRegDp_u0__16BIT_A0_REG )

        #define Period_SHIFT_REG_VALUE_LSB_PTR    ( (reg16 *) \
                                  Period_bSR_sC16_BShiftRegDp_u0__16BIT_A1_REG )

        #define Period_OUT_FIFO_VAL_LSB_PTR       ( (reg16 *) \
                                  Period_bSR_sC16_BShiftRegDp_u0__16BIT_F1_REG )


    #elif(Period_SR_SIZE <= 24u) /* 24bit - ShiftReg */
        #define Period_IN_FIFO_VAL_LSB_PTR        ( (reg32 *) \
                                        Period_bSR_sC16_BShiftRegDp_u0__F0_REG )

        #define Period_SHIFT_REG_LSB_PTR          ( (reg32 *) \
                                        Period_bSR_sC16_BShiftRegDp_u0__A0_REG )

        #define Period_SHIFT_REG_VALUE_LSB_PTR    ( (reg32 *) \
                                        Period_bSR_sC16_BShiftRegDp_u0__A1_REG )

        #define Period_OUT_FIFO_VAL_LSB_PTR       ( (reg32 *) \
                                        Period_bSR_sC16_BShiftRegDp_u0__F1_REG )

    #else /* 32bit - ShiftReg */
        #define Period_IN_FIFO_VAL_LSB_PTR        ( (reg32 *) \
                                  Period_bSR_sC16_BShiftRegDp_u0__32BIT_F0_REG )

        #define Period_SHIFT_REG_LSB_PTR          ( (reg32 *) \
                                  Period_bSR_sC16_BShiftRegDp_u0__32BIT_A0_REG )

        #define Period_SHIFT_REG_VALUE_LSB_PTR    ( (reg32 *) \
                                  Period_bSR_sC16_BShiftRegDp_u0__32BIT_A1_REG )

        #define Period_OUT_FIFO_VAL_LSB_PTR       ( (reg32 *) \
                                  Period_bSR_sC16_BShiftRegDp_u0__32BIT_F1_REG )

    #endif  /* (Period_SR_SIZE <= 8u) */
#endif      /* (CY_PSOC3 || CY_PSOC5) */


/***************************************
*       Register Constants
***************************************/

#define Period_INTERRUPTS_ENABLE      (0x10u)
#define Period_LOAD_INT_EN            (0x01u)
#define Period_STORE_INT_EN           (0x02u)
#define Period_RESET_INT_EN           (0x04u)
#define Period_CLK_EN                 (0x01u)

#define Period_RESET_INT_EN_MASK      (0xFBu)
#define Period_LOAD_INT_EN_MASK       (0xFEu)
#define Period_STORE_INT_EN_MASK      (0xFDu)
#define Period_INTS_EN_MASK           (0x07u)

#define Period_OUT_FIFO_CLR_BIT       (0x02u)

#if(0u != Period_USE_INPUT_FIFO)

    #define Period_IN_FIFO_MASK       (0x18u)

    #define Period_IN_FIFO_FULL       (0x00u)
    #define Period_IN_FIFO_EMPTY      (0x01u)
    #define Period_IN_FIFO_PARTIAL    (0x02u)
    
    /* This define is obsolete */
    #define Period_IN_FIFO_NOT_EMPTY  (0x02u)
    
#endif /* (0u != Period_USE_INPUT_FIFO) */

#define Period_OUT_FIFO_MASK          (0x60u)

#define Period_OUT_FIFO_EMPTY         (0x00u)
#define Period_OUT_FIFO_FULL          (0x01u)
#define Period_OUT_FIFO_PARTIAL       (0x02u)

/* This define is obsolete */
#define Period_OUT_FIFO_NOT_EMPTY     (0x02u)

#define Period_IN_FIFO_SHIFT_MASK     (0x03u)
#define Period_OUT_FIFO_SHIFT_MASK    (0x05u)

#define Period_DISABLED               (0u)
#define Period_DEFAULT_A0             (0u)
#define Period_DEFAULT_A1             (0u)


/***************************************
*       Macros
***************************************/

#define Period_IS_ENABLED         (0u != (Period_SR_CONTROL & Period_CLK_EN))

#define Period_GET_OUT_FIFO_STS   ((Period_SR_STATUS & Period_OUT_FIFO_MASK) >> \
                                              Period_OUT_FIFO_SHIFT_MASK)

#define Period_GET_IN_FIFO_STS    ((Period_SR_STATUS & Period_IN_FIFO_MASK)  >> \
                                              Period_IN_FIFO_SHIFT_MASK)


/***************************************
*       Obsolete
***************************************/

/* Following code are OBSOLETE and must not be used 
 * starting from ShiftReg 2.20 
 */

#define Period_SR_CONTROL     (Period_SR_CONTROL_REG)
#define Period_SR_STATUS      (Period_SR_STATUS_REG)
#define Period_SR_STATUS_MASK (Period_SR_STATUS_MASK_REG)
#define Period_SR_AUX_CONTROL (Period_SR_AUX_CONTROL_REG)

#define Period_IN_FIFO_SHFT_MASK  (Period_IN_FIFO_SHIFT_MASK)
#define Period_OUT_FIFO_SHFT_MASK (Period_OUT_FIFO_SHFIT_MASK)

#define Period_RET_FIFO_BAD_PARAM (0xFFu)

#endif /* (CY_SHIFTREG_Period_H) */


/* [] END OF FILE */
