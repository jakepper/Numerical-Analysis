# Secant Method

**Routine Name:** secant

**Author:** Jake Epperson

**Language:** Python

The program can be ran as follows,

    python secant.py

or with the argument `-v` for tabular results

    python secant.py -v

from the `src/root-finding/Python` directory.

**Description/Purpose:** This routine will compute an approximation of the root of the following function,

$$ f(x) = xe^{-x} $$

This is done using the secant method of root finding.

**Inputs:**

Pre-determined Inputs
- $ f(x) $
- Tolerance : upper bound for the error in the approximation
- Max Iterations : maximum allowed iterations before program terminates

User Inputs
- $ a $ : Lower Bound
- $ b $ : Upper Bound

Command Line Inputs

- `-v` for tabulation of results : *optional*

**Output:** This routine returns an approximation value for the root of $f(x)$. When specified, this routine will output the approximate root and error pertaining to each iteration of the root finding method in a tabular form.

**Usage/Example:**

    python secant.py -v

```
Lower Bound (x0): -0.8
Upper Bound (x1): 0.6

        Approximate Root: 0.000007

       Iteration           ~Root             Error
           1             3.8149e-01       2.604965e-01
           2            -4.4598e-01       6.966325e-01
           3             1.5628e-01       1.336689e-01
           4             5.9322e-02       5.590560e-02
           5            -1.0382e-02       1.049026e-02
           6             6.3107e-04       6.306688e-04
           7             6.5198e-06       6.519788e-06
```

**Implementation/Code:** [secant.py](../../src/root-finding/Python/secant.py)