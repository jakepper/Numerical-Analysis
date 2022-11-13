#include "functions.h"
#include <math.h>

/*
    Parallel Implementation of Numerical Integration with Trapezoid Rule
*/
double trapezoid_p(double a, double b, double (*f)(double x), long n) {
    double h = fabs(b - a) / n;

    double sum = 0.0;
    #pragma omp parallel for reduction(+:sum)
    {
        for (int i = 1; i < n; i++) {
            sum += f(a + i*h);
        }
    }

    return (h / 2) * (f(a) + 2*sum + f(b));
}