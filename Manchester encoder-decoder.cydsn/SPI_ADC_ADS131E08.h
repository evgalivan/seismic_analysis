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
#include "types.h"



/***************************************
*   Conditional Compilation Parameters
***************************************/



/***************************************
*        Data Struct Definition
***************************************/



/* 
Description config 1.
1) DAISY_IN
    Daisy-chain and multiple data readback mode.
    This bit determines which mode is enabled.
    0 : Daisy-chain mode
    1 : Multiple data readback mode
2) CLK_EN
    CLK connection (1).
    This bit determines if the internal oscillator signal is connected to
    the CLK pin when the CLKSEL pin = 1.
    0 : Oscillator clock output disabled
    1 : Oscillator clock output enabled
3) DR[2:0]
    Output data rate.
    These bits determine the output data rate and resolution;
    110     1 kSPS
    101     2 kSPS
    100     4 kSPS 
*/

typedef struct {
    //config 1: address 0x01, reset 0x91
    uint8 data_rate: 3;
    uint8 : 1;          //Must be set to 0. This bit reads low.
    uint8 : 1;          //Must be set to 1. This bit reads high.
    uint8 clk_en: 1;
    uint8 daisy_in: 1;
    uint8 : 1;          //Must be set to 1. This bit reads high.
}adc_config1;

/* Description config 2.
1) INT_TEST
    Test signal source.
    This bit determines the source for the test signal.
    0 : Test signals are driven externally
    1 : Test signals are generated internally
2) TEST_AMP
    Test signal amplitude.
    These bits determine the calibration signal amplitude.
    0 : 1 × –(VVREFP – VVREFN) / 2400
    1 : 2 × –(VVREFP – VVREFN) / 2400
3) TEST_FREQ[1:0]
    Test signal frequency.
    These bits determine the test signal frequency.
    00 : Pulsed at fCLK / 221
    01 : Pulsed at fCLK / 220
    10 : Not used
    11 : At dc
*/

typedef struct {
    //config 2: address 0x02, reset 0xE0
    uint8 test_freq: 2;
    uint8 test_amp: 1;
    uint8 : 1;          //Must be set to 0. This bit reads low.
    uint8 int_test: 1;
    uint8 : 3;          //Must be set to 1. This bit reads high.
}adc_config2;

/* Description config 3.
1) PDB_REFBUF
    PDB_REFBUF: Power-down reference buffer
    This bit determines the power-down reference buffer state.
    0 : Power-down internal reference buffer
    1 : Enable internal reference buffer
2) VREF_4V
    Internal reference voltage.
    This bit determines the internal reference voltage, VREF.
    0 : VREF is set to 2.4 V
    1 : VREF is set to 4 V
3) OPAMP_REF
    Op amp reference.
    This bit determines whether the op amp noninverting input
    connects to the OPAMPP pin or to the internally-derived supply
    (AVDD + AVSS) / 2.
    0 : Noninverting input connected to the OPAMPP pin
    1 : Noninverting input connected to (AVDD + AVSS) / 2
4) PDB_OPAMP
    Op amp power-down.
    This bit powers down the op amp.
    0 : Power-down op amp
    1 : Enable op amp
*/
typedef struct {
    //config 3: address 0x03, reset 0x40
    uint8 : 1;          //Reads back as either 1 or 0.
    uint8 : 1;          //Must be set to 0. Reads back as 0.
    uint8 pdb_opamp: 1;
    uint8 opamp_ref: 1;
    uint8 : 1;          //Must be set to 0. This bit reads low
    uint8 vref_4v: 1;
    uint8 : 1;          //Must be set to 1. This bit reads high.
    uint8 pdb_refbuf: 1;
}adc_config3;

/* Description FAULT.
1) COMP_TH[2:0]
    Fault detect comparator threshold.
    These bits determine the fault detect comparator threshold level
    setting. See the Input Out-of-Range Detection section for a
    detailed description.
    Comparator high-side threshold.
    000 : 95%
    001 : 92.5%
    010 : 90%
    011 : 87.5%
    100 : 85%
    101 : 80%
    110 : 75%
    111 : 70%
    Comparator low-side threshold.
    000 : 5%
    001 : 7.5%
    010 : 10%
    011 : 12.5%
    100 : 15%
    101 : 20%
    110 : 25%
    111 : 30%
*/

typedef struct {
    //FAULT: address 0x04, reset 0x00
    uint8 : 5;          //Must be set to 0. Reads back as 0.
    uint8 comp_th: 3;
}adc_FAULT;

/* Description CHnSet.
1) PDn
    Power-down (n = individual channel number).
    This bit determines the channel power mode for the
    corresponding channel.
    0 : Normal operation
    1 : Channel power-down
2) GAINn[2:0]
    PGA gain (n = individual channel number).
    These bits determine the PGA gain setting.
    000 : Do not use
    001 : 1
    010 : 2
    011 : Do not use
    100 : 4
    101 : 8
    110 : 12
    111 : Do not use
3) MUXn[2:0]
    Channel input (n = individual channel number).
    These bits determine the channel input selection.
    000 : Normal input
    001 : Input shorted to (AVDD + AVSS) / 2 (for offset or noise
    measurements)
    010 : Do not use
    011 : MVDD for supply measurement
    100 : Temperature sensor
    101 : Test signal
    110 : Do not use
    111 : Do not use
*/

typedef struct {
    //config 3: address 0x03, reset 0x40
    uint8 mux: 3;
    uint8 : 1;          //Must be set to 0. This bit reads low
    uint8 gain: 3;
    uint8 pd: 1;
}adc_chset;

