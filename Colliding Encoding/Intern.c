/*******************************************************************
* Filename:   intern.c
* Author:     Michał Bajkos
* Details:    Intern implementation for Excercise Colliding Encoding Google
*********************************************************************/
/*************************** HEADER FILES ***************************/
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include "defines.h"
#include "intern.h"
#include "md2.h"
#include "ascii-table.h"

#define DEBUG

#ifndef DEBUG
#define printf(...) 0
#endif // DEBUG


/**************************** VARIABLES *****************************/
InputDataType data = {0};
HashDataType HashData = {0};


/*********************** STATIC FUNCTION DECLARATIONS ***************/
static status prepareData(InputDataType *data, HashDataType* hashData);
static status inputData(InputDataType *data);

/*********************** FUNCTION DEFINITIONS ***********************/
static status prepareData(InputDataType *data, HashDataType* hashData)
{
    status retVal = NOT_OK;

    /* Guard empty data */
    if(data == NULL)
    {
        printf("\n Eror empty data");
        return retVal;
    }
    else
    {
        /* Count Number Test Case*/
        data->internalCounter = 0u;

        /* How many includes input data  */
        data->TestCount = data->input[BYTE_NUMER_OF_TESTS] - '0';

    //    while(data->TestCount)
    //    {
            /* CYPHER */
            uint8_t counterBytesCypher  = 0;
            uint8_t counterBytes = 1;

            for(counterBytes=1; counterBytes<BUFOR_LENGTH; counterBytes++)
            {
                if( data->input[counterBytes]  != ' ' && data->input[counterBytes]  != EOF)
                {
                    if(data->input[counterBytes] - '0' >= 0 && data-> input[counterBytes] - '0' < 10)
                    {

                        data->Cypher[counterBytesCypher] = data->input[counterBytes] - '0';
                        counterBytesCypher++;
                    }
                    if(counterBytesCypher == BYTES_OF_CYPHER)
                    {
                        break;
                    }
                }
            }
        /* HOW MANY WORDS */
        data->howManyWords = data->input[counterBytes + OFFSET_IN_BUFFOR] - '0';

        /* WORDS */
        uint8_t counterBytes2 = 0;

        for(uint8_t k = 1; k<BUFOR_LENGTH; k++)
        {
            data->words[data->internalCounter][counterBytes2] = data->input[counterBytes + OFFSET_IN_BUFFOR + k + 1];
            counterBytes2++;
        }


        /* Here should be decide about cypher words */
        counterBytes2 = 0;
        BYTE buf[16];
        MD2_CTX ctx;
       
       /* Last value measured '/n' */
        uint8_t lastVal = 0;
        for(uint8_t y=0; y<MAX_WORDS*3; y++)
        {
            if(data->words[0][y] != '\n')
            {
                #ifdef HASH_DEBUG 
                    printf("\n WORDBE[%d] : %c ", y, data->words[0][y]);
                #endif
            }
            else
            {
                /* Size of current word*/
                hashData->size =  (y - lastVal);
                printf("\b \n Sizeof TEXT: %d ",  hashData->size);
                printf("\b \n Index of Hash: %d ",  hashData->hashIndex);

                /* Create New Bufor for HASH*/
                BYTE text[hashData->size];

                /* Var for control HASH Bufor */
                uint8_t loopVariable = (hashData->size)-1;

                /* Loop for create HASH bufor */
                for(int z=y; z>=lastVal; z--)
                {
                    if(data->words[data->internalCounter][z] != '\n')
                    {
                        text[loopVariable] = data->words[data->internalCounter][z];
                        printf("\n SLOWA[%d] : %c ", loopVariable, text[loopVariable]);
                        loopVariable--;
                    }
                }

              
                /* Calculate Hash */
                md2_init(&ctx);
                md2_update(&ctx, text, hashData->size); /* strlen version, strcspn -> length without \n */
                md2_final(&ctx, buf);
                printf("\n ROZMIAR TO: %d", hashData->size);

                /* HASH DEBUG */
                #ifdef HASH_DEBUG 
                    BYTE hash_ABC[MD2_BLOCK_SIZE] = {0x67, 0xC7, 0xA6, 0x94, 0xB8, 0xF9, 0x93, 0x96, 0xBB, 0x19, 0x46, 0xEB, 0x79, 0x50, 0xE2, 0xC4};
                    BYTE hash_BC[MD2_BLOCK_SIZE] = {0x18, 0x1C, 0x30, 0x93, 0x34, 0x72, 0x02, 0x15, 0xFB, 0x56, 0xC4, 0xD1, 0xB5, 0x3A, 0x3F, 0x88};
                    BYTE hash_BCD[MD2_BLOCK_SIZE] = {0x14,0x3D,0x9F,0xB1,0x03,0xBE,0xEC,0xAA,0x15,0xB5,0xF5,0xF9,0x80,0x04,0x52,0x5B};
                    BYTE hash_CDE[MD2_BLOCK_SIZE] = {0x45,0xE8,0x81,0x9C,0x43,0x71,0xB4,0x8C,0xFA,0xB5,0xB8,0xA5,0xCD,0x75,0xD5,0xEF};
                    int pass = 1;
                    pass = pass && !memcmp(hash_ABC, buf, MD2_BLOCK_SIZE);
                    printf("\n MD2 HASH RESULT: %s \n",  pass ? "SUCCEEDED" : "FAILED");
                #endif

                /* Add Hash to Bufor with All Hashes*/
                hashData->hash[hashData->hashIndex] = (int)buf;

                /* Mark where you finish to prepare for next word and than Hash */
                lastVal = y+1;

                /* Iterate index to prepare for next Hash */
                hashData->hashIndex++;
            }
            
            // printf("\n\n Kolejne słowo");
        }
    }

    #ifdef InputDataDebug
        printf("\n Liczba testow: %d ", data->TestCount);
        for(uint8_t j=0; j<BYTES_OF_CYPHER; j++)
        {
            printf("\n Cypher[%d]: %d ",j, data->Cypher[j]);
        }
        printf("\n Liczba SLOW: %d ", data->howManyWords);

        for(uint8_t x=0; x<15; x++)
        {
            printf("\n WORDS[%d]: %c ",x, data->words[0][x]);
        }
    #endif /* InputDataDebug */

    return OK;
}


