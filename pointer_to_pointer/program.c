/*
 * program.c
 *
 *  Created on: Feb 21, 2017
 *      Author: ins222
 */


/*
 Author: ins222
 Date: Feb 21, 2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(char ** cPtrPtr, int iRows)
{
	for (int var = 0; var < iRows; ++var)
	{
		printf("%s\n", cPtrPtr[var]);
	}
}

char * allocateRow(int iRowSize)
{
	return (char *)malloc(iRowSize * sizeof(char));
}


/*
iRowSizes - an integer array with the length of each row
iNumRows - number of rows to create
*/

char ** createJaggedArray(int iRowSizes [], int iNumRows)
{
	//Create the array of pointers
	char ** cPtrPtr = (char **)malloc(iNumRows*sizeof(char *));

	//Loop through the array of pointers and create each
	for (int i = 0; i < iNumRows; ++i)
	{
		*(cPtrPtr + i) = allocateRow(iRowSizes[i]);
		//cPtrPtr[i] = allocateRow(iRowSizes[i]);
	}

	return cPtrPtr;
}

void testJaggedArray()
{
	int iRowVals [] = {4, 6, 5};

	//Calculate the number of rows in iRowVals
	int iRows = sizeof(iRowVals)/sizeof(int);

	//Create the jagged array
	char ** cPtrPtr = createJaggedArray(iRowVals, iRows);

	//Add some data to the rows
	cPtrPtr[0][0] = 'R';
	cPtrPtr[0][1] = 'o';
	cPtrPtr[0][2] = 'b';
	cPtrPtr[0][3] = '\0';


	//Index in using pointer math
	**(cPtrPtr+1) = 'S';
	*(*(cPtrPtr+1) + 1)= 'h';
	*(*(cPtrPtr+1) + 2)= 'a';
	*(*(cPtrPtr+1) + 3)= 'n';
	*(*(cPtrPtr+1) + 4)= 'e';
	*(*(cPtrPtr+1) + 5)= '\0';

	//Use strcpy
	strcpy(cPtrPtr[2], "Rick");

	//Print the array
	printArray(cPtrPtr, iRows);


	//Free the individual rows
	for (int i = 0; i < iRows; ++i)
	{
		free(cPtrPtr[i]);
		cPtrPtr[i] = NULL;
	}

	//Free the array of pointers
	free(cPtrPtr);
	cPtrPtr = NULL;
}



/*
Purpose:  Trim iNumChars off the end of a dynamically allocate array of chars.
cPtrPtr -> a pointer to a pointer of characters (a string)
iNumChars -> number of chars to trim off the right end.
*/
void trimRight(char ** cPtrPtr, int iNumChars)
{
	int iDiff  = 0;

	//Create a pointer to the original array, note that we dereference once to get a pointer to the array of chars.
	char * cTempPtr = *cPtrPtr;

	//Difference in length of the old array and the number of chars to remove
	iDiff = strlen(cTempPtr) - iNumChars;

	//Allocate space for the new array
	*cPtrPtr =  (char *)malloc((iDiff + 1)*sizeof(char));

	//Copy the data from the old string to the new string
	memcpy(*cPtrPtr, cTempPtr, iDiff*sizeof(char));

	//Add the null terminator
	*((*cPtrPtr) + iDiff) = '\0';

	//Free the old array
	free(cTempPtr);
	cTempPtr = NULL;

}


void testTrimRight()
{
	char cArray [] ="Robert";

	char * cPtr = (char *) malloc (sizeof(cArray));

	strcpy(cPtr, cArray);

	printf("%s\n", cPtr);

	//Trim the right 3 characters
	trimRight(&cPtr, 3);

	printf("%s\n", cPtr);

	free(cPtr);
	cPtr = NULL;
}

void stringConcatDynamic(char ** cPtrPtr, char * cPtr)
{
	char * cTemp = *cPtrPtr;

	*cPtrPtr = (char *)malloc((strlen(cTemp)+ strlen(cPtr) + 1)*sizeof(char));

	strcpy(*cPtrPtr, cTemp);

	strcpy(*cPtrPtr + strlen(cTemp), cPtr);

	free(cTemp);

	cTemp = NULL;
}


void testStringConcatDynamic()
{
	char cArray [] = "Robert";
	char * cNamePtr = (char *)malloc(sizeof(cArray));
	strcpy(cNamePtr, cArray);


	stringConcatDynamic(&cNamePtr, " Miller");
	printf("The concatenated string is %s\n", cNamePtr);
	free(cNamePtr);
	cNamePtr = NULL;
}


int main (void)
{
	setbuf(stdout, NULL);
	//testTrimRight();
	//testJaggedArray();
	testStringConcatDynamic();

	return EXIT_SUCCESS;
}




















