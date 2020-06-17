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
#include "USB_UART_cdc.h"
#include <Clock.h>
#include <BitCounterDec.h>
#include <Agg_sent.h>


uint32 incr_compare = 512; // зависит от той частоты, которую мы хотим получить
uint32 value_usec_gps, value_sec_gps;

uint8 errorStatus = 0u;
uint8 data_ready_flag = 0, lenght_rxData_buf;
uint8 count_char = 0,                      // счетчик длины буфера
        count_char_mirror=0;             // счетчик для записи двух символов после "*"
uint8 GlobalPrepareFlag = 0, GlobalTimeReady = 0;
int delta_clock = 0;


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

uart_context usb_context={{{},0,0}, .sentence_ready=0}, gps_context={{{},0,0}, .sentence_ready=0};


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
            InsertByte(&gps_context.primary_buf, rxData);
        }
    }while((rxStatus & UART_RX_STS_FIFO_NOTEMPTY) != 0u);
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

uint32 main_freq =  72000000LL; //сдули BusClock
uint32 desired_freq  = 1024000LL;
uint32 divider_freq = (32LL);
uint32 capacity = (0xffffffffLL);  //емкость сумматора 

inline long long PeriodCalculation(long long desired_freq){
    return ( long long )  capacity * divider_freq * desired_freq / (1 * main_freq);    //977343669
    //period = 1956895899;
}

#define LENGTH_OF(Array) (sizeof(Array)/sizeof(Array[0]))
#define SENDER      //RESIEVER or SENDER
volatile int storeflag=0, length = 72;
volatile long long  period;
enum Regim curRegim = DUMMY; 
inline uint32 set_increment(uint32 discr_freq){return (desired_freq/ discr_freq);}
int main(void)
{
    p_ex_buf = ex_buf;
    
    gps1 = mess_gps1;
    gps2 = mess_gps2;
    
    incr_compare =set_increment(1000L); 
    period = ( long long ) PeriodCalculation( desired_freq);    //977343669
    //period = 1956895899;
    CyGlobalIntDisable; /* Enable global interrupts. */
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    // Инициализация устройств Encoder
    TransmitShiftReg_Start( );
    BitCounterEnc_Start( );
    
	// Инициализация устройств Clock
    UART_Start();
    
    #define USBFS_DEVICE    (0u)
    USBUART_Start(USBFS_DEVICE, USBUART_5V_OPERATION);
    
    isr_rx_StartEx(RxIsr);
    Period_Start();
    SigmaReg_Start();
    Boundary32bit_Start();
//    usec_counter_Start();
//    sec_counter_Start();
//    cap_comp_tc_Start();
    isr_comp_Start();
//    isr_cap_Start();
    isr_tc_Start();
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
        LED_ON_Write(1);
        UpdatePeriod(0xffffffff);
        UpdatePeriod(0x7fffffff);
        UpdatePeriod(0x3fffffff);
        UpdatePeriod(0x1fffffff);
        UpdatePeriod(0x0fffffff);
        UpdatePeriod(0x07ffffff);
        UpdatePeriod(period);
        UpdatePeriod(period);
    #ifdef SENDER
        
//  Polling_GPS();
    
//DO NOT TOUCH !!!!!
        Control_Capture_Write(0);
        FrameAllow_Write(0);
        
        PrepareToSend(massage,0);
        Send();
        
        while(PrepareToSend(massage,0)==TRBUSY);
        
        FrameAllow_Write(1);
//only if You known about it
        
        
        //while (PrepareToStore(recieve_buf) == RCBUSY);
        
        //int massage = 0xAAAA5555;
        int flag = 0, true_word = 0;
        int store = 0;
        uint8 RecieverFIFO[1]= {0x0};
        uint32 *p1=ex_buf;
        CyGlobalIntDisable;
        GlobalTimeReady = 1;
        value_sec_gps = 0x55555555;
        curRegim = TIME_STMP;
        CyGlobalIntEnable;
        
        while(1) 
        {
            if (agg_sent(&gps_context))
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
            
            USBARTInitCDC();
            
            Service_USB();
            if (agg_sent(&usb_context)) usb_context.sentence_ready=1;
            if (usb_context.sentence_ready){
                /* разбор сентенций USB
                всего 3 сентенции: 
                Установка частоты дискритизации                 
                Установка поправки времени распространения      
                Установка начальных адресов сегмента            IPSET */
                if (strncmp((char*)usb_context.sentence, "$IPSET", 6) == 0)
                {
                    /*функция парсера ipset*/
                    IpPars(usb_context.sentence);
                    switch (IP_Complete.chanel){
                        case 1: curRegim = ADDR_SET1; break;
                        case 2: curRegim = ADDR_SET2; break;
                        case 3: curRegim = ADDR_SET3; break;
                        case 4: curRegim = ADDR_SET4; break;
                        default: break;                        
                    }
                    renumber_frame.pattern.MacHiHi = 207;
                    renumber_frame.pattern.MacHiLo = 210;
                    renumber_frame.pattern.MacMiHi = IP_Complete.mac[2];
                    renumber_frame.pattern.MacMiLo = IP_Complete.mac[3];
                    renumber_frame.pattern.MacLoHi = IP_Complete.mac[4];
                    renumber_frame.pattern.MacLoLo = IP_Complete.mac[5];
                    renumber_frame.pattern.port = IP_Complete.port;
                    renumber_frame.pattern.MulHiHi = IP_Complete.multicast[0];
                    renumber_frame.pattern.MulHiLo = IP_Complete.multicast[1];
                    renumber_frame.pattern.MulLoHi = IP_Complete.multicast[2];
                    renumber_frame.pattern.MulLoLo = IP_Complete.multicast[3];
                    renumber_frame.pattern.UniHiHi = IP_Complete.unicast[0];
                    renumber_frame.pattern.UniHiLo = IP_Complete.unicast[1];
                    renumber_frame.pattern.UniLoHi = IP_Complete.unicast[2];
                    renumber_frame.pattern.UniLoLo = IP_Complete.unicast[3];
                } 
                //TO DO !!!!
                /* Установка частоты дискритизации                 
                Установка поправки времени распространения */
                
                usb_context.sentence_ready = 0;
            }
            GeneralSend (curRegim );
            
            //UpdatePeriod(period);
            
            
           
            
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
