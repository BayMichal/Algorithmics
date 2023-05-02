/*******************************************************************
* Filename:   intern.c
* Author:     Michał Bajkos
* Details:    Intern implementation for Excercise Colliding Encoding Google
*********************************************************************/
/*************************** HEADER FILES ***************************/
#include "intern.h"
#include "md2.h"
#include <stdio.h>
#include <string.h>
#include <memory.h>

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

        for(uint8_t x=0; x<MAX_SIZE_WORDS; x++)
        {
            printf("\n WORDS[%d]: %c ",x, data->words[0][x]);
        }
        for(uint8_t y=0; y<MAX_SIZE_WORDS; y++)
        {
            printf("\n HASH[%d]: %c ",y, data->hash[y]);
        }
    #endif /* InputDataDebug */

    return OK;
}


static status inputData(InputDataType *data)
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


void StartProgram()
{
    inputData(&data);
    prepareData(&data, &HashData);
}

