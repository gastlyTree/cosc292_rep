#include <stdio.h>
#include <string.h>

//note the declaration of a pointer in C. it uses the * operator
void ReadString(char * cPtr, char * cLengthPtr);
void PrintString(char * cPtr);
void ReadNumbers(int * iPtr);

int main()
{
    //char cArray [5];
    //char cArray2 [10];

    //test 1 - use scanf to input a string
    //ReadString(cArray, "4");
    //PrintString(cArray);
    


    //test 3 - read in some integers
    int iArray [4];
    ReadNumbers(iArray);
    //display the numbers in the array
    //recall that sizeof returns the size of the parameter in bytes
    for(int var = 0; var < sizeof(iArray)/sizeof(int); ++var)
    {
        printf("%d\n", iArray[var]);
    }

    return 0;
}

void ReadNumbers(int * iPtr)
{
    printf("Enter a number:\n");
    //note that scanf returns the number of reads that were sucessful. if it
    //returns a 0, it will exit out of the loop
    while(scanf("%d", iPtr++)){}
        //move the pointer tot he next int using pointer math
    
}

void ReadString(char * cPtr, char * cLengthPtr)
{
    char cFormat[4];
    //initialize as an empty string
    cFormat[0] = '\0';

    //use string concatenation to build up the format specifier
    strcat(cFormat, '%');
    strcat(cFormat, cLengthPtr);
    strcat(cFormat, "s");
    
    printf("Enter a string:\n");
    //note that scanf takes a format specifier (string) as a parameter and a
    //buffer (memory space).
    scanf(cFormat, cPtr);
}

void PrintString(char * cPtr)
{
    printf("%s\n", cPtr);
}
