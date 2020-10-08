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

#include <project.h>

void Strobe () {
    Control_Period_Write(1);
    while ((Status_Period_Read()&1) == 0);
    Control_Period_Write(0);
    while ((Status_Period_Read()&1) != 0);    
}

void UpdatePeriod(uint32 NewPeriod) {
    Period_WriteData(NewPeriod);
    Strobe();    
}
    

/* [] END OF FILE */
