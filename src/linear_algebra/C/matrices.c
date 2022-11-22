#include "matrices.h"
#include "omp.h"

/* Matrix-Vector Product */
void m_action(int m, int n, float A[m][n], float b[n], float result[]) {
    for (int i = 0; i < m; i++) {
        float sum = 0.0;
        for (int j = 0; j < n; j++) {
            sum += A[i][j] * b[j];
        }
        result[i] = sum;
    }
}

/* Matrix Addition */
void m_add(int m, int n, float A[m][n], float B[m][n], float result[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

/* Matrix Subtraction */
void m_sub(int m, int n, float A[m][n], float B[m][n], float result[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

/* Product of Matrices (parallel) */
void m_product(int m1, int n1, float A[m1][n1], int m2, int n2, float B[m2][n2], float result[m1][n2]) {
    if (n1 != m2) {
        return;
    }

    int i, j, k;
    #pragma omp parallel for shared(A, B, result) private(i, j, k)
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n2; j++) {
            float sum = 0.0;
            for (k = 0; k < n1; k++) {
                sum += A[i][k] * B[k][j];
            }
            result[i][j] = sum;
        }
    }
}

/* Hadamard Product of Matrices (serial) */
void m_hadamard_s(int m, int n, float A[m][n], float B[m][n], float result[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] * B[i][j];
        }
    }
}

/* Hadamard Product of Matrices (parallel) */
void m_hadamard_p(int m, int n, float A[m][n], float B[m][n], float result[m][n]) {
    int i, j;
    #pragma omp parallel for shared(A, B, result) private(i, j)
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            result[i][j] = A[i][j] * B[i][j];
        }
    }
}