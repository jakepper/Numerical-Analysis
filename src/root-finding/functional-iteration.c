#include <stdio.h>;
#include <math.h>;

double iterate(double, double (*f)(double x), float, int);

double iterate(double x0, double (*f)(double x), float tol, int iters) {
    double error = 10 * tol;
    int i = 0;
    while (error > tol && i < iters) {
        double x1 = x0 + f(x0);
        error = fabs(x1 - x0);
        x0 = x1;
        i++;
    }

    return x0;
}