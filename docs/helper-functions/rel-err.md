# Relative Error

**Routine Name:** rel_err

**Author:** Jake Epperson

**Language:** C

The program can be compiled into an object file as follows,

    gcc -c rel_err.c

from the `src/helper-functions/` directory.

**Description/Purpose:** This routine will compute and return the relative error of the given predicted and actual values.

**Inputs:**

- predicted : double
- actual : double

**Output:** rel_err : double

**Usage/Example:**
 
    printf("%f", rel_error(1.9, 2));

Output:

    0.050000

**Implementation/Code:** [rel_err.c](../../src/helper-functions/rel_err.c)