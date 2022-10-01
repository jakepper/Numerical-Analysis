#include <stdio.h>;
#include <math.h>;

double bisect(double, double, double (*f)(double x), float, int);

double bisect(double a, double b, double (*f)(double x), float tol, int iters) {
    double root;
    int i = 0;
    while (i < iters) {
        double fa = f(a);
        double fb = f(b);
        if (a < b && fa * fb < 0) {
            double m = (a + b) / 2;
            double fm = f(m);
            if (fabs(fm) < tol) {
                root = m;
            }
            else if (fa * fm < 0) {
                b = m;
            }
            else {
                a = m;
            }
        }
        i++;
    }

    return root;
}