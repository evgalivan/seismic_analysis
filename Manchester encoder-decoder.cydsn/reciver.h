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
#include <RecieveShiftReg.h>
#include <BitCounterDec.h>
#include <StartTransmit.h>
#include <FrameAllow.h>
#include <frame.h>

extern exchange_unit RecivedData;

typedef struct{
    int load: 1;            //Load status bit
    int store: 1;           //Store status bit
    int reset: 1;           //Reset status bit
    int F0_is_empty: 1;    //Input FIFO is empty
    int F0_not_full: 1;     //Input FIFO is neither full nor empty
    int F1_full: 1;         //Output FIFO is full
    int F1_partial: 1;      //Output FIFO is neither full nor empty
    int : 1;                //empty bit
}RecieveStatReg;
extern RecieveStatReg curStatRecive;

typedef enum{RCBUSY,RCSUCCSSY} RcResult;

void        Store(void);
RcResult    PrepareToStore(uint32* recieve_buf, int LENGTH);
void        ClearRcStatus(void);
void        ClearAllowStoreFlag(void);
void        SetAllowStoreFlag(void);
int         CheckAllowStoreFlag(void);
int         CheckNumberOfWords(void);
void        SetAllowPrepareToStoreFlag(void);
int         CheckAllowPrepareToStoreFlag(void);
void        ClearAllowPrepareToStoreFlag(void);
void        ClearShiftRecieverError(uint32* recieve_buf, int LENGTH);
void        GetStatusFifoReciever (uint8 *RecieverFifo);
unsigned int isRecived(void);
void ClearRecived(void);
void SetRecived(void);

/* [] END OF FILE */
