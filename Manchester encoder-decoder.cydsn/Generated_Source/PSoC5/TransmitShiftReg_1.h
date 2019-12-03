/*******************************************************************************
* File Name: TransmitShiftReg_1.h
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


#if !defined(CY_SHIFTREG_TransmitShiftReg_1_H)
#define CY_SHIFTREG_TransmitShiftReg_1_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h"


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define TransmitShiftReg_1_FIFO_SIZE          (4u)
#define TransmitShiftReg_1_USE_INPUT_FIFO     (1u)
#define TransmitShiftReg_1_USE_OUTPUT_FIFO    (0u)
#define TransmitShiftReg_1_SR_SIZE            (32u)


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

} TransmitShiftReg_1_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void  TransmitShiftReg_1_Start(void)                              ;
void  TransmitShiftReg_1_Stop(void)                               ;
void  TransmitShiftReg_1_Init(void)                               ;
void  TransmitShiftReg_1_Enable(void)                             ;
void  TransmitShiftReg_1_RestoreConfig(void)                      ;
void  TransmitShiftReg_1_SaveConfig(void)                         ;
void  TransmitShiftReg_1_Sleep(void)                              ;
void  TransmitShiftReg_1_Wakeup(void)                             ;
void  TransmitShiftReg_1_EnableInt(void)                          ;
void  TransmitShiftReg_1_DisableInt(void)                         ;
void  TransmitShiftReg_1_SetIntMode(uint8 interruptSource)        ;
uint8 TransmitShiftReg_1_GetIntStatus(void)                       ;
void  TransmitShiftReg_1_WriteRegValue(uint32 shiftData) \
                                                                ;
uint32 TransmitShiftReg_1_ReadRegValue(void) ;
uint8    TransmitShiftReg_1_GetFIFOStatus(uint8 fifoId)           ;

#if(0u != TransmitShiftReg_1_USE_INPUT_FIFO)
    cystatus TransmitShiftReg_1_WriteData(uint32 shiftData) \
                                                                ;
#endif /* (0u != TransmitShiftReg_1_USE_INPUT_FIFO) */

#if(0u != TransmitShiftReg_1_USE_OUTPUT_FIFO)
    uint32 TransmitShiftReg_1_ReadData(void) ;
#endif /* (0u != TransmitShiftReg_1_USE_OUTPUT_FIFO) */


/**********************************
*   Variable with external linkage
**********************************/

extern uint8 TransmitShiftReg_1_initVar;


/***************************************
*           API Constants
***************************************/

#define TransmitShiftReg_1_LOAD                   (0x01u)
#define TransmitShiftReg_1_STORE                  (0x02u)
#define TransmitShiftReg_1_RESET                  (0x04u)

#define TransmitShiftReg_1_IN_FIFO                (0x01u)
#define TransmitShiftReg_1_OUT_FIFO               (0x02u)

#define TransmitShiftReg_1_RET_FIFO_FULL          (0x00u)

/* This define is obsolete */
#define TransmitShiftReg_1_RET_FIFO_NOT_EMPTY     (0x01u)

#define TransmitShiftReg_1_RET_FIFO_PARTIAL       (0x01u)
#define TransmitShiftReg_1_RET_FIFO_EMPTY         (0x02u)
#define TransmitShiftReg_1_RET_FIFO_NOT_DEFINED   (0xFEu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define TransmitShiftReg_1__LEFT 0
#define TransmitShiftReg_1__RIGHT 1



/***************************************
*    Initial Parameter Constants
***************************************/

#define TransmitShiftReg_1_SR_MASK    (0xFFFFFFFFu) /* Unsigned is added to parameter */
#define TransmitShiftReg_1_INT_SRC    (1u)
#define TransmitShiftReg_1_DIRECTION  (0u)


/***************************************
*             Registers
***************************************/

/* Control register */
#define TransmitShiftReg_1_SR_CONTROL_REG (* (reg8 *) \
                                           TransmitShiftReg_1_bSR_SyncCtl_CtrlReg__CONTROL_REG)
#define TransmitShiftReg_1_SR_CONTROL_PTR (  (reg8 *) \
                                           TransmitShiftReg_1_bSR_SyncCtl_CtrlReg__CONTROL_REG)

/* Status register */
#define TransmitShiftReg_1_SR_STATUS_REG      (* (reg8 *) TransmitShiftReg_1_bSR_StsReg__STATUS_REG)
#define TransmitShiftReg_1_SR_STATUS_PTR      (  (reg8 *) TransmitShiftReg_1_bSR_StsReg__STATUS_REG)

/* Interrupt status register */
#define TransmitShiftReg_1_SR_STATUS_MASK_REG (* (reg8 *) TransmitShiftReg_1_bSR_StsReg__MASK_REG)
#define TransmitShiftReg_1_SR_STATUS_MASK_PTR (  (reg8 *) TransmitShiftReg_1_bSR_StsReg__MASK_REG)

