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
//podaje do funkcji stringa, a ona zwraca adres na nowego odwróconego stringa


#define len 50
typedef uint8_t u8;
typedef uint32_t u32;

char test[] =  "abbaaccdaababacdcdccadcdcaaadddadcccbcbcbcbdbdbac"; 



typedef struct{
    u8 alfabet[4]; // a b c d 
    u8 ileRazy[4]; // a -1 raz, b-2 razy itd
    u32 ktoreMiejsce[4]; // bitowo index 1, a-1,4,5 miejsce, b=2,6 itd
}str;



typedef enum{
    a = 0,
    b = 1,
    c = 2,
    d = 3,
}alfabet;


static int encode(char *wsk, str *data)
{
    memset(data, 0x00, sizeof(str));
    for(u8 i=0; i<len; i++)
    {
        if(wsk[i] == 'a')
        {
            data->alfabet[a] = 1;
            data->ileRazy[a] += 1;
            if(i == 0){
                data->ktoreMiejsce[a] |= 1 << (i+1);
            }
            else
            {
                data->ktoreMiejsce[a] |=  1 << (i+1);
            }
        }
        else if(wsk[i] == 'b')
        {
            data->alfabet[b] = 1;
            data->ileRazy[b] += 1;
            data->ktoreMiejsce[b] |= (i+1) << 1;
            if(i == 0){
                data->ktoreMiejsce[b] |= 1 << (i+1);
            }
            else
            {
                data->ktoreMiejsce[b] |=  1 << (i+1);
            }
        }
        else if(wsk[i] == 'c')
        {

            data->alfabet[c] = 1;
            data->ileRazy[c] += 1;
            if(i == 0){
                data->ktoreMiejsce[c] |= 1 << (i+1);
            }
            else
            {
                data->ktoreMiejsce[c] |=  1 << (i+1);
            }
        }
        else if(wsk[i] == 'd')
        {
            data->alfabet[d] = 1;
            data->ileRazy[d] += 1;
            if(i == 0){
                data->ktoreMiejsce[d] |= 1 << (i+1);
            }
            else
            {
                data->ktoreMiejsce[d] |=  1 << (i+1);
            }
        }
    }

    // printf("\n czy istnieje a %d",  data->alfabet[a]);
    // printf("\n ileRazy a %d",  data->ileRazy[a]);
    // printf("\n pozycja w charze a (bitowo) %d \n",  data->ktoreMiejsce[a]);

    // printf("\n czy istnieje b %d",  data->alfabet[b]);
    // printf("\n ileRazy b %d",  data->ileRazy[b]);
    // printf("\n pozycja w charze b (bitowo) %d \n",  data->ktoreMiejsce[b]);

    // printf("\n czy istnieje c %d",  data->alfabet[c]);
    // printf("\n ileRazy c %d",  data->ileRazy[c]);
    // printf("\n pozycja w charze c (bitowo) %d\n",  data->ktoreMiejsce[c]);

    // printf("\n czy istnieje d %d",  data->alfabet[d]);
    // printf("\n ileRazy d %d",  data->ileRazy[d]);
    // printf("\n pozycja w charze d (bitowo) %d\n",  data->ktoreMiejsce[d]);


    //----------------------WYNIK
    printf(" %d %d %d ", data->alfabet[a], data->ileRazy[a], data->ktoreMiejsce[a]);
    printf(" %d %d %d ", data->alfabet[b], data->ileRazy[b], data->ktoreMiejsce[b]);
    printf(" %d %d %d ", data->alfabet[c], data->ileRazy[c], data->ktoreMiejsce[c]);
    printf(" %d %d %d ", data->alfabet[d], data->ileRazy[d], data->ktoreMiejsce[d]);

    //----------------------------
    return 0;
}



int main()
{
    str data;
    encode(test, &data);

}