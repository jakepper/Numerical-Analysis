/*
Compile Instructions:

    gcc -c trapezoid.c approx_pi.c && gcc -o pi.exe pi.c trapezoid.o approx_pi.o -O1
    
*/


#include "functions.h"
#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, end;
    double time;
    start = clock();

    /* Serial PI Approximation*/
    long STEPS = 10000;
    printf("Approximation of PI with %ld partitions\n\n", STEPS);
    printf("\tResult: %.52f\n\n", approx_pi(STEPS));

    /* Parallel PI Approximation*/
    /* TODO */

    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution Time: %.12f\n", time);

    return 0;
}