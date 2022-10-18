# Secant/Bisection Hybrid Method

**Routine Name:** secant-hybrid

**Author:** Jake Epperson

**Language:** Python

The program can be ran as follows,

    python secant-hybrid.py

or with the argument `-v` for tabular results

    python secant-hybrid.py -v

from the `src/root-finding/Python` directory.

**Description/Purpose:** This routine will compute an approximation of 10 roots of the following function,

$$ f(x) = 10.14e^{x^2}\cos(\frac{\pi}{x}) $$

This is done using a secant and bisection hybrid method for root finding.

**Inputs:**

Pre-determined Inputs
- $ f(x)$
- $ g(x) $ : secant approximation function
- Tolerance : upper bound for the error in the approximation
- Max Iterations : maximum allowed iterations before program terminates
- Intervals of which will be tested

Calculated Inputs
- Max Bisection iterations $k$

Command Line Inputs
- `-v` for tabulation of results : *optional*

**Output:** This routine returns an approximation value for the roots of $ f(x) $. When specified, this routine will output the approximate root and error pertaining to each iteration of the root finding method in a tabular form.

**Usage/Example:**

    python secant-hybrid.py -v
```
.
.
.
Interval: (0.11, 0.125)

        Approximate Root: 0.117647

       Iteration           ~Root             Error              Type
           1             1.1733e-01       7.371213e-01         secant
           1             1.1750e-01       3.435383e-01       bisection
           2             1.2125e-01       7.334928e+00       bisection
           3             1.1937e-01       3.877416e+00       bisection
           4             1.1844e-01       1.822962e+00       bisection
           5             1.1797e-01       7.480644e-01       bisection
           6             1.1773e-01       2.036056e-01       bisection
           7             1.1762e-01       6.972605e-02       bisection
           8             1.1768e-01       6.701186e-02       bisection
           2             1.1765e-01       1.652778e-05         secant
           3             1.1765e-01       4.040433e-09         secant
.
.
.
```

**Implementation/Code:** [secant-hybrid.py](../../src/root-finding/Python/secant-hybrid.py)