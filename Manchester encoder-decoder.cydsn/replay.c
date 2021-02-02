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
#include "frame.h"
#include "msec.h"

static char replay_msg[256];

frame_t time_S={.items={((((('e'<<8)+'m')<<8)+'i')<<8)+'t'}};

int replay(void){
    if (usb_context.need_to_send) return 0;
    sprintf(replay_msg, "\n\r REPLAY MESSAGE \n");
    usb_context.count_to_send = strlen(replay_msg);
    usb_context.message_to_send = (uint8*)replay_msg;
    return usb_context.need_to_send = 1;
}
int insert_header(char* pchar){
    return sprintf(pchar,"$D");
}

int long2five(char* pchar, uint32 L){
    int cnt=0;
    char* initial_pointer = pchar;
    pchar +=sprintf(pchar,",");
    char byte;
    for(;cnt<5;cnt++){
       byte = (L&0x7f)|0x80;
       L>>=7;
       pchar +=sprintf(pchar,"%c",byte);
    }
    return pchar - initial_pointer;
}

int insert_frame(char* pchar, frame_t frame){
    char* initial_pointer = pchar;
    for (int i=0;i<WORDS_QUANTITY;i++){
        pchar += long2five(pchar, frame.items[i]);
    }
    return pchar - initial_pointer;
}
uint32 W_data=((((('a'<<8)+'t')<<8)+'a')<<8)+'d';
uint32 W_smpl=((((('l'<<8)+'p')<<8)+'m')<<8)+'s';



int insert_label(char* pchar){
    char* initial_pointer = pchar;
    pchar += long2five(pchar, W_data);//sprintf(pchar,",%02x%02x%02x%02x",'a','t','a','d');
    pchar += long2five(pchar, W_smpl);//sprintf(pchar,",%02x%02x%02x%02x",'l','p','m','s');
    pchar += long2five(pchar, seconds);
    pchar += long2five(pchar, mseconds);
    return pchar - initial_pointer;
}

int insert_crc8(char* pchar, char* pfirst){
    char crc8 = 0;
    while (pfirst<pchar){
        crc8 ^= *(pfirst++);
    }
    return sprintf(pchar,"*aa\r");//sprintf(pchar,"*%02x\n\r",crc8);
}

int ms_marker(void){
    char* pchar = replay_msg;
    char* pfirst = replay_msg+1;
    int length;
    pchar += insert_header(pchar);
    pchar += insert_label(pchar);
    time_S.items[2] = seconds;
    time_S.items[3] = mseconds;
    pchar += insert_frame(pchar, time_S);
    pchar += insert_crc8(pchar, pfirst);
    usb_context.count_to_send = strlen(replay_msg);
    usb_context.message_to_send = (uint8*)replay_msg;
    return usb_context.need_to_send = 1;
}

int msg_creator(void *buf){
    char* pchar = replay_msg;
    char* pfirst = replay_msg+1;
    frame_t* first = (frame_t*)buf;
    frame_t* last =  &first[7];
    int length;
    pchar += insert_header(pchar);
    pchar += insert_frame(pchar, *first);
    pchar += insert_frame(pchar, *last);
    pchar += insert_crc8(pchar, pfirst);
    usb_context.count_to_send = strlen(replay_msg);
    usb_context.message_to_send = (uint8*)replay_msg;
    return usb_context.need_to_send = 1;
}
/* [] END OF FILE */
