#include <math.h>

#include "functions.h"

double secant(double x0, double x1, double (*f)(double x), float tol, int iters) {
    double error = 10 * tol;
    int i = 0;
    double x2;
    while (error > tol && i < iters) {
        double fx1 = f(x1);
        x2 = x1 - (((x0 - x1) / (f(x0) - fx1)) * fx1);
        error = fabs(f(x2));
        x0 = x1;
        x1 = x2;
        i++;
    }

    return x2;
}