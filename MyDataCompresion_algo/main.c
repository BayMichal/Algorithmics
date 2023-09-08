/*******************************************************************
* Filename:   main.c
* Author:     Michał Bajkos
* Details:    Main Program file
*********************************************************************/
/*************************** HEADER FILES ***************************/
/******************************************************************************/
#include <string.h>
#include "stdio.h"
#include "stdint.h"
#include "DefAnderror.h"

char test[] =  "aqVILGBKCXQs434wZgmZtrCQdFCCh+6WnWK6Kmpon6f2ezCCAUQwgeugAwIBAgIJAQAAGPIAAAAAMAoGCCqGSM49BAMCMBIxEDAOBgNVBAMMB1RTCFdQQzEwIBcNMjlwMjE4MTM0MTEWhgPOTk50TEyMzEyMzU5NTIaMBIxEDAOBgNVBAMMBzAwNjltMDAwWTATBgcq"; 

typedef enum{
    a = 0,
    b = 1,
    c = 2,
    d = 3,
}alfabet;

#define DEBUG

static u8 whichIs(char *ptr)
{
    u8 Value = 0;

    if(ptr == NULL)
    {
        CONSOLE("Error %d ", INCORECT_POINTER);
    }
    else
    {
        switch(*ptr)
        {
            case 'A':
                Value = 0;
            break;

            case 'a':
                Value = 1;
            break;
            
            case 'q':
                Value = 2;
            break;
            
            case 'v':
                Value = 3;
            break;
            
            case 'V':
                Value = 4;
            break;
            
            case 'f':
                Value = 5;
            break;
            
            case 'g':
                Value = 6;
            break;
            
            case 'h':
                Value = 7;
            break;
            
            case 'i':
                Value = 8;
            break;
        }
    }
    
    return Value;
}

static int encode(char *wsk, str *data)
{
    if((wsk == NULL) || (data == NULL))
    {
        CONSOLE("Error %d ", INCORECT_POINTER);
    }
    else
    {
        memset(data, 0x00, sizeof(str));
        u8 counter = 0;
        for(u8 i=0; i<len; i++)
        {
            for(u8 j=_NULL; j<Z_LOWER; j++)
            {
                if(wsk[counter] == j)
                {
                    u8 charT = whichIs(&wsk[counter]);
                    data->alfabet[charT] = 1;
                    data->ileRazy[charT] += 1;
                    if(j == 0){
                        data->ktoreMiejsce[charT] |= 1 << (i+1);
                    }
                    else
                    {
                        data->ktoreMiejsce[charT] |=  1 << (i+1);
                    }
                }
            }
            
            counter++;
        }
    }

    
    #ifdef DEBUG
        printf(" %ld %ld %ld ", data->alfabet[a], data->ileRazy[a], data->ktoreMiejsce[a]);
        printf(" %ld %ld %ld ", data->alfabet[b], data->ileRazy[b], data->ktoreMiejsce[b]);
        printf(" %ld %ld %ld ", data->alfabet[c], data->ileRazy[c], data->ktoreMiejsce[c]);
        printf(" %ld %ld %ld ", data->alfabet[d], data->ileRazy[c], data->ktoreMiejsce[c]);
    #endif

    return 0;
}



int main()
{
    str data;
    encode(test, &data);
}