/*******************************************************************************
* File Name: SigmaReg.h
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


#if !defined(CY_SHIFTREG_SigmaReg_H)
#define CY_SHIFTREG_SigmaReg_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h"


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define SigmaReg_FIFO_SIZE          (4u)
#define SigmaReg_USE_INPUT_FIFO     (0u)
#define SigmaReg_USE_OUTPUT_FIFO    (0u)
#define SigmaReg_SR_SIZE            (32u)


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

} SigmaReg_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void  SigmaReg_Start(void)                              ;
void  SigmaReg_Stop(void)                               ;
void  SigmaReg_Init(void)                               ;
void  SigmaReg_Enable(void)                             ;
void  SigmaReg_RestoreConfig(void)                      ;
void  SigmaReg_SaveConfig(void)                         ;
void  SigmaReg_Sleep(void)                              ;
void  SigmaReg_Wakeup(void)                             ;
void  SigmaReg_EnableInt(void)                          ;
void  SigmaReg_DisableInt(void)                         ;
void  SigmaReg_SetIntMode(uint8 interruptSource)        ;
uint8 SigmaReg_GetIntStatus(void)                       ;
void  SigmaReg_WriteRegValue(uint32 shiftData) \
                                                                ;
uint32 SigmaReg_ReadRegValue(void) ;
uint8    SigmaReg_GetFIFOStatus(uint8 fifoId)           ;

#if(0u != SigmaReg_USE_INPUT_FIFO)
    cystatus SigmaReg_WriteData(uint32 shiftData) \
                                                                ;
#endif /* (0u != SigmaReg_USE_INPUT_FIFO) */

#if(0u != SigmaReg_USE_OUTPUT_FIFO)
    uint32 SigmaReg_ReadData(void) ;
#endif /* (0u != SigmaReg_USE_OUTPUT_FIFO) */


/**********************************
*   Variable with external linkage
**********************************/

extern uint8 SigmaReg_initVar;


/***************************************
*           API Constants
***************************************/

#define SigmaReg_LOAD                   (0x01u)
#define SigmaReg_STORE                  (0x02u)
#define SigmaReg_RESET                  (0x04u)

#define SigmaReg_IN_FIFO                (0x01u)
#define SigmaReg_OUT_FIFO               (0x02u)

#define SigmaReg_RET_FIFO_FULL          (0x00u)

/* This define is obsolete */
#define SigmaReg_RET_FIFO_NOT_EMPTY     (0x01u)

#define SigmaReg_RET_FIFO_PARTIAL       (0x01u)
#define SigmaReg_RET_FIFO_EMPTY         (0x02u)
#define SigmaReg_RET_FIFO_NOT_DEFINED   (0xFEu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define SigmaReg__LEFT 0
#define SigmaReg__RIGHT 1



/***************************************
*    Initial Parameter Constants
***************************************/

#define SigmaReg_SR_MASK    (0xFFFFFFFFu) /* Unsigned is added to parameter */
#define SigmaReg_INT_SRC    (0u)
#define SigmaReg_DIRECTION  (1u)


/***************************************
*             Registers
***************************************/

/* Control register */
#define SigmaReg_SR_CONTROL_REG (* (reg8 *) \
                                           SigmaReg_bSR_SyncCtl_CtrlReg__CONTROL_REG)
#define SigmaReg_SR_CONTROL_PTR (  (reg8 *) \
                                           SigmaReg_bSR_SyncCtl_CtrlReg__CONTROL_REG)

/* Status register */
#define SigmaReg_SR_STATUS_REG      (* (reg8 *) SigmaReg_bSR_StsReg__STATUS_REG)
#define SigmaReg_SR_STATUS_PTR      (  (reg8 *) SigmaReg_bSR_StsReg__STATUS_REG)

/* Interrupt status register */
#define SigmaReg_SR_STATUS_MASK_REG (* (reg8 *) SigmaReg_bSR_StsReg__MASK_REG)
#define SigmaReg_SR_STATUS_MASK_PTR (  (reg8 *) SigmaReg_bSR_StsReg__MASK_REG)

/* Aux control register */
#define SigmaReg_SR_AUX_CONTROL_REG (* (reg8 *) SigmaReg_bSR_StsReg__STATUS_AUX_CTL_REG)
#define SigmaReg_SR_AUX_CONTROL_PTR (  (reg8 *) SigmaReg_bSR_StsReg__STATUS_AUX_CTL_REG)

