#include "functions.h"
#include <stdio.h>
#include <math.h>

int main()
{
    int n = 9;
    double x[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    double y[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};

    double result[2];
    simple_linear_regression(x, y, n, result);

    printf("Testing Simple Linear Regression with f(x) = x\n");
    printf("Slope: %f\n", result[0]);
    printf("Intercept: %f\n", result[1]);
    printf("Resulting Equation: y = %fx + %f", result[0], result[1]);

    for (int i = 0; i < n; i++)
    {
        y[i] += 4;
    }

    simple_linear_regression(x, y, n, result);

    printf("Testing Simple Linear Regression with f(x) = x + 4\n");
    printf("Slope: %f\n", result[0]);
    printf("Intercept: %f\n", result[1]);
    printf("Resulting Equation: y = %fx + %f", result[0], result[1]);

    return 0;
}