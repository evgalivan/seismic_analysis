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
//
typedef enum{BUSY,SUCCSSY} TrResult;
TrResult  PrepareToSend(long* ex_buf,int LENGTH);
void    Preload(void);
void    Send(void);
void    ClearStatus(void);

/* [] END OF FILE */
