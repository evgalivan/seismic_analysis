/*******************************************************************************
* File Name: DeltaReg.h
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


#if !defined(CY_SHIFTREG_DeltaReg_H)
#define CY_SHIFTREG_DeltaReg_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h"


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define DeltaReg_FIFO_SIZE          (4u)
#define DeltaReg_USE_INPUT_FIFO     (1u)
#define DeltaReg_USE_OUTPUT_FIFO    (0u)
#define DeltaReg_SR_SIZE            (32u)


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

} DeltaReg_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void  DeltaReg_Start(void)                              ;
void  DeltaReg_Stop(void)                               ;
void  DeltaReg_Init(void)                               ;
void  DeltaReg_Enable(void)                             ;
void  DeltaReg_RestoreConfig(void)                      ;
void  DeltaReg_SaveConfig(void)                         ;
void  DeltaReg_Sleep(void)                              ;
void  DeltaReg_Wakeup(void)                             ;
void  DeltaReg_EnableInt(void)                          ;
void  DeltaReg_DisableInt(void)                         ;
void  DeltaReg_SetIntMode(uint8 interruptSource)        ;
uint8 DeltaReg_GetIntStatus(void)                       ;
void  DeltaReg_WriteRegValue(uint32 shiftData) \
                                                                ;
uint32 DeltaReg_ReadRegValue(void) ;
uint8    DeltaReg_GetFIFOStatus(uint8 fifoId)           ;

#if(0u != DeltaReg_USE_INPUT_FIFO)
    cystatus DeltaReg_WriteData(uint32 shiftData) \
                                                                ;
#endif /* (0u != DeltaReg_USE_INPUT_FIFO) */

#if(0u != DeltaReg_USE_OUTPUT_FIFO)
    uint32 DeltaReg_ReadData(void) ;
#endif /* (0u != DeltaReg_USE_OUTPUT_FIFO) */


/**********************************
*   Variable with external linkage
**********************************/

extern uint8 DeltaReg_initVar;


/***************************************
*           API Constants
***************************************/

#define DeltaReg_LOAD                   (0x01u)
#define DeltaReg_STORE                  (0x02u)
#define DeltaReg_RESET                  (0x04u)

#define DeltaReg_IN_FIFO                (0x01u)
#define DeltaReg_OUT_FIFO               (0x02u)

#define DeltaReg_RET_FIFO_FULL          (0x00u)

/* This define is obsolete */
#define DeltaReg_RET_FIFO_NOT_EMPTY     (0x01u)

#define DeltaReg_RET_FIFO_PARTIAL       (0x01u)
#define DeltaReg_RET_FIFO_EMPTY         (0x02u)
#define DeltaReg_RET_FIFO_NOT_DEFINED   (0xFEu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define DeltaReg__LEFT 0
#define DeltaReg__RIGHT 1



/***************************************
*    Initial Parameter Constants
***************************************/

#define DeltaReg_SR_MASK    (0xFFFFFFFFu) /* Unsigned is added to parameter */
#define DeltaReg_INT_SRC    (1u)
#define DeltaReg_DIRECTION  (1u)


/***************************************
*             Registers
***************************************/

/* Control register */
#define DeltaReg_SR_CONTROL_REG (* (reg8 *) \
                                           DeltaReg_bSR_SyncCtl_CtrlReg__CONTROL_REG)
#define DeltaReg_SR_CONTROL_PTR (  (reg8 *) \
                                           DeltaReg_bSR_SyncCtl_CtrlReg__CONTROL_REG)

/* Status register */
#define DeltaReg_SR_STATUS_REG      (* (reg8 *) DeltaReg_bSR_StsReg__STATUS_REG)
#define DeltaReg_SR_STATUS_PTR      (  (reg8 *) DeltaReg_bSR_StsReg__STATUS_REG)

/* Interrupt status register */
#define DeltaReg_SR_STATUS_MASK_REG (* (reg8 *) DeltaReg_bSR_StsReg__MASK_REG)
#define DeltaReg_SR_STATUS_MASK_PTR (  (reg8 *) DeltaReg_bSR_StsReg__MASK_REG)