/* Aux control register */
#define TransmitShiftReg_1_SR_AUX_CONTROL_REG (* (reg8 *) TransmitShiftReg_1_bSR_StsReg__STATUS_AUX_CTL_REG)
#define TransmitShiftReg_1_SR_AUX_CONTROL_PTR (  (reg8 *) TransmitShiftReg_1_bSR_StsReg__STATUS_AUX_CTL_REG)

/* A1 register: only used to implement capture function */
#define TransmitShiftReg_1_SHIFT_REG_CAPTURE_PTR    ( (reg8 *) \
                                        TransmitShiftReg_1_bSR_sC32_BShiftRegDp_u0__A1_REG )

#if(CY_PSOC3 || CY_PSOC5)
    #define TransmitShiftReg_1_IN_FIFO_VAL_LSB_PTR        ( (reg32 *) \
                                        TransmitShiftReg_1_bSR_sC32_BShiftRegDp_u0__F0_REG )

    #define TransmitShiftReg_1_SHIFT_REG_LSB_PTR          ( (reg32 *) \
                                        TransmitShiftReg_1_bSR_sC32_BShiftRegDp_u0__A0_REG )

    #define TransmitShiftReg_1_SHIFT_REG_VALUE_LSB_PTR    ( (reg32 *) \
                                        TransmitShiftReg_1_bSR_sC32_BShiftRegDp_u0__A1_REG )

    #define TransmitShiftReg_1_OUT_FIFO_VAL_LSB_PTR       ( (reg32 *) \
                                        TransmitShiftReg_1_bSR_sC32_BShiftRegDp_u0__F1_REG )

#else
    #if(TransmitShiftReg_1_SR_SIZE <= 8u) /* 8bit - ShiftReg */
        #define TransmitShiftReg_1_IN_FIFO_VAL_LSB_PTR        ( (reg8 *) \
                                        TransmitShiftReg_1_bSR_sC32_BShiftRegDp_u0__F0_REG )

        #define TransmitShiftReg_1_SHIFT_REG_LSB_PTR          ( (reg8 *) \
                                        TransmitShiftReg_1_bSR_sC32_BShiftRegDp_u0__A0_REG )

        #define TransmitShiftReg_1_SHIFT_REG_VALUE_LSB_PTR    ( (reg8 *) \
                                        TransmitShiftReg_1_bSR_sC32_BShiftRegDp_u0__A1_REG )

        #define TransmitShiftReg_1_OUT_FIFO_VAL_LSB_PTR       ( (reg8 *) \
                                        TransmitShiftReg_1_bSR_sC32_BShiftRegDp_u0__F1_REG )

    #elif(TransmitShiftReg_1_SR_SIZE <= 16u) /* 16bit - ShiftReg */
        #define TransmitShiftReg_1_IN_FIFO_VAL_LSB_PTR        ( (reg16 *) \
                                  TransmitShiftReg_1_bSR_sC32_BShiftRegDp_u0__16BIT_F0_REG )

        #define TransmitShiftReg_1_SHIFT_REG_LSB_PTR          ( (reg16 *) \
                                  TransmitShiftReg_1_bSR_sC32_BShiftRegDp_u0__16BIT_A0_REG )

        #define TransmitShiftReg_1_SHIFT_REG_VALUE_LSB_PTR    ( (reg16 *) \
                                  TransmitShiftReg_1_bSR_sC32_BShiftRegDp_u0__16BIT_A1_REG )

        #define TransmitShiftReg_1_OUT_FIFO_VAL_LSB_PTR       ( (reg16 *) \
                                  TransmitShiftReg_1_bSR_sC32_BShiftRegDp_u0__16BIT_F1_REG )


    #elif(TransmitShiftReg_1_SR_SIZE <= 24u) /* 24bit - ShiftReg */
        #define TransmitShiftReg_1_IN_FIFO_VAL_LSB_PTR        ( (reg32 *) \
                                        TransmitShiftReg_1_bSR_sC32_BShiftRegDp_u0__F0_REG )

        #define TransmitShiftReg_1_SHIFT_REG_LSB_PTR          ( (reg32 *) \
                                        TransmitShiftReg_1_bSR_sC32_BShiftRegDp_u0__A0_REG )

        #define TransmitShiftReg_1_SHIFT_REG_VALUE_LSB_PTR    ( (reg32 *) \
                                        TransmitShiftReg_1_bSR_sC32_BShiftRegDp_u0__A1_REG )

        #define TransmitShiftReg_1_OUT_FIFO_VAL_LSB_PTR       ( (reg32 *) \
                                        TransmitShiftReg_1_bSR_sC32_BShiftRegDp_u0__F1_REG )

    #else /* 32bit - ShiftReg */
        #define TransmitShiftReg_1_IN_FIFO_VAL_LSB_PTR        ( (reg32 *) \
                                  TransmitShiftReg_1_bSR_sC32_BShiftRegDp_u0__32BIT_F0_REG )

        #define TransmitShiftReg_1_SHIFT_REG_LSB_PTR          ( (reg32 *) \
                                  TransmitShiftReg_1_bSR_sC32_BShiftRegDp_u0__32BIT_A0_REG )

        #define TransmitShiftReg_1_SHIFT_REG_VALUE_LSB_PTR    ( (reg32 *) \
                                  TransmitShiftReg_1_bSR_sC32_BShiftRegDp_u0__32BIT_A1_REG )

        #define TransmitShiftReg_1_OUT_FIFO_VAL_LSB_PTR       ( (reg32 *) \
                                  TransmitShiftReg_1_bSR_sC32_BShiftRegDp_u0__32BIT_F1_REG )

    #endif  /* (TransmitShiftReg_1_SR_SIZE <= 8u) */
