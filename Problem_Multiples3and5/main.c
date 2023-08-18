/*******************************************************************
* Filename:   main.c
* Author:     Michał Bajkos
* Details:    Main Program file for Collision detect
*********************************************************************/
/*************************** HEADER FILES ***************************/
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "logic.h"

/*********************** MAIN FUNCTION DEF *************************/
int main()
{
   long int result = multiples3and5();
   MESSAGE("\n Result of sume multiples 3 and 5 below 1000 is: %ld ", result);
   return 0;
}
