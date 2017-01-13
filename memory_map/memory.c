#include <stdio.h>
#include "memory.h"

int MemoryMap(float x)
{
    static int i = 0;
    int a = 123456789;
    double d = 9.0;
    float b = 3.2;
    char c = 'a';
    short s = 10815;
    char cArray[] = "Hello";

    //Print the address of each variable
    //the "address of" operator is the overloaded &
    // note that %p is used for printing values in hex

    printf("The address of int i is \t\t %p \n", &i);
    printf("The address of int a is \t\t %p \n", &a);
    printf("The address of double d is \t\t %p \n", &d);
    printf("The address of float b is \t\t %p \n", &b);
    printf("The address of char c is \t\t %p \n", &c);
    printf("The address of short s is \t\t %p \n", &s);
    printf("The address of int cArray is \t\t %p \n", cArray);
    
    //print the address of the parameter
    printf("The address of float x is \t\t %p \n", &x);

    //print the address of the function itself. Note that the name of the
    //function stores it's address
    printf("The address of memoryMap is \t\t %p \n", MemoryMap);

}

