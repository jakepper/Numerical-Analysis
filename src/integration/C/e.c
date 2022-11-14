/*
Compile Instructions:

    gcc -c approx_e.c
    gcc -o e.exe e.c approx_e.o -O1
    rm approx_e.o
*/


#include "functions.h"
#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, mid, end;
    double time;
    long STEPS = 1000;
    start = clock();

    /* Serial e Approximation */
    printf("Serial approximation of e with n = %ld\n\n", STEPS);
    printf("\tResult: %.52f\n\n", approx_e(STEPS, 0));

    mid = clock();

    /* Parallel e Approximation */
    printf("Parallel approximation of e with n = %ld\n\n", STEPS);
    printf("\tResult: %.52f\n\n", approx_e(STEPS, 1));

    end = clock();
    time = ((double)(mid - start)) / CLOCKS_PER_SEC;
    printf("Serial Execution Time: %.12f seconds\n", time);
    time = ((double)(end - mid)) / CLOCKS_PER_SEC;
    printf("Parallel Execution Time: %.12f seconds\n", time);

    return 0;
}