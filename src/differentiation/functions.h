double approx_f1(double x, double h, double (*f)(double));

double approx_f2(double x, double h, double (*f)(double));

double explicit_euler(double (*f)(double, double, double), double, double, double, double, char);
