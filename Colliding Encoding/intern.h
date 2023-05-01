#ifndef INTERN_H_INCLUDED
#define INTERN_H_INCLUDED

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define CYPHER_LENGTH           26
#define BUFOR_LENGTH            512
#define OFFSET_IN_BUFFOR        2
#define SIZE_OF_ENDLINE         1
#define BYTE_NUMER_OF_TESTS     0
#define BYTES_OF_CYPHER         26
#define MAX_SIZE_WORDS          BYTES_OF_CYPHER*OFFSET_IN_BUFFOR
#define MAX_WORDS               10
#define START_BYTE_OF_CYPHER    1
#define BYTE_NUMER_OF_WORDS BYTE_NUMER_OF_TESTS + BYTES_OF_CYPHER


typedef struct{
     uint8_t TestCount;
     uint8_t Cypher[CYPHER_LENGTH];
     uint8_t howManyWords;
     uint8_t input[BUFOR_LENGTH];
     uint8_t words[MAX_WORDS][MAX_SIZE_WORDS];
     uint8_t internalCounter;
}ExcerciseType;

typedef enum{
    NOT_OK  = 0,
    OK      = 1
}status;


#ifdef cosik
2
0 1 2 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3
4
ABC
BC
BCD
CDE
0 1 2 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3
3
CDE
DEF
EFG

#endif



void StartProgram();


#endif // INTERN_H_INCLUDED
