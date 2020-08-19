/*******************************************************************************
* File Name: Boundary32bit.h  
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
    
#if !defined(CY_COUNTER_Boundary32bit_H)
#define CY_COUNTER_Boundary32bit_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 Boundary32bit_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Counter_v3_0 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Error message for removed Boundary32bit_CounterUDB_sCTRLReg_ctrlreg through optimization */
#ifdef Boundary32bit_CounterUDB_sCTRLReg_ctrlreg__REMOVED
    #error Counter_v3_0 detected with a constant 0 for the enable, a \
                                constant 0 for the count or constant 1 for \
                                the reset. This will prevent the component from\
                                operating.
#endif /* Boundary32bit_CounterUDB_sCTRLReg_ctrlreg__REMOVED */


/**************************************
*           Parameter Defaults        
**************************************/

#define Boundary32bit_Resolution            8u
#define Boundary32bit_UsingFixedFunction    1u
#define Boundary32bit_ControlRegRemoved     0u
#define Boundary32bit_COMPARE_MODE_SOFTWARE 0u
#define Boundary32bit_CAPTURE_MODE_SOFTWARE 0u
#define Boundary32bit_RunModeUsed           0u


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

    #if (!Boundary32bit_ControlRegRemoved)
        uint8 CounterControlRegister;               /* Counter Control Register */
    #endif /* (!Boundary32bit_ControlRegRemoved) */

}Boundary32bit_backupStruct;


/**************************************
 *  Function Prototypes
 *************************************/
void    Boundary32bit_Start(void) ;
void    Boundary32bit_Stop(void) ;
void    Boundary32bit_SetInterruptMode(uint8 interruptsMask) ;
uint8   Boundary32bit_ReadStatusRegister(void) ;
#define Boundary32bit_GetInterruptSource() Boundary32bit_ReadStatusRegister()
#if(!Boundary32bit_ControlRegRemoved)
    uint8   Boundary32bit_ReadControlRegister(void) ;
    void    Boundary32bit_WriteControlRegister(uint8 control) \
        ;
#endif /* (!Boundary32bit_ControlRegRemoved) */
#if (!(Boundary32bit_UsingFixedFunction && (CY_PSOC5A)))
    void    Boundary32bit_WriteCounter(uint8 counter) \
            ; 
#endif /* (!(Boundary32bit_UsingFixedFunction && (CY_PSOC5A))) */
uint8  Boundary32bit_ReadCounter(void) ;
uint8  Boundary32bit_ReadCapture(void) ;
void    Boundary32bit_WritePeriod(uint8 period) \
    ;
uint8  Boundary32bit_ReadPeriod( void ) ;
#if (!Boundary32bit_UsingFixedFunction)
    void    Boundary32bit_WriteCompare(uint8 compare) \
        ;
    uint8  Boundary32bit_ReadCompare( void ) \
        ;
#endif /* (!Boundary32bit_UsingFixedFunction) */

#if (Boundary32bit_COMPARE_MODE_SOFTWARE)
    void    Boundary32bit_SetCompareMode(uint8 compareMode) ;
#endif /* (Boundary32bit_COMPARE_MODE_SOFTWARE) */
#if (Boundary32bit_CAPTURE_MODE_SOFTWARE)
    void    Boundary32bit_SetCaptureMode(uint8 captureMode) ;
#endif /* (Boundary32bit_CAPTURE_MODE_SOFTWARE) */
void Boundary32bit_ClearFIFO(void)     ;
void Boundary32bit_Init(void)          ;
void Boundary32bit_Enable(void)        ;
void Boundary32bit_SaveConfig(void)    ;
void Boundary32bit_RestoreConfig(void) ;
void Boundary32bit_Sleep(void)         ;
void Boundary32bit_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Counter__CompareModes, Used in Compare Mode retained for backward compatibility of tests*/
#define Boundary32bit__B_COUNTER__LESS_THAN 1
#define Boundary32bit__B_COUNTER__LESS_THAN_OR_EQUAL 2
#define Boundary32bit__B_COUNTER__EQUAL 0
#define Boundary32bit__B_COUNTER__GREATER_THAN 3
#define Boundary32bit__B_COUNTER__GREATER_THAN_OR_EQUAL 4
#define Boundary32bit__B_COUNTER__SOFTWARE 5

