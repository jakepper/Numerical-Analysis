# Newton/Bisection Hybrid Method

**Routine Name:** newton-hybrid

**Author:** Jake Epperson

**Language:** Python

The program can be ran as follows,

    python newton-hybrid.py

or with the argument `-v` for tabular results

    python newton-hybrid.py -v

from the `src/root-finding/Python` directory.

**Description/Purpose:** This routine will compute an approximation of 10 roots of the following function,

$$ f(x) = 10.14e^{x^2}\cos(\frac{\pi}{x}) $$

This is done using a Newton and bisection hybrid method for root finding.

**Inputs:**

Pre-determined Inputs
- $ f(x) $
- $ f'(x) $
- $ g(x) $ : Newton's approximation function
- Tolerance : upper bound for the error in the approximation
- Max Iterations : maximum allowed iterations before program terminates
- Intervals of which will be tested

Calculated Inputs
- $x_0$ : initial approximation
- Max Bisection iterations $k$

Command Line Inputs
- `-v` for tabulation of results : *optional*

**Output:** This routine returns an approximation value for the roots of $ f(x) $. When specified, this routine will output the approximate root and error pertaining to each iteration of the root finding method in a tabular form.

**Usage/Example:**

    python newton-hybrid.py -v
```
.
.
.
Interval: (0.14, 0.17)

        Approximate Root: 0.153846

       Iteration           ~Root             Error              Type
           1             1.5383e-01       1.171113e-03         newton
           1             1.5500e-01       1.572814e+00       bisection
           2             1.4750e-01       7.977809e+00       bisection
           3             1.5125e-01       3.562395e+00       bisection
           4             1.5313e-01       9.967732e-01       bisection
           5             1.5406e-01       2.977159e-01       bisection
           6             1.5359e-01       3.483273e-01       bisection
           7             1.5383e-01       2.484905e-02       bisection
           8             1.5395e-01       1.365668e-01       bisection
           9             1.5389e-01       5.588985e-02       bisection
           2             1.5385e-01       4.057548e-05         newton
           3             1.5385e-01       1.058101e-08         newton
.
.
.
```

**Implementation/Code:** [newton-hybrid.py](../../src/root-finding/Python/newton-hybrid.py)