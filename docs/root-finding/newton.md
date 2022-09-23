# Newton's Method

**Routine Name:** newton

**Author:** Jake Epperson

**Language:** Python

The program can be ran as follows,

    python newton.py

or with the argument `-v` for tabular results

    python newton.py -v

from the `src/root-finding/` directory.

**Description/Purpose:** This routine will compute an approximation of the root of the following function,

$$ f(x) = xe^{-x} $$

This is done using the Newton's method for root finding.

**Inputs:**

Pre-determined Inputs
- $ f(x) $
- $ f'(x) $
- Tolerance : upper bound for the error in the approximation
- Max Iterations : maximum allowed iterations before program terminates

User Inputs
- $ x_0 $ : initial approximation

Command Line Inputs

- `-v` for tabulation of results : *optional*

**Output:** This routine returns an approximation value for the root of $ f(x) $. When specified, this routine will output the approximate root and error pertaining to each iteration of the root finding method in a tabular form.

**Usage/Example:**

    python newton.py -v
```
Enter x0: 0.4

        Approximate Root: -0.000000

       Iteration           ~Root             Error
           1            -2.6667e-01       6.666667e-01
           2            -5.6140e-02       2.105263e-01
           3            -2.9842e-03       5.315615e-02
           4            -8.8790e-06       2.975326e-03
           5            -7.8836e-11       8.878902e-06
```

**Implementation/Code:** [newton.py](../../src/root-finding/newton.py)