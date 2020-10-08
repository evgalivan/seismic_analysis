/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/


#include <SPI_ADC_ADS131E08.h>
#include <SPI_ADC.h>
#include <project.h>


/*
    The Register Write command is a two-byte command followed by the register data input. 
    The first byte contains the command and register address. 
    The second command byte specifies the number of registers to write – 1.
*/

uint8 tmp, byte_adc_read;
static uint8 transfer_buf[27];
static uint8 spi_adc_busy_flag = 0;
uint32 SPI_Data_ADS131E08[28] = {0};
Data_field Data_ADS131E08;

/*
uint8 Blocking_SPI_ADC_ReadByte(void){
    while (SPI_ADC_GetRxBufferSize() == 0);
    return SPI_ADC_ReadRxData();
}
*/


void SPI_Transaction(uint8* array, uint8 length){
    uint8 ToSend = length;
    uint8 ToRead = length;
    uint8* writebyte = array;
    uint8* readbyte = array;
    while (CSn_Read() == 0);
    while (ToSend){
        uint8 status = SPI_ADC_ReadTxStatus();
        if (0 != (SPI_ADC_STS_TX_FIFO_NOT_FULL & status)) {
            ToSend--;
            SPI_ADC_WriteTxData(*writebyte);
            writebyte++;
        }
        if (ToRead > ToSend){
            if (0 != (SPI_ADC_STS_RX_FIFO_NOT_EMPTY & status)){
                ToRead--;
                *readbyte = SPI_ADC_ReadRxData();
                readbyte++;
            }
        }
    }
    while (ToRead){
        uint8 status = SPI_ADC_ReadTxStatus();
        if (0 != (SPI_ADC_STS_RX_FIFO_NOT_EMPTY & status)){
                ToRead--;
                *readbyte = SPI_ADC_ReadRxData();
                readbyte++;
            }
    }
}

void SPI_ADC_ADS131E08_WReg(uint8 byte, uint8 Reg){
    register uint8 tmp = ADS131E08_WRITE_COMMAND;
    tmp |= Reg & ADS131E08_FIRSTBYTE_COMMAND_MASK;
    transfer_buf[0] = tmp;
    transfer_buf[1] = 0x0;
    transfer_buf[2] = byte;
    SPI_Transaction(transfer_buf, 3);
}


uint8 SPI_ADC_ADS131E08_RReg(uint8 Reg){
    register uint8 tmp = ADS131E08_READ_COMMAND;
    tmp |= Reg & ADS131E08_FIRSTBYTE_COMMAND_MASK;
    
    transfer_buf[0] = tmp;
    transfer_buf[1] = 0x0;
    SPI_Transaction(transfer_buf, 3);
    return transfer_buf[2];
}
//#define SPI_ADC_ADS131E08_SendAnyCommand(command)   SPI_Transaction(&command,1)
void SPI_ADC_ADS131E08_SendAnyCommand(uint8 command){
    SPI_Transaction(&command,1);
}

result SPI_ADC_ADS131E08_WReg_Check(uint8 byte, uint8 Reg){
    SPI_ADC_ADS131E08_WReg(byte, Reg);
    
    byte_adc_read = SPI_ADC_ADS131E08_RReg(Reg);
    if (Reg != ADS131E08_CONFIG3_ADDRESS){
        if (byte == byte_adc_read) return SUCCESS;
    }
    else {
        if ((byte>>1) == (byte_adc_read>>1)) return SUCCESS;
    }
    return ERROR;
}

/* [] END OF FILE */
