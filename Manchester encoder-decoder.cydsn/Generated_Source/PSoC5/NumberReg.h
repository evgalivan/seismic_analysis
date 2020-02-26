/*******************************************************************************
* File Name: NumberReg.h
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


#if !defined(CY_SHIFTREG_NumberReg_H)
#define CY_SHIFTREG_NumberReg_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h"


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define NumberReg_FIFO_SIZE          (4u)
#define NumberReg_USE_INPUT_FIFO     (0u)
#define NumberReg_USE_OUTPUT_FIFO    (0u)
#define NumberReg_SR_SIZE            (32u)


/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;

    uint32 saveSrA0Reg;
    uint32 saveSrA1Reg;

    #if(CY_UDB_V0)
        uint32 saveSrIntMask;
    #endif /* (CY_UDB_V0) */

} NumberReg_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void  NumberReg_Start(void)                              ;
void  NumberReg_Stop(void)                               ;
void  NumberReg_Init(void)                               ;
void  NumberReg_Enable(void)                             ;
void  NumberReg_RestoreConfig(void)                      ;
void  NumberReg_SaveConfig(void)                         ;
void  NumberReg_Sleep(void)                              ;
void  NumberReg_Wakeup(void)                             ;
void  NumberReg_EnableInt(void)                          ;
void  NumberReg_DisableInt(void)                         ;
void  NumberReg_SetIntMode(uint8 interruptSource)        ;
uint8 NumberReg_GetIntStatus(void)                       ;
void  NumberReg_WriteRegValue(uint32 shiftData) \
                                                                ;
uint32 NumberReg_ReadRegValue(void) ;
uint8    NumberReg_GetFIFOStatus(uint8 fifoId)           ;

#if(0u != NumberReg_USE_INPUT_FIFO)
    cystatus NumberReg_WriteData(uint32 shiftData) \
                                                                ;
#endif /* (0u != NumberReg_USE_INPUT_FIFO) */

#if(0u != NumberReg_USE_OUTPUT_FIFO)
    uint32 NumberReg_ReadData(void) ;
#endif /* (0u != NumberReg_USE_OUTPUT_FIFO) */


/**********************************
*   Variable with external linkage
**********************************/

extern uint8 NumberReg_initVar;


/***************************************
*           API Constants
***************************************/

#define NumberReg_LOAD                   (0x01u)
#define NumberReg_STORE                  (0x02u)
#define NumberReg_RESET                  (0x04u)

#define NumberReg_IN_FIFO                (0x01u)
#define NumberReg_OUT_FIFO               (0x02u)

#define NumberReg_RET_FIFO_FULL          (0x00u)

/* This define is obsolete */
#define NumberReg_RET_FIFO_NOT_EMPTY     (0x01u)

#define NumberReg_RET_FIFO_PARTIAL       (0x01u)
#define NumberReg_RET_FIFO_EMPTY         (0x02u)
#define NumberReg_RET_FIFO_NOT_DEFINED   (0xFEu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define NumberReg__LEFT 0
#define NumberReg__RIGHT 1



/***************************************
*    Initial Parameter Constants
***************************************/

#define NumberReg_SR_MASK    (0xFFFFFFFFu) /* Unsigned is added to parameter */
#define NumberReg_INT_SRC    (0u)
#define NumberReg_DIRECTION  (1u)


/***************************************
*             Registers
***************************************/

/* Control register */
#define NumberReg_SR_CONTROL_REG (* (reg8 *) \
                                           NumberReg_bSR_SyncCtl_CtrlReg__CONTROL_REG)
#define NumberReg_SR_CONTROL_PTR (  (reg8 *) \
                                           NumberReg_bSR_SyncCtl_CtrlReg__CONTROL_REG)

/* Status register */
#define NumberReg_SR_STATUS_REG      (* (reg8 *) NumberReg_bSR_StsReg__STATUS_REG)
#define NumberReg_SR_STATUS_PTR      (  (reg8 *) NumberReg_bSR_StsReg__STATUS_REG)

/* Interrupt status register */
#define NumberReg_SR_STATUS_MASK_REG (* (reg8 *) NumberReg_bSR_StsReg__MASK_REG)
#define NumberReg_SR_STATUS_MASK_PTR (  (reg8 *) NumberReg_bSR_StsReg__MASK_REG)

