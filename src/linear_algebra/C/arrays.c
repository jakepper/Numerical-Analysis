#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "arrays.h"

#define LIMIT 5

void print_vector(int n, double v[n]) {
    for (int i = 0; i < n; i++) {
        printf("%f  ", v[i]);
    }
    printf("\n");
}

void gen_vector(int n, double v[n]) {
    for (int i = 0; i < n; i++) {
        v[i] = (double) rand_lim(LIMIT);
    }
}

void fill_vector(int n, double v[n], double value) {
    for (int i = 0; i < n; i++) {
        v[i] = value;
    }
}

void scale_diag(int n, int c, double A[n][n]) {
    for (int i = 0; i < n; i++) {
        A[i][i] = A[i][i] * c;
    }
}

void print_matrix(int m, int n, double A[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f  ", A[i][j]);
        }
        printf("\n      ");
    }
    printf("\n");
}

void gen_matrix(int m, int n, double A[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = (double) rand_lim(LIMIT);
        }
    }
}

int rand_lim(int limit) {
    int divisor = RAND_MAX / (limit);
    int retval;

    do { 
        retval = rand() / divisor;
    } while (retval > limit);

    return retval + 1;
}

void arr_alloc (int m, int n, double(**aptr)[m][n])
{
  *aptr = malloc(sizeof(double[m][n]) ); // allocate a true 2D array
  assert(*aptr != NULL);
}