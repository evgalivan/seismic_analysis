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


#include <Clock.h>

void Strobe (void) {
    Control_Period_Write(0);
    Control_Period_Write(2);
    register uint8 tmp = Period_SR_STATUS;
    while((tmp)&1){
        tmp = Period_SR_STATUS;   
    }//сигнал load
    Control_Period_Write(1);
    Control_Period_Write(3);    
}

void EmptyFIFO(void){
    register uint8 tmp = Period_SR_STATUS;   
    while((tmp&8) == 0){
        Strobe();
        tmp = Period_SR_STATUS;
    }
}



void UpdateFrequency(uint32 NewPeriod) {
    EmptyFIFO();
    Period_WriteData((uint8)NewPeriod);
    EmptyFIFO(); 
}
    

/* [] END OF FILE */
