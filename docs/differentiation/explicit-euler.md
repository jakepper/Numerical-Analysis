# Explicit Euler Approximation - IVP

**Routine Name:** explicit_euler

**Author:** Jake Epperson

**Language:** Python

Run the `tasksheet5` program as follows to test the explicit_euler method,

    python tests/tasksheet5.py -t 1

from the `math4610/` directory.

**Description/Purpose:** This routine will compute an approximation of the solution to an ordinary differential equation initial value problem using the Explicit Euler method.

**Inputs:**

- f : dy/dt
- T : np.array of t values to approximate a solution at
- f0 : y(0) = y_0 (initial value)
- step : partition size
- n : number of partitions

**Output:** Y : np.array of approximated values

**Usage/Example:**
    
*TODO*

**Implementation/Code:** [explicit_euler.py](../../src/differentiation/explicit_euler.py)