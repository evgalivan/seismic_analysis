/*******************************************************************************
* File Name: Waiter.h  
* Version 3.0
*
*  Description:
*   Contains the function prototypes and constants available to the counter
*   user module.
*
*   Note:
*    None
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
    
#if !defined(CY_COUNTER_Waiter_H)
#define CY_COUNTER_Waiter_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 Waiter_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Counter_v3_0 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Error message for removed Waiter_CounterUDB_sCTRLReg_ctrlreg through optimization */
#ifdef Waiter_CounterUDB_sCTRLReg_ctrlreg__REMOVED
    #error Counter_v3_0 detected with a constant 0 for the enable, a \
                                constant 0 for the count or constant 1 for \
                                the reset. This will prevent the component from\
                                operating.
#endif /* Waiter_CounterUDB_sCTRLReg_ctrlreg__REMOVED */


/**************************************
*           Parameter Defaults        
**************************************/

#define Waiter_Resolution            8u
#define Waiter_UsingFixedFunction    0u
#define Waiter_ControlRegRemoved     1u
#define Waiter_COMPARE_MODE_SOFTWARE 0u
#define Waiter_CAPTURE_MODE_SOFTWARE 0u
#define Waiter_RunModeUsed           0u


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Mode API Support
 * Backup structure for Sleep Wake up operations
 *************************************************************************/
typedef struct
{
    uint8 CounterEnableState; 
    uint8 CounterUdb;         /* Current Counter Value */

    #if (!Waiter_ControlRegRemoved)
        uint8 CounterControlRegister;               /* Counter Control Register */
    #endif /* (!Waiter_ControlRegRemoved) */

}Waiter_backupStruct;


/**************************************
 *  Function Prototypes
 *************************************/
void    Waiter_Start(void) ;
void    Waiter_Stop(void) ;
void    Waiter_SetInterruptMode(uint8 interruptsMask) ;
uint8   Waiter_ReadStatusRegister(void) ;
#define Waiter_GetInterruptSource() Waiter_ReadStatusRegister()
#if(!Waiter_ControlRegRemoved)
    uint8   Waiter_ReadControlRegister(void) ;
    void    Waiter_WriteControlRegister(uint8 control) \
        ;
#endif /* (!Waiter_ControlRegRemoved) */
#if (!(Waiter_UsingFixedFunction && (CY_PSOC5A)))
    void    Waiter_WriteCounter(uint8 counter) \
            ; 
#endif /* (!(Waiter_UsingFixedFunction && (CY_PSOC5A))) */
uint8  Waiter_ReadCounter(void) ;
uint8  Waiter_ReadCapture(void) ;
void    Waiter_WritePeriod(uint8 period) \
    ;
uint8  Waiter_ReadPeriod( void ) ;
#if (!Waiter_UsingFixedFunction)
    void    Waiter_WriteCompare(uint8 compare) \
        ;
    uint8  Waiter_ReadCompare( void ) \
        ;
#endif /* (!Waiter_UsingFixedFunction) */

#if (Waiter_COMPARE_MODE_SOFTWARE)
    void    Waiter_SetCompareMode(uint8 compareMode) ;
#endif /* (Waiter_COMPARE_MODE_SOFTWARE) */
#if (Waiter_CAPTURE_MODE_SOFTWARE)
    void    Waiter_SetCaptureMode(uint8 captureMode) ;
#endif /* (Waiter_CAPTURE_MODE_SOFTWARE) */
void Waiter_ClearFIFO(void)     ;
void Waiter_Init(void)          ;
void Waiter_Enable(void)        ;
void Waiter_SaveConfig(void)    ;
void Waiter_RestoreConfig(void) ;
void Waiter_Sleep(void)         ;
void Waiter_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Counter__CompareModes, Used in Compare Mode retained for backward compatibility of tests*/
#define Waiter__B_COUNTER__LESS_THAN 1
#define Waiter__B_COUNTER__LESS_THAN_OR_EQUAL 2
#define Waiter__B_COUNTER__EQUAL 0
#define Waiter__B_COUNTER__GREATER_THAN 3
#define Waiter__B_COUNTER__GREATER_THAN_OR_EQUAL 4
#define Waiter__B_COUNTER__SOFTWARE 5

