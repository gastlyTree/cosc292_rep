
/*
Author: ins222
Date:  Feb 15, 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include "DMA.h"

void TestIntDMA()
{
	int iSize = 3;
	int * iBufferPtr = getInts(iSize);
	printInts(iBufferPtr, iSize);

	/*
	 * Demo a buffer overflow
	 * C allows us to overflow the buffer creating potential errors and security vulnerabilities.
	 * It is up to the programmer to ensure that you never go beyond the bounds of the buffer.
	 */
	//iBufferPtr[4]= 9;
	//printInts(iBufferPtr, iSize + 2);
    
    iBufferPtr = addInt(iBufferPtr, &iSize);
    printInts(iBufferPtr, iSize);

	//Once done with dynamically allocate memory, free it
	free(iBufferPtr);
	//Good practice to set pointer to null so we don't inadvertently access that memory location.
	iBufferPtr = NULL;
}

void TestDynamicString()
{
    char * cFirstPtr = NULL;
    char * cLastPtr = NULL;

    //read in names
    cFirstPtr = getStringDynamic("Enter first name: ");
    cLastPtr = getStringDynamic("Enter last name: ");

    //print the names
    if(cFirstPtr)
    {
        printf("The first name is: %s\n", cLastPtr);
        free(cFirstPtr);
        cFirstPtr = NULL;
    }

    if(cLastPtr)
    {
        printf("The last name is %s\n", cLastPtr);
        free(cLastPtr);
        cLastPtr = NULL;
    }
}

void TestNameANDSIN()
{
    char * cBuffer = getNameAndSIN();
    printNameAndSIN(cBuffer);
    free(cBuffer);
    cBuffer = NULL;
}

int main()
{
	//TestIntDMA();
    //TestDynamicString();
    TestNameANDSIN();
	return EXIT_SUCCESS;
}
