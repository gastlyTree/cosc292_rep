#include <stdio.h>
#include <stdlib.h>
#include "arraypointers.h"

void TestIntArray()
{
    int iArray [] = {2,7,9};
    int iArraySize = sizeof(iArray)/sizeof(int);
    intArrayPrinterWithPointers(iArray, iArraySize);
}

void TestCharArrayPrinterWithPointers()
{
    charArrayPrinterWithPointers("Hello World");    
}

void TestIntBytePointer()
{
    int x = 0x3A4F506B;
    intBytePrinter(x);
}

void TestEncodeDecode()
{
    double x = Encode();
    Decode(x);
}

int main()
{
    //TestIntArray();
    //TestCharArrayPrinterWithPointers();
    //TestIntBytePointer();
    TestEncodeDecode();
    return EXIT_SUCCESS;
}
