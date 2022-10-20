# Functional Iteration

**Routine Name:** func_iter

**Author:** Jake Epperson

**Language:** Python

Run the `tasksheet1` program  as follows to test the func_iter method,

    python tasksheet1.py -t 1

or with the argument `-v` for tabular results

    python tasksheet1.py -t 1 -v

from the `src/root-finding/Python` directory.

**Description/Purpose:** This routine will compute an approximation of the root of a given function f(x),

This is done using the funcitonal iteration method of root finding.

**Inputs:**

- x0 : initial x value to begin iteration with
- $ g $ : function used during iteration used to approximate root
- Tolerance : upper bound for the error in the approximation
- Max Iterations : maximum allowed iterations before program terminates
- verbose : specifies whether to print tabular results

**Output:**

- Approximate root is printed 
- Tabular data is printed when specified
- Approximate root is returned

**Usage/Example:**

    python tasksheet1.py -t 1

Output:
```
Functional Iteration with f(x) = x * e^(-x)

   g -> x - f(x)

   Approximate Root: 0.000000

   g -> x + f(x)

   Approximate Root: 4.530660
```
**Implementation/Code:** [functional-iteration.py](../../src/root-finding/Python/functional_iteration.py)

**Test Implementation/Code:** [tasksheet1.py](../../src/root-finding/Python/tasksheet1.py)