# Newton-Bisection Hybrid

**Routine Name:** newton_hybrid

**Author:** Jake Epperson

**Language:** Python

Run the `tasksheet2` program  as follows to test the newton_hybrid method,

    python tasksheet2.py -t 4

or with the argument `-v` for tabular results

    python tasksheet2.py -t 4 -v

from the `src/root-finding/Python` directory.

**Description/Purpose:** This routine will compute an approximation of the root of a given function f(x),

This is done using a Newton-bisection hybrid method of root finding.

**Inputs:**

- a : lower bound of initial approximation
- b : upper bound of initial approximation
- f : function of which we are approximating the root/s of
- f_prime : derivative of f (used in approximation)
- tol : upper bound for the error in the approximation
- max_iters : maximum allowed iterations before program terminates
- verbose : specifies whether to print tabular results

**Output:**

- Tabular data is printed when specified
- Approximate root is printed and returned

**Usage/Example:**

    python tasksheet2.py -t 4

Output:
```
Newton Hybrid method with f(x) = x * e^(-x)

Interval [0.1, 0.11]:

   Approximate Root: 0.105263

Interval [0.11, 0.125]:

   Approximate Root: 0.117647

Interval [0.125, 0.14]:

   Approximate Root: 0.133333

Interval [0.14, 0.17]:

   Approximate Root: 0.153846

Interval [0.17, 0.21]:

   Approximate Root: 0.181818

Interval [0.21, 0.26]:

   Approximate Root: 0.222222

Interval [0.26, 0.31]:

   Approximate Root: 0.285714

Interval [0.31, 0.6]:

   Approximate Root: 0.400000

Interval [0.6, 1]:

   Approximate Root: 0.666667

Interval [1, 2.8]:

   Approximate Root: 2.000000
```
**Implementation/Code:** [newton_hybrid.py](../../src/root-finding/Python/newton_hybrid.py)

**Test Implementation/Code:** [tasksheet2.py](../../src/root-finding/Python/tasksheet2.py)