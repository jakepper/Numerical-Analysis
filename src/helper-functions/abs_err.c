#include "functions.h"
#include <math.h>

double abs_err(double predicted, double actual)
{
    return fabs(actual - predicted);
}