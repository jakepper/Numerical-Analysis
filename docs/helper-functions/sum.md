# Array Sum

**Routine Name:** sum

**Author:** Jake Epperson

**Language:** C

The program can be compiled into an object file as follows,

    gcc -c sum.c

from the `src/helper-functions/` directory.

**Description/Purpose:** This routine will compute and return the sum of the given array.

**Inputs:**

- values : double[]
- size : int

**Output:** sum : double

**Usage/Example:**
    
    int size = 4;
    double values[] = {1, 2, 3, 4};
    printf("%f", sum(values, size));

Output:

    10.000000

**Implementation/Code:** [sum.c](../../src/helper-functions/sum.c)