/* Enumerated Type Counter_CompareModes */
#define Waiter_CMP_MODE_LT 1u
#define Waiter_CMP_MODE_LTE 2u
#define Waiter_CMP_MODE_EQ 0u
#define Waiter_CMP_MODE_GT 3u
#define Waiter_CMP_MODE_GTE 4u
#define Waiter_CMP_MODE_SOFTWARE_CONTROLLED 5u

/* Enumerated Type B_Counter__CaptureModes, Used in Capture Mode retained for backward compatibility of tests*/
#define Waiter__B_COUNTER__NONE 0
#define Waiter__B_COUNTER__RISING_EDGE 1
#define Waiter__B_COUNTER__FALLING_EDGE 2
#define Waiter__B_COUNTER__EITHER_EDGE 3
#define Waiter__B_COUNTER__SOFTWARE_CONTROL 4

/* Enumerated Type Counter_CompareModes */
#define Waiter_CAP_MODE_NONE 0u
#define Waiter_CAP_MODE_RISE 1u
#define Waiter_CAP_MODE_FALL 2u
#define Waiter_CAP_MODE_BOTH 3u
#define Waiter_CAP_MODE_SOFTWARE_CONTROLLED 4u


/***************************************
 *  Initialization Values
 **************************************/
#define Waiter_CAPTURE_MODE_CONF       3u
#define Waiter_INIT_PERIOD_VALUE       254u
#define Waiter_INIT_COUNTER_VALUE      0u
#if (Waiter_UsingFixedFunction)
#define Waiter_INIT_INTERRUPTS_MASK    ((uint8)((uint8)0u << Waiter_STATUS_ZERO_INT_EN_MASK_SHIFT))
#else
#define Waiter_INIT_COMPARE_VALUE      9u
#define Waiter_INIT_INTERRUPTS_MASK ((uint8)((uint8)0u << Waiter_STATUS_ZERO_INT_EN_MASK_SHIFT) | \
        ((uint8)((uint8)0u << Waiter_STATUS_CAPTURE_INT_EN_MASK_SHIFT)) | \
        ((uint8)((uint8)0u << Waiter_STATUS_CMP_INT_EN_MASK_SHIFT)) | \
        ((uint8)((uint8)0u << Waiter_STATUS_OVERFLOW_INT_EN_MASK_SHIFT)) | \
        ((uint8)((uint8)0u << Waiter_STATUS_UNDERFLOW_INT_EN_MASK_SHIFT)))
#define Waiter_DEFAULT_COMPARE_MODE    4u

#if( 0 != Waiter_CAPTURE_MODE_CONF)
    #define Waiter_DEFAULT_CAPTURE_MODE    ((uint8)((uint8)3u << Waiter_CTRL_CAPMODE0_SHIFT))
#else    
    #define Waiter_DEFAULT_CAPTURE_MODE    (3u )
#endif /* ( 0 != Waiter_CAPTURE_MODE_CONF) */

#endif /* (Waiter_UsingFixedFunction) */


/**************************************
 *  Registers
 *************************************/
#if (Waiter_UsingFixedFunction)
    #define Waiter_STATICCOUNT_LSB     (*(reg16 *) Waiter_CounterHW__CAP0 )
    #define Waiter_STATICCOUNT_LSB_PTR ( (reg16 *) Waiter_CounterHW__CAP0 )
    #define Waiter_PERIOD_LSB          (*(reg16 *) Waiter_CounterHW__PER0 )
    #define Waiter_PERIOD_LSB_PTR      ( (reg16 *) Waiter_CounterHW__PER0 )
    /* MODE must be set to 1 to set the compare value */
    #define Waiter_COMPARE_LSB         (*(reg16 *) Waiter_CounterHW__CNT_CMP0 )
    #define Waiter_COMPARE_LSB_PTR     ( (reg16 *) Waiter_CounterHW__CNT_CMP0 )
    /* MODE must be set to 0 to get the count */
    #define Waiter_COUNTER_LSB         (*(reg16 *) Waiter_CounterHW__CNT_CMP0 )
    #define Waiter_COUNTER_LSB_PTR     ( (reg16 *) Waiter_CounterHW__CNT_CMP0 )
    #define Waiter_RT1                 (*(reg8 *) Waiter_CounterHW__RT1)
    #define Waiter_RT1_PTR             ( (reg8 *) Waiter_CounterHW__RT1)