inline static status inputData(InputDataType *data)
{
    int i=0;
    int c;
    while ((c = getchar()) != EOF) {

        /* OverWrite secure */
        if(i == BUFOR_LENGTH)
        {
            break;
        }
        /* Data Packed to bufor */
        else
        {
            data->input[i] = c;
            i++;
        }
    }
    return OK;
}


static status alphaBett(uint8_t *ascii, InputDataType *data, uint8_t *CounterUpdate)
{
    status retVal = NOT_OK;


    /* Guard empty data */
    if(data == NULL)
    {
        printf("\n Eror empty data");
    }
    else
    {
        /* to calculate witch index in cyper is
        * start counter_cypher=0
        *
        * counter_cypher++          | A
        * counter_cypher++          | B
        * counter_cypher++          | C
        * [...]
        */
        uint8_t counter_cypher = 0u;

        /* output index data */
        uint8_t counter_data = *CounterUpdate;

        for(uint8_t i=(uint8_t)A_UPPER; i<(uint8_t)Z_UPPER; i++)
        {
            if(*ascii == (uint8_t)i)
            {
                printf("\n alphaBett_ %c _  data->output[%d] = %d ",*ascii, counter_data, data->Cypher[counter_cypher]);
                data->output[counter_data] = data->Cypher[counter_cypher];
                break;
            }
            counter_cypher++;
        }

        printf("\n ZATRZYMALEM SIE NA %d ", counter_data);
        retVal = OK;
    }

    return retVal;
}