typedef struct {
    adc_config1 config1;
    adc_config2 config2;
    adc_config3 config3;
    adc_FAULT fault;
    adc_chset ch1set;
    adc_chset ch2set;
    adc_chset ch3set;
    adc_chset ch4set;
    adc_chset ch5set;
    adc_chset ch6set;
    adc_chset ch7set;
    adc_chset ch8set;
}adc_regim;

typedef union {
    uint8 array[12];
    adc_regim regim;
}adc_regim_set;

typedef struct {
    uint32 RData:       8;
    uint32 adc_status:  24;
    uint32 data_ch1:    24;
    uint32 data_ch2:    24;
    uint32 data_ch3:    24;
    uint32 data_ch4:    24;
    uint32 data_ch5:    24;
    uint32 data_ch6:    24;
    uint32 data_ch7:    24;
    uint32 data_ch8:    24;
}Data_field;

extern adc_regim_set ADS131E08_CurSet;
extern Data_field Data_ADS131E08;
extern uint32 SPI_Data_ADS131E08[28];

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
uint8 SPI_ADC_ADS131E08_RReg(uint8);
void SPI_ADC_ADS131E08_WReg(uint8,uint8);
void SPI_ADC_ADS131E08_SendAnyCommand(uint8 command);
result SPI_ADC_ADS131E08_WReg_Check(uint8 byte, uint8 Reg);
uint8 Blocking_SPI_ADC_ReadByte(void);
void SPI_Transaction(uint8* array, uint8 length);

/***************************************
*   Variable with external linkage
***************************************/


/***************************************
*           API Constants
***************************************/

#define ADC_SPI_PACKET_LENGTH (16)

//Settling Time for Different Data Rates
#define ADS131E08_SetTime_1KSPS     (9224)
#define ADS131E08_SetTime_2KSPS     (4616)
#define ADS131E08_SetTime_4KSPS     (2312)

//First byte
#define ADS131E08_WAKEUP      (0x02)
#define ADS131E08_STANDBY     (0x04)
#define ADS131E08_RESET       (0x06)
#define ADS131E08_START       (0x08)
#define ADS131E08_STOP        (0x0A)
#define ADS131E08_OFFSETCAL   (0x1A)
#define ADS131E08_RDATAC      (0x10)
#define ADS131E08_SDATAC      (0x11)
#define ADS131E08_RDATA       (0x12)

//
#define SPI_ADC_ADS131E08_WAKEUP    SPI_ADC_ADS131E08_SendAnyCommand(ADS131E08_WAKEUP)
#define SPI_ADC_ADS131E08_STANDBY   SPI_ADC_ADS131E08_SendAnyCommand(ADS131E08_STANDBY)
#define SPI_ADC_ADS131E08_RESET     SPI_ADC_ADS131E08_SendAnyCommand(ADS131E08_RESET)
#define SPI_ADC_ADS131E08_START     SPI_ADC_ADS131E08_SendAnyCommand(ADS131E08_START)
#define SPI_ADC_ADS131E08_STOP      SPI_ADC_ADS131E08_SendAnyCommand(ADS131E08_STOP)
#define SPI_ADC_ADS131E08_OFFSETCAL SPI_ADC_ADS131E08_SendAnyCommand(ADS131E08_OFFSETCAL)
#define SPI_ADC_ADS131E08_RDataC    SPI_ADC_ADS131E08_SendAnyCommand(ADS131E08_RDATAC)
#define SPI_ADC_ADS131E08_SDataC    SPI_ADC_ADS131E08_SendAnyCommand(ADS131E08_SDATAC)
#define SPI_ADC_ADS131E08_RData     SPI_ADC_ADS131E08_SendAnyCommand(ADS131E08_RDATA)

// Read\Write Masks
#define ADS131E08_FIRSTBYTE_COMMAND_MASK (0x1F) // 010r rrrr, where r rrrr is the starting register address
                                                // 000n nnnn, where n nnnn is the number of registers to write – 1
#define ADS131E08_READ_COMMAND   (0x20)      // 001r rrrr
#define ADS131E08_WRITE_COMMAND  (0x40)      // 001r rrrr

#define ADS131E08_CONFIG1_DEFAULT       (0x96)
#define ADS131E08_CONFIG2_DEFAULT       (0xE0)

#define CONFIG3_PDB_REFBUF_ON           (0x80)
#define CONFIG3_OPAMP_REF_HALF_VCC      (0x08)
#define CONFIG3_PDB_OPAMP_ENABLE        (0x04)

#define ADS131E08_CONFIG3_DEFAULT       (0x40)|\
    CONFIG3_PDB_REFBUF_ON|\
    CONFIG3_OPAMP_REF_HALF_VCC|\
    CONFIG3_PDB_OPAMP_ENABLE

#define ADS131E08_FAULT_DEFAULT         (0x00)
#define ADS131E08_CHSET_DEFAULT         (0x10)
#define ADS131E08_CHSET_POWERDOWN       (0x90)

#define ADS131E08_CONFIG1_ADDRESS   (0x01)
#define ADS131E08_CONFIG2_ADDRESS   (0x02)
#define ADS131E08_CONFIG3_ADDRESS   (0x03)
#define ADS131E08_FAULT_ADDRESS     (0x04)
#define ADS131E08_CH1SET_ADDRESS     (0x05)
#define ADS131E08_CH2SET_ADDRESS     (0x06)
#define ADS131E08_CH3SET_ADDRESS     (0x07)
#define ADS131E08_CH4SET_ADDRESS     (0x08)
#define ADS131E08_CH5SET_ADDRESS     (0x09)
#define ADS131E08_CH6SET_ADDRESS     (0x0A)
#define ADS131E08_CH7SET_ADDRESS     (0x0B)
#define ADS131E08_CH8SET_ADDRESS     (0x0C)

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
