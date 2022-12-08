/*
    Compiler Instructions:

    gcc -c vectors.c matrices.c -fopenmp -O1
    gcc -o ./executables/had_m.exe had_m.c vectors.o matrices.o -fopenmp -O1 -lm
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

void print_matrix(int m, int n, float[m][n]);
int rand_lim(int limit);
void gen_matrix(int m, int n, float A[m][n]);
void arr_alloc (size_t m, size_t n, float(**aptr)[m][n]);

int main(void) {
    printf("   M = %d, N = %d\n\n", M, N);
    double time;

    float (*A)[M][N];
    arr_alloc(M, N, &A);
    float (*B)[M][N];
    arr_alloc(M, N, &B);
    gen_matrix(M, N, *A);
    gen_matrix(M, N, *B);
    float (*m_result)[M][N];
    arr_alloc(M, N, &m_result);

    printf("   Hadamard Matrix Product (serial)\n");
    time = omp_get_wtime();
    m_hadamard_s(M, N, *A, *B, *m_result);
    printf("   Execution Time: %e sec\n", omp_get_wtime() - time);
    printf("\n");

    printf("   Hadamard Matrix Product (parallel)\n");
    time = omp_get_wtime();
    m_hadamard_p(M, N, *A, *B, *m_result);
    printf("   Execution Time: %e sec\n", omp_get_wtime() - time);
    printf("\n");

    free(A);
    free(B);
    free(m_result);

    return 0;
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

void print_matrix(int m, int n, float A[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.1f  ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void arr_alloc (size_t m, size_t n, float(**aptr)[m][n])
{
  *aptr = malloc(sizeof(float[m][n]) ); // allocate a true 2D array
  assert(*aptr != NULL);
}