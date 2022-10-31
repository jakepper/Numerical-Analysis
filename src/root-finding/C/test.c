#include <stdio.h>
#include <math.h>

#include "functions.h"

float TOL = 0.000001;
int MAX_ITERS = 25;

double f(double);
double f_prime(double);

int main() {

    double x0 = -0.456;
    double x1 = 0.789;

    int k = (int) fabs((-1 * ((log10(TOL) / log10(x1 - x0))) / log10(2)) + 1);

    printf("Functional Iteration: %.4f\n", iterate(x1, f, TOL, MAX_ITERS));
    double bounds[2];
    printf("Bisection: %.4f\n", bisect(x0, x1, f, k, bounds));
    printf("Newtons: %.4f\n", newton(x0, f, f_prime, TOL, MAX_ITERS));
    printf("Secant: %.4f\n", secant(x0, x1, f, TOL, MAX_ITERS));
    printf("Secant Hybrid: %.4f\n", secant_hybrid(-13.456, 5.123, f, TOL, MAX_ITERS, k));
    printf("Newton Hybrid: %.4f\n", newton_hybrid(-16.123, 4.456, f, f_prime, TOL, MAX_ITERS, k));

    return 0;
}

double f(double x) {
    return x * exp(-x);
}

double f_prime(double x) {
    return (1 - x) * exp(-x);
}