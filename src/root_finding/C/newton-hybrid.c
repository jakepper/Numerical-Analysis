#include <math.h>
#include "functions.h"

double newton_hybrid(double a, double b, double (*f)(double), double (*f_prime)(double), double tol, int iters, int k) {
    double error = 10 * tol;
    double prev_error = error * 10;
    double x0 = (a + b) / 2;
    double x1;
    int i = 0;
    while (error > tol && i < iters) {
        x1 = x0 - (f(x0) / f_prime(x0));
        error = fabs(x1 - x0);
        if (x1 <= a || x1 >= b || error > prev_error) {
            double results[2];
            x0 = bisect(x0, x1, f, k, results);
            a = results[0];
            b = results[1];
        }
        else {
            x0 = x1;
        }
        prev_error = error;
        i++;
    }

    return x1;
}