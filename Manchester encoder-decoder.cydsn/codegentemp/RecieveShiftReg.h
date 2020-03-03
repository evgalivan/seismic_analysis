/*******************************************************************************
* File Name: RecieveShiftReg.h
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


#if !defined(CY_SHIFTREG_RecieveShiftReg_H)
#define CY_SHIFTREG_RecieveShiftReg_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h"


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define RecieveShiftReg_FIFO_SIZE          (4u)
#define RecieveShiftReg_USE_INPUT_FIFO     (0u)
#define RecieveShiftReg_USE_OUTPUT_FIFO    (1u)
#define RecieveShiftReg_SR_SIZE            (32u)


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

} RecieveShiftReg_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void  RecieveShiftReg_Start(void)                              ;
void  RecieveShiftReg_Stop(void)                               ;
void  RecieveShiftReg_Init(void)                               ;
void  RecieveShiftReg_Enable(void)                             ;
void  RecieveShiftReg_RestoreConfig(void)                      ;
void  RecieveShiftReg_SaveConfig(void)                         ;
void  RecieveShiftReg_Sleep(void)                              ;
void  RecieveShiftReg_Wakeup(void)                             ;
void  RecieveShiftReg_EnableInt(void)                          ;
void  RecieveShiftReg_DisableInt(void)                         ;
void  RecieveShiftReg_SetIntMode(uint8 interruptSource)        ;
uint8 RecieveShiftReg_GetIntStatus(void)                       ;
void  RecieveShiftReg_WriteRegValue(uint32 shiftData) \
                                                                ;
uint32 RecieveShiftReg_ReadRegValue(void) ;
uint8    RecieveShiftReg_GetFIFOStatus(uint8 fifoId)           ;

#if(0u != RecieveShiftReg_USE_INPUT_FIFO)
    cystatus RecieveShiftReg_WriteData(uint32 shiftData) \
                                                                ;
#endif /* (0u != RecieveShiftReg_USE_INPUT_FIFO) */

#if(0u != RecieveShiftReg_USE_OUTPUT_FIFO)
    uint32 RecieveShiftReg_ReadData(void) ;
#endif /* (0u != RecieveShiftReg_USE_OUTPUT_FIFO) */


/**********************************
*   Variable with external linkage
**********************************/

extern uint8 RecieveShiftReg_initVar;


/***************************************
*           API Constants
***************************************/

#define RecieveShiftReg_LOAD                   (0x01u)
#define RecieveShiftReg_STORE                  (0x02u)
#define RecieveShiftReg_RESET                  (0x04u)

#define RecieveShiftReg_IN_FIFO                (0x01u)
#define RecieveShiftReg_OUT_FIFO               (0x02u)

#define RecieveShiftReg_RET_FIFO_FULL          (0x00u)

/* This define is obsolete */
#define RecieveShiftReg_RET_FIFO_NOT_EMPTY     (0x01u)

#define RecieveShiftReg_RET_FIFO_PARTIAL       (0x01u)
#define RecieveShiftReg_RET_FIFO_EMPTY         (0x02u)
#define RecieveShiftReg_RET_FIFO_NOT_DEFINED   (0xFEu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define RecieveShiftReg__LEFT 0
#define RecieveShiftReg__RIGHT 1



/***************************************
*    Initial Parameter Constants
***************************************/

#define RecieveShiftReg_SR_MASK    (0xFFFFFFFFu) /* Unsigned is added to parameter */
#define RecieveShiftReg_INT_SRC    (2u)
#define RecieveShiftReg_DIRECTION  (0u)


/***************************************
*             Registers
***************************************/

/* Control register */
#define RecieveShiftReg_SR_CONTROL_REG (* (reg8 *) \
                                           RecieveShiftReg_bSR_SyncCtl_CtrlReg__CONTROL_REG)
#define RecieveShiftReg_SR_CONTROL_PTR (  (reg8 *) \
                                           RecieveShiftReg_bSR_SyncCtl_CtrlReg__CONTROL_REG)

/* Status register */
#define RecieveShiftReg_SR_STATUS_REG      (* (reg8 *) RecieveShiftReg_bSR_StsReg__STATUS_REG)
#define RecieveShiftReg_SR_STATUS_PTR      (  (reg8 *) RecieveShiftReg_bSR_StsReg__STATUS_REG)

/* Interrupt status register */
#define RecieveShiftReg_SR_STATUS_MASK_REG (* (reg8 *) RecieveShiftReg_bSR_StsReg__MASK_REG)
#define RecieveShiftReg_SR_STATUS_MASK_PTR (  (reg8 *) RecieveShiftReg_bSR_StsReg__MASK_REG)