#endif      /* (CY_PSOC3 || CY_PSOC5) */


/***************************************
*       Register Constants
***************************************/

#define TransmitShiftReg_1_INTERRUPTS_ENABLE      (0x10u)
#define TransmitShiftReg_1_LOAD_INT_EN            (0x01u)
#define TransmitShiftReg_1_STORE_INT_EN           (0x02u)
#define TransmitShiftReg_1_RESET_INT_EN           (0x04u)
#define TransmitShiftReg_1_CLK_EN                 (0x01u)

#define TransmitShiftReg_1_RESET_INT_EN_MASK      (0xFBu)
#define TransmitShiftReg_1_LOAD_INT_EN_MASK       (0xFEu)
#define TransmitShiftReg_1_STORE_INT_EN_MASK      (0xFDu)
#define TransmitShiftReg_1_INTS_EN_MASK           (0x07u)

#define TransmitShiftReg_1_OUT_FIFO_CLR_BIT       (0x02u)

#if(0u != TransmitShiftReg_1_USE_INPUT_FIFO)

    #define TransmitShiftReg_1_IN_FIFO_MASK       (0x18u)

    #define TransmitShiftReg_1_IN_FIFO_FULL       (0x00u)
    #define TransmitShiftReg_1_IN_FIFO_EMPTY      (0x01u)
    #define TransmitShiftReg_1_IN_FIFO_PARTIAL    (0x02u)
    
    /* This define is obsolete */
    #define TransmitShiftReg_1_IN_FIFO_NOT_EMPTY  (0x02u)
    
#endif /* (0u != TransmitShiftReg_1_USE_INPUT_FIFO) */

#define TransmitShiftReg_1_OUT_FIFO_MASK          (0x60u)

#define TransmitShiftReg_1_OUT_FIFO_EMPTY         (0x00u)
#define TransmitShiftReg_1_OUT_FIFO_FULL          (0x01u)
#define TransmitShiftReg_1_OUT_FIFO_PARTIAL       (0x02u)

/* This define is obsolete */
#define TransmitShiftReg_1_OUT_FIFO_NOT_EMPTY     (0x02u)

#define TransmitShiftReg_1_IN_FIFO_SHIFT_MASK     (0x03u)
#define TransmitShiftReg_1_OUT_FIFO_SHIFT_MASK    (0x05u)

#define TransmitShiftReg_1_DISABLED               (0u)
#define TransmitShiftReg_1_DEFAULT_A0             (0u)
#define TransmitShiftReg_1_DEFAULT_A1             (0u)


/***************************************
*       Macros
***************************************/

#define TransmitShiftReg_1_IS_ENABLED         (0u != (TransmitShiftReg_1_SR_CONTROL & TransmitShiftReg_1_CLK_EN))

#define TransmitShiftReg_1_GET_OUT_FIFO_STS   ((TransmitShiftReg_1_SR_STATUS & TransmitShiftReg_1_OUT_FIFO_MASK) >> \
                                              TransmitShiftReg_1_OUT_FIFO_SHIFT_MASK)

#define TransmitShiftReg_1_GET_IN_FIFO_STS    ((TransmitShiftReg_1_SR_STATUS & TransmitShiftReg_1_IN_FIFO_MASK)  >> \
                                              TransmitShiftReg_1_IN_FIFO_SHIFT_MASK)


/***************************************
*       Obsolete
***************************************/

/* Following code are OBSOLETE and must not be used 
 * starting from ShiftReg 2.20 
 */

#define TransmitShiftReg_1_SR_CONTROL     (TransmitShiftReg_1_SR_CONTROL_REG)
#define TransmitShiftReg_1_SR_STATUS      (TransmitShiftReg_1_SR_STATUS_REG)
#define TransmitShiftReg_1_SR_STATUS_MASK (TransmitShiftReg_1_SR_STATUS_MASK_REG)
#define TransmitShiftReg_1_SR_AUX_CONTROL (TransmitShiftReg_1_SR_AUX_CONTROL_REG)

#define TransmitShiftReg_1_IN_FIFO_SHFT_MASK  (TransmitShiftReg_1_IN_FIFO_SHIFT_MASK)
#define TransmitShiftReg_1_OUT_FIFO_SHFT_MASK (TransmitShiftReg_1_OUT_FIFO_SHFIT_MASK)

#define TransmitShiftReg_1_RET_FIFO_BAD_PARAM (0xFFu)

#endif /* (CY_SHIFTREG_TransmitShiftReg_1_H) */


/* [] END OF FILE */