/* Aux control register */
#define DeltaReg_SR_AUX_CONTROL_REG (* (reg8 *) DeltaReg_bSR_StsReg__STATUS_AUX_CTL_REG)
#define DeltaReg_SR_AUX_CONTROL_PTR (  (reg8 *) DeltaReg_bSR_StsReg__STATUS_AUX_CTL_REG)

/* A1 register: only used to implement capture function */
#define DeltaReg_SHIFT_REG_CAPTURE_PTR    ( (reg8 *) \
                                        DeltaReg_bSR_sC32_BShiftRegDp_u0__A1_REG )

#if(CY_PSOC3 || CY_PSOC5)
    #define DeltaReg_IN_FIFO_VAL_LSB_PTR        ( (reg32 *) \
                                        DeltaReg_bSR_sC32_BShiftRegDp_u0__F0_REG )

    #define DeltaReg_SHIFT_REG_LSB_PTR          ( (reg32 *) \
                                        DeltaReg_bSR_sC32_BShiftRegDp_u0__A0_REG )

    #define DeltaReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg32 *) \
                                        DeltaReg_bSR_sC32_BShiftRegDp_u0__A1_REG )

    #define DeltaReg_OUT_FIFO_VAL_LSB_PTR       ( (reg32 *) \
                                        DeltaReg_bSR_sC32_BShiftRegDp_u0__F1_REG )

#else
    #if(DeltaReg_SR_SIZE <= 8u) /* 8bit - ShiftReg */
        #define DeltaReg_IN_FIFO_VAL_LSB_PTR        ( (reg8 *) \
                                        DeltaReg_bSR_sC32_BShiftRegDp_u0__F0_REG )

        #define DeltaReg_SHIFT_REG_LSB_PTR          ( (reg8 *) \
                                        DeltaReg_bSR_sC32_BShiftRegDp_u0__A0_REG )

        #define DeltaReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg8 *) \
                                        DeltaReg_bSR_sC32_BShiftRegDp_u0__A1_REG )

        #define DeltaReg_OUT_FIFO_VAL_LSB_PTR       ( (reg8 *) \
                                        DeltaReg_bSR_sC32_BShiftRegDp_u0__F1_REG )

    #elif(DeltaReg_SR_SIZE <= 16u) /* 16bit - ShiftReg */
        #define DeltaReg_IN_FIFO_VAL_LSB_PTR        ( (reg16 *) \
                                  DeltaReg_bSR_sC32_BShiftRegDp_u0__16BIT_F0_REG )

        #define DeltaReg_SHIFT_REG_LSB_PTR          ( (reg16 *) \
                                  DeltaReg_bSR_sC32_BShiftRegDp_u0__16BIT_A0_REG )

        #define DeltaReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg16 *) \
                                  DeltaReg_bSR_sC32_BShiftRegDp_u0__16BIT_A1_REG )

        #define DeltaReg_OUT_FIFO_VAL_LSB_PTR       ( (reg16 *) \
                                  DeltaReg_bSR_sC32_BShiftRegDp_u0__16BIT_F1_REG )


    #elif(DeltaReg_SR_SIZE <= 24u) /* 24bit - ShiftReg */
        #define DeltaReg_IN_FIFO_VAL_LSB_PTR        ( (reg32 *) \
                                        DeltaReg_bSR_sC32_BShiftRegDp_u0__F0_REG )

        #define DeltaReg_SHIFT_REG_LSB_PTR          ( (reg32 *) \
                                        DeltaReg_bSR_sC32_BShiftRegDp_u0__A0_REG )

        #define DeltaReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg32 *) \
                                        DeltaReg_bSR_sC32_BShiftRegDp_u0__A1_REG )

        #define DeltaReg_OUT_FIFO_VAL_LSB_PTR       ( (reg32 *) \
                                        DeltaReg_bSR_sC32_BShiftRegDp_u0__F1_REG )

    #else /* 32bit - ShiftReg */
        #define DeltaReg_IN_FIFO_VAL_LSB_PTR        ( (reg32 *) \
                                  DeltaReg_bSR_sC32_BShiftRegDp_u0__32BIT_F0_REG )

        #define DeltaReg_SHIFT_REG_LSB_PTR          ( (reg32 *) \
                                  DeltaReg_bSR_sC32_BShiftRegDp_u0__32BIT_A0_REG )

        #define DeltaReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg32 *) \
                                  DeltaReg_bSR_sC32_BShiftRegDp_u0__32BIT_A1_REG )

        #define DeltaReg_OUT_FIFO_VAL_LSB_PTR       ( (reg32 *) \
                                  DeltaReg_bSR_sC32_BShiftRegDp_u0__32BIT_F1_REG )

    #endif  /* (DeltaReg_SR_SIZE <= 8u) */
