#include <stdio.h>
#include <math.h>

#include "functions.h"

double newton(double x0, double (*f)(double x), double (*f_prime)(double x), float tol, int iters) {
    double error = 10 * tol;
    int i = 0;
    while (error > tol && i < iters) {
        double x1 = x0 - (f(x0) / f_prime(x0));
        error = fabs(x1 - x0);
        x0 = x1;
        i++;
    }

    return x0;
}