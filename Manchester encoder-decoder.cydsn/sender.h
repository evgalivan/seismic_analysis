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
#include "global.h"


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

/* [] END OF FILE */
