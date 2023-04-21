
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define CYPHER_LENGTH   3
#define BUFOR_LENGTH   136
#define SIZE_OF_ENDLINE     1
#define BYTE_NUMER_OF_TESTS 0
#define START_BYTE_OF_CYPHER 1
#define BYTES_OF_CYPHER 26

typedef struct{
     uint8_t TestCount;
     uint8_t Cypher[CYPHER_LENGTH];
     uint8_t howManyWords;
     uint8_t input[BUFOR_LENGTH];
}ExcerciseType;

typedef enum{
    NOT_OK  = 0,
    OK      = 1
}status;

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
         printf("\n 0byute = %d ",  data->input[0] - '0');
        // data->TestCount = data->input[BYTE_NUMER_OF_TESTS];
        
        // uint8_t j=0;
        // for(uint8_t i=0; i<BUFOR_LENGTH; i++)
        // {
        //     if(j == BYTES_OF_CYPHER)
        //     {
        //         break;
        //     }
        //     if( data->input[i] >= 0 && data->input[i] < 10)
        //     {
        //         // printf("\n data[%d] = %c ", i, data->input[i]);
        //         data->Cypher[j] = data->input[i];
        //         j++;
        //     }
            
        // }

        
    }
    
    
    // printf("\n Liczba testów: %d ", data->TestCount);
    // for(uint8_t j=0; j<50; j++)
    // {
    //     printf("\n Cypher[%d]: %d ",j, data->input[j]);
    // }
    
}



int main() {

    
    scanf("%[^EOF]i", data.input);
  
    prepareData(&data);
  

   
  
  
    
   return 0;
}