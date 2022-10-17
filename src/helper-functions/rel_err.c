#include "functions.h"

double rel_err(double predicted, double actual)
{
    return abs_err(predicted, actual) / actual;
}