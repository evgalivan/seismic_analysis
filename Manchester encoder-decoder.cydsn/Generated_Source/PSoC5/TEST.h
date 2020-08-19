/*******************************************************************************
* File Name: TEST.h
* Version 3.30
*
* Description:
*  Contains the prototypes and constants for the functions available to the
*  PWM user module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PWM_TEST_H)
#define CY_PWM_TEST_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 TEST_initVar;


/***************************************
* Conditional Compilation Parameters
***************************************/
#define TEST_Resolution                     (16u)
#define TEST_UsingFixedFunction             (0u)
#define TEST_DeadBandMode                   (1u)
#define TEST_KillModeMinTime                (0u)
#define TEST_KillMode                       (1u)
#define TEST_PWMMode                        (1u)
#define TEST_PWMModeIsCenterAligned         (0u)
#define TEST_DeadBandUsed                   (1u)
#define TEST_DeadBand2_4                    (1u)

#if !defined(TEST_PWMUDB_genblk8_stsreg__REMOVED)
    #define TEST_UseStatus                  (1u)
#else
    #define TEST_UseStatus                  (0u)
#endif /* !defined(TEST_PWMUDB_genblk8_stsreg__REMOVED) */

#if !defined(TEST_PWMUDB_genblk1_ctrlreg__REMOVED)
    #define TEST_UseControl                 (1u)
#else
    #define TEST_UseControl                 (0u)
#endif /* !defined(TEST_PWMUDB_genblk1_ctrlreg__REMOVED) */

#define TEST_UseOneCompareMode              (0u)
#define TEST_MinimumKillTime                (1u)
#define TEST_EnableMode                     (0u)

#define TEST_CompareMode1SW                 (0u)
#define TEST_CompareMode2SW                 (0u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PWM_v3_30 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Use Kill Mode Enumerated Types */
#define TEST__B_PWM__DISABLED 0
#define TEST__B_PWM__ASYNCHRONOUS 1
#define TEST__B_PWM__SINGLECYCLE 2
#define TEST__B_PWM__LATCHED 3
#define TEST__B_PWM__MINTIME 4


/* Use Dead Band Mode Enumerated Types */
#define TEST__B_PWM__DBMDISABLED 0
#define TEST__B_PWM__DBM_2_4_CLOCKS 1
#define TEST__B_PWM__DBM_256_CLOCKS 2


/* Used PWM Mode Enumerated Types */
#define TEST__B_PWM__ONE_OUTPUT 0
#define TEST__B_PWM__TWO_OUTPUTS 1
#define TEST__B_PWM__DUAL_EDGE 2
#define TEST__B_PWM__CENTER_ALIGN 3
#define TEST__B_PWM__DITHER 5
#define TEST__B_PWM__HARDWARESELECT 4


/* Used PWM Compare Mode Enumerated Types */
#define TEST__B_PWM__LESS_THAN 1
#define TEST__B_PWM__LESS_THAN_OR_EQUAL 2
#define TEST__B_PWM__GREATER_THAN 3
#define TEST__B_PWM__GREATER_THAN_OR_EQUAL_TO 4
#define TEST__B_PWM__EQUAL 0
#define TEST__B_PWM__FIRMWARE 5



/***************************************
* Data Struct Definition
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for PWM Component
 *************************************************************************/
typedef struct
{

    uint8 PWMEnableState;

    #if(!TEST_UsingFixedFunction)
        uint16 PWMUdb;               /* PWM Current Counter value  */
        #if(!TEST_PWMModeIsCenterAligned)
            uint16 PWMPeriod;
        #endif /* (!TEST_PWMModeIsCenterAligned) */
        #if (TEST_UseStatus)
            uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
        #endif /* (TEST_UseStatus) */

        /* Backup for Deadband parameters */
        #if(TEST_DeadBandMode == TEST__B_PWM__DBM_256_CLOCKS || \
            TEST_DeadBandMode == TEST__B_PWM__DBM_2_4_CLOCKS)
            uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
        #endif /* deadband count is either 2-4 clocks or 256 clocks */

        /* Backup Kill Mode Counter*/
        #if(TEST_KillModeMinTime)
            uint8 PWMKillCounterPeriod; /* Kill Mode period value */
        #endif /* (TEST_KillModeMinTime) */

        /* Backup control register */
        #if(TEST_UseControl)
            uint8 PWMControlRegister; /* PWM Control Register value */
        #endif /* (TEST_UseControl) */

    #endif /* (!TEST_UsingFixedFunction) */

}TEST_backupStruct;


