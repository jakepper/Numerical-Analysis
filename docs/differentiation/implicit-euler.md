# Implicit Euler Approximation - IVP

**Routine Name:** implicit_euler

**Author:** Jake Epperson

**Language:** Python

Run the `tasksheet5` program as follows to test the implicit_euler method,

    python tests/tasksheet5.py -t 3

from the `math4610/` directory.

**Description/Purpose:** This routine will compute an approximation of the solution to an ordinary differential equation initial value problem using the Implicit Euler method.

**Inputs:**

- f : dy/dt
- f_prime : derivative of dy/dt
- T : np.array of t values to approximate a solution at
- f0 : y(0) = y_0 (initial value)
- step : partition size
- n : number of partitions

**Output:** Y : np.array of approximated values

**Usage/Example:**
    
*TODO*

**Implementation/Code:** [implicit_euler.py](../../src/differentiation/implicit_euler.py)