#endif      /* (CY_PSOC3 || CY_PSOC5) */


/***************************************
*       Register Constants
***************************************/

#define DeltaReg_INTERRUPTS_ENABLE      (0x10u)
#define DeltaReg_LOAD_INT_EN            (0x01u)
#define DeltaReg_STORE_INT_EN           (0x02u)
#define DeltaReg_RESET_INT_EN           (0x04u)
#define DeltaReg_CLK_EN                 (0x01u)

#define DeltaReg_RESET_INT_EN_MASK      (0xFBu)
#define DeltaReg_LOAD_INT_EN_MASK       (0xFEu)
#define DeltaReg_STORE_INT_EN_MASK      (0xFDu)
#define DeltaReg_INTS_EN_MASK           (0x07u)

#define DeltaReg_OUT_FIFO_CLR_BIT       (0x02u)

#if(0u != DeltaReg_USE_INPUT_FIFO)

    #define DeltaReg_IN_FIFO_MASK       (0x18u)

    #define DeltaReg_IN_FIFO_FULL       (0x00u)
    #define DeltaReg_IN_FIFO_EMPTY      (0x01u)
    #define DeltaReg_IN_FIFO_PARTIAL    (0x02u)
    
    /* This define is obsolete */
    #define DeltaReg_IN_FIFO_NOT_EMPTY  (0x02u)
    
#endif /* (0u != DeltaReg_USE_INPUT_FIFO) */

#define DeltaReg_OUT_FIFO_MASK          (0x60u)

#define DeltaReg_OUT_FIFO_EMPTY         (0x00u)
#define DeltaReg_OUT_FIFO_FULL          (0x01u)
#define DeltaReg_OUT_FIFO_PARTIAL       (0x02u)

/* This define is obsolete */
#define DeltaReg_OUT_FIFO_NOT_EMPTY     (0x02u)

#define DeltaReg_IN_FIFO_SHIFT_MASK     (0x03u)
#define DeltaReg_OUT_FIFO_SHIFT_MASK    (0x05u)

#define DeltaReg_DISABLED               (0u)
#define DeltaReg_DEFAULT_A0             (0u)
#define DeltaReg_DEFAULT_A1             (0u)


/***************************************
*       Macros
***************************************/

#define DeltaReg_IS_ENABLED         (0u != (DeltaReg_SR_CONTROL & DeltaReg_CLK_EN))

#define DeltaReg_GET_OUT_FIFO_STS   ((DeltaReg_SR_STATUS & DeltaReg_OUT_FIFO_MASK) >> \
                                              DeltaReg_OUT_FIFO_SHIFT_MASK)

#define DeltaReg_GET_IN_FIFO_STS    ((DeltaReg_SR_STATUS & DeltaReg_IN_FIFO_MASK)  >> \
                                              DeltaReg_IN_FIFO_SHIFT_MASK)


/***************************************
*       Obsolete
***************************************/

/* Following code are OBSOLETE and must not be used 
 * starting from ShiftReg 2.20 
 */

#define DeltaReg_SR_CONTROL     (DeltaReg_SR_CONTROL_REG)
#define DeltaReg_SR_STATUS      (DeltaReg_SR_STATUS_REG)
#define DeltaReg_SR_STATUS_MASK (DeltaReg_SR_STATUS_MASK_REG)
#define DeltaReg_SR_AUX_CONTROL (DeltaReg_SR_AUX_CONTROL_REG)

#define DeltaReg_IN_FIFO_SHFT_MASK  (DeltaReg_IN_FIFO_SHIFT_MASK)
#define DeltaReg_OUT_FIFO_SHFT_MASK (DeltaReg_OUT_FIFO_SHFIT_MASK)

#define DeltaReg_RET_FIFO_BAD_PARAM (0xFFu)

#endif /* (CY_SHIFTREG_DeltaReg_H) */


/* [] END OF FILE */
