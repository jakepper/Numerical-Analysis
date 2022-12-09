#include "matrices.h"
#include "vectors.h"
#include "arrays.h"

#include "omp.h"
#include <math.h>
#include <stdlib.h>


/* Matrix-Vector Product (serial) */
void action_s(int m, int n, double A[m][n], double b[n], double result[n]) {
    for (int i = 0; i < m; i++) {
        double sum = 0.0;
        for (int j = 0; j < n; j++) {
            sum += A[i][j] * b[j];
        }
        result[i] = sum;
    }
}

/* Matrix-Vector Product (parallel) */
void action_p(int m, int n, double A[m][n], double b[n], double result[n]) {
    int i;
    #pragma omp parallel for collapse(1)
    for (i = 0; i < m; i++) {
        double sum = 0.0;
        for (int j = 0; j < n; j++) {
            sum += A[i][j] * b[j];
        }
        result[i] = sum;
    }
}

/* Matrix Addition */
void m_add(int m, int n, double A[m][n], double B[m][n], double result[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

/* Matrix Subtraction */
void m_sub(int m, int n, double A[m][n], double B[m][n], double result[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

/* Product of Matrices (serial) */
void m_product_s(int m1, int n1, double A[m1][n1], int m2, int n2, double B[m2][n2], double result[m1][n2]) {
    if (n1 != m2) {
        return;
    }

    int i, j, k;
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n2; j++) {
            double sum = 0.0;
            for (k = 0; k < n1; k++) {
                sum += A[i][k] * B[k][j];
            }
            result[i][j] = sum;
        }
    }
}

/* Product of Matrices (parallel) */
void m_product_p(int m1, int n1, double A[m1][n1], int m2, int n2, double B[m2][n2], double result[m1][n2]) {
    if (n1 != m2) {
        return;
    }

    int i, j, k;
    double sum;
    #pragma omp parallel for collapse(2)
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n2; j++) {
            sum = 0.0;
            for (k = 0; k < n1; k++) {
                sum += A[i][k] * B[k][j];
            }
            result[i][j] = sum;
        }
    }
}

/* Hadamard Product of Matrices (serial) */
void m_hadamard_s(int m, int n, double A[m][n], double B[m][n], double result[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] * B[i][j];
        }
    }
}

/* Hadamard Product of Matrices (parallel) */
void m_hadamard_p(int m, int n, double A[m][n], double B[m][n], double result[m][n]) {
    int i, j;
    #pragma omp parallel for collapse(2)
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            result[i][j] = A[i][j] * B[i][j];
        }
    }
}

/* Kronecker Product of Matrices (serial) */
/* Result is a Matrix of Matrices (4 dimensional array) */
void kronecker_s(int m1, int n1, double A[m1][n1], int m2, int n2, double B[m2][n2], double result[m1][n1][m2][n2]) {
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            for (int k = 0; k < m2; k++) {
                for (int l = 0; l < n1; l++) {
                    result[i][j][k][l] = A[i][j] * B[k][l];
                }
            }
        }
    }
}

/* Kronecker Product of Matrices (parallel) */
/* Result is a Matrix of Matrices (4 dimensional array)*/
void kronecker_p(int m1, int n1, double A[m1][n1], int m2, int n2, double B[m2][n2], double result[m1][n1][m2][n2]) {
    int i, j, k, l;
    #pragma omp parallel for collapse(4)
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n1; j++) {
            for (k = 0; k < m2; k++) {
                for (l = 0; l < n1; l++) {
                    result[i][j][k][l] = A[i][j] * B[k][l];
                }
            }
        }
    }
}

/* Serial Power Method */
double power_method_s(int m, int n, double A[m][n], int max_iters, double approx[n]) {
    double Ab[n];

    // iterate
    for (int i = 0; i < max_iters; i++) {
        action_s(m, n, A, approx, Ab);
        v_mult_s(Ab, 1.0 / norm(n, Ab), n, approx);
    }

    // compute eigenvalue
    action_s(m, n, A, approx, Ab);
    double num = dot(approx, Ab, n);
    double den = dot(approx, approx, n);

    return num / den; // return eigenvalue | approximate eigenvector is stored in approx
}

/* Parallel Power Method */
double power_method_p(int m, int n, double A[m][n], int max_iters, double approx[n]) {
    double Ab[n];

    // iterate
    for (int i = 0; i < max_iters; i++) {
        action_p(m, n, A, approx, Ab);
        v_mult_p(Ab, 1.0 / norm(n, Ab), n, approx);
    }

    // compute eigenvalue
    action_p(m, n, A, approx, Ab);
    double num = dot(approx, Ab, n);
    double den = dot(approx, approx, n);

    return num / den; // return eigenvalue | approximate eigenvector is stored in approx
}

