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
#include <frame.h>

#define ADC_BITS (24)
#define FULL_RANGE (1UL << ADC_BITS)
#define SIGN_MASK (FULL_RANGE / 2)
#define FROM32TO24MASK (FULL_RANGE - 1)
#define FIRSTBYTE (0x0000ff)
#define MIDDLEBYTE (0x00ff00)
#define LASTLEBYTE (0xff0000)
#define PWM_BITS (15)
#define FULL_PWM_RANGE (1UL << PWM_BITS)
#define PWM_ZERO (FULL_PWM_RANGE / 2)
#define PWM_SIGN_ZERO ((int32)PWM_ZERO)

uint16 Converter32To16(uint32 value){
    uint16 result;
    value &= FROM32TO24MASK; //вычленяем данные ацп из фрейма
    int32 tmp = value;
    //если отрицательное, то добавляем знак в страшем байте
    if (tmp & (int32)SIGN_MASK) tmp |=  0xff << ADC_BITS;
    //проверяем граничные условия
    if (tmp > PWM_SIGN_ZERO) tmp = PWM_SIGN_ZERO; //
    if (tmp < ((-1) * PWM_SIGN_ZERO)) tmp = (-1) * PWM_SIGN_ZERO;
    
    result = tmp + PWM_ZERO;
    
    return result;
}

void DataAdcToDataPwm (frame_t* data){
    PWM_1_WriteCompare1(Converter32To16(data->items[0]));
    PWM_1_WriteCompare2(Converter32To16(data->items[1]));
    PWM_2_WriteCompare1(Converter32To16(data->items[2]));
    PWM_2_WriteCompare2(Converter32To16(data->items[3]));
}

/* [] END OF FILE */
