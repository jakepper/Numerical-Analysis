#include "functions.h"
#include <math.h>

double trapezoid(double a, double b, double (*f)(double x), long n) {
    double h = fabs(b - a) / n;

    double sum = 0.0;
    double x;
    for (int i = 1; i < n; i++) {
        x = a + i*h;
        sum += f(x);
    }

    return (h / 2) * (f(a) + 2*sum + f(b));
}