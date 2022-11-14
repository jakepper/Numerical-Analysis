# Approximate PI

**Routine Name:** approx_pi

**Author:** Jake Epperson

**Language:** C

The program can be compiled into an object file as follows,

    gcc -c approx_pi.c

from the `src/integration/C/` directory.

**Description/Purpose:** This routine will compute an approximation of the value of PI using a method numerical integration.

The approximation can be computed sequentially or in parallel when specified.

**Inputs:**

- steps : long - The number of partitions to use during integration
- parallel : boolean - Specifies whether approximation should be computed in parallel or sequentially

**Output:** pi : double

**Usage/Example:**
 
    printf("%f", approx_pi(1000, 0));

Output:

    3.141592

**Implementation/Code:** [approx_pi.c](../../src/integration/C/approx_pi.c)