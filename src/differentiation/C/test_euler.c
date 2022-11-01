/*
    Compile Instructions:

    gcc -o task-5.exe test_euler.c explicit_euler.o
*/

#include "functions.h"
#include <stdio.h>

double dP_dt(double, double, double);

int main()
{
    char verbose = 0;

    double alpha[] = {0.2, 0.01, 1.0};
    double beta = 0.0005;
    double P_0 = 10.0;

    printf("\nIVP: dP/dt = alpha * P - beta * P^2, P(0) = P_0\n\n");

    for (int i = 0; i < 3; i++)
    {
        printf("Testing alpha = %f, beta = %f, P_0 = %f\n\n", alpha[i], beta, P_0);
        printf("\tApproximation: %f\n\n", explicit_euler(dP_dt, 0, P_0, alpha[i], beta, verbose));
    }

    return 0;
}

double dP_dt(double P, double alpha, double beta)
{
    return (alpha * P) - (beta * P * P);
}