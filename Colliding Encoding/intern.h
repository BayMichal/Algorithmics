/*******************************************************************
* Filename:   intern.h
* Author:     Michał Bajkos
* Details:    Header file for intern
*********************************************************************/

#ifndef INTERN_H_INCLUDED
#define INTERN_H_INCLUDED

/*************************** HEADER FILES ***************************/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "defines.h"

/**************************** DATA TYPES ****************************/
typedef struct{
    uint8_t TestCount;                         /* How Many Test Case Inlucde Input Data    */
    uint8_t Cypher[CYPHER_LENGTH];             /* Cypher from One Test Case                */
    uint8_t howManyWords;                      /* Var from count of words in One Test Case */
    uint8_t input[BUFOR_LENGTH];               /* Input data                               */
    uint8_t words[MAX_WORDS][MAX_SIZE_WORDS];  /* All Words from input data                */
    uint8_t internalCounter;                   /* InternCounter control Test Case          */
    uint8_t output[MAX_SIZE_WORDS];            /* Cypered data */
    uint8_t outputSize;                        /* Cypered data size */
    uint8_t compare[MAX_SIZE_WORDS];
}InputDataType;


typedef struct{
    uint8_t size;                               /* Sizeof current word                      */
    uint8_t hashIndex;                          /* Var to store index Hash                  */
    unsigned char hash[MAX_WORDS];              /* Bufor for Hash Words (All Words)         */
}HashDataType;

typedef enum{
    NOT_OK  = 0,
    OK      = 1
}status;

typedef enum{
    A   = 0,
    B   = 1,
    C   = 2,
    D   = 3,
    E   = 4,
    F   = 5,
    G   = 6,
    H   = 7,
    I   = 8,
    J   = 9,
    K   = 10,
    L   = 11,
    M   = 12,
    N   = 13,
    O   = 14,
    P   = 15,
    R   = 16,
    S   = 17,
    T   = 18,
    U   = 19,
    W   = 20,
    Y   = 21,
    Z   = 22
}alphaBettOrder;


#ifdef inputData    /* Example data to input */
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


#v2
1
0 1 2 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3
4
ABC
BC
BCD
CDE
#endif

/*********************** FUNCTION DECLARATIONS **********************/
status StartProgram();


#endif // INTERN_H_INCLUDED
