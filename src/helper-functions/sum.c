#include "functions.h"

double sum(double values[], int size)
{
    double sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += values[i];
    }

    return sum;
}