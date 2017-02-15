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
    FILE * filePtr;
    int iErr = EXIT_SUCCESS;
    int intChar, retVal;
    char cBuffer [MAXSIZE];

    if((filePtr =  fopen(fileName, fileMode)) != NULL )
    {
        retVal = fwrite((void *)str, sizeof(char), strlen(str), filePtr);
        if(retVal > 0)
        {
            printf("File writen: %s\n", fileName);    
        }
        else
        {
            if(iErr = ferror(filePtr))
            {
                    printf("Error writing to the file %s: %s\n", fileName,
                    strerror(iErr));
            }
            else
            {
                printf("Could not write data.\n");    
            }
        }

        //close the file when done
        fclose(filePtr);
        printf("%s was successfully wrote tot he file.\n", fileName);
    }
    else
    {
        printf("Error accessing the file %s: %s\n", fileName, strerror(iErr));
    }
    return iErr;
}

int demoWriteBinary(const char * fileName, const char * fileMode, const int * iPtr)
{
    FILE * filePtr;
    int iErr = EXIT_SUCCESS;
    int intChar, retVal;

    if((filePtr =  fopen(fileName, fileMode)) != NULL )
    {
        retVal = fwrite((void *)iPtr, sizeof(int), 1, filePtr);
        if(retVal > 0)
        {
            printf("File writen: %s\n", fileName);    
        }
        else
        {
            if(iErr = ferror(filePtr))
            {
                    printf("Error writing to the file %s: %s\n", fileName,
                    strerror(iErr));
            }
            else
            {
                printf("Could not write data.\n");    
            }
        }

        //close the file when done
        fclose(filePtr);
        printf("%s was successfully wrote tot he file.\n", fileName);
    }
    else
    {
        printf("Error accessing the file %s: %s\n", fileName, strerror(iErr));
    }
    return iErr;
}

int exerciseBinaryWrite(const char* fileName, const char * fileMode)
{
    FILE * filePtr;
    int iErr = EXIT_SUCCESS;
    int iSin, retSin, retName;
    char cNameArray [MAXNAME];
    short sNumRecords = NUM_RECORDS;
    
    if((filePtr =  fopen(fileName, fileMode)) != NULL )
    {
    	fwrite((void *)&sNumRecords, sizeof(short), 1, filePtr );
        
    	
    	for(int var = 0; var < NUM_RECORDS; ++var)
    	{
            //Prompt the user for a sin number
            printf("\nEnter sin number:\n");
            scanf("%i", &iSin);
            
            //clear the stdin buffer of any hard return characters

            fflush(stdin);

            //get the name
            printf("\nEnter Name:\n");
            //Safe way to get a string
            fgets(cNameArray, MAXNAME -1, stdin);

            retSin = fwrite((void *)&iSin, sizeof(int), 1, filePtr);
            retName = fwrite((void *)cNameArray, MAXNAME, 1, filePtr);

            if(retSin == 0 || retName == 0)
            {
                if((iErr = ferror(filePtr)))
                {
                    printf("Error writing the file %s : %s\n", fileName,
                    strerror(iErr));    
                }
                else
                {
                    printf("Could not write date\n");    
                }
            }
            
    	}	
        //close the file
        fclose(filePtr);
    }
    else
    {
        printf("Error accessing the file %s: %s\n", fileName, strerror(iErr));
    }
    return iErr;

}

int exerciseBinaryRead(const char* fileName, const char * fileMode, int id)
{
    FILE * filePtr;
    int iErr = EXIT_SUCCESS;
    int iSin, retSin, retName;
    char cNameArray [MAXNAME];
    short sNumRecords = NUM_RECORDS;
    int found = 0;

    if((filePtr =  fopen(fileName, fileMode)) != NULL )
    {
        fread((void *)&sNumRecords, sizeof(short), 1, filePtr);

        for(int var = 0; var < sNumRecords && !found; ++var)
        {
            //Read in the SIN#
            fread((void *)&iSin, sizeof(int), 1, filePtr);
            if(iSin == id)
            {
                //Read the name from  the file, quit looping as well
                found = fread((void *)cNameArray, MAXNAME, 1, filePtr);
                printf("The name is %s\n", cNameArray);
            }
            else
            {
                fseek(filePtr, MAXNAME, SEEK_CUR);    
            }
        }
        if(!found)
        {
            printf("SIN# not found.\n");    
        }
        //close the file
        fclose(filePtr);
    }
    else
    {
        printf("Error accessing the file %s: %s\n", fileName, strerror(iErr));
    }
    return iErr;
}