#else
    
    #if (Waiter_Resolution <= 8u) /* 8-bit Counter */
    
        #define Waiter_STATICCOUNT_LSB     (*(reg8 *) \
            Waiter_CounterUDB_sC8_counterdp_u0__F0_REG )
        #define Waiter_STATICCOUNT_LSB_PTR ( (reg8 *) \
            Waiter_CounterUDB_sC8_counterdp_u0__F0_REG )
        #define Waiter_PERIOD_LSB          (*(reg8 *) \
            Waiter_CounterUDB_sC8_counterdp_u0__D0_REG )
        #define Waiter_PERIOD_LSB_PTR      ( (reg8 *) \
            Waiter_CounterUDB_sC8_counterdp_u0__D0_REG )
        #define Waiter_COMPARE_LSB         (*(reg8 *) \
            Waiter_CounterUDB_sC8_counterdp_u0__D1_REG )
        #define Waiter_COMPARE_LSB_PTR     ( (reg8 *) \
            Waiter_CounterUDB_sC8_counterdp_u0__D1_REG )
        #define Waiter_COUNTER_LSB         (*(reg8 *) \
            Waiter_CounterUDB_sC8_counterdp_u0__A0_REG )  
        #define Waiter_COUNTER_LSB_PTR     ( (reg8 *)\
            Waiter_CounterUDB_sC8_counterdp_u0__A0_REG )
    
    #elif(Waiter_Resolution <= 16u) /* 16-bit Counter */
        #if(CY_PSOC3) /* 8-bit address space */ 
            #define Waiter_STATICCOUNT_LSB     (*(reg16 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__F0_REG )
            #define Waiter_STATICCOUNT_LSB_PTR ( (reg16 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__F0_REG )
            #define Waiter_PERIOD_LSB          (*(reg16 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__D0_REG )
            #define Waiter_PERIOD_LSB_PTR      ( (reg16 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__D0_REG )
            #define Waiter_COMPARE_LSB         (*(reg16 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__D1_REG )
            #define Waiter_COMPARE_LSB_PTR     ( (reg16 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__D1_REG )
            #define Waiter_COUNTER_LSB         (*(reg16 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__A0_REG )  
            #define Waiter_COUNTER_LSB_PTR     ( (reg16 *)\
                Waiter_CounterUDB_sC8_counterdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define Waiter_STATICCOUNT_LSB     (*(reg16 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__16BIT_F0_REG )
            #define Waiter_STATICCOUNT_LSB_PTR ( (reg16 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__16BIT_F0_REG )
            #define Waiter_PERIOD_LSB          (*(reg16 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__16BIT_D0_REG )
            #define Waiter_PERIOD_LSB_PTR      ( (reg16 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__16BIT_D0_REG )
            #define Waiter_COMPARE_LSB         (*(reg16 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__16BIT_D1_REG )
            #define Waiter_COMPARE_LSB_PTR     ( (reg16 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__16BIT_D1_REG )
            #define Waiter_COUNTER_LSB         (*(reg16 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__16BIT_A0_REG )  
            #define Waiter_COUNTER_LSB_PTR     ( (reg16 *)\
                Waiter_CounterUDB_sC8_counterdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */   
    #elif(Waiter_Resolution <= 24u) /* 24-bit Counter */
        
        #define Waiter_STATICCOUNT_LSB     (*(reg32 *) \
            Waiter_CounterUDB_sC8_counterdp_u0__F0_REG )
        #define Waiter_STATICCOUNT_LSB_PTR ( (reg32 *) \
            Waiter_CounterUDB_sC8_counterdp_u0__F0_REG )
        #define Waiter_PERIOD_LSB          (*(reg32 *) \
            Waiter_CounterUDB_sC8_counterdp_u0__D0_REG )
        #define Waiter_PERIOD_LSB_PTR      ( (reg32 *) \
            Waiter_CounterUDB_sC8_counterdp_u0__D0_REG )
        #define Waiter_COMPARE_LSB         (*(reg32 *) \
            Waiter_CounterUDB_sC8_counterdp_u0__D1_REG )
        #define Waiter_COMPARE_LSB_PTR     ( (reg32 *) \
            Waiter_CounterUDB_sC8_counterdp_u0__D1_REG )
        #define Waiter_COUNTER_LSB         (*(reg32 *) \
            Waiter_CounterUDB_sC8_counterdp_u0__A0_REG )  
        #define Waiter_COUNTER_LSB_PTR     ( (reg32 *)\
            Waiter_CounterUDB_sC8_counterdp_u0__A0_REG )
    
    #else /* 32-bit Counter */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define Waiter_STATICCOUNT_LSB     (*(reg32 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__F0_REG )
            #define Waiter_STATICCOUNT_LSB_PTR ( (reg32 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__F0_REG )
            #define Waiter_PERIOD_LSB          (*(reg32 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__D0_REG )
            #define Waiter_PERIOD_LSB_PTR      ( (reg32 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__D0_REG )
            #define Waiter_COMPARE_LSB         (*(reg32 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__D1_REG )
            #define Waiter_COMPARE_LSB_PTR     ( (reg32 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__D1_REG )
            #define Waiter_COUNTER_LSB         (*(reg32 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__A0_REG )  
            #define Waiter_COUNTER_LSB_PTR     ( (reg32 *)\
                Waiter_CounterUDB_sC8_counterdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define Waiter_STATICCOUNT_LSB     (*(reg32 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__32BIT_F0_REG )
            #define Waiter_STATICCOUNT_LSB_PTR ( (reg32 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__32BIT_F0_REG )
            #define Waiter_PERIOD_LSB          (*(reg32 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__32BIT_D0_REG )
            #define Waiter_PERIOD_LSB_PTR      ( (reg32 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__32BIT_D0_REG )
            #define Waiter_COMPARE_LSB         (*(reg32 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__32BIT_D1_REG )
            #define Waiter_COMPARE_LSB_PTR     ( (reg32 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__32BIT_D1_REG )
            #define Waiter_COUNTER_LSB         (*(reg32 *) \
                Waiter_CounterUDB_sC8_counterdp_u0__32BIT_A0_REG )  
            #define Waiter_COUNTER_LSB_PTR     ( (reg32 *)\
                Waiter_CounterUDB_sC8_counterdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */   
    #endif

	#define Waiter_COUNTER_LSB_PTR_8BIT     ( (reg8 *)\
                Waiter_CounterUDB_sC8_counterdp_u0__A0_REG )
				
    #define Waiter_AUX_CONTROLDP0 \
        (*(reg8 *) Waiter_CounterUDB_sC8_counterdp_u0__DP_AUX_CTL_REG)
    
    #define Waiter_AUX_CONTROLDP0_PTR \
        ( (reg8 *) Waiter_CounterUDB_sC8_counterdp_u0__DP_AUX_CTL_REG)
    
    #if (Waiter_Resolution == 16 || Waiter_Resolution == 24 || Waiter_Resolution == 32)
       #define Waiter_AUX_CONTROLDP1 \
           (*(reg8 *) Waiter_CounterUDB_sC8_counterdp_u1__DP_AUX_CTL_REG)
       #define Waiter_AUX_CONTROLDP1_PTR \
           ( (reg8 *) Waiter_CounterUDB_sC8_counterdp_u1__DP_AUX_CTL_REG)
    #endif /* (Waiter_Resolution == 16 || Waiter_Resolution == 24 || Waiter_Resolution == 32) */
    
    #if (Waiter_Resolution == 24 || Waiter_Resolution == 32)
       #define Waiter_AUX_CONTROLDP2 \
           (*(reg8 *) Waiter_CounterUDB_sC8_counterdp_u2__DP_AUX_CTL_REG)
       #define Waiter_AUX_CONTROLDP2_PTR \
           ( (reg8 *) Waiter_CounterUDB_sC8_counterdp_u2__DP_AUX_CTL_REG)
    #endif /* (Waiter_Resolution == 24 || Waiter_Resolution == 32) */
    
    #if (Waiter_Resolution == 32)
       #define Waiter_AUX_CONTROLDP3 \
           (*(reg8 *) Waiter_CounterUDB_sC8_counterdp_u3__DP_AUX_CTL_REG)
       #define Waiter_AUX_CONTROLDP3_PTR \
           ( (reg8 *) Waiter_CounterUDB_sC8_counterdp_u3__DP_AUX_CTL_REG)
    #endif /* (Waiter_Resolution == 32) */

