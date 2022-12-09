#include "vectors.h"

#include "omp.h"
#include <math.h>


double norm(int n, double v[]) {
    double sum = 0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++) {
        sum += v[i] * v[i];
    }

    return (double) sqrt(sum);
}

/* Vector Addition */
void v_add(double u[], double v[], int n, double result[]) {    
    for (int i = 0; i < n; i++) {
        result[i] = u[i] + v[i];
    }
}

/* Vector Subtraction */
void v_sub(double u[], double v[], int n, double result[]) {
    for (int i = 0; i < n; i++) {
        result[i] = u[i] - v[i];
    }
}

/* Vector Multiplication by Scalar (serial) */
void v_mult_s(double v[], double c, int n, double result[]) {
    for (int i = 0; i < n; i++) {
        result[i] = v[i] * c;
    }
}

/* Vector Multiplication by Scalar (parallel) */
void v_mult_p(double v[], double c, int n, double result[]) {
    int i;
    #pragma omp parallel for
    for (i = 0; i < n; i++) {
        result[i] = v[i] * c;
    }
}

/* Vector Dot Product */
double dot(double u[], double v[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += u[i] * v[i];
    }

    return sum;
}

/* Vector Cross Product */
void cross(double u[], double v[], int n, double result[]) {
    if (n != 3) {
        return;
    }
    
    result[0] = u[1] * v[2] - u[2] * v[1];
    result[1] = u[2] * v[0] - u[0] * v[2];
    result[2] = u[0] * v[1] - u[1] * v[0];
}

/* Triple Vector Product */
void triple(double u[], double v[], double w[], int n, double result[]) {
    if (n != 3) {
        return;
    }
    
    double temp[3];
    cross(v, w, n, temp);
    cross(u, temp, n, result);
}

void v_hadamard_s(double u[], double v[], int n, double result[]) {
    for (int i = 0; i < n; i++) {
        result[i] = u[i] * v[i];
    }
}

void v_hadamard_p(double u[], double v[], int n, double result[]) {
    int i;
    #pragma omp parallel for
    for (i = 0; i < n; i++) {
        result[i] = u[i] * v[i];
    }
}

void v_outer_s(double u[], double v[], int n, double result[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = u[i] * v[j];
        }
    }
}

void v_outer_p(double u[], double v[], int n, double result[n][n]) {
    int i, j;
    #pragma omp parallel for collapse(2)
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            result[i][j] = u[i] * v[j];
        }
    }
}