#include <stdio.h>
#include <stdlib.h>
#include "fileio.h"

void TestOpenClose()
{
    int iErr = demoOpenClose("foo", "r");
    printf("The error number returned was %d\n", iErr);
}

int main()
{
    TestOpenClose();

    return EXIT_SUCCESS;
}