/* Aux control register */
#define NumberReg_SR_AUX_CONTROL_REG (* (reg8 *) NumberReg_bSR_StsReg__STATUS_AUX_CTL_REG)
#define NumberReg_SR_AUX_CONTROL_PTR (  (reg8 *) NumberReg_bSR_StsReg__STATUS_AUX_CTL_REG)

/* A1 register: only used to implement capture function */
#define NumberReg_SHIFT_REG_CAPTURE_PTR    ( (reg8 *) \
                                        NumberReg_bSR_sC32_BShiftRegDp_u0__A1_REG )

#if(CY_PSOC3 || CY_PSOC5)
    #define NumberReg_IN_FIFO_VAL_LSB_PTR        ( (reg32 *) \
                                        NumberReg_bSR_sC32_BShiftRegDp_u0__F0_REG )

    #define NumberReg_SHIFT_REG_LSB_PTR          ( (reg32 *) \
                                        NumberReg_bSR_sC32_BShiftRegDp_u0__A0_REG )

    #define NumberReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg32 *) \
                                        NumberReg_bSR_sC32_BShiftRegDp_u0__A1_REG )

    #define NumberReg_OUT_FIFO_VAL_LSB_PTR       ( (reg32 *) \
                                        NumberReg_bSR_sC32_BShiftRegDp_u0__F1_REG )

#else
    #if(NumberReg_SR_SIZE <= 8u) /* 8bit - ShiftReg */
        #define NumberReg_IN_FIFO_VAL_LSB_PTR        ( (reg8 *) \
                                        NumberReg_bSR_sC32_BShiftRegDp_u0__F0_REG )

        #define NumberReg_SHIFT_REG_LSB_PTR          ( (reg8 *) \
                                        NumberReg_bSR_sC32_BShiftRegDp_u0__A0_REG )

        #define NumberReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg8 *) \
                                        NumberReg_bSR_sC32_BShiftRegDp_u0__A1_REG )

        #define NumberReg_OUT_FIFO_VAL_LSB_PTR       ( (reg8 *) \
                                        NumberReg_bSR_sC32_BShiftRegDp_u0__F1_REG )

    #elif(NumberReg_SR_SIZE <= 16u) /* 16bit - ShiftReg */
        #define NumberReg_IN_FIFO_VAL_LSB_PTR        ( (reg16 *) \
                                  NumberReg_bSR_sC32_BShiftRegDp_u0__16BIT_F0_REG )

        #define NumberReg_SHIFT_REG_LSB_PTR          ( (reg16 *) \
                                  NumberReg_bSR_sC32_BShiftRegDp_u0__16BIT_A0_REG )

        #define NumberReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg16 *) \
                                  NumberReg_bSR_sC32_BShiftRegDp_u0__16BIT_A1_REG )

        #define NumberReg_OUT_FIFO_VAL_LSB_PTR       ( (reg16 *) \
                                  NumberReg_bSR_sC32_BShiftRegDp_u0__16BIT_F1_REG )


    #elif(NumberReg_SR_SIZE <= 24u) /* 24bit - ShiftReg */
        #define NumberReg_IN_FIFO_VAL_LSB_PTR        ( (reg32 *) \
                                        NumberReg_bSR_sC32_BShiftRegDp_u0__F0_REG )

        #define NumberReg_SHIFT_REG_LSB_PTR          ( (reg32 *) \
                                        NumberReg_bSR_sC32_BShiftRegDp_u0__A0_REG )

        #define NumberReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg32 *) \
                                        NumberReg_bSR_sC32_BShiftRegDp_u0__A1_REG )

        #define NumberReg_OUT_FIFO_VAL_LSB_PTR       ( (reg32 *) \
                                        NumberReg_bSR_sC32_BShiftRegDp_u0__F1_REG )

    #else /* 32bit - ShiftReg */
        #define NumberReg_IN_FIFO_VAL_LSB_PTR        ( (reg32 *) \
                                  NumberReg_bSR_sC32_BShiftRegDp_u0__32BIT_F0_REG )

        #define NumberReg_SHIFT_REG_LSB_PTR          ( (reg32 *) \
                                  NumberReg_bSR_sC32_BShiftRegDp_u0__32BIT_A0_REG )

        #define NumberReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg32 *) \
                                  NumberReg_bSR_sC32_BShiftRegDp_u0__32BIT_A1_REG )

        #define NumberReg_OUT_FIFO_VAL_LSB_PTR       ( (reg32 *) \
                                  NumberReg_bSR_sC32_BShiftRegDp_u0__32BIT_F1_REG )

    #endif  /* (NumberReg_SR_SIZE <= 8u) */
