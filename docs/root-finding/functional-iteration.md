# Functional Iteration

**Routine Name:** functional-iteration

**Author:** Jake Epperson

**Language:** Python

The program can be ran as follows,

    python functional-iteration.py

or with the argument `-v` for tabular results

    python functional-iteration.py -v

from the `src/root-finding/Python` directory.

**Description/Purpose:** This routine will compute an approximation of the root of the following two functions,

$$ f(x) = xe^{-x} $$
$$ f(x) = 10.14 * e^{x^2} * cos(\frac{\pi}{x}) $$

This is done using the funcitonal iteration method of root finding.

**Inputs:**

Pre-determined Inputs
- $ f(x) $
- Tolerance : upper bound for the error in the approximation
- Max Iterations : maximum allowed iterations before program terminates

User Inputs
- $ x_0 $ : initial approximation

Command Line Inputs

- `-v` for tabulation of results : *optional*

**Output:** This routine returns an approximation value for the root of $f(x)$. When specified, this routine will output the approximate root and error pertaining to each iteration of the root finding method in a tabular form.

**Usage/Example:**

    python functional-iteration.py
 
After running the program you will be prompted with,

    Functional Iteration with f(x) = x * e^(-x)

    Enter x0: 0.5

and the program will output,


        g1->[x - f(x)] Approximate Root: 0.000000

        g2->[x + f(x)] Approximate Root: 4.416481

as well as a few approximations for the roots of the second function in the description.

**Implementation/Code:** [functional-iteration.py](../../src/root-finding/Python/functional-iteration.py)