/* Aux control register */
#define RecieveShiftReg_SR_AUX_CONTROL_REG (* (reg8 *) RecieveShiftReg_bSR_StsReg__STATUS_AUX_CTL_REG)
#define RecieveShiftReg_SR_AUX_CONTROL_PTR (  (reg8 *) RecieveShiftReg_bSR_StsReg__STATUS_AUX_CTL_REG)

/* A1 register: only used to implement capture function */
#define RecieveShiftReg_SHIFT_REG_CAPTURE_PTR    ( (reg8 *) \
                                        RecieveShiftReg_bSR_sC32_BShiftRegDp_u0__A1_REG )

#if(CY_PSOC3 || CY_PSOC5)
    #define RecieveShiftReg_IN_FIFO_VAL_LSB_PTR        ( (reg32 *) \
                                        RecieveShiftReg_bSR_sC32_BShiftRegDp_u0__F0_REG )

    #define RecieveShiftReg_SHIFT_REG_LSB_PTR          ( (reg32 *) \
                                        RecieveShiftReg_bSR_sC32_BShiftRegDp_u0__A0_REG )

    #define RecieveShiftReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg32 *) \
                                        RecieveShiftReg_bSR_sC32_BShiftRegDp_u0__A1_REG )

    #define RecieveShiftReg_OUT_FIFO_VAL_LSB_PTR       ( (reg32 *) \
                                        RecieveShiftReg_bSR_sC32_BShiftRegDp_u0__F1_REG )

#else
    #if(RecieveShiftReg_SR_SIZE <= 8u) /* 8bit - ShiftReg */
        #define RecieveShiftReg_IN_FIFO_VAL_LSB_PTR        ( (reg8 *) \
                                        RecieveShiftReg_bSR_sC32_BShiftRegDp_u0__F0_REG )

        #define RecieveShiftReg_SHIFT_REG_LSB_PTR          ( (reg8 *) \
                                        RecieveShiftReg_bSR_sC32_BShiftRegDp_u0__A0_REG )

        #define RecieveShiftReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg8 *) \
                                        RecieveShiftReg_bSR_sC32_BShiftRegDp_u0__A1_REG )

        #define RecieveShiftReg_OUT_FIFO_VAL_LSB_PTR       ( (reg8 *) \
                                        RecieveShiftReg_bSR_sC32_BShiftRegDp_u0__F1_REG )

    #elif(RecieveShiftReg_SR_SIZE <= 16u) /* 16bit - ShiftReg */
        #define RecieveShiftReg_IN_FIFO_VAL_LSB_PTR        ( (reg16 *) \
                                  RecieveShiftReg_bSR_sC32_BShiftRegDp_u0__16BIT_F0_REG )

        #define RecieveShiftReg_SHIFT_REG_LSB_PTR          ( (reg16 *) \
                                  RecieveShiftReg_bSR_sC32_BShiftRegDp_u0__16BIT_A0_REG )

        #define RecieveShiftReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg16 *) \
                                  RecieveShiftReg_bSR_sC32_BShiftRegDp_u0__16BIT_A1_REG )

        #define RecieveShiftReg_OUT_FIFO_VAL_LSB_PTR       ( (reg16 *) \
                                  RecieveShiftReg_bSR_sC32_BShiftRegDp_u0__16BIT_F1_REG )


    #elif(RecieveShiftReg_SR_SIZE <= 24u) /* 24bit - ShiftReg */
        #define RecieveShiftReg_IN_FIFO_VAL_LSB_PTR        ( (reg32 *) \
                                        RecieveShiftReg_bSR_sC32_BShiftRegDp_u0__F0_REG )

        #define RecieveShiftReg_SHIFT_REG_LSB_PTR          ( (reg32 *) \
                                        RecieveShiftReg_bSR_sC32_BShiftRegDp_u0__A0_REG )

        #define RecieveShiftReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg32 *) \
                                        RecieveShiftReg_bSR_sC32_BShiftRegDp_u0__A1_REG )

        #define RecieveShiftReg_OUT_FIFO_VAL_LSB_PTR       ( (reg32 *) \
                                        RecieveShiftReg_bSR_sC32_BShiftRegDp_u0__F1_REG )

    #else /* 32bit - ShiftReg */
        #define RecieveShiftReg_IN_FIFO_VAL_LSB_PTR        ( (reg32 *) \
                                  RecieveShiftReg_bSR_sC32_BShiftRegDp_u0__32BIT_F0_REG )

        #define RecieveShiftReg_SHIFT_REG_LSB_PTR          ( (reg32 *) \
                                  RecieveShiftReg_bSR_sC32_BShiftRegDp_u0__32BIT_A0_REG )

        #define RecieveShiftReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg32 *) \
                                  RecieveShiftReg_bSR_sC32_BShiftRegDp_u0__32BIT_A1_REG )

        #define RecieveShiftReg_OUT_FIFO_VAL_LSB_PTR       ( (reg32 *) \
                                  RecieveShiftReg_bSR_sC32_BShiftRegDp_u0__32BIT_F1_REG )

    #endif  /* (RecieveShiftReg_SR_SIZE <= 8u) */
