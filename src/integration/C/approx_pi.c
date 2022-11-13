#include "functions.h"

double f(double);

double approx_pi(long steps, short parallel) {
    double pi;

    if (parallel) {
        pi =  4 * trapezoid_p(0.0, 1.0, f, steps);
    }
    else {
        pi =  4 * trapezoid_s(0.0, 1.0, f, steps);
    }

    return pi;
}

double f(double x) {
    return 1.0 / (1.0 + x * x);
}