/* Enumerated Type Counter_CompareModes */
#define Boundary32bit_CMP_MODE_LT 1u
#define Boundary32bit_CMP_MODE_LTE 2u
#define Boundary32bit_CMP_MODE_EQ 0u
#define Boundary32bit_CMP_MODE_GT 3u
#define Boundary32bit_CMP_MODE_GTE 4u
#define Boundary32bit_CMP_MODE_SOFTWARE_CONTROLLED 5u

/* Enumerated Type B_Counter__CaptureModes, Used in Capture Mode retained for backward compatibility of tests*/
#define Boundary32bit__B_COUNTER__NONE 0
#define Boundary32bit__B_COUNTER__RISING_EDGE 1
#define Boundary32bit__B_COUNTER__FALLING_EDGE 2
#define Boundary32bit__B_COUNTER__EITHER_EDGE 3
#define Boundary32bit__B_COUNTER__SOFTWARE_CONTROL 4

/* Enumerated Type Counter_CompareModes */
#define Boundary32bit_CAP_MODE_NONE 0u
#define Boundary32bit_CAP_MODE_RISE 1u
#define Boundary32bit_CAP_MODE_FALL 2u
#define Boundary32bit_CAP_MODE_BOTH 3u
#define Boundary32bit_CAP_MODE_SOFTWARE_CONTROLLED 4u


/***************************************
 *  Initialization Values
 **************************************/
#define Boundary32bit_CAPTURE_MODE_CONF       0u
#define Boundary32bit_INIT_PERIOD_VALUE       7u
#define Boundary32bit_INIT_COUNTER_VALUE      0u
#if (Boundary32bit_UsingFixedFunction)
#define Boundary32bit_INIT_INTERRUPTS_MASK    ((uint8)((uint8)0u << Boundary32bit_STATUS_ZERO_INT_EN_MASK_SHIFT))
#else
#define Boundary32bit_INIT_COMPARE_VALUE      3u
#define Boundary32bit_INIT_INTERRUPTS_MASK ((uint8)((uint8)0u << Boundary32bit_STATUS_ZERO_INT_EN_MASK_SHIFT) | \
        ((uint8)((uint8)0u << Boundary32bit_STATUS_CAPTURE_INT_EN_MASK_SHIFT)) | \
        ((uint8)((uint8)0u << Boundary32bit_STATUS_CMP_INT_EN_MASK_SHIFT)) | \
        ((uint8)((uint8)0u << Boundary32bit_STATUS_OVERFLOW_INT_EN_MASK_SHIFT)) | \
        ((uint8)((uint8)0u << Boundary32bit_STATUS_UNDERFLOW_INT_EN_MASK_SHIFT)))
#define Boundary32bit_DEFAULT_COMPARE_MODE    1u

#if( 0 != Boundary32bit_CAPTURE_MODE_CONF)
    #define Boundary32bit_DEFAULT_CAPTURE_MODE    ((uint8)((uint8)0u << Boundary32bit_CTRL_CAPMODE0_SHIFT))
#else    
    #define Boundary32bit_DEFAULT_CAPTURE_MODE    (0u )
#endif /* ( 0 != Boundary32bit_CAPTURE_MODE_CONF) */

#endif /* (Boundary32bit_UsingFixedFunction) */


/**************************************
 *  Registers
 *************************************/
