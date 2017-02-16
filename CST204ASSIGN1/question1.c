/*
    Course: COSC292
    Name:   Nicholas Sutter
    CST#:   CST204
    Assgn:  1
    Description:
        Implementation of the stringCompare function for question 1
*/
#include <stdio.h>
#include <stdlib.h>
#include "question1.h"

//string compare function that compares the two strings entered, returns 0 if
//they are the same.
int stringCompare(char * string1, char * string2)
{
    int result = 0; 
    
    //loop through each character in each string. Stop if result != 0 or one of
    //the strings reaches the end.
	while (result == 0 && *string1 != '\0' && *string2 != '\0')
	{
        //compare the strings by subracting the second from the first, then find
        //the difference. if it is 0, they are the same
		result = *string1 - *string2;
        
        //walk the pointers
		string1++;
		string2++;
	}

	return result;   
}
