#include "vectors.h"

/* Vector Addition */
void add(float u[], float v[], int n, float result[]) {    
    for (int i = 0; i < n; i++) {
        result[i] = u[i] + v[i];
    }
}

/* Vector Subtraction */
void sub(float u[], float v[], int n, float result[]) {
    for (int i = 0; i < n; i++) {
        result[i] = u[i] - v[i];
    }
}

/* Vector Multiplication by Scalar */
void mult(float v[], float c, int n, float result[]) {
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
    
}

/* Triple Vector Product */
void triple(float u[], float v[], float w[], int n, float result[]) {
    
}