# Power Method

**Routine Name:** jacobi

**Author:** Jake Epperson

**Language:** C

**Description/Purpose:** Uses Jacobi iteration to approximate the solution to a linear system of equations of the form,

    Ax = y

**Inputs:**

- n : int - rows/columns
- A : float[n][n]
- x : float[n] - initial approximation
- y : float[n]
- D : float[n][n] - to hold D inverse
- iters : int

**Output:** 

- eigenvector : stored in `approx`

- eigenvalue : returned

**Usage/Example:**

Output:
```
```

**Implementation/Code:** [matrices.c](../../../../src/linear_algebra/C/matrices.c)