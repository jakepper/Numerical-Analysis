/*
    Compiler Instructions:

    gcc -c vectors.c matrices.c -fopenmp -O1
    gcc -o ./executables/kronecker.exe kronecker.c matrices.o vectors.o -fopenmp -O1 -lm
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <omp.h>

#include "matrices.h"

#define LIMIT 10
#define M 1024
#define N 1024

void print_matrix(int m, int n, float[m][n]);
void gen_matrix(int m, int n, float A[m][n]);
int rand_lim(int limit);
void arr_alloc_2 (size_t m, size_t n, float(**aptr)[m][n]);
void arr_alloc_4 (size_t a, size_t b, size_t c, size_t d, float(**aptr)[a][b][c][d]);

int main(void) {
    double time;

    float (*A)[M][N];
    arr_alloc_2(M, N, &A);
    gen_matrix(M, N, *A);

    float (*B)[M][N];
    arr_alloc_2(M, N, &B);
    gen_matrix(M, N, *B);

    float (*result)[N][M][N] = malloc(sizeof(*result) * M);
    // arr_alloc_4(M, N, M, N, &result);
    assert(*result != NULL);

    printf("   Kronecker Product (serial)\n");
    time = omp_get_wtime();
    kronecker_s(M, N, *A, M, N, *B, result);
    printf("   Execution Time: %e sec\n", omp_get_wtime() - time);
    printf("\n");

    printf("   Kronecker Product (parallel)\n");
    time = omp_get_wtime();
    kronecker_p(M, N, *A, M, N, *B, result);
    printf("   Execution Time: %e sec\n", omp_get_wtime() - time);
    printf("\n");

    free(A);
    free(B);
    free(result);

    return 0;
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

void arr_alloc_2 (size_t m, size_t n, float(**aptr)[m][n])
{
  *aptr = malloc(sizeof(float[m][n]) ); // allocate a true 2D array
  assert(*aptr != NULL);
}

void arr_alloc_4(size_t a, size_t b, size_t c, size_t d, float(**aptr)[a][b][c][d]) {
    *aptr = malloc(sizeof(float[a][b][c][d]) ); // allocate a true 2D array
    assert(*aptr != NULL);
}