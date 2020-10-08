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
#include "global.h"

/* Функция проверки, что буффер пуст 
Принимает указатель на кольцевой буфер */

uint8 IsNotEmpty(RingBuff_t* buf){
    uint8 delta;
    CyGlobalIntDisable;
    delta = (buf->begin != buf->end);
    CyGlobalIntEnable;
    if (delta) return 1;
    return 0;
}
/* Функция добавления байта в буфер */

uint8 InsertByte(RingBuff_t* buf, uint8 byte){
    uint8 index = buf->end;
    IN_RING(index);
    if (index == buf->begin)return 1;
    buf->buf[ buf->end ] = byte; 
    buf->end = index;
    return 0;
}

/* Функция извлечения из буффера */

uint8 ExtractByte(RingBuff_t* buf){
    uint8 result = buf->buf[buf->begin];
    IN_RING((buf->begin));
    return result;
}
/* Функция  */

uint8 ByteToInt(uint8 byte){
    uint8 result=0;
    switch (byte){
        case 'F':
        case 'f': result++; 
        case 'E':
        case 'e': result++;
        case 'D':
        case 'd': result++;
        case 'C':
        case 'c': result++;
        case 'B':
        case 'b': result++;
        case 'A':
        case 'a': result++;
        case '9': result++;
        case '8': result++;
        case '7': result++;
        case '6': result++;
        case '5': result++;
        case '4': result++;
        case '3': result++;
        case '2': result++;
        case '1': result++;
        default : 
        case '0': break;
    }
    return result;
}

/* Функция агрегатора сентенции 
возвращает состояние: "Можно разбирать сентенцию или нельзя"
*/
uint8 agg_sent(uart_context *context){
    uint8 result = 0;
        while(IsNotEmpty(&context->primary_buf)){
            uint8 rxData = ExtractByte(&context->primary_buf);
            switch (context->state)
            {
                /* */
                case WAITINGOFDOLLAR: 
                    if (rxData == '$')
                    {
                             //обнуление счетчика символов 
                        context->sentence[context->count_char = 0] = rxData;  //запись символа                        
                        context->state = WAITINGOFSTAR;
                    }
                break;
                    
                case WAITINGOFSTAR:
                    if (rxData == '*')
                    {
                        context->sentence[++context->count_char] = 0x0;
                        context->state = WAITINGOFCHSUM;          //смена состояния для прекращения накомления буфера
                    }
                    else context->sentence[++context->count_char] = rxData;     //запись символа
                break;
                    
                case WAITINGOFCHSUM:
                    context->checksum = (uint8) 16 * ByteToInt(rxData);
                    context->state= WAITINGOFCHSUM2;
                break;
                    
                case WAITINGOFCHSUM2:
                    context->checksum += ByteToInt(rxData);
                    context->state = WAITINGOFDOLLAR;
                    return result = 1;
                break;
            }
        }
        return result;
}
/* [] END OF FILE */
