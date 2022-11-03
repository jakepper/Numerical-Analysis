# Analytic Solution - IVP

**Routine Name:** analytic_sol

**Author:** Jake Epperson

**Language:** Python

Run the `tasksheet5` program as follows to test the analytic_sol method,

    python tests/tasksheet5.py -t 3

from the `math4610/` directory.

**Description/Purpose:** This routine will evaluate the solution to an ordinary differential equation initial value problem based on a given derived equation of y from some ODE dy/dt, and partition of t values.

**Inputs:**

- F : derived equation for 'y'
- T : np.array of t values to evaluate the derived function at

**Output:** Y : np.array of resulting values

**Usage/Example:**
    
*TODO*

**Implementation/Code:** [explicit_euler.py](../../src/differentiation/explicit_euler.py)