#if (Boundary32bit_UsingFixedFunction)
    #define Boundary32bit_STATICCOUNT_LSB     (*(reg16 *) Boundary32bit_CounterHW__CAP0 )
    #define Boundary32bit_STATICCOUNT_LSB_PTR ( (reg16 *) Boundary32bit_CounterHW__CAP0 )
    #define Boundary32bit_PERIOD_LSB          (*(reg16 *) Boundary32bit_CounterHW__PER0 )
    #define Boundary32bit_PERIOD_LSB_PTR      ( (reg16 *) Boundary32bit_CounterHW__PER0 )
    /* MODE must be set to 1 to set the compare value */
    #define Boundary32bit_COMPARE_LSB         (*(reg16 *) Boundary32bit_CounterHW__CNT_CMP0 )
    #define Boundary32bit_COMPARE_LSB_PTR     ( (reg16 *) Boundary32bit_CounterHW__CNT_CMP0 )
    /* MODE must be set to 0 to get the count */
    #define Boundary32bit_COUNTER_LSB         (*(reg16 *) Boundary32bit_CounterHW__CNT_CMP0 )
    #define Boundary32bit_COUNTER_LSB_PTR     ( (reg16 *) Boundary32bit_CounterHW__CNT_CMP0 )
    #define Boundary32bit_RT1                 (*(reg8 *) Boundary32bit_CounterHW__RT1)
    #define Boundary32bit_RT1_PTR             ( (reg8 *) Boundary32bit_CounterHW__RT1)
