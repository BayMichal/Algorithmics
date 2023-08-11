/*******************************************************************
* Filename:   defines.c
* Author:     Michał Bajkos
* Details:    Intern implementation for Excercise Colliding Encoding Google
*********************************************************************/
#ifndef DEFINES_H_INCLUDED
#define DEFINES_H_INCLUDED
/*************************** defines ***************************/

#define ALFABETSIZE     (24u)   /* Size of words in alphabet type enum */
#define InputDataDebug
#define CYPHER_LENGTH           (26u)
#define BUFOR_LENGTH            (255u)
#define OFFSET_IN_BUFFOR        (2u)
#define SIZE_OF_ENDLINE         (1u)
#define BYTE_NUMER_OF_TESTS     (0u)
#define BYTES_OF_CYPHER         (26u)
#define MAX_SIZE_WORDS          (BYTES_OF_CYPHER*OFFSET_IN_BUFFOR)
#define MAX_WORDS               (8u) //long int 8bytes -> 8 words to check consistancy
#define START_BYTE_OF_CYPHER    (1u)
#define BYTE_NUMER_OF_WORDS BYTE_NUMER_OF_TESTS + BYTES_OF_CYPHER
#define MY_ASCII_NEW_LINE       (0x98)
#define MY_END_ASCII            (0x99)
#endif // DEFINES_H_INCLUDED