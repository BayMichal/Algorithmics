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
#include "logic.h"




#define len 4
#define size 50
typedef uint8_t u8;
typedef uint32_t u32;
typedef long int li;

char test[] =  "AqAAL"; 



typedef struct{
    li alfabet[size]; // a b c d 
    li ileRazy[size]; // a -1 raz, b-2 razy itd
    li ktoreMiejsce[size]; // bitowo index 1, a-1,4,5 miejsce, b=2,6 itd
}str;

typedef enum{
    a_ = 'a',
    b_ = 'b',
    c_ = 'c',
    d_ = 'd',
    e_ = 'e',
    f_ = 'f',
    g_ = 'g',
}asd;

typedef enum{
    a = 0,
    b = 1,
    c = 2,
    d = 3,
}alfabet;



static u8 whichIs(char *ptr)
{
    u8 Value = 0;

    switch(*ptr)
    {
        case 'a':
            Value = 0;
        break;

        case 'A':
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

    printf("\n DUPA char: %c, =  %d ", *ptr, Value);

    return Value;
}

static int encode(char *wsk, str *data)
{
    memset(data, 0x00, sizeof(str));



        u8 counter = 0;
        for(u8 i=0; i<len; i++)
        {
            printf("\n CASE %c ", wsk[i]);

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
    

    //----------------------WYNIK---------------------------------------------------
    printf(" %ld %ld %ld ", data->alfabet[a], data->ileRazy[a], data->ktoreMiejsce[a]);
    printf(" %ld %ld %ld ", data->alfabet[b], data->ileRazy[b], data->ktoreMiejsce[b]);
    printf(" %ld %ld %ld ", data->alfabet[c], data->ileRazy[c], data->ktoreMiejsce[c]);
    printf(" %ld %ld %ld ", data->alfabet[d], data->ileRazy[c], data->ktoreMiejsce[c]);
    //-----------------------------------------------------------------------------
    return 0;
}



int main()
{
    str data;
    encode(test, &data);

}