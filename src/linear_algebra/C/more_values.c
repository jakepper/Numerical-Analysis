/*
    Compiler Instructions:

    gcc -c arrays.c vectors.c matrices.c
    gcc -o ./executables/more_values.exe more_values.c arrays.o vectors.o matrices.o -fopenmp -O1 -lm
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <omp.h>
#include <time.h>

#include "vectors.h"
#include "matrices.h"
#include "arrays.h"

#define M 16
#define N 16
#define MAX_ITERS 100

int main(void) {
    /* Intializes random number generator */
    time_t t;
    srand((unsigned) time(&t));

    printf("   M = %d, N = %d\n\n", M, N);
    double eigen_values[2];
    double eigen_vector[N];
    double (*A)[M][N];
    arr_alloc(M, N, &A);
    gen_matrix(M, N, *A);

    fill_vector(N, eigen_vector, 1.0);
    eigen_values[0] = power_method_s(M, N, *A, MAX_ITERS, eigen_vector);
    fill_vector(N, eigen_vector, 1.0);
    eigen_values[1] = inverse_power(N, *A, eigen_vector, MAX_ITERS);
    double max = fmax(eigen_values[0], eigen_values[1]);
    double min = fmin(eigen_values[0], eigen_values[1]);

    printf("   Eigen Values: min = %f, max = %f\n", min, max);
    double eigenvalue, shift;
    for (int i = min + 1; i < max; i++) {
        gen_vector(N, eigen_vector);
        shift = (double) i;
        eigenvalue = inverse_power_shift(N, *A, eigen_vector, shift, MAX_ITERS);
        printf("   Shift = %f: eigenvalue = %f\n", shift, eigenvalue);
    }

    free(A);

    return 0;
}