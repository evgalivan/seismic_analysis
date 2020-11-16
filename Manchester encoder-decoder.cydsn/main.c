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
//#include "sender.h"
#include "reciver.h"
#include "replay.h"
#include "USB_UART_cdc.h"

uint32 incr_compare = 512; // зависит от той частоты, которую мы хотим получить
uart_context usb_context={{{},0,0}, .sentence_ready=0};

uint32 first_frame[4], last_frame[4];
uint32 flag_ff_store = 0;

// задание структуры для регистра статуса ShiftReg
struct control {
    int load: 1;        //Load status bit
    int store: 1;       //Store status bit
    int reset: 1;       //Reset status bit
    int F0_is_empty: 1;    //Input FIFO is empty
    int F0_not_full: 1;  //Input FIFO is neither full nor empty
    int F1_full: 1;     //Output FIFO is full
    int F1_partial: 1;  //Output FIFO is neither full nor empty
    int : 1;         //empty bit
} Control;


uint32 massage[1] = { 0xFAAAAAAF };

uint32 main_freq =  72000000LL;
uint32 desired_freq  = 4096000LL;
uint32 divider_freq = (8LL);
uint32 capacity = (0xffLL);  //емкость сумматора 




volatile int storeflag=0, length = 72;
static volatile long long  period;
uint32 the_output_buffer_prepared_but_not_sended = 0;

         int seconds;
         int mseconds;
volatile int mseconds_flag = 0;


int main(void)
{
    incr_compare = desired_freq / 1L; 
    period = ( long long ) capacity * divider_freq * desired_freq / (1 * main_freq);    //977343669

    CyGlobalIntDisable; /* Enable global interrupts. */
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    // Инициализация устройств Encoder
    //TransmitShiftReg_Start( );
    //BitCounterEnc_Start( );
    
    #define USBFS_DEVICE    (0u)
    USBUART_Start(USBFS_DEVICE, USBUART_5V_OPERATION);

	// Инициализация устройств Decoder
    RecieveShiftReg_Start() ;
	Waiter_Start() ;
    BitCounterDec_Start() ;
    VDAC8_1_Start();
    Comp_1_Start();
    Comp_2_Start();
    Opamp_1_Start();
    Counter_1_Start();
    isr_update_time_Start();
    
//    Period_Start();
//    SigmaReg_Start();
//    Boundary8bit_Start();
//    usec_counter_Start();
//    cap_comp_tc_Start();
    
    // Инициализация прерываний
    //StartFrame_Start();
    EndFrame_Start();
    //isr_Load_TrShReg_Start();
	WordShifted_Start();
    //isr_TransmitWordShift_Start( );
    //isr_TransmitWordShift_Disable( );
    
	
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    /*Call func PrepareToStore until initialisation*/
    PrepareToStore();
    
    while(1) 
    {
             
            USBUARTInitCDC();
            Send_USB();
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
//                    switch (IP_Complete.chanel){
//                        case 1: curRegim = ADDR_SET1; break;
//                        case 2: curRegim = ADDR_SET2; break;
//                        case 3: curRegim = ADDR_SET3; break;
//                        case 4: curRegim = ADDR_SET4; break;
//                        default: break;                        
//                    }
//                    renumber_frame.pattern.MacHiHi = 207;
//                    renumber_frame.pattern.MacHiLo = 210;
//                    renumber_frame.pattern.MacMiHi = IP_Complete.mac[2];
//                    renumber_frame.pattern.MacMiLo = IP_Complete.mac[3];
//                    renumber_frame.pattern.MacLoHi = IP_Complete.mac[4];
//                    renumber_frame.pattern.MacLoLo = IP_Complete.mac[5];
//                    renumber_frame.pattern.port = IP_Complete.port;
//                    renumber_frame.pattern.MulHiHi = IP_Complete.multicast[0];
//                    renumber_frame.pattern.MulHiLo = IP_Complete.multicast[1];
//                    renumber_frame.pattern.MulLoHi = IP_Complete.multicast[2];
//                    renumber_frame.pattern.MulLoLo = IP_Complete.multicast[3];
//                    renumber_frame.pattern.UniHiHi = IP_Complete.unicast[0];
//                    renumber_frame.pattern.UniHiLo = IP_Complete.unicast[1];
//                    renumber_frame.pattern.UniLoHi = IP_Complete.unicast[2];
//                    renumber_frame.pattern.UniLoLo = IP_Complete.unicast[3];
                } 
                //TO DO !!!!
                /* Установка частоты дискритизации                 
                Установка поправки времени распространения */
                
                usb_context.sentence_ready = 0;
            }
            //replay();
        if(flag_write_done){
            flag_write_done = 0;

            
            //Copy first and last frames of datagramm
            memcpy(first_frame, (void*) line_buf, 4);
            memcpy(last_frame, (void*) &line_buf[PACKET_LENGTH - 4], 4);
            
            // Pars Frames like in imitator COM project
            Msg_COM(first_frame);
            
            // set flag for sending second frame in usb context
            flag_ff_store = 1;
            
            PrepareToStore();
        }
        
        // after usb context sended first frame will send second frame
        if ((flag_ff_store == 1) && (usb_context.need_to_send == 0)){
            //reset flag first frame 
            flag_ff_store = 0;
            
            // Pars Frames like in imitator COM project
            Msg_COM(last_frame);
        }
    }
}

/* [] END OF FILE */
