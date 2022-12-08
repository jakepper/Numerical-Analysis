/*
    Compiler Instructions:

    gcc -c vectors.c matrices.c
    gcc -o ./executables/jacobi.exe jacobi.c vectors.o matrices.o -fopenmp -O1 -lm
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <omp.h>

#include "vectors.h"
#include "matrices.h"

#define LIMIT 64
#define M 128
#define N 128
#define MAX_ITERS 1000

void print_vector(int n, float[]);
void gen_vector(int n, float v[]);
void fill_vector(int n, float v[], float value);
void print_matrix(int m, int n, float[m][n]);
void gen_matrix(int m, int n, float A[m][n]);
int rand_lim(int limit);
void arr_alloc (size_t m, size_t n, float(**aptr)[m][n]);

int main(void) {
    double time;

    float (*A)[M][N]; // A
    arr_alloc(M, N, &A);
    gen_matrix(M, N, *A);
    print_matrix(M, N, *A);
    printf("\n");
    
    float x[N]; // x
    fill_vector(N, x, 1.0);
    print_vector(N, x);
    printf("\n");

    float y[N]; // = y
    gen_vector(N, y);
    print_vector(N, y);
    printf("\n");

    float (*D)[M][N]; // to hold D inverse
    arr_alloc(M, N, &D);

    printf("   jacobi (serial)\n");
    time = omp_get_wtime();
    jacobi(M, N, *A, x, y, *D, MAX_ITERS);
    printf("   Execution Time: %e sec\n", omp_get_wtime() - time);
    printf("   Solution: ");
    print_vector(N, x);
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

void fill_vector(int n, float v[], float value) {
    for (int i = 0; i < n; i++) {
        v[i] = value;
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