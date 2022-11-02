#include "functions.h"

void simple_linear_regression(double x[], double y[], int n, double result[])
{
    double sum_x = 0, sum_x2 = 0, sum_y = 0, sum_xy = 0;

    for (int i = 0; i < n; i++)
    {
        sum_x += x[i];
        sum_x2 += x[i] * x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
    }

    double slope = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    double intercept = (sum_y - slope * sum_x) / n;

    result[0] = slope;
    result[1] = intercept;
}