/*
 * program.c
 *
 *  Created on: Feb 22, 2017
 *      Author: cst204
 */

/*
Author: ins222
Date:  Feb 22, 2017
*/

#include <stdio.h>
#include <stdlib.h>

/*
Purpose:  Trim iNumChars from the right end of the string passed in.
cPtrPtr --> a pointer to a pointer that points to a string
iNumChars --> the number of characters to chop off the right end of the string.
*/
void trimRight(char ** cPtrPtr, int iNumChars)
{
	int iDiff = 0;

	//Create a temp pointer to the original array
	char * cTempPtr = *cPtrPtr;

	//Difference in the size of the new and old string
	iDiff = strlen(cTempPtr) - iNumChars;

	//Allocate space for the new array
	*cPtrPtr = (char *)malloc((iDiff + 1)*sizeof(char));

	//Copy the old string to the new string.
	memcpy(*cPtrPtr, cTempPtr, iDiff*sizeof(char));

	//Add the null terminator
	*((*cPtrPtr)+iDiff) ='\0';

	//Free the old string
	free(cTempPtr);
	cTempPtr = NULL;
}

void testTrimRight()
{
	char cArray[] = "Robert";
	char * cPtr = (char *)malloc(strlen(cArray)*sizeof(char));
	strcpy(cPtr, cArray);

	printf("%s\n", cPtr);
	//Trim the right 3 characters
	//Note that we pass the address of the pointer.
	trimRight(&cPtr, 3);
	printf("%s\n", cPtr);
	free(cPtr);
	cPtr = NULL;
}



int main()
{
	setbuf(stdout, NULL);


	testTrimRight();
	return EXIT_SUCCESS;
}
