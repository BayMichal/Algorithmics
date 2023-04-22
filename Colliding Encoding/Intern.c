#include "intern.h"

#define DEBUG

#ifndef DEBUG
#define printf(...) 0
#endif // DEBUG


static status prepareData(ExcerciseType *data);



ExcerciseType data = {0};

static status prepareData(ExcerciseType *data)
{
    status retVal = NOT_OK;

    if(data == NULL)
    {
        return retVal;
    }
    else
    {
        data->internalCounter = 0u;
        /* NUMER OF TESTS */
        data->TestCount = data->input[BYTE_NUMER_OF_TESTS] - '0';

      //  while(data->TestCount)
      //  {
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
            data->words[data->internalCounter][counterBytes2] = data->input[counterBytes + OFFSET_IN_BUFFOR + k +1];
            counterBytes2++;
        }

       // data->TestCount--;
      //  }




    }


    printf("\n Liczba testów: %d ", data->TestCount);
    for(uint8_t j=0; j<BYTES_OF_CYPHER; j++)
    {
        printf("\n Cypher[%d]: %d ",j, data->Cypher[j]);
    }
     printf("\n Liczba SLOW: %d ", data->howManyWords);

    for(uint8_t x=0; x<BYTES_OF_CYPHER; x++)
    {
        printf("\n WORDS[%d]: %c ",x, data->words[0][x]);
    }

}



void StartProgram()
{

    scanf("%[^EOF]i", data.input);

    prepareData(&data);

    system("pause");

}

