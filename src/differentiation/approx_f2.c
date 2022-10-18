#include "functions.h"

double approx_f2(double x, double h, double (*f)(double x))
{
    return (f(x + h) + f(x - h) - 2 * f(x)) / (h * h);
}