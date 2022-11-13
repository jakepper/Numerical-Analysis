#include "functions.h"

double f(double);

double approx_pi(long steps) {
    return 4 * trapezoid(0.0, 1.0, f, steps);
}

double f(double x) {
    return 1.0 / (1.0 + x * x);
}