#include "intern.h"
#include "md2.h"
#include <stdio.h>
#include <string.h>
#include <memory.h>

#define DEBUG

#ifndef DEBUG
#define printf(...) 0
#endif // DEBUG


ExcerciseType data = {0};

static status prepareData(ExcerciseType *data);



// static status CalculateCypher(ExcerciseType *data)
// {

// }


static status prepareData(ExcerciseType *data)
{
    status retVal = NOT_OK;

    if(data == NULL)
    {
        printf("\n Eror empty data");
        return retVal;
    }
    else
    {
        data->internalCounter = 0u;
        /* NUMER OF TESTS */
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
        BYTE text[3];
        for(uint8_t y=0; y<MAX_WORDS; y++)
        {
            
            if(data->words[0][y] != '\n')
            {
                
                // text[y] = data->words[data->internalCounter][y];
                printf("\n SLOWA[%d] : %c ", y, data->words[0][y]);
            }
            // else
            // {
            //     /* Calculate Hash */
            //     md2_init(&ctx);
            //     md2_update(&ctx, text, strlen(text));
            //     md2_final(&ctx, buf);
            //     data->hash[data->internalCounter] = buf;

            //     /* Prepare data for next word */
            //     data->internalCounter += 1;
            //     y = 0;
            // }
            // printf("\n Kolejne słowo");
        }
        
  

        // BYTE text1[] = {"abc"};
        // BYTE buf[16];
	    // MD2_CTX ctx;
        // md2_init(&ctx);
        // md2_update(&ctx, text1, strlen(text1));
        // md2_final(&ctx, buf);

       // data->TestCount--;
      //  }




    }


    // printf("\n Liczba testow: %d ", data->TestCount);
    // for(uint8_t j=0; j<BYTES_OF_CYPHER; j++)
    // {
    //     printf("\n Cypher[%d]: %d ",j, data->Cypher[j]);
    // }
    //  printf("\n Liczba SLOW: %d ", data->howManyWords);

    // for(uint8_t x=0; x<MAX_SIZE_WORDS; x++)
    // {
    //     printf("\n WORDS[%d]: %c ",x, data->words[0][x]);
    // }
    // for(uint8_t y=0; y<MAX_SIZE_WORDS; y++)
    // {
    //     printf("\n HASH[%d]: %c ",y, data->hash[y]);
    // }

}


status inputData(ExcerciseType *data)
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
    printf("\n Algorytm start ! ");
    prepareData(&data);

    // for(uint8_t j=0; j<BUFOR_LENGTH; j++)
    // {
    //     printf("\n Data[%d]: %c ",j, data.input[j]);
    // }

   
}

