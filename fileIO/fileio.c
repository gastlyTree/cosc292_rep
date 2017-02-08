#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "fileio.h"

int demoOpenClose(const char * fileName, const char * fileMode)
{
    //Pointer to a file stream
    FILE * filePtr;

    //A variable to store potential error codes
    int iErr = EXIT_SUCCESS;

    //use fopen to open a file. note that it returns a FILE pointer that must be
    //assigned. If it fails, it returns a NULL and sets the errno variable to
    //indicate an error. Parameters are a const char * indicating a
    //path/filename. The second is a const char * indicating the mode (read,
    //write, append, ect). See document on handout drive.

    if((filePtr =  fopen(fileName, fileMode)) != NULL )
    {
        //close the file when done
        fclose(filePtr);
        printf("%s was successfully opened and closed.\n", fileName);
    }
    else
    {
        iErr = errno;
        printf("Error accessing the file %s: %s\n", fileName, strerror(iErr));
    }
    return iErr;
}
int demoRead(const char * fileName, const char * fileMode)
{
    FILE * filePtr;
    int iErr = EXIT_SUCCESS;
    int intChar, retVal;
    char cBuffer [MAXSIZE];

    //all read operations read data from the file to t he memory location
    //indicated (cBuffer). Only fgets adds an additional nul terminator to the
    //data in the buffer. Return types vary, so testing for success depends on
    //the function used
    //fscanf/fread - return number of times assigned/read, fscanf returns EOF if
    //a failure occurs
    //fgets - returns a pointer tot he string read or NULL
    //fgetc - returns the character or EOF

    if((filePtr =  fopen(fileName, fileMode)) != NULL )
    {
        //how to initialize a buffer
        memset(cBuffer, '\0', MAXSIZE);

        retVal = fscanf(filePtr, "%s\n", cBuffer); //Quits at a space
        if(retVal > 0)
        {
            printf("%s\n", cBuffer);    
        }
        else
        {
            if(iErr = ferror(filePtr))
            {
                    printf("Error reading from the file %s: %s\n", fileName,
                    strerror(iErr));
            }
            else
            {
                printf("Could not retrieve data.\n");    
            }
        }

        //close the file when done
        fclose(filePtr);
        printf("%s was successfully opened and closed.\n", fileName);
    }
    else
    {
        printf("Error accessing the file %s: %s\n", fileName, strerror(iErr));
    }
    return iErr;

}
int demoWrite(const char * fileName, const char * fileMode, const char * str)
{
    
}
int demoWriteBinary(const char * fileName, const char * fileMode, const int * iPtr)
{
    
}


