/*
 * funcs.c
 *
 *  Created on: Mar 21, 2017
 *      Author: ins222
 */
#include "funcs.h"

void iterateNumbers (int iArray [], int iSize, FNPTR_TYPE fn)
{
	int iVal = 0;

	for (int var = 0; var < iSize; ++var)
	{
		iVal = fn(iArray[var]);
		printf("The value after the function pointer is applied is: %d\n", iVal);
	}
}
