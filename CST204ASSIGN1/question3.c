/*
    Course: COSC292
    Name:   Nicholas Sutter
    CST#:   CST204
    Assgn:  1
    Description:
        This file containes two functions for assignment 1 question 3. These two
        functions will write to and read from a file inputed by the user.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "question1.h"
#include "question3.h"

//Function to write to a file inputed by the user
void writeDataToFile(char * cFileNamePtr)
{
	FILE * filePtr;
	int iErr = EXIT_SUCCESS;
	char lineInput[1024];//holds the current line, can enter a kilobyte per line
    //open the file
	if ((filePtr = fopen(cFileNamePtr, "a")) != NULL)
	{
        //prompt the user
		printf("Type your message. Type (Quit) to stop.\n");
        //loop until the user types "Quit"
		do
		{
			fgets(lineInput, 1023, stdin);
			setbuf(stdin, NULL);
            //using the stringCompare function from question1 to check if the
            //user typed quit
			if (stringCompare(lineInput, "Quit\n"))
			{
				fwrite((void *)lineInput, sizeof(char), strlen(lineInput), filePtr);
			}
		} while (stringCompare(lineInput, "Quit\n"));
        //close the file
		fclose(filePtr);
	}
    else
    {
        printf("Could not open file.");    
    }
}

//Function to read from a file and output it line for line
void readDataFromFile(char * cFileNamePtr)
{
	FILE * filePtr;
	char cBuffer[1024];
	int iErr = EXIT_SUCCESS;
    //open the file 
	if ((filePtr = fopen(cFileNamePtr, "r")) != NULL)
	{
        //loop through each line of the file
		while (fgets(cBuffer, 1024, filePtr) != NULL)
		{
			printf("%s", cBuffer);
		}
        //close the file
        fclose(filePtr);
	}
	else
	{
        printf("Could not open file.");
    }

}
