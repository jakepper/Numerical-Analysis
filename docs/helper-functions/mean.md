# Array Mean

**Routine Name:** mean

**Author:** Jake Epperson

**Language:** C

The program can be compiled into an object file as follows,

    gcc -c mean.c

from the `src/helper-functions/` directory.

**Description/Purpose:** This routine will compute and return the mean of the given array.

**Inputs:**

- values : double[]
- size : int

**Output:** mean : double

**Usage/Example:**
    
    int size = 4;
    double values[] = {1, 2, 3, 4};
    printf("%f", mean(values, size));

Output:

    2.500000

**Implementation/Code:** [mean.c](../../src/helper-functions/mean.c)