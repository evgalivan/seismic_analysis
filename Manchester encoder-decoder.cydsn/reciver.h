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

typedef struct{
    int load: 1;        //Load status bit
    int store: 1;       //Store status bit
    int reset: 1;       //Reset status bit
    int F0_not_empty: 1;    //Input FIFO is empty
    int F0_not_full: 1;  //Input FIFO is neither full nor empty
    int F1_full: 1;     //Output FIFO is full
    int F1_partial: 1;  //Output FIFO is neither full nor empty
    int : 1;         //empty bit
}RecieveStatReg;

extern RecieveStatReg curStatRecive;

void    Store(void);
void    PrepareToStore(uint32* recieve_buf, int LENGTH);
void    ClearAllowStoreFlag(void);
void    SetAllowStoreFlag(void);
int     CheckAllowStoreFlag(void);
void    ClearShiftRecieverError(uint32* recieve_buf, int LENGTH);
void    GetStatusFifoReciever (uint8 *RecieverFifo);
int     CheckNumberOfWords(void);

/* [] END OF FILE */
