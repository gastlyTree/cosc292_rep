#include <stdio.h>
#include <string.h>

//note the declaration of a pointer in C. it uses the * operator
void ReadString(char * cPtr, char * cLengthPtr);
void PrintString(char * cPtr);

int main()
{
    //test 1 - use scanf to input a string
    //create a buffer to put data into
    char cArray [5];
    ReadString(cArray, "4");
    PrintString(cArray);

    return 0;
}

void ReadString(char * cPtr, char * cLengthPtr)
{
    scanf("%4s", cPtr);
}

void PrintString(char * cPtr)
{
    printf("%s\n", cPtr);
}