#else
    
    #if (Boundary32bit_Resolution <= 8u) /* 8-bit Counter */
    
        #define Boundary32bit_STATICCOUNT_LSB     (*(reg8 *) \
            Boundary32bit_CounterUDB_sC8_counterdp_u0__F0_REG )
        #define Boundary32bit_STATICCOUNT_LSB_PTR ( (reg8 *) \
            Boundary32bit_CounterUDB_sC8_counterdp_u0__F0_REG )
        #define Boundary32bit_PERIOD_LSB          (*(reg8 *) \
            Boundary32bit_CounterUDB_sC8_counterdp_u0__D0_REG )
        #define Boundary32bit_PERIOD_LSB_PTR      ( (reg8 *) \
            Boundary32bit_CounterUDB_sC8_counterdp_u0__D0_REG )
        #define Boundary32bit_COMPARE_LSB         (*(reg8 *) \
            Boundary32bit_CounterUDB_sC8_counterdp_u0__D1_REG )
        #define Boundary32bit_COMPARE_LSB_PTR     ( (reg8 *) \
            Boundary32bit_CounterUDB_sC8_counterdp_u0__D1_REG )
        #define Boundary32bit_COUNTER_LSB         (*(reg8 *) \
            Boundary32bit_CounterUDB_sC8_counterdp_u0__A0_REG )  
        #define Boundary32bit_COUNTER_LSB_PTR     ( (reg8 *)\
            Boundary32bit_CounterUDB_sC8_counterdp_u0__A0_REG )
    
    #elif(Boundary32bit_Resolution <= 16u) /* 16-bit Counter */
        #if(CY_PSOC3) /* 8-bit address space */ 
            #define Boundary32bit_STATICCOUNT_LSB     (*(reg16 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__F0_REG )
            #define Boundary32bit_STATICCOUNT_LSB_PTR ( (reg16 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__F0_REG )
            #define Boundary32bit_PERIOD_LSB          (*(reg16 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__D0_REG )
            #define Boundary32bit_PERIOD_LSB_PTR      ( (reg16 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__D0_REG )
            #define Boundary32bit_COMPARE_LSB         (*(reg16 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__D1_REG )
            #define Boundary32bit_COMPARE_LSB_PTR     ( (reg16 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__D1_REG )
            #define Boundary32bit_COUNTER_LSB         (*(reg16 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__A0_REG )  
            #define Boundary32bit_COUNTER_LSB_PTR     ( (reg16 *)\
                Boundary32bit_CounterUDB_sC8_counterdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define Boundary32bit_STATICCOUNT_LSB     (*(reg16 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__16BIT_F0_REG )
            #define Boundary32bit_STATICCOUNT_LSB_PTR ( (reg16 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__16BIT_F0_REG )
            #define Boundary32bit_PERIOD_LSB          (*(reg16 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__16BIT_D0_REG )
            #define Boundary32bit_PERIOD_LSB_PTR      ( (reg16 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__16BIT_D0_REG )
            #define Boundary32bit_COMPARE_LSB         (*(reg16 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__16BIT_D1_REG )
            #define Boundary32bit_COMPARE_LSB_PTR     ( (reg16 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__16BIT_D1_REG )
            #define Boundary32bit_COUNTER_LSB         (*(reg16 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__16BIT_A0_REG )  
            #define Boundary32bit_COUNTER_LSB_PTR     ( (reg16 *)\
                Boundary32bit_CounterUDB_sC8_counterdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */   
    #elif(Boundary32bit_Resolution <= 24u) /* 24-bit Counter */
        
        #define Boundary32bit_STATICCOUNT_LSB     (*(reg32 *) \
            Boundary32bit_CounterUDB_sC8_counterdp_u0__F0_REG )
        #define Boundary32bit_STATICCOUNT_LSB_PTR ( (reg32 *) \
            Boundary32bit_CounterUDB_sC8_counterdp_u0__F0_REG )
        #define Boundary32bit_PERIOD_LSB          (*(reg32 *) \
            Boundary32bit_CounterUDB_sC8_counterdp_u0__D0_REG )
        #define Boundary32bit_PERIOD_LSB_PTR      ( (reg32 *) \
            Boundary32bit_CounterUDB_sC8_counterdp_u0__D0_REG )
        #define Boundary32bit_COMPARE_LSB         (*(reg32 *) \
            Boundary32bit_CounterUDB_sC8_counterdp_u0__D1_REG )
        #define Boundary32bit_COMPARE_LSB_PTR     ( (reg32 *) \
            Boundary32bit_CounterUDB_sC8_counterdp_u0__D1_REG )
        #define Boundary32bit_COUNTER_LSB         (*(reg32 *) \
            Boundary32bit_CounterUDB_sC8_counterdp_u0__A0_REG )  
        #define Boundary32bit_COUNTER_LSB_PTR     ( (reg32 *)\
            Boundary32bit_CounterUDB_sC8_counterdp_u0__A0_REG )
    
    #else /* 32-bit Counter */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define Boundary32bit_STATICCOUNT_LSB     (*(reg32 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__F0_REG )
            #define Boundary32bit_STATICCOUNT_LSB_PTR ( (reg32 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__F0_REG )
            #define Boundary32bit_PERIOD_LSB          (*(reg32 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__D0_REG )
            #define Boundary32bit_PERIOD_LSB_PTR      ( (reg32 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__D0_REG )
            #define Boundary32bit_COMPARE_LSB         (*(reg32 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__D1_REG )
            #define Boundary32bit_COMPARE_LSB_PTR     ( (reg32 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__D1_REG )
            #define Boundary32bit_COUNTER_LSB         (*(reg32 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__A0_REG )  
            #define Boundary32bit_COUNTER_LSB_PTR     ( (reg32 *)\
                Boundary32bit_CounterUDB_sC8_counterdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define Boundary32bit_STATICCOUNT_LSB     (*(reg32 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__32BIT_F0_REG )
            #define Boundary32bit_STATICCOUNT_LSB_PTR ( (reg32 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__32BIT_F0_REG )
            #define Boundary32bit_PERIOD_LSB          (*(reg32 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__32BIT_D0_REG )
            #define Boundary32bit_PERIOD_LSB_PTR      ( (reg32 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__32BIT_D0_REG )
            #define Boundary32bit_COMPARE_LSB         (*(reg32 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__32BIT_D1_REG )
            #define Boundary32bit_COMPARE_LSB_PTR     ( (reg32 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__32BIT_D1_REG )
            #define Boundary32bit_COUNTER_LSB         (*(reg32 *) \
                Boundary32bit_CounterUDB_sC8_counterdp_u0__32BIT_A0_REG )  
            #define Boundary32bit_COUNTER_LSB_PTR     ( (reg32 *)\
                Boundary32bit_CounterUDB_sC8_counterdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */   
    #endif

	#define Boundary32bit_COUNTER_LSB_PTR_8BIT     ( (reg8 *)\
                Boundary32bit_CounterUDB_sC8_counterdp_u0__A0_REG )
				
    #define Boundary32bit_AUX_CONTROLDP0 \
        (*(reg8 *) Boundary32bit_CounterUDB_sC8_counterdp_u0__DP_AUX_CTL_REG)
    
    #define Boundary32bit_AUX_CONTROLDP0_PTR \
        ( (reg8 *) Boundary32bit_CounterUDB_sC8_counterdp_u0__DP_AUX_CTL_REG)
    
    #if (Boundary32bit_Resolution == 16 || Boundary32bit_Resolution == 24 || Boundary32bit_Resolution == 32)
       #define Boundary32bit_AUX_CONTROLDP1 \
           (*(reg8 *) Boundary32bit_CounterUDB_sC8_counterdp_u1__DP_AUX_CTL_REG)
       #define Boundary32bit_AUX_CONTROLDP1_PTR \
           ( (reg8 *) Boundary32bit_CounterUDB_sC8_counterdp_u1__DP_AUX_CTL_REG)
    #endif /* (Boundary32bit_Resolution == 16 || Boundary32bit_Resolution == 24 || Boundary32bit_Resolution == 32) */
    
    #if (Boundary32bit_Resolution == 24 || Boundary32bit_Resolution == 32)
       #define Boundary32bit_AUX_CONTROLDP2 \
           (*(reg8 *) Boundary32bit_CounterUDB_sC8_counterdp_u2__DP_AUX_CTL_REG)
       #define Boundary32bit_AUX_CONTROLDP2_PTR \
           ( (reg8 *) Boundary32bit_CounterUDB_sC8_counterdp_u2__DP_AUX_CTL_REG)
    #endif /* (Boundary32bit_Resolution == 24 || Boundary32bit_Resolution == 32) */
    
    #if (Boundary32bit_Resolution == 32)
       #define Boundary32bit_AUX_CONTROLDP3 \
           (*(reg8 *) Boundary32bit_CounterUDB_sC8_counterdp_u3__DP_AUX_CTL_REG)
       #define Boundary32bit_AUX_CONTROLDP3_PTR \
           ( (reg8 *) Boundary32bit_CounterUDB_sC8_counterdp_u3__DP_AUX_CTL_REG)
    #endif /* (Boundary32bit_Resolution == 32) */

