/*
    Compiler Instructions:

    gcc -c arrays.c vectors.c matrices.c
    gcc -o ./executables/inverse_power_test.exe inverse_power_test.c arrays.o vectors.o matrices.o -fopenmp -O1 -lm
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <omp.h>
#include <time.h>

#include "vectors.h"
#include "matrices.h"
#include "arrays.h"

#define M 2
#define N 2
#define MAX_ITERS 100

int main(void) {
    /* Intializes random number generator */
    time_t t;
    srand((unsigned) time(&t));

    printf("   M = %d, N = %d\n\n", M, N);
    double time;

    double eigen_value;
    double eigen_vector[N];

    double A[M][N] = {{-6, 3}, {4, 5}}; // A
    printf("   A: ");
    print_matrix(M, N, A);
    // arr_alloc(M, N, &A);
    // gen_matrix(M, N, *A);
    // scale_diag(N * 2, *A);

    printf("   Power Method (serial)\n");
    gen_vector(N, eigen_vector); // random vector for initial approximation
    time = omp_get_wtime();
    eigen_value = power_method_s(M, N, A, MAX_ITERS, eigen_vector);
    // eigen_value = inverse_power_shift(N, A, eigen_vector, 0.0, MAX_ITERS);
    printf("   Execution Time: %e sec\n", omp_get_wtime() - time);
    printf("   Eigen Vector (normalized): ");
    print_vector(N, eigen_vector);
    printf("   Eigen Value: %f\n", eigen_value);
    printf("\n");

    printf("   Inverse Power Method (serial)\n");
    gen_vector(N, eigen_vector); // random vector for initial approximation
    time = omp_get_wtime();
    eigen_value = inverse_power(N, A, eigen_vector, MAX_ITERS);
    // eigen_value = inverse_power_shift(N, A, eigen_vector, 0.0, MAX_ITERS);
    printf("   Execution Time: %e sec\n", omp_get_wtime() - time);
    printf("   Eigen Vector (normalized): ");
    print_vector(N, eigen_vector);
    printf("   Eigen Value: %f\n", eigen_value);
    printf("\n");

    // free(A);

    return 0;
}