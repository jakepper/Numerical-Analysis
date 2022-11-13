/*
Compile Instructions:

    gcc -c trapezoid_s.c trapezoid_p.c approx_pi.c 
    gcc -o pi.exe pi.c trapezoid_s.o trapezoid_p.o approx_pi.o -O1
    rm trapezoid_s.o trapezoid_p.o approx_pi.o
*/


#include "functions.h"
#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, mid, end;
    double time;
    long STEPS = 1000;
    start = clock();

    /* Serial PI Approximation*/
    printf("Serial approximation of PI with %ld partitions\n\n", STEPS);
    printf("\tResult: %.52f\n\n", approx_pi(STEPS, 0));

    mid = clock();

    /* Parallel PI Approximation*/
    printf("Parallel approximation of PI with %ld partitions\n\n", STEPS);
    printf("\tResult: %.52f\n\n", approx_pi(STEPS, 1));

    end = clock();
    time = ((double)(mid - start)) / CLOCKS_PER_SEC;
    printf("Serial Execution Time: %.12f seconds\n", time);
    time = ((double)(end - mid)) / CLOCKS_PER_SEC;
    printf("Parallel Execution Time: %.12f seconds\n", time);

    return 0;
}