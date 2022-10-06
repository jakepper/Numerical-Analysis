#include <math.h>

#include "functions.h"

double iterate(double x0, double (*f)(double x), float tol, int iters) {
    double error = 10 * tol;
    int i = 0;
    while (error > tol && i < iters) {
        double x1 = x0 - f(x0);
        error = fabs(x1 - x0);
        x0 = x1;
        i++;
    }

    return x0;
}