#endif      /* (CY_PSOC3 || CY_PSOC5) */


/***************************************
*       Register Constants
***************************************/

#define NumberReg_INTERRUPTS_ENABLE      (0x10u)
#define NumberReg_LOAD_INT_EN            (0x01u)
#define NumberReg_STORE_INT_EN           (0x02u)
#define NumberReg_RESET_INT_EN           (0x04u)
#define NumberReg_CLK_EN                 (0x01u)

#define NumberReg_RESET_INT_EN_MASK      (0xFBu)
#define NumberReg_LOAD_INT_EN_MASK       (0xFEu)
#define NumberReg_STORE_INT_EN_MASK      (0xFDu)
#define NumberReg_INTS_EN_MASK           (0x07u)

#define NumberReg_OUT_FIFO_CLR_BIT       (0x02u)

#if(0u != NumberReg_USE_INPUT_FIFO)

    #define NumberReg_IN_FIFO_MASK       (0x18u)

    #define NumberReg_IN_FIFO_FULL       (0x00u)
    #define NumberReg_IN_FIFO_EMPTY      (0x01u)
    #define NumberReg_IN_FIFO_PARTIAL    (0x02u)
    
    /* This define is obsolete */
    #define NumberReg_IN_FIFO_NOT_EMPTY  (0x02u)
    
#endif /* (0u != NumberReg_USE_INPUT_FIFO) */

#define NumberReg_OUT_FIFO_MASK          (0x60u)

#define NumberReg_OUT_FIFO_EMPTY         (0x00u)
#define NumberReg_OUT_FIFO_FULL          (0x01u)
#define NumberReg_OUT_FIFO_PARTIAL       (0x02u)

/* This define is obsolete */
#define NumberReg_OUT_FIFO_NOT_EMPTY     (0x02u)

#define NumberReg_IN_FIFO_SHIFT_MASK     (0x03u)
#define NumberReg_OUT_FIFO_SHIFT_MASK    (0x05u)

#define NumberReg_DISABLED               (0u)
#define NumberReg_DEFAULT_A0             (0u)
#define NumberReg_DEFAULT_A1             (0u)


/***************************************
*       Macros
***************************************/

#define NumberReg_IS_ENABLED         (0u != (NumberReg_SR_CONTROL & NumberReg_CLK_EN))

#define NumberReg_GET_OUT_FIFO_STS   ((NumberReg_SR_STATUS & NumberReg_OUT_FIFO_MASK) >> \
                                              NumberReg_OUT_FIFO_SHIFT_MASK)

#define NumberReg_GET_IN_FIFO_STS    ((NumberReg_SR_STATUS & NumberReg_IN_FIFO_MASK)  >> \
                                              NumberReg_IN_FIFO_SHIFT_MASK)


/***************************************
*       Obsolete
***************************************/

/* Following code are OBSOLETE and must not be used 
 * starting from ShiftReg 2.20 
 */

#define NumberReg_SR_CONTROL     (NumberReg_SR_CONTROL_REG)
#define NumberReg_SR_STATUS      (NumberReg_SR_STATUS_REG)
#define NumberReg_SR_STATUS_MASK (NumberReg_SR_STATUS_MASK_REG)
#define NumberReg_SR_AUX_CONTROL (NumberReg_SR_AUX_CONTROL_REG)

#define NumberReg_IN_FIFO_SHFT_MASK  (NumberReg_IN_FIFO_SHIFT_MASK)
#define NumberReg_OUT_FIFO_SHFT_MASK (NumberReg_OUT_FIFO_SHFIT_MASK)

#define NumberReg_RET_FIFO_BAD_PARAM (0xFFu)

#endif /* (CY_SHIFTREG_NumberReg_H) */


/* [] END OF FILE */
