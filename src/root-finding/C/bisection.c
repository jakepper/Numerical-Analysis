#include <stdio.h>
#include <math.h>

#include "functions.h"

double bisect(double a, double b, double (*f)(double x), int iters, double results[]) {
    double m;
    for (int i = 0; i <= iters; i++) {
        double fa = f(a);
        double fb = f(b);
        if (a < b && fa * fb < 0) {
            m = (a + b) / 2;
            if (fa * f(m) < 0) {
                b = m;
            }
            else {
                a = m;
            }
        }
    }

    /* resulting bounds */
    results[0] = a;
    results[1] = b;

    /* approximate root */
    return m;
}