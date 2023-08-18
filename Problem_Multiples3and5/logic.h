/**********************************************************************
* Filename:   LOGIC.h
* Author:     Michał Bajkos
* Details:    Header file for LOGIC
**********************************************************************/

#ifndef LOGIC_H_INCLUDED
#define LOGIC_H_INCLUDED

/*************************** HEADER FILES ****************************/
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*************************** DEFINES  ********************************/
#define MESSAGE             printf
#define FLUSH_DATA          initData
#define BOUNDARY_CONDITION  1000u
#define DIVIDER_3           3u
#define DIVIDER_5           5u
#define NULL_DATA           0u
/***************************  DATA TYPES   ***************************/

/*
 * Main data of program
 *
 */
typedef struct{
    int sumintersection[BOUNDARY_CONDITION];    /* Bufer for intersercion 3 & 5 */
    int sum_3[BOUNDARY_CONDITION];              /* Bufer for sume (divider 3)   */
    int sum_5[BOUNDARY_CONDITION];              /* Bufer for sume (divider 5)   */
}sumBuf;

/***************************  DATA DECLARE  **************************/
sumBuf data;
/***************************  FUNCTIONS   ****************************/
long int multiples3and5(void);

#endif // INTERN_H_INCLUDED