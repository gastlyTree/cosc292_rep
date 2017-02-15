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

void TestExerciseWrite()
{
    exerciseBinaryWrite("exercise.dat", "wb");    
}

TestExerciseRead()
{
    int Sin = 0;
    printf("Enter SIN# to find\n");
    scanf("%d", &Sin);
    exerciseBinaryRead("exercise.dat", "rb", Sin);
}

int main()
{
    //TestOpenClose();
    //TestRead();
    //TestWriteText();
    //TestWriteBinary();
    TestExerciseWrite();
    //TestExerciseRead();
    return EXIT_SUCCESS;
}
