#include <stdio.h>
#include <mathfuncs.h>

double StdDev (double data [], int iSize)
{
    double dAvg = Average(data, iSize);
    int i = 0;
    double sum = 0;

    for(i = 0; i < iSize; i++)
    {
        sum += Square(data[i] - dAvg);
    }
    return Sqrt(sum);
}
