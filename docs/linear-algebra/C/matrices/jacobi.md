# Power Method

**Routine Name:** 

serial : jacobi

parallel : jacobi_p

**Author:** Jake Epperson

**Language:** C

**Description/Purpose:** Uses Jacobi iteration to approximate the solution to a linear system of equations of the form,

    Ax = y

**Inputs:**

- n : int - rows/columns
- A : double[n][n]
- x : double[n] - initial approximation
- y : double[n]
- D : double[n][n] - to hold D inverse
- iters : int

**Output:** 

- eigenvector : stored in `x`

- eigenvalue : returned

**Usage/Example:**

Output:
```
```

**Implementation/Code:** [matrices.c](../../../../src/linear_algebra/C/matrices.c)