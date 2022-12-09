/*
    Compiler Instructions:

    gcc -c arrays.c vectors.c matrices.c
    gcc -o ./executables/inverse_power_shift_comparison128.exe inverse_power_shift_comparison.c arrays.o vectors.o matrices.o -fopenmp -O1 -lm
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <omp.h>
#include <time.h>

#include "vectors.h"
#include "matrices.h"
#include "arrays.h"

#define M 128
#define N 128
#define MAX_ITERS 50

int main(void) {
    /* Intializes random number generator */
    time_t t;
    srand((unsigned) time(&t));

    printf("   M = %d, N = %d\n\n", M, N);
    double time;

    double eigen_value;
    double eigen_vector[N];
    double (*A)[M][N];
    arr_alloc(M, N, &A);
    gen_matrix(M, N, *A);

    printf("   Power Method (serial)\n");
    gen_vector(N, eigen_vector); // random vector for initial approximation
    time = omp_get_wtime();
    eigen_value = inverse_power_shift(N, *A, eigen_vector, 2.2, MAX_ITERS);
    printf("   Execution Time: %e sec\n", omp_get_wtime() - time);
    printf("   Eigen Value: %f\n", eigen_value);
    printf("\n");

    printf("   Inverse Power Method (serial)\n");
    gen_vector(N, eigen_vector); // random vector for initial approximation
    time = omp_get_wtime();
    eigen_value = inverse_power_shift_p(N, *A, eigen_vector, 2.2, MAX_ITERS);
    printf("   Execution Time: %e sec\n", omp_get_wtime() - time);
    printf("   Eigen Value: %f\n", eigen_value);
    printf("\n");

    free(A);

    return 0;
}