static status calculateData(InputDataType *data)
{
    status retVal = NOT_OK;

    printf("\n\n\n");

    /* Guard empty data */
    if(data == NULL)
    {
        printf("\n Eror empty data");
    }
    else
    {
            /* in buf:
            * A |
            * B | 1 WORD
            * C |
            *   | counterWord++;
            * C |
            * B | 2 WORD
            * [...]
            *   | counterWord++
            *   | break (secound in row NULL at data)
            */
            uint8_t counterWord = 0u;
            
            /* in buf:
            * A |                   | test++
            * B | 1 WORD            | test++
            * C |                   | buf[test] = MY_ASCII_CHAR && test++
            *   | counterWord++;    | test++
            * C |                   | buf[test] = MY_ASCII_CHAR && test++
            * B | 2 WORD            | test++
            * [...]                 | [...]
            *   | end
            */
            uint8_t SpaceCounter = 0u;

            for(uint8_t j=0u; j<MAX_SIZE_WORDS; j++)
            {
                /* Guard case*/
                if(data->words[0][j] == _NULL && data->words[0][j+1] == _NULL)
                {
                    break;
                }
                /* Counter case*/
                else if (data->words[0][j] == _NULL ||  data->words[0][j] == 0x0a)
                {
                    data->output[SpaceCounter] = MY_ASCII_NEW_LINE;
                    counterWord++;
                    SpaceCounter++;
                }
                /* Data case  */
                else
                {
                    alphaBett(&data->words[0][j], data, &SpaceCounter);
                    SpaceCounter++;
                }
                
            }
        data->outputSize =  (SpaceCounter-2u);          /* Update final size*/
        data->output[SpaceCounter] = MY_END_ASCII;      /* Marked last byte in final buf */
        
        retVal = OK;
    }

    return retVal;
}


static status calculate(InputDataType *data)
{
    status retVal = NOT_OK;

  printf("\n \n");
    /* Guard empty data */
    if(data->outputSize == 0 || data->output == NULL)
    {
        printf("\n Eror empty data");
    }
    else
    {
        uint8_t counter = 0u;
        uint8_t previos = 0u;
        long int MeaValues[MAX_WORDS] = {0};

        for(uint8_t i=0u; i<=(data->outputSize+1); i++)
        {
            // printf("\n NOWY ZNAK %d", i);
            /* New line means new packet of data to calculate */
            if( data->output[i] == MY_ASCII_NEW_LINE)
            {
                /* remember cypher */
                for(uint8_t x=previos; x<i; x++)
                {
                    MeaValues[counter] = data->output[x] << (x*8);
                }

                printf("\n test = %ld ",  MeaValues[counter]);
                       
                previos = i+1;
                counter++;
            }
        }

        for(uint8_t j=0; j<counter; j++)
        {
            for(uint8_t k=0; k<counter-1; k++)
            {
                if(k != j)
                {
                    if(MeaValues[j] == MeaValues[k])
                    {
                        printf(" \n\n WYNIK: POWTARZA SIE  [%d] %ld =  [%d] %ld ",j, MeaValues[j],k, MeaValues[k] );
                        retVal = OK;
                        break;
                    } 
                }

            }
            if(retVal == OK)    
                break;
        }

    }

    return retVal;
}


status StartProgram(void)
{
    status retVal = NOT_OK;
    
    retVal |= inputData(&data);
    printf("\n STATUS 1 %s ",  retVal ? "OK" : "NOT_OK");

    retVal |= prepareData(&data, &HashData);
    printf("\n STATUS 2 %s ",  retVal ? "OK" : "NOT_OK");

    retVal |= calculateData(&data);
    printf("\n STATUS 3 %s ",  retVal ? "OK" : "NOT_OK");

    retVal |= calculate(&data);
    printf("\n STATUS 4 %s ",  retVal ? "OK" : "NOT_OK");

    return (retVal ? OK : NOT_OK);
}

