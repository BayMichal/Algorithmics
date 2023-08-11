/*******************************************************************
* Filename:   main.c
* Author:     Michał Bajkos
* Details:    Main Program file for Excercise Colliding Encoding Google
*********************************************************************/
/*************************** HEADER FILES ***************************/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "intern.h"

/*********************** MAIN FUNCTION DEF *************************/
int main()
{
   status retVal = NOT_OK;
   retVal = StartProgram();
   printf("\n Request: %s ", retVal ? "OK" : "NOT_OK");
   return 0;
}
