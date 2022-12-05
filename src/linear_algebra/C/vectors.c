#include "vectors.h"
#include "omp.h"

/* Vector Addition */
void v_add(float u[], float v[], int n, float result[]) {    
    for (int i = 0; i < n; i++) {
        result[i] = u[i] + v[i];
    }
}

/* Vector Subtraction */
void v_sub(float u[], float v[], int n, float result[]) {
    for (int i = 0; i < n; i++) {
        result[i] = u[i] - v[i];
    }
}

/* Vector Multiplication by Scalar */
void v_mult(float v[], float c, int n, float result[]) {
    for (int i = 0; i < n; i++) {
        result[i] = v[i] * c;
    }
}

/* Vector Dot Product */
void dot(float u[], float v[], int n, float result) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += u[i] * v[i];
    }

    result = sum;
}

/* Vector Cross Product */
void cross(float u[], float v[], int n, float result[]) {
    if (n != 3) {
        return;
    }
    
    result[0] = u[1] * v[2] - u[2] * v[1];
    result[1] = u[2] * v[0] - u[0] * v[2];
    result[2] = u[0] * v[1] - u[1] * v[0];
}

/* Triple Vector Product */
void triple(float u[], float v[], float w[], int n, float result[]) {
    if (n != 3) {
        return;
    }
    
    float temp[3];
    cross(v, w, n, temp);
    cross(u, temp, n, result);
}

void v_hadamard_s(float u[], float v[], int n, float result[]) {
    for (int i = 0; i < n; i++) {
        result[i] = u[i] * v[i];
    }
}

void v_hadamard_p(float u[], float v[], int n, float result[]) {
    int i;
    #pragma omp parallel for shared(u, v, result) private(i)
    for (i = 0; i < n; i++) {
        result[i] = u[i] * v[i];
    }
}

void v_outer_s(float u[], float v[], int n, float result[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = u[i] * v[j];
        }
    }
}

void v_outer_p(float u[], float v[], int n, float result[n][n]) {
    int i;
    #pragma omp parallel for shared(u, v, result) private (i)
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = u[i] * v[j];
        }
    }
}