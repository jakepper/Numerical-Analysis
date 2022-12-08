/*
    Compiler Instructions:

    gcc -c vectors.c matrices.c
    gcc -o ./executables/power256.exe power_method.c vectors.o matrices.o -fopenmp -O1 -lm
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <omp.h>

#include "vectors.h"
#include "matrices.h"

#define LIMIT 10
#define M 256
#define N 256
#define MAX_ITERS 1000

void print_vector(int n, float[]);
void gen_vector(int n, float v[]);
void print_matrix(int m, int n, float[m][n]);
void gen_matrix(int m, int n, float A[m][n]);
int rand_lim(int limit);
void arr_alloc (size_t m, size_t n, float(**aptr)[m][n]);

int main(void) {
    printf("   M = %d, N = %d\n\n", M, N);
    double time;

    float eigen_value;
    float eigen_vector[N];

    float (*A)[M][N];
    arr_alloc(M, N, &A);
    gen_matrix(M, N, *A);

    printf("   Power Method (serial)\n");
    gen_vector(N, eigen_vector); // random vector for initial approximation
    time = omp_get_wtime();
    eigen_value = power_method_s(M, N, *A, MAX_ITERS, eigen_vector);
    printf("   Execution Time: %e sec\n", omp_get_wtime() - time);
    if (N < 17) {
        printf("   Eigen Vector: ");
        print_vector(N, eigen_vector);
    }
    printf("   Eigen Value: %f\n", eigen_value);
    printf("\n");

    printf("   Power Method (parallel)\n");
    gen_vector(N, eigen_vector); // random vector for initial approximation
    time = omp_get_wtime();
    eigen_value = power_method_p(M, N, *A, MAX_ITERS, eigen_vector);
    printf("   Execution Time: %e sec\n", omp_get_wtime() - time);
    if (N < 17) {
        printf("   Eigen Vector: ");
        print_vector(N, eigen_vector);
    }
    printf("   Eigen Value: %f\n", eigen_value);
    printf("\n");

    free(A);

    return 0;
}

void print_vector(int n, float v[]) {
    for (int i = 0; i < n; i++) {
        printf("%f  ", v[i]);
    }
    printf("\n");
}

void gen_vector(int n, float v[]) {
    for (int i = 0; i < n; i++) {
        v[i] = (float) rand_lim(LIMIT);
    }
}

void print_matrix(int m, int n, float A[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f  ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void gen_matrix(int m, int n, float A[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = (float) rand_lim(LIMIT);
        }
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

void arr_alloc (size_t m, size_t n, float(**aptr)[m][n])
{
  *aptr = malloc(sizeof(float[m][n]) ); // allocate a true 2D array
  assert(*aptr != NULL);
}