# Explicit Euler Approximation - IVP

**Routine Name:** explicit_euler

**Author:** Jake Epperson

**Language:** C

The program can be compiled into an object file as follows,

    gcc -c explicit_euler.c

from the `src/differentiation/` directory.

**Description/Purpose:** This routine will compute an approximation of the solution to an ordinary differential equation initial value problem.

**Inputs:**

- f : double (*f) ; dx/dt
- t : double ; initial value of t
- y : double ; x(t_0)
- alpha : double ; growth constant alpha>0
- beta : double ; limiting constant beta>0

**Output:** approximate solution : double

**Usage/Example:**
    
see example [here](../../src/differentiation/test_euler.c)

**Implementation/Code:** [explicit_euler.c](../../src/differentiation/explicit_euler.c)