#endif  /* (Boundary32bit_UsingFixedFunction) */

#if (Boundary32bit_UsingFixedFunction)
    #define Boundary32bit_STATUS         (*(reg8 *) Boundary32bit_CounterHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define Boundary32bit_STATUS_MASK             (*(reg8 *) Boundary32bit_CounterHW__SR0 )
    #define Boundary32bit_STATUS_MASK_PTR         ( (reg8 *) Boundary32bit_CounterHW__SR0 )
    #define Boundary32bit_CONTROL                 (*(reg8 *) Boundary32bit_CounterHW__CFG0)
    #define Boundary32bit_CONTROL_PTR             ( (reg8 *) Boundary32bit_CounterHW__CFG0)
    #define Boundary32bit_CONTROL2                (*(reg8 *) Boundary32bit_CounterHW__CFG1)
    #define Boundary32bit_CONTROL2_PTR            ( (reg8 *) Boundary32bit_CounterHW__CFG1)
    #if (CY_PSOC3 || CY_PSOC5LP)
        #define Boundary32bit_CONTROL3       (*(reg8 *) Boundary32bit_CounterHW__CFG2)
        #define Boundary32bit_CONTROL3_PTR   ( (reg8 *) Boundary32bit_CounterHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define Boundary32bit_GLOBAL_ENABLE           (*(reg8 *) Boundary32bit_CounterHW__PM_ACT_CFG)
    #define Boundary32bit_GLOBAL_ENABLE_PTR       ( (reg8 *) Boundary32bit_CounterHW__PM_ACT_CFG)
    #define Boundary32bit_GLOBAL_STBY_ENABLE      (*(reg8 *) Boundary32bit_CounterHW__PM_STBY_CFG)
    #define Boundary32bit_GLOBAL_STBY_ENABLE_PTR  ( (reg8 *) Boundary32bit_CounterHW__PM_STBY_CFG)
    

    /********************************
    *    Constants
    ********************************/

    /* Fixed Function Block Chosen */
    #define Boundary32bit_BLOCK_EN_MASK          Boundary32bit_CounterHW__PM_ACT_MSK
    #define Boundary32bit_BLOCK_STBY_EN_MASK     Boundary32bit_CounterHW__PM_STBY_MSK 
    
    /* Control Register Bit Locations */    
    /* As defined in Register Map, part of TMRX_CFG0 register */
    #define Boundary32bit_CTRL_ENABLE_SHIFT      0x00u
    #define Boundary32bit_ONESHOT_SHIFT          0x02u
    /* Control Register Bit Masks */
    #define Boundary32bit_CTRL_ENABLE            ((uint8)((uint8)0x01u << Boundary32bit_CTRL_ENABLE_SHIFT))         
    #define Boundary32bit_ONESHOT                ((uint8)((uint8)0x01u << Boundary32bit_ONESHOT_SHIFT))

    /* Control2 Register Bit Masks */
    /* Set the mask for run mode */
    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        #define Boundary32bit_CTRL_MODE_SHIFT        0x01u    
        #define Boundary32bit_CTRL_MODE_MASK         ((uint8)((uint8)0x07u << Boundary32bit_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Use CFG2 Mode bits to set run mode */
        #define Boundary32bit_CTRL_MODE_SHIFT        0x00u    
        #define Boundary32bit_CTRL_MODE_MASK         ((uint8)((uint8)0x03u << Boundary32bit_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    /* Set the mask for interrupt (raw/status register) */
    #define Boundary32bit_CTRL2_IRQ_SEL_SHIFT     0x00u
    #define Boundary32bit_CTRL2_IRQ_SEL          ((uint8)((uint8)0x01u << Boundary32bit_CTRL2_IRQ_SEL_SHIFT))     
    
    /* Status Register Bit Locations */
    #define Boundary32bit_STATUS_ZERO_SHIFT      0x07u  /* As defined in Register Map, part of TMRX_SR0 register */ 

    /* Status Register Interrupt Enable Bit Locations */
    #define Boundary32bit_STATUS_ZERO_INT_EN_MASK_SHIFT      (Boundary32bit_STATUS_ZERO_SHIFT - 0x04u)

    /* Status Register Bit Masks */                           
    #define Boundary32bit_STATUS_ZERO            ((uint8)((uint8)0x01u << Boundary32bit_STATUS_ZERO_SHIFT))

    /* Status Register Interrupt Bit Masks*/
    #define Boundary32bit_STATUS_ZERO_INT_EN_MASK       ((uint8)((uint8)Boundary32bit_STATUS_ZERO >> 0x04u))
    
    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define Boundary32bit_RT1_SHIFT            0x04u
    #define Boundary32bit_RT1_MASK             ((uint8)((uint8)0x03u << Boundary32bit_RT1_SHIFT))  /* Sync TC and CMP bit masks */
    #define Boundary32bit_SYNC                 ((uint8)((uint8)0x03u << Boundary32bit_RT1_SHIFT))
    #define Boundary32bit_SYNCDSI_SHIFT        0x00u
    #define Boundary32bit_SYNCDSI_MASK         ((uint8)((uint8)0x0Fu << Boundary32bit_SYNCDSI_SHIFT)) /* Sync all DSI inputs */
    #define Boundary32bit_SYNCDSI_EN           ((uint8)((uint8)0x0Fu << Boundary32bit_SYNCDSI_SHIFT)) /* Sync all DSI inputs */
    
