#include "functions.h"
#include <stdio.h>
#include <math.h>

double f(double);
void simple_linear_regression(double x[], double y[], int n, double result[]);

int main()
{
    int n = 4;
    double h = 0.1;

    double x[] = {0, M_PI_4, M_PI_2, M_PI};
    double y[n];

    for (int i = 0; i < n; i++)
    {
        y[i] = approx_f2(x[i], h, f);
    }

    double result[2];
    simple_linear_regression(x, y, n, result);

    printf("Testing Simple Linear Regression with f(x) = (x - pi/2)tan(x) / (x^2 + 65) with values,\nx = ");
    for (int i = 0; i < n; i++)
    {
        printf("%f, ", x[i]);
    }
    printf("\nSlope: %f\n", result[0]);
    printf("Intercept: %f\n", result[1]);

    return 0;
}

double f(double x)
{
    return ((x - M_PI_2) * tan(x)) / (x * x + 65);
}