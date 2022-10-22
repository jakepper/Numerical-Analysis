# Secant

**Routine Name:** secant

**Author:** Jake Epperson

**Language:** Python

Run the `tasksheet2` program  as follows to test the secant method,

    python tasksheet2.py -t 2

or with the argument `-v` for tabular results

    python tasksheet2.py -t 2 -v

from the `src/root-finding/Python` directory.

**Description/Purpose:** This routine will compute an approximation of the root of a given function f(x),

This is done using the secant method of root finding.

**Inputs:**

- x0 : lower bound
- x1 : upper bound
- f : function of which we are approximating the root/s of
- tol : upper bound for the error in the approximation
- max_iters : maximum allowed iterations before program terminates
- verbose : specifies whether to print tabular results

**Output:**

- Tabular data is printed when specified
- Approximate root is printed and returned

**Usage/Example:**

    python tasksheet2.py -t 2

Output:
```
Secant method with f(x) = x * e^(-x)

        Approximate Root: -0.000000
```
**Implementation/Code:** [secant.py](../../src/root-finding/Python/secant.py)

**Test Implementation/Code:** [tasksheet2.py](../../src/root-finding/Python/tasksheet2.py)