/* A1 register: only used to implement capture function */
#define SigmaReg_SHIFT_REG_CAPTURE_PTR    ( (reg8 *) \
                                        SigmaReg_bSR_sC32_BShiftRegDp_u0__A1_REG )

#if(CY_PSOC3 || CY_PSOC5)
    #define SigmaReg_IN_FIFO_VAL_LSB_PTR        ( (reg32 *) \
                                        SigmaReg_bSR_sC32_BShiftRegDp_u0__F0_REG )

    #define SigmaReg_SHIFT_REG_LSB_PTR          ( (reg32 *) \
                                        SigmaReg_bSR_sC32_BShiftRegDp_u0__A0_REG )

    #define SigmaReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg32 *) \
                                        SigmaReg_bSR_sC32_BShiftRegDp_u0__A1_REG )

    #define SigmaReg_OUT_FIFO_VAL_LSB_PTR       ( (reg32 *) \
                                        SigmaReg_bSR_sC32_BShiftRegDp_u0__F1_REG )

#else
    #if(SigmaReg_SR_SIZE <= 8u) /* 8bit - ShiftReg */
        #define SigmaReg_IN_FIFO_VAL_LSB_PTR        ( (reg8 *) \
                                        SigmaReg_bSR_sC32_BShiftRegDp_u0__F0_REG )

        #define SigmaReg_SHIFT_REG_LSB_PTR          ( (reg8 *) \
                                        SigmaReg_bSR_sC32_BShiftRegDp_u0__A0_REG )

        #define SigmaReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg8 *) \
                                        SigmaReg_bSR_sC32_BShiftRegDp_u0__A1_REG )

        #define SigmaReg_OUT_FIFO_VAL_LSB_PTR       ( (reg8 *) \
                                        SigmaReg_bSR_sC32_BShiftRegDp_u0__F1_REG )

    #elif(SigmaReg_SR_SIZE <= 16u) /* 16bit - ShiftReg */
        #define SigmaReg_IN_FIFO_VAL_LSB_PTR        ( (reg16 *) \
                                  SigmaReg_bSR_sC32_BShiftRegDp_u0__16BIT_F0_REG )

        #define SigmaReg_SHIFT_REG_LSB_PTR          ( (reg16 *) \
                                  SigmaReg_bSR_sC32_BShiftRegDp_u0__16BIT_A0_REG )

        #define SigmaReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg16 *) \
                                  SigmaReg_bSR_sC32_BShiftRegDp_u0__16BIT_A1_REG )

        #define SigmaReg_OUT_FIFO_VAL_LSB_PTR       ( (reg16 *) \
                                  SigmaReg_bSR_sC32_BShiftRegDp_u0__16BIT_F1_REG )


    #elif(SigmaReg_SR_SIZE <= 24u) /* 24bit - ShiftReg */
        #define SigmaReg_IN_FIFO_VAL_LSB_PTR        ( (reg32 *) \
                                        SigmaReg_bSR_sC32_BShiftRegDp_u0__F0_REG )

        #define SigmaReg_SHIFT_REG_LSB_PTR          ( (reg32 *) \
                                        SigmaReg_bSR_sC32_BShiftRegDp_u0__A0_REG )

        #define SigmaReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg32 *) \
                                        SigmaReg_bSR_sC32_BShiftRegDp_u0__A1_REG )

        #define SigmaReg_OUT_FIFO_VAL_LSB_PTR       ( (reg32 *) \
                                        SigmaReg_bSR_sC32_BShiftRegDp_u0__F1_REG )

    #else /* 32bit - ShiftReg */
        #define SigmaReg_IN_FIFO_VAL_LSB_PTR        ( (reg32 *) \
                                  SigmaReg_bSR_sC32_BShiftRegDp_u0__32BIT_F0_REG )

        #define SigmaReg_SHIFT_REG_LSB_PTR          ( (reg32 *) \
                                  SigmaReg_bSR_sC32_BShiftRegDp_u0__32BIT_A0_REG )

        #define SigmaReg_SHIFT_REG_VALUE_LSB_PTR    ( (reg32 *) \
                                  SigmaReg_bSR_sC32_BShiftRegDp_u0__32BIT_A1_REG )

        #define SigmaReg_OUT_FIFO_VAL_LSB_PTR       ( (reg32 *) \
                                  SigmaReg_bSR_sC32_BShiftRegDp_u0__32BIT_F1_REG )

    #endif  /* (SigmaReg_SR_SIZE <= 8u) */
