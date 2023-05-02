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

/****************************** MACROS ******************************/
#define CYPHER_LENGTH           (26u)
#define BUFOR_LENGTH            (255u)
#define OFFSET_IN_BUFFOR        (2u)
#define SIZE_OF_ENDLINE         (1u)
#define BYTE_NUMER_OF_TESTS     (0u)
#define BYTES_OF_CYPHER         (26u)
#define MAX_SIZE_WORDS          (BYTES_OF_CYPHER*OFFSET_IN_BUFFOR)
#define MAX_WORDS               (10u)
#define START_BYTE_OF_CYPHER    (1u)
#define BYTE_NUMER_OF_WORDS BYTE_NUMER_OF_TESTS + BYTES_OF_CYPHER


/**************************** DATA TYPES ****************************/
typedef struct{
     uint8_t TestCount;                         /* How Many Test Case Inlucde Input Data    */
     uint8_t Cypher[CYPHER_LENGTH];             /* Cypher from One Test Case                */
     uint8_t howManyWords;                      /* Var from count of words in One Test Case */
     uint8_t input[BUFOR_LENGTH];               /* Input data                               */
     uint8_t words[MAX_WORDS][MAX_SIZE_WORDS];  /* All Words from input data                */
     uint8_t internalCounter;                   /* InternCounter control Test Case          */
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

#endif

/*********************** FUNCTION DECLARATIONS **********************/
void StartProgram();


#endif // INTERN_H_INCLUDED
