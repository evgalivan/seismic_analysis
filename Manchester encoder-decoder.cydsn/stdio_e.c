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
#include "stdio.h"
#include "string.h"
#include "cytypes.h"

static char  *ptok=NULL;

char* strtok_e (char *pstr, char delimiter){
    
    uint8 i = 0;

    //test = *ptok;
    if (pstr == NULL)
    {
        pstr = ptok + 1;
    }
    else ptok = pstr;
    
    char *result    = pstr;
    
    for (i=0; 0!= *pstr; pstr++,i++)
    {
        ptok = pstr;
        if (*pstr == delimiter)
        {
            *pstr = 0;
            break;
        }
    }
    if (i == 0) return NULL;
    return  result;
}
/* [] END OF FILE */