#endif      /* (CY_PSOC3 || CY_PSOC5) */


/***************************************
*       Register Constants
***************************************/

#define SigmaReg_INTERRUPTS_ENABLE      (0x10u)
#define SigmaReg_LOAD_INT_EN            (0x01u)
#define SigmaReg_STORE_INT_EN           (0x02u)
#define SigmaReg_RESET_INT_EN           (0x04u)
#define SigmaReg_CLK_EN                 (0x01u)

#define SigmaReg_RESET_INT_EN_MASK      (0xFBu)
#define SigmaReg_LOAD_INT_EN_MASK       (0xFEu)
#define SigmaReg_STORE_INT_EN_MASK      (0xFDu)
#define SigmaReg_INTS_EN_MASK           (0x07u)

#define SigmaReg_OUT_FIFO_CLR_BIT       (0x02u)

#if(0u != SigmaReg_USE_INPUT_FIFO)

    #define SigmaReg_IN_FIFO_MASK       (0x18u)

    #define SigmaReg_IN_FIFO_FULL       (0x00u)
    #define SigmaReg_IN_FIFO_EMPTY      (0x01u)
    #define SigmaReg_IN_FIFO_PARTIAL    (0x02u)
    
    /* This define is obsolete */
    #define SigmaReg_IN_FIFO_NOT_EMPTY  (0x02u)
    
#endif /* (0u != SigmaReg_USE_INPUT_FIFO) */

#define SigmaReg_OUT_FIFO_MASK          (0x60u)

#define SigmaReg_OUT_FIFO_EMPTY         (0x00u)
#define SigmaReg_OUT_FIFO_FULL          (0x01u)
#define SigmaReg_OUT_FIFO_PARTIAL       (0x02u)

/* This define is obsolete */
#define SigmaReg_OUT_FIFO_NOT_EMPTY     (0x02u)

#define SigmaReg_IN_FIFO_SHIFT_MASK     (0x03u)
#define SigmaReg_OUT_FIFO_SHIFT_MASK    (0x05u)

#define SigmaReg_DISABLED               (0u)
#define SigmaReg_DEFAULT_A0             (0u)
#define SigmaReg_DEFAULT_A1             (0u)


/***************************************
*       Macros
***************************************/

#define SigmaReg_IS_ENABLED         (0u != (SigmaReg_SR_CONTROL & SigmaReg_CLK_EN))

#define SigmaReg_GET_OUT_FIFO_STS   ((SigmaReg_SR_STATUS & SigmaReg_OUT_FIFO_MASK) >> \
                                              SigmaReg_OUT_FIFO_SHIFT_MASK)

#define SigmaReg_GET_IN_FIFO_STS    ((SigmaReg_SR_STATUS & SigmaReg_IN_FIFO_MASK)  >> \
                                              SigmaReg_IN_FIFO_SHIFT_MASK)


/***************************************
*       Obsolete
***************************************/

/* Following code are OBSOLETE and must not be used 
 * starting from ShiftReg 2.20 
 */

#define SigmaReg_SR_CONTROL     (SigmaReg_SR_CONTROL_REG)
#define SigmaReg_SR_STATUS      (SigmaReg_SR_STATUS_REG)
#define SigmaReg_SR_STATUS_MASK (SigmaReg_SR_STATUS_MASK_REG)
#define SigmaReg_SR_AUX_CONTROL (SigmaReg_SR_AUX_CONTROL_REG)

#define SigmaReg_IN_FIFO_SHFT_MASK  (SigmaReg_IN_FIFO_SHIFT_MASK)
#define SigmaReg_OUT_FIFO_SHFT_MASK (SigmaReg_OUT_FIFO_SHFIT_MASK)

#define SigmaReg_RET_FIFO_BAD_PARAM (0xFFu)

#endif /* (CY_SHIFTREG_SigmaReg_H) */


/* [] END OF FILE */
