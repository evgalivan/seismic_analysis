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

#include <frame.h>

extern exchange_unit DataToTransmit;

#include <TransmitShiftReg.h>
//
// задание структуры для регистра статуса ShiftReg
typedef struct{
    int load: 1;        //Load status bit
    int store: 1;       //Store status bit
    int reset: 1;       //Reset status bit
    int F0_is_empty: 1;    //Input FIFO is empty
    int F0_not_full: 1;  //Input FIFO is neither full nor empty
    int F1_full: 1;     //Output FIFO is full
    int F1_partial: 1;  //Output FIFO is neither full nor empty
    int : 1;         //empty bit
}statReg;
extern statReg curStat;

typedef enum {TRBUSY,TRSUCCSSY} TrResult;
TrResult    PrepareToSend(uint32* ex_buf,int LENGTH);
void        ClearErrorShiftReg(uint32* TestWord);
void        Load(void);
void        Send(void);
void        ClearStatus(void);
void        SetNeedLoadFlag(void);
void        ClearNeedLoadFlag(void);
int         CheckNeedLoadFlag (void);
int         GetStatusFifoSender (void);
void        PrepareTheOutputBuffer(void);

/* [] END OF FILE */
