# Approximate e

**Routine Name:** approx_e

**Author:** Jake Epperson

**Language:** C

The program can be compiled into an object file as follows,

    gcc -c approx_e.c

from the `src/integration/C/` directory.

**Description/Purpose:** This routine will compute an approximation of the value of e (eulers number) using the following formula,

$$ \sum_{k=0}^{n} \frac{1}{k!} $$

The approximation can be computed sequentially or in parallel when specified.

**Inputs:**

- n : long
- parallel : boolean - Specifies whether approximation should be computed in parallel or sequentially

**Output:** e : double

**Usage/Example:**
 
    printf("%f", approx_e(1000, 0));

Output:

    2.718281

**Implementation/Code:** [approx_e.c](../../src/integration/C/approx_e.c)