#endif  /* (Waiter_UsingFixedFunction) */

#if (Waiter_UsingFixedFunction)
    #define Waiter_STATUS         (*(reg8 *) Waiter_CounterHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define Waiter_STATUS_MASK             (*(reg8 *) Waiter_CounterHW__SR0 )
    #define Waiter_STATUS_MASK_PTR         ( (reg8 *) Waiter_CounterHW__SR0 )
    #define Waiter_CONTROL                 (*(reg8 *) Waiter_CounterHW__CFG0)
    #define Waiter_CONTROL_PTR             ( (reg8 *) Waiter_CounterHW__CFG0)
    #define Waiter_CONTROL2                (*(reg8 *) Waiter_CounterHW__CFG1)
    #define Waiter_CONTROL2_PTR            ( (reg8 *) Waiter_CounterHW__CFG1)
    #if (CY_PSOC3 || CY_PSOC5LP)
        #define Waiter_CONTROL3       (*(reg8 *) Waiter_CounterHW__CFG2)
        #define Waiter_CONTROL3_PTR   ( (reg8 *) Waiter_CounterHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define Waiter_GLOBAL_ENABLE           (*(reg8 *) Waiter_CounterHW__PM_ACT_CFG)
    #define Waiter_GLOBAL_ENABLE_PTR       ( (reg8 *) Waiter_CounterHW__PM_ACT_CFG)
    #define Waiter_GLOBAL_STBY_ENABLE      (*(reg8 *) Waiter_CounterHW__PM_STBY_CFG)
    #define Waiter_GLOBAL_STBY_ENABLE_PTR  ( (reg8 *) Waiter_CounterHW__PM_STBY_CFG)
    

    /********************************
    *    Constants
    ********************************/

    /* Fixed Function Block Chosen */
    #define Waiter_BLOCK_EN_MASK          Waiter_CounterHW__PM_ACT_MSK
    #define Waiter_BLOCK_STBY_EN_MASK     Waiter_CounterHW__PM_STBY_MSK 
    
    /* Control Register Bit Locations */    
    /* As defined in Register Map, part of TMRX_CFG0 register */
    #define Waiter_CTRL_ENABLE_SHIFT      0x00u
    #define Waiter_ONESHOT_SHIFT          0x02u
    /* Control Register Bit Masks */
    #define Waiter_CTRL_ENABLE            ((uint8)((uint8)0x01u << Waiter_CTRL_ENABLE_SHIFT))         
    #define Waiter_ONESHOT                ((uint8)((uint8)0x01u << Waiter_ONESHOT_SHIFT))

    /* Control2 Register Bit Masks */
    /* Set the mask for run mode */
    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        #define Waiter_CTRL_MODE_SHIFT        0x01u    
        #define Waiter_CTRL_MODE_MASK         ((uint8)((uint8)0x07u << Waiter_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Use CFG2 Mode bits to set run mode */
        #define Waiter_CTRL_MODE_SHIFT        0x00u    
        #define Waiter_CTRL_MODE_MASK         ((uint8)((uint8)0x03u << Waiter_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    /* Set the mask for interrupt (raw/status register) */
    #define Waiter_CTRL2_IRQ_SEL_SHIFT     0x00u
    #define Waiter_CTRL2_IRQ_SEL          ((uint8)((uint8)0x01u << Waiter_CTRL2_IRQ_SEL_SHIFT))     
    
    /* Status Register Bit Locations */
    #define Waiter_STATUS_ZERO_SHIFT      0x07u  /* As defined in Register Map, part of TMRX_SR0 register */ 

    /* Status Register Interrupt Enable Bit Locations */
    #define Waiter_STATUS_ZERO_INT_EN_MASK_SHIFT      (Waiter_STATUS_ZERO_SHIFT - 0x04u)

    /* Status Register Bit Masks */                           
    #define Waiter_STATUS_ZERO            ((uint8)((uint8)0x01u << Waiter_STATUS_ZERO_SHIFT))

    /* Status Register Interrupt Bit Masks*/
    #define Waiter_STATUS_ZERO_INT_EN_MASK       ((uint8)((uint8)Waiter_STATUS_ZERO >> 0x04u))
    
    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define Waiter_RT1_SHIFT            0x04u
    #define Waiter_RT1_MASK             ((uint8)((uint8)0x03u << Waiter_RT1_SHIFT))  /* Sync TC and CMP bit masks */
    #define Waiter_SYNC                 ((uint8)((uint8)0x03u << Waiter_RT1_SHIFT))
    #define Waiter_SYNCDSI_SHIFT        0x00u
    #define Waiter_SYNCDSI_MASK         ((uint8)((uint8)0x0Fu << Waiter_SYNCDSI_SHIFT)) /* Sync all DSI inputs */
    #define Waiter_SYNCDSI_EN           ((uint8)((uint8)0x0Fu << Waiter_SYNCDSI_SHIFT)) /* Sync all DSI inputs */
    
