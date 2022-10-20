# Bisection

**Routine Name:** bisect

**Author:** Jake Epperson

**Language:** Python

Run the `tasksheet1` program  as follows to test the bisection method,

    python tasksheet1.py -t 4

or with the argument `-v` for tabular results

    python tasksheet1.py -t 4 -v

from the `src/root-finding/Python` directory.

**Description/Purpose:** This routine will compute an approximation of the root of of a given function f(x).

This is done using the bisection method of root finding.

**Inputs:**

- $ a $ : Lower Bound
- $ b $ : Upper Bound
- $ f(x) $ function to approximate root of
- tol : upper bound for the error in the approximation
- verbose : specifies whether to print tabular results

Calculated Inputs
- Iterations ($k$)

**Output:** 

- Approximate root is printed 
- Tabular data is printed when specified
- Approximate root is returned

**Usage/Example:**

    python tasksheet1.py -t 4

Output:
```
Bisection with f(x) = x * e^(-x)

   Approximate Root: -0.000001

Bisection with f(x) = 10.14 * e^(x^2) * cos(π/x)

   Approximate Root: 0.666667
```

**Implementation/Code:** [bisection.py](../../src/root-finding/Python/bisection.py)

**Test Implementation/Code:** [tasksheet1.py](../../src/root-finding/Python/tasksheet1.py)