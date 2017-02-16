/*
    Course: COSC292
    Name:   Nicholas Sutter
    CST#:   CST204
    Assgn:  1
    Description:
        Implementation of the stringCompareEfficient function for question 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "question2.h"

//string compare function that compares the two strings entered, returns 0 if
//they are the same.
int stringCompareEfficient(char * string1, char * string2)
{
	int result = 0;
    //set the strings to ints so t hey can be accessed in 4 byte chunks
	int * String1 = string1; 
	int * String2 = string2;

    //loop through each character in each string. Stop if result != 0 or one of
    //the strings reaches the end.
	while (result == 0 && *String1 != '\0' && *String2 != '\0')
	{
        //compare the strings by subracting the second from the first, then find
        //the difference. if it is 0, they are the same
		result = *String1 - *String2;
        
        //walk the pointer
		String1++;
		String2++;
	}

	return result;
}
