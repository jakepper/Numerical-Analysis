# Absolute Error

**Routine Name:** abs_err

**Author:** Jake Epperson

**Language:** C

The program can be compiled into an object file as follows,

    gcc -c abs_err.c

from the `src/helper-functions/` directory.

**Description/Purpose:** This routine will compute and return the absolute error of the given predicted and actual values.

**Inputs:**

- predicted : double
- actual : double

**Output:** abs_err : double

**Usage/Example:**
 
    printf("%f", abs_error(1.9, 2));

Output:

    0.100000

**Implementation/Code:** [abs_err.c](../../src/helper-functions/abs_err.c)