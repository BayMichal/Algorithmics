/**********************************************************************
* Filename:   logic.c
* Author:     Michał Bajkos
* Details:    Header file for logic
**********************************************************************/

/*************************** HEADER FILES ****************************/
#include <stdio.h>
#include <stdbool.h>
#include "logic.h"
#include "error.h"


/*************************** HEADER STATIC FUN ***********************/
/**
 * initData - static function to init global data
 * @param data - pointer to data to be init
 */
static void initData(sumBuf *data);

/**
 * initData - static function to init global data
 * @param input -pointer to input data
 * @param inlen - pointer to size of data 
 * @param text - pointer to type of operation
 * @return If succesfull operation = sum of input data, else -1 (see error.h)
 */
static long int findSum(int *input, int *inlen, char *text);

/*************************** BODY STATIC FUN *************************/
/* To desribe - See Header */
static void initData(sumBuf *data)
{
    if(data != NULL)
    {
        memset(data, 0x00, sizeof(sumBuf));
    }

}

/* To desribe - See Header */
static long int findSum(int *input, int *inlen, char *text)
{
    if(input == NULL || inlen == NULL)
    {
        return ERROR_INPUT_DATA;
    }
    else
    {
        long int sum = 0u;
        for(int i=1; i <= (*inlen); i++)
        {
            sum += input[i];
        }

        MESSAGE("\n Sume of %s:  %ld ", text, sum);
        return sum;
    }
}   

/*************************** BODY GLOBAL FUN *************************/
/* To desribe - See Header */
long int multiples3and5(void)
{
    MESSAGE("\n Example 1.1");
    FLUSH_DATA(&data);

    /* Local data */
    int howMuch_I = NULL_DATA;
    int howMuch_3 = NULL_DATA;
    int howMuch_5 = NULL_DATA;

    for(int i=1; i<BOUNDARY_CONDITION; i++)
    {
        //ignore multiple values NAND
        if( (i % DIVIDER_3 == NULL_DATA) && (i % DIVIDER_5 == NULL_DATA))
        {
            data.sumintersection[++howMuch_I] = i;
        }
        else if((i % DIVIDER_3 == NULL_DATA) && (i % DIVIDER_5 != NULL_DATA))
        {
            data.sum_3[++howMuch_3] = i;
        }
        else if((i % DIVIDER_5 == NULL_DATA) && (i % DIVIDER_3 != NULL_DATA))
        {
            data.sum_5[++howMuch_5] = i;
        }
        else
        {
            continue;
            //do nothing
        }
    }

    return (findSum(data.sumintersection, &howMuch_I, "Intersections") + \
            findSum(data.sum_3,           &howMuch_3, "Three ") + \
            findSum(data.sum_5,           &howMuch_5, "Five "));
}