/***************************************
*        Function Prototypes
 **************************************/

void    TEST_Start(void) ;
void    TEST_Stop(void) ;

#if (TEST_UseStatus || TEST_UsingFixedFunction)
    void  TEST_SetInterruptMode(uint8 interruptMode) ;
    uint8 TEST_ReadStatusRegister(void) ;
#endif /* (TEST_UseStatus || TEST_UsingFixedFunction) */

#define TEST_GetInterruptSource() TEST_ReadStatusRegister()

#if (TEST_UseControl)
    uint8 TEST_ReadControlRegister(void) ;
    void  TEST_WriteControlRegister(uint8 control)
          ;
#endif /* (TEST_UseControl) */

#if (TEST_UseOneCompareMode)
   #if (TEST_CompareMode1SW)
       void    TEST_SetCompareMode(uint8 comparemode)
               ;
   #endif /* (TEST_CompareMode1SW) */
#else
    #if (TEST_CompareMode1SW)
        void    TEST_SetCompareMode1(uint8 comparemode)
                ;
    #endif /* (TEST_CompareMode1SW) */
    #if (TEST_CompareMode2SW)
        void    TEST_SetCompareMode2(uint8 comparemode)
                ;
    #endif /* (TEST_CompareMode2SW) */
#endif /* (TEST_UseOneCompareMode) */

#if (!TEST_UsingFixedFunction)
    uint16   TEST_ReadCounter(void) ;
    uint16 TEST_ReadCapture(void) ;

    #if (TEST_UseStatus)
            void TEST_ClearFIFO(void) ;
    #endif /* (TEST_UseStatus) */

    void    TEST_WriteCounter(uint16 counter)
            ;
#endif /* (!TEST_UsingFixedFunction) */

void    TEST_WritePeriod(uint16 period)
        ;
uint16 TEST_ReadPeriod(void) ;

#if (TEST_UseOneCompareMode)
    void    TEST_WriteCompare(uint16 compare)
            ;
    uint16 TEST_ReadCompare(void) ;
#else
    void    TEST_WriteCompare1(uint16 compare)
            ;
    uint16 TEST_ReadCompare1(void) ;
    void    TEST_WriteCompare2(uint16 compare)
            ;
    uint16 TEST_ReadCompare2(void) ;
#endif /* (TEST_UseOneCompareMode) */


#if (TEST_DeadBandUsed)
    void    TEST_WriteDeadTime(uint8 deadtime) ;
    uint8   TEST_ReadDeadTime(void) ;
#endif /* (TEST_DeadBandUsed) */

#if ( TEST_KillModeMinTime)
    void TEST_WriteKillTime(uint8 killtime) ;
    uint8 TEST_ReadKillTime(void) ;
#endif /* ( TEST_KillModeMinTime) */

void TEST_Init(void) ;
void TEST_Enable(void) ;
void TEST_Sleep(void) ;
void TEST_Wakeup(void) ;
void TEST_SaveConfig(void) ;
void TEST_RestoreConfig(void) ;


/***************************************
*         Initialization Values
**************************************/
#define TEST_INIT_PERIOD_VALUE          (511u)
#define TEST_INIT_COMPARE_VALUE1        (255u)
#define TEST_INIT_COMPARE_VALUE2        (255u)
#define TEST_INIT_INTERRUPTS_MODE       (uint8)(((uint8)(0u <<   \
                                                    TEST_STATUS_TC_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    TEST_STATUS_CMP2_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    TEST_STATUS_CMP1_INT_EN_MASK_SHIFT )) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    TEST_STATUS_KILL_INT_EN_MASK_SHIFT )))
#define TEST_DEFAULT_COMPARE2_MODE      (uint8)((uint8)3u <<  TEST_CTRL_CMPMODE2_SHIFT)
#define TEST_DEFAULT_COMPARE1_MODE      (uint8)((uint8)1u <<  TEST_CTRL_CMPMODE1_SHIFT)
#define TEST_INIT_DEAD_TIME             (1u)


/********************************
*         Registers
******************************** */

