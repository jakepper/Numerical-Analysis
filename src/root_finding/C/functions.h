double iterate(double, double (*f)(double x), double, int);
double newton(double, double (*f)(double x), double (*f_prime)(double), double, int);
double bisect(double, double, double (*f)(double), int, double[2]);
double secant(double, double, double (*f)(double), double, int);
double secant_hybrid(double, double, double (*f)(double), double, int, int);
double newton_hybrid(double, double, double (*f)(double), double (*f_prime)(double), double, int, int);