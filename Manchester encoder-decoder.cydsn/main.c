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
#include "sender.h"
#include <Clock.h>
#include <BitCounterDec.h>

uint32 incr_compare = 512; // зависит от той частоты, которую мы хотим получить
uint32 value_usec_gps, value_sec_gps;

uint8 errorStatus = 0u;
uint8 data_ready_flag=0, lenght_rxData_buf;
uint8 count_char=0,                      // счетчик длины буфера
        count_char_mirror=0;             // счетчик для записи двух символов после "*"
uint8 GlobalPrepareFlag = 0;
int delta_clock = 0;
typedef enum {WAITINGOFDOLLAR, WAITINGOFSTAR, WAITINGOFCHSUM, ENDSENTENS} State;

gps_rmc RMC_stamp, *pRMC_stamp;

State state;
Sentence sentence;

char mess_gps1[100], mess_gps2[100], *gps1, *gps2;
char *pstr;
char str1[10]="ab,de,,h", *pteststr1, str2[10], *pteststr2, test;

long long utc_time;
long long pps_time;
uint32 capture_flag, UnixTime1, time_ready_flag = 0;
long long UnixTime2;
char *ptok, *ptok2;

char* strtok_e (char *pstr1, const char* pstr2){
    
    uint8 i = 0;
    test = *ptok;
    if (pstr1 == NULL)
    {
        pstr1 = ptok2 + 1;
    }
    if (pstr1 != NULL)
        {
            ptok = pstr1;
        }
    for (i = 0; i < strlen(pstr1); i++)
    {        
        if (*pstr1 == *pstr2)
        {
            *pstr1 = 0;
            ptok2 = pstr1;
            break;
        }
        pstr1++;
    }
    if (i == 0) return NULL;
    return  ptok;
}

/*******************************************************************************
* Function Name: RxIsr
********************************************************************************
*
* Summary:
*  Interrupt Service Routine for RX portion of the UART
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
CY_ISR(RxIsr)
{
    uint8 rxStatus;         
    uint8 rxData;
    char* tmp;
    
    do
    {
        /* Read receiver status register */
        rxStatus = UART_RXSTATUS_REG;

        if((rxStatus & (UART_RX_STS_BREAK      | UART_RX_STS_PAR_ERROR |
                        UART_RX_STS_STOP_ERROR | UART_RX_STS_OVERRUN)) != 0u)
        {
            /* ERROR handling. */
            errorStatus |= rxStatus & ( UART_RX_STS_BREAK      | UART_RX_STS_PAR_ERROR | 
                                        UART_RX_STS_STOP_ERROR | UART_RX_STS_OVERRUN);
        }
        
        if((rxStatus & UART_RX_STS_FIFO_NOTEMPTY) != 0u)
        {
            /* Read data from the RX data register */
            rxData = UART_RXDATA_REG;
            
            switch (state)
            {
                /* */
                case WAITINGOFDOLLAR: 
                    if (rxData == '$')
                    {
                        count_char=1;       //обнуление счетчика символов 
                        *gps1 = rxData;     //запись символа                        
                        state = WAITINGOFSTAR;
                    }
                break;
                    
                case WAITINGOFSTAR:
                    if (rxData == '*')
                    {                    
                        count_char_mirror = count_char;  //после присвоения будем записывать еще 2 символа
                        state = WAITINGOFCHSUM;          //смена состояния для прекращения накомления буфера
                    }
                    count_char++;
                    gps1++;             //следующий элемент массива
                    *gps1 = rxData;     //запись символа                    
                break;
                    
                case WAITINGOFCHSUM: 
                    if ( (count_char - count_char_mirror) > 2) state = ENDSENTENS;
                    count_char++;       //инкремент счетчика символов
                    gps1++;             //следующий элемент массива
                    *gps1 = rxData;     //запись символа                    
                break;
                    
                case ENDSENTENS:
                    gps1 -= (count_char - 1);
                    tmp = gps1;
                    gps1 = gps2;
                    gps2 = tmp;
                    data_ready_flag = 1;
                    lenght_rxData_buf = count_char;
                    state = WAITINGOFDOLLAR;
                break;
            }
        }
    }while((rxStatus & UART_RX_STS_FIFO_NOTEMPTY) != 0u);
    count_char = count_char;
}

// задание структуры для регистра статуса ShiftReg
struct control {
    int load: 1;        //Load status bit
    int store: 1;       //Store status bit
    int reset: 1;       //Reset status bit
    int F0_not_empty: 1;    //Input FIFO is empty
    int F0_not_full: 1;  //Input FIFO is neither full nor empty
    int F1_full: 1;     //Output FIFO is full
    int F1_partial: 1;  //Output FIFO is neither full nor empty
    int : 1;         //empty bit
} Control;

