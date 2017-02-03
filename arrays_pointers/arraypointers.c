#include <stdio.h>
#include "arraypointers.h"

void intArrayPrinter(int iArray [] , int iArraySize)
{
    //note that the array is passed in as a pointer. if we do sizeof(iArray) it
    //will return the size of a int pointer, not the size of the array.

    //print out the values in the array
    for(int var = 0; var < iArraySize; ++var)
    {
        printf("The value of loop counter id=s %d and tha rray value is %d\n",
        var, iArray[var]);    
    }
}

void charArrayPrinter(char cArray[])
{
    
}

void intArrayPrinterWithPointers(int * iArrayPtr, int iArraySize)
{
    for (int var = 0; var < iArraySize; ++var)
    {
        //to reference the value where a pointer points, we "dereference" it
        //printf("The value of loop counter is %d and tha array value is %d\n",
        //var, *(iArrayPtr + var));
        printf("The value of loop counter is %d and tha array value is %d\n",
        var, *(iArrayPtr++));
    }
}

void charArrayPrinterWithPointers(char * cArrayPtr)
{
    while(*cArrayPtr)
    {
        printf("%c", *(cArrayPtr++));    
    }
}

void intBytePrinter(int iValue)
{
    //note the cast of the int pointer to a char pointer.
    char * cPtr = (char *)&iValue;
    int size = sizeof(iValue);
    for(int var = 0; var < size; ++var)
    {
        printf("The byte value is %x and the char equivalent %c\n", *cPtr, *cPtr);
        cPtr++;
    }
}

double Encode()
{
    double x;

    printf("Enter the first 3 letters of your name:\n");
    scanf("%3s", &x);

    printf("\nEnter your age\n");
    scanf("%d", &x);

    printf("\nEnter your student debt\n");
    scanf("%d", &x);
    
    return x;
}

void Decode(double x)
{
    char * cPtr = (char *)&x;
    for(int var = 0; var < 3; ++var)
    {
        printf("%c", *cPtr++);   
    }
    cPtr++;
    printf("\n%d\n", *cPtr++);
    printf("%hu\n", *cPtr);

}
