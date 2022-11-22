#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "vectors.h"
#include "matrices.h"

#define LIMIT 10
#define M 4096
#define N 4096

void print_matrix(int m, int n, float[m][n]);
void print_vector(int n, float[]);
int rand_lim(int limit);
void gen_vector(int n, float v[]);
void gen_matrix(int m, int n, float A[m][n]);
void arr_alloc (size_t m, size_t n, float(**aptr)[m][n]);

int main(void) {
    clock_t start, end;

    float u[N];
    float v[N];
    gen_vector(N, u);
    gen_vector(N, v);
    float v_result[N];

    printf("Hadamard Vector Product (serial)\n");
    start = clock();
    v_hadamard_s(u, v, N, v_result);
    end = clock();
    printf("Execution Time: %e sec\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    printf("\n");

    printf("Hadamard Vector Product (parallel)\n");
    start = clock();
    v_hadamard_p(u, v, N, v_result);
    end = clock();
    printf("Execution Time: %e sec\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    printf("\n");

    float (*A)[M][N];
    arr_alloc(M, N, &A);
    float (*B)[M][N];
    arr_alloc(M, N, &B);
    gen_matrix(M, N, *A);
    gen_matrix(M, N, *B);
    float (*m_result)[M][N];
    arr_alloc(M, N, &m_result);

    printf("Hadamard Matrix Product (serial)\n");
    start = clock();
    m_hadamard_s(M, N, *A, *B, *m_result);
    end = clock();
    printf("Execution Time: %e sec\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    printf("\n");

    printf("Hadamard Matrix Product (parallel)\n");
    start = clock();
    m_hadamard_p(M, N, *A, *B, *m_result);
    end = clock();
    printf("Execution Time: %e sec\n", ((double) (end - start)) / CLOCKS_PER_SEC);
    printf("\n");

    free(A);
    free(B);

    return 0;
}

void gen_vector(int n, float v[]) {
    for (int i = 0; i < n; i++) {
        v[i] = (float) rand_lim(LIMIT);
    }
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

void print_vector(int n, float v[]) {
    for (int i = 0; i < n; i++) {
        printf("%.1f  ", v[i]);
    }
    printf("\n");
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