#if (TEST_UsingFixedFunction)
   #define TEST_PERIOD_LSB              (*(reg16 *) TEST_PWMHW__PER0)
   #define TEST_PERIOD_LSB_PTR          ( (reg16 *) TEST_PWMHW__PER0)
   #define TEST_COMPARE1_LSB            (*(reg16 *) TEST_PWMHW__CNT_CMP0)
   #define TEST_COMPARE1_LSB_PTR        ( (reg16 *) TEST_PWMHW__CNT_CMP0)
   #define TEST_COMPARE2_LSB            (0x00u)
   #define TEST_COMPARE2_LSB_PTR        (0x00u)
   #define TEST_COUNTER_LSB             (*(reg16 *) TEST_PWMHW__CNT_CMP0)
   #define TEST_COUNTER_LSB_PTR         ( (reg16 *) TEST_PWMHW__CNT_CMP0)
   #define TEST_CAPTURE_LSB             (*(reg16 *) TEST_PWMHW__CAP0)
   #define TEST_CAPTURE_LSB_PTR         ( (reg16 *) TEST_PWMHW__CAP0)
   #define TEST_RT1                     (*(reg8 *)  TEST_PWMHW__RT1)
   #define TEST_RT1_PTR                 ( (reg8 *)  TEST_PWMHW__RT1)

#else
   #if (TEST_Resolution == 8u) /* 8bit - PWM */

       #if(TEST_PWMModeIsCenterAligned)
           #define TEST_PERIOD_LSB      (*(reg8 *)  TEST_PWMUDB_sP16_pwmdp_u0__D1_REG)
           #define TEST_PERIOD_LSB_PTR  ((reg8 *)   TEST_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #else
           #define TEST_PERIOD_LSB      (*(reg8 *)  TEST_PWMUDB_sP16_pwmdp_u0__F0_REG)
           #define TEST_PERIOD_LSB_PTR  ((reg8 *)   TEST_PWMUDB_sP16_pwmdp_u0__F0_REG)
       #endif /* (TEST_PWMModeIsCenterAligned) */

       #define TEST_COMPARE1_LSB        (*(reg8 *)  TEST_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define TEST_COMPARE1_LSB_PTR    ((reg8 *)   TEST_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define TEST_COMPARE2_LSB        (*(reg8 *)  TEST_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define TEST_COMPARE2_LSB_PTR    ((reg8 *)   TEST_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define TEST_COUNTERCAP_LSB      (*(reg8 *)  TEST_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define TEST_COUNTERCAP_LSB_PTR  ((reg8 *)   TEST_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define TEST_COUNTER_LSB         (*(reg8 *)  TEST_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define TEST_COUNTER_LSB_PTR     ((reg8 *)   TEST_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define TEST_CAPTURE_LSB         (*(reg8 *)  TEST_PWMUDB_sP16_pwmdp_u0__F1_REG)
       #define TEST_CAPTURE_LSB_PTR     ((reg8 *)   TEST_PWMUDB_sP16_pwmdp_u0__F1_REG)

   #else
        #if(CY_PSOC3) /* 8-bit address space */
            #if(TEST_PWMModeIsCenterAligned)
               #define TEST_PERIOD_LSB      (*(reg16 *) TEST_PWMUDB_sP16_pwmdp_u0__D1_REG)
               #define TEST_PERIOD_LSB_PTR  ((reg16 *)  TEST_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #else
               #define TEST_PERIOD_LSB      (*(reg16 *) TEST_PWMUDB_sP16_pwmdp_u0__F0_REG)
               #define TEST_PERIOD_LSB_PTR  ((reg16 *)  TEST_PWMUDB_sP16_pwmdp_u0__F0_REG)
            #endif /* (TEST_PWMModeIsCenterAligned) */

            #define TEST_COMPARE1_LSB       (*(reg16 *) TEST_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define TEST_COMPARE1_LSB_PTR   ((reg16 *)  TEST_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define TEST_COMPARE2_LSB       (*(reg16 *) TEST_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define TEST_COMPARE2_LSB_PTR   ((reg16 *)  TEST_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define TEST_COUNTERCAP_LSB     (*(reg16 *) TEST_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define TEST_COUNTERCAP_LSB_PTR ((reg16 *)  TEST_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define TEST_COUNTER_LSB        (*(reg16 *) TEST_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define TEST_COUNTER_LSB_PTR    ((reg16 *)  TEST_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define TEST_CAPTURE_LSB        (*(reg16 *) TEST_PWMUDB_sP16_pwmdp_u0__F1_REG)
            #define TEST_CAPTURE_LSB_PTR    ((reg16 *)  TEST_PWMUDB_sP16_pwmdp_u0__F1_REG)
        #else
            #if(TEST_PWMModeIsCenterAligned)
               #define TEST_PERIOD_LSB      (*(reg16 *) TEST_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
               #define TEST_PERIOD_LSB_PTR  ((reg16 *)  TEST_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #else
               #define TEST_PERIOD_LSB      (*(reg16 *) TEST_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
               #define TEST_PERIOD_LSB_PTR  ((reg16 *)  TEST_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
            #endif /* (TEST_PWMModeIsCenterAligned) */

            #define TEST_COMPARE1_LSB       (*(reg16 *) TEST_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define TEST_COMPARE1_LSB_PTR   ((reg16 *)  TEST_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define TEST_COMPARE2_LSB       (*(reg16 *) TEST_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define TEST_COMPARE2_LSB_PTR   ((reg16 *)  TEST_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define TEST_COUNTERCAP_LSB     (*(reg16 *) TEST_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define TEST_COUNTERCAP_LSB_PTR ((reg16 *)  TEST_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define TEST_COUNTER_LSB        (*(reg16 *) TEST_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define TEST_COUNTER_LSB_PTR    ((reg16 *)  TEST_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define TEST_CAPTURE_LSB        (*(reg16 *) TEST_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
            #define TEST_CAPTURE_LSB_PTR    ((reg16 *)  TEST_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
        #endif /* (CY_PSOC3) */

       #define TEST_AUX_CONTROLDP1          (*(reg8 *)  TEST_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)
       #define TEST_AUX_CONTROLDP1_PTR      ((reg8 *)   TEST_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (TEST_Resolution == 8) */

   #define TEST_COUNTERCAP_LSB_PTR_8BIT ( (reg8 *)  TEST_PWMUDB_sP16_pwmdp_u0__A1_REG)
   #define TEST_AUX_CONTROLDP0          (*(reg8 *)  TEST_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)
   #define TEST_AUX_CONTROLDP0_PTR      ((reg8 *)   TEST_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (TEST_UsingFixedFunction) */

