/*
 * program.c
 *
 *  Created on: Mar 21, 2017
 *      Author: ins222
 */




#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int doNothing(int i)
{
	return i;
}

int doSquare(int i)
{
	return i*i;
}

//Do we need to match signature?
//No, it will still compile and run.
//You need to make sure that there are no errors in converting one data type
//to the next if your signature does not match.  In general, using functions that
//do not match signatures with the function pointer is not a good idea.
int dontMatchSignature(short x)
{
	return (int)x;
}


int main (void)
{
	setbuf(stdout, NULL);

	int iArray [] = {45, 56, 35000};
	//Note that we pass a function into iterate number as the last parameter.
	//The name of the function stores the address of the function.
	iterateNumbers(iArray, sizeof(iArray)/sizeof(int), dontMatchSignature);

	return EXIT_SUCCESS;
}