/* Inverse Power Method */
double inverse_power(int n, double A[n][n], double approx[n], int max_iters) {
    double sol[n]; // temp

    double (*D)[n][n]; // for jacobi
    arr_alloc(n, n, &D);

    // iterate
    for (int i = 0; i < max_iters; i++) {
        fill_vector(n, sol, 1.0);
        jacobi(n, A, sol, approx, *D, max_iters); // solve A*b_k+1 = b_k
        v_mult_s(sol, 1.0 / norm(n, sol), n, approx); // normalize : update approximation of eigen vector
    }

    // compute eigenvalue
    action_p(n, n, A, approx, sol);
    double num = dot(approx, sol, n);
    double den = dot(approx, approx, n);

    free(D);

    return num / den; // return eigenvalue | approximate eigenvector is stored in appprox
}

/* Shifted Inverse Power Method (serial) */
double inverse_power_shift(int n, double A[n][n], double approx[n], double shift, int max_iters) {
    double sol[n];

    double (*D)[n][n]; // for jacobi
    arr_alloc(n, n, &D);

    double (*sI)[n][n]; // (shift * I) where I is the identity matrix
    arr_alloc(n, n, &sI);
    for (int i = 0; i < n; i++) {
        *sI[i][i] = shift;
    }

    double (*B)[n][n]; // B = (A - shift * I)
    arr_alloc(n, n, &B);
    m_sub(n, n, A, *sI, *B);

    // iterate
    for (int i = 0; i < max_iters; i++) {
        fill_vector(n, sol, 1.0);
        jacobi(n, *B, sol, approx, *D, max_iters); // solve B*b_k+1 = b_k
        v_mult_s(sol, 1.0 / norm(n, sol), n, approx); // normalize : update approximation of eigen vector
    }

    // compute eigenvalue
    action_s(n, n, A, approx, sol);
    double num = dot(approx, sol, n);
    double den = dot(approx, approx, n);

    free(D);
    free(sI);
    free(B);

    return num / den; // return eigenvalue | approximate eigenvector is stored in appprox
}

/* Shifted Inverse Power Method (parallel) */
double inverse_power_shift_p(int n, double A[n][n], double approx[n], double shift, int max_iters) {
    double sol[n];

    double (*D)[n][n]; // for jacobi
    arr_alloc(n, n, &D);

    double (*sI)[n][n]; // (shift * I) where I is the identity matrix
    arr_alloc(n, n, &sI);
    for (int i = 0; i < n; i++) {
        *sI[i][i] = shift;
    }

    double (*B)[n][n]; // B = (A - shift * I)
    arr_alloc(n, n, &B);
    m_sub(n, n, A, *sI, *B);

    // iterate
    for (int i = 0; i < max_iters; i++) {
        fill_vector(n, sol, 1.0);
        jacobi_p(n, *B, sol, approx, *D, max_iters); // solve B*b_k+1 = b_k
        v_mult_p(sol, 1.0 / norm(n, sol), n, approx); // normalize : update approximation of eigen vector
    }

    // compute eigenvalue
    action_p(n, n, A, approx, sol);
    double num = dot(approx, sol, n);
    double den = dot(approx, approx, n);

    free(D);
    free(sI);
    free(B);

    return num / den; // return eigenvalue | approximate eigenvector is stored in appprox
}

/* Jacobi Iteration */
void jacobi(int n, double A[n][n], double x[n], double y[n], double D[n][n], int iters) {
    // initialize D inverse
    for (int i = 0; i < n; i++) {
        D[i][i] = 1.0 / A[i][i]; // place inverse of diagonal value in D
        A[i][i] = 0.0; // remove diagonal from A to create (L + U)
    }

    double temp1[n], temp2[n];
    for (int i = 0; i < iters; i++) {
        action_s(n, n, A, x, temp1); // (L + U)x
        v_sub(y, temp1, n, temp2); // y - (L + U)x
        action_s(n, n, D, temp2, x); // D^(-1)[y - (L + U)x]
    }

    // Revert changes made to A
    for (int i = 0; i < n; i++) {
        A[i][i] = 1.0 / D[i][i];
    }
}

/* Jacobi Iteration */
void jacobi_p(int n, double A[n][n], double x[n], double y[n], double D[n][n], int iters) {
    // initialize D inverse
    for (int i = 0; i < n; i++) {
        D[i][i] = 1.0 / A[i][i]; // place inverse of diagonal value in D
        A[i][i] = 0.0; // remove diagonal from A to create (L + U)
    }

    double temp1[n], temp2[n];
    for (int i = 0; i < iters; i++) {
        action_p(n, n, A, x, temp1); // (L + U)x
        v_sub(y, temp1, n, temp2); // y - (L + U)x
        action_p(n, n, D, temp2, x); // D^(-1)[y - (L + U)x]
    }

    // Revert changes made to A
    for (int i = 0; i < n; i++) {
        A[i][i] = 1.0 / D[i][i];
    }
}