#else /* !Boundary32bit_UsingFixedFunction */
    #define Boundary32bit_STATUS               (* (reg8 *) Boundary32bit_CounterUDB_sSTSReg_stsreg__STATUS_REG )
    #define Boundary32bit_STATUS_PTR           (  (reg8 *) Boundary32bit_CounterUDB_sSTSReg_stsreg__STATUS_REG )
    #define Boundary32bit_STATUS_MASK          (* (reg8 *) Boundary32bit_CounterUDB_sSTSReg_stsreg__MASK_REG )
    #define Boundary32bit_STATUS_MASK_PTR      (  (reg8 *) Boundary32bit_CounterUDB_sSTSReg_stsreg__MASK_REG )
    #define Boundary32bit_STATUS_AUX_CTRL      (*(reg8 *) Boundary32bit_CounterUDB_sSTSReg_stsreg__STATUS_AUX_CTL_REG)
    #define Boundary32bit_STATUS_AUX_CTRL_PTR  ( (reg8 *) Boundary32bit_CounterUDB_sSTSReg_stsreg__STATUS_AUX_CTL_REG)
    #define Boundary32bit_CONTROL              (* (reg8 *) Boundary32bit_CounterUDB_sCTRLReg_ctrlreg__CONTROL_REG )
    #define Boundary32bit_CONTROL_PTR          (  (reg8 *) Boundary32bit_CounterUDB_sCTRLReg_ctrlreg__CONTROL_REG )


    /********************************
    *    Constants
    ********************************/
    /* Control Register Bit Locations */
    #define Boundary32bit_CTRL_CAPMODE0_SHIFT    0x03u       /* As defined by Verilog Implementation */
    #define Boundary32bit_CTRL_RESET_SHIFT       0x06u       /* As defined by Verilog Implementation */
    #define Boundary32bit_CTRL_ENABLE_SHIFT      0x07u       /* As defined by Verilog Implementation */
    /* Control Register Bit Masks */
    #define Boundary32bit_CTRL_CMPMODE_MASK      0x07u 
    #define Boundary32bit_CTRL_CAPMODE_MASK      0x03u  
    #define Boundary32bit_CTRL_RESET             ((uint8)((uint8)0x01u << Boundary32bit_CTRL_RESET_SHIFT))  
    #define Boundary32bit_CTRL_ENABLE            ((uint8)((uint8)0x01u << Boundary32bit_CTRL_ENABLE_SHIFT)) 

    /* Status Register Bit Locations */
    #define Boundary32bit_STATUS_CMP_SHIFT       0x00u       /* As defined by Verilog Implementation */
    #define Boundary32bit_STATUS_ZERO_SHIFT      0x01u       /* As defined by Verilog Implementation */
    #define Boundary32bit_STATUS_OVERFLOW_SHIFT  0x02u       /* As defined by Verilog Implementation */
    #define Boundary32bit_STATUS_UNDERFLOW_SHIFT 0x03u       /* As defined by Verilog Implementation */
    #define Boundary32bit_STATUS_CAPTURE_SHIFT   0x04u       /* As defined by Verilog Implementation */
    #define Boundary32bit_STATUS_FIFOFULL_SHIFT  0x05u       /* As defined by Verilog Implementation */
    #define Boundary32bit_STATUS_FIFONEMP_SHIFT  0x06u       /* As defined by Verilog Implementation */
    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define Boundary32bit_STATUS_CMP_INT_EN_MASK_SHIFT       Boundary32bit_STATUS_CMP_SHIFT       
    #define Boundary32bit_STATUS_ZERO_INT_EN_MASK_SHIFT      Boundary32bit_STATUS_ZERO_SHIFT      
    #define Boundary32bit_STATUS_OVERFLOW_INT_EN_MASK_SHIFT  Boundary32bit_STATUS_OVERFLOW_SHIFT  
    #define Boundary32bit_STATUS_UNDERFLOW_INT_EN_MASK_SHIFT Boundary32bit_STATUS_UNDERFLOW_SHIFT 
    #define Boundary32bit_STATUS_CAPTURE_INT_EN_MASK_SHIFT   Boundary32bit_STATUS_CAPTURE_SHIFT   
    #define Boundary32bit_STATUS_FIFOFULL_INT_EN_MASK_SHIFT  Boundary32bit_STATUS_FIFOFULL_SHIFT  
    #define Boundary32bit_STATUS_FIFONEMP_INT_EN_MASK_SHIFT  Boundary32bit_STATUS_FIFONEMP_SHIFT  
    /* Status Register Bit Masks */                
    #define Boundary32bit_STATUS_CMP             ((uint8)((uint8)0x01u << Boundary32bit_STATUS_CMP_SHIFT))  
    #define Boundary32bit_STATUS_ZERO            ((uint8)((uint8)0x01u << Boundary32bit_STATUS_ZERO_SHIFT)) 
    #define Boundary32bit_STATUS_OVERFLOW        ((uint8)((uint8)0x01u << Boundary32bit_STATUS_OVERFLOW_SHIFT)) 
    #define Boundary32bit_STATUS_UNDERFLOW       ((uint8)((uint8)0x01u << Boundary32bit_STATUS_UNDERFLOW_SHIFT)) 
    #define Boundary32bit_STATUS_CAPTURE         ((uint8)((uint8)0x01u << Boundary32bit_STATUS_CAPTURE_SHIFT)) 
    #define Boundary32bit_STATUS_FIFOFULL        ((uint8)((uint8)0x01u << Boundary32bit_STATUS_FIFOFULL_SHIFT))
    #define Boundary32bit_STATUS_FIFONEMP        ((uint8)((uint8)0x01u << Boundary32bit_STATUS_FIFONEMP_SHIFT))
    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define Boundary32bit_STATUS_CMP_INT_EN_MASK            Boundary32bit_STATUS_CMP                    
    #define Boundary32bit_STATUS_ZERO_INT_EN_MASK           Boundary32bit_STATUS_ZERO            
    #define Boundary32bit_STATUS_OVERFLOW_INT_EN_MASK       Boundary32bit_STATUS_OVERFLOW        
    #define Boundary32bit_STATUS_UNDERFLOW_INT_EN_MASK      Boundary32bit_STATUS_UNDERFLOW       
    #define Boundary32bit_STATUS_CAPTURE_INT_EN_MASK        Boundary32bit_STATUS_CAPTURE         
    #define Boundary32bit_STATUS_FIFOFULL_INT_EN_MASK       Boundary32bit_STATUS_FIFOFULL        
    #define Boundary32bit_STATUS_FIFONEMP_INT_EN_MASK       Boundary32bit_STATUS_FIFONEMP         
    

    /* StatusI Interrupt Enable bit Location in the Auxilliary Control Register */
    #define Boundary32bit_STATUS_ACTL_INT_EN     0x10u /* As defined for the ACTL Register */
    
    /* Datapath Auxillary Control Register definitions */
    #define Boundary32bit_AUX_CTRL_FIFO0_CLR         0x01u   /* As defined by Register map */
    #define Boundary32bit_AUX_CTRL_FIFO1_CLR         0x02u   /* As defined by Register map */
    #define Boundary32bit_AUX_CTRL_FIFO0_LVL         0x04u   /* As defined by Register map */
    #define Boundary32bit_AUX_CTRL_FIFO1_LVL         0x08u   /* As defined by Register map */
    #define Boundary32bit_STATUS_ACTL_INT_EN_MASK    0x10u   /* As defined for the ACTL Register */
    
#endif /* Boundary32bit_UsingFixedFunction */

#endif  /* CY_COUNTER_Boundary32bit_H */


/* [] END OF FILE */

