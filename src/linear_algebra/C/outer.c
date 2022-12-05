/*
    Compiler Instructions:

    gcc -c vectors.c matrices.c -fopenmp -O3
    gcc -o outer.exe outer.c vectors.o matrices.o -fopenmp -O3
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

void print_vector(int n, float[]);
void gen_vector(int n, float v[]);
void print_matrix(int m, int n, float[m][n]);
void gen_matrix(int m, int n, float A[m][n]);
int rand_lim(int limit);
void arr_alloc (size_t m, size_t n, float(**aptr)[m][n]);

int main(void) {
    double time;

    float u[N];
    float v[N];
    gen_vector(N, u);
    gen_vector(N, v);

    float (*m_result)[M][N];
    arr_alloc(M, N, &m_result);

    printf("   Vector Outer Product (serial)\n");
    time = omp_get_wtime();
    v_outer_s(u, v, N, *m_result);
    printf("   Execution Time: %e sec\n", omp_get_wtime() - time);
    printf("\n");

    printf("   Vector Outer Product (parallel)\n");
    time = omp_get_wtime();
    v_outer_p(u, v, N, *m_result);
    printf("   Execution Time: %e sec\n", omp_get_wtime() - time);
    printf("\n");

    free(m_result);

    return 0;
}

void print_vector(int n, float v[]) {
    for (int i = 0; i < n; i++) {
        printf("%.1f  ", v[i]);
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

void arr_alloc (size_t m, size_t n, float(**aptr)[m][n])
{
  *aptr = malloc(sizeof(float[m][n]) ); // allocate a true 2D array
  assert(*aptr != NULL);
}