#if(TEST_KillModeMinTime )
    #define TEST_KILLMODEMINTIME        (*(reg8 *)  TEST_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define TEST_KILLMODEMINTIME_PTR    ((reg8 *)   TEST_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (TEST_KillModeMinTime ) */

#if(TEST_DeadBandMode == TEST__B_PWM__DBM_256_CLOCKS)
    #define TEST_DEADBAND_COUNT         (*(reg8 *)  TEST_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define TEST_DEADBAND_COUNT_PTR     ((reg8 *)   TEST_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define TEST_DEADBAND_LSB_PTR       ((reg8 *)   TEST_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define TEST_DEADBAND_LSB           (*(reg8 *)  TEST_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(TEST_DeadBandMode == TEST__B_PWM__DBM_2_4_CLOCKS)
    
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (TEST_UsingFixedFunction)
        #define TEST_DEADBAND_COUNT         (*(reg8 *)  TEST_PWMHW__CFG0)
        #define TEST_DEADBAND_COUNT_PTR     ((reg8 *)   TEST_PWMHW__CFG0)
        #define TEST_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << TEST_DEADBAND_COUNT_SHIFT)

        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define TEST_DEADBAND_COUNT_SHIFT   (0x06u)
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define TEST_DEADBAND_COUNT         (*(reg8 *)  TEST_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define TEST_DEADBAND_COUNT_PTR     ((reg8 *)   TEST_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define TEST_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << TEST_DEADBAND_COUNT_SHIFT)

        /* As defined by the verilog implementation of the Control Register */
        #define TEST_DEADBAND_COUNT_SHIFT   (0x00u)
    #endif /* (TEST_UsingFixedFunction) */
#endif /* (TEST_DeadBandMode == TEST__B_PWM__DBM_256_CLOCKS) */



#if (TEST_UsingFixedFunction)
    #define TEST_STATUS                 (*(reg8 *) TEST_PWMHW__SR0)
    #define TEST_STATUS_PTR             ((reg8 *) TEST_PWMHW__SR0)
    #define TEST_STATUS_MASK            (*(reg8 *) TEST_PWMHW__SR0)
    #define TEST_STATUS_MASK_PTR        ((reg8 *) TEST_PWMHW__SR0)
    #define TEST_CONTROL                (*(reg8 *) TEST_PWMHW__CFG0)
    #define TEST_CONTROL_PTR            ((reg8 *) TEST_PWMHW__CFG0)
    #define TEST_CONTROL2               (*(reg8 *) TEST_PWMHW__CFG1)
    #define TEST_CONTROL3               (*(reg8 *) TEST_PWMHW__CFG2)
    #define TEST_GLOBAL_ENABLE          (*(reg8 *) TEST_PWMHW__PM_ACT_CFG)
    #define TEST_GLOBAL_ENABLE_PTR      ( (reg8 *) TEST_PWMHW__PM_ACT_CFG)
    #define TEST_GLOBAL_STBY_ENABLE     (*(reg8 *) TEST_PWMHW__PM_STBY_CFG)
    #define TEST_GLOBAL_STBY_ENABLE_PTR ( (reg8 *) TEST_PWMHW__PM_STBY_CFG)


    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define TEST_BLOCK_EN_MASK          (TEST_PWMHW__PM_ACT_MSK)
    #define TEST_BLOCK_STBY_EN_MASK     (TEST_PWMHW__PM_STBY_MSK)
    
    /* Control Register definitions */
    #define TEST_CTRL_ENABLE_SHIFT      (0x00u)

    /* As defined by Register map as MODE_CFG bits in CFG2*/
    #define TEST_CTRL_CMPMODE1_SHIFT    (0x04u)

    /* As defined by Register map */
    #define TEST_CTRL_DEAD_TIME_SHIFT   (0x06u)  

    /* Fixed Function Block Only CFG register bit definitions */
    /*  Set to compare mode */
    #define TEST_CFG0_MODE              (0x02u)   

    /* Enable the block to run */
    #define TEST_CFG0_ENABLE            (0x01u)   
    
    /* As defined by Register map as DB bit in CFG0 */
    #define TEST_CFG0_DB                (0x20u)   

    /* Control Register Bit Masks */
    #define TEST_CTRL_ENABLE            (uint8)((uint8)0x01u << TEST_CTRL_ENABLE_SHIFT)
    #define TEST_CTRL_RESET             (uint8)((uint8)0x01u << TEST_CTRL_RESET_SHIFT)
    #define TEST_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << TEST_CTRL_CMPMODE2_SHIFT)
    #define TEST_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << TEST_CTRL_CMPMODE1_SHIFT)

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define TEST_CTRL2_IRQ_SEL_SHIFT    (0x00u)
    #define TEST_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << TEST_CTRL2_IRQ_SEL_SHIFT)

    /* Status Register Bit Locations */
    /* As defined by Register map as TC in SR0 */
    #define TEST_STATUS_TC_SHIFT        (0x07u)   
    
    /* As defined by the Register map as CAP_CMP in SR0 */
    #define TEST_STATUS_CMP1_SHIFT      (0x06u)   

    /* Status Register Interrupt Enable Bit Locations */
    #define TEST_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)
    #define TEST_STATUS_TC_INT_EN_MASK_SHIFT            (TEST_STATUS_TC_SHIFT - 4u)
    #define TEST_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)
    #define TEST_STATUS_CMP1_INT_EN_MASK_SHIFT          (TEST_STATUS_CMP1_SHIFT - 4u)

    /* Status Register Bit Masks */
    #define TEST_STATUS_TC              (uint8)((uint8)0x01u << TEST_STATUS_TC_SHIFT)
    #define TEST_STATUS_CMP1            (uint8)((uint8)0x01u << TEST_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks */
    #define TEST_STATUS_TC_INT_EN_MASK              (uint8)((uint8)TEST_STATUS_TC >> 4u)
    #define TEST_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)TEST_STATUS_CMP1 >> 4u)

    /*RT1 Synch Constants */
    #define TEST_RT1_SHIFT             (0x04u)

    /* Sync TC and CMP bit masks */
    #define TEST_RT1_MASK              (uint8)((uint8)0x03u << TEST_RT1_SHIFT)
    #define TEST_SYNC                  (uint8)((uint8)0x03u << TEST_RT1_SHIFT)
    #define TEST_SYNCDSI_SHIFT         (0x00u)

    /* Sync all DSI inputs */
    #define TEST_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << TEST_SYNCDSI_SHIFT)

    /* Sync all DSI inputs */
    #define TEST_SYNCDSI_EN            (uint8)((uint8)0x0Fu << TEST_SYNCDSI_SHIFT)


#else
    #define TEST_STATUS                (*(reg8 *)   TEST_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define TEST_STATUS_PTR            ((reg8 *)    TEST_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define TEST_STATUS_MASK           (*(reg8 *)   TEST_PWMUDB_genblk8_stsreg__MASK_REG)
    #define TEST_STATUS_MASK_PTR       ((reg8 *)    TEST_PWMUDB_genblk8_stsreg__MASK_REG)
    #define TEST_STATUS_AUX_CTRL       (*(reg8 *)   TEST_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG)
    #define TEST_CONTROL               (*(reg8 *)   TEST_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    #define TEST_CONTROL_PTR           ((reg8 *)    TEST_PWMUDB_genblk1_ctrlreg__CONTROL_REG)


    /***********************************
    *          Constants
    ***********************************/

    /* Control Register bit definitions */
    #define TEST_CTRL_ENABLE_SHIFT      (0x07u)
    #define TEST_CTRL_RESET_SHIFT       (0x06u)
    #define TEST_CTRL_CMPMODE2_SHIFT    (0x03u)
    #define TEST_CTRL_CMPMODE1_SHIFT    (0x00u)
    #define TEST_CTRL_DEAD_TIME_SHIFT   (0x00u)   /* No Shift Needed for UDB block */
    
    /* Control Register Bit Masks */
    #define TEST_CTRL_ENABLE            (uint8)((uint8)0x01u << TEST_CTRL_ENABLE_SHIFT)
    #define TEST_CTRL_RESET             (uint8)((uint8)0x01u << TEST_CTRL_RESET_SHIFT)
    #define TEST_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << TEST_CTRL_CMPMODE2_SHIFT)
    #define TEST_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << TEST_CTRL_CMPMODE1_SHIFT)

    /* Status Register Bit Locations */
    #define TEST_STATUS_KILL_SHIFT          (0x05u)
    #define TEST_STATUS_FIFONEMPTY_SHIFT    (0x04u)
    #define TEST_STATUS_FIFOFULL_SHIFT      (0x03u)
    #define TEST_STATUS_TC_SHIFT            (0x02u)
    #define TEST_STATUS_CMP2_SHIFT          (0x01u)
    #define TEST_STATUS_CMP1_SHIFT          (0x00u)

    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define TEST_STATUS_KILL_INT_EN_MASK_SHIFT          (TEST_STATUS_KILL_SHIFT)
    #define TEST_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    (TEST_STATUS_FIFONEMPTY_SHIFT)
    #define TEST_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      (TEST_STATUS_FIFOFULL_SHIFT)
    #define TEST_STATUS_TC_INT_EN_MASK_SHIFT            (TEST_STATUS_TC_SHIFT)
    #define TEST_STATUS_CMP2_INT_EN_MASK_SHIFT          (TEST_STATUS_CMP2_SHIFT)
    #define TEST_STATUS_CMP1_INT_EN_MASK_SHIFT          (TEST_STATUS_CMP1_SHIFT)

    /* Status Register Bit Masks */
    #define TEST_STATUS_KILL            (uint8)((uint8)0x00u << TEST_STATUS_KILL_SHIFT )
    #define TEST_STATUS_FIFOFULL        (uint8)((uint8)0x01u << TEST_STATUS_FIFOFULL_SHIFT)
    #define TEST_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << TEST_STATUS_FIFONEMPTY_SHIFT)
    #define TEST_STATUS_TC              (uint8)((uint8)0x01u << TEST_STATUS_TC_SHIFT)
    #define TEST_STATUS_CMP2            (uint8)((uint8)0x01u << TEST_STATUS_CMP2_SHIFT)
    #define TEST_STATUS_CMP1            (uint8)((uint8)0x01u << TEST_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define TEST_STATUS_KILL_INT_EN_MASK            (TEST_STATUS_KILL)
    #define TEST_STATUS_FIFOFULL_INT_EN_MASK        (TEST_STATUS_FIFOFULL)
    #define TEST_STATUS_FIFONEMPTY_INT_EN_MASK      (TEST_STATUS_FIFONEMPTY)
    #define TEST_STATUS_TC_INT_EN_MASK              (TEST_STATUS_TC)
    #define TEST_STATUS_CMP2_INT_EN_MASK            (TEST_STATUS_CMP2)
    #define TEST_STATUS_CMP1_INT_EN_MASK            (TEST_STATUS_CMP1)

    /* Datapath Auxillary Control Register bit definitions */
    #define TEST_AUX_CTRL_FIFO0_CLR         (0x01u)
    #define TEST_AUX_CTRL_FIFO1_CLR         (0x02u)
    #define TEST_AUX_CTRL_FIFO0_LVL         (0x04u)
    #define TEST_AUX_CTRL_FIFO1_LVL         (0x08u)
    #define TEST_STATUS_ACTL_INT_EN_MASK    (0x10u) /* As defined for the ACTL Register */
#endif /* TEST_UsingFixedFunction */

#endif  /* CY_PWM_TEST_H */


/* [] END OF FILE */
