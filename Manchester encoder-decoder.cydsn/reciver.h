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



extern volatile unsigned int CountToRecieve;

typedef enum{RCBUSY,RCSUCCSSY} RcResult;

inline void Store(uint32 tmp);
RcResult    PrepareToStore(void);//, int LENGTH);
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

/* [] END OF FILE */
