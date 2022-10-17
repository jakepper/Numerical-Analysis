# First Derivative Approximation

**Routine Name:** approx_f1

**Author:** Jake Epperson

**Language:** C

The program can be compiled into an object file as follows,

    gcc -c approx_f1.c

from the `src/differentiation/` directory.

**Description/Purpose:** This routine will compute an approximation of the first derivative of a function f(x) at a given point x

**Inputs:**

- x : double
- h : double
- f : (*f)(double)

**Output:** approximation : double

**Usage/Example:**
    
    double f(x) {
        return x*x
    }
    
    double h = 0.001;
    double x = 0.5;
    printf("f'(%.1f) => %f", x, approx_f1(x, h, f));

Output:

    f'(0.5) => 1.000000

**Implementation/Code:** [approx_f1.c](../../src/differentiation/approx_f1.c)