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
#include <global.h>

typedef struct {
    char chanel[6];
    char port[6];
    char multicast[20];
    char unicast[20];
    char mac[20];
}ip_preset;

int atoh(char *str){
    int result=16 * ByteToInt(str[0]);
    result+= ByteToInt(str[1]);
    return result;
}

static ip_preset IP_Instance;
ip_set IP_Complete;

void IpParsTokenToMac(char* Dest, char* Token){
    Dest[0]=atoh(strtok_e (Token, ':'));
    Dest[1]=atoh(strtok_e (NULL, ':'));
    Dest[2]=atoh(strtok_e (NULL, ':'));
    Dest[3]=atoh(strtok_e (NULL, ':'));
    Dest[4]=atoh(strtok_e (NULL, ':'));
    Dest[5]=atoh(strtok_e (NULL, ':'));
}

void IpParsTokenToAddr(char* Dest, char* Token){
    Dest[0]=atoi(strtok_e (Token, '.'));
    Dest[1]=atoi(strtok_e (NULL, '.'));
    Dest[2]=atoi(strtok_e (NULL, '.'));
    Dest[3]=atoi(strtok_e (NULL, '.'));
}

void IpParsToTokens(uint8* sentence){
    strtok_e ((char*)sentence, ',');
    strcpy(IP_Instance.chanel,strtok_e (NULL, ','));
    strcpy(IP_Instance.mac,strtok_e (NULL, ','));
    strcpy(IP_Instance.unicast,strtok_e (NULL, ','));
    strcpy(IP_Instance.multicast,strtok_e (NULL, ','));
    strcpy(IP_Instance.port,strtok_e (NULL, ','));
}

void IpPars(uint8* sentence){
    IpParsToTokens(sentence);
    IpParsTokenToAddr(IP_Complete.multicast, IP_Instance.multicast);
    IpParsTokenToAddr(IP_Complete.unicast, IP_Instance.unicast);
    IpParsTokenToMac(IP_Complete.mac, IP_Instance.mac);
    IP_Complete.port = atoi(IP_Instance.port);
    IP_Complete.chanel = atoi(IP_Instance.chanel);
}



/* [] END OF FILE */
