/*
    Compile Instructions:

    gcc -o task-2&3.exe test_euler.c approx_f2.o ../fitting/simple_linear_regression.o
*/

#include "functions.h"
#include <stdio.h>
#include <math.h>

double f(double);
void simple_linear_regression(double x[], double y[], int n, double result[]);

int main()
{
    int n = 4;
    double h = 0.001;

    double x[] = {-M_PI_4, 0.0, M_PI_4, 1.0};
    double y[n];

    printf("f(x) = (x - pi/2) * tan^2(x) / (x^2 + 65)\n");
    printf("h = %.3f\n\n", h);

    for (int i = 0; i < n; i++)
    {
        y[i] = approx_f2(x[i], h, f);
        printf("f''(%f) \u2248 %f\n", x[i], y[i]);
    }
    printf("\n");


    double result[2];
    simple_linear_regression(x, y, n, result);

    printf("Testing Simple Linear Regression with the output from the second derivative approximation of f(x)\n\n");
    printf("\ty = %fx + %f\n\n", result[0], result[1]);

    return 0;
}

double f(double x)
{
    return ((x - M_PI_2) * pow(tan(x), 2)) / (x * x + 65);
}