/*******************************************************************************
* File Name: SPI_ADC_ADS131E08.h
* Version 1.0
*
* Description:
*  Contains the function prototypes, constants and register definition
*  of the SPI ADS131E08 protocol.
*
* Note:
*  None
*
********************************************************************************
* 
* 
* 
* 
*******************************************************************************/

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */


/***************************************
*   Conditional Compilation Parameters
***************************************/



/***************************************
*        Data Struct Definition
***************************************/

typedef struct {
    uint32 status: 24;
    uint32 data0: 24;
    uint32 data1: 24;
    uint32 data2: 24;
    uint32 data3: 24;
    uint32 data4: 24;
    uint32 data5: 24;
    uint32 data6: 24;
    uint32 data7: 24;
}burst_read;

typedef union{
    uint8 array[27];
    burst_read Fields;
}exchanged_subject;

extern exchanged_subject Data_ADS131E08;

/***************************************
*        Function Prototypes
***************************************/

//System commands
void SPI_ADC_ADS131E08_WakeUp(void);
void SPI_ADC_ADS131E08_StandBy(void);
void SPI_ADC_ADS131E08_Reset(void);
void SPI_ADC_ADS131E08_Start(void);
void SPI_ADC_ADS131E08_Stop(void);
void SPI_ADC_ADS131E08_OffSetCal(uint8);

//Data read commands
void SPI_ADC_ADS131E08_RDataC(void);
void SPI_ADC_ADS131E08_SDataC(void);
void SPI_ADC_ADS131E08_RData(void);

//Register read commands
void SPI_ADC_ADS131E08_RReg(uint8);
void SPI_ADC_ADS131E08_WReg(uint8,uint8);

/***************************************
*   Variable with external linkage
***************************************/


/***************************************
*           API Constants
***************************************/

//First byte
#define ADS131E08_FIRSTBYTE_WAKEUP      (0x02)
#define ADS131E08_FIRSTBYTE_STANDBY     (0x04)
#define ADS131E08_FIRSTBYTE_RESET       (0x06)
#define ADS131E08_FIRSTBYTE_START       (0x08)
#define ADS131E08_FIRSTBYTE_STOP        (0x0A)
#define ADS131E08_FIRSTBYTE_OFFSETCAL   (0x1A)
#define ADS131E08_FIRSTBYTE_RDARAC      (0x10)
#define ADS131E08_FIRSTBYTE_SDATAC      (0x11)
#define ADS131E08_FIRSTBYTE_RDATA       (0x12)

// Read\Write Masks
#define ADS131E08_FIRSTBYTE_WRITE_COMMAND_MASK (0x1F) // 010r rrrr, where r rrrr is the starting register address
#define ADS131E08_SECONDBYTE_WRITE_COMMAND_MASK (0x1F) // 000n nnnn, where n nnnn is the number of registers to write – 1


/***************************************
*    Initial Parameter Constants
***************************************/




/***************************************
*             Registers
***************************************/




/***************************************
*       Register Constants
***************************************/

/* Status Register Definitions */
#define SPI_ADC_STS_SPI_DONE_SHIFT             (0x00u)
#define SPI_ADC_STS_TX_FIFO_EMPTY_SHIFT        (0x01u)
#define SPI_ADC_STS_TX_FIFO_NOT_FULL_SHIFT     (0x02u)
#define SPI_ADC_STS_BYTE_COMPLETE_SHIFT        (0x03u)
#define SPI_ADC_STS_SPI_IDLE_SHIFT             (0x04u)
#define SPI_ADC_STS_RX_FIFO_FULL_SHIFT         (0x04u)
#define SPI_ADC_STS_RX_FIFO_NOT_EMPTY_SHIFT    (0x05u)
#define SPI_ADC_STS_RX_FIFO_OVERRUN_SHIFT      (0x06u)

#define SPI_ADC_STS_SPI_DONE           ((uint8) (0x01u << SPI_ADC_STS_SPI_DONE_SHIFT))
#define SPI_ADC_STS_TX_FIFO_EMPTY      ((uint8) (0x01u << SPI_ADC_STS_TX_FIFO_EMPTY_SHIFT))
#define SPI_ADC_STS_TX_FIFO_NOT_FULL   ((uint8) (0x01u << SPI_ADC_STS_TX_FIFO_NOT_FULL_SHIFT))
#define SPI_ADC_STS_BYTE_COMPLETE      ((uint8) (0x01u << SPI_ADC_STS_BYTE_COMPLETE_SHIFT))
#define SPI_ADC_STS_SPI_IDLE           ((uint8) (0x01u << SPI_ADC_STS_SPI_IDLE_SHIFT))
#define SPI_ADC_STS_RX_FIFO_FULL       ((uint8) (0x01u << SPI_ADC_STS_RX_FIFO_FULL_SHIFT))
#define SPI_ADC_STS_RX_FIFO_NOT_EMPTY  ((uint8) (0x01u << SPI_ADC_STS_RX_FIFO_NOT_EMPTY_SHIFT))
#define SPI_ADC_STS_RX_FIFO_OVERRUN    ((uint8) (0x01u << SPI_ADC_STS_RX_FIFO_OVERRUN_SHIFT))

/***************************************
*       Macros
***************************************/

/* Returns true if componentn enabled */
#define SPI_ADC_IS_ENABLED (0u != (SPI_ADC_TX_STATUS_ACTL_REG & SPI_ADC_INT_ENABLE))

/* Retuns TX status register */
#define SPI_ADC_GET_STATUS_TX(swTxSts) ( (uint8)(SPI_ADC_TX_STATUS_REG | \
                                                          ((swTxSts) & SPI_ADC_TX_STS_CLR_ON_RD_BYTES_MASK)) )
/* Retuns RX status register */
#define SPI_ADC_GET_STATUS_RX(swRxSts) ( (uint8)(SPI_ADC_RX_STATUS_REG | \
                                                          ((swRxSts) & SPI_ADC_RX_STS_CLR_ON_RD_BYTES_MASK)) )

/* [] END OF FILE */
