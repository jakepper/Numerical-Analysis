# Secant

**Routine Name:** newton

**Author:** Jake Epperson

**Language:** Python

Run the `tasksheet2` program  as follows to test the newton method,

    python tasksheet2.py -t 1

or with the argument `-v` for tabular results

    python tasksheet2.py -t 1 -v

from the `src/root-finding/Python` directory.

**Description/Purpose:** This routine will compute an approximation of the root of a given function f(x),

This is done using Newton's method of root finding.

**Inputs:**

- x0 : initial approximation
- f : function of which we are approximating the root/s of
- f_prime : derivative of f (used in approximation)
- tol : upper bound for the error in the approximation
- max_iters : maximum allowed iterations before program terminates
- verbose : specifies whether to print tabular results

**Output:**

- Tabular data is printed when specified
- Approximate root is printed and returned

**Usage/Example:**

    python tasksheet2.py -t 1

Output:
```
Newtons method with f(x) = x * e^(-x)

        Approximate Root: -0.000000
```
**Implementation/Code:** [newton.py](../../src/root-finding/Python/newton.py)

**Test Implementation/Code:** [tasksheet2.py](../../src/root-finding/Python/tasksheet2.py)