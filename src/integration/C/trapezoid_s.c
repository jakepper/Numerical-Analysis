#include "functions.h"
#include <math.h>

/*
    Serial Implementation of Numerical Integration with Trapezoid Rule
*/
double trapezoid_s(double a, double b, double (*f)(double x), long n) {
    double h = fabs(b - a) / n;

    double sum = 0.0;
    for (int i = 1; i < n; i++) {
        sum += f(a + i*h);
    }

    return (h / 2) * (f(a) + 2*sum + f(b));
}