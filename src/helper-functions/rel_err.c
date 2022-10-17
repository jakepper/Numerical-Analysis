#include "functions.h"
#include <math.h>

double rel_err(double predicted, double actual)
{
    return fabs((actual - predicted) / actual);
}