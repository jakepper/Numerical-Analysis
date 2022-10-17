#include "functions.h"
#include <stdio.h>

double dP_dt(double, double, double);

int main()
{
    char verbose = 0;

    double alpha[] = {0.2, 0.01, 1.0};
    double beta = 0.0005;
    double P_0 = 10.0;

    for (int i = 0; i < 3; i++)
    {
        printf("Testing alpha = %f", alpha[i]);
        printf("Approximation: %f", explicit_euler(dP_dt, 0, P_0, alpha[i], beta, verbose));
    }

    return 0;
}

double dP_dt(double P, double alpha, double beta)
{
    return (alpha * P) - (beta * P * P);
}