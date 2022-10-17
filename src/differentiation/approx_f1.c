#include "functions.h"

double approx_f1(double x, double h, double (*f)(double x))
{
    return (f(x + h) - f(x - h)) / (2 * h);
}