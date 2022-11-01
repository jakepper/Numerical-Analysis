#include <math.h>
#include "functions.h"

double secant_hybrid(double x0, double x1, double (*f)(double), float tol, int iters, int k) {
    double error = 10 * tol;
    double prev_error = error * 10;
    double x2;
    int i = 0;
    while (error > tol && i < iters) {
        double fx1 = f(x1);
        x2 = x1 - (((x0 - x1) / (f(x0) - fx1)) * fx1);
        error = fabs(f(x2));
        if (x2 <= x0 || x2 >= x1 || error > prev_error) {
            double results[2];
            x2 = bisect(x0, x1, f, k, results);
            x0 = results[0];
            x1 = results[1];
        }
        else {
            x0 = x1;
            x1 = x2;
        }
        prev_error = error;
        i++;
    }

    return x2;
}