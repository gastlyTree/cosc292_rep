/*
 * DMA.c
 *
 *  Created on: Feb 15, 2017
 *      Author: ins222
 */
#include <stdio.h>
#include <string.h>
#include <malloc.h> //Required for DMA
#include "DMA.h"

//Method to print an array of integers
void printInts(int * iBufferPtr, int iSize)
{
	int i = 0;
	printf("The integers are: ");
	for(; i < iSize - 1; i++)
	{
		printf("%d, ", *(iBufferPtr++));
	}
	printf("%d\n", *iBufferPtr);
}

/*
The following function demonstrates how to use dynamically allocated memory (DMA).
Memory allocated dynamically is allocated on the heap.  It is yours until you release it back
to the system.  There is NO garbage collection.
*/

//Return an array of integers that are dynamically allocated
int * getInts(int iNumInts)
{
	/*
	 Create a memory space for the integers using the function malloc.
	 Malloc takes the size of memory in bytes as a parameter.
	 Malloc returns a pointer to the first byte of the requested memory.
	 Malloc returns a (void *) void pointer, which is still a pointer,
	 just no associated type.  Usually, a cast is required.
	*/

	int * iBufferPtr = (int *)malloc(iNumInts*sizeof(int));
	for (int var = 0; var < iNumInts; ++var)
	{
		printf("Enter int %d: ", var);
		scanf("%d", iBufferPtr + var);
	}

	return iBufferPtr;
}

//Add an int to the end of a dynamic array
//Purpose --> Takes an array, increase its size by one. Asks the user for an
//int, and add it to the end
//iArrayPtr --> the original dynamically allocated array.
//iSizePtr --> Pointer to the original size of the array passed in.i
int * addInt(int * iArrayPtr, int * iSizePtr)
{
    //create a new array
    int * iNewBufferPtr = (int *)malloc((*iSizePtr + 1)*sizeof(int));

    //copy data from old array to new
    memcpy(iNewBufferPtr, iArrayPtr, *iSizePtr * sizeof(int));
    
    //free the original array
    free(iArrayPtr);

    //get int from user
    printf("Enter int:\n");
    scanf("%d", iNewBufferPtr + *iSizePtr);

    //increase the size
    (*iSizePtr)++;

    //return the pointer to the new array
    return iNewBufferPtr;
}

//Get a dynamic string
char * getStringDynamic (char * cPrompt)
{
    //pointer to a dynamically alocated temporary array
    char * cTempPtr = NULL;

    //Pointer to dynamically allocated array of exact size required
    char * cReturnPtr = NULL;

    //allocate momory for the temp array
    cTempPtr = (char *)malloc(MAX_STRING_SIZE*sizeof(char));

    //Ifmemory was allocated (malloc can fail, if it does, it returns NULL)
    if(cTempPtr)
    {
        //Prompt the use for a string
        printf("%s", cPrompt);
        //Scan in a string with spaces potentially
        fgets(cTempPtr, MAX_STRING_SIZE, stdin);

        //Allocate a new buffer based on the actuall size of the input
        //Always remember t o allocate space for the null terminator
        cReturnPtr = (char *)malloc((strlen(cTempPtr) + 1)*sizeof(char));

        if(cReturnPtr)
        {
            //Copy the data from temp array to return array
            strcpy(cReturnPtr, cTempPtr);
        }
        free(cTempPtr);
        cTempPtr = NULL;
    }
    return cReturnPtr;
}

//A function that creates a buffer with a name (MAX_NAME_SIZE) and SIN#
char * getNameAndSIN()
{
    //create a buffer that can fit 20 chars for the names and one int for the
    //SIN#
    char * cArray = (char *)malloc(MAX_NAME_SIZE*sizeof(char)+sizeof(int));
    
    //Read in the name
    printf("Enter the name: ");
    fgets(cArray, MAX_NAME_SIZE, stdin);

    //fgets puts in t he newline character which we might not want.
    //you can overwrite it with a null terminator
    cArray[strlen(cArray)-1] = '\0';

    //read in the SIN#
    printf("Enter the SIN#: ");
    scanf("%d", (int *)(cArray+MAX_NAME_SIZE));

    return cArray;
}

//A function to display a name and sin#
void printNameAndSIN(char * cBufferPtr)
{
    printf("The name is %s\n", cBufferPtr);
    printf("The SIN# is %d\n", *((int *)(cBufferPtr+MAX_NAME_SIZE)));
}