uint32 ex_buf[4];
uint32 massage[1] = { 0xFAAAAAAF };

uint32 *p_ex_buf;

uint32 main_freq =  72000000LL;
uint32 desired_freq  = 1024000LL;
uint32 divider_freq = (32LL);
uint32 capacity = (0xffffffffLL);  //емкость сумматора 



#define LENGTH_OF(Array) (sizeof(Array)/sizeof(Array[0]))
#define SENDER      //RESIEVER or SENDER
volatile int storeflag=0, length = 72;
volatile long long  period;


int main(void)
{
    p_ex_buf = ex_buf;
    
    gps1 = mess_gps1;
    gps2 = mess_gps2;
    
    incr_compare = desired_freq/ 1000L; 
    period = ( long long ) capacity * divider_freq * desired_freq / (1 * main_freq);    //977343669
    //period = 1956895899;
    CyGlobalIntDisable; /* Enable global interrupts. */
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    // Инициализация устройств Encoder
    TransmitShiftReg_Start( );
    BitCounterEnc_Start( );
    
	// Инициализация устройств Clock
    UART_Start();
    isr_rx_StartEx(RxIsr);
    Period_Start();
    SigmaReg_Start();
    Boundary32bit_Start();
    usec_counter_Start();
    sec_counter_Start();
    cap_comp_tc_Start();
    // Инициализация прерываний
    //StartFrame_Start();
    
    isr_Load_TrShReg_Start();

    TransmitWordShift_Start( );
    TransmitWordShift_Disable( );
    int delay = 0xFFffff;
    
    CyGlobalIntEnable; /* Enable global interrupts. */    

//    TransmitShiftReg_WriteData(1);
//    BitCounterEnc_WriteCounter(BitCounterEnc_ReadCompare());
//    *(char*)(&curStat)=TransmitShiftReg_SR_STATUS;
//    while( 0 != curStat.F0_not_empty ){
//        StartTransmit_Write(1);
//        delay = 0xFFF;
//        while (delay--);
//        StartTransmit_Write(0);
//        *(char*)(&curStat)=TransmitShiftReg_SR_STATUS;
//    }
    
    #ifdef SENDER
        
        while (value_sec_gps == 0){
            if (data_ready_flag)
            {
                data_ready_flag = 0;
                sentence = WhatSentence(gps2);
                switch (sentence)
                {
                    case RMC:
                        RMC_stamp = ReadGpsTime(gps2);
                        UnixTime1 = GpsDataToInt(RMC_stamp.data);
                        UnixTime1 += GpsTimeToInt(RMC_stamp.utc_time);
                        value_sec_gps = UnixToCountSec(UnixTime1);
                        value_usec_gps = UnixToCountuSec(UnixTime1);
                        time_ready_flag = 1;
                        break;
                    case GGA:
                        break;
                    case GLL:
                        break;
                    case GSA:
                        break;
                    case GSV:
                        break;
                    case VTG:
                        break;
                    case ERROR:
                        break;
                }
            }
        }
    
    
        Control_Capture_Write(0);
        FrameAllow_Write(0);
        
        PrepareToSend(massage,0);
        Send();
        
        while(PrepareToSend(massage,0)==TRBUSY);
        
        FrameAllow_Write(1);
        
        
        //while (PrepareToStore(recieve_buf) == RCBUSY);
        
        //int massage = 0xAAAA5555;
        int flag = 0, true_word = 0;
        int store = 0;
        uint8 RecieverFIFO[1]= {0x0};
        uint32 *p1=ex_buf;
        UpdatePeriod(period);
        
        while(1) 
        {
            if (data_ready_flag)
            {
                                
                pteststr1 = str1;                             
                pteststr2 = str2;                
                data_ready_flag = 0;
                sentence = WhatSentence(gps2);
                switch (sentence)
                {
                    case RMC:
                        RMC_stamp = ReadGpsTime(gps2);
                        UnixTime1 = GpsDataToInt(RMC_stamp.data);
                        UnixTime1 += GpsTimeToInt(RMC_stamp.utc_time);
                        value_sec_gps = UnixToCountSec(UnixTime1);
                        value_usec_gps = UnixToCountuSec(UnixTime1);                        
                        data_ready_flag = 0;
                        break;
                    case GGA:
                        break;
                    case GLL:
                        break;
                    case GSA:
                        break;
                    case GSV:
                        break;
                    case VTG:
                        break;
                    case ERROR:
                        break;
                }
            }          
            //UpdatePeriod(period);
            //int i=0;

            
            //if (CheckAllowStoreFlag()) 
                
            
            
            //, length);
            
            if (GlobalPrepareFlag && time_ready_flag){
                time_ready_flag = 0;
                PrepareToSend(ex_buf,LENGTH_OF(ex_buf));
                p_ex_buf = ex_buf;
            }
            
            //          *******Передатчик*******
            //while (PrepareToStore(recieve_buf) == RCBUSY);
    //        if (1)
    //        {
    //            //if (StartButton_Read() != 0)
    //            if (PrepareToSend(ex_buf,length) == TRSUCCSSY )
    //            {
    //                
    //    //            delay = 0x1; //‭44AA200‬
    //    //            while (delay--);
    //                //flag = 1;
    //
    ////                for (int i = 0; i < 72; i++) recieve_buf[i] = 0x0;
    //    //            LED = 0;
    //    //            LED_ON_Write(LED);
    //    //            delay = 0x1; //‭44AA200‬
    //    //            while (delay--);
    //                LED_ON_Write(0);
    //    //            delay = 0x1;
    //    //            while (delay--);
    //                Send();
    //                
    //                
    //    //            flag++;
    //            }
    //            
    //        }
           /* else if (flag != 0)
            {
                flag = 0;
                
                //PrepareToStore(recieve_buf, length);
                //PrepareToSend(ex_buf, length); 
                Send();
                */
                    
                /*
                TransmitShiftReg_WriteData(massage);
                BitCounterEnc_WriteCounter(BitCounterEnc_ReadCompare());
                StartTransmit_Write(1);
                
                starttransmit_write(0);
                wordshifted_clearpending();
                */
    //        }

            if (CheckNeedLoadFlag()){
                ClearNeedLoadFlag();
                Load();
            }
            
            //                  ********КОНЕЦ Передатчика********
            
            
            //                  *******Приемник*******               
            
    //        if (CheckAllowPrepareToStoreFlag()) {
    //                //ClearShiftRecieverError((uint32*)massage, LENGTH_OF(massage));
    //                ClearAllowPrepareToStoreFlag();
    //                PrepareToStore(recieve_buf, length);
    //      }
                    
            
    //        if (CheckAllowStoreFlag())
    //        {
    //            ClearAllowStoreFlag();
                //Store();
    //        }
            
    //        for (i = 0; i < length; i++){
    //            if( *p1 == *p2 ) true_word++;
    //                p1++;
    //                p2++;
            
    //        if (*(p1+length-1) == *(p2+length-1)){
    //            LED = 1;
    //            LED_ON_Write(LED);
    //        }
            
                
    //        
    //        true_word = 0;
            
            
            
            

    //        GetStatusFifoReciever(RecieverFIFO);
    //        GetStatusFifoReciever(RecieverFIFO);
        }

    #else
            
        FrameAllow_Write(0);
        
        PrepareToSend(massage,0);
        Send();
        
        while(PrepareToSend(massage,0)==BUSY);
        
        FrameAllow_Write(1);
        
        ClearShiftRecieverError((uint32*)massage, LENGTH_OF(massage));
        
        //int massage = 0xAAAA5555;
        int flag = 0, LED = 0, true_word = 0;
        int store = 0;
        uint8 RecieverFIFO[1]= {0x0};    
        
        while(1) 
        {
            int i=0;
            //PrepareToSend(ex_buf,LENGTH_OF(ex_buf));
            
            //          *******Передатчик*******
            
            if (CheckAllowPrepareToStoreFlag())
            {
                ClearAllowPrepareToStoreFlag();
                for (int i = 0; i < 72; i++) recieve_buf[i] = 0x0;
                LED = 0;
                LED_ON_Write(LED);     
                PrepareToStore(recieve_buf, length);
                PrepareToSend(ex_buf, length); 
                Send();
            }
           
            if (CheckNeedLoadFlag()){
                ClearNeedLoadFlag();
                Load();
            }
            
            //                  ********КОНЕЦ Передатчика********
            
            
            //                  *******Приемник*******               
            
    //        if (CheckNumberOfWords() <= 0) {
    //                //ClearShiftRecieverError((uint32*)massage, LENGTH_OF(massage));
    //                PrepareToStore(recieve_buf, length);
    //        }
                    
            
            if (CheckAllowStoreFlag())
            {
                ClearAllowStoreFlag();
                Store();
            }
            
    //        for (i = 0; i < length; i++){
    //            if( *p1 == *p2 ) true_word++;
    //                p1++;
    //                p2++;
                if (*(p1+length-1) == *(p2+length-1)){
                    LED = 1;
                    LED_ON_Write(LED);
                }
                
    //        
    //        true_word = 0;
            
            
            
            
            GetStatusFifoReciever(RecieverFIFO);
            GetStatusFifoReciever(RecieverFIFO);

           
            //                  ********КОНЕЦ Приемника********
            
            
        }
    #endif
}

/* [] END OF FILE */
