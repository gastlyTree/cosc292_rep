#include <stdio.h>
#include <stdlib.h>
#include "fileio.h"

void TestOpenClose()
{
    int iErr = demoOpenClose("foo", "r");
    printf("The error number returned was %d\n", iErr);
}

void TestRead()
{
    int iErr = demoRead("foo", "r");
    printf("The error number returned was %d\n", iErr);
}

void TestWriteText()
{
    int iErr = demoWrite("foobar", "w", "HelloWorld");
    printf("The error number returned was %d\n", iErr);    
}

void TestWriteBinary()
{
    int x = 123456789;
    int iErr = demoWriteBinary("foobar.bin", "wb", &x);
    printf("The error number returned was %d\n", iErr);        
}

void TestExerciseBinaryWrite()
{
    int iErr = exerciseBinaryWrite("snNames", "wb");
    printf("The error number returned was %d\n", iErr);
}

int main()
{
    //TestOpenClose();
    //TestRead();
    //TestWriteText();
    //TestWriteBinary();
    TestExerciseBinaryWrite();
    return EXIT_SUCCESS;
}
