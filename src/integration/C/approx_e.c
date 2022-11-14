#include "functions.h"


double approx_e(long n, short parallel) {
    double e = 0.0;
    float factorial = 1.0;

    if (parallel) {
        #pragma omp parallel for reduction(+:e)
        {
            for (int i = 1; i < n + 1; i++) {
                e += 1.0 / factorial;
                factorial *= i;
            }
        }
    }
    else {
        for (int i = 1; i < n + 1; i++) {
            e += 1.0 / factorial;
            factorial *= i;
        }
    }

    return e;
}