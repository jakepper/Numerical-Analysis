/*
    Compiler Instructions:

    gcc -c vectors.c matrices.c -fopenmp -O1
    gcc -o ./executables/had_v.exe had_v.c vectors.o matrices.o -fopenmp -O1 -lm
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <omp.h>

#include "vectors.h"
#include "matrices.h"

#define LIMIT 10
#define M 2048
#define N 2048

void print_vector(int n, double[]);
int rand_lim(int limit);
void gen_vector(int n, double v[]);

int main(void) {
    printf("   M = %d, N = %d\n\n", M, N);
    double time;

    double u[N];
    double v[N];
    gen_vector(N, u);
    gen_vector(N, v);
    double v_result[N];

    printf("   Hadamard Vector Product (serial)\n");
    time = omp_get_wtime();
    v_hadamard_s(u, v, N, v_result);
    printf("   Execution Time: %e sec\n", omp_get_wtime() - time);
    printf("\n");

    printf("   Hadamard Vector Product (parallel)\n");
    time = omp_get_wtime();
    v_hadamard_p(u, v, N, v_result);
    printf("   Execution Time: %e sec\n", omp_get_wtime() - time);
    printf("\n");

    return 0;
}

void gen_vector(int n, double v[]) {
    for (int i = 0; i < n; i++) {
        v[i] = (double) rand_lim(LIMIT);
    }
}

int rand_lim(int limit) {
    int divisor = RAND_MAX / (limit+1);
    int retval;

    do { 
        retval = rand() / divisor;
    } while (retval > limit);

    return retval;
}

void print_vector(int n, double v[]) {
    for (int i = 0; i < n; i++) {
        printf("%.1f  ", v[i]);
    }
    printf("\n");
}