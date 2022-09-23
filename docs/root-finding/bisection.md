# Bisection Method

**Routine Name:** bisection

**Author:** Jake Epperson

**Language:** Python

The program can be ran as follows,

    python bisection.py

or with the argument `-v` for tabular results

    python bisection.py -v

from the `src/root-finding/` directory.

**Description/Purpose:** This routine will compute an approximation of the root of the following two functions,

$$ f(x) = xe^{-x} $$
$$ f(x) = 10.14 * e^{x^2} * cos(\frac{\pi}{x}) $$

This is done using the bisection method of root finding.

**Inputs:**

Pre-determined Inputs
- $ f(x) $
- Tolerance : upper bound for the error in the approximation

User Inputs
- $ a $ : Lower Bound
- $ b $ : Upper Bound

Calculated Inputs
- Max Iterations $k$

Command Line Inputs

- `-v` for tabulation of results : *optional*

**Output:** This routine returns an approximation value for the root of $f(x)$. When specified, this routine will output the approximate root and error pertaining to each iteration of the root finding method in a tabular form.

**Usage/Example:**

    python bisection.py

```
Bisection with f(x) = x * e^(-x)

Lower Bound: -1
Upper Bound: 0.5

Iterations: 114
Approximate Root: -0.000001
Bisection with f(x) = 10.14 * e^(x^2) * cos(π/x)

Lower Bound: 1.9
Upper Bound: 2.2

Iterations: 37
Approximate root: 2.000000
```

**Implementation/Code:** [bisection.py](../../src/root-finding/bisection.py)