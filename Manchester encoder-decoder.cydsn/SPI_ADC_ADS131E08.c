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

#include <global.h>
#include <SPI_ADC_ADS131E08.h>
#include <SPI_ADC.h>


/*
    The Register Write command is a two-byte command followed by the register data input. 
    The first byte contains the command and register address. 
    The second command byte specifies the number of registers to write – 1.
*/

static uint8 transfer_buf[27];
exchanged_subject Data_ADS131E08;


void SPI_ADC_ADS131E08_WReg(uint8 byte, uint8 Reg){
    register uint8 tmp = 0x40;
    tmp |= Reg & ADS131E08_FIRSTBYTE_WRITE_COMMAND_MASK;
    
    transfer_buf[0] = tmp;
    transfer_buf[1] = 0x0;
    transfer_buf[2] = byte;
    SPI_ADC_PutArray(transfer_buf, 3);
    SPI_ADC_ClearRxBuffer();
}

/* [] END OF FILE */