#else /* !Waiter_UsingFixedFunction */
    #define Waiter_STATUS               (* (reg8 *) Waiter_CounterUDB_sSTSReg_stsreg__STATUS_REG )
    #define Waiter_STATUS_PTR           (  (reg8 *) Waiter_CounterUDB_sSTSReg_stsreg__STATUS_REG )
    #define Waiter_STATUS_MASK          (* (reg8 *) Waiter_CounterUDB_sSTSReg_stsreg__MASK_REG )
    #define Waiter_STATUS_MASK_PTR      (  (reg8 *) Waiter_CounterUDB_sSTSReg_stsreg__MASK_REG )
    #define Waiter_STATUS_AUX_CTRL      (*(reg8 *) Waiter_CounterUDB_sSTSReg_stsreg__STATUS_AUX_CTL_REG)
    #define Waiter_STATUS_AUX_CTRL_PTR  ( (reg8 *) Waiter_CounterUDB_sSTSReg_stsreg__STATUS_AUX_CTL_REG)
    #define Waiter_CONTROL              (* (reg8 *) Waiter_CounterUDB_sCTRLReg_ctrlreg__CONTROL_REG )
    #define Waiter_CONTROL_PTR          (  (reg8 *) Waiter_CounterUDB_sCTRLReg_ctrlreg__CONTROL_REG )


    /********************************
    *    Constants
    ********************************/
    /* Control Register Bit Locations */
    #define Waiter_CTRL_CAPMODE0_SHIFT    0x03u       /* As defined by Verilog Implementation */
    #define Waiter_CTRL_RESET_SHIFT       0x06u       /* As defined by Verilog Implementation */
    #define Waiter_CTRL_ENABLE_SHIFT      0x07u       /* As defined by Verilog Implementation */
    /* Control Register Bit Masks */
    #define Waiter_CTRL_CMPMODE_MASK      0x07u 
    #define Waiter_CTRL_CAPMODE_MASK      0x03u  
    #define Waiter_CTRL_RESET             ((uint8)((uint8)0x01u << Waiter_CTRL_RESET_SHIFT))  
    #define Waiter_CTRL_ENABLE            ((uint8)((uint8)0x01u << Waiter_CTRL_ENABLE_SHIFT)) 

    /* Status Register Bit Locations */
    #define Waiter_STATUS_CMP_SHIFT       0x00u       /* As defined by Verilog Implementation */
    #define Waiter_STATUS_ZERO_SHIFT      0x01u       /* As defined by Verilog Implementation */
    #define Waiter_STATUS_OVERFLOW_SHIFT  0x02u       /* As defined by Verilog Implementation */
    #define Waiter_STATUS_UNDERFLOW_SHIFT 0x03u       /* As defined by Verilog Implementation */
    #define Waiter_STATUS_CAPTURE_SHIFT   0x04u       /* As defined by Verilog Implementation */
    #define Waiter_STATUS_FIFOFULL_SHIFT  0x05u       /* As defined by Verilog Implementation */
    #define Waiter_STATUS_FIFONEMP_SHIFT  0x06u       /* As defined by Verilog Implementation */
    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define Waiter_STATUS_CMP_INT_EN_MASK_SHIFT       Waiter_STATUS_CMP_SHIFT       
    #define Waiter_STATUS_ZERO_INT_EN_MASK_SHIFT      Waiter_STATUS_ZERO_SHIFT      
    #define Waiter_STATUS_OVERFLOW_INT_EN_MASK_SHIFT  Waiter_STATUS_OVERFLOW_SHIFT  
    #define Waiter_STATUS_UNDERFLOW_INT_EN_MASK_SHIFT Waiter_STATUS_UNDERFLOW_SHIFT 
    #define Waiter_STATUS_CAPTURE_INT_EN_MASK_SHIFT   Waiter_STATUS_CAPTURE_SHIFT   
    #define Waiter_STATUS_FIFOFULL_INT_EN_MASK_SHIFT  Waiter_STATUS_FIFOFULL_SHIFT  
    #define Waiter_STATUS_FIFONEMP_INT_EN_MASK_SHIFT  Waiter_STATUS_FIFONEMP_SHIFT  
    /* Status Register Bit Masks */                
    #define Waiter_STATUS_CMP             ((uint8)((uint8)0x01u << Waiter_STATUS_CMP_SHIFT))  
    #define Waiter_STATUS_ZERO            ((uint8)((uint8)0x01u << Waiter_STATUS_ZERO_SHIFT)) 
    #define Waiter_STATUS_OVERFLOW        ((uint8)((uint8)0x01u << Waiter_STATUS_OVERFLOW_SHIFT)) 
    #define Waiter_STATUS_UNDERFLOW       ((uint8)((uint8)0x01u << Waiter_STATUS_UNDERFLOW_SHIFT)) 
    #define Waiter_STATUS_CAPTURE         ((uint8)((uint8)0x01u << Waiter_STATUS_CAPTURE_SHIFT)) 
    #define Waiter_STATUS_FIFOFULL        ((uint8)((uint8)0x01u << Waiter_STATUS_FIFOFULL_SHIFT))
    #define Waiter_STATUS_FIFONEMP        ((uint8)((uint8)0x01u << Waiter_STATUS_FIFONEMP_SHIFT))
    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define Waiter_STATUS_CMP_INT_EN_MASK            Waiter_STATUS_CMP                    
    #define Waiter_STATUS_ZERO_INT_EN_MASK           Waiter_STATUS_ZERO            
    #define Waiter_STATUS_OVERFLOW_INT_EN_MASK       Waiter_STATUS_OVERFLOW        
    #define Waiter_STATUS_UNDERFLOW_INT_EN_MASK      Waiter_STATUS_UNDERFLOW       
    #define Waiter_STATUS_CAPTURE_INT_EN_MASK        Waiter_STATUS_CAPTURE         
    #define Waiter_STATUS_FIFOFULL_INT_EN_MASK       Waiter_STATUS_FIFOFULL        
    #define Waiter_STATUS_FIFONEMP_INT_EN_MASK       Waiter_STATUS_FIFONEMP         
    

    /* StatusI Interrupt Enable bit Location in the Auxilliary Control Register */
    #define Waiter_STATUS_ACTL_INT_EN     0x10u /* As defined for the ACTL Register */
    
    /* Datapath Auxillary Control Register definitions */
    #define Waiter_AUX_CTRL_FIFO0_CLR         0x01u   /* As defined by Register map */
    #define Waiter_AUX_CTRL_FIFO1_CLR         0x02u   /* As defined by Register map */
    #define Waiter_AUX_CTRL_FIFO0_LVL         0x04u   /* As defined by Register map */
    #define Waiter_AUX_CTRL_FIFO1_LVL         0x08u   /* As defined by Register map */
    #define Waiter_STATUS_ACTL_INT_EN_MASK    0x10u   /* As defined for the ACTL Register */
    
#endif /* Waiter_UsingFixedFunction */

#endif  /* CY_COUNTER_Waiter_H */


/* [] END OF FILE */