#endif      /* (CY_PSOC3 || CY_PSOC5) */


/***************************************
*       Register Constants
***************************************/

#define RecieveShiftReg_INTERRUPTS_ENABLE      (0x10u)
#define RecieveShiftReg_LOAD_INT_EN            (0x01u)
#define RecieveShiftReg_STORE_INT_EN           (0x02u)
#define RecieveShiftReg_RESET_INT_EN           (0x04u)
#define RecieveShiftReg_CLK_EN                 (0x01u)

#define RecieveShiftReg_RESET_INT_EN_MASK      (0xFBu)
#define RecieveShiftReg_LOAD_INT_EN_MASK       (0xFEu)
#define RecieveShiftReg_STORE_INT_EN_MASK      (0xFDu)
#define RecieveShiftReg_INTS_EN_MASK           (0x07u)

#define RecieveShiftReg_OUT_FIFO_CLR_BIT       (0x02u)

#if(0u != RecieveShiftReg_USE_INPUT_FIFO)

    #define RecieveShiftReg_IN_FIFO_MASK       (0x18u)

    #define RecieveShiftReg_IN_FIFO_FULL       (0x00u)
    #define RecieveShiftReg_IN_FIFO_EMPTY      (0x01u)
    #define RecieveShiftReg_IN_FIFO_PARTIAL    (0x02u)
    
    /* This define is obsolete */
    #define RecieveShiftReg_IN_FIFO_NOT_EMPTY  (0x02u)
    
#endif /* (0u != RecieveShiftReg_USE_INPUT_FIFO) */

#define RecieveShiftReg_OUT_FIFO_MASK          (0x60u)

#define RecieveShiftReg_OUT_FIFO_EMPTY         (0x00u)
#define RecieveShiftReg_OUT_FIFO_FULL          (0x01u)
#define RecieveShiftReg_OUT_FIFO_PARTIAL       (0x02u)

/* This define is obsolete */
#define RecieveShiftReg_OUT_FIFO_NOT_EMPTY     (0x02u)

#define RecieveShiftReg_IN_FIFO_SHIFT_MASK     (0x03u)
#define RecieveShiftReg_OUT_FIFO_SHIFT_MASK    (0x05u)

#define RecieveShiftReg_DISABLED               (0u)
#define RecieveShiftReg_DEFAULT_A0             (0u)
#define RecieveShiftReg_DEFAULT_A1             (0u)


/***************************************
*       Macros
***************************************/

#define RecieveShiftReg_IS_ENABLED         (0u != (RecieveShiftReg_SR_CONTROL & RecieveShiftReg_CLK_EN))

#define RecieveShiftReg_GET_OUT_FIFO_STS   ((RecieveShiftReg_SR_STATUS & RecieveShiftReg_OUT_FIFO_MASK) >> \
                                              RecieveShiftReg_OUT_FIFO_SHIFT_MASK)

#define RecieveShiftReg_GET_IN_FIFO_STS    ((RecieveShiftReg_SR_STATUS & RecieveShiftReg_IN_FIFO_MASK)  >> \
                                              RecieveShiftReg_IN_FIFO_SHIFT_MASK)


/***************************************
*       Obsolete
***************************************/

/* Following code are OBSOLETE and must not be used 
 * starting from ShiftReg 2.20 
 */

#define RecieveShiftReg_SR_CONTROL     (RecieveShiftReg_SR_CONTROL_REG)
#define RecieveShiftReg_SR_STATUS      (RecieveShiftReg_SR_STATUS_REG)
#define RecieveShiftReg_SR_STATUS_MASK (RecieveShiftReg_SR_STATUS_MASK_REG)
#define RecieveShiftReg_SR_AUX_CONTROL (RecieveShiftReg_SR_AUX_CONTROL_REG)

#define RecieveShiftReg_IN_FIFO_SHFT_MASK  (RecieveShiftReg_IN_FIFO_SHIFT_MASK)
#define RecieveShiftReg_OUT_FIFO_SHFT_MASK (RecieveShiftReg_OUT_FIFO_SHFIT_MASK)

#define RecieveShiftReg_RET_FIFO_BAD_PARAM (0xFFu)

#endif /* (CY_SHIFTREG_RecieveShiftReg_H) */


/* [] END OF FILE */
