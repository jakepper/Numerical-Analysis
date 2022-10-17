# Simple Linear Regression

**Routine Name:** simple_linear_regression

**Author:** Jake Epperson

**Language:** C

The program can be compiled into an object file as follows,

    gcc -c simple_linear_regression.c

from the `src/fitting/` directory.

**Description/Purpose:** This routine will perform a simple linear regression given 

**Inputs:**

- x : double[]
- y : double[]
- n : int
- result: double[2]

**Output:** result -> [slope: double, intercept: double]

**Usage/Example:**
    
    int n = 4;
    double x[] = {1, 2, 3, 4};
    double x[] = {3, 4, 5, 6};
    double result[2];
    simple_linear_regression(x, y, n, result));
    printf("slope: %f\nintercept: %f\n", result[0], result[1]);

Output:

    slope: 1.000000
    intercept: 2.000000

**Implementation/Code:** [simple_linear_regression.c](../../src/fitting/simple_linear_regression.c)