#include <stdio.h>
#include "pingpong.h"

void ping()
{
    printf("ping\n");
    pong();
}

void pong()
{
    //static int creates one instance reguardless of how many times pong is
    //called.
    static int iCount = 0;
    iCount++;
    printf("pong\n");
    if(iCount < 10)
    {
        ping();
    }
}

